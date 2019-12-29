// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int resolver(const std::vector<int>& capitulos) {

	int maximo = 0;

	int posicion = 0;

	std::unordered_map<int,int> capituloPosicion;

	for(int c = 0 ; c < capitulos.size() ; ++c) {

		if(capituloPosicion.count(capitulos[c]) && capituloPosicion[capitulos[c]] >= posicion) {

			maximo = std::max(maximo,c-posicion);

			posicion = capituloPosicion[capitulos[c]] + 1;

		}

		capituloPosicion[capitulos[c]] = c;

	}

	maximo = std::max(maximo, ((int)capitulos.size()) - posicion );

	return maximo;

}


void resuelveCaso() {

	int numCapitulos;
	std::cin >> numCapitulos;

	std::vector<int> capitulos(numCapitulos);

	for(int& i : capitulos)

		std::cin >> i;

	std::cout << resolver(capitulos) << std::endl;

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
