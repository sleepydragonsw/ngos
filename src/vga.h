#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

class VgaTextDisplay {
    private:
        uint16_t * const mVideoMemory;
        size_t mNumRows;
        size_t mNumCols;
    public:
        VgaTextDisplay();
        size_t numRows() const { return mNumRows; }
        size_t numCols() const { return mNumCols; }
        void clear();
        bool putChar(size_t row, size_t col, char c);
};
