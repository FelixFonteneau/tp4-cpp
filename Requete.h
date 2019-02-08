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
//d'un fichier log. Elle permet également de faire tout les traitements sur une requête
//pour vérifier si elle est conforme à la syntaxe d'une ligne de log.
//Une fois la requête validée, elle permet de l'ajouter soit au graphe ou au top10
//mais aussi de filtrer les requêtes par rapport aux différentes specifications:
//soit en ne prenant pas compte les images, les fichiers javascrip, ou en considérant que
//les requêtes qui ont été opérés dans un intervalle de temps.
//------------------------------------------------------------------------

class Requete 
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- Méthodes publiques
	
	void AjouterAuGraphe(Graphe * g) ;
		// Mode d'emploi :Prend en paramètre un pointeur de Graphe auquel il ajoute les attributs 
		//fichierDemandé et referer de la requête courante.

	void AjouterAuTop(Top * t) ;
		// Mode d'emploi : Prend en paramètre un pointeur de Top auquel il ajoute l'attribut
		//fichierDemande de la requete courante

	bool filtreDoc();
		// Mode d'emploi : Renvoie vrai si le document a une extension de type image, css ou javascript
	    //renvoie faux sinon.
		// Contrat : doit être appliqué à une requête "valide"

	bool filtreHeure(int heure);
	// Mode d'emploi : Renvoie vrai si le document a été consulté dans l'intervalle
	//[heure, heure+1] renvoie faux sinon.
	// Contrat : doit être appliqué à une requête "valide"



	//------------------------------------------------- Surcharge d'opérateurs


	friend istream & operator >> (istream &,  Requete & requete);
	// Mode d'emploi : Extrait les informations du fichier istream à la volée 
	//pour remplir les attributs d'une requête à partir 
	//d'une ligne de log


	friend ostream & operator << (ostream &, const Requete & requete);
	// Mode d'emploi : Afficher sur la sortie standard les attributs 
	//de la requête un par ligne.


//-------------------------------------------- Constructeurs - destructeur

	Requete();
	// Mode d'emploi : Construit une requête avec des valeurs
	// par défaut pour les attributs
	
	virtual ~Requete();
	// Mode d'emploi : Détruit la requête courante
	

//------------------------------------------------------------------ PRIVE

private:

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
