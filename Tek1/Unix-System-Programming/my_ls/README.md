# my_ls

## Description
Complete reimplementation of the Unix `ls` command in C. This project recreates the directory listing functionality with support for multiple options and file/directory arguments, providing detailed file information and various sorting methods.

## Objective
Implement a `my_ls` program that must:
- Replicate the behavior of `ls [-alRdrt] [FILE]` command
- Handle multiple options in any order combination
- Accept multiple files and directories as parameters
- Display file information with proper formatting
- Support recursive directory traversal

## Technical Requirements

**Core Features:**
- Directory traversal and file stat information
- Permission string formatting (drwxrwxrwx)
- User and group name resolution
- File size and modification time display
- Proper column alignment in long format

## Constraints
- Language: C
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Limited to specific system calls only

### Authorized System Calls
- Directory operations: `opendir`, `readdir`, `closedir`
- File information: `stat`, `lstat`, `readlink`
- User/group info: `getpwuid`, `getgrgid`
- Time functions: `time`, `ctime`
- Memory: `malloc`, `free`
- Error handling: `perror`, `strerror`, `exit`
- Variadic functions: `va_start`, `va_arg`, `va_end`
