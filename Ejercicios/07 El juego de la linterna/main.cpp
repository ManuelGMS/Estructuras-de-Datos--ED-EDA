/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <stack>
#include <vector>
#include <fstream>
#include <iostream>

bool resolver(const std::vector<int>& entrada) {

	int mediano = -1;

	std::stack<int> pila;

	bool siemprePremio = true;

	for (int i = entrada.size() - 1 ; i > -1 && siemprePremio ; --i) {

		if(entrada[i] < mediano) {

			siemprePremio = false;

		} else {

			while(!pila.empty() && entrada[i] > pila.top()) {

				mediano = std::max(mediano,pila.top());

				pila.pop();

			}

			pila.push(entrada[i]);

		}


		std::cout << entrada[i] << " " << mediano <<  std::endl;
	}

	return siemprePremio;

}

bool resuelveCaso() {

	int elementos;
	std::cin >> elementos;

	if(!std::cin)

		return false;

	std::vector<int> entrada(elementos);

	for(int& i : entrada)

		std::cin >> i;

	std::cout << ((resolver(entrada))? "SIEMPRE PREMIO" : "ELEGIR OTRA") << std::endl;

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
