#include "Graphe.h"
#include <iostream>

using namespace std;

int main()
{

	Graphe g;
	g.AjouterArc("chat","miaou");
	g.AjouterArc("chat","miaou");
	g.AjouterArc("Oiseau","cuicui");
	g.AjouterArc("chat","miaou");
	g.AjouterArc("furet","hmmm");
	g.AjouterArc("chat","bla");
	cout << g;
	return 0;
}
