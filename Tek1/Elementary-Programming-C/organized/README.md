# ORGANIZED

## Description
Workshop management system implementing linked lists and sorting algorithms to organize hardware materials. The program provides an interactive shell interface for adding, deleting, displaying, and sorting various types of hardware components.

## Objective
Implement an `organized` program that must:
- Store and manage hardware materials using linked lists
- Provide interactive shell commands for material management
- Implement efficient sorting algorithms with multiple criteria
- Handle five categories of hardware materials
- Support reverse sorting and multi-level sorting operations

### Key Features
- **Hardware Storage**: Linked list implementation for material management
- **Interactive Shell**: Command-line interface for workshop operations
- **Multi-Category Support**: Five types of hardware materials
- **Flexible Sorting**: Multiple sorting criteria with reverse options
- **Unique ID System**: Auto-incrementing identification for materials
- **Batch Processing**: Support for pre-filled command files

### Hardware Categories
- **Actuators**: buttons, levers, etc.
- **Devices**: radios, watches, recorders, etc.
- **Processors**: intel, amd, etc.
- **Sensors**: movement sensor, sound sensor, thermal sensor, etc.
- **Wires**: type-c, hdmi, jack, etc.

### Material Properties
- **Type**: Hardware category (WIRE, ACTUATOR, DEVICE, PROCESSOR, SENSOR)
- **Name**: Descriptive name for the material
- **ID**: Unique auto-incrementing identifier (starting from 0)

### Data Structure Implementation
- Materials stored in linked list with reverse insertion order
- New materials added at the beginning of the list
- Efficient sorting algorithms for large datasets
- Support for complex multi-criteria sorting operations

## Constraints
- Language: C
- Compilation via Makefile with `re`, `clean`, `fclean` rules
- Error code 84 on error, 0 otherwise
- Authorized functions: `open`, `read`, `write`, `close`, `malloc`, `free`
- Uses provided `libshell.a` library and `shell.h` header
- Must implement: `add()`, `del()`, `disp()`, `sort()` functions
