// E24: Manuel Guerrero Moñús

#include <map>
#include <fstream>
#include <iostream>
#include <unordered_map>

class cmp {

public:

	bool operator () (const int& a, const int& b) {

		return a > b;

	}

};

std::map<int,std::map<std::string,int>,cmp> resolver(std::unordered_map<std::string,int>& deporteEstudiantes, const std::unordered_map<std::string,std::unordered_map<std::string,int>>& alumnoDeporteVeces) {

	for(const auto& alumno : alumnoDeporteVeces)

		if(alumno.second.size() > 1)

			for(auto& deporte : alumno.second)

				--deporteEstudiantes[deporte.first];

	std::map<int,std::map<std::string,int>,cmp> estudiantesDeporteEstudiantes;

	for(const auto& deporte : deporteEstudiantes)

		estudiantesDeporteEstudiantes[deporte.second][deporte.first] = deporte.second;

	return estudiantesDeporteEstudiantes;

}

bool resuelveCaso() {

	std::string dato;
	std::string deporte;
	std::unordered_map<std::string,int> deporteEstudiantes;
	std::unordered_map<std::string,std::unordered_map<std::string,int>> alumnoDeporteVeces;

	std::cin >> dato;

	if(!std::cin)

		return false;

	do {

		deporte = dato;

		deporteEstudiantes[deporte];

		std::cin >> dato;

		while(dato[0] >= 'a' && dato[0] <= 'z') {

			int& adv = alumnoDeporteVeces[dato][deporte];

			++adv;

			if(adv > 1)

				adv = 1;

			else

				++deporteEstudiantes[deporte];

			std::cin >> dato;

		}

	} while(dato.compare("_FIN_") != 0);

	auto solucion = resolver(deporteEstudiantes,alumnoDeporteVeces);

	for(const auto& s : solucion)

		for(const auto& l : s.second)

			std::cout << l.first << " " << l.second << std::endl;

	std::cout << "***" << std::endl;

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
