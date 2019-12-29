// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

template<class T>
void recorrerArbol(const bintree<T>& bt, std::vector<int>& frontera){

	if(!bt.empty()) {

		if(bt.left().empty() && bt.right().empty()) {

			frontera.push_back(bt.root());

		} else {

			recorrerArbol(bt.left(),frontera);
			recorrerArbol(bt.right(),frontera);

		}

	}

}

void resuelveCaso() {

	bintree<int> bt = leerArbol(-1);

	std::vector<int> frontera;

	recorrerArbol(bt,frontera);

	for(int& i : frontera)

		std::cout << i << " ";

	std::cout << std::endl;

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
