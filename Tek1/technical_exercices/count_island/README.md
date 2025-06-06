# Count Island

## Description

C program implementing an island detection and counting algorithm in a 2D grid. The system analyzes a character array to identify islands formed by connected 'X' characters and numbers them sequentially.

## Objective

Implement a `count_island` function that must:
- Scan a 2D grid containing '.' (water) and 'X' (land)
- Identify islands formed by connected 'X' characters
- Replace each 'X' with its island number (starting from 0)
- Return the total number of islands found

### Connection Rules

Two characters are connected if they are:
- Contiguous on the same line (horizontally)
- In the same column on contiguous lines (vertically)

## Constraints

- Language: C
- Recursive approach required
- Maximum 10 islands per grid
- Line-by-line processing in order of appearance
