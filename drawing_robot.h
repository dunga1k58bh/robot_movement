#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class DrawingRobot {
public:
	explicit DrawingRobot() : n(0), x(0), y(0) {}
	void setDimension(int n);

	// Move the cursor to (x, y) on the board
	void moveTo(int x, int y);

	// Draw a line from the current position of the cursor to (x, y) on the board
	void lineTo(int x, int y);

	/**
	 * @brief Draws a line on the grid using Bresenham's Line Algorithm.
	 *
	 * This implementation follows the algorithm described on Wikipedia:
	 * https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
	 *
	 * The algorithm efficiently calculates which grid points should be marked
	 * to approximate a straight line between (x0, y0) and (x1, y1) without using
	 * floating-point arithmetic.
	 *
	 * @param x0 Starting x-coordinate
	 * @param y0 Starting y-coordinate
	 * @param x1 Ending x-coordinate
	 * @param y1 Ending y-coordinate
	 */
	void drawLine(int x0, int y0, int x1, int y1);
	
	// Execute a list of commands
	void executeCommands(const std::vector<std::string> commands);

	// Draw the board
	void drawBoard();

	// Draw to the file txt
	void drawToTxt(const std::string& filename);

	//Getter
	int getDimention() const;
	int getX() const;
	int getY() const;
	const std::vector<std::vector<char>>& getBoard() const;

private:
	int n;
	std::vector<std::vector<char>> board;
	int x, y;

	// Check if the input (x, y) is valid
	inline bool checkInput(int x, int y) const;
};