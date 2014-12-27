CC := i686-elf-gcc
CXX := i686-elf-g++
AS := i686-elf-as
TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))
OUTDIR := $(TOPDIR)out/
.DEFAULT := all
.PHONY := all clean

BUILD_TARGETS :=

include $(TOPDIR)/src/Makefile

$(OUTDIR):
	mkdir --parents $(OUTDIR)

all: $(BUILD_TARGETS)

clean:
	rm -rf $(OUTDIR)
