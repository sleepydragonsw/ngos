#ifndef __VGA_H__
#define __VGA_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

class VgaTextDisplay {

    private:
        uint16_t * const mVideoMemory;
        size_t mNumRows;
        size_t mNumCols;

    public:

        enum Color {
            BLACK = 0,
            BLUE = 1,
            GREEN = 2,
            CYAN = 3,
            RED = 4,
            MAGENTA = 5,
            BROWN = 6,
            GRAY = 7,
        };

        struct DisplayOptions {
            Color fgColor;
            Color bgColor;
            bool bright;
            bool blink;
        };

        VgaTextDisplay();
        size_t numRows() const { return mNumRows; }
        size_t numCols() const { return mNumCols; }
        void clear();
        bool putChar(size_t row, size_t col, char c,
            const DisplayOptions *options = NULL);

        bool putChar(size_t row, size_t col, char c,
                Color fgColor, Color bgColor = BLACK,
                bool bright = false, bool blink = false) {
            DisplayOptions options;
            options.fgColor = fgColor;
            options.bgColor = bgColor;
            options.bright = bright;
            options.blink  = blink;
            return putChar(row, col, c, &options);
        }
};

#endif /* #ifndef __VGA_H__ */
