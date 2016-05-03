#ifndef LASER_H
#define LASER_H

#include "Coord.h"

class Laser
{
public:
	bool isAlive;
	Coord coord;

	void startLaser(int);
	void removeLaser() const;
	void putLaser() const;
	virtual void moveLaser();
	void killLaser();
};

#endif