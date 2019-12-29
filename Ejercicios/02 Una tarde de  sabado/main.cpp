/*
E24: Manuel Guerrero Moñús
Coste: O(n *log(n))
*/

#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "hora.h"
#include "pelicula.h"

bool resuelveCaso() {

	int peliculas;

	std::cin >> peliculas;

	if(peliculas == 0)

		return false;

	std::vector<Pelicula> cartelera(peliculas);

	for(Pelicula& p : cartelera)

		std::cin >> p;

	std::sort(cartelera.begin(),cartelera.end());

	for(Pelicula& p : cartelera)

		std::cout << p << std::endl;

	std::cout << "---" << std::endl;

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
