#include <iostream>
using namespace std;


int nwd(int k, int n){
	while(n%k!=0){
		int p=0;
		p=n%k;
		n=k;
		k=p;
	}
	if(k==1) return 1;
	return 0;	
}



int main() {
	int n;
	cin >> n;
	int wynik=0;
	for(int i =1;i<=n;i++){
		if(nwd(i,n)==1)wynik++;
	}
	cout << wynik;
    

    return 0;
}
