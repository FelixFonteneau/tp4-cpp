/************************************************************************
								Requete - description
								------------------ -
	d�but                : 25/01/2019
	copyright : (C)2019 par F�lix Fonteneau et Houda Ouhssain
	e - mail : Felix.Fonteneau@insa-lyon.fr / houda.ouhssain@insa-lyon.fr
	/* ************************************************************************ */
	
	//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( Requete_H )
#define Requete_H
using namespace std;

//--------------------------------------------------- Interfaces utilis�es
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
// R�le de la classe <Requete>
//Cette classe permet de constituer une requ�te � partir du contenu d'une ligne 
//d'un fichier log(A developper)
//
//------------------------------------------------------------------------

class Requete 
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	

	
	void AjouterAuGraphe(Graphe * g) ;
		// Mode d'emploi :
		//Prend en param�tre un pointeur de Graphe auquel il ajoute les attributs fichierDemande 
		//et referer de la requ�te courante.
		// Contrat :
		//

	void AjouterAuTop(Top * t) ;
		// Mode d'emploi :
		//Prend en param�tre un pointeur de Top auquel il ajoute l'attribut fichierDemande de la requete
	    //courante
		// Contrat :
		//

	bool filtreDoc();
		// Mode d'emploi :
		//Renvoie vrai si le document a une extension de type image, css ou javascript
	    //renvoie faux sinon.
		// Contrat : doit �tre applique sur une requ�te "valide"

	bool filtreHeure(int heure);
	// Mode d'emploi :
	//Renvoie vrai si le document a �t� consult� dans l'intervalle
	//[heure, heure+1] renvoie faux sinon.
	// Contrat : doit �tre applique sur une requ�te "valide"



	//------------------------------------------------- Surcharge d'op�rateurs


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
	// Mode d'emploi (constructeur par d�faut) :
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

	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
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
