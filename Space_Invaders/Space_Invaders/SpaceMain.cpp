#include <iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>

#include "Coord.h"
#include "ExtraTerrestre.h"
#include "Laser.h"
#include "Martien.h"
#include "Vaisseau.h"

int main(){

	Vaisseau monVaisseau;
	Laser monLaser;
	int monVaisseauX = 20;

	while (true){
		char touche = _getch();

		// Déplacement
		if (touche == 'l' || touche == 'k'){
			if (touche == 'l' && monVaisseauX < 40){
				monVaisseauX++;
				monVaisseau.modifierPosition(touche);
			}
			else if (touche == 'k' && monVaisseauX > 0){
				monVaisseauX--;
			monVaisseau.modifierPosition(touche);
			}
		}
		// Lancer laser
		else if (touche == 'a'){
			monLaser.startLaser(monVaisseauX);
		}

	/*
	
	if (_kbhit() != 0){
		touche = _getch();
		monLaser.moveLaser();
	}

	*/

	return 0;


}