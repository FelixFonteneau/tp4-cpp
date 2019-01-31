/************************************************************************
								Requete - description
								------------------ -
	début                : 25/01/2019
	copyright : (C)2019 par Félix Fonteneau et Houda Ouhssain
	e - mail : Felix.Fonteneau@insa-lyon.fr / houda.ouhssain@insa-lyon.fr
/************************************************************************* */

	//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

	//---------------------------------------------------------------- INCLUDE

	//-------------------------------------------------------- Include système
#include <iostream>
	using namespace std;

//------------------------------------------------------ Include personnel
#include "Requete.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
	void AjouterAuGraphe(Graphe * g) const;
	// Algorithme :
	// prend en paramètre un graphe auquel il ajoute une requete
	{

	} //----- Fin de Méthode


	void AjouterAuTop(Top * t) const;
	// Algorithme :
	//
	{

	} //----- Fin de Méthode

	string GetFichierDemande()const;
	// Algorithme :
	//
	{
		return fichierDemande;
	} //----- Fin de Méthode


	string GetReferer()const;
	// Algorithme :
	//
	{
		return referer;
	} //----- Fin de Méthode

	Date GetHeure()const;
	// Algorithme :
	//
	{
		return date.heure;
	} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = (const Requete & unRequete)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Requete::Requete(const Requete & unRequete)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur de copie)


//Requete::Requete()
// Algorithme :
//
//{
//#ifdef MAP
	//cout << "Appel au constructeur de <Requete>" << endl;
//#endif
//} //----- Fin de Requete

Requete::~Requete()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées