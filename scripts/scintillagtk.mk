APPNAME 		= scintilla.a
INCLUDEDIRS 	= -I$(SCINTILLA_SRC)/include -I$(SCINTILLA_SRC)/lexlib -I$(SCINTILLA_SRC)/src
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

CTFLAGS			= -DNDEBUG -Os $(CXXBASEFLAGS) $(THREADFLAGS)
CXXTFLAGS		:= --std=c++0x $(CTFLAGS) $(REFLAGS)
CONFIGFLAGS		:= $(shell pkg-config --cflags $(GTKVERSION))

ifdef PLUGIN_ARCH64
	ARCH_FLAGS 		= -m64
else
	ARCH_FLAGS 		= -m32 -I/usr/lib32/glib-2.0/include
endif


LEXOBJS			:= $(addsuffix .o,$(basename $(notdir $(wildcard $(SCINTILLA_SRC)/lexers/Lex*.cxx))))
MARSHALLER 		= scintilla-marshal.o
OBJNAME 		= Accessor.o CharacterSet.o LexerBase.o LexerModule.o LexerSimple.o \
				  StyleContext.o WordList.o CharClassify.o Decoration.o Document.o \
				  PerLine.o Catalogue.o CallTip.o CaseConvert.o CaseFolder.o ScintillaBase.o \
				  ContractionState.o EditModel.o Editor.o EditView.o ExternalLexer.o \
				  MarginView.o PropSetSimple.o PlatGTK.o KeyMap.o LineMarker.o \
				  PositionCache.o ScintillaGTK.o ScintillaGTKAccessible.o CellBuffer.o \
				  CharacterCategory.o ViewStyle.o RESearch.o RunStyles.o Selection.o Style.o \
				  Indicator.o AutoComplete.o UniConversion.o XPM.o \
				  $(MARSHALLER) $(LEXOBJS)

VPATH 			= $(SCI_BUILD_DIR)
vpath %.cxx $(SCINTILLA_SRC)/src $(SCINTILLA_SRC)/lexlib $(SCINTILLA_SRC)/lexers
vpath %.c $(SCINTILLA_SRC)/gtk
vpath %.cxx $(SCINTILLA_SRC)/gtk

COMPLIB 		= $(addprefix $(SCI_BUILD_DIR)/, $(APPNAME))

all: $(COMPLIB)

$(COMPLIB): $(addprefix $(SCI_BUILD_DIR)/, $(OBJNAME))
	@echo "----------Make static library"
	$(AR) $(ARFLAGS) $@ $^
	$(RANLIB) $@

$(SCI_BUILD_DIR)/%.o: %.c
	@echo "----------Compiling $*"
	$(CC) $(ARCH_FLAGS) $(CONFIGFLAGS) $(CTFLAGS) $(CFLAGS) -w -c $< -o $@

$(SCI_BUILD_DIR)/%.o: %.cxx
	@echo "----------Compiling $*"
	$(CXX) $(ARCH_FLAGS) $(CONFIGFLAGS) $(CXXTFLAGS) $(CXXFLAGS) -c $< -o $@
