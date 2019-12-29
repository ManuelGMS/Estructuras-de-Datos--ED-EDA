// E24: Manuel Guerrero Moñús

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unordered_map>

std::map<int,std::map<int,std::map<std::string,int>>,std::greater<int>> resolver(std::unordered_map<std::string,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<int>>>>& equipoProblemaVeredictoTiempoVeces) {

	int totalTiempo;
	int problemasCorrectos;
	int problemasIncorrectos;

	std::map<int,std::map<int,std::map<std::string,int>>,std::greater<int>> correctosTiempoEquipoFallidos;

	for(const std::pair<std::string,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<int>>>>& equipo : equipoProblemaVeredictoTiempoVeces) {

		totalTiempo = 0;
		problemasCorrectos = 0;
		problemasIncorrectos = 0;

		for(const std::pair<std::string,std::unordered_map<std::string,std::vector<int>>>& problema : equipo.second)

			if(problema.second.count("AC")) {

				++problemasCorrectos;

				totalTiempo += equipoProblemaVeredictoTiempoVeces[equipo.first][problema.first]["AC"].back();

				for(const std::pair<std::string,std::vector<int>>& veredicto : problema.second)

					for(const int& envio : veredicto.second)

						if(veredicto.first.compare("AC") != 0)

							++problemasIncorrectos;

			}

		totalTiempo += problemasIncorrectos * 20;

		correctosTiempoEquipoFallidos[problemasCorrectos][totalTiempo][equipo.first] = problemasIncorrectos;

	}

	return correctosTiempoEquipoFallidos;

}

bool resuelveCaso() {

	std::string linea;
	std::string equipo;
	std::string problema;
	int minutosTranscurridos;
	std::string veredictoJuez;

	std::unordered_map<std::string,std::unordered_map<std::string,std::unordered_map<std::string,std::vector<int>>>> equipoProblemaVeredictoTiempoVeces;

	do {

		getline(std::cin,linea);

		if(linea.compare("FIN") != 0) {

			std::stringstream ss(linea);

			ss >> equipo >> problema >> minutosTranscurridos >> veredictoJuez;

			if(!equipoProblemaVeredictoTiempoVeces[equipo][problema].count("AC"))

				equipoProblemaVeredictoTiempoVeces[equipo][problema][veredictoJuez].push_back(minutosTranscurridos);

		}

	} while(linea.compare("FIN") != 0);

	std::map<int,std::map<int,std::map<std::string,int>>,std::greater<int>> correctosTiempoEquipoFallidos = resolver(equipoProblemaVeredictoTiempoVeces);

	for(const std::pair<int,std::map<int,std::map<std::string,int>>>& correctos : correctosTiempoEquipoFallidos)

		for(const std::pair<int,std::map<std::string,int>>& tiempo : correctos.second)

			for(const std::pair<std::string,int>& equipo : tiempo.second)

				std::cout << equipo.first << " " << correctos.first << " " << tiempo.first << std::endl;

	std::cout << "----" << std::endl;

	return true;

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
