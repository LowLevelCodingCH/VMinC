#ifndef INSTRUCTIONSET_h_
#define INSTRUCTIONSET_h_

/*
    Basic program:
    (Adds 1 to the r1 register.)
    03 01
    00000010 00000001 // binary c sys
    Mov r1, 1
*/

// added by josh
// example:
// 0x3, 0x1, 0x71 (set R1 to 1)
typedef enum {
    // added no-op as its useful // llcch: added some more loads
    INST_NOP=0, // no operation

    INST_ADD=1, // add
    INST_SUB=2, // subtract
    INST_DIV=3, // divide
    INST_IDIV=4, // signed divide
    INST_MUL=5, // multiply
    INST_IMUL=6, // signed multiply
    INST_AND=7, // AND
    INST_OR=8, // OR
    INST_NOT=9, // NOT
    INST_INEG=10, // signed negation
    INST_XOR=11, // XOR
    INST_BSR=12, // bit shift right
    INST_BSL=13, // bit shift left
    INST_CMP=14, // compare

    MOV=16,

    INST_JMP=17, // jump
    INST_JC=18, // jump carry
    INST_JNC=19, // jump not carry
    INST_JZ=20, // jump zero
    INST_JNZ=21, // jump not zero

    INST_CALL=22, // call
    INST_RET=23, // return

    INST_PUSH=24, // push
    INST_PUSHI=25, // push immediate
    INST_POP=26, // pop

    INST_DEL=27, //llcch delete some register / clear some register

    INST_CDO=28, //llcch call display output to display something (BIOS ONLY)
    INST_KGI=29, //llcch get keyboard input (BIOS ONLY)

} instructions;

#endif