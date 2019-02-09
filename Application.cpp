/*************************************************************************
                           Application  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "Requete.h"
#include "Graphe.h"
#include "Top.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Application::Traiter(const int argc, char *argv[])
// Algorithme : verifie les specifications puis analyse le fichier
// et affiche le resultat sur la sortie standard
{
  bool bonneExecution = true;
  ofstream fichierGraphe;

  if(argc < 2)
  {
    cerr << "Pas assez de paramètres sont passé à l'executable : " << argv[0] << endl;
    return false;
  }

  //on regarde toutes les options passees
  for (int i(1); i < argc-1; i++)
  {
    if( strcmp(argv[i], "-g") == 0)
    {
      faireGraphe = true;

      //verification de
      fichierGraphe.open(argv[i+1], ofstream::out);
      bonneExecution = fichierGraphe.good();
    }
    if( strcmp(argv[i], "-e") == 0)
    {
      enleverExtensions = true;
    }
    if( strcmp(argv[i], "-t") == 0)
    {
      filtreHeure = true;
      heure = atoi(argv[i+1]);
    }
  }

  if( bonneExecution && (bonneExecution = traiterLogs(argv[argc-1])) )
  {
    cout << "Resultat du traitement du fichier : " << argv[argc-1] << endl;
    if(faireGraphe)
    {
      fichierGraphe << graphe;
    }
    else
    {
      cout << top;
    }
    cout << nbLignesTraitees << " ligne(s) traitées, " << nbLignesErronnees
         << " ligne(s) erronées" << endl;
  }
  return bonneExecution;

} //----- Fin de Traiter


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Application::Application ():
    graphe(), top(10), faireGraphe(false), enleverExtensions(false),
    filtreHeure(false), heure(0), nbLignesErronnees(0), nbLignesTraitees(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif
} //----- Fin de Application


Application::~Application ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Application>" << endl;
#endif
} //----- Fin de ~Application


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
bool Application::traiterLogs(const char * nomFichier)
// Algorithme :
//
{
  char c;
  ifstream fichierLogs(nomFichier, ifstream::in);
  if (!fichierLogs.good())
  {
    cerr << "Erreur d'ouverture du fichier de log : " << nomFichier << endl;
    return false;
  }

  Requete requete;

  while (fichierLogs.good())
  {
    fichierLogs >> requete;

    //on verifie les specifications avnat d'ajouter
    if( (!filtreHeure || (filtreHeure && requete.FiltreHeure(heure))) &&
        (!enleverExtensions || (enleverExtensions && !requete.FiltreDoc())) )
    {
      if(faireGraphe)
      {
        nbLignesErronnees = requete.AjouterAuGraphe(graphe) ? nbLignesErronnees : nbLignesErronnees + 1;
      }
      else
      {
        nbLignesErronnees = requete.AjouterAuTop(top) ? nbLignesErronnees : nbLignesErronnees + 1;
      }
      ++nbLignesTraitees;
    }
    c = fichierLogs.get();

    //on sort car il ne reste juste un caractere vide qui peut troubler l'analyse
    if (c == '\n')
    {
      break;
    }
    fichierLogs.putback(c);
  }

  fichierLogs.close();
  return true;

} //----- Fin de Traiter
