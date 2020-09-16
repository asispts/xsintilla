export PLUGIN_ARCH32 	= 64
export BUILD_DIR 		= $(BUILD_ROOT)/Linux-X86-64
export LIB_DIR 			= $(OUTPUT_DIR)/Linux-X86-64
export SCI_BUILD_DIR 	= $(BUILD_DIR)/scintilla_$(SCI_VERSION)

all: makedir
	@echo "***Building library:[ scintilla - linux-x86_64 release ]***"
	$(MAKE) -f scripts/scintillagtk.mk
	@echo "***Building plugin:[ xsintilla - linux-x86_64 release ]***"
	$(MAKE) -f scripts/makeplugin-linux.mk

makedir:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(LIB_DIR)
	mkdir -p $(SCI_BUILD_DIR)

clean:
	rm -rvf $(BUILD_DIR)/*.o
	rm -rvf $(LIB_DIR)/*.so
