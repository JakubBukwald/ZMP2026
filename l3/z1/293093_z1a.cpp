#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int p1=1;
	int p2=1;
	int wynik=0;
	while(n!=0){
		int zm=p2;
		p2=p2+p1;
		p1=zm;
		n--;
	}
	cout << p1;	
}
