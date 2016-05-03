#ifndef MARTIEN_H
#define MARTIEN_H

#include "ExtraTerrestre.h"

class Martien : public ExtraTerrestre
{
	bool jiggle;

public:
	Martien(int, int);
	void jiggleMartien();
};

#endif
