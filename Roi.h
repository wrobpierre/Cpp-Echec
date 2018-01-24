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
	* @param white est un bool�en d�terminant sa couleur.
	*
	* @return retourne un roi.
	*
	*/
	Roi(bool white);

	/**
	* Teste la validit� des mouvements d'une roi.
	*
	* @param e un pointeur de l'echequier.
	* @param x un int d�terminant la position x.
	* @param y un int d�terminant la position y.
	*
	* @return true si le mouvement est valide, false sinon.
	*
	*/
	bool mouvementValide(Echiquier &e, int x, int y);

	/**
	* Renvoi le type de la pi�ce.
	*
	*
	* @return 'R' si la pi�ce est blanche, 'r' sinon.
	*
	*/
	char type();
};

#endif // !defined Roi_h

