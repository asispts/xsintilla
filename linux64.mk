export PLUGIN_ARCH64 	= 64
export BUILDDIR 		= $(BUILDROOT)/Linux-x86-64
export LIBDIR 			= $(LIBROOT)/Linux-x86-64
export SCIBUILD 		= $(BUILDDIR)/scintilla_$(SCIVERSION)

all: makedir
	@echo "***Building library:[ scintilla - linux-x86_64 release ]***"
	$(MAKE) -f scintillagtk.mk
	@echo "***Building plugin:[ xsintilla - linux-x86_64 release ]***"
	$(MAKE) -f makeplugin-linux.mk

makedir:
	mkdir -p $(BUILDDIR)
	mkdir -p $(LIBDIR)
	mkdir -p $(SCIBUILD)

clean:
	rm -rvf $(BUILDDIR)/*.o
	rm -rvf $(LIBDIR)/*.so
