#include "modsclex.h"
#include "rb_plugin.h"

// declaration, reserved1, mFlags, attributeCount, attributes
static REALconstant sclexConstants[] = {
    // SCLEX_CONTAINER, SCLEX_AUTOMATIC
    {"Container as Integer = 0", 0, REALScopeProtected},
    {"Automatic as Integer = 1000", 0, REALScopeProtected},

    // LexAsm.cxx; SCLEX_ASM, SCLEX_AS
    {"ASM as Integer = 34", 0, REALScopeProtected},
    {"LexAS as Integer = 113", 0, REALScopeProtected},

    // LexASY.cxx; SCLEX_ASYMPTOTE
    {"Asymptote as Integer = 85", 0, REALScopeProtected},

    // LexBash.cxx; SCLEX_BASH
    {"BASH as Integer = 62", 0, REALScopeProtected},

    // LexBasic.cxx; SCLEX_BLITZBASIC, SCLEX_PUREBASIC, SCLEX_FREEBASIC
    {"BlitzBasic as Integer = 66", 0, REALScopeProtected},
    {"PureBasic as Integer = 67", 0, REALScopeProtected},
    {"FreeBasic as Integer = 75", 0, REALScopeProtected},

    // LexBatch.cxx; SCLEX_BATCH
    {"Batch as Integer = 12", 0, REALScopeProtected},

    // LexBibTeX.cxx; SCLEX_BIBTEX
    {"BibTeX as Integer = 116", 0, REALScopeProtected},

    // LexCmake.cxx; SCLEX_CMAKE
    {"CMake as Integer = 80", 0, REALScopeProtected},

    // LexConf.cxx; SCLEX_CONF
    {"Conf as Integer = 17", 0, REALScopeProtected},

    // LexCPP.cxx; SCLEX_CPP, SCLEX_CPPNOCASE
    {"CPP as Integer = 3", 0, REALScopeProtected},
    {"CPPNoCase as Integer = 35", 0, REALScopeProtected},

    // LexCSS.cxx; SCLEX_CSS
    {"CSS as Integer = 38", 0, REALScopeProtected},

    // LexD.cxx; SCLEX_D
    {"D as Integer = 79", 0, REALScopeProtected},

    // LexDiff.cxx; SCLEX_DIFF
    {"Diff as Integer = 16", 0, REALScopeProtected},

    // LexErrorList.cxx; SCLEX_ERRORLIST
    {"ErrorList as Integer = 10", 0, REALScopeProtected},

    // LexFortran.cxx; SCLEX_FORTRAN, SCLEX_F77
    {"Fortran as Integer = 36", 0, REALScopeProtected},
    {"F77 as Integer = 37", 0, REALScopeProtected},

    // LexHex.cxx; SCLEX_SREC, SCLEX_IHEX, SCLEX_TEHEX
    {"SREC as Integer = 117", 0, REALScopeProtected},
    {"IHex as Integer = 118", 0, REALScopeProtected},
    {"TeHex as Integer = 119", 0, REALScopeProtected},

    // LexHTML.cxx; SCLEX_HTML, SCLEX_XML, SCLEX_PHPSCRIPT
    {"HTML as Integer = 4", 0, REALScopeProtected},
    {"XML as Integer = 5", 0, REALScopeProtected},
    {"PHP as Integer = 69", 0, REALScopeProtected},

    // LexInno.cxx; SCLEX_INNOSETUP
    {"InnoSetup as Integer = 76", 0, REALScopeProtected},

    // LexJSON.cxx; SCLEX_JSON
    {"JSON as Integer = 120", 0, REALScopeProtected},

    // LexLaTeX.cxx; SCLEX_LATEX
    {"LaTeX as Integer = 14", 0, REALScopeProtected},

    // LexMake.cxx; SCLEX_MAKEFILE
    {"Makefile as Integer = 11", 0, REALScopeProtected},

    // LexMarkdown.cxx; SCLEX_MARKDOWN
    {"Markdown as Integer = 98", 0, REALScopeProtected},

    // LexMatlab.cxx; SCLEX_MATLAB, SCLEX_OCTAVE
    {"Matlab as Integer = 32", 0, REALScopeProtected},
    {"Octave as Integer = 54", 0, REALScopeProtected},

    // LexNull.cxx; SCLEX_NULL
    {"Null as Integer = 1", 0, REALScopeProtected},

    // LexPascal.cxx; SCLEX_PASCAL
    {"Pascal as Integer = 18", 0, REALScopeProtected},

    // LexPB.cxx; SCLEX_POWERBASIC
    {"PowerBasic as Integer = 51", 0, REALScopeProtected},

    // LexPerl.cxx; SCLEX_PERL
    {"PERL as Integer = 6", 0, REALScopeProtected},

    // LexProps.cxx; SCLEX_PROPERTIES
    {"Properties as Integer = 9", 0, REALScopeProtected},

    // LexPS.cxx; SCLEX_PS
    {"PS as Integer = 42", 0, REALScopeProtected},

    // LexPython.cxx; SCLEX_PYTHON
    {"Python as Integer = 2", 0, REALScopeProtected},

    // LexRegistry.cxx; SCLEX_REGISTRY
    {"Registry as Integer = 115", 0, REALScopeProtected},

    // LexSQL.cxx; SCLEX_SQL
    {"SQL as Integer = 7", 0, REALScopeProtected},

    // LexTCMD.cxx; SCLEX_TCMD
    {"TCMD as Integer = 103", 0, REALScopeProtected},

    // LexTeX.cxx; SCLEX_TEX
    {"TEX as Integer = 49", 0, REALScopeProtected},

    // LexVB.cxx; SCLEX_VB, SCLEX_VBSCRIPT
    {"VB as Integer = 8", 0, REALScopeProtected},
    {"VBScript as Integer = 28", 0, REALScopeProtected},

    //{"XCode as Integer = 13", 0, REALScopeProtected},
    //{"Lua as Integer = 15", 0, REALScopeProtected},
    //{"Ave as Integer = 19", 0, REALScopeProtected},
    //{"Ada as Integer = 20", 0, REALScopeProtected},
    //{"Lisp as Integer = 21", 0, REALScopeProtected},
    //{"Ruby as Integer = 22", 0, REALScopeProtected},
    //{"Eifel as Integer = 23", 0, REALScopeProtected},
    //{"EifelKW as Integer = 24", 0, REALScopeProtected},
    //{"TCL as Integer = 25", 0, REALScopeProtected},
    //{"nnCronTab as Integer = 26", 0, REALScopeProtected},
    //{"BullAnt as Integer = 27", 0, REALScopeProtected},
    //{"Baan as Integer = 31", 0, REALScopeProtected},
    //{"Scriptol as Integer = 33", 0, REALScopeProtected},
    //{"POV as Integer = 39", 0, REALScopeProtected},
    //{"Lout as Integer = 40", 0, REALScopeProtected},
    //{"eScript as Integer = 41", 0, REALScopeProtected},
    //{"NSIS as Integer = 43", 0, REALScopeProtected},
    //{"MMIXAL as Integer = 44", 0, REALScopeProtected},
    //{"CLW as Integer = 45", 0, REALScopeProtected},
    //{"CLWNoCase as Integer = 46", 0, REALScopeProtected},
    //{"LOT as Integer = 47", 0, REALScopeProtected},
    //{"YAML as Integer = 48", 0, REALScopeProtected},
    //{"Metapost as Integer = 50", 0, REALScopeProtected},
    //{"Forth as Integer = 52", 0, REALScopeProtected},
    //{"Erlang as Integer = 53", 0, REALScopeProtected},
    //{"MSSQL as Integer = 55", 0, REALScopeProtected},
    //{"Verilog as Integer = 56", 0, REALScopeProtected},
    //{"Kix as Integer = 57", 0, REALScopeProtected},
    //{"Gui4CLI as Integer = 58", 0, REALScopeProtected},
    //{"Specman as Integer = 59", 0, REALScopeProtected},
    //{"AU3 as Integer = 60", 0, REALScopeProtected},
    //{"APDL as Integer = 61", 0, REALScopeProtected},
    //{"ASN1 as Integer = 63", 0, REALScopeProtected},
    //{"VHDL as Integer = 64", 0, REALScopeProtected},
    //{"CAML as Integer = 65", 0, REALScopeProtected},
    //{"Haskell as Integer = 68", 0, REALScopeProtected},
    //{"TADS3 as Integer = 70", 0, REALScopeProtected},
    //{"Rebol as Integer = 71", 0, REALScopeProtected},
    //{"SmallTalk as Integer = 72", 0, REALScopeProtected},
    //{"FlagShip as Integer = 73", 0, REALScopeProtected},
    //{"CSound as Integer = 74", 0, REALScopeProtected},
    //{"Opal as Integer = 77", 0, REALScopeProtected},
    //{"Spice as Integer = 78", 0, REALScopeProtected},
    //{"GAP as Integer = 81", 0, REALScopeProtected},
    //{"PLM as Integer = 82", 0, REALScopeProtected},
    //{"Progress as Integer = 83", 0, REALScopeProtected},
    //{"Abaqus as Integer = 84", 0, REALScopeProtected},
    //{"R as Integer = 86", 0, REALScopeProtected},
    //{"Magik as Integer = 87", 0, REALScopeProtected},
    //{"PowerShell as Integer = 88", 0, REALScopeProtected},
    //{"MySQL as Integer = 89", 0, REALScopeProtected},
    //{"PO as Integer = 90", 0, REALScopeProtected},
    //{"TAL as Integer = 91", 0, REALScopeProtected},
    //{"Cobol as Integer = 92", 0, REALScopeProtected},
    //{"TACL as Integer = 93", 0, REALScopeProtected},
    //{"Sorcus as Integer = 94", 0, REALScopeProtected},
    //{"PowerPro as Integer = 95", 0, REALScopeProtected},
    //{"Nimrod as Integer = 96", 0, REALScopeProtected},
    //{"SML as Integer = 97", 0, REALScopeProtected},
    //{"Txt2Tags as Integer = 99", 0, REALScopeProtected},
    //{"A68K as Integer = 100", 0, REALScopeProtected},
    //{"Modula as Integer = 101", 0, REALScopeProtected},
    //{"CoffeScript as Integer = 102", 0, REALScopeProtected},
    //{"AVS as Integer = 104", 0, REALScopeProtected},
    //{"ECL as Integer = 105", 0, REALScopeProtected},
    //{"OSCript as Integer = 106", 0, REALScopeProtected},
    //{"VisualProlog as Integer = 107", 0, REALScopeProtected},
    //{"LiterateHaskell as Integer = 108", 0, REALScopeProtected},
    //{"StTxt as Integer = 109", 0, REALScopeProtected},
    //{"KVIRC as Integer = 110", 0, REALScopeProtected},
    //{"RUST as Integer = 111", 0, REALScopeProtected},
    //{"DMAP as Integer = 112", 0, REALScopeProtected},
    //{"DMIS as Integer = 114", 0, REALScopeProtected},
    //{"EdiFact as Integer = 121", 0, REALScopeProtected},
};

static REALmoduleDefinition modSclex = {
    kCurrentREALControlVersion,                     // version
    "ScLex",                                        // name
    NULL,                                           // methods
    0,                                              // methodCount
    sclexConstants,                                 // constants
    sizeof(sclexConstants) / sizeof(REALconstant),  // constantCount
    NULL,                                           // properties
    0,                                              // propertyCount
    NULL,                                           // structures
    0,                                              // structureCount
    NULL,                                           // enums
    0,                                              // enumCount
};

void registerSclex()
{
    REALRegisterModule(&modSclex);
}
