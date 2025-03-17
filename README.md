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
git clone <your-repo-url>
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
./unittests.exe
```

2. Run the executable

Running with defaut testcase
```bash
cd out/Debug
./hometest.exe
```

Running with custom testcase
```bash
./hometest.exe <testname>

# Example
./hometest.exe test1.txt
```

Running and Writing Output to File Txt
```bash
./hometest.exe <testname> --totxt

# Example
./hometest.exe test1.txt --totxt
```
By default, the output is saved to testcases_output/my_testcase.txt. To specify a custom output file:
```bash
./hometest.exe <testname> --totxt <outputname>
# Example
./hometest.exe test1.txt --totxt my_output.txt
```