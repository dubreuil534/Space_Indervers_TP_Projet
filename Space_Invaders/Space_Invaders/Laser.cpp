#include "Laser.h"

#include <iostream>
using namespace std;

void Laser::startLaser(int x)
{
	coord.setPositionX(x);
	coord.setPositionY(39);
	putLaser();
	isAlive = true;
}

void Laser::removeLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << " ";
}

void Laser::putLaser() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << char(15);
}

void Laser::moveLaser()
{
	removeLaser();
	if (coord.getPositionY()>0)
	{
		coord.setPositionY(coord.getPositionY() - 1);
		putLaser();
	}
	else
		isAlive = false;
}

void Laser::killLaser()
{
	removeLaser();
	isAlive = false;
}
