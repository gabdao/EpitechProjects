# SETTING UP

## Description
Dynamic programming algorithm to find the largest possible square on a board while avoiding obstacles. The program can either read a board from a file or generate one based on given parameters.

## Objective
Implement a `setting_up` program that must:
- Find the largest free square area on a grid containing obstacles
- Handle two input modes: file reading and pattern generation
- Use dynamic programming for optimal square detection
- Display the solution by marking the largest square with 'x' characters
- Apply tie-breaking rules when multiple solutions exist

### Key Features
- **File Input Mode**: Read board layout from a specified file
- **Generation Mode**: Create board from size and pattern parameters
- **Square Detection**: Find largest possible square area without obstacles
- **Dynamic Programming**: Efficient algorithm implementation
- **Solution Display**: Mark the optimal square with 'x' characters
- **Tie-Breaking**: Choose highest square, then leftmost when multiple solutions exist

### Algorithm Details
- Uses dynamic programming to efficiently find largest square
- Considers each cell as potential bottom-right corner of a square
- Builds solution incrementally based on previously computed results
- Time complexity: O(n×m) where n and m are board dimensions

## Constraints
- Language: C
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Authorized functions: `open`, `read`, `write`, `close`, `malloc`, `free`, `stat`
- Board must contain at least one line
- All board lines must have equal length (except first line in file mode)

## Input Validation
- File must respect specified format constraints
- Only '.' and 'o' characters allowed on board
- First line must contain only the number of rows
- Each line must be properly terminated with '\n'
