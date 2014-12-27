TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))
BUILD_TARGETS += $(OUTDIR)boot.o

$(OUTDIR)boot.o: $(TOPDIR)boot.s
	$(AS) $^ -o $@
