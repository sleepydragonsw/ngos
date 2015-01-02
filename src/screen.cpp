#include "screen.h"

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
