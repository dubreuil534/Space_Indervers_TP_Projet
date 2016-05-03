#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "Coord.h"

class Vaisseau
{
protected:
	void removeVaisseau() const;
	void putVaisseau() const;

public:
	Coord coord;
	Vaisseau();
	void modifierPosition(char);
};

#endif