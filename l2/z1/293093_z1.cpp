#include <iostream>

using namespace std;

int nwd(int n, int k){
	while(n%k!=0){
		int p=0;
		p=n%k;
		n=k;
		k=p;
	}
	return k;
}

int main() {
	int n=0;
	cin >> n;
	int tab[n];
	for (int i =0;i<n;i++){
		cin >> tab[i];
	}
	int k = nwd(tab[0],tab[1]);
	for(int i =2;i<n;i++){
		k=nwd(k,tab[i]);
	}

	cout << k;
}
