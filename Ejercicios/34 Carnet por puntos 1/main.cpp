// E24: Manuel Guerrero Moñús

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unordered_map>

const int MAX_PUNTOS = 15;

class carnet_puntos {

private:

	std::vector<int> puntosCantidad;
	std::unordered_map<std::string,int> dniPuntos;

public:

	carnet_puntos() : puntosCantidad(std::vector<int>(MAX_PUNTOS+1)) {}

	void nuevo(const std::string& dni) {

		if(dniPuntos.count(dni))

			throw std::domain_error("Conductor duplicado");

		dniPuntos[dni] = MAX_PUNTOS;

		++puntosCantidad[MAX_PUNTOS];

	}

	void quitar(const std::string& dni, const int& puntos) {

		auto it = dniPuntos.find(dni);

		if(it == dniPuntos.end())

			throw std::domain_error("Conductor inexistente");

		--puntosCantidad[(*it).second];

		(*it).second = (puntos > (*it).second)? 0 : (*it).second - puntos;

		++puntosCantidad[(*it).second];

	}

	void consultar(const std::string& dni) const {

		auto it = dniPuntos.find(dni);

		if(it == dniPuntos.end())

			throw std::domain_error("Conductor inexistente");

		std::cout << "Puntos de " << dni << ": " << (*it).second << std::endl;

	}

	void cuantos_con_puntos(const int& puntos) {

		if(puntos < 0 || puntos > MAX_PUNTOS)

			throw std::domain_error("Puntos no validos");

		std::cout << "Con " << puntos << " puntos hay " << puntosCantidad[puntos] << std::endl;

	}

};

void resolver(const std::string& primeraLinea) {

	int puntos;
	std::string dni;
	carnet_puntos cp;
	std::string operacion;
	std::string linea(primeraLinea);

	do {

		std::stringstream ss(linea);

		ss >> operacion;

		try {

			if(operacion.compare("nuevo") == 0) {

				ss >> dni;
				cp.nuevo(dni);

			} else if(operacion.compare("quitar") == 0) {

				ss >> dni;
				ss >> puntos;
				cp.quitar(dni,puntos);

			} else if(operacion.compare("consultar") == 0) {

				ss >> dni;
				cp.consultar(dni);

			} else if(operacion.compare("cuantos_con_puntos") == 0) {

				ss >> puntos;
				cp.cuantos_con_puntos(puntos);

			}

		} catch(const std::domain_error& e) {

			std::cout << "ERROR: " << e.what() << std::endl;

		}

		getline(std::cin,linea);

	} while(linea.compare("FIN") != 0);

}

bool resuelveCaso() {

	std::string linea;

	getline(std::cin,linea);

	if(!std::cin)

		return false;

	if(linea.compare("FIN") != 0)

		resolver(linea);

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
