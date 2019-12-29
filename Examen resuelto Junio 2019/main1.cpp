// E24: Manuel Guerrero Moñús

/*

Complejidad: O(n) --> Para n numero de fechas.

El recorrido del vector y el tratamiento de los datos de la pila es lineal.

*/

#include<stack>
#include<vector>
#include<iomanip>
#include <fstream>
#include <iostream>

class fecha {

	int dia;
	int mes;
	int anyo;
	int muertos;

public:

	fecha() {}

	fecha(int& d, int& me, int& a, int& mu) : dia(d) , mes(me) , anyo(a) , muertos(mu) {}

	int getDia() const {
		return this->dia;
	}

	int getMes() const {
		return this->mes;
	}

	int getAnyo() const {
		return this->anyo;
	}

	int getMuertos() const {
		return this->muertos;
	}

	void print() const {
		std::cout << std::setw(2) << std::setfill('0') << dia << "/" << std::setw(2) << std::setfill('0') << mes << "/" << std::setw(4) << std::setfill('0') << anyo << std::endl;
	}

};

void resolver(const std::vector<fecha>& fechas) {

	std::stack<fecha> pila;

	for (int i = 0; i < fechas.size(); ++i) {

		if (pila.empty()) {

			std::cout << "NO HAY" << std::endl;

		} else {

			while (!pila.empty() && pila.top().getMuertos() <= fechas[i].getMuertos())

				pila.pop();

			if (pila.empty())

				std::cout << "NO HAY" << std::endl;

			else

				pila.top().print();

		}

		pila.push(fechas[i]);

	}

}


bool resuelveCaso() {

	int casos;
	std::cin >> casos;

	if (!std::cin)

		return false;

	std::vector<fecha> fechas(casos);

	for (int i = 0; i < casos; ++i) {
	
		int d;
		int me;
		int a;
		int mu;
		char sep;

		std::cin >> d >> sep >> me >> sep >> a >> mu;

		fechas[i] = fecha(d,me,a,mu);
		
	}

	resolver(fechas);

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
	getchar();
#endif

	return 0;

}
