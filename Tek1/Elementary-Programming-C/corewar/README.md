# Corewar

## Description
Virtual machine implementation for the Corewar tournament where robot champions compete for memory dominance. The VM executes bytecode programs (.cor files) in a shared memory arena, managing program scheduling, instruction execution, and survival determination through the `live` instruction mechanism.

## Objective
Implement a `corewar` virtual machine that must:
- Load and execute multiple champion programs simultaneously
- Manage shared memory arena with proper address spacing
- Execute 16 instruction types with cycle-accurate timing
- Handle process scheduling and parallel execution simulation
- Determine tournament winner based on `live` instruction survival
- Support memory dumping and program loading configuration

### Virtual Machine Architecture
**Program Components:**
- **Registers**: REG_NUMBER registers of REG_SIZE bytes each
- **Program Counter (PC)**: Memory address of next instruction
- **Carry Flag**: Set to 1 when last operation returned zero
- **Player Number**: Stored in r1 register at startup

**Memory Management:**
- Shared memory arena of MEM_SIZE bytes
- Automatic address optimization for maximum separation
- Modulo addressing with IDX_MOD constraints
- Custom load addresses via `-a` parameter

### Instruction Set (16 opcodes)
- **0x01 (live)**: Signal player alive status
- **0x02 (ld)**: Load value into register
- **0x03 (st)**: Store register value
- **0x04-0x05 (add/sub)**: Arithmetic operations
- **0x06-0x08 (and/or/xor)**: Bitwise operations
- **0x09 (zjmp)**: Conditional jump based on carry
- **0x0a-0x0b (ldi/sti)**: Indirect load/store operations
- **0x0c (fork)**: Create new process
- **0x0d-0x0f (lld/lldi/lfork)**: Long versions without IDX_MOD
- **0x10 (aff)**: Display ASCII character

### Survival Mechanism
- Champions must execute `live` every CYCLE_TO_DIE cycles
- After NBR_LIVE executions, CYCLE_TO_DIE decreases by CYCLE_DELTA
- Process continues until only one champion remains alive
- Last champion to execute `live` wins the tournament

## Technical Specifications
- **Binary**: `corewar`
- **Language**: C
- **Compilation**: Makefile with `re`, `clean`, `fclean` rules
- **Input**: Bytecode files (.cor)
- **Scheduling**: Cycle-accurate parallel simulation
- **Authorized functions**: File I/O, memory management

## Key Features
- Multi-program virtual machine execution
- Cycle-based instruction scheduling with timing accuracy
- Process creation and management via `fork` operations
- Memory protection and address validation
- Automatic champion spacing optimization
- Real-time survival monitoring and elimi
