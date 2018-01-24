#pragma once

/**
* Header de Roi.cxx
*
* @file Roi.h
*/

#if !defined Roi_h
#define Roi_h

#include "Piece.h"

class Roi : public Piece
{
public:
	/**
	* Initialisation du roi.
	*
	* @param white est un booléen déterminant sa couleur.
	*
	* @return retourne un roi.
	*
	*/
	Roi(bool white);

	/**
	* Teste la validité des mouvements d'une roi.
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
	* @return 'R' si la pièce est blanche, 'r' sinon.
	*
	*/
	char type();
};

#endif // !defined Roi_h

