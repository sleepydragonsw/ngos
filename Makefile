# Specify the "all" build target first so that it is the default;
# it is overridden later
all:

CXX := i686-elf-g++
CXXFLAGS := -masm=intel -std=gnu++11 -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti
AS := i686-elf-as
TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))
OUTDIR := $(TOPDIR)out/

BUILD_TARGETS :=

include $(TOPDIR)/src/Makefile

$(OUTDIR):
	mkdir --parents $(OUTDIR)

all: $(OUTDIR) $(BUILD_TARGETS)

clean:
	rm -rf $(OUTDIR)
