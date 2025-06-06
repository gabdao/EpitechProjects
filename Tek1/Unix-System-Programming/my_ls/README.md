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

### Supported Options
- `-l`: Long format listing (permissions, links, owner, group, size, date)
- `-a`: Show all files including hidden files (starting with '.')
- `-R`: Recursive listing of subdirectories
- `-d`: List directories themselves, not their contents
- `-r`: Reverse sort order
- `-t`: Sort by modification time (newest first)

### Option Combinations
Options can be combined in any order:
```bash
./my_ls -l -t        # Separate options
./my_ls -lRt         # Combined options
./my_ls -lt -R -t    # Mixed format
```

### Multiple File Arguments
```bash
./my_ls -l /dev /usr/sbin
./my_ls -l -r file1 file2
```

## Technical Requirements

**Core Features:**
- Directory traversal and file stat information
- Permission string formatting (drwxrwxrwx)
- User and group name resolution
- File size and modification time display
- Proper column alignment in long format

**Bonus Features:**
- Column formatting without `-l` option
- File sorting and coloring
- Additional options: `-u`, `-F`, `-g`, `-f`

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
- I/O: `write`
- Memory: `malloc`, `free`
- Error handling: `perror`, `strerror`, `exit`
- Variadic functions: `va_start`, `va_arg`, `va_end`
