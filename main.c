#include "xsintilla.h"
#include "xsi-behaviour.h"
#include "xsi-event.h"
#include "sci-text.h"

// group, name, type, flags, getter, setter, param, editor, enumCount, enumEntries, attributeCount, attributes
REALproperty xsiProperties[] = {
    /*
     * sci-text.h
     */
    { "", "readonly", "Boolean", REALconsoleSafe, (REALproc)xsip_getReadonly, (REALproc)xsip_setReadonly },
    { "", "text", "String", REALconsoleSafe, (REALproc)xsip_getText, (REALproc)xsip_setText }
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
