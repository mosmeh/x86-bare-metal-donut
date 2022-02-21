#define ASM_FILE
#include "multiboot.h"

#define FLAGS 0
#define CHECKSUM -(MULTIBOOT_HEADER_MAGIC + FLAGS)
#define STACK_SIZE 0x4000

  .section .multiboot, "a"
  .align MULTIBOOT_HEADER_ALIGN
  .long MULTIBOOT_HEADER_MAGIC
  .long FLAGS
  .long CHECKSUM

  .text
  .globl _start
_start:
  movl $stack_top, %esp
  call init

  cli
loop:
  hlt
  jmp loop

  .section .stack, "aw", @nobits
  .skip STACK_SIZE
stack_top:
