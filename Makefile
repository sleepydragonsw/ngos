CC := i686-elf-gcc
AS := i686-elf-as
TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))
OUTDIR := $(TOPDIR)out/
.DEFAULT := all

BUILD_TARGETS :=

include $(TOPDIR)/src/Makefile

all: $(BUILD_TARGETS)