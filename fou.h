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
	* Initialisation du fou par défaut.
	*
	*/
	Fou();

	/**
	* Initialisation du fou.
	*
	* @param white un booléen déterminant la couleur de la pièce.
	* @param left un booléen déterminant la posiotion de la pièce.
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
	* @param white est un booléen déterminant sa couleur.
	*
	* @return retourne un fou.
	*
	*/
	Fou(int x , int y , bool white);

	/**
	* Teste la validité des mouvements d'un fou.
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
	* Renvoi le type du fou.
	*
	*
	* @return 'F' si la pièce est blanche, 'f' sinon.
	*
	*/
	char type();
};
#endif // !defined Fou_h