#include "fou.h"
#include "Piece.h"
#include <iostream>
#include "Echiquier.h"
#include <cmath>

using namespace std;

// Initialisation du fou par défaut.
Fou::Fou() {};

// Initialisation du fou en position de départ.
Fou::Fou(bool white, bool left) : Piece((left ? 3 : 6), (white ? 1 : 8), white) { }

// Initialisation du fou en position donnée.
Fou::Fou(int x , int y , bool white) : Piece(x,y,white) { }

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
	//Initialisation des positions actelles de la pièce et de la distance entre départ et arrivée.
	int pos_x = 0;
	int pos_y = 0;
	int nb_move = 0;

	//Vérifie si le mouvement est une diagonale.
	if (abs(x - this->m_x) == abs(y - this->m_y) && x > 0 && x < 9 && y > 0 && y < 9) {
		pos_x = this->m_x;
		pos_y = this->m_y;

		if (this->m_x < x && this->m_y < y) {
			pos_x = this->m_x + 1;
			pos_y = this->m_y + 1;

			// Vérification si le mouvement est valide case par case (diagonale vers bas et droite).
			nb_move = abs(x - this->m_x);
			for (int i = 0; i <= nb_move; i++) {
				if (pos_x != x && pos_y != y && e.getPiece(pos_x, pos_y) != 0 && this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack())
					return false;
				if (e.getPiece(pos_x, pos_y) == 0 || this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack()) {
					if (pos_x == x && pos_y == y)
						return true;
				}
				else
					return false;
				pos_x++;
				pos_y++;
			}
		}

		if (this->m_x > x && this->m_y > y) {
			pos_x = this->m_x - 1;
			pos_y = this->m_y - 1;

			// Vérification si le mouvement est valide case par case (diagonale vers haut et gauche).
			nb_move = abs(x - this->m_x);
			for (int i = 0; i <= nb_move; i++) {
				if (pos_x != x && pos_y != y && e.getPiece(pos_x, pos_y) != 0 && this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack())
					return false;
				if (e.getPiece(pos_x, pos_y) == 0 || this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack()) {
					if (pos_x == x && pos_y == y)
						return true;
				}
				else
					return false;
				pos_x--;
				pos_y--;
			}
		}

		if (this->m_x < x && this->m_y > y) {
			pos_x = this->m_x + 1;
			pos_y = this->m_y - 1;

			// Vérification si le mouvement est valide case par case (diagonale vers haut et droite).
			nb_move = abs(x - this->m_x);
			for (int i = 0; i <= nb_move; i++) {
				if (pos_x != x && pos_y != y && e.getPiece(pos_x, pos_y) != 0 && this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack())
					return false;
				if (e.getPiece(pos_x, pos_y) == 0 || this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack()) {
					if (pos_x == x && pos_y == y)
						return true;
				}
				else
					return false;
				pos_x++;
				pos_y--;
			}
		}

		if (this->m_x > x && this->m_y < y) {
			pos_x = this->m_x - 1;
			pos_y = this->m_y + 1;

			// Vérification si le mouvement est valide case par case (diagonale vers bas et gauche).
			nb_move = abs(x - this->m_x);
			for (int i = 0; i <= nb_move; i++) {
				if (pos_x != x && pos_y != y && e.getPiece(pos_x, pos_y) != 0 && this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack())
					return false;
				if (e.getPiece(pos_x, pos_y) == 0 || this->isWhite() == e.getPiece(pos_x, pos_y)->isBlack()) {
					if (pos_x == x && pos_y == y)
						return true;
				}
				else
					return false;
				pos_x--;
				pos_y++;
			}
		}
	}
	return false;
}

char
Fou::type()
{
	return m_white ? 'F' : 'f';
}