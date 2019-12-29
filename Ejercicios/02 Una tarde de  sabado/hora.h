class Hora {

private:

	int horas;
	int minutos;
	int segundos;
	char separator;

public:

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

	Hora operator + (const Hora& h) const {

		Hora temp = *this;

		temp.horas += h.horas;
		temp.minutos += h.minutos;
		temp.segundos += h.segundos;

		temp.minutos += temp.segundos / 60;
		temp.horas += temp.minutos / 60;
		temp.segundos %= 60;
		temp.minutos %= 60;

		return temp;

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
