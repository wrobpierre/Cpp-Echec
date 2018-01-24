#pragma once
/**
* Header de JoueurNoir.cxx
*
* @file JoueurNoir.h
*/

#if !defined JoueurNoir_h
#define JoueurNoir_h

#include "Piece.h"
#include "Roi.h"
#include "Cavalier.h"
#include "pion.h"
#include "Echiquier.h"
#include "reine.h"
#include "fou.h"
#include "Tour.h"

class JoueurNoir
{
protected:
	Piece *m_pieces[16];
public:
	JoueurNoir();
	~JoueurNoir();
	bool isWhite();
	bool isBlack();
	void init(bool white);
	bool placerPieces(Echiquier & e);
	void affiche();
};
#endif // !defined JoueurNoir_h