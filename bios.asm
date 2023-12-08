#include "instructionset.h"
#include "cpu.h"
#include <stdio.h>

struct interrupts{
    // i_set = isetvar

    char int10h {
        // display the "CHAR" in r1 to the screen
        printf("%s", R1);
    };
};
