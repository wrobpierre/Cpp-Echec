/**
* Header de JoueurBlanc.cxx
*
* @file JoueurBlanc.h
*/

#if !defined JoueurBlanc_h
#define JoueurBlanc_h


#pragma once
#include "Piece.h"
#include "Roi.h"
#include "Cavalier.h"
#include "pion.h"
#include "Echiquier.h"
#include "reine.h"
#include "fou.h"
#include "Tour.h"

class JoueurBlanc
{
protected:
	Piece *m_pieces[16];
public:
	JoueurBlanc();
	~JoueurBlanc();
	bool isWhite();
	bool isBlack();
	void init(bool white);
	bool placerPieces(Echiquier & e);
	void affiche();
};
#endif // !defined JoueurBlanc_h