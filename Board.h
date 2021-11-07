#pragma once
#include "Cell.h"
#include <conio.h>  // Y tho?

const short ROWS = 13;
const short COLS = 26;


class Board
{
	Cell cells[ROWS][COLS];	// CHANGED!
 		
public:
	Board();
	void printBoard();
	short nextCellCont(Direction dic, const unsigned short* _pos);

	void changeFood2Path(Cell cur)
	{
		cur.setMyContent(PATH);
	}

	Cell getCell(short _x, short _y)
	{
		return cells[_y][_x];
	}

};

inline bool isSecretdoor(int i, int j)//secret passage check by coord
{
	return (i == 7 && (j == 0 || j == 25));
}


inline bool IsOnBorder(int i, int j) { return (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1); }
