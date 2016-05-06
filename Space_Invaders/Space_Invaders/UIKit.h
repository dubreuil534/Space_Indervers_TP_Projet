//	Version au 15/01/2015
#define VERSION_H 15012015

#ifndef __CLASSUTILEGRAPHIQUE_UIKIT_H
#define __CLASSUTILEGRAPHIQUE_UIKIT_H

#include <windows.h>
#include <iostream>
using namespace std;

//	pour information : les constantes de couleur
//#define FOREGROUND_BLUE      0x0001 // text color contains blue.
//#define FOREGROUND_GREEN     0x0002 // text color contains green.
//#define FOREGROUND_RED       0x0004 // text color contains red.
//#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
//#define BACKGROUND_BLUE      0x0010 // background color contains blue.
//#define BACKGROUND_GREEN     0x0020 // background color contains green.
//#define BACKGROUND_RED       0x0040 // background color contains red.
//#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.

class UIKit {
private:
	static HANDLE handle;
	static bool isPaletteReset;

	static void resetPalette();

public:
	/***********************
	//prototypes
	************************/

	//afficher en couleur
	static void color(unsigned short laCouleur);

	//positionner le curseur
	static void gotoXY(int x, int y);

	//connaître la position du curseur
	static char getCharXY(int x, int y);

	//déterminer la dimension de la fenetre
	static void setDimensionFenetre(int x1, int y1, int x2, int y2);

	//dessiner un cadre
	static void cadre(int cd,int ld,int cf,int lf, int couleur);

	static int whereX();
	static int whereY();
	static void curseurVisible(bool visibilite);
};
#endif
