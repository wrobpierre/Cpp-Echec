#pragma once

/**
* Header de pion.cxx
*
* @file pion.h
*/

#if !defined Pion_h
#define Pion_h

#include "Piece.h"

class Pion : public Piece
{
public:
	/**
	* Initialisation du pion.
	*
	* @param x un int envoyant la positon x.
	* @param white est un bool�en d�terminant sa couleur.
	*
	* @return retourne un cavalier.
	*
	*/
	Pion(int x, bool white);

	/**
	* Teste la validit� des mouvements d'un pion.
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
	* @return 'P' si la pi�ce est blanche, 'p' sinon.
	*
	*/
	char type();

	/**
	* Applique le mouvement de la pi�ce.
	*
	*/
	void move( int x, int y);
};
#endif // !defined Pion_h