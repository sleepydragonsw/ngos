/*
This file was adapted from http://wiki.osdev.org/Bare_Bones
*/

#include "vga.h"

/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

extern "C"
void kernel_main()
{
    VgaTextDisplay display;
    display.clear();
    display.putChar(0, 0, 'H');
    display.putChar(0, 1, 'e');
    display.putChar(0, 2, 'l');
    display.putChar(0, 3, 'l');
    display.putChar(0, 4, 'o');
    display.putChar(0, 5, ' ');
    display.putChar(0, 6, 'W');
    display.putChar(0, 7, 'o');
    display.putChar(0, 8, 'r');
    display.putChar(0, 9, 'l');
    display.putChar(0, 10, 'd');
    display.putChar(0, 11, '!');
}
