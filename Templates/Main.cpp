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

	LinkedList<int> intList;
	for (int i = 0; i < 10; i++)
	{
		intList.addItem(i);
	}

	LinkedList<std::string> stringList;
	stringList.addItem("Hello");
	stringList.addItem("my");
	stringList.addItem("name");
	stringList.addItem("is");
	stringList.addItem("Ross");

	LinkedList<double> doubleList;
	doubleList.addItem(123.45342);
	doubleList.addItem(32.5009089);
	doubleList.addItem(1.3238978);


	for(int i = 0; i < intList.getNoOfItems(); i++)
	{
		std::cout << i << ": " << intList[i] << std::endl;
	}

	std::cout << "\n";

	for (int i = 0; i < stringList.getNoOfItems(); i++)
	{
		std::cout << i << ": " << stringList[i] << std::endl;
	}

	std::cout << "\n";

	for (int i = 0; i < doubleList.getNoOfItems(); i++)
	{
		std::cout << i << ": " << doubleList[i] << std::endl;
	}
	
	return 0;
}