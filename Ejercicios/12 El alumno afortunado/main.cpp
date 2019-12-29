/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <vector>
#include <fstream>
#include <iostream>

#include "list_eda.h"

void resolver(list<int>& miLista, const int& saltos) {

	int contador = 0;

	while(miLista.size() != 1) {

		auto it = miLista.begin();

		while(it != miLista.end() && miLista.size() != 1) {

			if(contador == saltos) {

				contador = 0;

				it = miLista.erase(it);

			}

			if(it != miLista.end()) {

				++contador;

				++it;

			}

		}

	}

}

bool resuelveCaso() {

	int saltos;
	int alumnos;

	std::cin >> alumnos >> saltos;

	if(alumnos == 0 && saltos == 0)

		return false;

	list<int> miLista;

	for(int i = 1 ; i <= alumnos ; ++i)

		miLista.insert(miLista.end(),i);

	if(saltos != 0) {

		resolver(miLista,saltos);

		std::cout << *miLista.begin() << std::endl;

	} else

		std::cout << miLista.back() << std::endl;

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
