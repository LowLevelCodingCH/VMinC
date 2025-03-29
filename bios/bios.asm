;; NOTE THAT THIS IS NOT OUR ARCH, BUT AN INTEL-ARM-RISCV-AND_MY_OWN MIX
;; THIS IS INBRED
;; AND JUST TO SHOW WHAT IT WOULD LOOK LIKE

bios_SETUP: ; Will get called, Immediately.
    call init_ivt ; Loads interrupts for CPU
    ret

isr0:
    pusha
    cli
        mov [0xB8000 + ah], byte al
    sti
    popa
    ret ; iret for intel

isr1:
    pusha
    cli
        mov [0xA0000], byte al
    sti
    popa
    ret ; iret for intel

ivt: ; Possible IVT
    call isr0
    call isr1
    ; ...

init_ivt:
    livt [ivt] ; Interrupt vector table
    ret
