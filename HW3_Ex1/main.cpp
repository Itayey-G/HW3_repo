#include "vector.h"
#include <iostream>

int main() {
	vector* v1 = new vector(5);
	vector* v2 = v1;
	std::cout << v1->capacity() << std::endl;

	if (v1->empty()) {
		for (int i = 0; i <= 5; i++) {
			v1->push_back(i * 2);
		}
	}
	v1->resize(10);
	v1->assign(10);
	v2->resize(10, 10);

	delete v2;
	delete v1;
	
	return 0;
}