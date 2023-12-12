#ifndef CPU_h_
#define CPU_h_

struct cpu
{
    struct registers
    {
        // INITIALIZE: r1 r2 r3 r4 r5 r6 r7 r8
        char R1 = 0x00;
        char R2 = 0x00;
        char R3 = 0x00;
        char R4 = 0x00;
        char R5 = 0x00;
        char R6 = 0x00;
        char R7 = 0x00;
        char R8 = 0x00;
    };
};

#endif
