/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>

#include "complejo.h"

template<typename T>
bool resolver(const Complejo<T>& c, const int& iteraciones) {

	Complejo<T> base(0,0);

	for(int i = 0 ; base.iMod() <= 2 && i < iteraciones ; ++i)

		base = ((base * base) + c);

	return base.iMod() <= 2;

}

void resuelveCaso() {

	float real;
	int iteraciones;
	float imaginaria;

	std::cin >> real >> imaginaria >> iteraciones;

	Complejo<float> c(real,imaginaria);

	std::cout << ((resolver(c,iteraciones))? "SI" : "NO") << std::endl;

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
