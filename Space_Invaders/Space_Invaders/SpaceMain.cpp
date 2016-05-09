#include <iostream>
using namespace std;
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>  
#include "Menu.cpp"


#include "Coord.h"
#include "ExtraTerrestre.h"
#include "Laser.h"
#include "Bomb.h"
#include "Martien.h"
#include "Vaisseau.h"
#include "Timer.h"
#include "Menu.h"


#define MAX_LASER 10



int main(){


	system("color 02");

	Menu menuJeu;

	menuJeu.afficherMenuPrin();


	// Instance Vaisseau
	Vaisseau monVaisseau;

	// Tableau Laser
	Laser mesLaser[MAX_LASER];

	Bomb maBombe;

	int explosionDelay = 50;

	clock_t explosionTime = clock();


	// Instance Martien
	//Martien MesMartiens1(2, 20);


	mesLaser[MAX_LASER].isAlive = false;

	for (int i = 0; i < MAX_LASER; i++){
		mesLaser[i].isAlive = false;
	}


	// Chronometres Temps Laser

	Timer temps50(50);

	Timer temps100(100); 

	Timer temps200(200);

	Timer temps300(300);

	while (true){


		//  Gestion des touches du jeux
		if (_kbhit() != 0) {
			char touche = _getch();

			// Mouvement du vaisseau
			if (touche == 'l' || touche == 'k'){
				if (touche == 'l' && monVaisseau.coord.getPositionX() < 40){
					monVaisseau.modifierPosition(touche);
				}
				else if (touche == 'k' && monVaisseau.coord.getPositionX() > 0){
					monVaisseau.modifierPosition(touche);
				}
			}


			// Trigger Laser
			if (touche == ' '  && !mesLaser[MAX_LASER].isAlive){
				int i = 0;
				while (i < MAX_LASER && mesLaser[i].isAlive)
					i++;

				if (i < MAX_LASER)
					mesLaser[i].startLaser(monVaisseau.coord.getPositionX());
			}


			// Trigger Bomb
			if (touche == 'a'  && !maBombe.isAlive && !maBombe.isExploding){
				maBombe.startLaser(monVaisseau.coord.getPositionX());
			}

			// Explose Bomb
			if (touche == 's'  && maBombe.isAlive){
				maBombe.explosion();
			}
		}



		// Gestion Temps Laser
		if (temps100.isReady()){
			for (int i = 0; i < MAX_LASER; i++)
			mesLaser[i].moveLaser();


		}

		// Gestion Temps de la bombe
		if (temps200.isReady()){
			if (maBombe.isAlive){
				maBombe.moveBomb();
			}
		}

		// Gestion de l'explosion

		if (temps50.is){
			explosionTime = clock();
			maBombe.explosion();
		}





		// Gestion du temps des martiens et du deplacement
		/*
		if (clock() >= martienTime + martienDelay){
		martienTime = clock();
		MesMartiens1.jiggleMartien();
		}
		*/


	}
	return 0;

}


/*
// Fetch tab key state.
SHORT tabKeyState = GetAsyncKeyState( VK_TAB );

// Test high bit - if set, key was down when GetAsyncKeyState was called.
if( ( 1 << 16 ) & tabKeyState )
{
// TAB key down...
}

*/