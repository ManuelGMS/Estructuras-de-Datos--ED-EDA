// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	int maximo;
	int minimo;
};

datos recorrerArbol(const bintree<int>& bt){

		if(bt.left().empty() && bt.right().empty())

			return { bt.root() , bt.root() };

		else if(bt.left().empty()) {

			datos der = recorrerArbol(bt.right());

			if((der.maximo == -1 && der.minimo == -1) || der.minimo <= bt.root())

				return { -1 , -1 };

			return { std::max(der.maximo,bt.root()) , std::min(der.minimo,bt.root()) };

		} else if(bt.right().empty()) {

			datos izq = recorrerArbol(bt.left());

			if((izq.maximo == -1 && izq.minimo == -1) || izq.maximo >= bt.root())

				return { -1 , -1 };

			return { std::max(izq.maximo,bt.root()) , std::min(izq.minimo,bt.root()) };

		} else {

			datos izq = recorrerArbol(bt.left());

			if(izq.maximo == -1 && izq.minimo == -1)

				return { -1 , -1 };

			datos der = recorrerArbol(bt.right());

			if(der.maximo == -1 && der.minimo == -1)

				return { -1 , -1 };

			if(izq.maximo >= bt.root() || der.minimo <= bt.root())

				return { -1 , -1 };

			return { std::max(der.maximo,bt.root()) , std::min(izq.minimo,bt.root()) };

		}

}

void resuelveCaso() {

	bintree<int> bt = leerArbol(-1);

	if(bt.empty())

		std::cout << "SI" << std::endl;

	else {

		datos solucion = recorrerArbol(bt);

		std::cout << ((solucion.maximo == -1 && solucion.minimo == -1)? "NO" : "SI") << std::endl;

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
