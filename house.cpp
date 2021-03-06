#include "stdafx.h"
#include "house.h"
house::house()
{
	this->sizehouse = 36;
	this->f = new flat[this->sizehouse];
	for (size_t i = 0; i < this->sizehouse; i++) this->f[i].setnum(i + 1);
}
house::house(size_t size)
{
	this->sizehouse = size;
	this->f = new flat[this->sizehouse];
	for (size_t i = 0; i < this->sizehouse; i++) this->f[i].setnum(i + 1);
}
house::house(house &&move)
{
	this->f = move.f;
	this->sizehouse = move.sizehouse;
	move.f = nullptr;
}
int inputnumflats(size_t num, size_t max)
{
	do
	{
		system("cls");
		std::cout << "Номер квартиры должен быть в пределах от " << 1 << " до " << max << "." << std::endl;
		std::cout << "Введите номер квартиры: ";
		std::cin >> num;
		std::cin.ignore();
	} while (num < 1 || num > max);
	return num;
}