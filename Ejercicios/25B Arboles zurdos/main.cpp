// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	bool zurdo;
	int descendientes;
};

datos recorrerArbol(const bintree<char>& bt) {

	if(bt.empty()) {

		return { true , 0 };

	} else if(bt.left().empty() && bt.right().empty()) {

		return { true , 1 };

	} else {

		datos izq = recorrerArbol(bt.left());

		if(!izq.zurdo)

			return { false , -1 };

		datos der = recorrerArbol(bt.right());

		if(!der.zurdo)

			return { false , -1 };

		if(izq.descendientes <= ((izq.descendientes + der.descendientes) / 2))

			return { false , -1 };

		return { true , izq.descendientes + der.descendientes + 1 };

	}

}

void resuelveCaso() {

	bintree<char> bt = leerArbol('.');

	std::cout << ((bt.empty() || recorrerArbol(bt).zurdo)? "SI" : "NO") << std::endl;

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
