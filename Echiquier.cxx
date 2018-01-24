/**
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */
#include <iostream>
// A besoin de la declaration de la classe
#include "Echiquier.h"
#include <stdlib.h> 
/*#include "Cavalier.h"
#include "fou.h"
#include "reine.h"
#include "Tour.h"*/

using namespace std;

Echiquier::Echiquier()
{
  for (int i = 0 ; i < 64 ; i++)
  {
    m_cases[ i ] = NULL;
    //m_cases[ i ] = 0; //equivalent
  }
}

Piece*
Echiquier::getPiece( int x, int y )
{
  if ( x >= 1  && x <= 8 && y >= 1 && y <= 8 )
    return m_cases[ x - 1 + (y - 1) * 8];

  return NULL;
}

bool
Echiquier::placer( Piece* p )
{
  if ( ( p != NULL )
       && ( getPiece( p->x(), p->y() ) == NULL )
       && ( p->x() >= 1 ) && ( p->x() <= 8 )
       && ( p->y() >= 1 ) && ( p->y() <= 8 ) )
  {
    m_cases[p->x() - 1 + (p->y() - 1) * 8] = p;
    return true;
  }
  return false;
}

bool
Echiquier::deplacer( Piece* p, int x, int y )
{
	if (p != NULL) {
		if ((x <= 8 && x >= 1) && (y <= 8 && y >= 1)) {
			if (p->mouvementValide(*this, x, y)){
				if (getPiece(x, y) == NULL) {
					p = enleverPiece(p->x(), p->y());
					if (p != NULL) {
						p->move(x, y);
					}
					return placer(p);
				}
				else {
					p = enleverPiece(p->x(), p->y());
					enleverPiece(this->getPiece(x, y)->x(), this->getPiece(x, y)->y());
					if (p != NULL) {
						p->move(x, y);
						return placer(p);
					}
				}
			}
		}
	}
	return false;
}

Piece*
Echiquier::enleverPiece( int x, int y )
{
  if ( ( x >= 1 ) && ( x <= 8 )
       && ( y >= 1 ) && ( y <= 8 )
       && ( getPiece( x, y ) != 0 ) )
  {
    Piece *tmp;
    tmp=m_cases[x - 1 + (y - 1) * 8];
    m_cases[x - 1 + (y - 1) * 8] = NULL;
    return tmp;
  }
  return NULL;
}

void
Echiquier::affiche()
{
  cout << endl << "   1 2 3 4 5 6 7 8 " << endl;
  cout << "   _______________ " << endl;
  for ( int y = 1; y <= 8; ++y )
    {
      cout << y << "|";
      for ( int x = 1; x <= 8; ++x )
    {
      char c;
      Piece* p = getPiece( x, y );
      if ( p == 0 )
        c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
      else
        c = p->type(); //c = p->isWhite() ? 'B' : 'N';
      cout << " "<< c;
    }
      cout << "|" << y << " " << endl;
    }
  cout << "   _______________ " << endl;
  cout << "   1 2 3 4 5 6 7 8 " << endl;
}

Piece* Echiquier::echec(bool white) {
	
	for (int i = 0; i < 64; i++) {
		//On trouve le roi blanc
		if (this->m_cases[i] != NULL && white == true && this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y()) != NULL &&  this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y())->type() == 'R') {
			for (int j = 0; j < 64; j++) {
				//Pour les blancs on vérifie si chacun des noirs peut mettre le roi en echec.
				if (this->m_cases[j] != NULL && this->m_cases[j]->isBlack() == true && this->m_cases[j]->mouvementValide(*this, this->m_cases[i]->x(), this->m_cases[i]->y()) == true) {
					return this->m_cases[i];
				}
			}
		}
		//On trouve le roi noir
		if (this->m_cases[i] != NULL && white == false && this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y()) != NULL && this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y())->type() == 'r') {
			for (int j = 0; j < 64; j++) {
				//Pour les noirs on vérifie si chacun des blancs peut mettre le roi en echec.
				if (this->m_cases[j] != NULL && this->m_cases[j]->isWhite() == true && this->m_cases[j]->mouvementValide(*this, this->m_cases[i]->x(), this->m_cases[i]->y()) == true) {
					return this->m_cases[i];
				}
			}
		}
	}
	return NULL;
}

bool Echiquier::test_echec(bool white, int x, int y) {
	// Teste pour chaque pièce adverse si la position donnée (x, y) peut être mise en échec.
	for (int i = 0; i < 64; i++) {
		if (white == true && this->m_cases[i] != NULL && this->m_cases[i]->isBlack() == true && this->m_cases[i]->mouvementValide(*this, x, y) == true) {
			return true;
		}
		if (white == false && this->m_cases[i] != NULL && this->m_cases[i]->isWhite() == true && this->m_cases[i]->mouvementValide(*this, x, y) == true) {
			return true;
		}
	}
	return false;
}

bool Echiquier::verif_echec_mat(){
	int compte_echec = 0;
	int pos_x_roi = 0;
	int pos_y_roi = 0;
	int compteur_tab = 0;

	//On trouve le roi blanc
	if (this->echec(true) != NULL) {	
		for (int i = 0; i < 64; i++) {
			if (this->m_cases[i] != NULL && this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y())->type() == 'R') {
				pos_x_roi = this->m_cases[i]->x();
				pos_y_roi = this->m_cases[i]->y();
			}
		}
		//On compte le nombre de pièces noirs pouvant le mettre en échec.
		for (int i = 0; i < 64; i++) {
			if (this->m_cases[i] != NULL && this->m_cases[i]->isBlack() == true && this->m_cases[i]->mouvementValide(*this , pos_x_roi , pos_y_roi)) {
				compte_echec++;
			}
		}

		//On créé un tableau avec toutes les pièces pouvant atteeindre le roi.
		int** tab_echec = (int**)malloc(sizeof(int*)*compte_echec);
		if (tab_echec == NULL) {
			cout << "Probleme de memoire verif_echec_mat" << endl;
			exit(1);
		}

		//On rentre la position des pièce pouvant atteindre le roi.
		for (int i = 0; i < 64; i++) {	
			if (this->m_cases[i] != NULL && this->m_cases[i]->isBlack() == true && this->m_cases[i]->mouvementValide(*this, pos_x_roi, pos_y_roi)) {
				int tab_echec_pos[2] = {this->m_cases[i]->x() ,this->m_cases[i]->y()};
				tab_echec[compteur_tab] = tab_echec_pos;
				compteur_tab++;
			}
		}

		//Pour toutes les pièces pouvant mettre le roi en échec on regarde si un allié peut le sauver.
		for (int i = 0; i < compte_echec; i++) {
			for (int j = 0; j < 64; j++) {
				if (this->m_cases[j] != NULL && this->m_cases[j]->isWhite() == true) {

					if (pos_x_roi == tab_echec[i][0]) {
						if (pos_y_roi < tab_echec[i][1]) {
							for (int y = pos_y_roi + 1; y <= tab_echec[i][1]; y++) {
								if (this->m_cases[j]->mouvementValide(*this, tab_echec[i][0], y) == true && this->m_cases[j]->type() != 'R') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_x_roi == tab_echec[i][0]) {
						if (pos_y_roi > tab_echec[i][1]) {
							for (int y = tab_echec[i][1]; y < pos_y_roi - 1; y++) {
								if (this->m_cases[j]->mouvementValide(*this, tab_echec[i][0], y) == true && this->m_cases[j]->type() != 'R') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_y_roi == tab_echec[i][1]) {
						if (pos_x_roi < tab_echec[i][0]) {
							for (int y = pos_x_roi + 1; y <= tab_echec[i][0]; y++) {
								if (this->m_cases[j]->mouvementValide(*this, y, tab_echec[i][1]) == true && this->m_cases[j]->type() !='R') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_y_roi == tab_echec[i][1]) {
						if (pos_x_roi > tab_echec[i][0]) {
							for (int y = tab_echec[i][0]; y < pos_x_roi; y++) {
								if (this->m_cases[j]->mouvementValide(*this, y, tab_echec[i][1]) == true && this->m_cases[j]->type() != 'R') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_x_roi > tab_echec[i][0] && pos_y_roi > tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'c' ) {
						int axe_y = tab_echec[i][1];
						for (int y = tab_echec[i][0]; y < pos_x_roi - 1 ; y++) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'R') {
								free(tab_echec);
								return false;
							}
							axe_y++;
						}
					}

					else if (pos_x_roi < tab_echec[i][0] && pos_y_roi < tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'c') {
						int axe_y = pos_y_roi + 1;
						for (int y = pos_x_roi + 1; y <= tab_echec[i][0]; y++) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'R') {
								free(tab_echec);
								return false;
							}
							axe_y++;
						}
					}

					else if (pos_x_roi > tab_echec[i][0] && pos_y_roi < tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'c') {
						int axe_y = pos_y_roi + 1;
						for (int y = pos_x_roi - 1 ; y >= tab_echec[i][0]; y--) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'R') {
								free(tab_echec);
								return false;
							}
							axe_y++;
						}
					}

					else if (pos_x_roi < tab_echec[i][0] && pos_y_roi > tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'c') {
						int axe_y = pos_y_roi - 1;
						for (int y = pos_x_roi + 1; y >= tab_echec[i][0]; y++) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'R') {
								free(tab_echec);
								return false;
							}
							axe_y--;
						}
					}

					else if (this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() == 'c' && this->m_cases[j]->type() != 'R') {
						if (this->m_cases[j]->mouvementValide(*this, tab_echec[i][0], tab_echec[i][1]) == true) {
							return false;
						}
					}
					else{
						free(tab_echec);
						return true;
					}
				}
			}
		}
		free(tab_echec);
	}

	//On trouve le roi noir.
	else if (this->echec(false) != NULL) {
		for (int i = 0; i < 64; i++) {
			if (this->m_cases[i] != NULL && this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y())->type() == 'r') {
				pos_x_roi = this->m_cases[i]->x();
				pos_y_roi = this->m_cases[i]->y();
			}
		}

		//On compte le nombre de pièces blanches pouvant le mettre en échec.
		for (int i = 0; i < 64; i++) {
			if (this->m_cases[i] != NULL && this->m_cases[i]->isWhite() == true && this->m_cases[i]->mouvementValide(*this, pos_x_roi, pos_y_roi)) {
				compte_echec++;
			}
		}

		//On créé un tableau avec toutes les pièces pouvant atteeindre le roi.
		int** tab_echec = (int**)malloc(sizeof(int*)*compte_echec);
		if (tab_echec == NULL) {
			cout << "Probleme de memoire verif_echec_mat" << endl;
			exit(1);
		}

		//On rentre la position des pièce pouvant atteindre le roi.
		for (int i = 0; i < 64; i++) {

			if (this->m_cases[i] != NULL && this->m_cases[i]->isWhite() == true && this->m_cases[i]->mouvementValide(*this, pos_x_roi, pos_y_roi)) {
				int tab_echec_pos[2] = { this->m_cases[i]->x() ,this->m_cases[i]->y() };
				tab_echec[compteur_tab] = tab_echec_pos;
				compteur_tab++;
			}
		}

		//Pour toutes les pièces pouvant mettre le roi en échec on regarde si un allié peut le sauver.
		for (int i = 0; i < compte_echec; i++) {
			for (int j = 0; j < 64; j++) {
				if (this->m_cases[j] != NULL && this->m_cases[j]->isBlack() == true) {
					
					if (pos_x_roi == tab_echec[i][0]) {
						if (pos_y_roi < tab_echec[i][1]) {
							for (int y = pos_y_roi + 1; y <= tab_echec[i][1]; y++) {
								if (this->m_cases[j]->mouvementValide(*this, tab_echec[i][0], y) == true && this->m_cases[j]->type() != 'r') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_x_roi == tab_echec[i][0]) {
						if (pos_y_roi > tab_echec[i][1]) {
							for (int y = tab_echec[i][1]; y < pos_y_roi - 1; y++) {
								if (this->m_cases[j]->mouvementValide(*this, tab_echec[i][0], y) == true && this->m_cases[j]->type() != 'r') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_y_roi == tab_echec[i][1]) {
						if (pos_x_roi < tab_echec[i][0]) {
							for (int y = pos_x_roi + 1; y <= tab_echec[i][0]; y++) {
								if (this->m_cases[j]->mouvementValide(*this, y, tab_echec[i][1]) == true && this->m_cases[j]->type() != 'r') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_y_roi == tab_echec[i][1]) {
						if (pos_x_roi > tab_echec[i][0]) {
							for (int y = tab_echec[i][0]; y < pos_x_roi; y++) {
								if (this->m_cases[j]->mouvementValide(*this, y, tab_echec[i][1]) == true && this->m_cases[j]->type() != 'r') {
									free(tab_echec);
									return false;
								}
							}
						}
					}

					else if (pos_x_roi > tab_echec[i][0] && pos_y_roi > tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'C') {
						int axe_y = tab_echec[i][1];
						for (int y = tab_echec[i][0]; y < pos_x_roi - 1; y++) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'r') {
								free(tab_echec);
								return false;
							}
							axe_y++;
						}
					}

					else if (pos_x_roi < tab_echec[i][0] && pos_y_roi < tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'C') {
						int axe_y = pos_y_roi + 1;
						for (int y = pos_x_roi + 1; y <= tab_echec[i][0]; y++) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'r') {
								free(tab_echec);
								return false;
							}
							axe_y++;
						}
					}

					else if (pos_x_roi > tab_echec[i][0] && pos_y_roi < tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'C') {
						int axe_y = pos_y_roi + 1;
						for (int y = pos_x_roi - 1; y >= tab_echec[i][0]; y--) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'r') {
								free(tab_echec);
								return false;
							}
							axe_y++;
						}
					}

					else if (pos_x_roi < tab_echec[i][0] && pos_y_roi > tab_echec[i][1] && this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() != 'C') {
						int axe_y = pos_y_roi - 1;
						for (int y = pos_x_roi + 1; y >= tab_echec[i][0]; y++) {
							if (this->m_cases[j]->mouvementValide(*this, y, axe_y) == true && this->m_cases[j]->type() != 'r') {
								free(tab_echec);
								return false;
							}
							axe_y--;
						}
					}

					else if (this->getPiece(tab_echec[i][0], tab_echec[i][1])->type() == 'C' && this->m_cases[j]->type() != 'r') {
						if (this->m_cases[j]->mouvementValide(*this, tab_echec[i][0], tab_echec[i][1]) == true) {
							return false;
						}
					}
					else {
						free(tab_echec);
						return true;
					}
				}
			}
		}
		free(tab_echec);
	}
	
	return true;
}

//On teste pour une position donnée si le roi peut se sauver d'un echec.
bool Echiquier::test_echec_mat( bool white ,int x, int y) {
	if (white == true) {
		for (int i = 0; i < 64; i++) {
			if (this->m_cases[i] != NULL && this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y())->type() == 'R') {
				int pos_x = this->m_cases[i]->x();
				int pos_y = this->m_cases[i]->y();
				if (this->test_echec(true, (pos_x + x), (pos_y + y)) == true || this->getPiece(pos_x, pos_y) != NULL && this->getPiece(pos_x , pos_y)->mouvementValide(*this, (pos_x + x), (pos_y + y)) == false) {
					return true;
				}
			}
		}
		return false;
	}
	else {

		for (int i = 0; i < 64; i++) {
			if (this->m_cases[i] != NULL && this->getPiece(this->m_cases[i]->x(), this->m_cases[i]->y())->type() == 'r') {
				int pos_x = this->m_cases[i]->x();
				int pos_y = this->m_cases[i]->y();
				if (this->test_echec(false, (pos_x + x), (pos_y + y)) == true || this->getPiece(pos_x, pos_y) != NULL && this->getPiece(pos_x, pos_y)->mouvementValide(*this, (pos_x + x), (pos_y + y)) == false) {
					return true;
				}		
			}
		}
		return false;
	}
}

//On teste pour toutes les positions autour du roi si il peut y accéder puis, s'il est en echec, on regarde si c'est un echec et mat 
Piece* Echiquier::echec_mat() {
	//Pour les blancs
	if (this->echec(true) != NULL && this->echec(true)->isWhite() == true) {
		if (this->test_echec_mat(this->echec(true)->isWhite(), 1, 0) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(true)->isWhite(), 1, 1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(true)->isWhite(), 1, -1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(true)->isWhite(), 0, 1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(true)->isWhite(), 0, -1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(true)->isWhite(), -1, 0) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(true)->isWhite(), -1, 1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(true)->isWhite(), -1, -1) == false) {
			return NULL;
		}
		if(verif_echec_mat() == true)
			return this->echec(true);

	}

	//Pour les noirs
	else if (this->echec(false) != NULL && this->echec(false)->isBlack() == true) {
		if (this->test_echec_mat(this->echec(false)->isWhite(), 1, 0) == false) {
			return NULL;
		}

		if (this->test_echec_mat(this->echec(false)->isWhite(), 1, 1) == false) {
			return NULL;
		}

		if (this->test_echec_mat(this->echec(false)->isWhite(), 1, -1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(false)->isWhite(), 0, 1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(false)->isWhite(), 0, -1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(false)->isWhite(), -1, 0) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(false)->isWhite(), -1, 1) == false) {
			return NULL;
		}
		if (this->test_echec_mat(this->echec(false)->isWhite(), -1, -1) == false) {
			return NULL;
		}
		if (verif_echec_mat() == true) {
			return this->echec(false);
		}
	}
	return NULL;
}
/*
//Ne fonctionne pas, envoie un pointeur null dans affichage
void Echiquier::change(bool white, int pos_x, int pos_y) {
	char choix = NULL;
	while (choix != 'c' && choix != 'f' && choix != 't' && choix != 'r') {
		cout << "Choisissez la piece a remplacer par le pion (c = cavalier ; f = fou ; t = tour ; r = reine) :" << endl;
		cin >> choix;
	}
	if (choix == 'c') {
		this->enleverPiece(pos_x, pos_y);
		Cavalier cav = Cavalier(pos_x, pos_y, white);
		this->placer(&cav);
	}
	else if (choix == 'f') {
		this->enleverPiece(pos_x, pos_y);
		Fou cav = Fou(pos_x, pos_y, white);
		this->placer(&cav);
	}
	else if (choix == 't') {
		this->enleverPiece(pos_x, pos_y);
		Tour tour = Tour(pos_x, pos_y, white);
		this->placer(&tour);
	}
	else if (choix == 'r') {
		this->enleverPiece(pos_x, pos_y);
		Reine reine = Reine(pos_x, pos_y, white);
		this->placer(&reine);
	}
	else {
		cout << "Choix invaide !" << endl;
	}
}*/