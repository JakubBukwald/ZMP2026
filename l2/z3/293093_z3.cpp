#include <iostream>

using namespace std;



int main() {
	bool sekret[8];
	bool wiado[8];
	
	for(int i =0;i<8;i++){
		cin >> sekret[i];	
	}
	for(int i =0;i<8;i++){
		cin >> wiado[i];	
	}	
	for(int i =0;i<8;i++){
		cout << (sekret[i]^wiado[i]) << " ";	
	}

}
