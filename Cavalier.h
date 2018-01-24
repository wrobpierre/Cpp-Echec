#pragma once

/**
* Header de cavalier.cxx
*
* @file cavalier.h
*/

#if !defined Cavalier_h
#define Cavalier_h

#include "Piece.h"
class Cavalier : public Piece
{
public:
	/**
	* Initialisation du cavalier.
	*
	* @param white est un booléen déterminant sa couleur.
	* @param left est un booléen déterminant sa place.
	*
	* @return retourne un cavalier.
	* 
	*/
	Cavalier(bool white, bool left);

	/**
	* Initialisation du cavalier.
	*
	* @param x un int déterminant la position x.
	* @param y un int déterminant la position y.
	*
	* @return retourne un cavalier.
	*
	*/
	Cavalier(int x, int y , bool white);

	/**
	* Teste la validité des mouvements d'un cavalier.
	*
	* @param e un pointeur de l'echequier.
	* @param x un int déterminant la position x.
	* @param y un int déterminant la position y.
	*
	* @return true si le mouvement est valide, false sinon.
	*
	*/
	bool mouvementValide(Echiquier &e, int x, int y);

	/**
	* Renvoi le type de la pièce.
	*
	*
	* @return 'C' si la pièce est blanche, 'c' sinon.
	*
	*/
	char type();
};
#endif // !defined Cavalier_h
