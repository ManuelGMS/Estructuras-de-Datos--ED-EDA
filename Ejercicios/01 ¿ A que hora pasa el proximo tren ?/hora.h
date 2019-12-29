class Hora {

	int horas;
	int minutos;
	int segundos;
	char separator;

public:

	Hora() : horas(0) , minutos(0) , segundos(0) , separator(':') {

	}

	Hora(const int& h, const int& m, const int& s, const char& c) : horas(h) , minutos(m) , segundos(s) , separator(c) {

		bool inferior = horas >= 0 && minutos >= 0 && segundos >= 0;

		bool superior = horas <= 23 && minutos <= 59 && segundos <= 59;

		if(!(inferior && superior))

			throw std::domain_error("ERROR");

	}

	bool operator < (const Hora& h) const {

		if(horas < h.horas)

			return true;

		else if(horas == h.horas)

			if(minutos < h.minutos)

				return true;

			else if(minutos == h.minutos)

				if(segundos < h.segundos)

					return true;

		return false;

	}

friend std::istream& operator >> (std::istream& is, Hora& h);

friend std::ostream& operator << (std::ostream& os, const Hora& h);

};

inline std::istream& operator >> (std::istream& is, Hora& h) {

	is >> h.horas >> h.separator >> h.minutos >> h.separator >> h.segundos;

	return is;

}

inline std::ostream& operator << (std::ostream& os, const Hora& h) {

	os << std::setfill('0') << std::setw(2) << h.horas;
	os << h.separator;
	os << std::setfill('0') << std::setw(2) << h.minutos;
	os << h.separator;
	os << std::setfill('0') << std::setw(2) << h.segundos;

	return os;

}
