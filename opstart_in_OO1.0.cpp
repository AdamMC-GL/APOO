#include <stdio.h>
#include <iostream> 
using namespace std;

class zwembad{
public:
	float breedte;
	float lengte;
	float diepte;
	
	float getBreedte(){
		return breedte;
	}
	float getLengte(){
		return lengte;
	}
	float getDiepte(){
		return diepte;
	}
	float inhoud(){
		return (breedte * lengte * diepte);
	}
	void setBreedte(float arg){
		breedte = arg;
	}
	void setDiepte(float arg){
		diepte = arg;
	}
	void setLengte(float arg){
		lengte = arg;
	}
	void toString(){
		cout << "GEGEVENS ZWEMBAD: Dit zwembad is "<< breedte <<" meter breed, "<< lengte <<" meter lang, en "<< diepte <<" meter diep\n";
	}
	
};



int main()
{
	zwembad z1 = {2.0, 5.5, 1.5};
	cout << "BREEDTE: " << z1.getBreedte() << "\n";
	cout << "LENGTE: " << z1.getLengte() << "\n";
	cout << "DIEPTE: " << z1.getDiepte() << "\n";
	cout << "BEREKENDE INHOUD: " << z1.inhoud() << "\n";
	
	
	zwembad z2;
	z2.setBreedte(2.5);
	z2.setLengte(100.0);
	z2.setDiepte(2.0);
	z2.toString();
	cout <<"BEREKENDE INHOUD: " << z2.inhoud() << "\n";
	
}
