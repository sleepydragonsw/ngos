/*
This file was adapted from http://wiki.osdev.org/Bare_Bones
*/

#include "vga.h"
#include "screen.h"
#include "comport.h"
#include <stddef.h>

/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

static void doComPort(Screen &screen) {
    ComPort comPort;
    screen.print("COM Port Base I/O Port: 0x");
    screen.printHex(comPort.getBaseIoPort());
    screen.println();

    screen.print("COM Port Supported: ");
    screen.print(comPort.isSupported());
    screen.println();

    char c;
    while (true) {
        if (! comPort.read(&c)) {
            break;
        }
        comPort.write(c+1);
    }
}

extern "C"
void kernel_main()
{
    VgaTextDisplay display;
    Screen screen(display);
    screen.clear();
    doComPort(screen);
}
