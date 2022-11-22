#include "gameOfLife.h"

gameOfLife::gameOfLife(int row, int column) : grid(row, vector<int>(column, 0)), next (row, vector<int>(column,0))
{
	this->row = row;
	this->column = column;
}

gameOfLife::~gameOfLife()
{

}

int gameOfLife::getCell(int row, int column)
{
	return grid[row][column];
}

void gameOfLife::setCell(int row, int column, int position)
{
	grid[row][column] = position;
}

vector<vector<int>> gameOfLife::getGrid()
{
	return this->grid;
}

void gameOfLife::nextGeneration()
{
	int x = 0; int y = 0; int n = 0; int i = -1; int j = -1;
	do
	{
		x++;

		do
		{
			y++;

			do
			{
				i++;

				do
				{
					if (x + i >= 0 && x + i < row &&y +j < column)
					{
						n += grid[x + i][y + j];
					}
					j++;
				} while (j < 2);

			} while (i < 2);

			n -= grid[x][y];

			if (grid[x][y])
			{
				next[x][y] = (n < 2 || n > 3) ? 0 : 1;
			}
			else
			{
				next[x][y] = (n == 3) ? 1 : 0;
			}

		} while (y < column);

	} while (x < row);
	swap(grid, next);
}

void gameOfLife::reset()
{
	for (auto& row : grid)
		fill(row.begin(), row.end(), 0);

	for (auto& row : next)
		fill(row.begin(), row.end(), 0);
}
