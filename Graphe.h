/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( GRAPHE_H )
#define GRAPHE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <unordered_map>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe> : Permet de creer un structure de donnees 
// representant un graphe de log. Les noeuds du graphe sont de type string. 
// Le poid des arcs sont de type entier.
//------------------------------------------------------------------------


class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	void AjouterArc(string referer, string cible);
    // Mode d'emploi : Ajoute, si besoin les noeuds referer et cible et l'arc 
    // au graphe. Sinon Augmente le poid du noeud visé existant.



    // Mode d'emploi : Affiche le graphe actuel sur la sortie standard 
    // sous la forme "GraphViz".



//------------------------------------------------- Surcharge d'opérateurs

	friend ostream & operator << (ostream &, const Graphe & graphe);
    // Mode d'emploi : Affiche le graphe actuel sur la sortie standard 
    // sous la forme "GraphViz".

//-------------------------------------------- Constructeurs - destructeur

    Graphe ( ) : nombreDeNoeuds(0);
    // Mode d'emploi : construit un graphe vide.
 

    virtual ~Graphe ( );
    // Mode d'emploi : detruit le graphe actuel
  

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
	typedef unordered_map<string, unordered_map<string, int > > Tgraphe;
	Tgraphe structureDeDonne;
	unordered_map<string,string> listeDesNoeuds;
	unsigned int nombreDeNoeuds;

};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // GRAPHE_H

