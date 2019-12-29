// E24: Manuel Guerrero Moñús

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <unordered_map>

using medico = std::string;
using paciente = std::string;

class fecha {

private:

	int dia;
	int hora;
	int minuto;

public:

	fecha(const int& d, const int& h, const int& m) : dia(d) , hora(h) , minuto(m) {}

	bool operator < (const fecha& that) const {

		if(this->dia < that.dia)

			return true;

		else if(this->dia == that.dia) {

			if(this->hora < that.hora)

				return true;

			else if(this->hora == that.hora) {

				if(this->minuto < that.minuto)

					return true;

			}

		}

		return false;

	}

	void print() const {

		//std::cout << std::setw(2) << std::setfill('0') << this->dia;
		//std::cout << ':';
		std::cout << std::setw(2) << std::setfill('0') << this->hora;
		std::cout << ':';
		std::cout << std::setw(2) << std::setfill('0') << this->minuto;

	}

	int getDia() const {

		return this->dia;

	}

};

class consultorio {

private:

	std::unordered_map<medico,std::map<fecha,paciente>> medicoFechaPaciente;

public:

	void nuevoMedico(const medico& m) {

		medicoFechaPaciente[m];

	}

	void pideConsulta(const paciente& p, const medico& m, const fecha& f) {

		auto itMedico = medicoFechaPaciente.find(m);

		if(itMedico != medicoFechaPaciente.end()) {

			if(!(*itMedico).second.count(f)) {

				(*itMedico).second[f] = p;

			} else {

				throw std::domain_error("Fecha ocupada");

			}

		} else {

			throw std::domain_error("Medico no existente");

		}

	}

	void siguientePaciente(const medico& m) {

		auto itMedico = medicoFechaPaciente.find(m);

		if(itMedico != medicoFechaPaciente.end()) {

			if((*itMedico).second.size() != 0) {

				std::cout << "Siguiente paciente doctor " << (*itMedico).first << std::endl;

				std::cout << (*(*itMedico).second.begin()).second << std::endl;

				std::cout << "---" << std::endl;

			} else {

				throw std::domain_error("No hay pacientes");

			}

		} else {

			throw std::domain_error("Medico no existente");

		}

	}

	void atiendeConsulta(const medico& m) {

		auto itMedico = medicoFechaPaciente.find(m);

		if(itMedico != medicoFechaPaciente.end()) {

			if((*itMedico).second.size() != 0) {

				(*itMedico).second.erase((*itMedico).second.begin());

			} else {

				throw std::domain_error("No hay pacientes");

			}

		} else {

			throw std::domain_error("Medico no existente");

		}

	}

	void listaPacientes(const medico& m, const int& d) {

		auto itMedico = medicoFechaPaciente.find(m);

		if(itMedico != medicoFechaPaciente.end()) {

			std::cout << "Doctor " << m << " dia " << d << std::endl;

			for(const auto& it : (*itMedico).second) {

				if(it.first.getDia() == d) {

					std::cout << it.second << " ";

					it.first.print();

					std::cout << std::endl;

				}

			}

			std::cout << "---" << std::endl;

		} else {

			throw std::domain_error("Medico no existente");

		}

	}

};

void resolver(int& lineas) {

	int dia;
	int hora;
	int minuto;

	medico m;
	paciente p;
	consultorio c;
	std::string linea;
	std::string operacion;

	for( ; lineas > 0 ; --lineas) {

		getline(std::cin,linea);

		std::stringstream ss(linea);

		ss >> operacion;

		try {

			if(operacion.compare("nuevoMedico") == 0) {

				ss >> m;
				c.nuevoMedico(m);

			} else if(operacion.compare("pideConsulta") == 0) {

				ss >> p;
				ss >> m;
				ss >> dia;
				ss >> hora;
				ss >> minuto;

				c.pideConsulta(p,m,fecha(dia,hora,minuto));

			} else if(operacion.compare("listaPacientes") == 0) {

				ss >> m;
				ss >> dia;
				c.listaPacientes(m,dia);

			} else if(operacion.compare("siguientePaciente") == 0) {

				ss >> m;
				c.siguientePaciente(m);

			} else if(operacion.compare("atiendeConsulta") == 0) {

				ss >> m;
				c.atiendeConsulta(m);

			}

		} catch(const std::domain_error& e) {

			std::cout << e.what() << "\n---\n";

		}

	}

}

bool resuelveCaso() {

	int lineas;
	std::cin >> lineas;

	if(!std::cin)

		return false;

	std::cin.ignore();

	resolver(lineas);

	std::cout << "------" << std::endl;

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
