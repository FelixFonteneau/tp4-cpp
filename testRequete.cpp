
#include <string>
#include<iostream>
#include<fstream>
#include "Requete.h"
#include "Graphe.h"

using namespace std;
int main()
{
	Graphe g;
	Top top(10);
	Requete requete;
	ifstream fichier("mini.log");
	for (int i = 0; i < 17; i++)
	{
		fichier >> requete;
		if (!requete.filtreDoc())
		{
			requete.AjouterAuGraphe(&g);
			requete.AjouterAuTop(&top);
		}
	}
	cout << g << endl;
	cout << top << endl;

	fichier.close();
	
	

	
// FAIT DES ERREURS VALGRIND QUAND JE METS LE WHILE
//PROBLEME DANS DATE.MOIS JE NE COMPREND PAS POURQUOI!!!!!!
	/*
	if (!(fichier.fail())
	{
		while (fichier)
		{
			fichier >> requete;
			requete.AjouterAuGraphe(&g);
		}
	}
	
	cout << g << endl;
	fichier.close();
	*/
}



