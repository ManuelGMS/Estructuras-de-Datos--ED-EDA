// E24: Manuel Guerrero Moñús

#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <exception>
#include <unordered_map>

using duracion = int;
using cancion = std::string;
using artista = std::string;

class iPud {

private:

	using datosCancion = struct {

		artista artist;

		duracion duration;

		std::list<cancion>::iterator itListaDeReproduccion;

		std::list<cancion>::iterator itCancionesMasRecientes;

	};

	std::list<cancion> listaDeReproduccion;

	std::list<cancion> cancionesMasRecientes;

	std::unordered_map<cancion, datosCancion> memoria;

public:

	void addSong(const cancion& c, const artista& a, const duracion& d) {

		if (!memoria.count(c)) {

			memoria[c] = { a , d , listaDeReproduccion.end() , cancionesMasRecientes.end() };

		} else throw std::domain_error("ERROR addSong");

	}

	void addToPlaylist(const cancion& c) {

		auto it = memoria.find(c);

		if (it != memoria.end()) {

			if (it->second.itListaDeReproduccion == listaDeReproduccion.end())

				it->second.itListaDeReproduccion = listaDeReproduccion.insert(listaDeReproduccion.end(),c);

		} else throw std::domain_error("ERROR addToPlaylist");

	}

	cancion current() {

		if (listaDeReproduccion.size() == 0)

			throw std::domain_error("ERROR current");

		return (*listaDeReproduccion.begin());

	}

	void play() {

		if (listaDeReproduccion.size() > 0) {

			std::string cancion = current();

			std::cout << "Sonando " << cancion << std::endl;

			if (memoria[cancion].itListaDeReproduccion != listaDeReproduccion.end())

				listaDeReproduccion.erase(listaDeReproduccion.begin());

			memoria[cancion].itListaDeReproduccion = listaDeReproduccion.end();

			if(memoria[cancion].itCancionesMasRecientes != cancionesMasRecientes.end())

				cancionesMasRecientes.erase(memoria[cancion].itCancionesMasRecientes);
			
			memoria[cancion].itCancionesMasRecientes = cancionesMasRecientes.insert(cancionesMasRecientes.begin(),cancion);

		}
		else {

			std::cout << "No hay canciones en la lista" << std::endl;

		}

	}

	void totalTime() {

		int total = 0;

		for (const auto& it : listaDeReproduccion)

			total += memoria[it].duration;

		std::cout << "Tiempo total " << total << std::endl;

	}

	void recent(const size_t& n) {

		if (cancionesMasRecientes.size() > 0) {

			size_t i = 0;

			std::cout << "Las " << ((n > cancionesMasRecientes.size()) ? cancionesMasRecientes.size() : n) << " mas recientes" << std::endl;

			for (auto it = cancionesMasRecientes.begin(); it != cancionesMasRecientes.end() && i < n; ++i, ++it)

				std::cout << "    " << (*it) << std::endl;

		}
		else {

			std::cout << "No hay canciones recientes" << std::endl;

		}

	}

	void deleteSong(const cancion& c) {

		auto it = memoria.find(c);

		if (it != memoria.end()) {
			
			if(it->second.itListaDeReproduccion != listaDeReproduccion.end())

				listaDeReproduccion.erase(it->second.itListaDeReproduccion);

			if(it->second.itCancionesMasRecientes != cancionesMasRecientes.end())

				cancionesMasRecientes.erase(it->second.itCancionesMasRecientes);

			memoria.erase(c);

		}

	}

};

void resolver(const std::string& primeraLinea) {

	int d;
	iPud i;
	size_t n;
	cancion c;
	artista a;
	std::string orden;
	std::string linea(primeraLinea);

	do {

		std::stringstream ss(linea);

		ss >> orden;

		try {

			if (orden.compare("addSong") == 0) {

				ss >> c;
				ss >> a;
				ss >> d;
				i.addSong(c, a, d);

			}
			else if (orden.compare("addToPlaylist") == 0) {

				ss >> c;
				i.addToPlaylist(c);

			}
			else if (orden.compare("current") == 0) {

				i.current();

			}
			else if (orden.compare("play") == 0) {

				i.play();

			}
			else if (orden.compare("totalTime") == 0) {

				i.totalTime();

			}
			else if (orden.compare("recent") == 0) {

				ss >> n;
				i.recent(n);

			}
			else if (orden.compare("deleteSong") == 0) {

				ss >> c;
				i.deleteSong(c);

			}

		}
		catch (const std::domain_error& e) {

			std::cout << e.what() << std::endl;

		}

		std::getline(std::cin, linea);

	} while (linea.compare("FIN") != 0);

}

bool resuelveCaso() {

	std::string primeraLinea;
	std::getline(std::cin, primeraLinea);

	if (!std::cin)

		return false;

	if (primeraLinea.compare("FIN") != 0)

		resolver(primeraLinea);

	std::cout << "----" << std::endl;

	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	getchar();
#endif

	return 0;

}
