#include "modscmarker.h"
#include "rb_plugin.h"

//declaration, reserved1, mFlags, attributeCount, attributes
static REALconstant scMark[] = {
    {"MarkerMax as Integer = 31"},
    {"Circle as Integer = 0"},
    {"RoundRect as Integer = 1"},
    {"Arrow as Integer = 2"},
    {"SmallRect as Integer = 3"},
    {"ShortArrow as Integer = 4"},
    {"Empty as Integer = 5"},
    {"ArrowDown as Integer = 6"},
    {"Minus as Integer = 7"},
    {"Plus as Integer = 8"},
    {"Vline as Integer = 9"},
    {"LCorner as Integer = 10"},
    {"TCorner as Integer = 11"},
    {"BoxPlus as Integer = 12"},
    {"BoxPlusConnected as Integer = 13"},
    {"BoxMinus as Integer = 14"},
    {"BoxMinusConnected as Integer = 15"},
    {"LCornerCurve as Integer = 16"},
    {"TCornerCurve as Integer = 17"},
    {"CirclePlus as Integer = 18"},
    {"CirclePlusConnected as Integer = 19"},
    {"CircleMinus as Integer = 20"},
    {"CircleMinusConnected as Integer = 21"},
    {"Background as Integer = 22"},
    {"DotDotDot as Integer = 23"},
    {"Arrows as Integer = 24"},
    {"Pixmap as Integer = 25"},
    {"FullRect as Integer = 26"},
    {"LeftRect as Integer = 27"},
    {"Available as Integer = 28"},
    {"Underline as Integer = 29"},
    {"RGBImage as Integer = 30"},
    {"Bookmark as Integer = 31"},
    {"Character as Integer = 10000"},
};

static REALmoduleDefinition modMark = {
    kCurrentREALControlVersion,             // version
    "Scmark",                               // name
    NULL,                                   // methods
    0,                                      // methodCount
    scMark,                                 // constants
    sizeof(scMark)/sizeof(REALconstant),    // constantCount
};


static REALconstant scMarknum[] = {
    {"FolderEnd as Integer = 25"},
    {"FolderOpenMid as Integer = 26"},
    {"FolderMidTail as Integer = 27"},
    {"FolderTail as Integer = 28"},
    {"FolderSub as Integer = 29"},
    {"Folder as Integer = 30"},
    {"FolderOpen as Integer = 31"},
};

static REALmoduleDefinition modMarkNum = {
    kCurrentREALControlVersion,                 // version
    "Scmarknum",                                // name
    NULL,                                       // methods
    0,                                          // methodCount
    scMarknum,                                 // constants
    sizeof(scMarknum)/sizeof(REALconstant),     // constantCount
};

static REALconstant scMask[] = {
    {"Folder as Integer = &hFE000000"},
};

static REALmoduleDefinition modMask = {
    kCurrentREALControlVersion,             // version
    "Scmask",                               // name
    NULL,                                   // methods
    0,                                      // methodCount
    scMask,                                 // constants
    sizeof(scMask)/sizeof(REALconstant),    // constantCount
};

void registerScmarker()
{
    REALRegisterModule(&modMark);
    REALRegisterModule(&modMarkNum);
    REALRegisterModule(&modMask);
}
