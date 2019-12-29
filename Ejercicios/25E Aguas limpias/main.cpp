// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	int tramos;
	int caudal;
};

datos resolver(const bintree<int>& bt) {

	if(bt.left().empty() && bt.right().empty()) {

		return { 0 , 1 };

	} else if(bt.left().empty()) {

		datos tramoAnterior = resolver(bt.right());

		return {
			(tramoAnterior.caudal >= 3)? (tramoAnterior.tramos + 1) : tramoAnterior.tramos
			,
			(tramoAnterior.caudal - bt.root() < 0)? 0 : (tramoAnterior.caudal - bt.root())
		};

	} else if(bt.right().empty()) {

		datos tramoAnterior = resolver(bt.left());

		return {
			(tramoAnterior.caudal >= 3)? (tramoAnterior.tramos + 1) : tramoAnterior.tramos
			,
			(tramoAnterior.caudal - bt.root() < 0)? 0 : (tramoAnterior.caudal - bt.root())
		};

	} else {

		datos tramoAnteriorIzquierdo = resolver(bt.left());

		datos tramoAnteriorDerecho = resolver(bt.right());

		return {
			((tramoAnteriorIzquierdo.caudal >= 3)? (tramoAnteriorIzquierdo.tramos + 1) : tramoAnteriorIzquierdo.tramos)
			+
			((tramoAnteriorDerecho.caudal >= 3)? (tramoAnteriorDerecho.tramos + 1) : tramoAnteriorDerecho.tramos)
			,
			(tramoAnteriorIzquierdo.caudal + tramoAnteriorDerecho.caudal - bt.root() < 0)? 0 : (tramoAnteriorIzquierdo.caudal + tramoAnteriorDerecho.caudal - bt.root())
		};

	}

}

void resuelveCaso() {

	bintree<int> bt = leerArbol(-1);

	std::cout << ((bt.empty())? 0 : resolver(bt).tramos) << std::endl;

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
