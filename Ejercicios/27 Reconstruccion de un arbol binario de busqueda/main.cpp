// E24: Manuel Guerrero Moñús

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

#include "bintree_eda.h"

bintree<int> reconstruirArbol(const std::vector<int>& preorden, const std::pair<int,int>& indices){

	if(indices.first > indices.second) {

		return {};

	} else {

		int i = indices.first + 1;

		int raiz = preorden[indices.first];

		while(i <= indices.second && raiz > preorden[i]) ++i;

		bintree<int> izq = reconstruirArbol(preorden,{indices.first+1,i-1});

		bintree<int> der = reconstruirArbol(preorden,{i,indices.second});

		return { izq , raiz , der };

	}

}

void recorridoPostOrden(const bintree<int>& bt, std::vector<int>& postOrden) {

	if(bt.left().empty() && bt.right().empty())

		postOrden.push_back(bt.root());

	else {

		if(!bt.left().empty())

			recorridoPostOrden(bt.left(),postOrden);

		if(!bt.right().empty())

			recorridoPostOrden(bt.right(),postOrden);

		postOrden.push_back(bt.root());

	}

}

bool resuelveCaso() {

	std::string linea;

	getline(std::cin,linea);

	if(!std::cin)

		return false;

	int dato;

	std::vector<int> preorden;

	std::pair<int,int> indices;

	std::stringstream ss(linea);

	while(ss >> dato)

		preorden.push_back(dato);

	bintree<int> bt = reconstruirArbol(preorden,{0,preorden.size()-1});

	std::vector<int> postOrden;

	recorridoPostOrden(bt,postOrden);

	for(const int& i : postOrden)

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
