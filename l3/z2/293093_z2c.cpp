#include <iostream>
//g++ 293093_z2c.cpp -o 293093_z2c.exe -std=c++17 && 293093_z2c.exe
using namespace std;

void fun(int tab[],int n,bool tab2[],int depth, int k, int ile_wz){
	if(ile_wz>k)return; //nie ma sensu rozpatrywaæ podzbiorów wiêkszych niz k wiêc ucinamy t¹ ga³¹Ÿ
	
	if(depth == n){
		
		if (ile_wz != k)return;
		
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
	
	tab2[depth]= true;
	ile_wz++;
	depth++;
	fun(tab,n,tab2,depth,k,ile_wz);
	depth--;
	ile_wz--;
	tab2[depth] = false;
	depth++;
	fun(tab,n,tab2,depth,k,ile_wz);

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
	int k;
	cin >> k;
	int depth =0;
	int ile_wz=0;
	fun(tab,n,tab2,depth,k,ile_wz);
}
