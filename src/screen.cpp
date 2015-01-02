#include "screen.h"

static const char HEX_DIGITS[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F'
};

static char getHexDigit(unsigned int value) {
    return HEX_DIGITS[value & 0xF];
}

Screen::Screen(VgaTextDisplay &display) :
        mDisplay(display),
        mCursorRow(0),
        mCursorCol(0)
{
}

Screen& Screen::print(char c) {
    if (c == '\n') {
        println();
    } else {
        if (mCursorRow < mDisplay.numRows()) {
            mDisplay.putChar(mCursorRow, mCursorCol, c);
        }
        mCursorCol++;
        if (mCursorCol >= mDisplay.numCols()) {
            println();
        }
    }
    return *this;
}

Screen& Screen::print(const char *s) {
    while ((*s) != 0) {
        print(*s);
        s++;
    }
    return *this;
}

Screen& Screen::print(bool v) {
    return print(v ? "true" : "false");
}

Screen& Screen::printHex(uint16_t v) {
    print(getHexDigit(v >> 12));
    print(getHexDigit(v >> 8));
    print(getHexDigit(v >> 4));
    return print(getHexDigit(v));
}

Screen& Screen::println() {
    mCursorCol = 0;
    mCursorRow++;
    return *this;
}

Screen& Screen::println(char c) {
    print(c);
    return println();
}

Screen& Screen::println(const char *s) {
    print(s);
    return println();
}

void Screen::clear() {
    mDisplay.clear();
}
