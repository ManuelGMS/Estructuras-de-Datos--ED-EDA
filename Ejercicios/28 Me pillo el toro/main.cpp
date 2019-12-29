// E24: Manuel Guerrero Moñús

#include <map>
#include <fstream>
#include <iostream>

using calificacion = int;
using alumno = std::string;

std::map<alumno,calificacion> resolver(const int& ejercicios) {

	std::string nota;
	std::string nombre;

	std::map<alumno,calificacion> resultados;

	for (int i = 0; i < ejercicios; ++i) {

		std::getline(std::cin,nombre);
		std::getline(std::cin,nota);

		resultados[nombre] += ((nota.compare("CORRECTO") == 0)? 1 : -1);

	}

	return resultados;

}


bool resuelveCaso() {

	int ejercicios;
	std::cin >> ejercicios;

	if(ejercicios == 0)

		return false;

	std::string saltoDeLinea;
	std::getline(std::cin,saltoDeLinea);

	for(const auto& solucion : resolver(ejercicios))

		if(solucion.second != 0)

			std::cout << solucion.first << ", " << solucion.second << std::endl;

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
