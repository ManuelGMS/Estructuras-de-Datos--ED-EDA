// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	int maximo;
	int caminoMasLargo;
};

template<class T>
struct datos recorrerArbol(const bintree<T>& bt){

	if(!bt.empty()) {

		datos izq = recorrerArbol(bt.left());
		datos der = recorrerArbol(bt.right());

		return {
			std::max(std::max(izq.maximo,der.maximo),1+izq.caminoMasLargo+der.caminoMasLargo) ,
			1 + std::max(izq.caminoMasLargo,der.caminoMasLargo)
		};

	} else {

		return { 0 , 0 };

	}

}

void resuelveCaso() {

	std::cout << recorrerArbol(leerArbol('.')).maximo << std::endl;

}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int casos;
	std::cin >> casos;

	for( ; casos > 0 ; --casos)

		resuelveCaso();

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}
