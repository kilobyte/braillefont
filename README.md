# braillefont
This hack will convert a given text to a bitmapped version using the Braille range of Unicode.
Individual characters use a grid of 6x8 (5x7 usable) "pixels" which are rendered by 3x2 blocks of Unicode characters.

The result:

⡇⠀⠀⡠⠤⡀⣄⠤⡀⡠⠤⡀⡠⡠⡀⠀⠀⠀⠠⡅⠀⡤⠤⡀⡠⠤⠄⡄⠀⡄⡠⡠⡀
⠧⠤⠄⠣⠤⠃⠇⠀⠀⠫⠭⠁⠇⠁⠇⠀⠀⠀⠀⠣⠀⡗⠒⠁⠬⠭⠂⠣⠤⠃⠇⠁⠇

Whether it is readable strongly depends on font used by your reader.  Most fonts produce a nice well-aligned grid,
some introduce unsightly gaps at character boundaries, unfortunately some (like Dejavu Mono Sans) try to render
"off" pixels which makes things hard to read with a large font size and utterly unreadable with a small font.

Various clients with default settings on Debian:
* xterm: good
* rxvt: good
* xfce-terminal (and others using libvte): bad but somewhat readable
* osso-xterm (libvte): good
