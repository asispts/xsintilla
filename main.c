#include "xsintilla.h"
#include "xsi-behaviour.h"
#include "xsi-event.h"
#include "sci-text.h"
#include "sci-styledef.h"
#include "sci-margin.h"

// group, name, type, flags, getter, setter, param, editor, enumCount, enumEntries, attributeCount, attributes
REALproperty xsiProperties[] = {
    /*
     * sci-text.h
     */
    { "", "readonly", "Boolean", REALconsoleSafe | REALpropRuntimeOnly, (REALproc)xsip_getReadonly, (REALproc)xsip_setReadonly },
    { "", "text", "String", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getText, (REALproc)xsip_setText }
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
    { (REALproc) xsim_styleSetFont,         REALnoImplementation, "StyleSetFont(style as Integer, fontName as String)" },
    { (REALproc) xsim_styleGetFont,         REALnoImplementation, "StyleGetFont(style as Integer) as String" },
    { (REALproc) xsim_styleSetSize,         REALnoImplementation, "StyleSetSize(style as Integer, sizePoints as Integer)" },
    { (REALproc) xsim_styleGetSize,         REALnoImplementation, "StyleGetSize(style as Integer) as Integer" },
    { (REALproc) xsim_styleSetWeight,       REALnoImplementation, "StyleSetWeight(style as Integer, weight as Integer)" },
    { (REALproc) xsim_styleGetWeight,       REALnoImplementation, "StyleGetWeight(style as Integer) as Integer" },
    { (REALproc) xsim_styleSetFore,         REALnoImplementation, "StyleSetForecolor(style as Integer, fore as Color)" },
    { (REALproc) xsim_styleGetFore,         REALnoImplementation, "StyleGetForecolor(style as Integer) as Color" },
    { (REALproc) xsim_styleSetBack,         REALnoImplementation, "StyleSetBackcolor(style as Integer, back as Color)" },
    { (REALproc) xsim_styleGetBack,         REALnoImplementation, "StyleGetBackcolor(style as Integer) as Color" },
    { (REALproc) xsim_styleSetVisible,      REALnoImplementation, "StyleSetVisible(style as Integer, visible as Boolean)" },
    { (REALproc) xsim_styleGetVisible,      REALnoImplementation, "StyleGetVisible(style as Integer) as Boolean" },
    /*
     * sci-margin.h
     */
    { (REALproc) xsim_getMargins,       REALnoImplementation, "Margins() as Integer" },
    { (REALproc) xsim_setMargins,       REALnoImplementation, "Margins(assigns count as Integer)" },
    { (REALproc) xsim_getMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer, assigns marginType as Integer)" },
    { (REALproc) xsim_getMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer, assigns pixelWidth as Integer)" },
    { (REALproc) xsim_getMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer) as Color" },
    { (REALproc) xsim_setMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer, assigns back as Color)" },
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
    NULL,                               // constants
    0,                                  // constantCount
#if kCurrentREALControlVersion >= 11
    NULL,                               // sharedProperties
    0,                                  // sharedPropertyCount
    NULL,                               // sharedMethods
    0,                                  // sharedMethodCount
    NULL,                               // delegates
    0,                                  // delegateCount
    NULL,                               // enums
    0                                   // enumCount
#endif
    // end of structure
};



void PluginEntry()
{
    REALRegisterControl(&xsiControl);
}
