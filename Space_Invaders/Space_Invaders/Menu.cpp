#include <iostream>
using namespace std;
#include <string>
#include <Windows.h> // gestion de la musique et commande windows
#include <mmsystem.h>
#include <conio.h>
class Menu {
private:

	string *options;
	int maxOptions;
	int nbOptions;

public:

	Menu() {
		this->maxOptions = 1;
		this->nbOptions = 0;
		options = new string[maxOptions];
	}

	void addOption(string newOption) {
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

	void removeOption(int idOption) {
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



	void clearOptions() {
		this->maxOptions = 1;
		this->nbOptions = 0;
		options = new string[maxOptions];
	}

	int play() {

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

	~Menu() {
		delete[] options;
	}

};


// fonction principale


/*- Attention pour faire fonctionner la musique, il faut ajouter un linker dans le fichier projet.
- ajouter #include <Windows.h> et #include <mmsystem.h> dans le fichier cpp
Voici les etapes.
- Cliquer droit sur le projet dans visual studio
- view
- Solution Explorer
- clique droit sur la solution
- proprieter
- configuration proprieter
- linker
- input
- addtionnal dependencie
-edit et ajouter winmm.lib*/




int main() {

	PlaySound(TEXT("Space_Invaders.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	system("color 02");
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

	return 0;

}
