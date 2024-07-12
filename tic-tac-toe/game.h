#ifndef GAMEH
#define GAMEH
#include <iostream>
#include <vector>

class Board
{
	std::string board[4][4] = {
		{"  ", "A ", "B ", "C "},
		{"1 ", "# ", "# ", "# "},
		{"2 ", "# ", "# ", "# "},
		{"3 ", "# ", "# ", "# "},
	};

	public:
		void drawBoard()
		{
			for(int row = 0; row < 4; row++)
			{
				for(int col = 0; col < 4; col++)
				{
					std::cout << board[row][col];
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		void updateBoard(std::string move, std::string player)
		{
			char col = std::toupper(move[0]);
			char row = move[1];
			int newCol;
			int newRow;

			switch(col)
			{
				case 'A':
					newCol = 1;
					break;
				case 'B':
					newCol = 2;
					break;
				case 'C':
					newCol = 3;
					break;
			}

			switch (row)
			{
				case '1':
					newRow = 1;
				case '2':
					newRow = 2;
				case '3':
					newRow = 3;
			}

			std::vector<std::string> offlimits = {"  ", "A ", "B ", "C ", "1 ", "2 ", "3 ", "X ", "O "};
			// Check if location is valid and available
			bool isValid = true;
			while (isValid)
			{
				for(std::string tile : offlimits)
				{
					if(tile == board[newRow][newCol])
					{
						isValid = false;
						break;
					}
				}
				break;
			}

			if (isValid)
			{
				board[newRow][newCol] = player;
			} else {
				std::cout << "You can not make a move there.\n";
			}

		}
		// Look for winner
		void checkBoard(std::string player)
		{
			for(int row = 1; row < 4; row++)
			{
				for(int col = 1; col < 4; col++)
				{
					bool isValid = true;
					while(isValid)
					{
						// Check North
						for(int i = 1; i < 4; i++)
						{
							if(board[row][col + i] != player)
							{
								break;
							}
						}
						// Check South
						// Check East
						// Check West
						// Check North East
						// Check North West
						// Check South East
						// Check South West
					}
				}
			}
		}
};

void playGame(Board &board);
bool validTile(std::string tile);

#endif
