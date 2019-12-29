// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

bool recorrerSubArbol(const bintree<char>& izq, const bintree<char>& der) {

	if(izq.empty() && !der.empty())

		return false;

	else if(!izq.empty() && der.empty())

		return false;

	else if(izq.empty() && der.empty())

		return true;

	else {

		return recorrerSubArbol(izq.left(),der.right()) && recorrerSubArbol(izq.right(),der.left());

	}

}

void resuelveCaso() {

	bintree<char> bt = leerArbol('.');

	std::cout << ((bt.empty() || recorrerSubArbol(bt.left(),bt.right()))? "SI" : "NO") << std::endl;

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
