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
	* Initialisation de la tour par d�faut.
	*
	*/
	Tour();

	/**
	* Initialisation de la tour.
	*
	* @param white un bool�en d�terminant la couleur de la pi�ce.
	* @param left un bool�en d�terminant la posiotion de la pi�ce.
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
	* @param white est un bool�en d�terminant sa couleur.
	*
	* @return retourne une tour.
	*
	*/
	Tour(int x, int y, bool white);

	/**
	* Teste la validit� des mouvements d'une tour.
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
	* Renvoi le type de la tour.
	*
	*
	* @return 'T' si la pi�ce est blanche, 't' sinon.
	*
	*/
	char type();
};
#endif // !defined Tour_h