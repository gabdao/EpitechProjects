# MINISHELL

## Description
Custom UNIX command interpreter based on TCSH with support for advanced shell features including pipes, redirections, and command chaining.

## Objective
Implement a `mysh` program that must:
- Display interactive prompt and execute commands
- Handle both PATH-based and absolute path commands
- Manage environment variables and built-in commands
- Process complex command sequences with pipes and redirections
- Maintain proper error handling and exit status propagation

### Key Features
- **Command Execution**: Execute binaries from PATH or absolute paths
- **Built-in Commands**: `cd`, `setenv`, `unsetenv`, `env`, `exit`
- **Environment Management**: Copy and restore initial environment
- **Command Chaining**: Execute multiple commands with `;`
- **Pipe Operations**: Chain commands with `|` for data flow
- **Redirections**: Handle `>`, `<`, `>>`, `<<` for I/O redirection
- **Priority Management**: Proper operator precedence handling
- **Error Handling**: Appropriate error messages on stderr
- **Exit Status**: Propagate command exit status correctly

## Constraints
- Language: C
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Authorized functions: `malloc`, `free`, `exit`, `opendir`, `readdir`, `closedir`, `getcwd`, `chdir`, `fork`, `stat`, `lstat`, `fstat`, `open`, `close`, `getline`, `strtok`, `strtok_r`, `read`, `write`, `execve`, `access`, `isatty`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `getpid`, `strerror`, `perror`, `strsignal`, `pipe`, `dup`, `dup2`

## Built-in Commands
- `cd [directory]`: Change current directory
- `setenv [var] [value]`: Set environment variable
- `unsetenv [var]`: Remove environment variable
- `env`: Display environment variables
- `exit`: Exit the shell
