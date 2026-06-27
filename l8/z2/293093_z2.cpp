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
		delete left;
		delete right;
	}
};

struct BTree {
	Node* root;
	BTree(): root{nullptr} {};
	
	bool czy_izo(Node* root1,Node* root2){
//		Node* root1 = rot->left;
//		Node* root2 = rot->right;
		if(root1 == nullptr && root2 == nullptr){//
			return true;
		}
		if((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)){//to nie s¹ izo
			return false;
		}
		
		bool x;
		x= czy_izo(root1->left, root2->left);
		bool y;
		y= czy_izo(root1->right, root2->right);
		if(x==y && x==true) return true;
		else return false;
	}
	
	void insert_node(int new_l){//gdzie k na pocz¹tku to 0
		if(root == nullptr){
			root = new Node(new_l);
			return;
		}
		Node* obecny = root;
		
		while(1==1){
			if(new_l < obecny->key){//iedziemy w lewo
				if(obecny->left ==nullptr){ //po lewej nic nie ma
					obecny->left = new Node(new_l);
					return;
				}else{
					obecny = obecny -> left;
					continue;
				}					
			}else{//idziemy w prawo
				if(obecny->right == nullptr){
					obecny->right = new Node(new_l);
					return;
				}else{
					obecny = obecny->right;
					continue;
				}
			}
	
		}	
		return;
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

	friend ostream & operator<<(ostream& ekran, BTree& drzewo) {
		drzewo.show(drzewo.root, 0);
		return ekran;
}

	friend istream & operator>>(istream& wejscie, BTree& drzewo) {
		int n;
		wejscie >> n;
		for (int i = 0; i < n; i++) {
			int wartosc;
			wejscie >> wartosc;
			drzewo.insert_node(wartosc);
		}
		return wejscie;
	}
};




//przeci¹¿anie + - 
Node* dodaj_wezly(Node* n1, Node* n2) {
	if (n1 == nullptr || n2 == nullptr) {
		return nullptr;
	}
	
	Node* nowy = new Node(n1->key + n2->key);
	
	nowy->left = dodaj_wezly(n1->left, n2->left);
	nowy->right = dodaj_wezly(n1->right, n2->right);
	

	return nowy;
}


Node* odejmi_wezly(Node* n1, Node* n2) {
	if (n1 == nullptr || n2 == nullptr) {
		return nullptr;
	}
	
	Node* nowy = new Node(n1->key - n2->key);
	
	nowy->left = odejmi_wezly(n1->left, n2->left);
	nowy->right = odejmi_wezly(n1->right, n2->right);
	

	return nowy; 
}

BTree operator+(BTree& t1, BTree& t2) {
	BTree wynik;
	if (t1.czy_izo(t1.root, t2.root)==true) {
		wynik.root = dodaj_wezly(t1.root, t2.root);
	} else {
		cout << " tego nie idzie dodac :c ";
	}
	return wynik;
}

BTree operator-(BTree& t1, BTree& t2) {
	BTree wynik;
	if (t1.czy_izo(t1.root, t2.root)==true) {
		wynik.root = odejmi_wezly(t1.root, t2.root);
	} else {
		cout << " tego nie idzie odjac :c ";
	}
	return wynik;
}

int main() {
	BTree t1, t2;
	
	
	cin >> t1 >> t2;

	if (t1.czy_izo(t1.root, t2.root)==true) {
		cout << "drzewa sa izomorficzne" << "\n" << "\n";
		
		BTree suma = t1 + t2;
		cout << "suma t1 i t2) to ->" << "\n" ;
		cout << suma << "\n";
		
		BTree roznica = t1 - t2;
		cout << "roznica t1 i t2 to ->" << "\n";
		cout << roznica << "\n";
	} else {
		cout << "drzewa nie sa izomorficzne :c";
	}
	
	return 0;
}
