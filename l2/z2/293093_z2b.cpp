#include <iostream>


using namespace std;

pair<bool,int> Binary_search(int tab[],int x, int size){
	int l = 0; //lewy kraniec
	int r = size - 1;	//prawy kraniec
	
	while(l<=r){
		int mid = (l + r)/2;
		
		if(tab[mid]==x) return {true, mid};
		
		if(tab[mid]<x){ //stoimy na �rodku i je�eli x jest wi�kszy to odpada nam lewa po�owa
			l=mid+1;//+1 bo wiemy �e mid=/=x
		}else{ 
			r=mid-1;//-1 bo wiemy �e mid=/=x
		}		
	}
	return {false, 0};		
}


int main() {
	int n;
	int k;


	cin >> n;
	cin >> k;
	int tab[k];
	
	for(int i =0;i<k;i++){
		cin >> tab[i];
	}	
	
	pair<bool,int> wynik;
	wynik=Binary_search(tab, n, k);
	
	if(wynik.first == true){
		cout << "tak " << wynik.second; 
	}else{
		cout << "nie";
	}
}
