#include "xsintilla.h"
#include "xsi-behaviour.h"
#include "xsi-event.h"
#include "sci-text.h"
#include "sci-styledef.h"
#include "sci-margin.h"
#include "sci-selection.h"
#include "sci-lexer.h"

// group, name, type, flags, getter, setter, param, editor, enumCount, enumEntries, attributeCount, attributes
REALproperty xsiProperties[] = {
    /*
     * sci-text.h
     */
    {
        "", "readonly", "Boolean", REALconsoleSafe | REALpropRuntimeOnly,
        (REALproc)xsip_getReadonly, (REALproc)xsip_setReadonly
    },
    {
        "", "text", "String", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getText, (REALproc)xsip_setText
    },
    /*
     * sci-margin.h
     */
    {
        "", "marginCount", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getMargins, (REALproc)xsip_setMargins
    },
    /*
     * sci-selection.h
     */
    {
        "", "textLength", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getTextLength, REALnoImplementation
    },
    {
        "", "length", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getLength, REALnoImplementation
    },
    {
        "", "lineCount", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getLineCount, REALnoImplementation
    },
    {
        "", "lineOnScreen", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_lineOnScreen, REALnoImplementation
    },
    {
        "", "modified", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getModify, REALnoImplementation
    },
    {
        "", "currentPos", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getCurrentPos, (REALproc)xsip_setCurrentPos
    },
    {
        "", "anchor", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getAnchor, (REALproc)xsip_setAnchor
    },
    {
        "", "selectionStart", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getSelectionStart, (REALproc)xsip_setSelectionStart
    },
    {
        "", "selectionEnd", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getSelectionEnd, (REALproc)xsip_setSelectionEnd
    },
    {
        "", "hideSelection", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly,
        REALnoImplementation, (REALproc)xsip_hideSelection
    },
    {
        "", "seltext", "String", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getSeltext, REALnoImplementation
    },
    {
        "", "selectionIsRectangle", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_selectionIsRectangle, REALnoImplementation
    },

    {
        "", "selectionMode", "Integer", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getSelectionMode, (REALproc)xsip_setSelectionMode
    },
    {
        "", "mouseSelectionRectangularSwitch", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getMouseSelectionRectangularSwitch, (REALproc)xsip_setMouseSelectionRectangularSwitch
    },
    /*
     * sci-selection.h
     */
    {
        "", "lexer", "Sclex", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getLexer, (REALproc)xsip_setLexer
    },
    {
        "", "lexerLanguage", "String", REALconsoleSafe  | REALpropRuntimeOnly,
        (REALproc)xsip_getLexerLanguage, (REALproc)xsip_setLexerLanguage
    },
};

//function, setterFunction, declaration, mFlags, attributeCount, attributes
REALmethodDefinition xsiMethods[] = {
    /*
     * sci-text.h
     */
    { (REALproc) xsim_setSavePoint,             REALnoImplementation, "SetSavePoint()" },
    { (REALproc) xsim_getLine,                  REALnoImplementation, "GetLineText(lineNum as Integer) as String" },
    { (REALproc) xsim_replaceSel,               REALnoImplementation, "ReplaceSel(text as String)" },
    { (REALproc) xsim_allocate,                 REALnoImplementation, "Allocate(bytes as Integer)" },
    { (REALproc) xsim_addText,                  REALnoImplementation, "AddText(length as Integer, text as String)" },
    { (REALproc) xsim_appendText,               REALnoImplementation, "AppendText(length as Integer, text as String)" },
    { (REALproc) xsim_insertText,               REALnoImplementation, "InsertText(pos as Integer, text as String)" },
    { (REALproc) xsim_clearAll,                 REALnoImplementation, "ClearAll()" },
    { (REALproc) xsim_deleteRange,              REALnoImplementation, "DeleteRange(start as Integer, lengthDelete as Integer)" },
    { (REALproc) xsim_clearDocumentStyle,       REALnoImplementation, "ClearDocumentStyle()" },
    { (REALproc) xsim_getCharAt,                REALnoImplementation, "GetCharAt(pos as Integer) as String" },
    { (REALproc) xsim_getStyleAt,               REALnoImplementation, "GetStyleAt(pos as Integer) as Integer" },
    { (REALproc) xsim_releaseAllExtendedStyles, REALnoImplementation, "ReleaseAllExtendedStyle()" },
    { (REALproc) xsim_allocateExtendedStyles,   REALnoImplementation, "AllocateExtendedStyles(numberStyles as Integer) as Integer" },
    /*
     * sci-styledef.h
     */
    { (REALproc) xsim_styleResetDefault,    REALnoImplementation, "StyleResetDefault()" },
    { (REALproc) xsim_styleClearAll,        REALnoImplementation, "StyleClearAll()" },
    { (REALproc) xsim_styleGetFont,         REALnoImplementation, "Font(style as Integer) as String" },
    { (REALproc) xsim_styleSetFont,         REALnoImplementation, "Font(style as Integer, assigns fontName as String)" },
    { (REALproc) xsim_styleGetSize,         REALnoImplementation, "FontSize(style as Integer) as Integer" },
    { (REALproc) xsim_styleSetSize,         REALnoImplementation, "FontSize(style as Integer, assigns sizePoints as Integer)" },
    { (REALproc) xsim_styleGetWeight,       REALnoImplementation, "FontWeight(style as Integer) as Integer" },
    { (REALproc) xsim_styleSetWeight,       REALnoImplementation, "FontWeight(style as Integer, assigns weight as Integer)" },
    { (REALproc) xsim_styleGetFore,         REALnoImplementation, "Forecolor(style as Integer) as Color" },
    { (REALproc) xsim_styleSetFore,         REALnoImplementation, "Forecolor(style as Integer, assigns fore as Color)" },
    { (REALproc) xsim_styleGetBack,         REALnoImplementation, "Backcolor(style as Integer) as Color" },
    { (REALproc) xsim_styleSetBack,         REALnoImplementation, "Backcolor(style as Integer, assigns back as Color)" },
    { (REALproc) xsim_styleGetVisible,      REALnoImplementation, "StyleVisible(style as Integer) as Boolean" },
    { (REALproc) xsim_styleSetVisible,      REALnoImplementation, "StyleVisible(style as Integer, assigns visible as Boolean)" },
    /*
     * sci-margin.h
     */
    { (REALproc) xsim_getMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer, assigns marginType as Integer)" },
    { (REALproc) xsim_getMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer, assigns pixelWidth as Integer)" },
    { (REALproc) xsim_getMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer) as Color" },
    { (REALproc) xsim_setMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer, assigns back as Color)" },
    /*
     * sci-selection.h
     */
    { (REALproc) xsim_setSel,                       REALnoImplementation, "SetSel(anchor as Integer, caret as Integer)" },
    { (REALproc) xsim_gotoPos,                      REALnoImplementation, "GotoPosition(caret as Integer)" },
    { (REALproc) xsim_gotoLine,                     REALnoImplementation, "GotoLine(line as Integer)" },
    { (REALproc) xsim_setEmptySelection,            REALnoImplementation, "EmptySelection(caret as Integer)" },
    { (REALproc) xsim_selectAll,                    REALnoImplementation, "SelectAll()" },
    { (REALproc) xsim_lineFromPosition,             REALnoImplementation, "LineFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_positionFromLine,             REALnoImplementation, "PositionFromLine(line as Integer) as Integer" },
    { (REALproc) xsim_getLineEndPosition,           REALnoImplementation, "LineEndPosition(line as Integer) as Integer" },
    { (REALproc) xsim_lineLength,                   REALnoImplementation, "LineLength(line as Integer) as Integer" },
    { (REALproc) xsim_getColumn,                    REALnoImplementation, "GetColumn(pos as Integer) as Integer" },
    { (REALproc) xsim_findColumn,                   REALnoImplementation, "FindColumn(line as Integer, column as Integer) as Integer" },
    { (REALproc) xsim_positionFromPoint,            REALnoImplementation, "PositionFromPoint(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_positionFromPointClose,       REALnoImplementation, "PositionFromPointClose(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_charPositionFromPoint,        REALnoImplementation, "CharPositionFromPoint(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_charPositionFromPointClose,   REALnoImplementation, "CharPositionFromPointClose(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_pointXFromPosition,           REALnoImplementation, "PointXFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_pointYFromPosition,           REALnoImplementation, "PointYFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_getCurLine,                   REALnoImplementation, "GetCurLineText(length as Integer) as String" },
    { (REALproc) xsim_getLineSelStartPosition,      REALnoImplementation, "GetLineSelStartPosition(line as Integer) as Integer" },
    { (REALproc) xsim_getLineSelEndPosition,        REALnoImplementation, "GetLineSelEndPosition(line as Integer) as Integer" },
    { (REALproc) xsim_moveCaretInsideView,          REALnoImplementation, "MoveCaretInsideView()" },
    { (REALproc) xsim_positionBefore,               REALnoImplementation, "PositionBefore(pos as Integer) as Integer" },
    { (REALproc) xsim_positionAfter,                REALnoImplementation, "PositionAfter(pos as Integer) as Integer" },
    { (REALproc) xsim_positionRelative,             REALnoImplementation, "PositionRelative(pos as Integer, relative as Integer) as Integer" },
    { (REALproc) xsim_countCharacters,              REALnoImplementation, "CountCharacters(posStart as Integer, posEnd as Integer) as Integer" },
    { (REALproc) xsim_textWidth,                    REALnoImplementation, "TextWidth(style as Integer, text as String) as Integer" },
    { (REALproc) xsim_textHeight,                   REALnoImplementation, "TextHeight(line as Integer) as Integer" },
    { (REALproc) xsim_chooseCaretX,                 REALnoImplementation, "ChooseCaretX()" },
    { (REALproc) xsim_moveSelectedLinesUp,          REALnoImplementation, "MoveSelectedLinesUp()" },
    { (REALproc) xsim_moveSelectedLinesDown,        REALnoImplementation, "MoveSelectedLinesDown()" },
    /*
     * sci-lexer.h
     */
    { (REALproc) xsim_colourise,   REALnoImplementation, "Colourise(posStart as Integer, posEnd as Integer)" },
    { (REALproc) xsim_changeLexerState,   REALnoImplementation, "ChangeLexerState(posStart as Integer, posEnd as Integer) as Integer" },
    { (REALproc) xsim_setKeywords,   REALnoImplementation, "SetKeywords(keywordSet as Integer, keywords as String)" },
    { (REALproc) xsim_describeKeywordSets,   REALnoImplementation, "DescribeKeywordSets(description as String) as Integer" },
};

REALevent xsiEvents[] = {
    // declaration, forSystemUse, attributeCount, attributes
    {"StyleNeeded()"},
    {"CharAdded(keyCode as Integer)"},
};

REALcontrolBehaviour xsiBehavior = {
    Constructor,                // constructorFunction
    Destructor,                 // destructorFunction
    NULL,                       // redrawFunction
    NULL,                       // clickFunction
    NULL,                       // mouseDragFunction
    NULL,                       // mouseUpFunction
    NULL,                       // gainedFocusFunction
    NULL,                       // lostFocusFunction
    NULL,                       // keyDownFunction
    OnOpen,                     // openFunction
    NULL,                       // closeFunction
    NULL,                       // backgroundIdleFunction
    OnDrawOffscreen,            // drawOffscreenFunction
    NULL,                       // setSpecialBackground
    NULL,                       // constantChanging
    NULL,                       // droppedNewInstance
    NULL,                       // mouseEnterFunction
    NULL,                       // mouseExitFunction
    NULL,                       // mouseMoveFunction
    OnStateChanged,             // stateChangedFunction
    NULL,                       // actionEventFunction
    NULL,                       // controlHandleGetter
    NULL,                       // mouseWheelFunction
    NULL,                       // enableMenuItemsFunction
    NULL,                       // menuItemActionFunction
    NULL,                       // controlAcceptFocus
    NULL,                       // keyUpFunction
    NULL,                       // redrawWithRectsFunction
    NULL,                       // unfilteredKeyDownFunction
    NULL,                       // scaleFactorChangedFunction
    NULL,                       // reserved2
    NULL                        // reserved3
    // end of struct
};
//declaration, reserved1, mFlags, attributeCount, attributes
REALconstant xsiConstants[] = {
    /*
     * Margin type
     */
    {"kMarginTypeSymbol as Integer = 0"},
    {"kMarginTypeNumber as Integer = 1"},
    {"kMarginTypeBackcolor as Integer = 2"},
    {"kMarginTypeForecolor as Integer = 3"},
    {"kMarginTypeText as Integer = 4"},
    {"kMarginTypeRText as Integer = 5"},
    {"kMarginTypeColour as Integer = 6"},
    /*
     * style definition
     */
    {"kStyleDefault as Integer = 32"},
    {"kStyleLineNumber as Integer = 33"},
    {"kStyleBraceLight as Integer = 34"},
    {"kStyleBraceBad as Integer = 34"},
    {"kStyleControlChar as Integer = 35"},
    {"kStyleIndentGuide as Integer = 36"},
    {"kStyleCalltip as Integer = 37"},
    {"kStyleFoldDisplayText as Integer = 38"},
    {"kStyleLastPredefined as Integer = 39"},
};

REALcontrol xsiControl = {
    kCurrentREALControlVersion,                         // version
    "xsintilla",                                        // name
    sizeof(xsiControlData),                             // dataSize
    0,                                                  // flags
    0,                                                  // toolbarPICT
    0,                                                  // toolbarDownPICT
    100,                                                // defaultWidth
    100,                                                // defaultHeight
    xsiProperties,                                      // properties
    sizeof(xsiProperties)/sizeof(REALproperty),         // propertyCount
    xsiMethods,                                         // methods
    sizeof(xsiMethods)/sizeof(REALmethodDefinition),    // methodCount
    xsiEvents,                                          // events
    sizeof(xsiEvents)/sizeof(REALevent),                // eventCount
    &xsiBehavior,                                       // behaviour
    0,                                                  // forSystemUse, always zero
    NULL,                               // eventInstances
    0,                                  // eventInstanceCount
    NULL,                               // interfaces
    NULL,                               // attributes
    0,                                  // attributeCount
    xsiConstants,                                       // constants
    sizeof(xsiConstants)/sizeof(REALconstant),          // constantCount
#if kCurrentREALControlVersion >= 11
    NULL,                               // sharedProperties
    0,                                  // sharedPropertyCount
    NULL,                               // sharedMethods
    0,                                  // sharedMethodCount
    NULL,                               // delegates
    0,                                  // delegateCount
    NULL,                               // enums
    0,                                  // enumCount
#endif
    // end of structure
};



const char *EnumSclex[] = {
    "Container = 0",
    "Null = 1",
    "Python = 2",
    "CPP = 3",
    "HTML = 4",
    "XML = 5",
    "PERL = 6",
    "SQL = 7",
    "VB = 8",
    "Properties = 9",
    "ErrorList = 10",
    "Makefile = 11",
    "Batch = 12",
    "XCode = 13",
    "LaTeX = 14",
    "Lua = 15",
    "Diff = 16",
    "Conf = 17",
    "Pascal = 18",
    "Ave = 19",
    "Ada = 20",
    "Lisp = 21",
    "Ruby = 22",
    "Eifel = 23",
    "EifelKW = 24",
    "TCL = 25",
    "nnCronTab = 26",
    "BullAnt = 27",
    "VBScript = 28",
    "Baan = 31",
    "Matlab = 32",
    "Scriptol = 33",
    "ASM = 34",
    "CPPNoCase = 35",
    "Fortran = 36",
    "F77 = 37",
    "CSS = 38",
    "POV = 39",
    "Lout = 40",
    "eScript = 41",
    "PS = 42",
    "NSIS = 43",
    "MMIXAL = 44",
    "CLW = 45",
    "CLWNoCase = 46",
    "LOT = 47",
    "YAML = 48",
    "TEX = 49",
    "Metapost = 50",
    "PowerBasic = 51",
    "Forth = 52",
    "Erlang = 53",
    "Octave = 54",
    "MSSQL = 55",
    "Verilog = 56",
    "Kix = 57",
    "Gui4CLI = 58",
    "Specman = 59",
    "AU3 = 60",
    "APDL = 61",
    "BASH = 62",
    "ASN1 = 63",
    "VHDL = 64",
    "CAML = 65",
    "BlitzBasic = 66",
    "PureBasic = 67",
    "Haskell = 68",
    "PHP = 69",
    "TADS3 = 70",
    "Rebol = 71",
    "SmallTalk = 72",
    "FlagShip = 73",
    "CSound = 74",
    "FreeBasic = 75",
    "InnoSetup = 76",
    "Opal = 77",
    "Spice = 78",
    "D = 79",
    "CMake = 80",
    "GAP = 81",
    "PLM = 82",
    "Progress = 83",
    "Abaqus = 84",
    "Asymptote = 85",
    "R = 86",
    "Magik = 87",
    "PowerShell = 88",
    "MySQL = 89",
    "PO = 90",
    "TAL = 91",
    "Cobol = 92",
    "TACL = 93",
    "Sorcus = 94",
    "PowerPro = 95",
    "Nimrod = 96",
    "SML = 97",
    "Markdown = 98",
    "Txt2Tags = 99",
    "A68K = 100",
    "Modula = 101",
    "CoffeScript = 102",
    "TCMD = 103",
    "AVS = 104",
    "ECL = 105",
    "OSCript = 106",
    "VisualProlog = 107",
    "LiterateHaskell = 108",
    "StTxt = 109",
    "KVIRC = 110",
    "RUST = 111",
    "DMAP = 112",
    "LexAS = 113",
    "DMIS = 114",
    "Registry = 115",
    "BibTeX = 116",
    "SREC = 117",
    "IHex = 118",
    "TeHex = 119",
    "JSON = 120",
    "EdiFact = 121",
    "Automatic = 1000",
};

//name, type, mFlags, fields, numFields, attributeCount, attributes
REALenum xsiEnums[] = {
    { "Sclex", NULL, REALScopeGlobal, EnumSclex, 103},
};


REALmoduleDefinition modXsintilla = {
    kCurrentREALControlVersion,         // version
    "ModXsintilla",                     // name
    NULL,                               // methods
    0,                                  // methodCount
    NULL,                               // constants
    0,                                  // constantCount
    NULL,                               // properties
    0,                                  // propertyCount
    NULL,                               // structures
    0,                                  // structureCount
    xsiEnums,                           // enums
    sizeof(xsiEnums)/sizeof(REALenum),  // enumCount
};


void PluginEntry()
{
    REALRegisterModule(&modXsintilla);
    REALRegisterControl(&xsiControl);
}
