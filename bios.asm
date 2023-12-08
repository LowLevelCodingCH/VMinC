INT10H:
    DISPLAYCHAR:
        CMP R4, 0x0E ;AH
        ADD R1, 0xFFC0
        C1T2
        SUB R2, 0xFFC0
        ; now getting ready: DISPLAY CHARACTER IN R3
        C2T3
        NOP
        DEL R1
        DEL R2
        CDO R3
        NOP
        DEL R3

INT15H:
    WAITSEC:
        CMP R4, 0x86
        CALL WAITTIME
        WAITTIME:
            CMP R5, R6
            JZ END15H
            NOP

INT16H:
    READCHAR:
        KGI R5
