#pragma once

/**
* Header de tour.cxx
*
* @file tour.h
*/

#if !defined Tour_h
#define Tour_h

#include "Piece.h"

class Tour : virtual public Piece
{
public:

	/**
	* Initialisation de la tour par défaut.
	*
	*/
	Tour();

	/**
	* Initialisation de la tour.
	*
	* @param white un booléen déterminant la couleur de la pièce.
	* @param left un booléen déterminant la posiotion de la pièce.
	*
	* @return retourne une Tour.
	*
	*/
	Tour(bool white, bool left);

	/**
	* Initialisation d'une tour.
	*
	* @param x un int envoyant la positon x.
	* @param y un int envoyant la positon y.
	* @param white est un booléen déterminant sa couleur.
	*
	* @return retourne une tour.
	*
	*/
	Tour(int x, int y, bool white);

	/**
	* Teste la validité des mouvements d'une tour.
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
	* Renvoi le type de la tour.
	*
	*
	* @return 'T' si la pièce est blanche, 't' sinon.
	*
	*/
	char type();
};
#endif // !defined Tour_h