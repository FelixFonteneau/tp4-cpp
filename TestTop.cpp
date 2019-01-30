#include "Top.h"
#include <iostream>

using namespace std;

int main()
{

	Top top(10);
  top.AjouterCible("Miaou");
  top.AjouterCible("Miaou");
  top.AjouterCible("Chat");
  top.AjouterCible("Miaou");
  top.AjouterCible("Chat");
  top.AjouterCible("Chat");
  top.AjouterCible("Oiseau");
  top.AjouterCible("Oiseau");
  top.AjouterCible("Miaou");
  top.AjouterCible("Miaou");
  top.AjouterCible("Miaou");
  top.AjouterCible("Chat");
  top.AjouterCible("Chat");
  top.AjouterCible("Oiseau");
  top.AjouterCible("Kanji");
  top.AjouterCible("Nohrio");
  top.AjouterCible("Miaou");
  top.AjouterCible("Miaou");

	cout << top;
	return 0;
}
