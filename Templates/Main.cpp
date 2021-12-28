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

	LinkedList<int> ll;
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Adding " << i << " to the linked list" << std::endl;
		std::cout << ll.getNoOfItems() << std::endl;
		ll.addItem(i);
	}


	for(int i = 0; i < 11; i++)
	{
		std::cout << i << ": " << ll[i] << std::endl;
	}
	
	return 0;
}