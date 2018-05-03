#include "margin-definition.h"
#include "margin.h"

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
REALproperty MarginPropertiesDef[] = {
    {"", "margins", "Integer", REALpropRuntimeOnly, (REALproc)margin_getMargins, (REALproc)margin_setMargins},
    {"", "left", "Integer", REALpropRuntimeOnly, (REALproc)margin_getMarginLeft, (REALproc)margin_setMarginLeft},
    {"", "right", "Integer", REALpropRuntimeOnly, (REALproc)margin_getMarginRight, (REALproc)margin_setMarginRight},
    {"", "styleOffset", "Integer", REALpropRuntimeOnly, (REALproc)margin_marginGetStyleOffset,
     (REALproc)margin_marginSetStyleOffset},
    {"", "options", "Integer", REALpropRuntimeOnly, (REALproc)margin_getMarginOptions,
     (REALproc)margin_setMarginOptions},
};

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
REALmethodDefinition MarginMethodDef[] = {
    {(REALproc)margin_marginGetText, REALnoImplementation, "Text(line as Integer) as String"},
    {(REALproc)margin_marginSetText, REALnoImplementation, "Text(line as Integer, Assigns value as String)"},
    {(REALproc)margin_marginGetStyle, REALnoImplementation, "Style(line as Integer) as Integer"},
    {(REALproc)margin_marginSetStyle, REALnoImplementation, "Style(line as Integer, Assigns value as Integer)"},
    {(REALproc)margin_marginGetStyles, REALnoImplementation, "StyleString(line as Integer) as String"},
    {(REALproc)margin_marginSetStyles, REALnoImplementation, "StyleString(line as Integer, Assigns value as String)"},
    {(REALproc)margin_setFoldMarginColour, REALnoImplementation,
     "FoldColour(useSetting as Boolean, Assigns value as Color)"},
    {(REALproc)margin_setFoldMarginHiColour, REALnoImplementation,
     "FoldHiColour(useSetting as Boolean, Assigns value as Color)"},
    {(REALproc)margin_marginTextClearAll, REALnoImplementation, "ClearAll()"},

    {REALnoImplementation, REALnoImplementation, "Constructor()", REALScopePrivate},
    {(REALproc)margin_getMarginTypeN, REALnoImplementation, "TypeN(margin as Integer) as eMarginType"},
    {(REALproc)margin_setMarginTypeN, REALnoImplementation, "TypeN(margin as Integer, Assigns value as eMarginType)"},
    {(REALproc)margin_getMarginWidthN, REALnoImplementation, "WidthN(margin as Integer) as Integer"},
    {(REALproc)margin_setMarginWidthN, REALnoImplementation, "WidthN(margin as Integer, Assigns value as Integer)"},
    {(REALproc)margin_getMarginBackN, REALnoImplementation, "BackN(margin as Integer) as Color"},
    {(REALproc)margin_setMarginBackN, REALnoImplementation, "BackN(margin as Integer, Assigns value as Color)"},
    {(REALproc)margin_getMarginMaskN, REALnoImplementation, "MaskN(margin as Integer) as Integer"},
    {(REALproc)margin_setMarginMaskN, REALnoImplementation, "MaskN(margin as Integer, Assigns value as Integer)"},
    {(REALproc)margin_getMarginSensitiveN, REALnoImplementation, "SensitiveN(margin as Integer) as Boolean"},
    {(REALproc)margin_setMarginSensitiveN, REALnoImplementation,
     "SensitiveN(margin as Integer, Assigns value as Boolean)"},
    {(REALproc)margin_getMarginCursorN, REALnoImplementation, "CursorN(margin as Integer) as Integer"},
    {(REALproc)margin_setMarginCursorN, REALnoImplementation, "CursorN(margin as Integer, Assigns value as Integer)"},
};

//+++++++++++++++++++++++++++++++++
// Constants
//+++++++++++++++++++++++++++++++++
REALconstant xsiMarginConstantDef[] = {
    {"MAX_MARGIN as Integer = 4"},             // SC_MAX_MARGIN 4
    {"MASK_FOLDERS as Integer = &hFE000000"},  // SC_MASK_FOLDERS 0xFE000000
};

//+++++++++++++++++++++++++++++++++
// Enums
//+++++++++++++++++++++++++++++++++
static const char* enumMarginType[] = {
    "Symbol = 0",     // SC_MARGIN_SYMBOL 0
    "Number = 1",     // SC_MARGIN_NUMBER 1
    "Backcolor = 2",  // SC_MARGIN_BACK 2
    "Forecolor = 3",  // SC_MARGIN_FORE 3
    "Text = 4",       // SC_MARGIN_TEXT 4
    "RText = 5",      // SC_MARGIN_RTEXT 5
    "Colour = 6",     // SC_MARGIN_COLOUR 6
};

REALenum xsiMarginEnumDef[] = {
    // name, type, mFlags, fields, numFields, attributeCount, attributes
    {"eMarginType", "Int8", REALScopePublic, enumMarginType, 7},
};

//+++++++++++++++++++++++++++++++++
// Class Definition
//+++++++++++++++++++++++++++++++++
REALclassDefinition xsiMarginDef = {
    kCurrentREALControlVersion,                              // version
    "xsiMargin",                                             // name
    NULL,                                                    // superName
    sizeof(xsiMarginData),                                   // dataSize
    0,                                                       // forSystemUse
    NULL,                                                    // constructor
    NULL,                                                    // destructor
    MarginPropertiesDef,                                     // properties
    sizeof(MarginPropertiesDef) / sizeof(REALproperty),      // propertyCount
    MarginMethodDef,                                         // methods
    sizeof(MarginMethodDef) / sizeof(REALmethodDefinition),  // methodCount
    NULL,                                                    // events
    0,                                                       // eventCount
    NULL,                                                    // eventInstances
    0,                                                       // eventInstanceCount
    NULL,                                                    // interfaces
    NULL,                                                    // attributes
    0,                                                       // attributeCount
    xsiMarginConstantDef,                                    // constants
    sizeof(xsiMarginConstantDef) / sizeof(REALconstant),     // constantCount
    0,                                                       // mFlags
    NULL,                                                    // sharedProperties
    0,                                                       // sharedPropertyCount
    NULL,                                                    // sharedMethods
    0,                                                       // sharedMethodCount; // End RB2006r4 stuff
#if kCurrentREALControlVersion >= 11
    NULL,                                         // delegates
    0,                                            // delegateCount
    xsiMarginEnumDef,                             // enums
    sizeof(xsiMarginEnumDef) / sizeof(REALenum),  // enumCount
#endif
};

void registerClassMargin(void)
{
    REALRegisterClass(&xsiMarginDef);
}
