// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	int nodos;
	int hojas;
	int altura;
};

template<class T>
struct datos recorrerArbol(const bintree<T>& bt){

	if(bt.empty()) {

		return { 0 , 0 , 0 };

	} else {

		auto izq = recorrerArbol(bt.left());
		auto der = recorrerArbol(bt.right());

		return { 1 + izq.nodos + der.nodos , (izq.hojas == 0 && der.hojas == 0)? 1 : (izq.hojas+der.hojas) , 1 + std::max(izq.altura,der.altura) };

	}

}

void resuelveCaso() {

	bintree<char> bt = leerArbol('.');

	auto solucion = recorrerArbol(bt);

	std::cout << solucion.nodos << " " << solucion.hojas << " " << solucion.altura << std::endl;

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
