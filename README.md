# braillefont
This hack will convert a given text to a bitmapped version using the Braille range of Unicode.
Individual characters use a grid of 6x8 (5x7 usable) "pixels" which are rendered by 3x2 blocks of Unicode characters.

The result:

    ⡇⠀⠀⡠⠤⡀⣄⠤⡀⡠⠤⡀⡠⡠⡀⠀⠀⠀⠠⡅⠀⡤⠤⡀⡠⠤⠄⡄⠀⡄⡠⡠⡀
    ⠧⠤⠄⠣⠤⠃⠇⠀⠀⠫⠭⠁⠇⠁⠇⠀⠀⠀⠀⠣⠀⡗⠒⠁⠬⠭⠂⠣⠤⠃⠇⠁⠇

Whether it is readable strongly depends on font used by your reader.  Most
fonts produce a nice well-aligned grid, some introduce unsightly gaps at
character boundaries, unfortunately one (FreeFont Mono) follows the Unicode
specification by rendering "off" pixels, which makes it completely
unreadable at font sizes usually used for terminals.  This applies to
legitimate uses of Braille, not just this abuse.  A fix for FreeFont is
available but hasn't been released yet.

The problem is, Freefont is installed by default on most distributions, and
in many cases it gets chosen as fallback for Braille glyphs.
