#pragma once
class Fraction
{
public:
	Fraction(int numerator, int denominator);
	~Fraction();
	bool operator>(const Fraction& rhs) const;

	int numerator;
	int denominator;
};

