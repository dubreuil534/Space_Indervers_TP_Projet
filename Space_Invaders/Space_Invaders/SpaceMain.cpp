#include <iostream>
#include <conio.h>
using namespace std;

#include "Coord.h"
#include "ExtraTerrestre.h"
#include "Laser.h"
#include "Martien.h"
#include "Vaisseau.h"

int main(){

	Vaisseau monVaisseau;
	int monVaisseauX = 20;

	while(true){
		char touche = _getch();

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
	}
	


	return 0;
}