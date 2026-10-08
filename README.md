*This project has been created as part of the 42 curriculum by vpoka.*

# push_swap

Sort a stack of integers with two stacks and a limited set of instructions, using as few moves as possible.

## Table of Contents
- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [Technical choices](#technical-choices)
- [Troubleshooting](#troubleshooting)
- [Status](#status)

## Description

push_swap is an algorithmic project from the 42 curriculum. You start with a stack of integers (`a`) and an empty stack (`b`), plus a fixed set of operations for moving elements between them. The program prints the shortest sequence of these operations that sorts `a` in ascending order, with the smallest number on top, one instruction per line.

The challenge is choosing and tuning a sorting strategy under a strict operation budget: sorting 100 random numbers must take fewer than 700 operations, and 500 random numbers no more than 5500.

Available operations:

| Operation | Effect |
|---|---|
| `sa` / `sb` | Swap the first two elements of stack a / b |
| `ss` | `sa` and `sb` at the same time |
| `pa` / `pb` | Push the top element of b to a / of a to b |
| `ra` / `rb` | Shift stack a / b up by one (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` / `rrb` | Shift stack a / b down by one (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

Features:

- Accepts numbers as separate arguments or as a single space-separated string
- Validates input: integers only, within `int` range, no duplicates
- Prints `Error` to standard error and exits when the input is invalid
- Prints nothing when no arguments are given or the stack is already sorted

## Instructions

### Prerequisites

- A C compiler (`cc`, as used by the Makefile)
- `make`
- No external libraries: the bundled [libft](libft/) is compiled automatically

The project is compiled with the flags `-Wall -Wextra -Werror`. No specific tool versions are required.

### Build

```bash
# Clone the repository
git clone https://github.com/HandsomeCarrot/42-push-swap.git

# Navigate into the project directory
cd 42-push-swap

# Compile libft and the push_swap executable
make
```

Other Makefile targets: `make clean` removes the object files, `make fclean` removes the object files and the executable, `make re` rebuilds everything from scratch.

### Usage

Run the program with a list of integers. The first argument is the top of the stack.

```bash
# Example with individual number arguments
./push_swap 4 67 3 87 23

# Example with a single formatted string
./push_swap "4 67 3 87 23"
```

The program prints the sorting instructions to standard output, one per line (e.g. `pa`, `pb`, `sa`, `ra`, `rra`).

## Resources

### AI usage

AI was used for documentation, commit messages, clarifying concepts, and improving code.

## Technical choices

- **Chunk-based sorting**: elements are pushed from `a` to `b` in ranges (chunks) whose size adapts to the input length ([split.c](split.c)), then merged back into `a` in order ([sort.c](sort.c)).
- **Normalization**: values are mapped to ranks `0..n-1` so the chunk logic only deals with small integers ([normalize.c](normalize.c)).
- **Small inputs**: stacks of 2 to 5 elements are handled with dedicated short sequences instead of the general algorithm ([sort.c](sort.c)).
- **Cheapest rotation**: for each move, the shorter of the forward and reverse rotation is chosen ([rotations.c](rotations.c)).

## Troubleshooting

- **`Error` printed to standard error:** the input is invalid — a non-integer value, a value outside the `int` range (`INT_MIN` to `INT_MAX`), or a duplicate. Fix the arguments and run again.
- **No output displayed:** with no arguments, or when the integers provided are already perfectly sorted, the program prints nothing and exits. This is the expected behaviour.

## Status

Completed - 18.02.2025 (96/100 pts)

