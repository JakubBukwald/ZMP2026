#include <iostream>
//g++ 293093_z2a.cpp -o 293093_z2a.exe -std=c++17 && 293093_z2a.exe
using namespace std;

void fun(int tab[],int n,bool tab2[],int depth){
	if(depth == n){
		bool czyem = true;
		for(int i = 0;i<n;i++){
			if(tab2[i]==true){
				czyem = false;
				cout << tab[i] << " ";
			} 
		}
		if(czyem == true)cout << "empty";
		cout << "\n";
		return;
	}
	/*
	Idea opiera siê na rozpisaniu drzewa banarnego gdzie z ka¿dym krokiem decyduje - biore (krok w lewo), nie biore (krok w prawo) itego elementu tablicy. 
	Koñcami trego drzewa bêd¹ wszyskie mo¿liwe podzbiory
	*/
	tab2[depth]= true;
	depth++;
	fun(tab,n,tab2,depth);
	depth--;
	tab2[depth] = false;
	depth++;
	fun(tab,n,tab2,depth);

}

int main() {
	int n;
	cin >> n;
	int tab[n];
	bool tab2[n];
	for(int i =0;i<n;i++){
		tab2[i]=false;
		cin >> tab[i];
	}
	int depth =0;
	fun(tab,n,tab2,depth);
	
}
