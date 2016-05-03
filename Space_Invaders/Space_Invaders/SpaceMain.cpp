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
	Laser monLaser;
	cout << endl;

	while (true){
		char touche = _getch();


		if (touche == 'l' || touche == 'k'){

			monVaisseau.modifierPosition(touche);

		}
		else if (touche == 'a'){



			monLaser.startLaser(29);
		}
	}

	/*
	
	if (_kbhit() != 0){
		touche = _getch();
	}
	
	*/

	return 0;
}