#include <iostream>
#include "Vector.h"

int main() {
	double a[] = { 5, 6 };
	Vector vector(a, 2);
	vector.print();
	vector.pushBack(8);
	std::cout << vector;
	vector.pushFront(9);
	std::cout << vector;
	vector.insert(10, 3);
	vector.print();
	vector.erase(3, 2);
	vector.print();
	std::cout << vector;
	std::cout << vector.find(9) << " " 
		<< vector.find(3);
	getchar();
	return 0;
}