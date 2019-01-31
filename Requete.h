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
#include "Top.h"
#include " Graphe.h"
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
//Cette classe permet de constituer un objet requête à partir d'une ligne 
//d'un fichier log
//
//------------------------------------------------------------------------

class Requete 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	
	void AjouterAuGraphe(Graphe * g) const;
		// Mode d'emploi :
		//
		// Contrat :
		//

	void AjouterAuTop(Top * t) const;
		// Mode d'emploi :
		//
		// Contrat :
		//

	string GetFichierDemande()const;
    	// Mode d'emploi :
		//
		// Contrat :
		//

	string GetReferer()const;
	// type Méthode ( liste des paramètres );
		// Mode d'emploi :
		//
		// Contrat :
		//

	Date GetHeure()const;
	// type Méthode ( liste des paramètres );
		// Mode d'emploi :
		//
		// Contrat :
		//



	//------------------------------------------------- Surcharge d'opérateurs
	Requete & operator = (const Requete & unRequete);
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
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Requete();
	// Mode d'emploi :
	//
	// Contrat :
	//

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
