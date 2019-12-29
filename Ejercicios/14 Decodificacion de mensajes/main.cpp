/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <iostream>

bool esVocal(const char& caracter) {

	bool esVocal = false;

	switch (caracter) {
		case 'a': esVocal = true; break;
		case 'A': esVocal = true; break;
		case 'e': esVocal = true; break;
		case 'E': esVocal = true; break;
		case 'i': esVocal = true; break;
		case 'I': esVocal = true; break;
		case 'o': esVocal = true; break;
		case 'O': esVocal = true; break;
		case 'u': esVocal = true; break;
		case 'U': esVocal = true; break;
	}

	return esVocal;

}

std::string resolver(const std::string& mensajeCodificado) {

	std::queue<char> cola;
	std::stack<char> pila;
	std::string mensajeDescodificado;

	for (int i = 0 ; i < mensajeCodificado.size() ; ++i) {

		if(i % 2 == 0)

			cola.push(mensajeCodificado[i]);

		else

			pila.push(mensajeCodificado[i]);

	}

	while(!pila.empty()) {

		cola.push(pila.top());
		pila.pop();

	}

	while(!cola.empty()) {

		if(esVocal(cola.front())) {

			mensajeDescodificado += cola.front();
			cola.pop();

		} else {

			while(!cola.empty() && !esVocal(cola.front())) {

				pila.push(cola.front());
				cola.pop();

			}

			while(!pila.empty()) {

				mensajeDescodificado += pila.top();
				pila.pop();

			}

		}

	}

	return mensajeDescodificado;

}

bool resuelveCaso() {

	std::string mensajeCodificado;

	getline(std::cin,mensajeCodificado);

	if(!std::cin)

		return false;

	std::cout << resolver(mensajeCodificado) << std::endl;

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
