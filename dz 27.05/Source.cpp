#include <iostream>
#include <time.h>
#include "Header.h"





void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	void(*pGame)();
	pGame = Game;
	void(*pProgram)();
	pProgram = Program;
	bool c = 0;
	do 
	{
		short choice = 0;
		c = 0;
		std::cout << "Для запуска игры введите 1\nДля запуска программы введите 2\nДля выхода введите 0\n";
		std::cin >> choice;
		std::cout << "\n";
		if (choice < 0)choice = 0;
		if (choice > 2)choice = 2;

		if (choice == 1) { pGame(); c = 1; }
		if (choice == 2) { pProgram(); c = 1; }
	} while (c);
}