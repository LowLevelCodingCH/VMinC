INT10H:
    CMP R4, 0x0E
    JZ DISPLAYCHAR
    JMP CONTINUE01
    DISPLAYCHAR:
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
    CONTINUE01:
        NOP

INT15H:
    CMP R4, 0x86
    JZ WAITSEC
    JMP CONTINUE02
    WAITSEC:
        CALL WAITTIME
        WAITTIME:
            CMP R5, R6
            JZ END15H
            NOP
        END15H:
            NOP
    CONTINUE02:
        NOP

INT16H:
    CMP R4, 0x00
    JZ READCHAR
    JMP CONTINUE03
    READCHAR:
        KGI R5
    CONTINUE03:
        NOP
