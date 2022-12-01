#include "Grid.hpp"

/*******************************************************************************
 * Programmers: Drew Evensen		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

// Constructor
Grid::Grid(int x, int y)
{
	// Ensure x and y are valid values
	if (x < 1)
		x = 1;
	if (y < 1)
		y = 1;

	// Source: https://www.geeksforgeeks.org/create-dynamic-2d-array-inside-class-c/

	// Instantiate each collumn in the grid
	cells = new Cell*[y];

	// Instantiate each row in the grid
	for (int i = 0; i < x; i++)
		cells[i] = new Dead[x];

	// Instantiate dividers
	dividers = new sf::RectangleShape[x * y];
	for (int i = 0; i < x * y; i++)
	{
		dividers[i] = sf::RectangleShape(sf::Vector2f(500, 1));

		dividers[i].move(0, 240);
	}
}

// Destructor
Grid::~Grid()
{

}

// Print the grid to the given window
void Grid::printGrid(sf::RenderWindow& window)
{
	window.draw(dividers[0]);
}