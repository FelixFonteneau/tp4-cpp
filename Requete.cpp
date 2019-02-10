/************************************************************************
								Requete - description
								------------------ -
	debut                : 25/01/2019
	copyright : (C)2019 par Felix Fonteneau et Houda Ouhssain
	e - mail : Felix.Fonteneau@insa-lyon.fr / houda.ouhssain@insa-lyon.fr
**************************************************************************/

	//---------- Realisation de la classe <Requete> (fichier Requete.cpp) ------------

	//---------------------------------------------------------------- INCLUDE

	//-------------------------------------------------------- Include systeme
#include <iostream>
using namespace std;
#include <algorithm>
#include <regex>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques

  bool Requete::AjouterAuGraphe(Graphe &g) const
	{
		if(valide && returnCode==200)
		{
			g.AjouterArc(referer, fichierDemande);
		}
		return valide;
	} //----- Fin de Methode


	bool Requete::AjouterAuTop(Top &t)const
	{
		if(valide && returnCode == 200)
		{
			t.AjouterCible(fichierDemande);
		}
		return valide;
	} //----- Fin de Methode

	bool Requete::FiltreDoc() const
	// Algorithme : traite le document de facon e ne laisser
	//que l'extension, puis compare l'extension avec celle
	//d'un doc de type image, css ou javascript
	{
		bool exclu=true;
		string extension = fichierDemande;
		int i = extension.find_last_of(".");
		extension.erase(0, i + 1);
		if (extension == "jped" || extension == "gif" || extension == "jpg" || extension == "png"
			|| extension == "tif" || extension == "css" || extension == "js")
		{
			return exclu;
		}
		return !exclu;

	}//----- Fin de Methode

	bool Requete::FiltreHeure( const int &heure) const
	{
		if (date.heure == heure)
		{
			return true;
		}
		else
		{
			return false;
		}
	}//----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs

istream & operator >> (istream & fluxDentre,  Requete & requete)
{
	string lesEntiers;
	string ligne;
	getline(fluxDentre,ligne);
	if( (requete.valide = requete.validerLigne(ligne)))
	{
		stringstream fluxString;
		fluxString << ligne;
		//AdresseIP
		getline(fluxString, requete.adresseIP,' ');
		//UserLogName
		getline(fluxString, requete.userLogName,' ');
		//AuthentificatedUser
		getline(fluxString, requete.authentificateUser,' ');
		fluxString.ignore(16, '[');
		//Date
		//--jour--
		getline(fluxString, lesEntiers, '/');
		requete.date.jour = atoi(lesEntiers.c_str());
		//--mois--
		getline(fluxString, requete.date.mois, '/');
		//--annee--
		getline(fluxString, lesEntiers, ':');
		requete.date.annee = atoi(lesEntiers.c_str());
		//--heure--
		getline(fluxString, lesEntiers, ':');
		requete.date.heure = atoi(lesEntiers.c_str());
		//--heure--
		getline(fluxString, lesEntiers, ':');
		requete.date.minute = atoi(lesEntiers.c_str());
		//--seconde--
		getline(fluxString, lesEntiers, ' ');
		requete.date.seconde = atoi(lesEntiers.c_str());
		//--fuseau--
		getline(fluxString, lesEntiers, ']');
		requete.date.fuseau = atoi(lesEntiers.c_str());
		//Protocole utilise
		fluxString.ignore(16, '\"');
		getline(fluxString, requete.ProtocoleUtilise, ' ');
		//Fichier demande
		getline(fluxString, requete.fichierDemande, ' ');
		//ReturnCode
		fluxString.ignore(32, ' ');
		getline(fluxString, lesEntiers, ' ');
		requete.returnCode = atoi(lesEntiers.c_str());
		//tailleReponseOctet
		getline(fluxString, lesEntiers, ' ');
		requete.tailleReponseOctet = atoi(lesEntiers.c_str());
		//referer
		fluxString.ignore(16, '\"');
		getline(fluxString, requete.referer, '\"');
		const string URLBASE = "http://intranet-if.insa-lyon.fr";
		if (!requete.referer.compare(0, URLBASE.size(), URLBASE))
		{
			(requete.referer).erase(0,URLBASE.size());
			requete.baseUrl = URLBASE;
		}
		//identificationNavigateur
		fluxString.ignore(16, '\"');
		getline(fluxString, requete.identificationNavigateur, '\"');
		getline(fluxString,lesEntiers);
		requete.valide = true;
	}
	else
	{
		cout << ligne << endl;
	}

	return fluxDentre;
}

ostream & operator << (ostream & fluxSortie, const Requete & requete)
{
	fluxSortie << requete.adresseIP << endl;
	fluxSortie << requete.userLogName << endl;
	fluxSortie << requete.authentificateUser << endl;
	fluxSortie << requete.date.jour << "/" << requete.date.mois << "/";
	fluxSortie << requete.date.annee << endl;
	fluxSortie << requete.date.heure << ":" << requete.date.minute << ":" << requete.date.seconde << " ";
	fluxSortie << requete.date.fuseau << endl;
	fluxSortie << requete.ProtocoleUtilise << endl;
	fluxSortie << requete.fichierDemande << endl;
	fluxSortie << requete.returnCode << endl;
	fluxSortie << requete.tailleReponseOctet << endl;
	fluxSortie << requete.referer << endl;
	fluxSortie << requete.baseUrl << endl;
	fluxSortie << requete.identificationNavigateur << endl;
	return fluxSortie;
}

//-------------------------------------------- Constructeurs - destructeur
Requete::Requete() : valide(false)
{
	baseUrl = "";
#ifdef MAP
	cout << "Appel au constructeur de <Requete>" << endl;
#endif
} //----- Fin de Requete

Requete::~Requete()
{
#ifdef MAP
	cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

bool Requete::validerLigne(string ligne) const
// Algorithme : verifie la validite de la ligne
// en utilisant les expressions regulieres
{
	regex const motif { "^[[:digit:]+\\.+]+[:digit:]* .+ .+ \\[\\d+/\\w+/\\d+:\\d+:\\d+:\\d+ [\\+\\-]\\d+\\] \"[A-Z]+ .+ .+\" \\d+ [\\d\\-]+ \".+\" \".+\"" };
	return regex_match(ligne, motif);
}//----- Fin de Methode
