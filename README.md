# push_swap

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [Status](#status)
- [Credits](#credits)
- [License](#license)

## Overview
Push_swap is an algorithmic project developed for the 42 coding school curriculum. The program calculates and displays the smallest possible sequence of operations to sort a given list of integers using two stacks (Stack A and Stack B). By limiting the allowed operations (like pushing, swapping, and rotating elements), the project challenges developers to build highly optimized sorting logic (such as the chunk-based sorting implemented here) to handle complex datasets efficiently.

## Installation
The project is written in C and provides a `Makefile` to automate the compilation process. It relies on a custom C library (`libft`), which is included within the repository.

To download and compile the project, run the following commands in your terminal:

```bash
# Clone the repository
git clone https://github.com/HandsomeCarrot/42-push-swap.git

# Navigate into the project directory
cd 42-push-swap

# Compile the executable and dependencies
make
```

This will compile the source files along with the `libft` library, producing the `push_swap` executable. You can also clean up the object files later using `make clean` or `make fclean`.

## Usage
Run the `push_swap` program by passing a list of integers as arguments. The program will output the sequence of operations required to sort the stack in ascending order.

You can provide the numbers as individual arguments or as a single space-separated string:

```bash
# Example with individual number arguments
./push_swap 4 67 3 87 23

# Example with a single formatted string
./push_swap "4 67 3 87 23"
```

The output will be a sequence of instructions (e.g., `pa`, `pb`, `sa`, `ra`, `rra`) printed to the standard output, with one instruction per line. 

## Troubleshooting
- **`Error` Output:** If the program outputs `Error` to the standard error stream and exits, it means your input is invalid. Check your input to ensure it contains only valid integers, has no duplicates, and includes no values that exceed the standard integer size limits (`INT_MIN` to `INT_MAX`).
- **No Output Displayed:** If you run the program and nothing prints out, the integers provided are already perfectly sorted. 

## Status
Completed - 18.02.2025 (96/100 pts)

## License
No license.
