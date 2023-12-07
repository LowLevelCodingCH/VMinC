char i_set[5] = {
    0x01, 0x02, 0x03, 0x04, 0x05
};

/*
    Mov r1; Add r1; Sub r1; Mul r1; Div r1


    Basic program:
    (Adds 1 to the r1 register.)
    01 01 
    00000001 00000001
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
    INST_MOV=3,
} instructions;
