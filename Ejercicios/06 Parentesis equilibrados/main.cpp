/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <stack>
#include <fstream>
#include <iostream>

bool comprobar(std::stack<char>& pila, const char& apertura) {

	bool expresionCorrecta = true;

	if(pila.empty() || pila.top() != apertura)

		expresionCorrecta = false;

	else

		pila.pop();

	return expresionCorrecta;

}

bool resolver(const std::string& linea) {

	std::stack<char> pila;

	bool expresionCorrecta = true;

	for(int i = 0 ; i < linea.size() && expresionCorrecta ; ++i) {

		switch(linea[i]) {
			case '{': pila.push(linea[i]); break;
			case '[': pila.push(linea[i]); break;
			case '(': pila.push(linea[i]); break;
			default:
				switch(linea[i]) {
					case '}': expresionCorrecta = comprobar(pila,'{'); break;
					case ']': expresionCorrecta = comprobar(pila,'['); break;
					case ')': expresionCorrecta = comprobar(pila,'('); break;
				}
		}

	}

	expresionCorrecta &= pila.empty();

	return expresionCorrecta;

}

bool resuelveCaso() {

	std::string linea;

	std::getline(std::cin,linea);

	if(!std::cin)

		return false;

	std::cout << ((resolver(linea))? "SI" : "NO") << std::endl;

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
