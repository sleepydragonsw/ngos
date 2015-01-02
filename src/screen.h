#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "vga.h"
#include <stddef.h>

class Screen {

    private:
        VgaTextDisplay &mDisplay;
        size_t mCursorRow;
        size_t mCursorCol;

    public:
        Screen(VgaTextDisplay &display);
        void clear();
        Screen& print(char c);
        Screen& print(const char *s);
        Screen& println();
        Screen& println(char c);
        Screen& println(const char *s);

};

#endif /* ifndef __SCREEN_H__ */
