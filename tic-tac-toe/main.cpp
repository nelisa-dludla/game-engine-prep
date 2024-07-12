#include "game.h"
#include <iostream>

int main()
{
	std::cout << "===== Welcome to Tic Tac Toe! (X vs. O) =====\n\n";

	Board board;

	bool gameStart = true;

	while(gameStart)
	{
		char response;
		std::cout << "Start Game? (y/n): ";
		std::cin >> response;

		if (response == 'y' || response == 'Y')
		{
			playGame(board);
		} else if (response == 'n' || response == 'N')
		{
			gameStart = false;
			break;
		} else
		{
			std::cout << "Invalid input.\n";
			std::cout << "(y) yes\n";
			std::cout << "(n) no\n";
		}
	}

	std::cout << "Closing Game...\n";

	return 0;
}
