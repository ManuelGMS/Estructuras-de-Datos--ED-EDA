// E24: Manuel Guerrero Moñús

#include<set>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<unordered_map>

const int MAX_EMISIONES = 100001;

using pelicula = struct {

	int emisiones;
	std::vector<std::pair<std::string, int>> reparto;

};

inline void resolver(const std::vector<std::string>& peliculasEnOrdenDeEmision, std::unordered_map<std::string, pelicula>& datosDePeliculas) {

	std::unordered_map<std::string, int> actorTotalTiempo; // Nombre - Total Tiempo

	int maxEmisiones = 0;
	std::vector<std::string> ultimaPeliculaEmitidaConIndiceEmisiones(MAX_EMISIONES); // Posicion = Emisiones ; Contenido = Pelicula

	// -------------------------------------------------------------------------------------------------------------

	// Parte1 Coste: O( Peliculas * Actores )

	for (int i = 0; i < peliculasEnOrdenDeEmision.size(); i++) { // O(peliculas)

		const std::string& peliculaActual = peliculasEnOrdenDeEmision[i]; // O(1)

		pelicula& peliConsultada = datosDePeliculas[peliculaActual]; // O(1)

		++peliConsultada.emisiones; // O(1)

		if (peliConsultada.emisiones > maxEmisiones) // O(1)

			maxEmisiones = peliConsultada.emisiones; // O(1)

		ultimaPeliculaEmitidaConIndiceEmisiones[peliConsultada.emisiones] = peliculaActual; // O(1)

		for (auto& it : peliConsultada.reparto) // O(actores) 

			actorTotalTiempo[it.first] += it.second; // O(1)

	}

	// Parte 2 Coste: O( 2 * Actores * log(DistintosTiemposDeActuacion) )

	std::map<int, std::set<std::string>, std::greater<int>> mejorActor; // Minutos - Nombres [ A - Z ]

	for (const auto& actorTiempo : actorTotalTiempo) // O(actores)

		mejorActor[actorTiempo.second].insert(actorTiempo.first); // O(2 * log(DistintosTiemposDeActuacion))

	// Coste total del algoritmo: O( Actores * ( Peliculas + 2 * log(DistintosTiemposDeActuacion) ) )  

	std::cout << maxEmisiones << " " << ultimaPeliculaEmitidaConIndiceEmisiones[maxEmisiones] << std::endl;

	std::cout << mejorActor.begin()->first;

	for (const std::string& it : mejorActor.begin()->second)

		std::cout << " " << it;

	std::cout << std::endl;

}

bool resuelveCaso() {

	int peliculas;
	std::cin >> peliculas;

	if (peliculas == 0)

		return false;

	std::unordered_map<std::string, pelicula> datosDePeliculas;

	for (int p = 0; p < peliculas; ++p) { // O( Peliculas * Actores )

		int actores;
		std::string titulo;

		std::cin >> titulo >> actores;

		pelicula peli = { 0 , std::vector<std::pair<std::string,int>>(actores) };

		for (int a = 0; a < actores; ++a) { // O( Actores ) 	

			int tiempo;
			std::string actor;

			std::cin >> actor >> tiempo;

			peli.reparto[a] = { actor,tiempo }; // O(1)

		}

		datosDePeliculas[titulo] = peli; // O(1)

	}

	int emisiones;
	std::cin >> emisiones;

	std::vector<std::string> peliculasEnOrdenDeEmision(emisiones);

	for (auto& p : peliculasEnOrdenDeEmision) // O(Emisiones)

		std::cin >> p;

	resolver(peliculasEnOrdenDeEmision, datosDePeliculas);

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
