
#pragma once
#include <iostream>

using namespace std;

class Monom {
public:

	double coef;
	int power;

	Monom(double coef = 0, int power = -1) {
		this->coef = coef;
		this->power = power;
	}

	Monom(const Monom& m) {
		this->coef = m.coef;
		this->power = m.power;
	}

	bool operator==(const Monom &m)
	{
		if (power == m.power)
			return true;

		return false;
	}

	bool operator<(const Monom &m)
	{
		if (power < m.power)
			return true;

		return false;
	}

	bool operator>(const Monom &m)
	{
		if (power > m.power)
			return true;

		return false;
	}


};
