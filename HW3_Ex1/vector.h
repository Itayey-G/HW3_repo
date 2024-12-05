#pragma once

class vector {
public:
	vector(); //c'tor
	vector(int n); //c'tor
	~vector(); //d'tor

	//getters
	int size() const;
	int capacity() const;
	int resizeFactor() const;
	bool empty() const;

	//setters
	void setSize(int size);
	void setCapacity(int capacity);
	void setResizeFactor(int resizeFactor);
	
	void push_back(const int& val);
	int pop_back();
	void reserve(int n);

	void resize(int n);
	void resize(int n, const int& val);
	void assign(int val);

	//The big three (d'tor is above)
	vector(const vector& other); //copy c'tor
	vector& operator=(const vector& other); //operator=

	int& operator[](int n) const; //n'th element in the vector

	

private:
	int* _elements;
	int _size;
	int _capacity;
	int _resizeFactor;

};

