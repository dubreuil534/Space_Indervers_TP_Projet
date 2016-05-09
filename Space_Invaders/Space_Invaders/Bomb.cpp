#include <iostream>
#include <string>
using namespace std;

#include "Laser.h"
#include "Bomb.h"

// Les constructeurs
Bomb::Bomb(){
	Laser::isAlive = false;
	Bomb::isExploding = false;
	Bomb::explosionStep = 0;
};

void Bomb::moveBomb(){

	moveLaser();
	if (coord.getPositionY() > 0){
		coord.gotoXY(coord.getPositionX(), coord.getPositionY());
		cout << "O";
	}
}

void Bomb::explosion(){

	string output;

	switch (explosionStep){
		case 0: 
			Bomb::killLaser();
			isExploding = true;
			output = "O";
			break;

		case 1: output = "<O>";
			break;
		case 2: output = "<<O>>";
			break;
		case 3: output = "<<<O>>>";
			break;
		case 4: output = "        ";
			break;
	}
	
	coord.gotoXY(coord.getPositionX() - explosionStep, coord.getPositionY());
	cout << output;

	if (explosionStep < 4){
		explosionStep++;
	}
	else{
		explosionStep = 0;
		isExploding = false;
	}
	
}