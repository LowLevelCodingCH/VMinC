from PIL import Image
import os
import numpy
import array

def compile_charset(filename):
    out = "{"

    image = Image.open(os.path.dirname(__file__) + "/" + filename).convert("L")

    bitmap = numpy.array(image)

    for row in range(8):
        for col in range(12):
            # out += "\n    "
            out += "{"

            for row1 in range(0, 16):
                for col1 in range(0, 16):
                    out += f"{color_to_num(bitmap[row * 16 + row1, col * 16 + col1])},"
                # out += "\n      "

            out += "},"

    return out + "}"

def color_to_num(c):
    if c > 0: return 0
    if c <= 0: return 1


def as_char(n):
    if n > 0:
        return "  "
    if n <= 0:
        return "██"


with open(os.path.dirname(__file__) + "/charset_debug.c", 'wb') as f:
    f.write(("const char charset_debug[96][256] = " + compile_charset("./charset_debug.png") + ";").encode())

with open(os.path.dirname(__file__) + "/charset.c", 'wb') as f:
    f.write(("const char charset[96][256] = " + compile_charset("./charset.png") + ";").encode())