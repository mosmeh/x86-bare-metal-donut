#include <stddef.h>
#include <string.h>

#define putchar print_char
#define printf fake_printf
#define usleep delay

void print_char(char c);
void fake_printf(const char* arg);
void delay(unsigned int usec);
