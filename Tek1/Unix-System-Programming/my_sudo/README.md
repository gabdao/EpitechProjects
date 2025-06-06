# MY_SUDO

## Description
Custom implementation of the sudo command that allows users to execute commands with elevated privileges. The program reads security policies from `/etc/sudoers` and authenticates users through password verification.

## Objective
Implement a `my_sudo` program that must:
- Parse and interpret `/etc/sudoers` file for security policies
- Authenticate users with password verification (3 attempts maximum)
- Execute commands with different user/group privileges
- Handle various command-line options and flags
- Maintain security standards for privilege escalation

### Key Features
- **User Authentication**: Password-based authentication with shadow file integration
- **Sudoers Parsing**: Read and interpret user aliases from `/etc/sudoers`
- **Privilege Switching**: Execute commands as different users/groups
- **Shell Support**: Launch interactive shells with `-s` flag
- **Security**: Safe handling of user credentials and input validation

## Constraints
- Language: C
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Forbidden functions: `getpw*`, `*getsp*`, `getgr*`, `*fork*`, `*clone*`, `openat*`
- Password authentication without PAM library
- Direct stdin reading for password input
- Must handle User Aliases from sudoers file

## Security Considerations
- Safe credential handling during authentication
- Input validation and sanitization
- No information disclosure on authentication failure
- Proper privilege dropping and escalation
