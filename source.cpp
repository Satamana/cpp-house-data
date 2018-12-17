#include "stdafx.h"
#include "house.h"
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int curnum = 0;
	int numofflats;
	char ch;
	do
	{
		system("cls");
		std::cout << "Какого типа ваш дом:" << std::endl;
		std::cout << "1 - Девятиэтажный панельный дом с 36 квартирами." << std::endl;
		std::cout << "2 - Произвольный дом, к-во квартир которого вы укажете." << std::endl;
		ch = _getch();
		if (ch == 49) numofflats = 36;
		else if (ch == 50)
		{

			std::cout << "Введите к-во квартир: ";
			std::cin >> numofflats;
			std::cin.ignore();
		}
	} while (ch != 49 && ch != 50);
	house h(numofflats);
	do
	{
		system("cls");
		std::cout << "Меню:" << std::endl;
		std::cout << "1 - Заселение жильца в квартиру." << std::endl;
		std::cout << "2 - Вывод списка жильцов квартиры." << std::endl;
		std::cout << "3 - Выселение жильца из квартиры." << std::endl;
		std::cout << "4 - Поиск жителя в квартире." << std::endl;
		std::cout << "esc Выход" << std::endl;
		ch = _getch();
		switch (ch)
		{
		case '1': h.haddhum(inputnumflats(curnum, numofflats)); break;
		case '2': h.hshowflat(inputnumflats(curnum, numofflats)); break;
		case '3': h.hdelhum(inputnumflats(curnum, numofflats)); break;
		case '4': h.hfindhum(inputnumflats(curnum, numofflats)); break;
		}
	} while (ch != 27);
}