# Unicode (UTF-8)

Unicode is an encoding scheam designed to be able to hold every character in every used language today including emojis with room for growth.

Everything in unicode is assigned a code point which is a unique combination of bits. 

## Properties

+ Includes all single byte characters
+ Also includes 2-4 byte values
+ All multi-byte values ( > 1) start with a top byte of 1

## Breakdown

|#Bytes | #Bits | Byte 1   |  Byte 2    | Byte 3     | Byte 4     | Holds                                             | 
| ----- | ----- | -------- | ---------- | ---------- | ---------- | ------------------------------------------------- |
| 1     | 7     | 0xxxxxxx | -          | -          | -          | ASCII encodings                                   |
| 2     | 11    | 110xxxxx | 10xxxxxx   | -          | -          | 2-byte codes including most latin-scrip alphabets |
| 3     | 16    | 1110xxxx | 10xxxxxx   | 10xxxxxx   | -          | 3-byte codes including most Asian languages       | 
| 4     | 21    | 11110xxx | 10xxxxxx   | 10xxxxxx   | 10xxxxxx   | 4-byte codes inclduing symbols and emojis         |

+ A 1-byte character starts out with a leading `0` bit
+ A 2-byte character starts out with a leading `110` set of bits
+ A 3-byte character starts out with a leading `1110` set of bits
+ A 4-byte character starts out with a leading `11110` set of bits

### Example Encodings

| character | code-point     | unicode binary    | UTF-8 Encoding       |
| --------- | -------------- | ----------------- | -------------------- | 
| $         | `U+0024`       | `0100100`         | `o0100100`           |

### Example Decoding

1. Determine how many bytes the code-point is
2. Strip away the leading bits
3. Combine remaining bits to get unicode symbol

Thefore the decoding of `$` is,

`100100`.

## Encoder Program

```
#include <stdio.h>
#include <stdint.h>

void print_utf8_encoding(uint32_t code_point) {
    uint8_t encoding[5] = {0};

    if (code_point < 0x80) {
        encoding[0] = code_point;
    } else if (code_point < 0x800) {
        encoding[0] = 0xC0 | (code_point >> 6);
        encoding[1] = 0x80 | (code_point & 0x3f);
    } else if (code_point < 0x10000) {
        encoding[0] = 0xE0 | (code_point >> 12);
        encoding[1] = 0x80 | ((code_point >> 6) & 0x3f);
        encoding[2] = 0x80 | (code_point  & 0x3f);
    } else if (code_point < 0x200000) {
        encoding[0] = 0xF0 | (code_point >> 18);
        encoding[1] = 0x80 | ((code_point >> 12) & 0x3f);
        encoding[2] = 0x80 | ((code_point >> 6)  & 0x3f);
        encoding[3] = 0x80 | (code_point  & 0x3f);
    }

    printf("U+%x  UTF-8: ", code_point);
    for (uint8_t *s = encoding; *s != 0; s++) {
        printf("0x%02x ", *s);
    }
    printf(" %s\n", encoding);
}

int main(void) {
    print_utf8_encoding(0x42);
    print_utf8_encoding(0x00A2);
    print_utf8_encoding(0x10be);
    print_utf8_encoding(0x1F600);
}

```