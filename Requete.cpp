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


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques


	bool ValiderLigne(string ligne)
	{
		// Algorithme :

	}//----- Fin de M�thode

     void Requete::AjouterAuGraphe(Graphe * g)
	{
		g->AjouterArc(referer, fichierDemande);

	} //----- Fin de M�thode


	void Requete::AjouterAuTop(Top * t)
	{
		t->AjouterCible(fichierDemande);
	} //----- Fin de M�thode

	bool Requete::filtreDoc()
	// Algorithme : traite le document de facon � ne laisser
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
		
	}//----- Fin de M�thode

	bool Requete::filtreHeure(int heure)
	{
		if (date.heure == heure)
		{
			return true;
		}
		else
		{
			return false;
		}
	}//----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs

istream & operator >> (istream & is,  Requete & requete) //j'ai enlev� le const
{
	string lesEntiers;
	//AdresseIP
	getline(is, requete.adresseIP,' ');
	//UserLogName
	getline(is, requete.userLogName,' ');
	//AuthentificatedUser
	getline(is, requete.authentificateUser,' ');
	is.ignore(16, '[');
	//Date
	//--jour--
	getline(is, lesEntiers, '/');
	requete.date.jour = atoi(lesEntiers.c_str());
	//--mois--
	getline(is, requete.date.mois, '/');
	//--annee--
	getline(is, lesEntiers, ':');
	requete.date.annee = atoi(lesEntiers.c_str());
	//--heure--
	getline(is, lesEntiers, ':');
	requete.date.heure = atoi(lesEntiers.c_str());
	//--heure--
	getline(is, lesEntiers, ':');
	requete.date.minute = atoi(lesEntiers.c_str());
	//--seconde--
	getline(is, lesEntiers, ' ');
	requete.date.seconde = atoi(lesEntiers.c_str());
	//--fuseau--
	getline(is, lesEntiers, ']');
	requete.date.fuseau = atoi(lesEntiers.c_str());
	//Protocole utilis�
	is.ignore(16, '\"');
	getline(is, requete.ProtocoleUtilise, ' ');
	//Fichier demande
	getline(is, requete.fichierDemande, ' ');
	//ReturnCode
	is.ignore(32, ' ');
	getline(is, lesEntiers, ' ');
	requete.returnCode = atoi(lesEntiers.c_str());
	//tailleReponseOctet
	getline(is, lesEntiers, ' ');
	requete.tailleReponseOctet = atoi(lesEntiers.c_str());
	//referer
	is.ignore(16, '\"');
	getline(is, requete.referer, '\"');
	//identificationNavigateur
	is.ignore(16, '\"');
	getline(is, requete.identificationNavigateur, '\"');

	return is;
}

ostream & operator << (ostream & os, const Requete & requete)
{
	os << requete.adresseIP<<endl;
	os << requete.userLogName << endl;
	os << requete.authentificateUser << endl;
	os << requete.date.jour<<"/"<< requete.date.mois<<"/";
	os << requete.date.annee << endl;
	os << requete.date.heure<<":"<< requete.date.minute << ":" << requete.date.seconde << " ";
	os << requete.date.fuseau << endl;
	os << requete.ProtocoleUtilise << endl;
	os << requete.fichierDemande << endl;
	os << requete.returnCode<<endl;
	os << requete.tailleReponseOctet << endl;
	os << requete.referer << endl;
	os << requete.identificationNavigateur << endl;
	return os;
}

//-------------------------------------------- Constructeurs - destructeur
Requete::Requete()
{
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

//----------------------------------------------------- M�thodes prot�g�es