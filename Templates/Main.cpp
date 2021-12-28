#include <iostream>
#include <crtdbg.h>
#include "Fraction.h"
#include "LinkedList.h"

template<typename T>
T& maximum(T& a, T& b);

template<typename T>
T& maximum(T& a, T& b) {
	return (a > b ? a : b);
}

int main() {
	_onexit(_CrtDumpMemoryLeaks);
	int a = 2;
	std::cout << a << std::endl;
	int b = 1;
	std::cout << b << std::endl;
	std::cout << maximum(a, b) << std::endl;

	Fraction f1(1, 4);
	Fraction f2(3, 4);

	Fraction max = maximum(f1, f2);

	template<typename T>
	LinkedList<T> ll();
	return 0;
}