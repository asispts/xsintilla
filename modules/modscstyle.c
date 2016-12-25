#include "modscstyle.h"
#include "rb_plugin.h"

//declaration, reserved1, mFlags, attributeCount, attributes
static REALconstant scConstants[] = {
    {"Default as Integer = 32"},
    {"LineNumber as Integer = 33"},
    {"BraceLight as Integer = 34"},
    {"BraceBad as Integer = 34"},
    {"ControlChar as Integer = 35"},
    {"IndentGuide as Integer = 36"},
    {"Calltip as Integer = 37"},
    {"FoldDisplayText as Integer = 38"},
    {"LastPredefined as Integer = 39"},
    {"StyleMax as Integer = 255"},
};

static REALmoduleDefinition modStyle = {
    kCurrentREALControlVersion,                 // version
    "Scstyle",                                  // name
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

void registerScstyle()
{
    REALRegisterModule(&modStyle);
}
