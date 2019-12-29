/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <list>
#include <vector>
#include <fstream>
#include <iostream>

class persona {

private:

	int edad;
	std::string nombre;

public:

	persona() {

	}

	persona(std::string& n, int& e) : edad(e) , nombre(n) {

	}

	int getEdad() const {
		return edad;
	}

	std::string getNombre() const {
		return nombre;
	}

};

template<typename T>
class miLista : public std::list<T> {

public:

	template<typename Predicate>
	void removeif(Predicate predicado) {

		auto it = this->begin();

		while(it != this->end()) {

			if(predicado(*it))

				it = this->erase(it);

			else

				++it;

		}

	}

};

class objetoFuncion {

private:

	int edadMinima;
	int edadMaxima;

public:

	objetoFuncion(int& emi, int& ema) : edadMinima(emi) , edadMaxima(ema) {

	}

	bool operator()(const persona& p) {

		return p.getEdad() < edadMinima || p.getEdad() > edadMaxima;

	}

};

bool resuelveCaso() {

	int personas;
	int edadMinima;
	int edadMaxima;

	std::cin >> personas >> edadMinima >> edadMaxima;

	if(personas == 0 && edadMinima == 0 && edadMinima == 0)

		return false;

	int edad;
	char separador;
	std::string nombre;
	miLista<persona> lista;

	for( ; personas > 0 ; --personas) {

		std::cin >> edad;
		getline(std::cin,nombre);
		nombre.erase(nombre.begin());
		lista.push_back(persona(nombre,edad));

	}

	objetoFuncion filtraedad(edadMinima,edadMaxima);

	lista.removeif(filtraedad);

	// lista.removeif([&edadMinima,&edadMaxima](const persona& p) -> bool { return p.getEdad() < edadMinima || p.getEdad() > edadMaxima; });

	for(auto it = lista.begin() ; it != lista.end() ; ++it)

		std::cout << (*it).getNombre() << std::endl;

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
