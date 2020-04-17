#include <stdio.h>
#include <iostream> 
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Game{
public:
	string name;
	int releaseYear;
	double price;
	double currentPrice;
	
	double current_price(){
		currentPrice = price;
		for(unsigned int i = releaseYear; i < 2020; i++){
			currentPrice = currentPrice - (currentPrice / 100 * 30);
		}
		return currentPrice;
	}
	
};


class Persoon{
public:
	string naam;
	double budget;
	vector<Game> owned_games;
	
	string koop(Game game){
		for(unsigned int i = 0; i < owned_games.size(); i++){
			if (game.name == owned_games[i].name){
				return "niet gelukt";
			}
		}
		if(game.current_price() > budget){
			return "niet gelukt";
		}
		
		budget = budget - (game.current_price());
		owned_games.push_back(game);
		return "gelukt";
	}
	
	string verkoop(Game game, Persoon & koper){
		
		for(unsigned int j = 0; j < koper.owned_games.size(); j++){
			if (game.name == koper.owned_games[j].name){
				return "niet gelukt";
			}
		}
		if(game.current_price() > koper.budget){
			return "niet gelukt";
		}
		for(signed int i = 0; i < owned_games.size(); i++){
			if (game.name == owned_games[i].name){
				koper.budget = koper.budget - game.current_price();
				budget = budget + game.current_price();
				koper.owned_games.push_back(game);
				owned_games.erase(owned_games.begin() + i);
				return "gelukt";
			}
		}
		return "niet gelukt";
		
		
	}
	
	string toString(){
		string str = naam + " heeft een budget van €" + to_string(budget) + " en bezit de volgende games: \n";
		for(unsigned int i = 0; i < owned_games.size(); i++){
			str += owned_games[i].name + ", uitgegeven in " + to_string(owned_games[i].releaseYear) + " nieuwprijs: " + to_string(owned_games[i].price) + " nu voor: €" + to_string(owned_games[i].current_price())+"\n";
		}
		return str;
	}
	
	
};


int main()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t); //http://cplusplus.com/forum/beginner/32329/
	
	int releaseJaar1 = timePtr->tm_year + 1900 - 1;
	int releaseJaar2 = timePtr->tm_year + 1900 - 2;
	
	Game g1 = {"Just Cause 3", releaseJaar1, 49.98};
	Game g2 = {"Need for Speed: Rivals", releaseJaar2, 45.99};
	Game g3 = {"Need for Speed: Rivals", releaseJaar2, 45.99};
	
	Persoon p1 = {"Eric", 200};
	Persoon p2 = {"Hans", 55};
	Persoon p3 = {"Arno", 185};
	
	cout << p1.koop(g1) << "\n";
	cout << p1.koop(g2) << "\n";
	cout << p1.koop(g3) << "\n";
	cout << p2.koop(g2) << "\n";
	cout << p2.koop(g1) << "\n";
	cout << p3.koop(g3) << "\n";
	cout << "\n";
	
	cout << p1.toString() << "\n";
	cout << p2.toString() << "\n";
	cout << p3.toString() << "\n";
		
	cout << p1.verkoop(g1, p3) << "\n";
	cout << p2.verkoop(g2, p3) << "\n";
	cout << p2.verkoop(g1, p1) << "\n";
	cout << "\n";

	cout << p1.toString() << "\n";
	cout << p2.toString() << "\n";
	cout << p3.toString() << "\n";

}
