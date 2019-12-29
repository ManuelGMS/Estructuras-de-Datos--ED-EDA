/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<int> resolver(const std::vector<int>& valorSobre, const int& comensales) {

	int i;
	std::vector<int> solucion;
	std::deque<int> colaDatos;
	std::deque<int> colaMaximos;

	for (i = 0 ; i < comensales ; ++i) {

		colaDatos.push_back(valorSobre[i]);

		while(!colaMaximos.empty() && colaMaximos.back() < valorSobre[i])

			colaMaximos.pop_back();

		colaMaximos.push_back(valorSobre[i]);

	}

	solucion.push_back(colaMaximos.front());

	for ( ; i < valorSobre.size() ; ++i) {

		// Este dato es el ultimo que debe de ser eliminado actualmente.
		colaDatos.push_back(valorSobre[i]);

		// Si el maximo coincide con el orden de entrada entonces es eliminado, si no
		// entonces el dato ya fue eliminado de la cola de maximos anteriormente y no tenemos que preocuparnos.
		if(colaDatos.front() == colaMaximos.front())

			colaMaximos.pop_front();

		// Al dato correspondiente le toca el turno de ser eliminado.
		colaDatos.pop_front();

		// Si el dato es el mayor de todos entonces la cola de maximos se vacia.
		// Si el dato no es el mayor de todos entonces elimina los otros hasta que este es colocado en su sitio.
		while(!colaMaximos.empty() && colaMaximos.back() < valorSobre[i])

			colaMaximos.pop_back();

		// Añadimos el maximo en la posicion que corresponda.
		colaMaximos.push_back(valorSobre[i]);

		// Añadimos el maximo al vector de soluciones.
		solucion.push_back(colaMaximos.front());

	}

	return solucion;

}

bool resuelveCaso() {


	int sobres, comensales;

	std::cin >> sobres >> comensales;

	if(sobres == 0 && comensales == 0)

		return false;

	std::vector<int> valorSobre(sobres);

	for(int& i : valorSobre)

		std::cin >> i;

	for(const int& i : resolver(valorSobre,comensales))

		std::cout << i << " ";

	std::cout << std::endl;

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
