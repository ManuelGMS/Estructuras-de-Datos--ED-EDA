// E24: Manuel Guerrero Moñús

#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <unordered_map>

using alumno = std::string;
using profesor = std::string;

class autoescuela {

private:

	typedef struct {

		int puntos;

		std::string profesor;

	} datosAlumno;

	std::unordered_map<alumno,datosAlumno> alumnoDatos;

	std::unordered_map<profesor,std::set<alumno>> profesorAlumnos;

public:

	autoescuela() {}

	void alta(const alumno& a, const profesor& p) {

		auto itAlumno = alumnoDatos.find(a);

		profesorAlumnos[p].insert(a);

		if(itAlumno != alumnoDatos.end()) {

			if((*itAlumno).second.profesor.compare(p) != 0) {

				profesorAlumnos[(*itAlumno).second.profesor].erase(a);

				(*itAlumno).second.profesor = p;

			}

		} else {

			alumnoDatos[a] = { 0 , p };

		}

	}

	void es_alumno(const alumno& a, const profesor& p) {

		std::cout << a << " " << ( (profesorAlumnos[p].count(a))? "es" : "no es" ) << " alumno de " << p << std::endl;

	}

	void puntuacion(const alumno& a) const {

		auto it = alumnoDatos.find(a);

		if(it != alumnoDatos.end())

			std::cout << "Puntuacion de " << a << ": " << (*it).second.puntos << std::endl;

		else

			throw std::domain_error("El alumno " + a + " no esta matriculado");

	}

	void actualizar(const alumno& a, const int& n) {

		auto it = alumnoDatos.find(a);

		if(it != alumnoDatos.end())

			(*it).second.puntos += n;

		else

			throw std::domain_error("El alumno " + a + " no esta matriculado");

	}

	void examen(const profesor& p, const int& n) {

		std::cout << "Alumnos de " << p << " a examen:" << std::endl;

		for(const auto& alumno : profesorAlumnos[p]) {

			if(alumnoDatos[alumno].puntos >= n) {

				std::cout << alumno << std::endl;

			}

		}

	}

	void aprobar(const alumno& a) {

		auto it = alumnoDatos.find(a);

		if(it != alumnoDatos.end()) {

			profesorAlumnos[(*it).second.profesor].erase(a);

			alumnoDatos.erase(a);

		} else

			throw std::domain_error("El alumno " + a + " no esta matriculado");

	}

};

void resolver(const std::string& primeraLinea) {

	int n;
	alumno a;
	profesor p;
	autoescuela aE;
	std::string orden;
	std::string linea(primeraLinea);

	do {

		std::stringstream ss(linea);

		ss >> orden;

		try {

			if(orden.compare("alta") == 0) {

				ss >> a;
				ss >> p;
				aE.alta(a,p);

			} else if(orden.compare("es_alumno") == 0) {

				ss >> a;
				ss >> p;
				aE.es_alumno(a,p);

			} else if(orden.compare("puntuacion") == 0) {

				ss >> a;
				aE.puntuacion(a);

			} else if(orden.compare("actualizar") == 0) {

				ss >> a;
				ss >> n;
				aE.actualizar(a,n);

			} else if(orden.compare("examen") == 0) {

				ss >> p;
				ss >> n;
				aE.examen(p,n);

			} else if(orden.compare("aprobar") == 0) {

				ss >> a;
				aE.aprobar(a);

			}


		} catch(const std::domain_error& e) {

			std::cout << "ERROR" << std::endl;

		}

		std::getline(std::cin,linea);

	} while(linea.compare("FIN") != 0);

}

bool resuelveCaso() {

	std::string primeraLinea;
	std::getline(std::cin,primeraLinea);

	if(!std::cin)

		return false;

	if(primeraLinea.compare("FIN") != 0)

		resolver(primeraLinea);

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
