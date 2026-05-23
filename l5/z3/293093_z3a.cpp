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
	int max = 0; //nie trzeba siê martwi o ujemne bo i tak kiedyœ bêdzie ró¿nica tego samego elementu
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if((tab[j]-tab[i])>=max) max = (tab[j]-tab[i]);
		}		
	}
	cout << max;
}
