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

bool resuelveCaso() {

	int horas;
	int trenes;

	std::cin >> trenes >> horas;

	if(trenes == 0 && horas == 0)

		return false;

	int hora;
	int minuto;
	int segundo;
	char separator;

	std::vector<Hora> trenesSalenEstacion(trenes);

	for(Hora& h : trenesSalenEstacion)

		std::cin >> h;

	for ( ; horas > 0 ; --horas) {

		try {

			std::cin >> hora >> separator >> minuto >> separator >> segundo;

			Hora h(hora,minuto,segundo,separator);

			auto i = std::lower_bound(trenesSalenEstacion.begin(),trenesSalenEstacion.end(),h);

			if(i == trenesSalenEstacion.end())

				std::cout << "NO" << std::endl;

			else

				std::cout << *i << std::endl;

		} catch(const std::domain_error& de) {

			std::cout << de.what() << std::endl;

		}

	}

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
