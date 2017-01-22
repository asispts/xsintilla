#include "modenums.h"
#include "rb_plugin.h"

static const char *EnumMarginType[] = {
    "Symbol = 0",     //SC_MARGIN_SYMBOL 0
    "Number = 1",     //SC_MARGIN_NUMBER 1
    "Backcolor = 2",  //SC_MARGIN_BACK 2
    "Forecolor = 3",  //SC_MARGIN_FORE 3
    "Text = 4",       //SC_MARGIN_TEXT 4
    "RText = 5",      //SC_MARGIN_RTEXT 5
    "Colour = 6",     //SC_MARGIN_COLOUR 6
};

static const char *EnumMarker[] = {
    "Circle = 0",                  //SC_MARK_CIRCLE 0
    "RoundRect = 1",               //SC_MARK_ROUNDRECT 1
    "Arrow = 2",                   //SC_MARK_ARROW 2
    "SmallRect = 3",               //SC_MARK_SMALLRECT 3
    "ShortArrow = 4",              //SC_MARK_SHORTARROW 4
    "Empty = 5",                   //SC_MARK_EMPTY 5
    "ArrowDown = 6",               //SC_MARK_ARROWDOWN 6
    "Minus = 7",                   //SC_MARK_MINUS 7
    "Plus = 8",                    //SC_MARK_PLUS 8
    "Vline = 9",                   //SC_MARK_VLINE 9
    "LCorner = 10",                //SC_MARK_LCORNER 10
    "TCorner = 11",                //SC_MARK_TCORNER 11
    "BoxPlus = 12",                //SC_MARK_BOXPLUS 12
    "BoxPlusConnected = 13",       //SC_MARK_BOXPLUSCONNECTED 13
    "BoxMinus = 14",               //SC_MARK_BOXMINUS 14
    "BoxMinusConnected = 15",      //SC_MARK_BOXMINUSCONNECTED 15
    "LCornerCurve = 16",           //SC_MARK_LCORNERCURVE 16
    "TCornerCurve = 17",           //SC_MARK_TCORNERCURVE 17
    "CirclePlus = 18",             //SC_MARK_CIRCLEPLUS 18
    "CirclePlusConnected = 19",    //SC_MARK_CIRCLEPLUSCONNECTED 19
    "CircleMinus = 20",            //SC_MARK_CIRCLEMINUS 20
    "CircleMinusConnected = 21",   //SC_MARK_CIRCLEMINUSCONNECTED 21
    "Background = 22",             //SC_MARK_BACKGROUND 22
    "DotDotDot = 23",              //SC_MARK_DOTDOTDOT 23
    "Arrows = 24",                 //SC_MARK_ARROWS 24
    "Pixmap = 25",                 //SC_MARK_PIXMAP 25
    "FullRect = 26",               //SC_MARK_FULLRECT 26
    "LeftRect = 27",               //SC_MARK_LEFTRECT 27
    "Available = 28",              //SC_MARK_AVAILABLE 28
    "Underline = 29",              //SC_MARK_UNDERLINE 29
    "RGBImage = 30",               //SC_MARK_RGBAIMAGE 30
    "Bookmark = 31",               //SC_MARK_BOOKMARK 31
    "Character = 10000",           //SC_MARK_CHARACTER 10000
};

static const char *EnumMarkNum[] = {
    "FolderEnd = 25",      //SC_MARKNUM_FOLDEREND 25
    "FolderOpenMid = 26",  //SC_MARKNUM_FOLDEROPENMID 26
    "FolderMidTail = 27",  //SC_MARKNUM_FOLDERMIDTAIL 27
    "FolderTail = 28",     //SC_MARKNUM_FOLDERTAIL 28
    "FolderSub = 29",      //SC_MARKNUM_FOLDERSUB 29
    "Folder = 30",         //SC_MARKNUM_FOLDER 30
    "FolderOpen = 31",     //SC_MARKNUM_FOLDEROPEN 31
};

static REALenum xsiEnums[] = {
    { "ScMarginType", NULL, REALScopeGlobal, EnumMarginType, 7 },
    { "ScMarker", NULL, REALScopeGlobal, EnumMarker, 32 },
    { "ScMarkNum", NULL, REALScopeGlobal, EnumMarkNum, 7 },
};


static REALmoduleDefinition modEnums = {
    kCurrentREALControlVersion,                     // version
    "xsiMod",                                        // name
    NULL,                                           // methods
    0,                                              // methodCount
    NULL,                                           // constants
    0,                                              // constantCount
    NULL,                                           // properties
    0,                                              // propertyCount
    NULL,                                           // structures
    0,                                              // structureCount
    xsiEnums,                                       // enums
    sizeof(xsiEnums)/sizeof(REALenum),              // enumCount
};

void registerEnums(void)
{
    REALRegisterModule(&modEnums);
}
