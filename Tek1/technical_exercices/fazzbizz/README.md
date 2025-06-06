# FazzBizz

## Description

C program that takes two numbers as parameters and prints all integers between them (inclusive) according to specific replacement rules based on multiples.

## Objective

Implement a `fazzbizz` program that must:
- Take two numbers as parameters
- Print all integers between them (inclusive)
- Apply replacement rules based on multiples of 9 and 10
- Validate that the second parameter is greater than or equal to the first

### Replacement Rules

- Multiple of 10: print "Fazz"
- Multiple of 9: print "Bizz"
- Multiple of both 9 and 10: print "FazzBizz"
- All other cases: print the number

### Validation Rules

- Second parameter must be greater than or equal to the first
- Both parameters are required

## Constraints

- Language: C
- Authorized functions: `write`, `atoi`, `printf`
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Error messages on error output
