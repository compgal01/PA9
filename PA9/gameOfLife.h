#pragma once

/*******************************************************************************
 * Programmers: Kaitlyn Cornish		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class gameOfLife
{
public:
//constructor
	gameOfLife(int row, int column);
//deconstructor
	~gameOfLife();

//setters and getters
	int getCell(int row, int column);
	void setCell(int row, int column, int position);

	vector<vector<int>> getGrid();

//updates and resets grid
	void nextGeneration();
	void reset();


private:
	int row;
	int column;
	vector<vector<int>> grid;
	vector<vector<int>> next;
};