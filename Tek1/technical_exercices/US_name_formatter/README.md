# US Name Formatter

## Description

C program that takes a string as parameter representing a name and formats it according to US naming conventions with specific capitalization and formatting rules.

## Objective

Implement a `USNameFormatter` program that must:
- Take a string parameter representing a full name
- Apply formatting rules to first name and last name
- Handle different first name formats (short, long, with middle initial)
- Format last name with proper capitalization

### Formatting Rules

**First Name:**
- If 2 letters long: print in UPPER CASE
- If contains additional single letter: print normally + single letter in UPPER CASE followed by '.'
- If more than 2 letters long: only first letter in upper case, rest in lower case

**Last Name:**
- First letter of every word in UPPER CASE
- All other letters in lower case

### Input Format

- Name composed of first name followed by last name
- First name: 1 word, possibly with additional single letter
- All input strings are well-formed

## Constraints

- Language: C
- Authorized function: `write` only
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Error messages on error output
