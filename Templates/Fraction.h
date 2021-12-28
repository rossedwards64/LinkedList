#pragma once
class Fraction
{
public:
	Fraction(int numerator, int denominator);
	~Fraction();
	bool operator>(Fraction& rhs);

	int numerator;
	int denominator;
};

