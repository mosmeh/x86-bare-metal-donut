CFLAGS := -m32 -nostdlib -ffreestanding -O2

.PHONY: all clean

all: donut

donut: entry.o donut.o hack.o
	$(CC) $(CFLAGS) -Wl,-Tlinker.ld -o '$@' $^

entry.o: entry.S
	$(CC) $(CFLAGS) -c -o '$@' '$<'

donut.o: donut.c
	$(CC) $(CFLAGS) -Wno-implicit-int -include hack.h -c -o '$@' '$<'

hack.o: hack.c
	$(CC) $(CFLAGS) -std=c11 -Wall -Wextra -c -o '$@' '$<'

clean:
	rm -f donut *.o
