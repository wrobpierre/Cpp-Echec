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
	* @param white est un bool�en d�terminant sa couleur.
	* @param left est un bool�en d�terminant sa place.
	*
	* @return retourne un cavalier.
	* 
	*/
	Cavalier(bool white, bool left);

	/**
	* Initialisation du cavalier.
	*
	* @param x un int d�terminant la position x.
	* @param y un int d�terminant la position y.
	*
	* @return retourne un cavalier.
	*
	*/
	Cavalier(int x, int y , bool white);

	/**
	* Teste la validit� des mouvements d'un cavalier.
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
	* @return 'C' si la pi�ce est blanche, 'c' sinon.
	*
	*/
	char type();
};
#endif // !defined Cavalier_h
