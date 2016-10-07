#include <stdio.h>
#include <wchar.h>
#include <locale.h>

const char *font =
#include "6x8font.h"
;

#define L (8*6)
#define R (L*8)

static void phalf(unsigned char c, int offset)
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

static short win1252[32]=
{
    0x20ac,     -1, 0x201a, 0x0192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x02c6, 0x2030, 0x0160, 0x2039, 0x0152,     -1, 0x017d,     -1,
        -1, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x02dc, 0x2122, 0x0161, 0x203a, 0x0153,     -1, 0x017e, 0x0178,
};

static wchar_t map_character(wchar_t c)
{
    if (c < 256)
        return c;
    for (int i=0; i<32; i++)
        if (c==win1252[i])
            return 128+i;
    return 127;
}

int main()
{
    wchar_t buf[1024];
    setlocale(LC_CTYPE, "");

    while (fgetws(buf, sizeof(buf), stdin))
    {
        const wchar_t *b;
        for (b=buf; *b; b++)
        {
            if (*b < 32)
                printf("%c", *b);
            else
                phalf(map_character(*b), 0);
        }
        for (b=buf; *b; b++)
        {
            if (*b < 32)
                printf("%c", *b);
            else
                phalf(map_character(*b), 4*L);
        }
    }

    return 0;
}
