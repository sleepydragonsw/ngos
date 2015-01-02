/*
This file was adapted from http://wiki.osdev.org/Bare_Bones
*/

#include "vga.h"
#include "screen.h"
#include <stdbool.h>
#include <stddef.h>

/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

static const char HEX_DIGITS[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F'
};

static char getHexChar(int c) {
    return HEX_DIGITS[c & 0xF];
}

static void memWordToHexString(int address, char* buf) {
    char *value = reinterpret_cast<char*>(address);
    char b1 = value[0];
    char b2 = value[1];
    buf[0] = '0';
    buf[1] = 'x';
    buf[2] = getHexChar(b2 >> 4);
    buf[3] = getHexChar(b2);
    buf[4] = getHexChar(b1 >> 4);
    buf[5] = getHexChar(b1);
    buf[6] = 0;
}

extern "C"
void kernel_main()
{
    VgaTextDisplay display;
    Screen screen(display);
    screen.clear();

    char buf[10];

    memWordToHexString(0x0400, buf);
    screen.print("COM Port 1 I/O Port: ").println(buf);

    memWordToHexString(0x0402, buf);
    screen.print("COM Port 2 I/O Port: ").println(buf);

    memWordToHexString(0x0463, buf);
    screen.print("Base I/O Port for Video: ").println(buf);
}
