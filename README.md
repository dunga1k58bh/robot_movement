# Robot Movement

Implement a robot that moves and draws on an N × N square grid by executing a 
series of commands

## Build Instructions

### Prerequisites
- CMake (version 3.10+ recommended)
- A C++ compiler (e.g., g++, clang++, MSVC)
- (Optional) Ninja or Make for faster builds


1. Clone the repository
```bash
git clone https://github.com/dunga1k58bh/coccoc_hometest.git
cd <your-repo-folder>
```

2. Create a build directory
```bash
mkdir out
cd out
```

3. Run Cmake

For Debug mode
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

For Release mode:
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
```

4. Build the project
```bash
cmake --build .
```

## Running instructions

1. Run unit tests
```bash
cd out/Debug
.\unittests.exe
```

2. Run the executable

- Running with defaut testcase
```bash
cd out/Debug
.\hometest.exe
```

- Running with custom testcase (console log)
```bash
.\hometest.exe <testname>

# Example
.\hometest.exe test1.txt
```

- Running and Writing Output to File Txt
```bash
.\hometest.exe <testname> --totxt

# Example
.\hometest.exe test1.txt --totxt
```
- By default, the output is saved to testcases_output/my_testcase.txt. To specify a custom output file:
```bash
.\hometest.exe <testname> --totxt <outputname>

# Example
.\hometest.exe test1.txt --totxt my_output.txt
```

- Create testcases
```bash
.\createtestcase.exe <dimentions> <num__commands> <outputname>

# Example
.\createtestcase.exe 1000 1000 test20.txt
```

- Full sample
```bash
.\createtestcase.exe 1000 1000 test20.txt
.\hometest.exe test20.txt --totxt
```
The output will show in Binary out/testcases and out/testcases_output folder

## Project Logic and Approach
### Code Structure
- Main Code: The robot movement and drawing logic are implemented in the core project files.
	- drawing_robot.h: Contains the class definition for the DrawingRobot, which represents the robot's movement and drawing capabilities. 
	- drawing_robot.cpp: Contains the main robot logic, including parsing commands and moving across the grid.
	- CocCoc_HomeTest.cpp: Contains the main function that reads input commands, creates a DrawingRobot instance, and executes the commands.
	- The robot reads commands (such as DIMENTION, MOVE_TO, LINE_TO) and moves across the grid.
	- The grid is an N x N matrix where the robot can move and draw based on the provided commands.
- Unit Tests: 
	- Unit tests are provided to verify each function in isolation, ensuring the correctness of logic (e.g., verifying the robot moves correctly and handles boundary conditions).
	- Using external library [Google Test](https://github.com/google/googletest) for unit tests.
- Testcase generation: A separate executable is provided to generate testcases with random commands and dimensions. This helps test the robot's performance with different input sizes and scenarios.

### Approach
- Grid Initialization: A grid of size N x N is created, where the robot begins in the top-left corner (0,0).
- Command Parsing: Each command is parsed and executed sequentially.
- Movement: The robot moves based on the direction provided by each command. It checks if the move is within the grid's boundaries.
- Drawing: When a `LINE_TO` command is received, the robot draw a line from current to target position on the grid using [Bresenham's Line Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm).
- Boundary Conditions: The robot does not move outside the grid. If a move would cause it to go out of bounds, it does not move.
 -Output: After executing all commands, the robot's path and the final grid state are outputted. If the --totxt option is provided, the result is written to a file.

This structure should now give clear, complete, and practical guidance for building and running the project, as well as a brief explanation of the underlying logic.

### Complexity Analysis
- Time Complexity: The time complexity of the robot movement and drawing logic is O(K * N + N * N), where K is number of command & N is the grid size.
	- Parsing commands: O(K) to parse K commands.
	- Drawing lines: O(N) to draw lines using Bresenham's algorithm.
	- Drawing board: O(N * N) to draw the final board state.
	- When N big, it will take more time to draw the board, we draw it to a new file to reduce time
	- Space complexity: The space complexity is O(N * N) to store the grid and O(1) for the robot's position.
- Space Complexity: The space complexity is O(N * N) to store the grid and O(1) for the robot's position and direction.