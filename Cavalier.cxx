#include "Cavalier.h"
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"

using namespace std;

// Initialisation du cavalier en position de départ.
Cavalier::Cavalier(bool white, bool left) : Piece((left ? 2 : 7), (white ? 1 : 8), white) { }

// Initialisation du cavalier en position donnée.
Cavalier::Cavalier(int x , int y , bool white) : Piece(x, y, white) { }

bool
Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
	//Test tous les déplacements possibles pour un cavalier (pour manger une pièce aussi).
	if ((this->m_x + 2 == x && this->m_y + 1 == y || this->m_x + 1 == x && this->m_y + 2 == y || this->m_x - 2 == x && this->m_y - 1 == y || this->m_x - 1 == x && this->m_y - 2 == y || this->m_x + 2 == x && this->m_y - 1 == y || this->m_x - 2 == x && this->m_y + 1 == y || this->m_x + 1 == x && this->m_y - 2 == y || this->m_x - 1 == x && this->m_y + 2 == y) && x > 0 && x < 9 && y > 0 && y < 9)
		if(e.getPiece(x, y) == 0 || e.getPiece(x,y)->isWhite() == this->isBlack())
			return true;
	return false;
}

char
Cavalier::type()
{
	return m_white ? 'C' : 'c';
}