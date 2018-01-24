/**
 * Header de Echiquier.cxx
 *
 * @file Echiquier.h
 */

#if !defined Echiquier_h
#define Echiquier_h

#include "Piece.h"

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Echiquier
{
private:
  /**
   * Les cases de l'echiquier
   */
  Piece* m_cases[ 64 ];

public:

  /**
   * Constructeur par d�faut.
   * Initialise � vide l'echiquier.
   */
  Echiquier();

  /**
   * Recupere la piece situee sur une case.
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
  Piece* getPiece( int x, int y );

  /**
   * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
   *
   * @param p un pointeur vers une piece
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide )
   */
  bool placer( Piece* p );

  /**
   * Deplace une piece sur l'echiquier, des coordonnees specifiees
   * dans la piece aux coordonnees x,y.
   *
   * @param p un pointeur vers une piece
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide, piece pas
   * presente au bon endroit sur l'echiquier)
   */
  bool deplacer( Piece* p, int x, int y );

  /**
   * Enleve la piece situee sur une case (qui devient vide).
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et le pointeur
   * vers la piece enlevee sinon.
   */
  Piece* enleverPiece( int x, int y );

  /**
   * Affiche l'echiquier avec des # pour les cases noires et . pour
   * les blanches si elles sont vides, et avec B pour les pieces
   * blanches et N pour les pieces noires.
   */
  void affiche();

  /**
  * V�rifie que les rois ne sont pas en echec.
  *
  * @param white est un bool�en, il d�termine si on v�rifie le roi blanc ou pas (dans ce cas noir).
  *
  *
  * @return NULL si le roi n'est pas en echec sinon retourne le roi qui est en echec (noir ou blanc).
  *
  */
  Piece* echec(bool white);

  /**
  * V�rifie pour un emplcament donn� que la zone n'est pas en echec (utilis� avant le d�placement du roi)
  *
  * @param white est un bol�en qui d�termine si la pi�ce fictive est blanche ou noire.
  * @param x un entier entre 1 et 8
  * @param y un entier entre 1 et 8
  *
  * @return false si aucune piece ne met en echec cette case et true sinon.
  *
  */
  bool test_echec(bool white, int x, int y);

  /**
  * V�rifie pour toutes les pi�ces alli�es si elle peuvent sauver le roi d'un echec et mat.
  *
  * @return false si le roi peut �tre sauver, true sinon.
  *
  */
  bool verif_echec_mat();

  /**
  * Test pour un roi en echec si un d�placement peut le sauver.
  *
  * @param white est un bol�en qui d�termine si la pi�ce fictive est blanche ou noire.
  * @param x un entier entre 1 et 8
  * @param y un entier entre 1 et 8
  *
  * @return false si le roi peut se d�placer, true sinon.
  *
  */
  bool test_echec_mat(bool white, int x, int y);

  /**
  * V�rifie si les rois sont en echec et mat
  *
  * @return NULL si aucun roi n'est en echec, le roi en echec sinon.
  *
  */
  Piece* echec_mat();

  //void change(bool white, int pos_x, int pos_y);

};

#endif // !defined Echiquier_h
