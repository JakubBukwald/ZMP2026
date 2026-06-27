#include <iostream>
#include <bitset>

//g++ 293093_z1.cpp -o 293093_z1.exe -std=c++17 && 293093_z1.exe #cmd

using namespace std;

class Pojazd{
	protected:
		string marka;
		string model;
		int rok_produkcji;
	public:
		
		
		Pojazd(string mar, string mod,int x){
			marka = mar;
			model = mod;
			rok_produkcji = x;
			
		}
		virtual void show() const = 0;
		virtual ~Pojazd() {
		}
};


class Samochod : public Pojazd{
	private:
		int liczba_drzwi;
	public:	
		Samochod(string mar, string mod,int x, int y) : Pojazd(mar, mod,x){
			liczba_drzwi = y;
		}
		void show() const override{
			cout << "Marka tego Samachodu - " << marka << " " << " model ";
			cout << model<< " rok produkcji to " << rok_produkcji << "\n";	
			cout << "oraz to auto posiada az " << liczba_drzwi << " drzwi" << "\n";		
		}
};



class Rower : public Pojazd{
	private:
		int liczba_przerzutek;
	public:	

		Rower(string mar, string mod,int x, int y) : Pojazd(mar, mod,x){
			liczba_przerzutek = y;
		}	
		void show() const override{
			cout << "Marka tego roweru - " << marka << " " << " model ";
			cout << model<< " rok produkcji to " << rok_produkcji << "\n";	
			cout << "oraz ten rower posiada az " << liczba_przerzutek << " przerzutek" << "\n";		
		}		
		
};





int main() {
	string marka_s, model_s, marka_r, model_r;
	int rok_s, drzwi, rok_r, przerzutki;

	cin >> marka_s >> model_s >> rok_s >> drzwi >> marka_r >> model_r >> rok_r >> przerzutki;

	Samochod s(marka_s, model_s, rok_s, drzwi);
	Rower r(marka_r, model_r, rok_r, przerzutki);

	s.show();
	r.show();

	return 0;
}
