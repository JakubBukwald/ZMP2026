#include <iostream>
#include <bitset>
#include <algorithm>
//g++ 293093_z2.cpp -o 293093_z2.exe -std=c++17 && 293093_z2.exe
using namespace std;






struct Node {
	int key;
	Node* left = nullptr;
	Node* right = nullptr;
	
	  
	Node(): key{0}, left{nullptr}, right{nullptr} {};
	Node(int val): key{val}, left{nullptr}, right{nullptr} {};
	
	~Node(){
	cout << "Niszczy node o kluczu " << key << "\n";
		delete left;
		delete right;
	}
};

struct BTree {
	Node* root;
	BTree(): root{nullptr} {};
	
	
//nie wiem dlaczego ale je¿eli ten fragment (wziêty z Pana kodu) jest odkomentowany to program mi siê zapêtla, niestety nie rozumiem w czym jest problem
	
//	~BTree(){
//		cout << "Destruktor drzewa wezwany!" << "\n";
//		delete root;
//	}
	//(ii)
	void sklejanie(BTree& x, int key){
		Node* y = new Node(key); //tworzymy kropke
		
		(*y).left = x.root;
		(*y).right = root;
		//po po³¹czenie obu drzew z kropk¹ zmieniamy czubek naszego drzewa
		root = y;
		x.root = nullptr;//a to drzewo ju¿ nam jest nie potrzebne		
	}
	//(iii)
	bool czy_jest(int x, Node* root2){
		if (root2 == nullptr) return false;
		
		if((*root2).key == x) return true;
		
		bool z = czy_jest(x,(*root2).left);
		bool y = czy_jest(x,(*root2).right);
		
		if(z==true || y==true)return true;
		else return false;
	}
	
	//(iiii)
	
	int hight(Node* root2){
		if (root2 == nullptr) return 0;
	    return 1 + max(hight((*root2).left), hight((*root2).right));
	}	
	
	//(iiiii)
	int liscie(Node* root2){
		if (root2 == nullptr) return 0; 
		if(root2->left == nullptr && root2->right == nullptr) return 1; //je¿eli nie ma nikogo pod nim to musi byæ liœciem
		int z = liscie((*root2).left);
		int y = liscie((*root2).right);
		return y+z;
	}	
	
	
	int policz_wezly(Node* root2) {
		if (root2 == nullptr) return 0;
		int z = policz_wezly((*root2).left);
		int y = policz_wezly((*root2).right);
		return 1+y+z;
	}


void show(Node* root2, int odstep) {
	//rysowanie drzewa obruconego o 90 stopni
		if (root2 == nullptr) return;

		//idziemy maksymalnie w prawo
		show((*root2).right, odstep + 5);

		for (int i = 0; i < odstep; i++) {
			cout << " ";
		}

		
		if ((*root2).left == nullptr && (*root2).right == nullptr) {
			//je¿eli jest to liœæ to dopiszemy obok niego ptr dla podkreœlania 
			cout << (*root2).key << " prt" << "\n";
		} else {
			cout << (*root2).key << "\n";
		}

		
		show((*root2).left, odstep + 5);
	}



};


/*
Idea 

dostajemy ci¹g A B C D E F G

wiemy ¿e G musi byæ na samej górze
dzielimy pozosta³e elementy na 2 czêœæi mid = (0+6-1)/2=2 
[A B C] [D E F]
t¹ sam¹ logik¹ C oraz F musz¹ byæ gór¹ w tym miejszym drzewie 

dla [A B C]
l=0,r=2,mid=(0+2-1)/2=0
lewa (0+1,2-1) = (1,1)
prawa (0,0)

nastêpnie przejœcia trafi¹ na warunek l>r wiêc siê nic nie podepnie

a potem dojdzie do sklejania A oraz B do C i wzracania C

*/
BTree fun_2_ii(int tab[],int l,int r){
	BTree wynik;
	
	if(l>r){ //pusty przedzia³
		return wynik;
	}
	if(l==r){
		wynik.root = new Node(tab[l]);
		return wynik;
	}
	
	int mid = (l+r-1)/2; //œrodek elemenów bez tego najwiêkszego wzglêdem indeksu 
	
	BTree lewe = fun_2_ii(tab,mid+1,r-1);
	BTree prawe = fun_2_ii(tab,l,mid);
	
	prawe.sklejanie(lewe, tab[r]);
	
	return prawe;
}

BTree fun_ii(int tab[],int n){
	return fun_2_ii(tab,0,n-1);
}





int main() {
	int n1,n2,r,s;
	cin >> n1 >> n2 >> r >> s;
	
	int tab1[n1];
	int tab2[n2];
	
	for(int i = 0; i < n1; i++) cin >> tab1[i];
	for(int i = 0; i < n2; i++) cin >> tab2[i];
	
	BTree drze1 = fun_ii(tab1, n1);
	BTree drze2 = fun_ii(tab2, n2);
	
	drze2.sklejanie(drze1, r);

	
	drze2.show(drze2.root, 0);
	cout << "\n\n";
	
	cout << "liczba wezlow " << drze2.policz_wezly(drze2.root) << "\n";
	cout << "liczba lisci " << drze2.liscie(drze2.root) << "\n";
	cout << "wysokosc drzewa " << drze2.hight(drze2.root) << "\n";
	
	if (drze2.czy_jest(s, drze2.root)) {
		cout << "wartosc " << s << " jest w drzewie.\n";
	} else {
		cout << "wartosc " << s << " nie wystepuje \n";
	}
	
	return 0;
}
