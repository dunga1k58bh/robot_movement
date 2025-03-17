#include "drawing_robot.h"

void DrawingRobot::setDimension(int n) {
	if (n < 0) {
		std::cout << "Invalid dimension" << std::endl;
		return;
	}
	this->n = n;
	board.assign(n, std::vector<char>(n, '.'));
}

void DrawingRobot::moveTo(int x, int y) {
	if (!checkInput(x, y)) {
		std::cout << "Invalid move" << x << ", " << y << std::endl;
		return;
	}
	this->x = x;
	this->y = y;
}

void DrawingRobot::lineTo(int x, int y) {
	if (!checkInput(x, y)) {
		std::cout << "Invalid line to" << x << ", " << y << std::endl;
		return;
	}

	drawLine(this->x, this->y, x, y);

	this->x = x;
	this->y = y;
}


void DrawingRobot::drawLine(int x0, int y0, int x1, int y1) {
	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;

	while (true) {
		board[y0][x0] = '+';
		int error2 = 2 * error;
		if (error2 >= dy) {
			if (x0 == x1) break;
			error += dy;
			x0 += sx;
		}

		if (error2 <= dx) {
			if (y0 == y1) break;
			error += dx;
			y0 += sy;
		}
	}
}


void DrawingRobot::executeCommands(std::vector<std::string> commands) {
	for (const auto& command : commands) {
		std::istringstream iss(command);
		std::string cmd;
		iss >> cmd;
		if (cmd == "DIMENSION") {
			int n;
			iss >> n;

			setDimension(n);
		}
		else if (cmd == "MOVE_TO") {
			int x, y;
			char comma;
			iss >> x >> comma >> y;
			moveTo(x, y);
		}
		else if (cmd == "LINE_TO") {
			int x, y;
			char comma;
			iss >> x >> comma >> y;
			lineTo(x, y);
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}
}

void DrawingRobot::drawBoard() {
	for (const auto& row : board) {
		for (const auto& cell : row) {
			std::cout << cell;
		}
		std::cout << std::endl;
	}
}


void DrawingRobot::drawToTxt(const std::string& filename) {
	std::ofstream file(filename);
	if (!file) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}
	for (const auto& row : board) {
		for (char cell : row) {
			file << cell;
		}
		file << '\n';
	}
	file.close();
}


int DrawingRobot::getDimention() const {
	return n;
}

int DrawingRobot::getX() const {
	return x;
}

int DrawingRobot::getY() const {
	return y;
}

const std::vector<std::vector<char>>& DrawingRobot::getBoard() const {
	return board;
}


inline bool DrawingRobot::checkInput(int x, int y) const {
	return x >= 0 && x < n && y >= 0 && y < n;
}