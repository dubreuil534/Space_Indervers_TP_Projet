#pragma once


#include <string>

using namespace std;


class Menu {
private:

	string *options;
	int maxOptions;
	int nbOptions;


	
public:

	Menu();

	void addOption(string newOption);

	void removeOption(int idOption);

	void clearOptions();

	int play();

	void afficherMenuPrin();

	~Menu();
};