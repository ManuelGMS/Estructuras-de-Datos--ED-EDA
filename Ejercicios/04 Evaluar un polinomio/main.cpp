/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>

#include "polinomio.h"

void resolver(const Polinomio& p) {

	int valor;
	int pruebas;
	std::cin >> pruebas;

	for( ; pruebas > 0 ; --pruebas) {

		std::cin >> valor;

		std::cout << p.evaluar(valor) << " ";

	}

	std::cout << std::endl;

}

bool resuelveCaso() {

	Polinomio p;
	int exponente;
	int coeficiente;

	std::cin >> coeficiente >> exponente;

	if(!std::cin)

		return false;

	while(!(coeficiente == 0 && exponente == 0)) {

		p.nuevoMonomio({coeficiente,exponente});

		std::cin >> coeficiente >> exponente;

	}

	resolver(p);

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
