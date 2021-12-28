#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator) : numerator(0), denominator(0) {
	
}

Fraction::~Fraction() {

}

bool Fraction::operator>(Fraction& rhs) {
	int tn1 = this->numerator * rhs.denominator;
	int tn2 = rhs.numerator * this->denominator;
	return tn1 > tn2;
}