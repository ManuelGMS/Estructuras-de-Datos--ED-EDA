class Pelicula {

private:

	Hora final;
	Hora inicio;
	Hora duracion;
	char separator;
	std::string titulo;

public:

	bool operator < (const Pelicula& p) const {

		if(!((final < p.final) || (p.final < final))) {

			return titulo.compare(p.titulo) < 0;

		}

		return final < p.final;

	}

	friend std::istream& operator >> (std::istream& is, Pelicula& p);
	friend std::ostream& operator << (std::ostream& os, const Pelicula& p);

};

inline std::ostream& operator << (std::ostream& os, const Pelicula& p) {

	os << p.final << p.titulo;

	return os;

}

inline std::istream& operator >> (std::istream& is, Pelicula& p) {

	is >> p.inicio;
	is >> p.duracion;
	std::getline(is,p.titulo);
	p.final = p.inicio + p.duracion;

	return is;

}
