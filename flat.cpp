#include "stdafx.h"
#include "flat.h"
flat::flat(flat &copy)
{
	this->h = new human[copy.getsize()];
	for (size_t i = 0; i < copy.getsize(); i++) this->h[i] = copy.h[i];
}
flat::flat(flat &&move)
{
	this->h = move.h;
	this->sizeflat = move.sizeflat;
	this->number = move.number;
	move.h = nullptr;
}
flat& flat::operator++(int)
{
	system("cls");
	std::cout << "Введите ФИО: ";
	char *str;
	get(str);
	for (size_t i = 0; i < this->sizeflat; i++)
	{
		if (_stricmp(this->h[i].gethum(), str) == 0)
		{
			delete[] str;
			str = nullptr;
		}
	}
	if (str)
	{
		human *tmp = new human[this->sizeflat + 1];
		for (size_t i = 0; i < this->sizeflat; i++) tmp[i] = this->h[i];
		tmp[this->sizeflat++].sethuman(str);
		delete[] this->h;
		this->h = tmp;
		std::cout << "Операция успешно выполнена." << std::endl;
	}
	else std::cout << "Такой житель уже есть." << std::endl;
	Sleep(1000);
	return *this;
}
flat& flat::operator--(int)
{
	system("cls");
	if (this->sizeflat)
	{
		std::cout << "Введите ФИО искомого: ";
		char *str;
		get(str);
		int j = 0;
		for (size_t i = 0; i < this->sizeflat; i++)
		{
			if (_stricmp(this->h[i].gethum(), str) == 0) j++;
		}
		if (j)
		{
			human *tmp = new human[this->sizeflat - 1];
			j = 0;
			for (size_t i = 0; i < this->sizeflat; i++)
			{
				if (_stricmp(this->h[i].gethum(), str) != 0)
				{
					tmp[j]= h[i];
					j++;
				}
			}
			delete[] str;
			delete[] this->h;
			this->h = tmp;
			this->sizeflat--;
			std::cout << "Операция успешно выполнена." << std::endl;
		}
		else std::cout << "Такого жильца в квартире нет." << std::endl;
	}
	else std::cout << "В квартире нет жильцов." << std::endl;
	Sleep(1000);
	return *this;
}
void flat::ffindhum()
{
	system("cls");
	if (this->sizeflat)
	{
		std::cout << "Введите ФИО искомого: ";
		char *str;
		get(str);
		int f = 0;
		for (size_t i = 0; i < this->sizeflat; i++)
		{
			if (_stricmp(this->h[i].gethum(), str) == 0)
			{
				std::cout << "ФИО: " << this->h[i].gethum() << std::endl;
				f = 1;
			}
		}
		if (f) system("pause");
		else
		{
			std::cout << "Такой житель не найден." << std::endl;
			Sleep(1000);
		}
	}
	else
	{
		std::cout << "В квартире нет жильцов." << std::endl;
		Sleep(1000);
	}
}
std::ostream & operator<<(std::ostream &os, flat &ob)
{
	system("cls");
	if (ob.sizeflat)
	{
		int n = 1;
		std::cout << "Список жильцов квартиры №" << ob.number << ":" << std::endl;
		for (size_t i = 0; i < ob.sizeflat; i++) std::cout << n++ << ". " << ob.h[i].gethum() << std::endl;
		system("pause");
		return os;
	}
	std::cout << "В квартире нет жильцов." << std::endl;
	Sleep(1000);
	return os;
}