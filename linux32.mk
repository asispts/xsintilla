export PLUGIN_ARCH32 	= 32
export BUILDDIR 		= $(BUILDROOT)/Linux-X86
export LIBDIR 			= $(LIBROOT)/Linux-X86
export SCIBUILD 		= $(BUILDDIR)/scintilla_$(SCIVERSION)

all: makedir
	@echo "***Building library:[ scintilla - linux-x86 release ]***"
	$(MAKE) -f scintillagtk.mk
	@echo "***Building plugin:[ xsintilla - linux-x86 release ]***"
	$(MAKE) -f makeplugin-linux.mk

makedir:
	mkdir -p $(BUILDDIR)
	mkdir -p $(LIBDIR)
	mkdir -p $(SCIBUILD)

clean:
	rm -rvf $(BUILDDIR)/*.o
	rm -rvf $(LIBDIR)/*.so
