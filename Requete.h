/************************************************************************
								Requete - description
								-------------------
	d�but                : 25/01/2019
	copyright : (C)2019 par F�lix Fonteneau et Houda Ouhssain
	e - mail : Felix.Fonteneau@insa-lyon.fr / houda.ouhssain@insa-lyon.fr
**************************************************************************/

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
//d'un fichier log. Elle permet �galement de faire tout les traitements sur une requ�te
//pour v�rifier si elle est conforme � la syntaxe d'une ligne de log.
//Une fois la requ�te valid�e, elle permet de l'ajouter soit au graphe ou au top10
//mais aussi de filtrer les requ�tes par rapport aux diff�rentes specifications:
//soit en ne prenant pas compte les images, les fichiers javascrip, ou en consid�rant que
//les requ�tes qui ont �t� op�r�s dans un intervalle de temps.
//------------------------------------------------------------------------

class Requete
{
	//----------------------------------------------------------------- PUBLIC

public:

	//----------------------------------------------------- M�thodes publiques

	bool AjouterAuGraphe(Graphe &g) const;
		// Mode d'emploi :Prend en param�tre un pointeur de Graphe auquel il ajoute les attributs
		//fichierDemand� et referer de la requ�te courante.

	bool AjouterAuTop(Top &t) const ;
		// Mode d'emploi : Prend en param�tre un pointeur de Top auquel il ajoute l'attribut
		//fichierDemande de la requete courante

	bool FiltreDoc() const;
		// Mode d'emploi : Renvoie vrai si le document a une extension de type image, css ou javascript
	    //renvoie faux sinon.
		// Contrat : doit �tre appliqu� � une requ�te "valide"

	bool FiltreHeure(const int &heure) const;
	// Mode d'emploi : Renvoie vrai si le document a �t� consult� dans l'intervalle
	//[heure, heure+1] renvoie faux sinon.
	// Contrat : doit �tre appliqu� � une requ�te "valide"



	//------------------------------------------------- Surcharge d'op�rateurs


	friend istream & operator >> (istream & fluxDentre,  Requete & requete);
	// Mode d'emploi : Extrait les informations du fichier istream � la vol�e
	//pour remplir les attributs d'une requ�te � partir
	//d'une ligne de log


	friend ostream & operator << (ostream & fluxSortie, const Requete & requete);
	// Mode d'emploi : Afficher sur la sortie standard les attributs
	//de la requ�te un par ligne.


//-------------------------------------------- Constructeurs - destructeur

	Requete();
	// Mode d'emploi : Construit une requ�te avec des valeurs
	// par d�faut pour les attributs

	virtual ~Requete();
	// Mode d'emploi : D�truit la requ�te courante


//------------------------------------------------------------------ PRIVE

private:
	//----------------------------------------------------- Méthodes protégées
	bool validerLigne(string ligne) const;
	// Mode d'emploi : renvoie true si la ligne est valide false sinon

	//----------------------------------------------------- Attributs prot�g�s
	string adresseIP;
	string userLogName;
	string authentificateUser;
	Date date;
	string ProtocoleUtilise;
	string fichierDemande;
	unsigned int returnCode;
	unsigned long int tailleReponseOctet;
	string baseUrl;
	string referer;
	string identificationNavigateur;
	bool valide;
};

#endif // Requete_H
