# MY_PRINTF

## Description
Custom implementation of the printf function from the C library according to the C99 standard. The project involves creating a static library containing a fully functional printf replacement with support for all standard format specifiers and flags.

## Objective
Implement a `my_printf` function that must:
- Replicate printf functionality according to C99 standard
- Handle all printf format specifiers and flags
- Process variable arguments using stdarg macros
- Generate a static library (libmy.a) containing the implementation
- Support all standard printf features without using libc functions

### Key Features
- **Format Specifiers**: Support for all standard printf format specifiers
- **Flag Processing**: Handle all printf flags (-, +, space, #, 0)
- **Width and Precision**: Support field width and precision modifiers
- **Variable Arguments**: Proper handling using va_start, va_end, va_arg
- **Static Library**: Packaged as libmy.a for easy integration
- **Standards Compliance**: Follows C99 printf specification

### Format Specifiers Support
- `%c`: Character
- `%s`: String
- `%d`, `%i`: Signed decimal integer
- `%o`: Unsigned octal
- `%x`, `%X`: Unsigned hexadecimal (lowercase/uppercase)
- `%u`: Unsigned decimal integer
- `%f`, `%F`: Floating point
- `%e`, `%E`: Scientific notation (lowercase/uppercase)
- `%g`, `%G`: Shortest representation
- `%p`: Pointer address
- `%%`: Literal percent character

## Constraints
- Language: C
- Output: Static library `libmy.a`
- Compilation via Makefile with specific rules
- Forbidden functions: Entire libC except `va_start`, `va_end`, `va_arg`, `malloc`, `free`, `write`
- Must handle all printf flags and format specifiers
- No printf buffer handling implementation required
