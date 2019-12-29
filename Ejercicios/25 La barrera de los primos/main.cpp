// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

struct datos {
	int valor;
	int profundidad;
};

datos recorrerArbol(const bintree<int>& bt, const int& profundidad){

	if(!bt.empty()) {

		int divisor = 2;

		while(divisor < bt.root() / 2 && bt.root() % divisor != 0)

			++divisor;

		if(bt.root() % divisor != 0)

			return { -1 , -1 };

		if(bt.root() % 7 == 0)

			return { bt.root() , profundidad };

		datos izq = recorrerArbol(bt.left(),profundidad+1);

		datos der = recorrerArbol(bt.right(),profundidad+1);

		if(izq.valor % 7 == 0 && der.valor % 7 == 0)

			if(izq.profundidad <= der.profundidad)

				return { izq.valor , izq.profundidad };

			else

				return { der.valor , der.profundidad };

		if(izq.valor % 7 == 0)

			return { izq.valor , izq.profundidad };

		if(der.valor % 7 == 0)

			return { der.valor , der.profundidad };

	}

	return { -1 , -1 };

}

void resuelveCaso() {

	datos solucion = recorrerArbol(leerArbol(-1),1);

	if(solucion.valor == -1)

		std::cout << "NO HAY" << std::endl;

	else

		std::cout << solucion.valor << " " << solucion.profundidad << std::endl;

}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("EntradaEjemplo.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	int casos;
	std::cin >> casos;

	for ( ; casos > 0 ; --casos)

		resuelveCaso();

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		// getchar();
	#endif

	return 0;

}
