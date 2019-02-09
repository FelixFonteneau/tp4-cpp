
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
	ifstream fichier("Mini.log");
	if (!fichier.fail())
	{
		while (fichier)
		{
			fichier >> requete;
			requete.AjouterAuGraphe(&g);
			requete.AjouterAuTop(&top);
		}
	}
	cout << g << endl;
	cout << top << endl;
	
	fichier.close();
}



