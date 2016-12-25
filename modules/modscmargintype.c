#include "modscmargintype.h"
#include "rb_plugin.h"

//declaration, reserved1, mFlags, attributeCount, attributes
static REALconstant scConstants[] = {
    {"Symbol as Integer = 0"},
    {"Number as Integer = 1"},
    {"Backcolor as Integer = 2"},
    {"Forecolor as Integer = 3"},
    {"Text as Integer = 4"},
    {"RText as Integer = 5"},
    {"Colour as Integer = 6"},
};

static REALmoduleDefinition modMarginType = {
    kCurrentREALControlVersion,                 // version
    "ScmarginType",                                  // name
    NULL,                                       // methods
    0,                                          // methodCount
    scConstants,                                // constants
    sizeof(scConstants)/sizeof(REALconstant),   // constantCount
    NULL,                                       // properties
    0,                                          // propertyCount
    NULL,                                       // structures
    0,                                          // structureCount
    NULL,                                       // enums
    0,                                          // enumCount
};

void registerScmarginType()
{
    REALRegisterModule(&modMarginType);
}
