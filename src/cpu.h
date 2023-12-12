#ifndef CPU_h_
#define CPU_h_

struct cpu
{
    struct registers
    {
        // INITIALIZE: r1 r2 r3 r4 r5 r6 r7 r8
        char A = 0x00;
        char B = 0x00;
        char C = 0x00;
        char D = 0x00;
        char E = 0x00;
        char F = 0x00;
        char G = 0x00;
        char H = 0x00;
    };
};

#endif