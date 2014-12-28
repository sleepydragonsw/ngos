CXX := i686-elf-g++
CXXFLAGS := -std=gnu++11 -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti
AS := i686-elf-as
TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))
OUTDIR := $(TOPDIR)out/
.DEFAULT := all
.PHONY := all clean

BUILD_TARGETS :=

include $(TOPDIR)/src/Makefile

$(OUTDIR):
	mkdir --parents $(OUTDIR)

all: $(OUTDIR) $(BUILD_TARGETS)

clean:
	rm -rf $(OUTDIR)
