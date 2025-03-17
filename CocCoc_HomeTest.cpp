#include "drawing_robot.h"
#include <iostream>
#include <fstream>
#include <filesystem>

// Default paths
const std::string TestcasesPath = TESTCASES_PATH "/";
const std::string OutputPath = TESTCASES_OUTPUT_PATH "/";
const std::string DefaultCommandsFile = "commands.txt";

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Parse arguments
    std::string inputFile = TestcasesPath + DefaultCommandsFile;
    bool writeToFile = false;
    std::string outputFile;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--totxt") {
            writeToFile = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') { // If a filename is provided
                outputFile = OutputPath + argv[i + 1];
                ++i; // Skip next argument since it's the filename
            }
        }
        else {
            inputFile = TestcasesPath + arg;
        }
    }

    // If output file is not specified, use the input file name
    if (writeToFile && outputFile.empty()) {
        outputFile = OutputPath + std::filesystem::path(inputFile).filename().string();
    }

    // Read input file
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cout << "Cannot open file " << inputFile << std::endl;
        return 1;
    }

    DrawingRobot robot;
    std::string line;
    std::vector<std::string> commands;
    while (getline(file, line)) {
        commands.emplace_back(std::move(line));
    }

    robot.executeCommands(commands);

    if (writeToFile) {
        robot.drawToTxt(outputFile);
        std::cout << "Output saved to " << outputFile << std::endl;
    }
    else {
        robot.drawBoard();
    }

    return 0;
}