# Robot Factory

## Description
Assembly language compiler for the Corewar tournament that transforms robot champions written in assembly (.s files) into executable bytecode (.cor files). The program serves as an assembler for a virtual machine where robot programs compete for memory dominance.

## Objective
Implement an `asm` program that must:
- Parse assembly language files with champion specifications
- Convert assembly instructions into machine bytecode
- Handle header information (name, comment) and instruction transcription
- Generate executable .cor files for the Corewar virtual machine
- Support all 16 instruction types with proper parameter encoding

### Assembly Language Structure
**Header Components:**
- `.name "Champion Name"` - Robot identifier
- `.comment "Description"` - Champion description
- Comments starting with '#' character

**Instruction Format:**
- **Opcode**: Instruction name (live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, fork, lld, lldi, lfork, aff)
- **Parameters**: Up to MAX_ARGS_NUMBER parameters separated by commas
- **Labels**: Coordinate points marked with LABEL_CHAR (':')

### Parameter Types
1. **Register**: `r1` to `rREG_NUMBER` - Internal processor memory
2. **Direct**: `%value` or `%:label` - Immediate values with DIRECT_CHAR
3. **Indirect**: `value` or `:label` - Memory address references

### Bytecode Generation
**Instruction Encoding (3 components):**
1. **Instruction Code**: Single byte opcode from op_tab
2. **Coding Byte**: Parameter type descriptor (2 bits per parameter)
   - Register: `01`
   - Direct: `10` 
   - Indirect: `11`
   - Unused: `00`
3. **Parameters**: Values encoded by type size
   - Register: 1 byte
   - Direct: DIR_SIZE bytes (IND_SIZE for indexes)
   - Indirect: IND_SIZE bytes

## Technical Specifications
- **Binary**: `asm`
- **Language**: C
- **Compilation**: Makefile with `re`, `clean`, `fclean` rules
- **Input**: Assembly files (.s)
- **Output**: Bytecode files (.cor)
- **Endianness**: BIG ENDIAN format
- **Authorized functions**: File I/O, memory management, getline

## Key Features
- Complete assembly language parser
- Header transcription with champion metadata
- 16 instruction types support with parameter validation
- Label resolution and address calculation
- Big-endian bytecode generation
- Index parameter handling for specific instructions
- Comprehensive error handling with exit code 84
