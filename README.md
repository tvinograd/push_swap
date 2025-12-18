_This project has been created as part of the 42 curriculum by tvinogra._

# push_swap

## Description

`push_swap` takes a list of integers and outputs s sequence of operations to sort them in ascending order using only two stacks (A and B).

### Goal
Sort efficiently within these benchmarks:
- 100 numbers: <= 1100 operations (80% grade)
- 500 numbers: <= 8500 operations (80% grade)

### Algorithm
Radix sort (binary) with special cases for 2-3 elements
1. Parse and validate input
2. Normalize values to indices (0 to n-1)
3. Process each bit position:
   - Push elements with `bit = 0` to stack B
   - Keep elements with `bit = 1` in stack A
   - Push all back from B to A

**Why radix?** Simple, predictable, allows for bit manipulation learning.

### Project structure
```
push_swap/
├── libft/           # 42's C library
├── ft_atoi_ps.c     # "atoi" adjusted for push_swap
├── index.c          # Indexing
├── main.c           # Entry point
├── Makefile         # Build rules
├── op_push.c        # Push operations
├── op_rev_rot.c     # Reverse rotate operations
├── op_rot.c         # Rotate operations
├── op_swap.c        # Swap operations
├── parse.c          # Parsing & validation
├── push_swap.h      # Header
├── radix.c          # Radix sorting
├── sort.c           # Sorting algorithms
└── stack.c          # Stack management
```

### Limitations

- No optimization for 4-5 elements (uses radix)
- Higher operation count than optimal algorithms
- Doesn't fully utilize combined operations (rr, rrr, ss)

## Instructions

### Compilation
```bash
make        # Compile
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Recompile

cc push_swap.a main.c -o push_swap
```

### Usage
```bash
./push_swap [integers]

# Examples:
./push_swap 3 2 1
./push_swap "3 2 1"
./push_swap "3 2" 1
```

**Errors:** Prints `Error\n` for duplicates, non-integers, overflow, or invalid input.

**Operations:**
- `sa`: Swap first 2 elements of stack A
- `sb`: Swap first 2 elements of stack B
- `ss`: `sa` and `sb` at the same time
- `pa`: Push top element from B to A
- `pb`: Push top element from A to B
- `ra`: Rotate A up (first element becomes last)
- `rb`: Rotate B up
- `rr`: `ra` and `rb` at the same time
- `rra`: Reverse rotate A (last element becomes first)
- `rrb`: Reverse rotate B
- `rrr`: `rra` and `rrb` at the same time

### Testing
```bash
# Count operations
ARG="[integers]"; ./push_swap $ARG | wc -l

# Verify with checker
ARG="[integers]"; ./push_swap $ARG | ./checker_OS $ARG
```

## Resources

- [42 norminette](https://github.com/42School/norminette)
- [Bitwise Operators in C - GeekforGeeks](https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/)
- [Push_swap Subject](https://projects.intra.42.fr/)
- [Radix Sort - GeekforGeeks](https://www.geeksforgeeks.org/dsa/radix-sort)
- [Radix Sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Radix Sort Algorithm Introduction in 5 Minutes - CS Dojo](https://www.youtube.com/watch?v=XiuSW_mEn7g)
- [Sorting Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Sorting Algorithms Explained Visually - Beyond Fireship](https://www.youtube.com/watch?v=RfXt_qHDEPw)

AI (Claude by Anthropic) was consulted for comparing sorting algorithms (radix, turk, butterfly, k-sort) to choose the best approach given time constraints and learning goals (I was particulary interested in bit manipulation); providing ocassional explanations. All code was written independently based on algorithm understanding and discussion with peers.
