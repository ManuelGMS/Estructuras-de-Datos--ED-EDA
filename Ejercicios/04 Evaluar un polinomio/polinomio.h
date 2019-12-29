class Polinomio {

	std::vector<std::pair<int,int>> monomios;

public:

	void nuevoMonomio(const std::pair<int,int>& monomio) {

		// Deberia ser con busquea binaria
		// Si encuentra el exponente "insert" del iterador O(n)
		// porque el hace el desplazamiento a la derecha.
		// Si no lo encuentra push_back;
		monomios.push_back(monomio);

	}

	int evaluar(const int& v) const {

		int result = 0;

		for(auto& m : monomios)

			result += m.first * pow(v,m.second);

		return result;

	}

};
