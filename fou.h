/**
* Header de fou.cxx
*
* @file fou.h
*/

#if !defined Fou_h
#define Fou_h

#pragma once
#include "Piece.h"

class Fou : virtual public Piece
{
public:

	/**
	* Initialisation du fou par d�faut.
	*
	*/
	Fou();

	/**
	* Initialisation du fou.
	*
	* @param white un bool�en d�terminant la couleur de la pi�ce.
	* @param left un bool�en d�terminant la posiotion de la pi�ce.
	*
	* @return retourne un fou.
	*
	*/
	Fou(bool white, bool left);

	/**
	* Initialisation du fou.
	*
	* @param x un int envoyant la positon x.
	* @param y un int envoyant la positon y.
	* @param white est un bool�en d�terminant sa couleur.
	*
	* @return retourne un fou.
	*
	*/
	Fou(int x , int y , bool white);

	/**
	* Teste la validit� des mouvements d'un fou.
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
	* Renvoi le type du fou.
	*
	*
	* @return 'F' si la pi�ce est blanche, 'f' sinon.
	*
	*/
	char type();
};
#endif // !defined Fou_h