// E24: Manuel Guerrero Moñús

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "bintree_eda.h"

struct indices {
	std::pair<int,int> in;
	std::pair<int,int> pre;
};

bintree<int> reconstruirArbol(const std::vector<int>& preorden, const std::vector<int>& inorden, const indices& i) {

	if(i.pre.first > i.pre.second) {

		return {};

	} else {

		int raiz = preorden[i.pre.first];

		int posicionRaizInorden = std::distance(inorden.begin()+i.in.first,std::find(inorden.begin()+i.in.first,inorden.begin()+i.in.second,raiz));

		bintree<int> izq = reconstruirArbol(preorden,inorden,{{i.in.first,i.in.first+posicionRaizInorden-1},{i.pre.first+1,i.pre.first+posicionRaizInorden}});

		bintree<int> der = reconstruirArbol(preorden,inorden,{{i.in.first+posicionRaizInorden+1,i.in.second},{i.pre.first+posicionRaizInorden+1,i.pre.second}});

		return { izq , raiz , der };

	}

}

std::vector<int> recorrerElArbol(const bintree<int>& bt) {

	std::vector<int> izq;
	std::vector<int> der;

	if(!bt.left().empty())

		izq = recorrerElArbol(bt.left());

	if(!bt.right().empty())

		der = recorrerElArbol(bt.right());

	for(const int& i : der)

		izq.push_back(i);

	izq.push_back(bt.root());

	return izq;

}

bool resuelveCaso() {

	std::string linea;
	std::getline(std::cin,linea);

	if(!std::cin)

		return false;

	int dato;

	std::vector<int> preorden;
	std::stringstream ss1(linea);

	while(ss1 >> dato)

		preorden.push_back(dato);

	std::getline(std::cin,linea);

	std::vector<int> inorden;
	std::stringstream ss2(linea);

	while(ss2 >> dato)

		inorden.push_back(dato);

	struct indices i = {
		{0,inorden.size()-1},
		{0,preorden.size()-1}
	};

	bintree<int> bt = reconstruirArbol(preorden,inorden,i);

	std::vector<int> postorden = recorrerElArbol(bt);

	for(const int& i : postorden)

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
