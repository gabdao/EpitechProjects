# 102architect

## Description

Home planning software for architecture firms implementing geometric transformations using homogeneous coordinates. The program computes point coordinates after applying various 2D transformations for architectural design purposes.

## Objective

Implement a `102architect` program that must:
- Apply geometric transformations to 2D points using homogeneous coordinates
- Support multiple transformation types and their combinations
- Display transformation matrices and final coordinates
- Handle transformations centered at origin O

### Supported Transformations

- **Translation** (`-t i j`): Move along vector (i, j)
- **Scaling** (`-z m n`): Scale by factors m (x-axis) and n (y-axis)
- **Rotation** (`-r d`): Rotate around origin O by d degrees
- **Reflection** (`-s d`): Reflect over axis through O with inclination angle d degrees
- **Combinations**: Apply multiple transformations in sequence

### Parameters

- `x y`: Original point coordinates
- `transfo arg1 [arg2]`: Transformation type and arguments
- Transformations are applied in the order specified

## Constraints

- Language: C (implemented)
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Matrix calculus libraries (like numpy) prohibited
- Must use homogeneous coordinates (3x3 matrices)
