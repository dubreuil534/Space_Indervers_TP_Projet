#include "Laser.h"

class Bomb : public Laser{

private:


public:
	// Attributs
	bool isExploding;
	int explosionStep;

	// Constructeur
	Bomb();

	// Méthodes
	void moveBomb();

	void explosion();

};