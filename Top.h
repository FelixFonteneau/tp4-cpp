/*************************************************************************
                           Top  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Top> (fichier Top.h) ----------------
#if ! defined ( TOP_H )
#define TOP_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <unordered_map>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Top> : Permet de creer une structure de donnees
// representant un top de string.
// A l'affichage, seul les n strings les plus ajoutee seront affichees
//------------------------------------------------------------------------

class Top
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void AjouterCible(string cible);
    // Mode d'emploi :
    // Ajoute la cible au top
    // si elle y est deja elle incremente son compteur


//------------------------------------------------- Surcharge d'opérateurs

  friend ostream & operator << (ostream & os, const Top & top);
  // Mode d'emploi : Affiche le top actuel sur la sortie standard


//-------------------------------------------- Constructeurs - destructeur

    Top (unsigned nbTop );
    // Mode d'emploi : creer un objet top avec le nombre de top a afficher
    // Contrat : passer un unsigned en parametre

    virtual ~Top ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  unsigned nombreDeTops;
typedef unordered_map<string, unsigned > Tcible;
Tcible listeDesCibles;

};

//-------------------------------- Autres définitions dépendantes de <Top>

#endif // TOP_H
