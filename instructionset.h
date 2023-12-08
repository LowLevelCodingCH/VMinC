
/*
    Basic program:
    (Adds 1 to the r1 register.)
    03 01 
    00000010 00000001 // binary c sys
    Mov r1, 1
*/

// added by josh
// example:
// 0x3, 0x1, 0x1 (set R1 to 1)
typedef enum {
    // added no-op as its useful // llcch: added some more loads
    INST_NOP=0,
    INST_ADD=1,
    INST_SUB=2,
    INST_LDI1=3,
    INST_LDI2=4,
    INST_LDI3=5,
    INST_LDI4=6,
    INST_LDI5=7
    INST_LDI6=8
    INST_LDI7=9,
    INST_LDI8=10,
} instructions;
