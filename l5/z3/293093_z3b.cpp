#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

/*
Idea
mamy jakieœ i oraz j które bêd¹ naszym wynikiem
³atwiej to wyt³umaczyæ dziel¹c tablice na 2

mamy tablice i dzielimy j¹ na 2 
scenariusz 1 
szukane i jest w tablicy lewej a szukane j jest w tablicy prawej 
i to bêdzie min z Tab_lewej a j to bêdzie max z Tab_prawej
tym samym znaleŸliœmy wynik
scenariusz 2 
i oraz j s¹ w tej samej tablicy, to rodzi problem bo wybieraj¹c min czy max pomijamy i albo j
rozwi¹zaniem bêdzie kolejne podzielenie tablicy
dzielimy tak d³ugo a¿ i oraz j bêd¹ w 2 rónych tablicach

ten schemat zastosowa³em ale od do³u, bo ju¿ mam kod z zadania 2

*/

int fun(int tab[],int l1,int r1, int l2, int r2){
	int mini_lew = tab[l1];
	//szukanie minimum w lewej tablicy
	for(int i = l1+1;i<=r1;i++){
		if(tab[i]<mini_lew) mini_lew = tab[i];
	}
	//max w prawej
	int max_praw = tab[l2];
	for(int i = l2+1;i<=r2;i++){
		if(tab[i]>max_praw) max_praw = tab[i];
	}
	return (max_praw - mini_lew);
		
}


int main() {
	int n;
	cin >> n;
	int tab[n];
	
	for(int i=0;i<n;i++){
		cin >> tab[i];
	}
	int wynik = 0;
	for(int rozmiar =1;rozmiar<n;rozmiar = rozmiar*2){//chcemy bloki 1 2 4 8 ...
		for(int j =0;j<n;j+=2*rozmiar){
			int l1 = j;
			int r1 = j + rozmiar - 1;
			int l2 = j + rozmiar;
			int r2 = min(j + 2 * rozmiar - 1, n - 1);

			if(l2 < n){
				int x = fun(tab, l1, r1, l2, r2);
				if (wynik < x) wynik =x;
			}
		}
		
	}
	
	cout << wynik;	
}
