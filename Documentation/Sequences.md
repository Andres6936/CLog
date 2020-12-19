### This is a complete list of the ANSI/VT escape sequences.

###### The initial escape character is assumed. 

The display consists of the buffer width and window height; add '+' before the
final character to use the buffer height (e.g. "[2J" will erase the window,
whilst "[2+J" will erase the buffer).  BEL will also be recognised, playing
the Windows default beep (but only if it's not already playing).

- [m	restore default color (and intensity)
- [0m	as above
- [...m	set attributes (any of these numbers, separated by semicolons):

```
        0	        all attributes off
        1	        bold (foreground is intense)
        4	        underline (background is intense)
        5	        blink (background is intense)
        7	        reverse video
        8	        concealed (foreground becomes background)
        22	        bold off (foreground is not intense)
        24	        underline off (background is not intense)
        25	        blink off (background is not intense)
        27	        normal video
        28	        concealed off
        30	        foreground black
        31	        foreground red
        32	        foreground green
        33	        foreground yellow
        34	        foreground blue
        35	        foreground magenta
        36	        foreground cyan
        37	        foreground white
        38;2;#	        foreground based on index (0-255)
        38;5;#;#;#      foreground based on RGB
        39	        default foreground (using current intensity)
        40	        background black
        41	        background red
        42	        background green
        43	        background yellow
        44	        background blue
        45	        background magenta
        46	        background cyan
        47	        background white
        48;2;#	        background based on index (0-255)
        48;5;#;#;#      background based on RGB
        49	        default background (using current intensity)
        90	        foreground bright black
        91	        foreground bright red
        92	        foreground bright green
        93	        foreground bright yellow
        94	        foreground bright blue
        95	        foreground bright magenta
        96	        foreground bright cyan
        97	        foreground bright white
        100	        background bright black
        101	        background bright red
        102	        background bright green
        103	        background bright yellow
        104	        background bright blue
        105	        background bright magenta
        106	        background bright cyan
        107	        background bright white

	  Index is 0-7 for the normal colors and 8-15 for the bright; 16-231
	  are a 6x6x6 color cube; and 232-255 are a grayscale ramp (without
	  black or white).  Indices 16-255 and RGB colors will find the nearest
	  color from the first 16.
```