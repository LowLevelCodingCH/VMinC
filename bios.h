#include "instructionset.h"
#include "cpu.h"
#include <stdio.h>

struct interrupts{
    // i_set = isetvar

    struct int10h {
        // display the "CHAR" in r1 to the screen
        putc(cpu.registers.R1); // josh: ALWAYS REMEMBER SEMICOLONS // llcch: OKAY SORRY
    };
};
