/*************************************************************************
                           Application  -  description
                             -------------------
    debut                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Realisation de la classe <Application> (fichier Application.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include<cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "Requete.h"



//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
bool Application::Traiter(const int argc, char *argv[])
// Algorithme : verifie les specifications puis analyse le fichier
// et affiche le resultat sur la sortie standard
{
  bool bonneExecution = true;
  ofstream fichierGraphe;

  if(argc <=2)
  {
    cerr << "Pas assez de parametres sont passes a l'executable : " << argv[0] << endl;
    return false;
  }

  //on regarde toutes les options passees
  for (int i(1); i < argc-1; i++)
  {

	  if (strcmp(argv[i], "-g") == 0)
	  {
			  //verification que l'argument suivant est un fichier.dot
			  string s = argv[i + 1];
			  if (s.compare(s.size() - 3, 3, "dot") == 0)
			  {
				  faireGraphe = true;
				  fichierGraphe.open(argv[i + 1], ofstream::out);
				  bonneExecution = fichierGraphe.good();
			  }
			  else
			  {
				  cerr << "Extension du fichier graphe non valide : Graphe non genere" << endl;
			  }
	  }
	  
	 

    if( strcmp(argv[i], "-e") == 0)
    {
      enleverExtensions = true;
    }
    if( strcmp(argv[i], "-t") == 0)
    {
			heure = atoi(argv[i + 1]);
			//Verification du format de l'heure
			if (heure < 0 || heure >= 24)
			{
				cerr << "Format de l'heure non valide" << endl;
			}
			else
			{
				filtreHeure = true;
			}
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
    cout << nbLignesTraitees << " ligne(s) traitees, " << nbLignesErronnees
         << " ligne(s) erronees" << endl;
  }
  return bonneExecution;

} //----- Fin de Traiter


//------------------------------------------------- Surcharge d'operateurs

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

//----------------------------------------------------- Methodes protegees
bool Application::traiterLogs(const char * nomFichier)
// Algorithme :
//
{
	//Verification que le fichier en entree a bien une extension .log
	const string s = nomFichier;
	if (s.compare(s.size() - 3, 3, "log") == 0|| s.compare(s.size() - 3, 3, "txt") == 0)
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

			//on verifie les specifications avant d'ajouter
			if ((!filtreHeure || (filtreHeure && requete.FiltreHeure(heure))) &&
				(!enleverExtensions || (enleverExtensions && !requete.FiltreDoc())))
			{
				if (faireGraphe)
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
	}
	else
	{
		cerr << "Extension du fichier à analyser non valide : doit être un .log ou un .txt" << endl;
		return false;
	}

} //----- Fin de Traiter
