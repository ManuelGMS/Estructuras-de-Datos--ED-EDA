// E24: Manuel Guerrero Moñús

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unordered_map>

std::pair<bool,std::unordered_map<char,std::map<std::string,std::string>>> resolver(const std::string& linea1, const std::string& linea2) {

	std::string clave;

	std::string valor;

	std::unordered_map<std::string,std::pair<char,std::string>> original;

	std::unordered_map<char,std::map<std::string,std::string>> clasificacion;

	std::stringstream ss1(linea1);

	while(ss1 >> clave) {

		ss1 >> valor;

		original[clave] = { '-' , valor };

	}

	std::stringstream ss2(linea2);

	while(ss2 >> clave) {

		ss2 >> valor;

		auto it = original.find(clave);

		if(it == original.end()) {

			original[clave] = { '+' , valor };

		} else if((*it).second.second.compare(valor) == 0) {

			original[clave] = { '=' , valor };

		} else {

			original[clave] = { '*' , valor };

		}

	}

	for(const auto v : original)

		clasificacion[v.second.first][v.first] = v.second.second;

	auto it = clasificacion.find('=');

	return { it != clasificacion.end() && (*it).second.size() == original.size() , clasificacion };

}

void resuelveCaso() {

	std::string linea1;
	std::string linea2;

	getline(std::cin,linea1);
	getline(std::cin,linea2);

	if(linea1.compare("") == 0 && linea2.compare("") == 0)

		std::cout << "Sin cambios" << std::endl;

	else {

		auto solucion = resolver(linea1,linea2);

		if(solucion.first)

			std::cout << "Sin cambios" << std::endl;

		else

			for(const auto clasificador : {'+','-','*'})

				if(solucion.second.count(clasificador)) {

					std::cout << clasificador << " ";

					for(const auto definicion : solucion.second[clasificador])

						std::cout << definicion.first << " ";

					std::cout << std::endl;

				}

	}

	std::cout << "----" << std::endl;

}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int casos;
	std::cin >> casos;

	std::string saltoDeLinea;
	getline(std::cin,saltoDeLinea);

	for( ; casos > 0 ; --casos)

		resuelveCaso();

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}
