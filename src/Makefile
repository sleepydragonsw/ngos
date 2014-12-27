TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))

$(OUTDIR)boot.o: $(TOPDIR)boot.s
	$(AS) $^ -o $@

$(OUTDIR)kernel.o: $(TOPDIR)kernel.c
	$(CC) -c $^ -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$(OUTDIR)ngos.bin: $(OUTDIR)boot.o $(OUTDIR)kernel.o $(TOPDIR)linker.ld
	$(CC) -T $(filter %.ld,$^) -o $@ -ffreestanding -O2 -nostdlib $(filter %.o,$^) -lgcc

BUILD_TARGETS += $(OUTDIR)ngos.bin
