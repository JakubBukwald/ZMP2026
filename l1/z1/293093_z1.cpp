#include <iostream>
using namespace std;

int fun(int n){
	if(n%2==0){
		return n/2;
	}else{
		return 3*n+1;
	}
}

int main() {
	int licz = 1;
	int n;
	cin >> n;
	if (n==1){
		cout << "1, 1";	
		return 0;
	} 
	cout << n;
	while(n!=1){
		n=fun(n);
		licz++;
		cout << " "<< n;
	}
    cout << ", "<< licz;

    return 0;
}
