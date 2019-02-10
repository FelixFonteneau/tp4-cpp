/*************************************************************************
                           Graphe  -  description
                             -------------------
    debut                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Realisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques

void Graphe::AjouterArc(string referer, string cible)
{
	ajouterGraphe(referer,cible);
	ajouterNoeud(referer);
	ajouterNoeud(cible);
} //----- Fin de AjouterLog


//------------------------------------------------- Surcharge d'operateurs
ostream & operator << (ostream & os, const Graphe & graphe)
// Algorithme :
{
	os <<  "digraph {\n";
	if( graphe.nombreDeNoeuds != 0)
	{
		unordered_map<string,string>::const_iterator debutNoeud, finNoeud;
		debutNoeud = graphe.listeDesNoeuds.begin();
		finNoeud = graphe.listeDesNoeuds.end();

		while(debutNoeud != finNoeud)
		{
			os << debutNoeud->second << " [label=\"" << debutNoeud->first << "\"];\n";
			debutNoeud++;
		}

		Graphe::Tgraphe::const_iterator debutReferer, finReferer;
		unordered_map<string,int>::const_iterator debutCible, finCible;

		debutReferer = graphe.catalogueDesArcs.begin();
		finReferer = graphe.catalogueDesArcs.end();
		while(debutReferer != finReferer)
		{
			debutCible = debutReferer->second.begin();
			finCible = debutReferer->second.end();
			while(debutCible != finCible)
			{
					os << graphe.listeDesNoeuds.find(debutReferer->first)->second;
					os << " -> ";
					os << graphe.listeDesNoeuds.find(debutCible->first)->second;
					os << " [label=\"" << debutCible->second << "\"];\n";
					debutCible++;
			}
			debutReferer++;
		}
	}
	os << "}";
	return os;
} //----- Fin de la surchage de <<


//-------------------------------------------- Constructeurs - destructeur


Graphe::Graphe ( ) : nombreDeNoeuds(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif
} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

void Graphe::ajouterGraphe(string referer, string cible)
// Algorithme : Recherche si le referer et la cible existent dans le catalogue
// Les ajoutes si necessaire, incremente le poid de l'arc sinon
{

	//recherche si le referer est dans le graphe
	Tgraphe::iterator iterateurReferer = catalogueDesArcs.find(referer);
	if (iterateurReferer != catalogueDesArcs.end())
	{
#ifdef MAP
    cout << "Referer Trouvee" << endl;
#endif
		//recherche si la cible est dans un arc du referer
		unordered_map<string, int >::iterator iterateurCible =
			iterateurReferer->second.find(cible);
		if( iterateurCible != iterateurReferer->second.end())
		{
#ifdef MAP
    cout << "Cible Trouvee" << endl;
#endif
			++iterateurCible->second;
		}
		else
		{
#ifdef MAP
    cout << "Cible non Trouvee" << endl;
#endif
			iterateurReferer->second.insert({cible,1});
		}
  }
	else
	{
#ifdef MAP
    cout << "Referer non trouvee, ajout" << endl;
#endif
		unordered_map<string, int > arc = {{cible,1}};//cree un arc de poid 1 vers cible
		catalogueDesArcs.insert({referer,arc});
  }
} //----- Fin de ajouterGraphe



void Graphe::ajouterNoeud(string noeud)
{
	// on verifie si le noeud est deja present, sinon on l'ajoute
	unordered_map<string,string>::iterator iterateurNoeud = listeDesNoeuds.find(noeud);
	if( iterateurNoeud == listeDesNoeuds.end() )
	{
		// concatenation de "node" et de l'entier nombreDeNoeuds pour l'ajouter
		// a la valeur de la clef noeud
		stringstream streamString;
		streamString << "node" << nombreDeNoeuds++;
		listeDesNoeuds.insert({noeud,streamString.str()});
	}

} //----- Fin de ajouterNoeud
