// E24: Manuel Guerrero Moñús

#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

using emitida = int;
using pelicula = std::string;
using fechas = std::vector<std::string>;

void resolver(int& dias) {

	std::string linea;
	std::string titulo;
	std::string instante;
	int peliculasEmitidas;

	std::map<pelicula,std::pair<emitida,fechas>> peliculaEmisiones;

	std::map<emitida,std::map<pelicula,std::pair<fechas::iterator,fechas::iterator>>,std::greater<emitida>> top;

	for( ; dias > 0 ; --dias) {

		std::getline(std::cin,linea);

		std::stringstream ss(linea);

		ss >> instante;

		ss >> peliculasEmitidas;

		for( ; peliculasEmitidas > 0 ; --peliculasEmitidas ) {

			std::getline(std::cin,titulo);

			if(peliculaEmisiones.count(titulo))

				top[peliculaEmisiones[titulo].first].erase(titulo);

			++peliculaEmisiones[titulo].first;

			if(peliculaEmisiones[titulo].second.empty() || peliculaEmisiones[titulo].second.back() != instante)

				peliculaEmisiones[titulo].second.push_back(instante);

			top[peliculaEmisiones[titulo].first][titulo] = { peliculaEmisiones[titulo].second.begin() , peliculaEmisiones[titulo].second.end() };

		}

	}

	std::cout << (*top.begin()).first << std::endl;

	for(const auto& it : (*top.begin()).second) {

		std::cout << it.first;

		for(auto itInstante = it.second.first ; itInstante != it.second.second ; ++itInstante)

			std::cout << " " << (*itInstante);

		std::cout << std::endl;

	}

}

bool resuelveCaso() {

	int dias;
	std::cin >> dias;

	if(!std::cin)

		return false;

	std::cin.ignore();

	resolver(dias);

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
