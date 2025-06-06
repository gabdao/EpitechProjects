# Count Words

## Description

C program that analyzes a string passed as parameter and displays the number of occurrences of each word on a separate line.

## Objective

Implement a `countwords` program that must:
- Take a string as parameter
- Count occurrences of each unique word
- Display results in order of word appearance
- Handle separators (spaces and tabulations)
- Display only `\n` if no parameter is provided

### Processing Rules

- Words are strings separated by spaces or tabulations
- Display order follows first appearance order in the string
- Output format: `word: occurrence_count`

## Constraints

- Language: C
- Authorized functions: `write`, `malloc`, `free`, `printf`
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Error messages on error output
