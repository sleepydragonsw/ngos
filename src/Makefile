TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))

$(OUTDIR)boot.o: $(OUTDIR) $(TOPDIR)boot.s
	$(AS) $(filter %.s,$^) -o $@

$(OUTDIR)kernel.o: $(OUTDIR) $(TOPDIR)kernel.c
	$(CC) -c $(filter %.c,$^) -o $@ -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$(OUTDIR)ngos.bin: $(OUTDIR) $(OUTDIR)boot.o $(OUTDIR)kernel.o $(TOPDIR)linker.ld
	$(CC) -T $(filter %.ld,$^) -o $@ -ffreestanding -O2 -nostdlib $(filter %.o,$^) -lgcc

BUILD_TARGETS += $(OUTDIR)ngos.bin
