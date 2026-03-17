#include <iostream>

//g++ 293093_z3.cpp -o 293093_z3.exe -std=c++17 && 293093_z3.exe
using namespace std;

int main() {
	//G³ówna idea - rozbijam na czynniki pierwsze n! i liczê ile mam 2 oraz 5. Bior¹c minimum z tej liczby otrzymam ile '10' dzieli n! to jest równowa¿ne z iloœci¹ zer na koñcu.
	int n;
	cin >> n;
	int ile_2=0, ile_5=0;
	for(int i =1; i<=n;i++){
		
		int p=i;
		while(1==1){
			if(p%2==0){
				p/=2;
				ile_2++;
				continue;
			}
			
			if(p%5==0){
				p/=5;
				ile_5++;
				continue;
			}	
			break;		
		}
	}
	int wynik = ile_2;
	if (wynik > ile_5){
		wynik=ile_5;
	}
	cout << wynik;
    

    return 0;
}
