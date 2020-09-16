export LIBXOJO_DIR		= $(SRC_DIR)/libxojo
export CONTROL_DIR		= $(SRC_DIR)/control
export API_DIR			= $(SRC_DIR)/api
export CONSTANTS_DIR	= $(SRC_DIR)/constants

##
# plugin directories definition
export SDK_PLUGIN 		= $(VENDOR_DIR)/PluginsSDK
export SDK_GLUECODE 	= $(SDK_PLUGIN)/GlueCode
export SDK_INCLUDES 	= $(SDK_PLUGIN)/Includes
export SDK_PREFIXHEADER = $(SDK_INCLUDES)/LinuxHeader.h



VPATH 				= $(BUILD_DIR)
vpath %.c $(SRC_DIR) $(LIBXOJO_DIR) $(CONTROL_DIR) $(API_DIR) $(CONSTANTS_DIR)
vpath %.cpp $(SDK_GLUECODE)

OBJNAME 			= 	PluginMain.o main.o XojoGraphics.o \
						xsintilla.o behaviour.o event.o definition.o \
						api_error.o api_event.o api_lexer.o api_margin.o \
						api_selection.o api_style.o api_styling.o api_text.o \
						lexerconst.o lexhtmlconst.o \

INCLUDES 			= -include $(SDK_PREFIXHEADER) -I$(SDK_INCLUDES) -I$(LIBXOJO_DIR) -I$(CONTROL_DIR) -I$(API_DIR) -I$(CONSTANTS_DIR)
DEBUGGING_FLAGS		= -g -O0

ifdef PLUGIN_ARCH64
	ARCH_FLAGS 			= -m64
else
	ARCH_FLAGS 			= -m32 -I/usr/lib32/glib-2.0/include
endif

# Enable Position Independent Code except on Windows where it is the default so the flag produces a warning
ifndef windir
	PIC_FLAGS 			= -fPIC
endif

DEPRECATED			= -DGDK_PIXBUF_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -DDISABLE_GDK_FONT
SCINTILLA_INCLUDE 	= -I$(SCINTILLA_SRC)/include
SCINTILLA_FLAGS 	= -DGTK -DSCI_LEXER `pkg-config --cflags gtk+-2.0` $(SCINTILLA_INCLUDE)
PLUGIN_FLAGS 		= -DIGNOREQT -D__INTEL__ -DLINUX=1 -D__GCC__

CC 					= gcc
CXX 				= g++
C_FLAGS 			= -Wall $(DEBUGGING_FLAGS) $(ARCH_FLAGS) $(PIC_FLAGS) $(INCLUDES) $(DEPRECATED)
CXX_FLAGS 			= --std=c++0x -Wall $(DEBUGGING_FLAGS) $(ARCH_FLAGS) $(PIC_FLAGS) $(INCLUDES) $(DEPRECATED)
LD_LIBS 			= -lstdc++ -lm -lgmodule-2.0 `pkg-config --libs gtk+-2.0`

LEXER_OBJS 			= $(wildcard $(SCI_BUILD_DIR)/Lex*.o)
SCINTILLA_ARCHIVE 	= $(SCI_BUILD_DIR)/scintilla.a
PLUGIN 				= $(addprefix $(LIB_DIR)/, $(APPNAME).so)


all: $(PLUGIN)

$(PLUGIN): $(addprefix $(BUILD_DIR)/, $(OBJNAME)) $(LEXER_OBJS) $(SCINTILLA_ARCHIVE)
	@echo "----------Building"
	$(CC) $(C_FLAGS) $(PLUGIN_FLAGS) $(SCINTILLA_FLAGS) -shared -Wl,--no-undefined -o $@ $^ $(LD_LIBS)

$(BUILD_DIR)/%.o: %.c
	@echo "----------Compiling $*"
	$(CC) $(C_FLAGS) $(PLUGIN_FLAGS) $(SCINTILLA_FLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp
	@echo "----------Compiling $*"
	$(CXX) $(CXX_FLAGS) $(PLUGIN_FLAGS) $(SCINTILLA_FLAGS) -c $< -o $@
