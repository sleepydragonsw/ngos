TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))

$(OUTDIR)boot.o: $(OUTDIR) $(TOPDIR)boot.s
	$(AS) $(filter %.s,$^) -o $@

$(OUTDIR)kernel.o: $(OUTDIR) $(TOPDIR)kernel.cpp
	$(CXX) -c $(filter %.cpp,$^) -o $@ -std=gnu++11 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

$(OUTDIR)ngos.bin: $(OUTDIR) $(OUTDIR)boot.o $(OUTDIR)kernel.o $(TOPDIR)linker.ld
	$(CXX) -T $(filter %.ld,$^) -o $@ -ffreestanding -O2 -nostdlib $(filter %.o,$^) -lgcc

BUILD_TARGETS += $(OUTDIR)ngos.bin
