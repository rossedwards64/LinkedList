#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : numerator(0), denominator(0) {
	
}

Fraction::~Fraction() {

}

bool Fraction::operator>(const Fraction& rhs) const
{
	const int tn1 = this->numerator * rhs.denominator;
	const int tn2 = rhs.numerator * this->denominator;
	return tn1 > tn2;
}
