TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))

$(OUTDIR)boot.o: $(TOPDIR)boot.s
	$(AS) $(filter %.s,$^) -o $@

$(OUTDIR)kernel.o: $(TOPDIR)kernel.cpp $(TOPDIR)vga.h
	$(CXX) -c $(filter %.cpp,$^) -o $@ $(CXXFLAGS)

$(OUTDIR)vga.o: $(TOPDIR)vga.cpp $(TOPDIR)vga.h
	$(CXX) -c $(filter %.cpp,$^) -o $@ $(CXXFLAGS)

$(OUTDIR)crti.o: $(TOPDIR)crti.s
	$(AS) $(filter %.s,$^) -o $@

$(OUTDIR)crtn.o: $(TOPDIR)crtn.s
	$(AS) $(filter %.s,$^) -o $@

CRTBEGIN_O := $(shell $(CXX) $(CXXFLAGS) -print-file-name=crtbegin.o)
CRTEND_O := $(shell $(CXX) $(CXXFLAGS) -print-file-name=crtend.o)

NGOS_OBJ_FILES := \
    $(OUTDIR)boot.o \
    $(OUTDIR)kernel.o \
    $(OUTDIR)vga.o \

# NOTE: The order of the .o files in this list is EXTREMELY important
NGOS_OBJ_FILES_WITH_CRT := \
    $(OUTDIR)crti.o \
    $(CRTBEGIN_O) \
    $(NGOS_OBJ_FILES) \
    $(CRTEND_O) \
    $(OUTDIR)crtn.o \

$(OUTDIR)ngos.bin: $(NGOS_OBJ_FILES_WITH_CRT) $(TOPDIR)linker.ld 
	$(CXX) -T $(TOPDIR)linker.ld -o $@ $(NGOS_OBJ_FILES_WITH_CRT) $(CXXFLAGS) -nostdlib -lgcc

BUILD_TARGETS += $(OUTDIR)ngos.bin
