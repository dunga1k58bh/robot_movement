#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

const std::string TestcasesPath = TESTCASES_PATH "/";

void generateTestCase(int dimension, int numCommands, const std::string& filename) {

	std::string filePath = TestcasesPath + filename;
    std::ofstream file(filePath);

    // Check if file is open
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Write DIMENSION
    file << "DIMENSION " << dimension << std::endl;

    // Generate initial MOVE_TO command
    int x = rand() % dimension;
    int y = rand() % dimension;
    file << "MOVE_TO " << x << "," << y << std::endl;

    // Generate random LINE_TO commands
    for (int i = 0; i < numCommands; ++i) {
		int command = rand() % 2;
        x = rand() % dimension;
        y = rand() % dimension;
		if (command == 0) {
			file << "MOVE_TO ";
		}
		else {
			file << "LINE_TO ";
		}
        
        file << x << "," << y << std::endl;
    }

    file.close();
    std::cout << "Test case generated in file: " << filePath << std::endl;
}

int main(int argc, char* argv[]) {
    // Ensure the user has provided the necessary arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <dimension> <num_commands> <output_filename>" << std::endl;
        return 1;
    }

    // Parse the arguments
    int dimension = std::stoi(argv[1]);  // Convert the first argument to integer (dimension)
    int numCommands = std::stoi(argv[2]); // Convert the second argument to integer (num_commands)
    std::string filename = argv[3];      // The third argument is the output filename

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate the test case and write it to the specified file
    generateTestCase(dimension, numCommands, filename);

    return 0;
}
