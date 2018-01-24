#include "JoueurNoir.h"
#include "Joueur.h"
#include <iostream>

using namespace std;

JoueurNoir::JoueurNoir() {
	init(false);
}

JoueurNoir::~JoueurNoir()
{
	for (int i = 0; i < 16; i++)
		delete m_pieces[i];
}

bool
JoueurNoir::isWhite()
{
	return false;
}

bool
JoueurNoir::isBlack()
{
	return true;
}

void JoueurNoir::init(bool white)
{
	int n = 0;
	for (int i = 1; i <= 8; i++)
	{
		m_pieces[n++] = new Pion(i, white);
	}
	m_pieces[n++] = new Roi(white);
	m_pieces[n++] = new Reine(white);
	m_pieces[n++] = new Cavalier(white, true);
	m_pieces[n++] = new Cavalier(white, false);
	m_pieces[n++] = new Fou(white, true);
	m_pieces[n++] = new Fou(white, false);
	m_pieces[n++] = new Tour(white, true);
	m_pieces[n++] = new Tour(white, false);
}

bool JoueurNoir::placerPieces(Echiquier & e)
{
	bool returned = true;
	for (int i = 0; i < 16; i++)
		returned &= e.placer(m_pieces[i]);

	return returned;
}

void JoueurNoir::affiche()
{
	for (int i = 0; i < 16; i++)
		m_pieces[i]->affiche();
}