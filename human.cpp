#include "stdafx.h"
#include "human.h"
human::human(char *str)
{
	this->fio = new char[strlen(str) + 1];
	strcpy_s(this->fio, strlen(str) + 1, str);
}
human::human(const human &copy)
{
	this->fio = new char[strlen(copy.fio) + 1];
	strcpy_s(this->fio, strlen(copy.fio) + 1, copy.fio);
}
human::human(human &&move)
{
	this->fio = move.fio;
	move.fio = nullptr;
}
human& human::operator=(const human &ob)
{
	if (this->fio) delete[] this->fio;
	this->fio = new char[strlen(ob.fio) + 1];
	strcpy_s(this->fio, strlen(ob.fio) + 1, ob.fio);
	return *this;
}
void human::sethuman(char *str)
{
	if (this->fio) delete[] this->fio;
	this->fio = new char[strlen(str) + 1];
	strcpy_s(this->fio, strlen(str) + 1, str);
}
void get(char *&str)
{
	char ch;
	int n = 0;
	char *tmp = nullptr;
	while ((ch = getchar()) != '\n')
	{
		tmp = (char*)realloc(tmp, n + 1);
		tmp[n++] = ch;
	}
	tmp = (char*)realloc(tmp, n + 1);
	tmp[n] = 0;
	str = nullptr;
	str = new char[strlen(tmp) + 1];
	strcpy_s(str, strlen(tmp) + 1, tmp);
	free(tmp);
}