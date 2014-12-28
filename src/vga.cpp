#include <stddef.h>

#include "vga.h"

static const int VGA_COLOR_ADDRESS = 0xB8000;
static const size_t VGA_DEFAULT_NUM_ROWS = 25;
static const size_t VGA_DEFAULT_NUM_COLS = 80;

static uint16_t makeVgaEntry(char c) {
    return c;
}

VgaTextDisplay::VgaTextDisplay() :
    mVideoMemory(reinterpret_cast<uint16_t * const>(VGA_COLOR_ADDRESS)),
    mNumRows(VGA_DEFAULT_NUM_ROWS),
    mNumCols(VGA_DEFAULT_NUM_COLS)
{
}

bool VgaTextDisplay::putChar(size_t row, size_t col, char c) {
    if (row >= mNumRows || col > mNumCols) {
        return false;
    }
    const uint16_t entry = makeVgaEntry(c);
    const size_t i = (row * mNumCols) + col;
    mVideoMemory[i] = entry;
    return true;
}

void VgaTextDisplay::clear() {
    size_t row = mNumRows;
    while (row > 0) {
        row--;
        size_t col = mNumCols;
        while (col > 0) {
            col--;
            putChar(row, col, ' ');
        }
    }
}
