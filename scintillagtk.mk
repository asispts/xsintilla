INCLUDEDIRS 	= -I$(SCIDIR)/include -I$(SCIDIR)/lexlib -I$(SCIDIR)/src

APPNAME 		= scintilla.a

.SUFFIXES: .cxx .c .o .h .a .list
ifdef CLANG
CXX 			= clang++ -Wno-deprecated-register
CC 				= clang
# Can choose aspect to sanitize: address and undefined can simply change SANITIZE but for
# thread also need to create Position Independent Executable -> search online documentation
SANITIZE 		= address
endif
ARFLAGS 		= rc
RANLIB 			= touch

ifdef GTK3
GTKVERSION		= gtk+-3.0
else
GTKVERSION		= gtk+-2.0
endif

# Environment variable windir always defined on Win32
ifndef windir
ifeq ($(shell uname),Darwin)
RANLIB 			= ranlib
endif
endif

# Enable Position Independent Code except on Windows where it is the default so the flag produces a warning
ifndef windir
PICFLAGS 		= -fPIC
endif

ifdef CHECK_DEPRECATED
DEPRECATED		= -DGDK_PIXBUF_DISABLE_DEPRECATED -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED -DDISABLE_GDK_FONT
endif
CXXBASEFLAGS	= -Wall -pedantic $(PICFLAGS) -DGTK -DSCI_LEXER $(INCLUDEDIRS) $(DEPRECATED)


ifdef NOTHREADS
THREADFLAGS		= -DG_THREADS_IMPL_NONE
else
THREADFLAGS		=
endif

ifdef NO_CXX11_REGEX
REFLAGS			= -DNO_CXX11_REGEX
endif

ifdef DEBUG
ifdef CLANG
CTFLAGS			= -DDEBUG -g -fsanitize=$(SANITIZE) $(CXXBASEFLAGS) $(THREADFLAGS)
else
CTFLAGS			= -DDEBUG -g $(CXXBASEFLAGS) $(THREADFLAGS)
endif
else
CTFLAGS			= -DNDEBUG -Os $(CXXBASEFLAGS) $(THREADFLAGS)
endif
#--std=gnu++0x
CXXTFLAGS:=--std=c++0x $(CTFLAGS) $(REFLAGS)
CONFIGFLAGS:=$(shell pkg-config --cflags $(GTKVERSION))

ifdef PLUGIN_ARCH64
ARCH_FLAGS 		= -m64
else
ARCH_FLAGS 		= -m32 -I/usr/lib32/glib-2.0/include
endif

LEXOBJS:=$(addsuffix .o,$(basename $(notdir $(wildcard $(SCIDIR)/lexers/Lex*.cxx))))
MARSHALLER 		= scintilla-marshal.o
OBJNAME = Accessor.o CharacterSet.o LexerBase.o LexerModule.o LexerSimple.o \
	StyleContext.o WordList.o CharClassify.o Decoration.o Document.o \
	PerLine.o Catalogue.o CallTip.o CaseConvert.o CaseFolder.o ScintillaBase.o \
	ContractionState.o EditModel.o Editor.o EditView.o ExternalLexer.o \
	MarginView.o PropSetSimple.o PlatGTK.o KeyMap.o LineMarker.o \
	PositionCache.o ScintillaGTK.o ScintillaGTKAccessible.o CellBuffer.o \
	CharacterCategory.o ViewStyle.o RESearch.o RunStyles.o Selection.o Style.o \
	Indicator.o AutoComplete.o UniConversion.o XPM.o \
	$(MARSHALLER) $(LEXOBJS)

VPATH 			= $(SCIBUILD)
vpath %.cxx $(SCIDIR)/src $(SCIDIR)/lexlib $(SCIDIR)/lexers

vpath %.c $(SCIDIR)/gtk
vpath %.cxx $(SCIDIR)/gtk

$(SCIBUILD)/%.o: %.c
	@echo "----------Compiling $*"
	$(CC) $(ARCH_FLAGS) $(CONFIGFLAGS) $(CTFLAGS) $(CFLAGS) -w -c $< -o $@

$(SCIBUILD)/%.o: %.cxx
	@echo "----------Compiling $*"
	$(CXX) $(ARCH_FLAGS) $(CONFIGFLAGS) $(CXXTFLAGS) $(CXXFLAGS) -c $< -o $@


COMPLIB 		= $(addprefix $(SCIBUILD)/, $(APPNAME))
all: $(COMPLIB)

$(COMPLIB): $(addprefix $(SCIBUILD)/, $(OBJNAME))
	@echo "----------Make static library"
	$(AR) $(ARFLAGS) $@ $^
	$(RANLIB) $@
