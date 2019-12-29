// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	int equiposDeRescate;
	int rutaConMasExcursionistas;
};

template<class T>
struct datos recorrerArbol(const bintree<T>& bt){

	if(!bt.empty()) {

		datos izq = recorrerArbol(bt.left());
		datos der = recorrerArbol(bt.right());

		return { (bt.root() > 0 && izq.equiposDeRescate == 0 && der.equiposDeRescate == 0)? 1 : (izq.equiposDeRescate + der.equiposDeRescate) ,
				bt.root() + std::max(izq.rutaConMasExcursionistas,der.rutaConMasExcursionistas)
		};

	} else {

		return { 0 , 0 };

	}

}

void resuelveCaso() {

	datos solucion = recorrerArbol(leerArbol(-1));

	std::cout << solucion.equiposDeRescate << " " << solucion.rutaConMasExcursionistas << std::endl;

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
