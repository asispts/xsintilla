#include "style-definition.h"
#include "style.h"
#include "xsintilla.h"

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
REALproperty StylePropDef[] = {
    {"", "idleStyling", "Integer", REALpropRuntimeOnly, (REALproc)styling_getIdleStyling,
     (REALproc)styling_setIdleStyling},
};

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
REALmethodDefinition StyleMethodDef[] = {
    {(REALproc)style_styleResetDefault, REALnoImplementation, "ResetDefault()"},
    {(REALproc)style_styleClearAll, REALnoImplementation, "ClearAll()"},
    {(REALproc)style_styleGetFont, REALnoImplementation, "Font(style as Integer) as String"},
    {(REALproc)style_styleSetFont, REALnoImplementation, "Font(style as Integer, Assigns fontName as String)"},
    {(REALproc)style_styleGetSize, REALnoImplementation, "FontSize(style as Integer) as Integer"},
    {(REALproc)style_styleSetSize, REALnoImplementation, "FontSize(style as Integer, Assigns sizePoints as Integer)"},
    {(REALproc)style_styleGetSizeFractional, REALnoImplementation, "SizeFractional(style as Integer) as Integer"},
    {(REALproc)style_styleSetSizeFractional, REALnoImplementation,
     "SizeFractional(style as Integer, Assigns sizeHundredthPoints as Integer)"},
    {(REALproc)style_styleGetBold, REALnoImplementation, "Bold(style as Integer) as Boolean"},
    {(REALproc)style_styleSetBold, REALnoImplementation, "Bold(style as Integer, Assigns value as Boolean)"},
    {(REALproc)style_styleGetWeight, REALnoImplementation, "FontWeight(style as Integer) as Integer"},
    {(REALproc)style_styleSetWeight, REALnoImplementation, "FontWeight(style as Integer, Assigns weight as Integer)"},
    {(REALproc)style_styleGetItalic, REALnoImplementation, "Italic(style as Integer) as Boolean"},
    {(REALproc)style_styleSetItalic, REALnoImplementation, "Italic(style as Integer, Assigns value as Boolean)"},
    {(REALproc)style_styleGetUnderline, REALnoImplementation, "Underline(style as Integer) as Boolean"},
    {(REALproc)style_styleSetUnderline, REALnoImplementation, "Underline(style as Integer, Assigns value as Boolean)"},
    {(REALproc)style_styleGetFore, REALnoImplementation, "Forecolor(style as Integer) as Color"},
    {(REALproc)style_styleSetFore, REALnoImplementation, "Forecolor(style as Integer, Assigns fore as Color)"},
    {(REALproc)style_styleGetBack, REALnoImplementation, "Backcolor(style as Integer) as Color"},
    {(REALproc)style_styleSetBack, REALnoImplementation, "Backcolor(style as Integer, Assigns back as Color)"},
    {(REALproc)style_styleGetEOLFilled, REALnoImplementation, "EOLFilled(style as Integer) as Boolean"},
    {(REALproc)style_styleSetEOLFilled, REALnoImplementation,
     "EOLFilled(style as Integer, Assigns eolFilled as Boolean)"},
    {(REALproc)style_styleGetCharacterSet, REALnoImplementation, "CharacterSet(style as Integer) as Integer"},
    {(REALproc)style_styleSetCharacterSet, REALnoImplementation,
     "CharacterSet(style as Integer, Assigns charSet as Integer)"},
    {(REALproc)style_styleGetCase, REALnoImplementation, "TextCase(style as Integer) as Integer"},
    {(REALproc)style_styleSetCase, REALnoImplementation, "TextCase(style as Integer, Assigns charSet as Integer)"},
    {(REALproc)style_styleGetVisible, REALnoImplementation, "Visible(style as Integer) as Boolean"},
    {(REALproc)style_styleSetVisible, REALnoImplementation, "Visible(style as Integer, Assigns visible as Boolean)"},
    {(REALproc)style_styleGetChangeable, REALnoImplementation, "Changeable(style as Integer) as Boolean"},
    {(REALproc)style_styleSetChangeable, REALnoImplementation,
     "Changeable(style as Integer, Assigns changeable as Boolean)"},
    {(REALproc)style_styleGetHotspot, REALnoImplementation, "Hotspot(style as Integer) as Boolean"},
    {(REALproc)style_styleSetHotspot, REALnoImplementation, "Hotspot(style as Integer, Assigns hotspot as Boolean)"},

    // styling
    {(REALproc)styling_getEndStyled, REALnoImplementation, "GetEndStyled() as Integer"},
    {(REALproc)styling_getMaxLineState, REALnoImplementation, "GetMaxLineState() as Integer"},
    {(REALproc)styling_startStyling, REALnoImplementation, "StartStyling(start as Integer)"},
    {(REALproc)styling_setStyling, REALnoImplementation, "SetStyling(length as Integer, style as Integer)"},
    {(REALproc)styling_setStylingEx, REALnoImplementation, "SetStylingEx(length as Integer, styles as String)"},
    {(REALproc)styling_getLineState, REALnoImplementation, "LineState(line as Integer) as Integer"},
    {(REALproc)styling_setLineState, REALnoImplementation, "LineState(line as Integer, Assigns state as Integer)"},
};

//+++++++++++++++++++++++++++++++++
// Class Definition
//+++++++++++++++++++++++++++++++++
REALclassDefinition xsiStyleDef = {
    kCurrentREALControlVersion,                             // version
    "xsiStyle",                                             // name
    NULL,                                                   // superName
    sizeof(xsiStyleData),                                   // dataSize
    0,                                                      // forSystemUse
    NULL,                                                   // constructor
    NULL,                                                   // destructor
    StylePropDef,                                           // properties
    sizeof(StylePropDef) / sizeof(REALproperty),            // propertyCount
    StyleMethodDef,                                         // methods
    sizeof(StyleMethodDef) / sizeof(REALmethodDefinition),  // methodCount
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
    NULL,  // delegates
    0,     // delegateCount
    NULL,  // enums
    0,     // enumCount
#endif
};

void registerClassStyledef(void)
{
    REALRegisterClass(&xsiStyleDef);
}
