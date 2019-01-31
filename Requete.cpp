/************************************************************************
								Requete - description
								------------------ -
	d�but                : 25/01/2019
	copyright : (C)2019 par F�lix Fonteneau et Houda Ouhssain
	e - mail : Felix.Fonteneau@insa-lyon.fr / houda.ouhssain@insa-lyon.fr
/************************************************************************* */

	//---------- R�alisation de la classe <Requete> (fichier Requete.cpp) ------------

	//---------------------------------------------------------------- INCLUDE

	//-------------------------------------------------------- Include syst�me
#include <iostream>
	using namespace std;

//------------------------------------------------------ Include personnel
#include "Requete.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
	void AjouterAuGraphe(Graphe * g) const;
	// Algorithme :
	// prend en param�tre un graphe auquel il ajoute une requete
	{

	} //----- Fin de M�thode


	void AjouterAuTop(Top * t) const;
	// Algorithme :
	//
	{

	} //----- Fin de M�thode

	string GetFichierDemande()const;
	// Algorithme :
	//
	{
		return fichierDemande;
	} //----- Fin de M�thode


	string GetReferer()const;
	// Algorithme :
	//
	{
		return referer;
	} //----- Fin de M�thode

	Date GetHeure()const;
	// Algorithme :
	//
	{
		return date.heure;
	} //----- Fin de M�thode



//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es