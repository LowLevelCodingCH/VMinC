
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

    INST_LDI1=3, // load immediate 1
    INST_LDI2=4, // load immediate 2
    INST_LDI3=5, // load immediate 3
    INST_LDI4=6, // load immediate 4
    INST_LDI5=7, // load immediate 5
    INST_LDI6=8, // load immediate 6
    INST_LDI7=9, // load immediate 7
    INST_LDI8=10, // load immediate 8

    INST_LD1=11, // load 1
    INST_LD2=12, // load 2
    INST_LD3=13, // load 3
    INST_LD4=14, // load 4
    INST_LD5=15, // load 5
    INST_LD6=16, // load 6
    INST_LD7=17, // load 7
    INST_LD8=18, // load 8

    INST_ST1=19, // store 1
    INST_ST2=20, // store 2
    INST_ST3=21, // store 3
    INST_ST4=22, // store 4
    INST_ST5=23, // store 5
    INST_ST6=24, // store 6
    INST_ST7=25, // store 7
    INST_ST8=26, // store 8

    INST_C1T2=27, // copy 1 to 2
    INST_C1T3=28, // copy 1 to 3
    INST_C1T4=29, // copy 1 to 4
    INST_C1T5=30, // copy 1 to 5
    INST_C1T6=31, // copy 1 to 6
    INST_C1T7=32, // copy 1 to 7
    INST_C1T8=31, // copy 1 to 8


    INST_C2T1=32, // copy 2 to 1
    INST_C2T3=32, // copy 2 to 3
    INST_C2T4=32, // copy 2 to 4
    INST_C2T5=32, // copy 2 to 5
    INST_C2T6=32, // copy 2 to 6
    INST_C2T7=32, // copy 2 to 7
    INST_C2T8=32, // copy 2 to 8

    // not finished so far

    INST_JMP=27, // jump
    INST_JC=28, // jump carry
    INST_JNC=29, // jump not carry
    INST_JZ=30, // jump zero
    INST_JNZ=31, // jump not zero

    INST_CALL=32, // call
    INST_RET=33, // return

    INST_DIV=34, // divide
    INST_IDIV=35, // signed divide
    INST_MUL=36, // multiply
    INST_IMUL=37, // signed multiply
    INST_AND=38, // AND
    INST_OR=39, // OR
    INST_NOT=40, // NOT
    INST_INEG=41, // signed negation
    INST_XOR=42, // XOR
    INST_BSR=43, // bit shift right
    INST_BSL=44, // bit shift left
    INST_CMP=45, // compare

    INST_PUSH=46, // push
    INST_PUSHI=47, // push immediate
    INST_POP=48, // pop

    INST_DEL=49, // delete some register / clear some register

    INST_CDO=50, // call display output to display something (BIOS ONLY)

} instructions;
