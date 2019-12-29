// E24: Manuel Guerrero Moñús

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unordered_map>

using t_puntos = int;
using t_cantidad = int;
using t_instante = int;
using t_dni = std::string;

const int MAX_PUNTOS = 15;

class carnet_puntos {

private:

	int instante = 0;
	std::unordered_map<t_dni,std::pair<t_puntos,t_instante>> dniPuntosInstante;
	std::vector<std::map<t_instante,t_dni,std::greater<t_puntos>>> puntosInstanteDni;

public:

	carnet_puntos() : puntosInstanteDni(std::vector<std::map<t_puntos,t_dni,std::greater<t_puntos>>>(MAX_PUNTOS+1)) {}

	void nuevo(const std::string& dni) {

		if(dniPuntosInstante.count(dni))

			throw std::domain_error("Conductor duplicado");

		++this->instante;

		puntosInstanteDni[MAX_PUNTOS][this->instante] = dni;

		dniPuntosInstante[dni] = { MAX_PUNTOS , this->instante };

	}

	void quitar(const std::string& dni, const int& puntos) {

		if(puntos > 0) {

			auto it = dniPuntosInstante.find(dni);

			if(it == dniPuntosInstante.end())

				throw std::domain_error("Conductor inexistente");

			if((*it).second.first > 0) {

				puntosInstanteDni[(*it).second.first].erase((*it).second.second);

				(*it).second.first -= puntos;

				if((*it).second.first < 0)

					(*it).second.first = 0;

				++this->instante;
				dniPuntosInstante[dni] = { (*it).second.first , this->instante };
				puntosInstanteDni[(*it).second.first][this->instante] = dni;

			}

		}

	}

	void consultar(const std::string& dni) const {

		auto it = dniPuntosInstante.find(dni);

		if(it == dniPuntosInstante.end())

			throw std::domain_error("Conductor inexistente");

		std::cout << "Puntos de " << dni << ": " << (*it).second.first << std::endl;

	}

	void cuantos_con_puntos(const int& puntos) {

		if(puntos < 0 || puntos > MAX_PUNTOS)

			throw std::domain_error("Puntos no validos");

		std::cout << "Con " << puntos << " puntos hay " << puntosInstanteDni[puntos].size() << std::endl;

	}

	void lista_por_puntos(const int& puntos) {

		if(puntos < 0 || puntos > MAX_PUNTOS)

			throw std::domain_error("Puntos no validos");

		std::cout << "Tienen " << puntos << " puntos:";

		for(auto& it : puntosInstanteDni[puntos])

			std::cout << " " << it.second;

		std::cout << std::endl;

	}

	void recuperar(const std::string& dni, const int& puntos) {

		if(puntos > 0) {

			auto it = dniPuntosInstante.find(dni);

			if(it == dniPuntosInstante.end())

				throw std::domain_error("Conductor inexistente");

			if((*it).second.first < MAX_PUNTOS) {

				puntosInstanteDni[(*it).second.first].erase((*it).second.second);

				(*it).second.first += puntos;

				if((*it).second.first > MAX_PUNTOS)

					(*it).second.first = MAX_PUNTOS;

				++this->instante;
				puntosInstanteDni[(*it).second.first][this->instante] = dni;
				dniPuntosInstante[dni] = { (*it).second.first , this->instante };

			}

		}

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

			} else if(operacion.compare("recuperar") == 0) {

				ss >> dni;
				ss >> puntos;
				cp.recuperar(dni,puntos);

			} else if(operacion.compare("lista_por_puntos") == 0) {

				ss >> puntos;
				cp.lista_por_puntos(puntos);

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
