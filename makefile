export MAKEFLAGS 	   += --silent
export SCI_VERSION 		= 371
export APPNAME 			= xsintilla

export BUILD_ROOT		= ./build
export OUTPUT_DIR		= ./dist

export SRC_DIR			= ./src
export VENDOR_DIR		= ./vendor
export SCINTILLA_SRC	= $(VENDOR_DIR)/scintilla


all: makedir
	$(MAKE) -f scripts/linux32.mk
	@echo "******"
	@echo "******"
	$(MAKE) -f scripts/linux64.mk
	@echo "******"
	@echo "DONE."

makedir:
	mkdir -p $(BUILD_ROOT)
	mkdir -p $(OUTPUT_DIR)

clean:
	$(MAKE) -f scripts/linux32.mk clean
	$(MAKE) -f scripts/linux64.mk clean
