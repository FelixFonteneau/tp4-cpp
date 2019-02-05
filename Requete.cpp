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


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques




	bool ValiderLigne(string ligne)
	{
		// Algorithme :

	}//----- Fin de Méthode

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

	bool Requete::filtreDoc()
	// Algorithme : traite le document de facon à ne laisser
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
		
	}//----- Fin de Méthode

	bool Requete::filtreHeure(int heure)
	// Algorithme :
	//
	{
		if (date.heure == heure)
		{
			return true;
		}
		else
		{
			return false;
		}
	}//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

istream & operator >> (istream & is,  Requete & requete) //j'ai enlevé le const
{
	//i représente l'indice de la position dans une ligne de log
	int i = 0;
	string ligne;
	getline(is, ligne);//voir si je dois mettre if (getligne)

	//if (ValiderLigne(ligne))
	//{

		//AdresseIP
		i = ligne.find(" ");
		requete.adresseIP = ligne.substr(0, i); 
		//on supprime au fur et à mesure les données qui ont été stockés dans un attribut
		ligne.erase(0, i + 1); 

		//UserLogName
		i = ligne.find(" ");
		requete.userLogName = ligne.substr(0, i);
		ligne.erase(0, i + 1);

		//authentificateUser
		i = ligne.find(" ");
		requete.authentificateUser = ligne.substr(0, i);
		ligne.erase(0, i + 2);

		//Date
		requete.date.jour= atoi((ligne.substr(0, 2)).c_str());
		requete.date.mois= ligne.substr(3, 6);
		requete.date.annee = atoi((ligne.substr(7, 11)).c_str());
		requete.date.heure = atoi((ligne.substr(12, 14)).c_str());
		requete.date.minute = atoi((ligne.substr(15, 17)).c_str());
		requete.date.seconde = atoi((ligne.substr(18, 20)).c_str());
		requete.date.fuseau = atoi((ligne.substr(21, 25)).c_str());
		ligne.erase(0, 29);

		//ProtocoleUtilise
		i = ligne.find(" ");
		requete.ProtocoleUtilise = ligne.substr(0, i);
		ligne.erase(0, i + 1);

		//FichierDemande
		i = ligne.find(" ");
		requete.fichierDemande = ligne.substr(0, i);
		ligne.erase(0, i + 1);
		i = ligne.find("\""); //on ignore le HTTP/1.1 on ne le stocke nulle part
		ligne.erase(0, i + 2);

		//returnCode
		i = ligne.find(" ");
		requete.returnCode=atoi((ligne.substr(0, i)).c_str());
		ligne.erase(0, i + 1);

		//tailleReponseOctet
		i = ligne.find(" ");
		requete.tailleReponseOctet= atol((ligne.substr(0, i)).c_str());
		ligne.erase(0, i + 2);

		//Referer
		i = ligne.find("\"");
		requete.referer= ligne.substr(0, i);
		ligne.erase(0, i + 3);

		//identificationNavigateur
		i = ligne.find("\"");
		requete.identificationNavigateur= ligne.substr(0, i);
	//}
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
Requete::Requete(const Requete & unRequete)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur de copie)

Requete::Requete()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Requete>" << endl;
#endif
} //----- Fin de Requete

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