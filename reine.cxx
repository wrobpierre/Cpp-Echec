#include "reine.h"
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"

using namespace std;

// Initialisation de la reine en position de départ.
Reine::Reine(bool white) : Piece(4, (white ? 1 : 8), white) { }

// Initialisation de la reine en position donnée.
Reine::Reine(int x, int y, bool white) : Piece(x, y, white) { }

//Vérifie si les mouvement de la tour et du fou sont valide pour la reine
bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
	return Tour::mouvementValide(e, x, y) || Fou::mouvementValide(e, x, y);
}

char
Reine::type()
{
	return m_white ? 'Q' : 'q';
}