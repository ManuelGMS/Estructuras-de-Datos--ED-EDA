// E24: Manuel Guerrero Moñús

#include<fstream>
#include<iostream>

#include "bintree.h"

using solucion = struct {

	bool completo;
	int niveLesInferiores;

};

solucion resolver(const bintree<char>& bt) {

	if (bt.left().empty() && bt.right().empty()) {

		return { true , 1 };

	} else {

		if (!bt.left().empty() && !bt.right().empty()) {

			auto izq = resolver(bt.left());

			if (!izq.completo)

				return { false , -1 };

			auto der = resolver(bt.right());

			if (!der.completo)

				return { false , -1 };

			if (izq.niveLesInferiores != der.niveLesInferiores)

				return { false , -1 };

			return { true , izq.niveLesInferiores + 1 };

		}

		return { false , -1 };

	}

}


void resuelveCaso() {

	bintree<char> bt = leerArbol('.');

	std::cout << ((bt.empty() || resolver(bt).completo) ? "SI" : "NO") << std::endl;
	
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	std::cin >> casos;

	for ( ; casos > 0 ; casos--)

		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	getchar();
#endif

	return 0;

}
