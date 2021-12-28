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

typedef LinkedList<int> intList;
typedef LinkedList<std::string> stringList;
typedef LinkedList<double> doubleList;

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

	intList ll1;
	for (int i = 0; i < 10; i++)
	{
		ll1.addItem(i);
	}

	stringList ll2;
	ll2.addItem("Hello");
	ll2.addItem("my");
	ll2.addItem("name");
	ll2.addItem("is");
	ll2.addItem("Ross");

	doubleList ll3;
	ll3.addItem(123.45342);
	ll3.addItem(32.5009089);
	ll3.addItem(1.3238978);


	for(int i = 0; i < ll1.getNoOfItems(); i++)
	{
		std::cout << i << ": " << ll1[i] << std::endl;
	}

	std::cout << "\n";

	for (int i = 0; i < ll2.getNoOfItems(); i++)
	{
		std::cout << i << ": " << ll2[i] << std::endl;
	}

	std::cout << "\n";

	for (int i = 0; i < ll3.getNoOfItems(); i++)
	{
		std::cout << i << ": " << ll3[i] << std::endl;
	}
	
	return 0;
}