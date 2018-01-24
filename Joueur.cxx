#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
    cout << "Création de joueur sans paramètres " << endl;
}

Joueur::~Joueur()
{
	cout << "Destruction de joueur sans paramètres " << endl;
}

/*Joueur::Joueur(bool white)
{
    init(white);
}

Joueur::~Joueur()
{
    for (int i=0 ; i < 16 ; i++)
        delete m_pieces[i];
}

void
Joueur::init(bool white)
{
    int n = 0;
    for (int i=1; i<=8; i++)
    {
        m_pieces[n++] = new Pion(i,white);
    }
    m_pieces[n++] = new Roi(white);
    m_pieces[n++] = new Reine(white);
    m_pieces[n++] = new Cavalier(white,true);
    m_pieces[n++] = new Cavalier(white,false);
    m_pieces[n++] = new Fou(white,true);
    m_pieces[n++] = new Fou(white,false);
    m_pieces[n++] = new Tour(white,true);
    m_pieces[n++] = new Tour(white,false);
}

void
Joueur::affiche()
{
    for (int i=0; i < 16; i++)
        m_pieces[i]->affiche();
}

bool
Joueur::placerPieces(Echiquier & e)
{
    bool returned = true;
    for (int i=0; i < 16; i++)
        returned &= e.placer(m_pieces[i]);

    return returned;
}


JoueurBlanc::JoueurBlanc() {
    init(true);
}

JoueurBlanc::~JoueurBlanc()
{
    cout << "Destruction de joueur blanc " << endl;
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

JoueurNoir::JoueurNoir() {
    init(false);
}

JoueurNoir::~JoueurNoir()
{
    cout << "Destruction de joueur noir " << endl;
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
}*/
