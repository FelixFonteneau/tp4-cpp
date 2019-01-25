/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Graphe::AjouterArc(string referer, string cible)
// Algorithme : Recherche
{

	//recherche si le referer est dans le graphe
	Tgraphe::iterator iterateurReferer = structureDeDonne.find(referer);
	if (iterateurReferer != structureDeDonne.end()) 
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
		structureDeDonne.insert({referer,arc});
   	}

	//ajout des noeuds dans nombreDeNoeuds
	
	
} //----- Fin de AjouterArc


//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & os, const Graphe & graphe)
// Algorithme :
{
	

	return os;
} //----- Fin de la surchage de <<


//-------------------------------------------- Constructeurs - destructeur


Graphe::Graphe ( )
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

//----------------------------------------------------- Méthodes protégées

