/*
E24: Manuel Guerrero Moñús
Coste: O(n)
*/

#include <queue>
#include <limits>
#include <vector>
#include <fstream>
#include <iostream>

const int MAS_INFINITO = std::numeric_limits<int>::max();

using elemento = std::pair<int,std::queue<int>>;

using diccionario = std::vector<elemento>;

int resolver(const std::vector<int>& mensaje, diccionario& indicesDeLasClaves) {

	int minimo = MAS_INFINITO;

	bool claveEncontrada = false;

	// Para cada caracter del texto
	for(int i = 0 ; i < mensaje.size() ; ++i) {

		// Miro si el numero es una clave
		for (int j = 0 ; j < indicesDeLasClaves.size() && !claveEncontrada ; ++j)

			// Si efectivamente es una clave
			if(indicesDeLasClaves[j].first == mensaje[i])

				// Si es eel primer digito de la clave o su anterior digito de clave ya ha salido
				if(j == 0 || indicesDeLasClaves[j-1].second.size() > 0) {

					// Pongo el digito final en el vector actual
					indicesDeLasClaves[j].second.push(i);

					// Si el vector actual es el que almacena la posicion del ultimo digito que cierra la clave
					if(indicesDeLasClaves[indicesDeLasClaves.size()-1].second.size() > 0) {

						int ultimoEliminado;
						int eliminarMenoresQueEste = indicesDeLasClaves[j].second.front();

						// Comenzando desde el penultimo vector hasta el primero
						for(int k = 1 ; j - k > -1 ; ++k) {

							// Mientras el vector actual no se vacie y aun no haya eliminado los numeros no necesarios en el vector actual
							while(!indicesDeLasClaves[j-k].second.empty() && indicesDeLasClaves[j-k].second.front() < eliminarMenoresQueEste) {

								ultimoEliminado = indicesDeLasClaves[j-k].second.front();

								indicesDeLasClaves[j-k].second.pop();

							}

							eliminarMenoresQueEste = ultimoEliminado;

						}

						// Obtenemos la longitud de la clave como la diferencia entre las posiciones del ultimo y del primero
						minimo = std::min(minimo,(indicesDeLasClaves[j].second.front()-ultimoEliminado)+1);

						// Eliminamos el ultimo digito de la clave
						indicesDeLasClaves[j].second.pop();

						// Para que el for no siga iterando y pase al siguiente numero del mensaje
						claveEncontrada = true;

						// Para todos los vectores
						for(int k = 0 ; k < indicesDeLasClaves.size() ; ++k) {

							// Si encuentro alguno vacio
							if(indicesDeLasClaves[k].second.empty()) {

								// Entonces los vectores superiores tienen que vaciarse ya que no seran validos
								for (int q = k + 1 ; q < indicesDeLasClaves.size() ; ++q) {

									while(!indicesDeLasClaves[q].second.empty())

										indicesDeLasClaves[q].second.pop();

								}

								k = indicesDeLasClaves.size();

							// Si el primer numero de una fila es mayor que el primer numero de su siguiente, las cifras han perdido el orden.
							} else if(k + 1 < indicesDeLasClaves.size() && indicesDeLasClaves[k].second.front() > indicesDeLasClaves[k+1].second.front()) {

								// Entonces los vectores superiores tienen que vaciarse ya que no seran validos
								for (int q = k + 1 ; q < indicesDeLasClaves.size() ; ++q) {

									while(!indicesDeLasClaves[q].second.empty() && indicesDeLasClaves[q].second.front() < indicesDeLasClaves[q-1].second.front())

										indicesDeLasClaves[q].second.pop();

								}

									k = indicesDeLasClaves.size();

							}

						}

					}

				}

		claveEncontrada = false;

	}

	return minimo;

}

bool resuelveCaso() {

	int longitudClave;
	std::cin >> longitudClave;

	if(!std::cin)

		return false;

	diccionario indicesDeLasClaves(longitudClave);

	for(elemento& i : indicesDeLasClaves)

		std::cin >> i.first;

	int longitudMensaje;
	std::cin >> longitudMensaje;

	std::vector<int> mensaje(longitudMensaje);

	for(int& i : mensaje)

		std::cin >> i;

	std::cout << resolver(mensaje,indicesDeLasClaves) << std::endl;

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
