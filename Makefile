CFLAGS=-std=c99 -Wall

all: braillefont
clean:
	rm -f braillefont braillefont.o 6x8font.h

braillefont:	braillefont.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

braillefont.o:	braillefont.c 6x8font.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c $<

6x8font.h:	png2font 6x8.png
	./png2font >6x8font.h
