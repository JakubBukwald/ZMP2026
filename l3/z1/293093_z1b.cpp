#include <iostream>
using namespace std;

int fibo(int n, int F1,int F2){
	if(n==0) return F1;
	return fibo(n-1,F2,F1+F2);
}


int main() {
	int n;
	cin >> n;
	int wynik = fibo(n,1,1);
	cout << wynik;
}
