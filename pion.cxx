#include "pion.h"
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"

using namespace std;

// Initialisation du fou en position de départ.
Pion::Pion(int x, bool white) : Piece(x, (white ? 2 : 7), white) {  }

bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{
	// Vérification si le mouvement est valide (même pour manger un adversaire).
	if (((this->m_y + 1 == y || (this->m_y + 2 == y && m_y == 2)) && this->m_x == x && this->isWhite() == true ) || ((this->m_y - 1 == y || (this->m_y - 2 == y && m_y == 7)) && this->m_x == x && this->isBlack() == true) || (this->m_y + 1 == y && (this->m_x + 1 == x || this->m_x - 1 == x) || (this->m_y - 1 == y && (this->m_x + 1 == x || this->m_x - 1 == x))) && x > 0 && x < 9 && y > 0 && y < 9) {
		if (e.getPiece(x, y) == 0 && this->m_x == x) {
			return true;
		}
		else if (e.getPiece(x, y) != 0 && this->isBlack() == e.getPiece(x, y)->isWhite() && (this->m_y + 1 == y && ((this->m_x + 1 == x || this->m_x - 1 == x) && this->isWhite()) || ((this->m_y - 1 == y && (this->m_x + 1 == x || this->m_x - 1 == x)) && this->isBlack()))) {
			return true;
		}
	}
	return false;
}

//Déplace un pion.
void Pion::move(int x, int y)
{
	Piece::move(x, y);
}

char
Pion::type()
{
	return m_white ? 'P' : 'p';
}