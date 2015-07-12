#include <stdio.h>

const char *font =
#include "6x8font.h"
;

#define L (8*6)
#define R (L*8)

static void phalf(char c, int offset)
{
    for (int x = 0; x < 3; x++)
    {
        int o = c%8*6 + x*2
              + (int)(c/8-4)*R + offset;
        int g = 0;
        if (font[o + 0 + 0*L] == '*') g+=1;
        if (font[o + 1 + 0*L] == '*') g+=8;
        if (font[o + 0 + 1*L] == '*') g+=2;
        if (font[o + 1 + 1*L] == '*') g+=16;
        if (font[o + 0 + 2*L] == '*') g+=4;
        if (font[o + 1 + 2*L] == '*') g+=32;
        if (font[o + 0 + 3*L] == '*') g+=64; // irregular
        if (font[o + 1 + 3*L] == '*') g+=128;
        // print Unicode codepoint 0x2800+g, as UTF-8.
        printf("%c%c%c", 0xe2, 0xa0+g/64, 0x80+g%64);
    }
}

int main()
{
    char buf[1024];
    while (fgets(buf, sizeof(buf), stdin))
    {
        const char *b;
        for (b=buf; *b; b++)
        {
            if (*b < 32)
                printf("%c", *b);
            else
                phalf(*b, 0);
        }
        for (b=buf; *b; b++)
        {
            if (*b < 32)
                printf("%c", *b);
            else
                phalf(*b, 4*L);
        }
    }

    return 0;
}
