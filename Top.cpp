/*************************************************************************
                           Top  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Top> (fichier Top.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Top.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Top::AjouterCible(string cible)
//Algorithme :
//
{
  Tcible::iterator iteratorCible = listeDesCibles.find(cible);

  //cible existante
  if (iteratorCible != listeDesCibles.end())
  {
    ++iteratorCible->second;
  }

  //pas trouvee
  else
  {
    listeDesCibles.insert({cible,1});
  }
} //----- Fin de AjouterCible

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & os, const Top & top)
// Algorithme : Pour créer le top, on ne peut pas trier selon le nombre d'finNbIteration
// de listeDesCibles car le second membre n'est pas un clef.
// La solution est donc d'ajouter toutes les valeur à une multimap en inversant
// clef et valeur. Puis on prend les n plus grandes clefs (nb iterations).
{
  typedef multimap<unsigned, string > Ttop;
  Ttop listeOrdonnee;

  Top::Tcible::const_iterator debutCible, finCible;
  debutCible = top.listeDesCibles.begin();
  finCible = top.listeDesCibles.end();

  while (debutCible != finCible)
  {
    listeOrdonnee.insert({debutCible->second,debutCible->first});
    debutCible++;
  }

  Ttop::const_reverse_iterator debutNbIteration, finNbIteration;
  finNbIteration = listeOrdonnee.rend();
  debutNbIteration = listeOrdonnee.rbegin();

  os << "Liste des sites les plus demandés : " << endl;
  for(unsigned i(1); (i <= top.nombreDeTops) && (debutNbIteration != finNbIteration); i++)
  {
    os << "  " << i << " - " << debutNbIteration->second << " demandé ";
    os << debutNbIteration->first << " fois " << endl;
    debutNbIteration++;
  }

  return os;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

Top::Top (unsigned nbTop ) : nombreDeTops(nbTop)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Top>" << endl;
#endif
} //----- Fin de Top


Top::~Top ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Top>" << endl;
#endif
} //----- Fin de ~Top


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
