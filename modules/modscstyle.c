#include "modscstyle.h"
#include "rb_plugin.h"

// declaration, reserved1, mFlags, attributeCount, attributes
static REALconstant ScstyleConstants[] = {
    // STYLE_DEFAULT 32
    {"Default as Integer = 32", NULL, REALScopeProtected},
    // STYLE_LINENUMBER 33
    {"LineNumber as Integer = 33", NULL, REALScopeProtected},
    // STYLE_BRACELIGHT 34
    {"BraceLight as Integer = 34", NULL, REALScopeProtected},
    // STYLE_BRACEBAD 35
    {"BraceBad as Integer = 35", NULL, REALScopeProtected},
    // STYLE_CONTROLCHAR 36
    {"ControlChar as Integer = 36", NULL, REALScopeProtected},
    // STYLE_INDENTGUIDE 37
    {"IndentGuide as Integer = 37", NULL, REALScopeProtected},
    // STYLE_CALLTIP 38
    {"Calltip as Integer = 38", NULL, REALScopeProtected},
    // STYLE_FOLDDISPLAYTEXT 39
    {"FoldDisplayText as Integer = 39", NULL, REALScopeProtected},
    // STYLE_LASTPREDEFINED 39
    {"LastPredefined as Integer = 39", NULL, REALScopeProtected},
};

static REALmoduleDefinition modStyle = {
    kCurrentREALControlVersion,                       // version
    "Scstyle",                                        // name
    NULL,                                             // methods
    0,                                                // methodCount
    ScstyleConstants,                                 // constants
    sizeof(ScstyleConstants) / sizeof(REALconstant),  // constantCount
    NULL,                                             // properties
    0,                                                // propertyCount
    NULL,                                             // structures
    0,                                                // structureCount
    NULL,                                             // enums
    0,                                                // enumCount
};

// declaration, reserved1, mFlags, attributeCount, attributes
static REALconstant ScstyleBasic[] = {
    // SCE_B_DEFAULT 0
    {"Default as Integer = 0", NULL, REALScopeProtected},
    // SCE_B_COMMENT 1
    {"Comment as Integer = 1", NULL, REALScopeProtected},
    // SCE_B_NUMBER 2
    {"Number as Integer = 2", NULL, REALScopeProtected},
    // SCE_B_KEYWORD 3
    {"Keyword as Integer = 3", NULL, REALScopeProtected},
    // SCE_B_STRING 4
    {"StringSty as Integer = 4", NULL, REALScopeProtected},
    // SCE_B_PREPROCESSOR 5
    {"Preprocessor as Integer = 5", NULL, REALScopeProtected},
    // SCE_B_OPERATOR 6
    {"Operator as Integer = 6", NULL, REALScopeProtected},
    // SCE_B_IDENTIFIER 7
    {"Identifier as Integer = 7", NULL, REALScopeProtected},
    // SCE_B_DATE 8
    {"DateSty as Integer = 8", NULL, REALScopeProtected},
    // SCE_B_STRINGEOL 9
    {"StringEOL as Integer = 9", NULL, REALScopeProtected},
    // SCE_B_KEYWORD2 10
    {"Keyword2 as Integer = 10", NULL, REALScopeProtected},
    // SCE_B_KEYWORD3 11
    {"Keyword3 as Integer = 11", NULL, REALScopeProtected},
    // SCE_B_KEYWORD4 12
    {"Keyword4 as Integer = 12", NULL, REALScopeProtected},
    // SCE_B_CONSTANT 13
    {"Constant as Integer = 13", NULL, REALScopeProtected},
    // SCE_B_ASM 14
    {"Asm as Integer = 14", NULL, REALScopeProtected},
    // SCE_B_LABEL 15
    {"Label as Integer = 15", NULL, REALScopeProtected},
    // SCE_B_ERROR 16
    {"Error as Integer = 16", NULL, REALScopeProtected},
    // SCE_B_HEXNUMBER 17
    {"HexNumber as Integer = 17", NULL, REALScopeProtected},
    // SCE_B_BINNUMBER 18
    {"BinNumber as Integer = 18", NULL, REALScopeProtected},
    // SCE_B_COMMENTBLOCK 19
    {"CommentBlock as Integer = 19", NULL, REALScopeProtected},
    // SCE_B_DOCLINE 20
    {"Docline as Integer = 20", NULL, REALScopeProtected},
    // SCE_B_DOCBLOCK 21
    {"DocBlock as Integer = 21", NULL, REALScopeProtected},
    // SCE_B_DOCKEYWORD 22
    {"DocKeyword as Integer = 22", NULL, REALScopeProtected},
};

static REALmoduleDefinition modBasic = {
    kCurrentREALControlVersion,                   // version
    "SceBasic",                                   // name
    NULL,                                         // methods
    0,                                            // methodCount
    ScstyleBasic,                                 // constants
    sizeof(ScstyleBasic) / sizeof(REALconstant),  // constantCount
    NULL,                                         // properties
    0,                                            // propertyCount
    NULL,                                         // structures
    0,                                            // structureCount
    NULL,                                         // enums
    0,                                            // enumCount
};

void registerScstyle()
{
    REALRegisterModule(&modStyle);
    REALRegisterModule(&modBasic);
}
