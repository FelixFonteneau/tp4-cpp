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




	bool ValiderLigne(string ligne)
	{
		
		/*
		regex re("^\d{3}\.\d{3}\.\d{1}\s-\s-\s\[d{2}\\[a-zA-Z]{3}$\\d{4}:d{2}:d{2}:d{2}\+d{4}\"[A-Z]*\s\\[a-zA-Z]*\s\\d{3}\sd*");
		bool result =regex_match(ligne, re);
		return result;

		/*
		var yearReg = '(201[4-9]|202[0-9])';            ///< Allows a number between 2014 and 2029
		var monthReg = '(0[1-9]|1[0-2])';               ///< Allows a number between 00 and 12
		var dayReg = '(0[1-9]|1[0-9]|2[0-9]|3[0-1])';   ///< Allows a number between 00 and 31
		var hourReg = '([0-1][0-9]|2[0-3])';            ///< Allows a number between 00 and 24
		var minReg = '([0-5][0-9])';                    ///< Allows a number between 00 and 59
		var reg = new RegExp('^' + yearReg + '-' + monthReg + '-' + dayReg + ' ' + hourReg + ':' + minReg + '$', 'g');
		*/

	}

     void Requete::AjouterAuGraphe(Graphe * g)
	// Algorithme :
	
	{
		g->AjouterArc(referer, fichierDemande);

	} //----- Fin de Méthode


	void Requete::AjouterAuTop(Top * t)
	// Algorithme :
	//
	{
		t->AjouterCible(fichierDemande);
	} //----- Fin de Méthode



//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = (const Requete & unRequete)
// Algorithme :
//
{
} //----- Fin de operator =

istream & operator >> (istream & is, const Requete & requete)
{
	string ligne;
	getline(is, ligne);
	if (ValiderLigne(ligne))
	{
		
	}

}
ostream & operator << (ostream & os, const Requete & requete)
{
	// Algorithme :
	os << requete.userLogName;
	os << requete.authentificateUser;
	//os << requete.date;
	os << requete.ProtocoleUtilise;
	os << requete.fichierDemande;
	os << requete.returnCode;
	os << requete.tailleReponseOctet;
	os << requete.referer;
	os << requete.identificationNavigateur;

}


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