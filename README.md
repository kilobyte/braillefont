# braillefont
This hack will convert a given text to a bitmapped version using the Braille range of Unicode.
Individual characters use a grid of 6x8 (5x7 usable) "pixels" which are rendered by 3x2 blocks of Unicode characters.

The result:

⡇⠀⠀⡠⠤⡀⣄⠤⡀⡠⠤⡀⡠⡠⡀⠀⠀⠀⠠⡅⠀⡤⠤⡀⡠⠤⠄⡄⠀⡄⡠⡠⡀
⠧⠤⠄⠣⠤⠃⠇⠀⠀⠫⠭⠁⠇⠁⠇⠀⠀⠀⠀⠣⠀⡗⠒⠁⠬⠭⠂⠣⠤⠃⠇⠁⠇

Whether it is readable strongly depends on font used by your reader.  Most fonts produce a nice well-aligned grid,
some introduce unsightly gaps at character boundaries, unfortunately some (like Dejavu Mono Sans) try to render
"off" pixels which makes things hard to read with a large font size and utterly unreadable with a small font.

The results are:
* most fonts: good
* Dejavu, large size: somewhat hard to read
* Dejavu, small size: useless, utterly illegible

The problem is, Dejavu is the default for some terminals on some distributions: xfce-terminal, gnome-terminal on Debian (but not Ubuntu).  Other terminals, like xterm or rxvt look fine.
