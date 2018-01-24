#include "Tour.h"
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"

using namespace std;

// Initialisation par d�faut de la tour.
Tour::Tour() {};

// Initialisation de la tour en position de d�part.

Tour::Tour(bool white, bool left) : Piece((left ? 1 : 8), (white ? 1 : 8), white) { }

// Initialisation de la tour en position donn�e.
Tour::Tour(int x, int y, bool white) : Piece(x , y , white) { }

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
	//Si d�placement horizontal.
	if (this->m_x != x && this->m_y == y && x > 0 && x < 9 && y > 0 && y < 9) {
		//Teste si d�placement vers la droite.
		if (this->m_x < x) {
			for (int i = this->m_x+1; i <= x; i++)
			{
				if (e.getPiece(i, y) == 0 || this->isWhite() == e.getPiece(i, y)->isBlack()) {
					if (i == x)
						return true;
					else if (e.getPiece(i, y) != 0 && i != x && this->isWhite() == e.getPiece(i, y)->isBlack())
						return false;
				}
				else 
					return false;
			}
		}
		//Teste si d�placement vers la gauche.
		else if (this->m_x > x) {
			for (int i = this->m_x-1; i >= x; i--)
			{
				if (e.getPiece(i, y) == 0 || this->isWhite() == e.getPiece(i, y)->isBlack()) {
					if (i == x)
						return true;
					else if (e.getPiece(i, y) != 0 && i != x && this->isWhite() == e.getPiece(i, y)->isBlack())
						return false;
				}
				else 
					return false;
			}
		}
	}
	
	//Si d�placement vertical.
	if (this->m_y != y && this->m_x == x && x > 0 && x < 9 && y > 0 && y < 9) {

		//Teste si d�placement vers le bas.
		if (this->m_y < y) {
			for (int i = this->m_y+1; i <= y; i++)
			{
				if (e.getPiece(x, i) == 0 || this->isWhite() == e.getPiece(x, i)->isBlack()) {
					if (i == y)
						return true;
					else if (e.getPiece(x, i) != 0 && i != y && this->isWhite() == e.getPiece(x, i)->isBlack())
						return false;
				}
				else
					return false;
			}
		}

		//Teste si d�placement vers le haut.
		else if (this->m_y > y) {
			for (int i = this->m_y-1; i >= y; i--)
			{
				if (e.getPiece(x, i) == 0 || this->isWhite() == e.getPiece(x, i)->isBlack()) {
					if (i == y)
						return true;
					else if (e.getPiece(x, i) != 0 && i != y && this->isWhite() == e.getPiece(x, i)->isBlack())
						return false;
				}
				else
					return false;
			}
		}
	}
	return false;
}

char
Tour::type()
{
	return m_white ? 'T' : 't';
}