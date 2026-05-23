#include <iostream>
#include <bitset>
#include <algorithm>



using namespace std;

void marge(int tab[],int l1,int r1, int l2, int r2, int wynik[]){
	int k=0;
	int pocz = l1;
	while(l1<=r1 && l2<=r2){
		if(tab[l1] <= tab[l2]){
			wynik[k]=tab[l1];
			l1++;
		}else{
			wynik[k]=tab[l2];
			l2++;			
		}	
		k++;	
	}
	
	while(l1<=r1){
		wynik[k] = tab[l1];
		l1++;
		k++;
	}
	while(l2<=r2){
		wynik[k] = tab[l2];
		l2++;
		k++;
	}
	
	for(int i = pocz; i<=r2;i++){
		tab[i] = wynik[i-pocz];
	}		
}


int main() {
	int n;
	cin >> n;
	int tab[n];
	int wynik[n];
	
	for(int i=0;i<n;i++){
		cin >> tab[i];
	}
	
	for(int rozmiar =1;rozmiar<n;rozmiar = rozmiar*2){//chcemy bloki 1 2 4 8 ...
		for(int j =0;j<n;j+=2*rozmiar){
			int l1 = j;
			int r1 = j + rozmiar - 1;
			int l2 = j + rozmiar;
			int r2 = min(j + 2 * rozmiar - 1, n - 1);

			if(l2 < n){
				marge(tab, l1, r1, l2, r2, wynik);
			}
		}
		
	}
	
	
	
	for(int i = 0; i < n; i++) {
		cout << tab[i] << " ";
	}	
}
