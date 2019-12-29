// E24: Manuel Guerrero Moñús

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

void resolver(std::map<std::string,std::vector<int>>& palabraLineas, const std::string& linea, const int& l) {

	std::string palabra;

	std::stringstream ss(linea);

	while(ss >> palabra) {

		if(palabra.size() > 2) {

			std::transform(palabra.begin(),palabra.end(),palabra.begin(),tolower);

			if(palabraLineas[palabra].empty() || palabraLineas[palabra].back() != l)

				palabraLineas[palabra].push_back(l);

		}

	}

}

bool resuelveCaso() {

	int lineas;
	std::cin >> lineas;

	if(lineas == 0)

		return false;

	std::string linea;

	std::map<std::string,std::vector<int>> palabraLineas;

	for(int l = 0 ; l <= lineas ; ++l) {

		getline(std::cin,linea);

		resolver(palabraLineas,linea,l);

	}

	for (const auto& a : palabraLineas) {

		std::cout << a.first << " ";

		for(const int& i : a.second)

			std::cout << i << " ";

		std::cout << std::endl;

	}

	std::cout << "----" << std::endl;

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
