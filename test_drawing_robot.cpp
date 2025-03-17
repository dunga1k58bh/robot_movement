#include "drawing_robot.h"
#include <gtest/gtest.h>

// ========== TEST SETTING DIMENSION ==========
TEST(DrawingRobotTest, SetValidDimension) {
    DrawingRobot robot;
    robot.setDimension(5);
    EXPECT_EQ(robot.getDimention(), 5);
}

TEST(DrawingRobotTest, SetZeroDimension) {
    DrawingRobot robot;
    robot.setDimension(0);
    EXPECT_EQ(robot.getDimention(), 0);
}

TEST(DrawingRobotTest, SetNegativeDimension) {
    DrawingRobot robot;
    robot.setDimension(-5);
    EXPECT_EQ(robot.getDimention(), 0); // Assuming negative values default to 0
}

// ========== TEST MOVE TO ==========
TEST(DrawingRobotTest, MoveToValidPosition) {
    DrawingRobot robot;
    robot.setDimension(5);
    robot.moveTo(2, 2);
    EXPECT_EQ(robot.getX(), 2);
    EXPECT_EQ(robot.getY(), 2);
}

TEST(DrawingRobotTest, MoveToOutOfBounds) {
    DrawingRobot robot;
    robot.setDimension(5);

    testing::internal::CaptureStdout();
    robot.moveTo(10, 10); // Invalid move
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Invalid move") != std::string::npos);

    EXPECT_NE(robot.getX(), 10);
    EXPECT_NE(robot.getY(), 10);
}

// ========== TEST LINE TO ==========
TEST(DrawingRobotTest, DrawValidDiagonalLine) {
    DrawingRobot robot;
    robot.setDimension(5);
    robot.moveTo(1, 1);
    robot.lineTo(3, 3);

    std::vector<std::vector<char>> expectedBoard = {
        {'.', '.', '.', '.', '.'},
        {'.', '+', '.', '.', '.'},
        {'.', '.', '+', '.', '.'},
        {'.', '.', '.', '+', '.'},
        {'.', '.', '.', '.', '.'}
    };

    EXPECT_EQ(robot.getBoard(), expectedBoard);
}

TEST(DrawingRobotTest, DrawValidVerticalLine) {
    DrawingRobot robot;
    robot.setDimension(5);
    robot.moveTo(1, 1);
    robot.lineTo(1, 4);

    std::vector<std::vector<char>> expectedBoard = {
        {'.', '.', '.', '.', '.'},
        {'.', '+', '.', '.', '.'},
        {'.', '+', '.', '.', '.'},
        {'.', '+', '.', '.', '.'},
        {'.', '+', '.', '.', '.'}
    };

    EXPECT_EQ(robot.getBoard(), expectedBoard);
}

TEST(DrawingRobotTest, DrawValidHorizontalLine) {
    DrawingRobot robot;
    robot.setDimension(5);
    robot.moveTo(1, 1);
    robot.lineTo(4, 1);

    std::vector<std::vector<char>> expectedBoard = {
        {'.', '.', '.', '.', '.'},
        {'.', '+', '+', '+', '+'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'}
    };

    EXPECT_EQ(robot.getBoard(), expectedBoard);
}

TEST(DrawingRobotTest, LineToOutOfBounds) {
    DrawingRobot robot;
    robot.setDimension(5);

    testing::internal::CaptureStdout();
    robot.lineTo(10, 10); // Invalid move
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Invalid line") != std::string::npos);
}

// ========== TEST EXECUTE COMMANDS ==========
TEST(DrawingRobotTest, ExecuteValidCommands) {
    DrawingRobot robot;
    robot.executeCommands({ "DIMENSION 5", "MOVE_TO 1,1", "LINE_TO 3,3" });

    std::vector<std::vector<char>> expectedBoard = {
        {'.', '.', '.', '.', '.'},
        {'.', '+', '.', '.', '.'},
        {'.', '.', '+', '.', '.'},
        {'.', '.', '.', '+', '.'},
        {'.', '.', '.', '.', '.'}
    };

    EXPECT_EQ(robot.getBoard(), expectedBoard);
}

TEST(DrawingRobotTest, ExecuteInvalidCommands) {
    DrawingRobot robot;

    testing::internal::CaptureStdout();
    robot.executeCommands({ "DIMENSION -1", "MOVE_TO 10,10", "LINE_TO 6,6" });
	robot.drawBoard();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Invalid") != std::string::npos);
}

// ========== TEST DRAW BOARD ==========
TEST(DrawingRobotTest, DrawBoardOutput) {
    DrawingRobot robot;
    robot.setDimension(3);
    robot.moveTo(1, 1);
    robot.lineTo(2, 2);

    testing::internal::CaptureStdout();
    robot.drawBoard();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput =
        "...\n"
        ".+.\n"
        "..+\n";

    EXPECT_EQ(output, expectedOutput);
}

// ========== TEST LARGE INPUT ==========
TEST(DrawingRobotTest, LargeGridPerformance) {
    DrawingRobot robot;
    robot.setDimension(1000);
    robot.moveTo(500, 500);
    robot.lineTo(999, 999);
    EXPECT_EQ(robot.getX(), 999);
    EXPECT_EQ(robot.getY(), 999);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
