// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	int profundidad;
	bool esGenealogico;
};

datos recorrerArbol(const bintree<int>& bt, const int& profundidad){

	if(bt.left().empty() && bt.right().empty())

		return { profundidad , true };

	else if(bt.left().empty())

		return { profundidad , false };

	else if(bt.right().empty()) {

		if(bt.root() - bt.left().root() < 18)

			return { profundidad , false };

		datos izq = recorrerArbol(bt.left(),profundidad+1);

		return { izq.profundidad , izq.esGenealogico };

	} else {

		if(bt.root() - bt.left().root() < 18)

			return { profundidad , false };

		if(bt.left().root() - bt.right().root() < 2)

			return { profundidad , false };

		datos izq = recorrerArbol(bt.left(),profundidad+1);
		datos der = recorrerArbol(bt.right(),profundidad+1);

		return { std::max(izq.profundidad,der.profundidad) , izq.esGenealogico && der.esGenealogico };

	}

}

void resuelveCaso() {

	bintree<int> bt = leerArbol(-1);

	if(!bt.empty()) {

		datos solucion = recorrerArbol(bt,1);

		if(solucion.esGenealogico)

			std::cout << "SI " << solucion.profundidad << std::endl;

		else

			std::cout << "NO" << std::endl;

	} else {

		std::cout << "SI 0" << std::endl;

	}

}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int casos;
	std::cin >> casos;

	for ( ; casos > 0 ; --casos)

		resuelveCaso();

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}
