#include <iostream>
#include <bitset>


using namespace std;
	

int main() {
	int n;
	cin >> n;
	int tab[n];
	
	for(int i=0;i<n;i++){
		cin >> tab[i];
	}
	int wynik=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(tab[i]>tab[j]) wynik++;
		}		
	}
	cout << wynik;
}
