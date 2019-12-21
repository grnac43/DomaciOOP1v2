#include "lista.h"
#include <iostream>

int main()
{
	Lista<int> lista;
	lista.dodaj(1).dodaj(2).dodaj(3);

	for (lista.naPrvi();lista.imaTek();lista.naSledeci())
		std::cout << lista.getTek() << ' ';
	system("pause");
	return 0;
}