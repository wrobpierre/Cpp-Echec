#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Roi.h"
#include "Cavalier.h"
#include "pion.h"
#include "Echiquier.h"
#include "reine.h"
#include "fou.h"
#include "Tour.h"

class Joueur
{
/*private:
    Piece *m_pieces[16];
	*/

public:
    //Joueur( bool white );
    Joueur();
    ~Joueur();

    //void init( bool white );
    //void affiche();
    //bool placerPieces(Echiquier & e);
};
/*
class JoueurBlanc : public Joueur {
public:
        JoueurBlanc();
        ~JoueurBlanc();

        bool isWhite();
        bool isBlack();
};

class JoueurNoir : public Joueur {
public:
        JoueurNoir();
        ~JoueurNoir();

        bool isWhite();
        bool isBlack();
};*/
#endif // !defined Joueur_h
