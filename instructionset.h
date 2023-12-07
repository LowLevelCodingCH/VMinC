
/*
    Basic program:
    (Adds 1 to the r1 register.)
    03 01 
    00000003 00000001
    Mov r1, 1
*/

// added by josh
// example:
// 0x3, 0x1, 0x1 (set R1 to 1)
typedef enum {
    // added no-op as its useful
    INST_NOP=0,
    INST_ADD=1,
    INST_SUB=2,
    INST_LDI1=3,
} instructions;
