#ifndef INSTRUCTIONSET_h_
#define INSTRUCTIONSET_h_

typedef enum {
    INST_NOP = 0,

    INST_ADD,
    INST_SUB,
    INST_DIV,
    INST_IDIV,
    INST_MUL,
    INST_IMUL,
    INST_AND,
    INST_OR,
    INST_NOT,
    INST_INEG,
    INST_XOR,
    INST_BSR,
    INST_BSL,
    INST_CMP,

    INST_LR1,      // Load into registers (1-8)
    INST_LR2,      // Load immediates btw
    INST_LR3,
    INST_LR4,
    INST_LR5,
    INST_LR6,
    INST_LR7,
    INST_LR8,

    INST_INT,      // Interrupt

    INST_RCPY,     // Copy from a memory address stored in a register into a register (Reverse copy)
                   // Example
                   //     rcpy r1, r2 ; Copy into r1 the value that is in ram at address of the value r2

    INST_CPYR,     // Copy registers
                   // Example
                   //     cpyr r1, r2 ; Copy into r1 the value that r2 posesses (I speak premium English)

    INST_CPY,      // Copy data from one register to a memory address (specified by another register)
                   // Example:
                   //     cpy r1, r2   ; Copy into the memory address specified by r1 the value of r2

    INST_JMP,
    INST_JC,
    INST_JNC,
    INST_JZ,
    INST_JNZ,

    INST_CALL,
    INST_RET,

    INST_PUSH,
    INST_PUSHI,
    INST_POP,

    INST_DEL,
} instructions;

#endif
