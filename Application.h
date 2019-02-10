/*************************************************************************
                           Application  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ----------------
#if ! defined ( APPLICATION_H )
#define APPLICATION_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include "Requete.h"


//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Application>
// Cette classe permet de gerer les entrees sorties du programme. Elle gere
// les parametre passes a l'executable, leur validite ainsi que toute les
// specifications.
// Si tout est correcte, elle passe a l'analyse du fichier de log et renvoie
// l'analyse obtenue sur la sortie standard.
//------------------------------------------------------------------------

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool Traiter(const int argc, char *argv[]);
    // Mode d'emploi : traite les paramètres passé à l'executable
    // et execute le programme de traitement de fichier log
    // Contrat : argc argv doivent etre les variables passées
    // par le main, ou le nombre d'élément de argv doit etre égal a argc


//-------------------------------------------- Constructeurs - destructeur
    Application ();
    // Mode d'emploi : construit un objet de type application

    virtual ~Application ();


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool traiterLogs(const char * nomFichier);
    // Mode d'emploi : ouvre le fichier de log et lit chaque ligne et en fait
    // un objet de type requete.
    //  Si le fichier n'est pas ouvrable, le traitement est annule et renvoi false
    // Contrat : nomFichier doit etre une chaine de caractere valide
    // designant le chemin d'acces a un fichier de log.

//----------------------------------------------------- Attributs protégés
    Graphe graphe;
    Top top;
    bool faireGraphe;
    bool enleverExtensions;
    bool filtreHeure;
    int heure;
    unsigned nbLignesErronnees;
    unsigned nbLignesTraitees;
};

//-------------------------------- Autres définitions dépendantes de <Application>

#endif // APPLICATION_H
