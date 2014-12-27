TOPDIR := $(dir $(lastword $(MAKEFILE_LIST)))

$(OUTDIR)boot.o: $(OUTDIR) $(TOPDIR)boot.s
	$(AS) $(filter %.s,$^) -o $@

$(OUTDIR)kernel.o: $(OUTDIR) $(TOPDIR)kernel.cpp
	$(CXX) -c $(filter %.cpp,$^) -o $@ $(CXXFLAGS)

$(OUTDIR)ngos.bin: $(OUTDIR) $(OUTDIR)boot.o $(OUTDIR)kernel.o $(TOPDIR)linker.ld
	$(CXX) -T $(filter %.ld,$^) -o $@ $(LDFLAGS) $(filter %.o,$^)

BUILD_TARGETS += $(OUTDIR)ngos.bin
