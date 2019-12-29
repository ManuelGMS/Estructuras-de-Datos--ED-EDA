// E24: Manuel Guerrero Moñús

/*

Complejidad: O(n) ya que hay que recorrer los n nodos del arbol binario.

*/

#include<algorithm>
#include <fstream>
#include <iostream>

#include "bintree.h"

using solucion = struct {
	
	int actual;
	int maximo;
	
};

solucion resolver(const bintree<int>& bt) {

	if (bt.empty()) {

		return {0,0};

	} else {

		if (bt.root() % 2 == 0) {

			auto izq = resolver(bt.left());
			auto der = resolver(bt.right());

			return { std::max(izq.actual,der.actual) + 1 , std::max(izq.actual+der.actual+1,std::max(izq.maximo,der.maximo)) };

		} else {

			auto izq = resolver(bt.left());
			auto der = resolver(bt.right());

			return { 0 , std::max(izq.maximo,der.maximo) };

		}

	}

}


void resuelveCaso() {

	bintree<int> bt = leerArbol(-1);

	solucion s = resolver(bt);

	std::cout << s.maximo << std::endl;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int casos;
	std::cin >> casos;

	for (; casos > 0; --casos)

		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	getchar();
#endif

	return 0;

}
