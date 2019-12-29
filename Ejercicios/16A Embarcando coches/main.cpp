/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <fstream>
#include <iostream>

using ui = unsigned int;

ui resolver(std::deque<std::string>& matriculasDeCochesEnElCarrilDelPuerto, std::list<std::string>& matriculasDeCochesEnOrdenDeEmbarque) {

	std::stack<std::string> muelle;

	ui cochesQueEntranEnElCarril = 0;

	auto it = matriculasDeCochesEnOrdenDeEmbarque.cbegin();

	while(!matriculasDeCochesEnElCarrilDelPuerto.empty() || !muelle.empty()) {

		if(!matriculasDeCochesEnElCarrilDelPuerto.empty() && (*it).compare(matriculasDeCochesEnElCarrilDelPuerto.front()) == 0) {

			matriculasDeCochesEnElCarrilDelPuerto.pop_front();
			++it;

		} else {

			if(!muelle.empty() && (*it).compare(muelle.top()) == 0) {

				muelle.pop();
				++it;

			} else {

				if(!matriculasDeCochesEnElCarrilDelPuerto.empty()) {

					muelle.push(matriculasDeCochesEnElCarrilDelPuerto.front());
					matriculasDeCochesEnElCarrilDelPuerto.pop_front();
					++cochesQueEntranEnElCarril;

				} else {

					while(!muelle.empty()) {

						matriculasDeCochesEnElCarrilDelPuerto.push_front(muelle.top());
						muelle.pop();

					}

				}

			}

		}

	}

	return cochesQueEntranEnElCarril;

}

bool resuelveCaso() {

	ui cochesQueDebenEmbarcar;
	std::cin >> cochesQueDebenEmbarcar;

	if(!std::cin)

		return false;

	std::string matricula;

	std::list<std::string> matriculasDeCochesEnOrdenDeEmbarque;

	for (ui i = 0; i < cochesQueDebenEmbarcar ; ++i) {

		std::cin >> matricula;

		matriculasDeCochesEnOrdenDeEmbarque.push_back(matricula);

	}

	std::deque<std::string> matriculasDeCochesEnElCarrilDelPuerto;

	for (ui i = 0; i < cochesQueDebenEmbarcar ; ++i) {

		std::cin >> matricula;

		matriculasDeCochesEnElCarrilDelPuerto.push_front(matricula);

	}

	std::cout << resolver(matriculasDeCochesEnElCarrilDelPuerto,matriculasDeCochesEnOrdenDeEmbarque) << std::endl;

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
