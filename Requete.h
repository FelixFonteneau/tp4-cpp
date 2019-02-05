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
#include"Graphe.h"
#include"Top.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Date
{
int jour;
string mois;
int annee;
int heure;
int minute;
int seconde;
int fuseau;
}Date;


//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//Cette classe permet de constituer une requête à partir du contenu d'une ligne 
//d'un fichier log(A developper)
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
		//et referer de la requête courante.
		// Contrat :
		//

	void AjouterAuTop(Top * t) ;
		// Mode d'emploi :
		//Prend en paramètre un pointeur de Top auquel il ajoute l'attribut fichierDemande de la requete
	    //courante
		// Contrat :
		//

	bool filtreDoc();
		// Mode d'emploi :
		//Renvoie vrai si le document a une extension de type image, css ou javascript
	    //renvoie faux sinon.
		// Contrat : doit être applique sur une requête "valide"

	bool filtreHeure(int heure);
	// Mode d'emploi :
	//Renvoie vrai si le document a été consulté dans l'intervalle
	//[heure, heure+1] renvoie faux sinon.
	// Contrat : doit être applique sur une requête "valide"



	//------------------------------------------------- Surcharge d'opérateurs


	friend istream & operator >> (istream &,  Requete & requete);
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

	Requete();
	// Mode d'emploi (constructeur par défaut) :
	//
	// Contrat :
	//

	virtual ~Requete();
	// Mode d'emploi (destructeur) :
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
	string ProtocoleUtilise; 
	string fichierDemande;
	unsigned int returnCode;
	unsigned long int tailleReponseOctet; 
	string referer;
	string identificationNavigateur;


};


#endif // Requete_H
