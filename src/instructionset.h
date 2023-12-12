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

    INST_LDIA=3, // load immediate A
    INST_LDIB=4, // load immediate B
    INST_LDIC=5, // load immediate C
    INST_LDID=6, // load immediate D
    INST_LDIE=7, // load immediate E
    INST_LDIF=8, // load immediate F
    INST_LDIG=9, // load immediate G
    INST_LDIH=10, // load immediate H

    INST_LDA=11, // load A
    INST_LDB=12, // load B
    INST_LDC=13, // load C
    INST_LDD=14, // load D
    INST_LDE=15, // load E
    INST_LDF=16, // load F
    INST_LDG=17, // load G
    INST_LDH=18, // load H

    INST_STA=19, // store A
    INST_STB=20, // store B
    INST_STC=21, // store C
    INST_STD=22, // store D
    INST_STE=23, // store E
    INST_STF=24, // store F
    INST_STG=25, // store G
    INST_STH=26, // store H

    INST_CAB=27, // copy A to B
    INST_CAC=28, // copy A to C
    INST_CAD=29, // copy A to D
    INST_CAE=30, // copy A to E
    INST_CAF=31, // copy A to F
    INST_CAG=32, // copy A to G
    INST_CAH=33, // copy A to H

    INST_CBA=34, // copy B to A
    INST_CBC=35, // copy B to C
    INST_CBD=36, // copy B to D
    INST_CBE=37, // copy B to E
    INST_CBF=38, // copy B to F
    INST_CBG=39, // copy B to G
    INST_CBH=40, // copy B to H

    INST_CCA=41, // copy C to A
    INST_CCB=42, // copy C to B
    INST_CCD=43, // copy C to D
    INST_CCE=44, // copy C to E
    INST_CCF=45, // copy C to F
    INST_CCG=46, // copy C to G
    INST_CCH=47, // copy C to H

    INST_CDA=48, // copy D to A
    INST_CDB=49, // copy D to B
    INST_CDC=50, // copy D to C
    INST_CDE=51, // copy D to E
    INST_CDF=52, // copy D to F
    INST_CDG=53, // copy D to G
    INST_CDH=54, // copy D to H

    INST_CEA=55, // copy E to A
    INST_CEB=56, // copy E to B
    INST_CEC=57, // copy E to C
    INST_CED=58, // copy E to D
    INST_CEF=59, // copy E to F
    INST_CEG=60, // copy E to G
    INST_CEH=61, // copy E to H

    INST_CFA=62, // copy F to A
    INST_CFB=63, // copy F to B
    INST_CFC=64, // copy F to C
    INST_CFD=65, // copy F to D
    INST_CFE=66, // copy F to E
    INST_CFG=67, // copy F to G
    INST_CFH=68, // copy F to H

    INST_CGA=69, // copy G to A
    INST_CGB=70, // copy G to B
    INST_CGC=71, // copy G to C
    INST_CGD=72, // copy G to D
    INST_CGE=73, // copy G to E
    INST_CGF=74, // copy G to F
    INST_CGH=75, // copy G to H

    INST_CHA=76, // copy H to A
    INST_CHB=77, // copy H to B
    INST_CHC=78, // copy H to C
    INST_CHD=79, // copy H to D
    INST_CHE=80, // copy H to E
    INST_CHF=81, // copy H to F
    INST_CHG=82, // copy H to G

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