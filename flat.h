#pragma once
#include "human.h"
class flat
{
	human *h = nullptr;
	size_t sizeflat = 0;
	size_t number = 0;
public:
	flat() = default;
	flat(flat &);
	flat(flat &&);
	flat &operator++(int);
	flat &operator--(int);
	friend std::ostream & operator<<(std::ostream &, flat &);
	void ffindhum();
	void setnum(int a) { this->number = a; }
	int getnum() { return this->number; }
	int getsize() { return this->sizeflat; }
	~flat() { delete[] this->h; }
};