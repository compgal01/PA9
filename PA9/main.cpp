/*******************************************************************************
 * Programmers: Drew Evensen		                                           *
 * Class: CptS 122				                                               *
 * Programming Assignment: 9	                                               *
 * Date: 12/07/22                                                              *
 *                                                                             *
 * Description:																   *
 *******************************************************************************/

#include <SFML/Graphics.hpp>// External Library
#include <iostream>
#include <random>
#include <Windows.h>
#include <time.h>

int main(int argc, char argv[])
{
#pragma region Test Code
	int test[30];

	srand(time(NULL));

	for (int i = 0; i < 30; i++)
		test[i] = rand() % 500 + 1;

	std::cout << "Test Array Initialized. Starting Config:" << std::endl;

	for (int i = 0; i < 30; i++)
		std::cout << test[i] << ", ";
#pragma endregion Code used in initial file setup to ensure RenderWindow is working properly

	// Iterator for bubble sort
	int b = 0, bMin = 0;

	// Array of rectangle objects to print to the screen
	sf::RectangleShape items[30];

	// Create new test window (500 pixels by 1200 pixels)      (Title of Window)
	sf::RenderWindow testWindow(sf::VideoMode(1200, 500), "Bubble Sort Algorithm Example");

	// Run while the window is open
	while (testWindow.isOpen())
	{
		// Catches an event in the window
		sf::Event event;

		// Close the window upon clicking the X
		while (testWindow.pollEvent(event))
			if (event.type == sf::Event::Closed())
				testWindow.close();

		// Iterate a step through the sorting algorithm
		if (b < 30)
		{
			bMin = b;
			for (int i = b; i < 30; i++)
				if (test[i] < test[bMin])
					bMin = i;

			int temp = test[b];
			test[b] = test[bMin];
			test[bMin] = temp;

			b++;
		}

		// Create each rectangle item
		for (int i = 0; i < 30; i++)
		{
			items[i] = sf::RectangleShape(sf::Vector2f(40, test[i]));
			items[i].setFillColor(sf::Color::White);
			items[i].setOrigin(0, -500 + test[i]);

			// Mark each changed rectangle red
			if (b == 30)
				items[i].setFillColor(sf::Color::Green);

			// Mark each rectangle green when sorted
			else if (bMin == i || b == i)
				items[i].setFillColor(sf::Color::Red);
		}

		// Clear the window
		testWindow.clear();

		// Draw the items to the screen
		for (int i = 0; i < 30; i++)
		{
			// Shift each rectangle to the correct position before drawing
			items[i].move(i * 40, 0);
			testWindow.draw(items[i]);
		}

		// Draw the window
		testWindow.display();

		Sleep(100);
	}
}