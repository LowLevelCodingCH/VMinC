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

    INST_MOV=3, // move

    INST_JMP=83, // jump
    INST_JC=84, // jump carry
    INST_JNC=85, // jump not carry
    INST_JZ=86, // jump zero
    INST_JNZ=87, // jump not zero

    INST_CALL=88, // call
    INST_RET=89, // return

    INST_DIV=90, // divide
    INST_IDIV=91, // signed divide
    INST_MUL=92, // multiply
    INST_IMUL=93, // signed multiply
    INST_AND=94, // AND
    INST_OR=95, // OR
    INST_NOT=96, // NOT
    INST_INEG=97, // signed negation
    INST_XOR=98, // XOR
    INST_BSR=99, // bit shift right
    INST_BSL=100, // bit shift left
    INST_CMP=101, // compare

    INST_PUSH=102, // push
    INST_PUSHI=103, // push immediate
    INST_POP=104, // pop

    INST_DEL=105, //llcch delete some register / clear some register

    INST_CDO=106, //llcch call display output to display something (BIOS ONLY)
    INST_KGI=107, //llcch get keyboard input (BIOS ONLY)

} instructions;

#endif
