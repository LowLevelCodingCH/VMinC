import sys

argv = sys.argv

fname = argv[1]

with open(fname, "r") as filestream:
    binarystack = []
    flines = filestream.readlines()
    iterator = 0
    for fline in flines:

    
        #DEFSECTION:
        def RStackReplace():
            if "r1" in flines[iterator] and flines[iterator][1] == "r1":
                    flines[iterator].replace("r1", "31")
            if "r2" in flines[iterator] and flines[iterator][1] == "r2":
                    flines[iterator].replace("r2", "32")
            if "r3" in flines[iterator] and flines[iterator][1] == "r3":
                    flines[iterator].replace("r3", "33")
            if "r4" in flines[iterator] and flines[iterator][1] == "r4":
                    flines[iterator].replace("r4", "34")
            if "r5" in flines[iterator] and flines[iterator][1] == "r5":
                    flines[iterator].replace("r5", "35")
            if "r6" in flines[iterator] and flines[iterator][1] == "r6":
                    flines[iterator].replace("r6", "36")
            if "r7" in flines[iterator] and flines[iterator][1] == "r7":
                    flines[iterator].replace("r7", "37")
            if "r8" in flines[iterator] and flines[iterator][1] == "r8":
                    flines[iterator].replace("r8", "38")

        def FLinesIterator(RString: str, IString: str):
            if flines[iterator].startswith(RString):
                flines[iterator].replace(RString, IString)
                RStackReplace()




        if flines[iterator] == "nop": flines[iterator].replace("nop","0")
        FLinesIterator("add", "1")
        FLinesIterator("sub", "2")
        FLinesIterator("div", "3")
        FLinesIterator("idiv", "4")
        FLinesIterator("mul", "5")
        FLinesIterator("imul", "6")
        #and or not ineg xor bsr bsl
        FLinesIterator("cmp", "14")

        FLinesIterator("mov", "16") #what the fuck bro, why, 14 to 16, but okay fuckers
        
        #jmp jc jnc jz jnz

        #call
        FLinesIterator("ret", "23")

        #push pushi pop

        FLinesIterator("del", "27")

        FLinesIterator("cdo", "28")
        FLinesIterator("kgi", "29")
        FLinesIterator("ldr", "30")

        iterator += 1