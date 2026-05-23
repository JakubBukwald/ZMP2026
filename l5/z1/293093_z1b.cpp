#include <iostream>
#include <bitset>
#include <algorithm>

//g++ 293093_z1b.cpp -o 293093_z1b.exe -std=c++17 && 293093_z1b.exe #cmd

using namespace std;
// 5 4 3 1 2
// 5 4 3 | 1 2
int marge(int tab[],int l1,int r1, int l2, int r2, int wynik[]){
	int inwersje =0;
	int k=0;
	int pocz = l1;
	while(l1<=r1 && l2<=r2){
		if(tab[l1] <= tab[l2]){
			wynik[k]=tab[l1];
			l1++;
		}else{
			wynik[k]=tab[l2];
			l2++;	
			inwersje += (r1 - l1 + 1);
			/*
			przychodz¹ tutaj ju¿ posortowane 2 tablice, je¿eli ta z "prawej strony" (l2/r2)
			ma mniejszy element to oznacza ¿e orginalnie ten elemnt sta³ za r1-l1+1 elementami z lewej tablicy
			oraz r1-l1 elementów bêdzie wiêksze od tego na l1 i sprawdziliœmy ¿e ten z l2 miejsze od tego z l1 wiêc r1-l1+1
			[2,3,5] i [1,3,7]
			2>1
			zatem 1 sta³o za 2 3 5 oryginalnie
			czyli do liczby inwersji dodaje 3
			*/
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
	
	return inwersje;		
}


int main() {
	int n;
	cin >> n;
	int tab[n];
	int wynik[n];
	int suma_inwersji = 0;
	
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
				suma_inwersji +=marge(tab, l1, r1, l2, r2, wynik);
			}
		}
		
	}
	
	cout << suma_inwersji;
		
}
