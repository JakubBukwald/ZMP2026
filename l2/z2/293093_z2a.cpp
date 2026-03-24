#include <iostream>

using namespace std;



int main() {
	int n;
	int k;
	int ws=0;

	cin >> n;
	cin >> k;
	int tab[k];
	bool czy=false;
	for(int i =0;i<k;i++){
		cin >> tab[i];
	}
	
	for(int i =0;i<k;i++){
		if(tab[i]==n){
			ws = i;
			czy = true;
			break;
		}
	}	
	
	
	if(czy == true) cout << "tak " << ws;
	else cout << "nie";
	
}
