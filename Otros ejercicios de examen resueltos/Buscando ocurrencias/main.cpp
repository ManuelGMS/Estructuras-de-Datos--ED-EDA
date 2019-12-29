// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>
#include<unordered_map>

void resolver(std::unordered_map<int, std::vector<int>>& numeroApariciones, const int& aparicion, const int& numero) {

	if (numeroApariciones.count(numero)) {

		if (aparicion + 1 > numeroApariciones.at(numero).size())

			std::cout << "NO HAY" << std::endl;
		
		else

			std::cout << numeroApariciones.at(numero)[aparicion] << std::endl;

	} else {

		std::cout << "NO HAY" << std::endl;

	}

}


bool resuelveCaso() {

	int elementos;
	int preguntas;

	std::cin >> elementos >> preguntas;

	if (!std::cin)

		return false;

	int dato;

	std::unordered_map<int, std::vector<int>> numeroApariciones;

	for (int i = 0 ; i < elementos ; ++i) {

		std::cin >> dato;

		numeroApariciones[dato].push_back(i + 1);

	}

	int numero;
	int aparicion;

	for (; preguntas > 0; --preguntas) {

		std::cin >> aparicion >> numero;
		resolver(numeroApariciones,aparicion-1,numero);

	}

	std::cout << "---" << std::endl;

	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	getchar();
#endif

	return 0;

}
