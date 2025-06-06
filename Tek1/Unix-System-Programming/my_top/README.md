# my_top

## Description
Complete reimplementation of the Unix `top` command in C using ncurses. This system monitoring tool displays real-time information about running processes and system statistics with an interactive terminal user interface.

## Objective
Implement a `my_top` program that must:
- Monitor system processes and statistics in real-time
- Display information using ncurses terminal interface
- Support filtering, sorting, and interactive commands
- Parse system information from /proc filesystem
- Handle process management and signal sending

### System Information Display
**Upper Section:**
- Current time of day
- System uptime (days, hours, minutes format)
- Number of logged-in users
- Load average (1, 5, 15 minutes)
- Task summary (total, running, sleeping, stopped, zombie)
- CPU usage statistics
- Memory usage (RAM)
- Swap usage

### Process Information Display
**Lower Section (Process List):**
- PID (Process ID) - **MUST be implemented first**
- USER (Process owner)
- PR (Priority)
- NI (Nice value)
- VIRT (Virtual memory size)
- RES (Resident memory size)
- SHR (Shared memory size)
- S (Process status)
- %CPU (CPU usage percentage)
- %MEM (Memory usage percentage)
- TIME+ (Process runtime)
- COMMAND (Process name)

## Technical Requirements

**Core Features:**
- Real-time system monitoring via /proc filesystem
- ncurses-based interactive interface
- Process filtering and sorting
- Memory unit conversion
- Signal sending to processes

## Constraints
- Language: C
- UI Library: ncurses
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Manual /proc parsing required (no system calls like getloadavg)

### Forbidden Functions
- `system`, `exec*`, `popen`
- `getloadavg`, `getrusage`, `getrlimit`
- `getutent`, `setutent`
- Any function that retrieves process/system info automatically

## Implementation Notes
