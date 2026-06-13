#include <iostream>
#include <bitset>
#include <algorithm>
//g++ 293093_z1.cpp -o 293093_z1.exe -std=c++17 && 293093_z1.exe
using namespace std;


struct vec{
	int size = 1;
	int current = 0; 	
	int* tab = new int[size]; //wskaŸnik na tablice
	
	void wypisz(){
		for(int i =0;i<current;i++){
			cout << tab[i] << " ";
		}
	}

	void dodaj(int x){
		if(current>=size){//wziêkszamy tablice o 2x
			size*=2;
			int* tab_new = new int[size];
			//przenosimy elementy 
			for(int i =0;i<current;i++){
				tab_new[i]=tab[i];
			}
			delete[] tab; 
			tab=tab_new;		
		}
		tab[current] = x;
		current++;			
	}
	
	int usun(){
		current--;
		return tab[current];
	}
	
	
	int get(int x){
		if(x>=0 && x<=current-1){
			return tab[x];	
		}else{
			return -1;
		}
	}
	~vec() { delete[] tab; }	
};




void marge(vec& tabi,int l1,int r1, int l2, int r2, vec& wynik){
	int k=0;
	int pocz = l1;
	while(l1<=r1 && l2<=r2){
		if(tabi.tab[l1] <= tabi.tab[l2]){
			wynik.tab[k]=tabi.tab[l1];
			l1++;
		}else{
			wynik.tab[k]=tabi.tab[l2];
			l2++;			
		}	
		k++;	
	}
	
	while(l1<=r1){
		wynik.tab[k] = tabi.tab[l1];
		l1++;
		k++;
	}
	while(l2<=r2){
		wynik.tab[k] = tabi.tab[l2];
		l2++;
		k++;
	}
	
	for(int i = pocz; i<=r2;i++){
		tabi.tab[i] = wynik.tab[i-pocz];
	}		
}


int main() {
	int n;
	cin >> n;
	vec tabi;
	vec wynik;
	int x;
	for(int i=0;i<n;i++){
		cin >> x;
		tabi.dodaj(x);
		wynik.dodaj(0);
	}
	
	for(int rozmiar =1;rozmiar<n;rozmiar = rozmiar*2){//chcemy bloki 1 2 4 8 ...
		for(int j =0;j<n;j+=2*rozmiar){
			int l1 = j;
			int r1 = j + rozmiar - 1;
			int l2 = j + rozmiar;
			int r2 = min(j + 2 * rozmiar - 1, n - 1);

			if(l2 < n){
				marge(tabi, l1, r1, l2, r2, wynik);
			}
		}
		
	}
	
	tabi.wypisz();
}
