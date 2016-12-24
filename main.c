#include "xsintilla.h"
#include "xsi-behaviour.h"
#include "xsi-event.h"
#include "sci-text.h"
#include "sci-styledef.h"
#include "sci-margin.h"
#include "sci-selection.h"

// group, name, type, flags, getter, setter, param, editor, enumCount, enumEntries, attributeCount, attributes
REALproperty xsiProperties[] = {
    /*
     * sci-text.h
     */
    { "", "readonly", "Boolean", REALconsoleSafe | REALpropRuntimeOnly, (REALproc)xsip_getReadonly, (REALproc)xsip_setReadonly },
    { "", "text", "String", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getText, (REALproc)xsip_setText }
    /*
     * sci-selection.h
     */
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
    { (REALproc) xsim_getMargins,       REALnoImplementation, "Margins() as Integer" },
    { (REALproc) xsim_setMargins,       REALnoImplementation, "Margins(assigns count as Integer)" },
    { (REALproc) xsim_getMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer, assigns marginType as Integer)" },
    { (REALproc) xsim_getMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer, assigns pixelWidth as Integer)" },
    { (REALproc) xsim_getMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer) as Color" },
    { (REALproc) xsim_setMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer, assigns back as Color)" },
    /*
     * sci-selection.h
     */
    { (REALproc) xsim_getTextLength,        REALnoImplementation, "TextLength() as Integer" },
    { (REALproc) xsim_getLength,            REALnoImplementation, "Length() as Integer" },
    { (REALproc) xsim_getLineCount,         REALnoImplementation, "LineCount() as Integer" },
    { (REALproc) xsim_lineOnScreen,         REALnoImplementation, "LineOnScreen() as Integer" },
    { (REALproc) xsim_getModify,            REALnoImplementation, "Modified() as Boolean" },
    { (REALproc) xsim_setSel,               REALnoImplementation, "SetSel(anchor as Integer, caret as Integer)" },
    { (REALproc) xsim_gotoPos,              REALnoImplementation, "GotoPosition(caret as Integer)" },
    { (REALproc) xsim_gotoLine,       REALnoImplementation, "GotoLine(line as Integer)" },
    { (REALproc) xsim_getCurrentPos,       REALnoImplementation, "CurrentPos() as Integer" },
    { (REALproc) xsim_setCurrentPos,       REALnoImplementation, "CurrentPos(assigns caret as Integer)" },
    { (REALproc) xsim_getAnchor,       REALnoImplementation, "Anchor() as Integer" },
    { (REALproc) xsim_setAnchor,       REALnoImplementation, "Anchor(assigns anchorPos as Integer)" },
    { (REALproc) xsim_getSelectionStart,       REALnoImplementation, "SelectionStart() as Integer" },
    { (REALproc) xsim_setSelectionStart,       REALnoImplementation, "SelectionStart(assigns anchor as Integer)" },
    { (REALproc) xsim_getSelectionEnd,       REALnoImplementation, "SelectionEnd() as Integer" },
    { (REALproc) xsim_setSelectionEnd,       REALnoImplementation, "SelectionEnd(assigns caret as Integer)" },
    { (REALproc) xsim_setEmptySelection,       REALnoImplementation, "EmptySelection(caret as Integer)" },
    { (REALproc) xsim_selectAll,       REALnoImplementation, "SelectAll()" },
    { (REALproc) xsim_lineFromPosition,       REALnoImplementation, "LineFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_positionFromLine,       REALnoImplementation, "PositionFromLine(line as Integer) as Integer" },
    { (REALproc) xsim_getLineEndPosition,       REALnoImplementation, "LineEndPosition(line as Integer) as Integer" },
    { (REALproc) xsim_lineLength,       REALnoImplementation, "LineLength(line as Integer) as Integer" },
    { (REALproc) xsim_getColumn,       REALnoImplementation, "GetColumn(pos as Integer) as Integer" },
    { (REALproc) xsim_findColumn,       REALnoImplementation, "FindColumn(line as Integer, column as Integer) as Integer" },
    { (REALproc) xsim_positionFromPoint,       REALnoImplementation, "PositionFromPoint(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_positionFromPointClose,       REALnoImplementation, "PositionFromPointClose(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_charPositionFromPoint,       REALnoImplementation, "CharPositionFromPoint(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_charPositionFromPointClose,       REALnoImplementation, "CharPositionFromPointClose(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_pointXFromPosition,       REALnoImplementation, "PointXFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_pointYFromPosition,       REALnoImplementation, "PointYFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_hideSelection,       REALnoImplementation, "HideSelection(hide as Boolean)" },
    { (REALproc) xsim_getSeltext,       REALnoImplementation, "GetSeltext() as String" },
    { (REALproc) xsim_getCurLine,       REALnoImplementation, "GetCurLine(length as Integer) as String" },
    { (REALproc) xsim_selectionIsRectangle,       REALnoImplementation, "SelectionIsRectangle() as Boolean" },
    { (REALproc) xsim_getSelectionMode,       REALnoImplementation, "SelectionMode() as Integer" },
    { (REALproc) xsim_setSelectionMode,       REALnoImplementation, "SelectionMode(assigns mode as Integer)" },
    { (REALproc) xsim_getLineSelStartPosition,       REALnoImplementation, "GetLineSelStartPosition(line as Integer) as Integer" },
    { (REALproc) xsim_getLineSelEndPosition,       REALnoImplementation, "GetLineSelEndPosition(line as Integer) as Integer" },
    { (REALproc) xsim_moveCaretInsideView,       REALnoImplementation, "MoveCaretInsideView()" },
    { (REALproc) xsim_positionBefore,       REALnoImplementation, "PositionBefore(pos as Integer) as Integer" },
    { (REALproc) xsim_positionAfter,       REALnoImplementation, "PositionAfter(pos as Integer) as Integer" },
    { (REALproc) xsim_positionRelative,       REALnoImplementation, "PositionRelative(pos as Integer, relative as Integer) as Integer" },
    { (REALproc) xsim_countCharacters,       REALnoImplementation, "CountCharacters(posStart as Integer, posEnd as Integer) as Integer" },
    { (REALproc) xsim_textWidth,       REALnoImplementation, "TextWidth(style as Integer, text as String) as Integer" },
    { (REALproc) xsim_textHeight,       REALnoImplementation, "TextHeight(line as Integer) as Integer" },
    { (REALproc) xsim_chooseCaretX,       REALnoImplementation, "ChooseCaretX()" },
    { (REALproc) xsim_moveSelectedLinesUp,       REALnoImplementation, "MoveSelectedLinesUp()" },
    { (REALproc) xsim_moveSelectedLinesDown,       REALnoImplementation, "MoveSelectedLinesDown()" },
    { (REALproc) xsim_getMouseSelectionRectangularSwitch,       REALnoImplementation, "TextLength() as Boolean" },
    { (REALproc) xsim_setMouseSelectionRectangularSwitch,       REALnoImplementation, "TextLength(assigns mouseSwitch as Boolean)" },
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
    0                                   // enumCount
#endif
    // end of structure
};



void PluginEntry()
{
    REALRegisterControl(&xsiControl);
}
