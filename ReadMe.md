# Matrix Multiplication Task

## Overview
This project implements matrix multiplication, allowing users to multiply two matrices, read matrix data from a file, and handle errors related to the input matrix data, such as alphabetic characters and missing data. The program reads matrices from a file, performs matrix multiplication, and prints the result.

The matrices are read from a file, and the program checks for errors like invalid input or missing values. The result of the multiplication is output as a matrix.

## Features
- Matrix multiplication implementation.
- Error handling for invalid characters in matrix data.
- Flexible matrix size (rows and columns specified in the input file).
- Support for multiple test cases.

## Requirements
- **C Compiler** (e.g., GCC)
- **C Standard Library** (`stdio.h`, `stdlib.h`, `ctype.h`, `limits.h`)

## Setup Instructions

### 1. Clone or Download the Repository
Clone the repository or download the source files to your local machine.
git clone https://github.com/yourusername/mat-multi-mcw.git

### 2. Compile the C Program
To compile the program, open a terminal, navigate to the project directory, and run the following command:
gcc driver.c -o driver -O2
This command will compile the C source code in driver.c and generate an executable named driver.

### 3. Running the Program
After successfully compiling the program, run the tests using the provided run_tests.sh script. This script will read input matrices from files, perform the multiplication, and save the results to a CSV file.
./run_tests.sh

The script will:

Compile the driver program.
Iterate through each test case (located in the Unit_test/ directory).
Perform matrix multiplication with different loop orders (ijk, ikj, jik, etc.).
Output the time taken for each test case and loop order in Results/time_report.csv.

### 4. Input File Format
The input matrix data should be provided in files located in the Unit_test/ directory. Each file should contain the following format:

The first line contains two integers: the number of rows and the number of columns in the matrix.
The remaining lines contain the matrix data, with integers separated by spaces.

example:
3 3
1 2 3
4 5 6
7 8 9

### 5. Output
The program generates a CSV file Results/time_report.csv that contains the following columns:

UnitTest: The name of the unit test.
LoopOrder: The loop order used for matrix multiplication.
TimeTaken(ms): The time taken for the multiplication in milliseconds.
Status: Whether the test passed or failed.

### 6. Handling Errors
If the input file contains non-numeric characters, the program will print an error message indicating the position of the invalid data and set the corresponding matrix element to INT_MAX (a sentinel value).
If the end of the file is reached unexpectedly or there is missing data, the program will display an error message and set the remaining matrix values to INT_MAX.


### 7. Result generation containing the time report for all the loop variations
The program will generate Results/time_report.csv, which will look something like this:

UnitTest,LoopOrder,TimeTaken(ms),Status
unit_1,ijk,5.25,Success
unit_1,ikj,4.98,Success
unit_2,jik,6.42,Failure


# DIRECTORY STRUCTURE:

matrix-multi_mcw_1/
├── driver.c               # Main driver program
├── matmul.c               # Matrix multiplication logic
├── unit_test/             # Folder containing test input files
│   ├── a.text             # Test matrix A
│   ├── b.text             # Test matrix B
│   ├── c.text             # Additional test file
├── run_tests.sh           # Script to run automated tests
├── unit_test_generation   # Script to generate unit test input files
├── README.md              # Project documentation



















