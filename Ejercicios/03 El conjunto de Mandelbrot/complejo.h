template<typename T>
class Complejo {

	T real;
	T imaginaria;

public:

	Complejo(const T& r, const T& i) : real(r) , imaginaria(i) {

	}

	Complejo operator + (const Complejo& c) const {

		return Complejo(real + c.real, imaginaria + c.imaginaria);

	}

	Complejo operator * (const Complejo& c) const {

		return Complejo(real * c.real - imaginaria * c.imaginaria, real * c.imaginaria + c.real * imaginaria);

	}

	float iMod() const {

		return sqrt(real*real+imaginaria*imaginaria);

	}

};
