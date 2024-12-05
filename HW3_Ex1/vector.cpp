#include "vector.h"
#include <iostream>

vector::vector()
{
	setSize(0);
	setCapacity(10);
	setResizeFactor(capacity());
	this->_elements = new int[capacity()];
}

vector::vector(int n)
{
	setSize(0);
	if (n < 2) { //make vector's capacity 2 if entered less than that
		setCapacity(2);
		setResizeFactor(2);
	}
	else {
		setCapacity(n);
		setResizeFactor(n);
	}
	;
	this->_elements = new int[capacity()];
}

vector::~vector()
{
	delete[] this->_elements;
}

int vector::size() const
{
	return this->_size;
}

int vector::capacity() const
{
	return this->_capacity;
}

int vector::resizeFactor() const
{
	return this->_resizeFactor;
}

bool vector::empty() const
{
	return this->size() == 0;
}

void vector::setSize(int size)
{
	this->_size = size;
}

void vector::setCapacity(int capacity)
{
	this->_capacity = capacity;
}

void vector::setResizeFactor(int resizeFactor)
{
	this->_resizeFactor = resizeFactor;
}

void vector::push_back(const int& val)
{
	//check if size equals capacity
	if (size() == capacity()) {
		setCapacity(capacity() * 2);
		int* new_elements = new int[capacity()];
		for (int i = 0; i <= size(); i++) {
			new_elements[i] = this->_elements[i];
		}
		
		delete[] this->_elements;
	}
	this->_elements[size()] = val;
	setSize(size() + 1);
}

/* will return the last value in the vector and put it out of the vector
* input: none
* output: the value at the end of the vector*/
int vector::pop_back()
{
	int pop = 0;
	if (size() == 0) { //check if there are any values to return
		std::cerr << "error: pop from empty" << std::endl;
		return -9999;
	}
	pop = this->_elements[size()];
	//delete this->_elements[size()];
	setSize(size() - 1);
	return pop;
}

/* will check that the factor is bigger than a number, if not increase it.
* input: the number to check
* output: none*/
void vector::reserve(int n)
{
	if (n > capacity()) {
		setCapacity(((n / resizeFactor()) + 1) * resizeFactor());
	}
}

/* Will resize the vector to the wanted size
* input: the wanted size 
* output: none*/
void vector::resize(int n)
{
	if (n < 2) { //check that n is not smaller than the smallest decided space
		n = 2;
	}
	if (capacity() < n) {
		reserve(n);
		while (size() < n) { //is this needed?
			push_back(0);
		}
	}

	while (capacity() > n) {
		pop_back();
	}
}

/* will resize the vector and put the value in all new avalable space
* input: the new size and the value to enter
* output: none */
void vector::resize(int n, const int& val)
{
	if (n < 2) { //check that n is not smaller than the smallest decided space
		n = 2;
	}
	if (capacity() < n) {
		reserve(n);
		while (size() < n) { 
			push_back(val);
		}
	}

	while (capacity() > n) {
		pop_back();
	}
}

/*will put value in every avalable place
* input: the value to put
* output: nont */
void vector::assign(int val)
{
	for (int i = 0; i <= size(); ++i) {
		pop_back();
		push_back(val);
	}
}

/* copy c'tor
* input: the vector to copy from
*/
vector::vector(const vector& other)
{
	*this = other;
}

/* will copy the data from one vector and put it in the wanted one
* input: */
vector& vector::operator=(const vector& other)
{
	if (this == &other) { 
		return *this; //for self-assignment
	}

	delete[] this->_elements;

	setSize(other.size());
	setCapacity(other.capacity());
	setResizeFactor(other.resizeFactor());
	int* new_elements = new int[capacity()];
	std::copy(other._elements, other._elements + other.size(), new_elements);
	this->_elements = new_elements;

	return *this;
}

/*will return the vector's element in place n
* input: the place of the element to get
* output: the element*/
int& vector::operator[](int n) const
{
	if (n < capacity() and n > 0) { //check if n is legal index
		std::cerr << "Index error: n is out of vector's range" << std::endl;
		return this->_elements[0];
	}

	return this->_elements[n];
}
