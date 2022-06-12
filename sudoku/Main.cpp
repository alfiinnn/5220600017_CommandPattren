#include <iostream>
#include "GameManager.h"

int main() {
	Board board;
	Player player;
	GameManager game(&board, &player);

	int menu = 10;
	while (menu != 0)
	{
		std::cout << "\nMain Menu" << std::endl
			<< "1. Play" << std::endl
			<< "0. Exit" << std::endl
			<< "Input []: "; std::cin >> menu;

		switch (menu)
		{
		case 1:
			game.set_name();
			game.Play();
			break;
		case 0:
			break;
		default:;
		}
	}
}