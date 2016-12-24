VPATH 				= $(BUILDDIR)
vpath %.c $(SRCROOT) $(LIBXOJO) $(LIBXSINTILLA)
vpath %.cpp $(SDKGLUECODEDIR)


OBJNAME 			= PluginMain.o main.o xsintilla.o xsi-behaviour.o xsi-event.o\
						XojoGraphics.o \
						sci-text.o sci-styledef.o


INCLUDES 			= -I$(SDKINCLUDEDIR) -I$(LIBXOJO) -I$(LIBXSINTILLA) -include $(PREFIXHEADER)
ifdef PLUGIN_ARCH64
ARCH_FLAGS 			= -m64
else
ARCH_FLAGS 			= -m32 -I/usr/lib32/glib-2.0/include
endif
# Enable Position Independent Code except on Windows where it is the default so the flag produces a warning
ifndef windir
PICFLAGS 			= -fPIC
endif
DEPRECATED			= -DGDK_PIXBUF_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -DDISABLE_GDK_FONT
SCININCLUDEDIRS 	= -I$(SCIDIR)/include
SCINTILLAFLAGS 		= -DGTK -DSCI_LEXER `pkg-config --cflags gtk+-2.0` $(SCININCLUDEDIRS)
PLUGINFLAGS 		= -DIGNOREQT -D__INTEL__ -DLINUX=1 -D__GCC__

CC 					= codelite-cc gcc
CXX 				= codelite-cc g++
CFLAGS 				= -Wall -g -O0 $(ARCH_FLAGS) $(PICFLAGS) $(INCLUDES) $(DEPRECATED)
CXXFLAGS 			= -Wall -g -O0 $(ARCH_FLAGS) $(PICFLAGS) $(INCLUDES) $(DEPRECATED)
LDLIBS 				= -lstdc++ -lm -lgmodule-2.0 `pkg-config --libs gtk+-2.0`
$(BUILDDIR)/%.o: %.c
	@echo "----------Compiling $*"
	$(CC) $(CFLAGS) $(PLUGINFLAGS) $(SCINTILLAFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: %.cpp
	@echo "----------Compiling $*"
	$(CXX) $(CXXFLAGS) $(PLUGINFLAGS) $(SCINTILLAFLAGS) -c $< -o $@

LEXEROBJS 			= $(wildcard $(SCIBUILD)/Lex*.o)
ARSCINTILLA 		= $(SCIBUILD)/scintilla.a
PLUGIN 				= $(addprefix $(LIBDIR)/, $(APPNAME))

all: $(PLUGIN)

$(PLUGIN): $(addprefix $(BUILDDIR)/, $(OBJNAME)) $(LEXEROBJS) $(ARSCINTILLA)
	@echo "----------Building"
	$(CC) $(CFLAGS) $(PLUGINFLAGS) $(SCINTILLAFLAGS) -shared -Wl,--no-undefined -o $@ $^ $(LDLIBS)
