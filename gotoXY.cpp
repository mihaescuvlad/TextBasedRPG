#include "gotoXY.h"

void gotoXY(short row, short col)			// Moves the cursor to the row and column
{
	COORD coord;							// Structure for setting coordinates
	coord.X = row;
	coord.Y = col;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, coord);
}