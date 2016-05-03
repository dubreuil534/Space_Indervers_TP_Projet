#include <iostream>
using namespace std;
#include<stdio.h>
#include<conio.h>

#include "Coord.h"
#include "ExtraTerrestre.h"
#include "Laser.h"
#include "Martien.h"
#include "Vaisseau.h"

int main()
{

	Vaisseau monVaisseau;
	Laser lancerLaser;
	cout << endl;

	while (true){
		char touche = _getch();


		if (touche == 'l' || touche == 'k'){

			monVaisseau.modifierPosition(touche);

		}
		else if (touche == 'a'){



			lancerLaser.startLaser(29);
		}
	}

	return 0;
}