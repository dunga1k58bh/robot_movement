cmake_minimum_required(VERSION 3.10)
project(CocCoc_HomeTest)

set(CMAKE_CXX_STANDARD 17)

# Add main executable
add_executable(hometest drawing_robot.cpp CocCoc_HomeTest.cpp)

# =========== GOOGLE TEST SETUP ===========
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(unittests drawing_robot.cpp test_drawing_robot.cpp)
target_link_libraries(unittests gtest_main)


# =========== For custom testcase ===========
# Define the testcases directory
set(TESTCASE_DIR ${CMAKE_SOURCE_DIR}/testcases)

# Ensure the testcases directory exists in the build folder
add_custom_target(copy_testcases ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${TESTCASE_DIR} ${CMAKE_BINARY_DIR}/testcases
    COMMENT "Copying test cases to build directory"
)

set(TESTCASES_OUTPUT_DIR "${CMAKE_BINARY_DIR}/testcases_output")
file(MAKE_DIRECTORY ${TESTCASES_OUTPUT_DIR})

add_compile_definitions(TESTCASES_PATH="${TESTCASE_DIR}")
add_compile_definitions(TESTCASES_OUTPUT_PATH="${TESTCASES_OUTPUT_DIR}")