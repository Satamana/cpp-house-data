#pragma once
#include "flat.h"
class house
{
	flat *f = nullptr;
	size_t sizehouse = 0;
public:
	house();
	house(size_t);
	house(house &&);
	void house::haddhum(size_t n) { this->f[n - 1]++; }
	void house::hshowflat(size_t n) { std::cout << this->f[n - 1]; }
	void house::hdelhum(size_t n) { this->f[n - 1]--; }
	void house::hfindhum(size_t n) { this->f[n - 1].ffindhum(); }
	int getsize() { return this->sizehouse; }
	~house() { delete[] this->f; }
};
int inputnumflats(size_t, size_t);