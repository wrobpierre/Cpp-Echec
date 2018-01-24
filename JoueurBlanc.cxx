#include "JoueurBlanc.h"
#include "Joueur.h"
#include <iostream>

using namespace std;

JoueurBlanc::JoueurBlanc() {
	init(true);
}

JoueurBlanc::~JoueurBlanc()
{
	for (int i = 0; i < 16; i++)
		delete m_pieces[i];
}

bool
JoueurBlanc::isWhite()
{
	return true;
}

bool
JoueurBlanc::isBlack()
{
	return false;
}

void JoueurBlanc::init(bool white)
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

bool JoueurBlanc::placerPieces(Echiquier & e)
{
	bool returned = true;
	for (int i = 0; i < 16; i++)
		returned &= e.placer(m_pieces[i]);

	return returned;
}

void JoueurBlanc::affiche()
{
	for (int i = 0; i < 16; i++)
		m_pieces[i]->affiche();
}