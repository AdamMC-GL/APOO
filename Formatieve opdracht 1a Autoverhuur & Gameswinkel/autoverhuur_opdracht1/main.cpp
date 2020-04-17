#include <stdio.h>
#include <iostream> 
#include <string>
using namespace std;

class Klant{
public:
	string naam;
	double kortingPercentage;
	
	void klant(string nm){
		naam = nm;
	}
	void setKorting(double kP){
		kortingPercentage = kP;
	}
	double getKorting(){
		return kortingPercentage;
	}
	string toString(){
		string str = "op naam van: " + naam + " (korting: " + to_string(kortingPercentage) + "%)\n";
		if(naam == ""){
			return "er is geen huurder bekend\n";
		}
		return str;
	}
};


class Auto{

public:
	string Type;
	double prijsPerDag;
	
	string autofunc(string tp, double prPd){
		Type = tp;
		prijsPerDag = prPd;
	}
	void setPrijsPerDag(double prPd){
		prijsPerDag = prPd;
	}
	double getPrijsPerDag(){
		return prijsPerDag;
	}
	string toString(){
		string str = "autotype: " + Type +" met prijs per dag: " + to_string(prijsPerDag)+"\n";
		if(Type == ""){
			return "er is geen auto bekend\n";
		}
		return str;
	}
};


class Autohuur{
private:
	int aantalDagen;
	Auto autovar;
	Klant klantvar;
public:
	void AutoHuur(){
		
	}
	void setAantalDagen(int aD){
		aantalDagen = aD;
	}
	void setGehuurdeAuto(Auto ga){
		autovar = ga;
	}
	string getGehuurdeAuto(){
		return autovar.Type + " met prijs per dag: " + to_string(autovar.prijsPerDag) +"%\n";
	}
	void setHuurder(Klant k){
		klantvar = k; 
	}
	string getHuurder(){
		return klantvar.naam + " met korting van: " + to_string(klantvar.kortingPercentage) + "%\n";
	}
	double totaalPrijs(){
		double totaalPrijs = aantalDagen * autovar.getPrijsPerDag();
		totaalPrijs = totaalPrijs - (totaalPrijs / 100 * klantvar.getKorting());
		return totaalPrijs;
		
	}
	string toString(){
		string str = autovar.toString() + klantvar.toString() + "aantal dagen: " + to_string(aantalDagen) + " en dat kost: " +to_string(totaalPrijs());
		return str;
	}
};



int main()
{
	Autohuur ah1 = {};
	cout << "Eerste autohuur: \n" << ah1.toString() << "\n";
	cout << "\n";
	
	Klant k = {"Mijnheer de Vries"};
	k.setKorting(10.0);
	ah1.setHuurder(k);
	cout << "Eerste autohuur: \n" << ah1.toString() << "\n";
	cout << "\n";
	
	Auto a1 = {"Peugeot 207", 50};
	ah1.setGehuurdeAuto(a1);
	ah1.setAantalDagen(4);
	cout << "Eerste autohuur: \n" << ah1.toString() << "\n";
	cout << "\n";
	
	Autohuur ah2 = {};
	Auto a2 = {"Ferrari", 3500};
	ah2.setGehuurdeAuto(a2);
	ah2.setHuurder(k);
	ah2.setAantalDagen(1);
	cout << "Tweede autohuur: \n" << ah2.toString() << "\n";
	cout << "\n";
	
	cout << "Gehuurd: " << ah1.getGehuurdeAuto();
	cout << "Gehuurd: " << ah2.getGehuurdeAuto();
}
