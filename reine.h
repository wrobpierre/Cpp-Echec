#pragma once

/**
* Header de reine.cxx
*
* @file reine.h
*/

#if !defined Reine_h
#define Reine_h

#include "Piece.h"
#include "fou.h"
#include "Tour.h"

class Reine : public Fou, public Tour
{
public:
	/**
	* Initialisation de la reine.
	*
	* @param white est un bool�en d�terminant sa couleur.
	*
	* @return retourne une reine.
	*
	*/
	Reine(bool white);

	/**
	* Initialisation d'une reine.
	*
	* @param x un int envoyant la positon x.
	* @param y un int envoyant la positon y.
	* @param white est un bool�en d�terminant sa couleur.
	*
	* @return retourne une reine.
	*
	*/
	Reine(int x, int y, bool white);

	/**
	* Teste la validit� des mouvements d'une reine.
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
	* @return 'Q' si la pi�ce est blanche, 'q' sinon.
	*
	*/
	char type();
};
#endif // !defined Reine_h