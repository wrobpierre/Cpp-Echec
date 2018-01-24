#include "Roi.h"
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"

using namespace std;

// Initialisation du roi en position de départ.
Roi::Roi(bool white) : Piece(5, (white ? 1 : 8), white) {}

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
	// Vérifie si les mouvement du roi sont valide (même pour manger une pièce adverse).
	if((x == this->m_x + 1 || x == this->m_x - 1 || x == this->m_x) && (y == this->m_y + 1 || y == this->m_y - 1 || y == this->m_y) && x > 0 && x < 9 && y > 0 && y < 9)
		if (e.getPiece(x, y) == 0 || e.getPiece(x, y)->isWhite() == this->isBlack() )
			return true;
	return false;
}

char
Roi::type()
{
	return m_white ? 'R' : 'r';
}