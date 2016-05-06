#include <iostream>
using namespace std;
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>  


#include "Coord.h"
#include "ExtraTerrestre.h"
#include "Laser.h"
#include "Martien.h"
#include "Vaisseau.h"


#define MAX_LASER 10

#define MAX_MARTIEN 10



int main(){

	// Instance Vaisseau
	Vaisseau monVaisseau;

	// Instance Laser
	Laser mesLaser[MAX_LASER];

	// Instance Martien
	//Martien mesMartiens[MAX_MARTIEN](2,2);

	mesLaser[MAX_LASER].isAlive = false;

	for (int i = 0; i < 10; i++){
		mesLaser[i].isAlive = false;
	}


	int timer = 100;
	clock_t liveTime = clock();

	while (true){


		//  Gestion du Déplacement des vaisseaux 

		if (_kbhit() != 0) {
			char touche = _getch();
			if (touche == 'l' || touche == 'k'){
				if (touche == 'l' && monVaisseau.coord.getPositionX() < 40){
					monVaisseau.modifierPosition(touche);
				}
				else if (touche == 'k' && monVaisseau.coord.getPositionX() > 0){
					monVaisseau.modifierPosition(touche);
				}
			}


			// Gestion du Laser
			if (touche == ' '  && !mesLaser[MAX_LASER].isAlive){
				int i = 0;
				while (i < MAX_LASER && mesLaser[i].isAlive)
					i++;

				if (i < MAX_LASER)
					mesLaser[i].startLaser(monVaisseau.coord.getPositionX());
			}
		}


		// Gestion du temps du laser et du deplacement
		if (clock() >= liveTime + timer){
			liveTime = clock();

			for (int i = 0; i < MAX_LASER; i++)
				if (mesLaser[i].isAlive)
					mesLaser[i].moveLaser();
		}

		// Gestion des martiens
//		MesMartiens.jiggleMartien();





	}
	return 0;

}