#include <iostream>
#include <string>
#include <Windows.h> // gestion de la musique et commande windows
#include <mmsystem.h>
#include <conio.h>
#include "Menu.h"

using namespace std;

Menu::Menu() {
		this->maxOptions = 1;
		this->nbOptions = 0;
		options = new string[maxOptions];
	}

	void Menu::addOption(string newOption) {
		if (nbOptions == maxOptions) {
			string *options2 = new string[maxOptions + 5];
			for (int i = 0; i < nbOptions; i++) {
				options2[i] = options[i];
			}
			options2[nbOptions] = newOption;
			nbOptions++;
			delete[]options;
			options = options2;
			maxOptions += 5;
		}
		else {
			options[nbOptions] = newOption;
			nbOptions++;
		}
	}

	void Menu::removeOption(int idOption) {
		for (int j = idOption; j < nbOptions; j++) {
			options[j - 1] = options[j];
		}
		nbOptions--;
		if (nbOptions == maxOptions - 5) {
			string *options2 = new string[maxOptions - 5];
			for (int i = 0; i < maxOptions; i++) {
				options2[i] = options[i];
			}
			delete[]options;
			options = options2;
			maxOptions += 5;
		}
	}



	void Menu::clearOptions() {
		this->maxOptions = 1;
		this->nbOptions = 0;
		options = new string[maxOptions];
	}

	int  Menu::play() {

		int choix = 0;


		if (nbOptions != 0) {
			

			cout << endl;
			for (int i = 0; i < nbOptions; i++) {
				cout << "                                                        " << i + 1 << "- " << options[i] << endl;
			}
			cout << endl;
			cout << "                           Veuillez faire votre choix : " << endl;
			cout << endl;
		}

		return choix;
	}

	Menu::~Menu() {
		delete[] options;
	}

	void Menu::afficherMenuPrin(){

		cout << "         ##########################################################################################################################" << endl;
		cout << "                    _________                            __                              ___               ___ ___  " << endl;
		cout << "                   /   _____/__________    ____  ____   |__| _______  __ ___________  __| _/___________   |   |   | " << endl;
		cout << "                    \\_____  \\____ \\__  \\ _/ ___\\/ __ \\  |  |/    \\  \\/ // __ \\_  __ \\/ __ |/ __ \\_  __ \\  |   |   | " << endl;
		cout << "                    /        \\  |_> > __ \\  \\__\\  ___/  |  |   |  \\   /\\  ___/|  | \\/ /_/ \\  ___/|  | \\/  |   |   | " << endl;
		cout << "                  /_______  /   __(____  /\\___  >___  > |__|___|  /\\_/  \\___  >__|  \\____ |\\___  >__|     |___|___| " << endl;
		cout << "                          \\/|__|       \\/     \\/    \\/          \\/          \\/           \\/    \\/                  " << endl;
		cout << "         ##########################################################################################################################" << endl;
		cout << "                                                PRESENTE PAR Jean-Christophe et DOMINIC       " << endl;
		cout << "                                        ______________________________________________________   " << endl;
		cout << "                                       |                   #############                     |  " << endl;
		cout << "                                       |                    ###########                      |  " << endl;
		cout << "                                       |                      #######                        |  " << endl;
		cout << "                                       |                                                     |  " << endl;
		cout << "                                       |                                                     |  " << endl;
		cout << "                                       |                                                     |  " << endl;
		cout << "                                       |                         o                           |  " << endl;
		cout << "                                       |                                                     |   " << endl;
		cout << "                                       |_________________________$___________________________|  " << endl;
		cout << "                                                                                                " << endl;
		cout << "         ##########################################################################################################################" << endl;

		Menu m1;
		m1.addOption("Jouer");
		m1.addOption("Choisir difficulte Niveau: 1- 2- 3-");
		m1.addOption("Quitter");
		m1.play(); 


	}





	
	