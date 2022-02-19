#include "hack.h"

#define COLUMNS 80
#define ROWS 24

static volatile unsigned char* video = (unsigned char*)0xb8000;
static int pox_x, pos_y;

int main();

void init() {
    volatile unsigned char* v = video;
    for (size_t i = 0; i < ROWS * COLUMNS; ++i) {
        *v++ = 0;
        *v++ = 7;
    }

    main();
}

void print_char(char c) {
    if (c == '\n') {
        pox_x = 0;
        ++pos_y;
        return;
    }

    *(video + (pox_x + pos_y * COLUMNS) * 2) = c;
    ++pox_x;
}

void fake_printf(const char* arg) {
    (void)arg;
    pos_y -= 23; // "\x1b[23A"
}

void delay(unsigned int usec) {
    unsigned char dummy;
    while (usec--)
        __asm__ volatile("inb $0x80, %0" : "=a"(dummy));
}

void* memset(void* s, int c, size_t n) {
    size_t dest = (size_t)s;
    __asm__ volatile("rep stosb\n"
                     : "=D"(dest), "=c"(n)
                     : "0"(dest), "1"(n), "a"(c)
                     : "memory");
    return s;
}
