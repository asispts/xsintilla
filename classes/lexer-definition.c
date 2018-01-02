#include "lexer-definition.h"
#include "lexer.h"
#include "xsintilla.h"

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
REALproperty LexerPropDef[] = {
    {"", "lexer", "eLexer", REALpropRuntimeOnly, (REALproc)lexer_getLexer, (REALproc)lexer_setLexer},
    {"", "language", "String", REALpropRuntimeOnly, (REALproc)lexer_getLexerLanguage, (REALproc)lexer_setLexerLanguage},
};

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
REALmethodDefinition LexerMethodDef[] = {
    {(REALproc)lexer_colourise, REALnoImplementation, "Colourise(posStart as Integer, posEnd as Integer)"},
    {(REALproc)lexer_changeLexerState, REALnoImplementation,
     "ChangeState(posStart as Integer, posEnd as Integer) as Integer"},
    {(REALproc)lexer_setKeywords, REALnoImplementation, "SetKeywords(keywordSet as Integer, keywords as String)"},
    {(REALproc)lexer_describeKeywordSets, REALnoImplementation,
     "DescribeKeywordSets(description as String) as Integer"},
    {(REALproc)lexer_getProperty, REALnoImplementation, "GetProperty(key as String) as String"},
    {(REALproc)lexer_setProperty, REALnoImplementation, "SetProperty(key as String, value as String)"},
    {(REALproc)lexer_loadLexerLibrary, REALnoImplementation, "LoadLibrary(path as String)"},
    {(REALproc)lexer_propertyNames, REALnoImplementation, "PropertyNames() as String"},
    {(REALproc)lexer_propertyType, REALnoImplementation, "PropertyType(name as String) as Integer"},
    {(REALproc)lexer_describeProperty, REALnoImplementation, "DescribeProperty(name as String) as String"},
    {(REALproc)lexer_getPropertyExpanded, REALnoImplementation,
     "GetPropertyExpanded(key as String, value as String) as Integer"},
    {(REALproc)lexer_getPropertyInt, REALnoImplementation,
     "GetPropertyInt(key as String, defaultValue as Integer) as Integer"},
    {(REALproc)lexer_getSubstyleBases, REALnoImplementation, "GetSubstyleBases() as String"},
    {(REALproc)lexer_distanceToSecondaryStyles, REALnoImplementation, "DistanceToSecondaryStyles() as Integer"},
    {(REALproc)lexer_allocateSubstyles, REALnoImplementation,
     "AllocateSubstyles(styleBase as Integer, numStyles as Integer) as Integer"},
    {(REALproc)lexer_freeSubstyles, REALnoImplementation, "FreeSubstyles()"},
    {(REALproc)lexer_getSubstylesStart, REALnoImplementation, "GetSubstylesStart(styleBase as Integer) as Integer"},
    {(REALproc)lexer_getSubstylesLength, REALnoImplementation, "GetSubstylesLength(styleBase as Integer) as Integer"},
    {(REALproc)lexer_getStyleFromSubstyle, REALnoImplementation,
     "GetStyleFromSubstyle(subStyle as Integer) as Integer"},
    {(REALproc)lexer_getPrimaryStyleFromStyle, REALnoImplementation,
     "GetPrimaryStyleFromStyle(style as Integer) as Integer"},
    {(REALproc)lexer_setIdentifiers, REALnoImplementation, "SetIdentifiers(style as Integer, id as Integer)"},
    {(REALproc)lexer_privateLexerCall, REALnoImplementation,
     "PrivateLexerCall(operation as Integer, pointer as Integer) as Integer"},
};

//+++++++++++++++++++++++++++++++++
static const char* enumLexer[] = {
    "CONTAINER = 0",          // SCLEX_CONTAINER 0
    "NULL = 1",               // SCLEX_NULL 1
    "PYTHON = 2",             // SCLEX_PYTHON 2
    "CPP = 3",                // SCLEX_CPP 3
    "HTML = 4",               // SCLEX_HTML 4
    "XML = 5",                // SCLEX_XML 5
    "PERL = 6",               // SCLEX_PERL 6
    "SQL = 7",                // SCLEX_SQL 7
    "VB = 8",                 // SCLEX_VB 8
    "PROPERTIES = 9",         // SCLEX_PROPERTIES 9
    "ERRORLIST = 10",         // SCLEX_ERRORLIST 10
    "MAKEFILE = 11",          // SCLEX_MAKEFILE 11
    "BATCH = 12",             // SCLEX_BATCH 12
    "XCODE = 13",             // SCLEX_XCODE 13
    "LATEX = 14",             // SCLEX_LATEX 14
    "LUA = 15",               // SCLEX_LUA 15
    "DIFF = 16",              // SCLEX_DIFF 16
    "CONF = 17",              // SCLEX_CONF 17
    "PASCAL = 18",            // SCLEX_PASCAL 18
    "AVE = 19",               // SCLEX_AVE 19
    "ADA = 20",               // SCLEX_ADA 20
    "LISP = 21",              // SCLEX_LISP 21
    "RUBY = 22",              // SCLEX_RUBY 22
    "EIFFEL = 23",            // SCLEX_EIFFEL 23
    "EIFFELKW = 24",          // SCLEX_EIFFELKW 24
    "TCL = 25",               // SCLEX_TCL 25
    "NNCRONTAB = 26",         // SCLEX_NNCRONTAB 26
    "BULLANT = 27",           // SCLEX_BULLANT 27
    "VBSCRIPT = 28",          // SCLEX_VBSCRIPT 28
    "BAAN = 31",              // SCLEX_BAAN 31
    "MATLAB = 32",            // SCLEX_MATLAB 32
    "SCRIPTOL = 33",          // SCLEX_SCRIPTOL 33
    "ASM = 34",               // SCLEX_ASM 34
    "CPPNOCASE = 35",         // SCLEX_CPPNOCASE 35
    "FORTRAN = 36",           // SCLEX_FORTRAN 36
    "F77 = 37",               // SCLEX_F77 37
    "CSS = 38",               // SCLEX_CSS 38
    "POV = 39",               // SCLEX_POV 39
    "LOUT = 40",              // SCLEX_LOUT 40
    "ESCRIPT = 41",           // SCLEX_ESCRIPT 41
    "PS = 42",                // SCLEX_PS 42
    "NSIS = 43",              // SCLEX_NSIS 43
    "MMIXAL = 44",            // SCLEX_MMIXAL 44
    "CLW = 45",               // SCLEX_CLW 45
    "CLWNOCASE = 46",         // SCLEX_CLWNOCASE 46
    "LOT = 47",               // SCLEX_LOT 47
    "YAML = 48",              // SCLEX_YAML 48
    "TEX = 49",               // SCLEX_TEX 49
    "METAPOST = 50",          // SCLEX_METAPOST 50
    "POWERBASIC = 51",        // SCLEX_POWERBASIC 51
    "FORTH = 52",             // SCLEX_FORTH 52
    "ERLANG = 53",            // SCLEX_ERLANG 53
    "OCTAVE = 54",            // SCLEX_OCTAVE 54
    "MSSQL = 55",             // SCLEX_MSSQL 55
    "VERILOG = 56",           // SCLEX_VERILOG 56
    "KIX = 57",               // SCLEX_KIX 57
    "GUI4CLI = 58",           // SCLEX_GUI4CLI 58
    "SPECMAN = 59",           // SCLEX_SPECMAN 59
    "AU3 = 60",               // SCLEX_AU3 60
    "APDL = 61",              // SCLEX_APDL 61
    "BASH = 62",              // SCLEX_BASH 62
    "ASN1 = 63",              // SCLEX_ASN1 63
    "VHDL = 64",              // SCLEX_VHDL 64
    "CAML = 65",              // SCLEX_CAML 65
    "BLITZBASIC = 66",        // SCLEX_BLITZBASIC 66
    "PUREBASIC = 67",         // SCLEX_PUREBASIC 67
    "HASKELL = 68",           // SCLEX_HASKELL 68
    "PHPSCRIPT = 69",         // SCLEX_PHPSCRIPT 69
    "TADS3 = 70",             // SCLEX_TADS3 70
    "REBOL = 71",             // SCLEX_REBOL 71
    "SMALLTALK = 72",         // SCLEX_SMALLTALK 72
    "FLAGSHIP = 73",          // SCLEX_FLAGSHIP 73
    "CSOUND = 74",            // SCLEX_CSOUND 74
    "FREEBASIC = 75",         // SCLEX_FREEBASIC 75
    "INNOSETUP = 76",         // SCLEX_INNOSETUP 76
    "OPAL = 77",              // SCLEX_OPAL 77
    "SPICE = 78",             // SCLEX_SPICE 78
    "D = 79",                 // SCLEX_D 79
    "CMAKE = 80",             // SCLEX_CMAKE 80
    "GAP = 81",               // SCLEX_GAP 81
    "PLM = 82",               // SCLEX_PLM 82
    "PROGRESS = 83",          // SCLEX_PROGRESS 83
    "ABAQUS = 84",            // SCLEX_ABAQUS 84
    "ASYMPTOTE = 85",         // SCLEX_ASYMPTOTE 85
    "R = 86",                 // SCLEX_R 86
    "MAGIK = 87",             // SCLEX_MAGIK 87
    "POWERSHELL = 88",        // SCLEX_POWERSHELL 88
    "MYSQL = 89",             // SCLEX_MYSQL 89
    "PO = 90",                // SCLEX_PO 90
    "TAL = 91",               // SCLEX_TAL 91
    "COBOL = 92",             // SCLEX_COBOL 92
    "TACL = 93",              // SCLEX_TACL 93
    "SORCUS = 94",            // SCLEX_SORCUS 94
    "POWERPRO = 95",          // SCLEX_POWERPRO 95
    "NIMROD = 96",            // SCLEX_NIMROD 96
    "SML = 97",               // SCLEX_SML 97
    "MARKDOWN = 98",          // SCLEX_MARKDOWN 98
    "TXT2TAGS = 99",          // SCLEX_TXT2TAGS 99
    "A68K = 100",             // SCLEX_A68K 100
    "MODULA = 101",           // SCLEX_MODULA 101
    "COFFEESCRIPT = 102",     // SCLEX_COFFEESCRIPT 102
    "TCMD = 103",             // SCLEX_TCMD 103
    "AVS = 104",              // SCLEX_AVS 104
    "ECL = 105",              // SCLEX_ECL 105
    "OSCRIPT = 106",          // SCLEX_OSCRIPT 106
    "VISUALPROLOG = 107",     // SCLEX_VISUALPROLOG 107
    "LITERATEHASKELL = 108",  // SCLEX_LITERATEHASKELL 108
    "STTXT = 109",            // SCLEX_STTXT 109
    "KVIRC = 110",            // SCLEX_KVIRC 110
    "RUST = 111",             // SCLEX_RUST 111
    "DMAP = 112",             // SCLEX_DMAP 112
    "AS_LEX = 113",           // SCLEX_AS 113
    "DMIS = 114",             // SCLEX_DMIS 114
    "REGISTRY = 115",         // SCLEX_REGISTRY 115
    "BIBTEX = 116",           // SCLEX_BIBTEX 116
    "SREC = 117",             // SCLEX_SREC 117
    "IHEX = 118",             // SCLEX_IHEX 118
    "TEHEX = 119",            // SCLEX_TEHEX 119
    "JSON = 120",             // SCLEX_JSON 120
    "EDIFACT = 121",          // SCLEX_EDIFACT 121
    "INDENT = 122",           // SCLEX_INDENT 122
    "AUTOMATIC = 1000",       // SCLEX_AUTOMATIC 1000
};

REALenum xsiLexerEnumDef[] = {
    // name, type, mFlags, fields, numFields, attributeCount, attributes
    {"eLexer", "Integer", REALScopePublic, enumLexer, 122},
};

//+++++++++++++++++++++++++++++++++
// Class Definition
//+++++++++++++++++++++++++++++++++
REALclassDefinition xsiLexerDef = {
    kCurrentREALControlVersion,                             // version
    "xsiLexer",                                             // name
    NULL,                                                   // superName
    sizeof(xsiLexerData),                                   // dataSize
    0,                                                      // forSystemUse
    NULL,                                                   // constructor
    NULL,                                                   // destructor
    LexerPropDef,                                           // properties
    sizeof(LexerPropDef) / sizeof(REALproperty),            // propertyCount
    LexerMethodDef,                                         // methods
    sizeof(LexerMethodDef) / sizeof(REALmethodDefinition),  // methodCount
    NULL,                                                   // events
    0,                                                      // eventCount
    NULL,                                                   // eventInstances
    0,                                                      // eventInstanceCount
    NULL,                                                   // interfaces
    NULL,                                                   // attributes
    0,                                                      // attributeCount
    NULL,                                                   // constants
    0,                                                      // constantCount
    0,                                                      // mFlags
    NULL,                                                   // sharedProperties
    0,                                                      // sharedPropertyCount
    NULL,                                                   // sharedMethods
    0,                                                      // sharedMethodCount; // End RB2006r4 stuff
#if kCurrentREALControlVersion >= 11
    NULL,                                        // delegates
    0,                                           // delegateCount
    xsiLexerEnumDef,                             // enums
    sizeof(xsiLexerEnumDef) / sizeof(REALenum),  // enumCount
#endif
};

void registerClassLexer(void)
{
    REALRegisterClass(&xsiLexerDef);
}
