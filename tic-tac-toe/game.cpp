#include "game.h"
#include <iostream>

void playGame(Board &board)
{
	bool gameOn = true;
	std::cout << "\nLet's play\n";

	int movesPlayed = 0;
	std::string player;

	while(gameOn)
	{
		// Draw board
		board.drawBoard();
		// Let player know who's turn is next
		if (movesPlayed % 2 == 0)
		{
			std::cout << "X's turn...\n";
			player = "X ";
		} else
		{
			std::cout << "O's turn...\n";
			player = "O ";
		}
		movesPlayed += 1;
		std::string playerMove;
		std::cout << "Enter position (Example A2): ";
		std::cin >> playerMove;
		std::cout << "Player " << player << "entered " << playerMove << std::endl;
		board.updateBoard(playerMove, player);
	}
}
