// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

template<class T>
T recorrerArbol(const bintree<T>& bt){

	auto it = bt.begin();

	T elementoMenor = *it;

	while(it != bt.end()) {

		elementoMenor = std::min(elementoMenor,*it);

		++it;

	}

	return elementoMenor;

}

bool resuelveCaso() {

	char tipo;
	std::cin >> tipo;

	if(!std::cin)

		return false;

	if(tipo == 'N')

		std::cout << recorrerArbol(leerArbol(-1)) << std::endl;

	else

		std::cout << recorrerArbol(leerArbol(std::string("#"))) << std::endl;

	return true;

}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while(resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}
