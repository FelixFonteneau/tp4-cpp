/************************************************************************
								Requete - description
								------------------ -
	début                : 25/01/2019
	copyright : (C)2019 par Félix Fonteneau et Houda Ouhssain
	e - mail : Felix.Fonteneau@insa-lyon.fr / houda.ouhssain@insa-lyon.fr
	/* ************************************************************************ */
	
	//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( Requete_H )
#define Requete_H
using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <regex>

#include "Top.h"
#include "Graphe.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Date
{
int jour;
int mois;
int annee;
int heure;
int minute;
int seconde;
int fuseau;
}Date;


//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//Cette classe permet de constituer une requête à partir du contenu d'une ligne 
//d'un fichier log
//
//------------------------------------------------------------------------

class Requete 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques

	

	
	void AjouterAuGraphe(Graphe * g) ;
		// Mode d'emploi :
		//Prend en paramètre un pointeur de Graphe auquel il ajoute les attributs fichierDemande 
		//et referer de la requête courante
		// Contrat :
		//

	void AjouterAuTop(Top * t) ;
		// Mode d'emploi :
		//Prend en paramètre un pointeur de Top auquel il ajoute l'attribut fichierDemande de la requete
	    //courante
		// Contrat :
		//

	


	//------------------------------------------------- Surcharge d'opérateurs
	Requete & operator = (const Requete & unRequete);
	// Mode d'emploi :
	//
	// Contrat :
	//

	friend istream & operator >> (istream &, const Requete & requete);
	// Mode d'emploi :
	//
	// Contrat :
	//

	friend ostream & operator << (ostream &, const Requete & requete);
	// Mode d'emploi :
	//
	// Contrat :
	//


//-------------------------------------------- Constructeurs - destructeur
	Requete(const Requete & unRequete);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Requete(string a = " ", string user = " ", string a_user = " ", Date d = {0,0,0,0,0,0,0}, string p = " ", string fd = " ",
		int rc = 0, int t = 0, string r = " ", string i = " ") : adresseIP(a), userLogName(user), date(d), fichierDemande(fd),
		ProtocoleUtilise(p),returnCode(rc), tailleReponseOctet(t), referer(r), identificationNavigateur(i) {}
	// Mode d'emploi :initiliase tous les attributs d'une requete par une valeur par defaut
	//
	// Contrat :
	//

	virtual ~Requete();
	

//------------------------------------------------------------------ PRIVE

private:

	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string adresseIP;
	string userLogName;
	string authentificateUser;
	Date date;
	string ProtocoleUtilise; //Voir si je peux mettre un enum
	string fichierDemande;
	unsigned int returnCode;
	unsigned long int tailleReponseOctet; 
	string referer;
	string identificationNavigateur;


};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // Requete_H
