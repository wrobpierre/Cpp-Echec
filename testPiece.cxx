/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <typeinfo>
#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"
#include "Echiquier.h"


// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  JoueurNoir jn;
  JoueurBlanc jb;
  int pos_x = 0;
  int pos_y = 0;
  int move_x;
  int move_y;
  int nb_move = 0;
  bool valid_move = true;
  bool est_echec = false;

  Echiquier e;
  e.affiche();


  bool piecesOK;
  piecesOK = jn.placerPieces(e);
  assert(piecesOK);
  piecesOK = jb.placerPieces(e);
  assert(piecesOK);
  e.affiche();

  while(e.echec_mat() == NULL) {
	  move_x = -1;
	  move_y = -1;
	  est_echec = false;
	  
	  //déplacement des pièces blanches.
	  if (nb_move % 2 == 0) {
		  //Tant que le mouvement est invalide.
		  while (e.getPiece(pos_x, pos_y) == 0 || e.getPiece(pos_x, pos_y)->isWhite() == false || e.getPiece(pos_x, pos_y)->mouvementValide(e, move_x, move_y) == false || est_echec == true) {
			e.affiche();

			//Teste echec et echec
			if (e.echec(true) != NULL && e.echec(true)->isWhite() == true)
				cout << "Echec !" << endl;

			cout << "C'est au tour des blancs." << endl; 
			cout << "Quelle piece deplacer (pour x)?" << endl;
			cin >> pos_x;
			cout << "Quelle piece deplacer (pour y)?" << endl;
			cin >> pos_y;
			cout << "Ou la deplacer (pour x)?" << endl;
			cin >> move_x;
			cout << "Ou la deplacer (pour y)?" << endl;
			cin >> move_y;

			//Teste mouvement valide et echec du roi
			if (e.getPiece(pos_x, pos_y) == 0 || e.getPiece(pos_x, pos_y)->mouvementValide(e, move_x, move_y) == false)
				cout << "Mouvement invalide" << endl;
			else {
				est_echec = false;
				if (e.echec(true) != NULL && e.echec(true)->isWhite() == true) {
					est_echec = true;
					if (e.getPiece(pos_x, pos_y) != 0 && (e.getPiece(pos_x, pos_y)->type() == 'R' && e.test_echec(e.echec(true)->isWhite(), move_x, move_y) == false) || e.verif_echec_mat()==false)
						est_echec = false;
				}
				if (e.getPiece(pos_x, pos_y) != 0 && e.getPiece(pos_x, pos_y)->type() == 'R' && e.test_echec(true, move_x, move_y) == true) 
					est_echec = true;
			}
				
		  }
		  e.deplacer(e.getPiece(pos_x, pos_y), move_x, move_y);

		  //Appel de fonction echange (ne fonctionne pas)
		  /*if (e.getPiece(move_x, move_y) != NULL && e.getPiece(move_x, move_y)->type() == 'P' && e.getPiece(move_x, move_y)->isWhite() == true && move_y == 8) {
			  e.change(true, move_x, move_y);
		  }*/

		  est_echec = false;
	  }

	  //déplacement des pièces blanches.
	  else {

		  //Tant que le mouvement est invalide.
		  while (e.getPiece(pos_x, pos_y) == 0 || e.getPiece(pos_x, pos_y)->isBlack() == false || e.getPiece(pos_x, pos_y)->mouvementValide(e, move_x, move_y) == false || est_echec == true) {
			  e.affiche();

			  //Teste echec et echec
			  if (e.echec(false) != NULL && e.echec(false)->isBlack() == true)
				  cout << "Echec !" << endl;
			  cout << "C'est au tour des noirs." << endl;
			  cout << "Quelle piece deplacer (pour x)?" << endl;
			  cin >> pos_x;
			  cout << "Quelle piece deplacer (pour y)?" << endl;
			  cin >> pos_y;
			  cout << "Ou la deplacer (pour x)?" << endl;
			  cin >> move_x;
			  cout << "Ou la deplacer (pour y)?" << endl;
			  cin >> move_y;

			  //Teste mouvement valide et echec du roi
			  if (e.getPiece(pos_x, pos_y) == 0 || e.getPiece(pos_x, pos_y)->mouvementValide(e, move_x, move_y) == false)
				  cout << "Mouvement invalide" << endl;
			  else {
				  est_echec = false;
				  if (e.echec(false) != NULL && e.echec(false)->isBlack() == true) {
					  est_echec = true;
					  if (e.getPiece(pos_x, pos_y) != 0 && e.getPiece(pos_x, pos_y)->type() == 'r' && e.test_echec(e.echec(false)->isBlack(), move_x, move_y) == false)
						  est_echec = false;
				  }
				  if (e.getPiece(pos_x, pos_y) != 0 && e.getPiece(pos_x, pos_y)->type() == 'r' && e.test_echec(false, move_x, move_y) == true)
					  est_echec = true;
			  }
		  }
		  e.deplacer(e.getPiece(pos_x, pos_y), move_x, move_y);

		  //Appel de fonction echange (ne fonctionne pas)
		  /*if (e.getPiece(move_x, move_y) != NULL && e.getPiece(move_x, move_y)->type() == 'p' && e.getPiece(move_x, move_y)->isBlack() == true && move_y == 1) {
			  e.change(false, move_x, move_y);
		  }*/

		  est_echec = false;
	  }
	  nb_move ++;
  }

  //Echec et mat et fin du jeu
  int fin = 0;
  cout << "Echec et mat !!!!" << endl;
  cout << "Appuez sur une touche puis entree pour sortir" << endl;
  cin >> fin;
  return 0;
}
