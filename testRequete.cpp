
#include <string>
#include<iostream>
#include<fstream>
#include "Requete.h"
#include "Graphe.h"

using namespace std;
int main()
{
	Graphe g;
	Requete requete;
	ifstream fichier;
	fichier.open("mini.log");
	fichier >> requete;
	requete.AjouterAuGraphe(&g);
	cout << g << endl;
	fichier.close();
	


	
// FAIT DES ERREURS VALGRIND QUAND JE METS LE WHILE
//PROBLEME DANS DATE.MOIS JE NE COMPREND PAS POURQUOI!!!!!!
	/*
	while (!fichier.eof())
	{
		fichier >> requete;
		requete.AjouterAuGraphe(&g);
	}
	cout << g << endl;
	
	fichier.close();
	*/
	
}



