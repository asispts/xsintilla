#include "modplugin.h"
#include "xsintilla.h"
#include "xsi-behaviour.h"
#include "xsi-event.h"
#include "sci-text.h"
#include "sci-styledef.h"
#include "sci-margin.h"
#include "sci-selection.h"
#include "sci-lexer.h"
#include "sci-marker.h"

// group, name, type, flags, getter, setter, param, editor, enumCount, enumEntries, attributeCount, attributes
REALproperty xsiProperties[] = {
    /*
     * sci-text.h
     */
    { "", "readonly", "Boolean", REALconsoleSafe | REALpropRuntimeOnly, (REALproc)xsip_getReadonly, (REALproc)xsip_setReadonly },
    { "", "text", "String", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getText, (REALproc)xsip_setText },
    /*
     * sci-margin.h
     */
    { "", "marginCount", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getMargins, (REALproc)xsip_setMargins },
    { "", "marginLeft", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getMarginLeft, (REALproc)xsip_setMarginLeft },
    { "", "marginRight", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getMarginRight, (REALproc)xsip_setMarginRight },
    { "", "marginStyleOffset", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_marginGetStyleOffset, (REALproc)xsip_marginSetStyleOffset },
    { "", "marginOptions", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getMarginOptions, (REALproc)xsip_setMarginOptions },
    /*
     * sci-selection.h
     */
    { "", "textLength", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getTextLength, REALnoImplementation },
    { "", "length", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getLength, REALnoImplementation },
    { "", "lineCount", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getLineCount, REALnoImplementation },
    { "", "lineOnScreen", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_lineOnScreen, REALnoImplementation },
    { "", "modified", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getModify, REALnoImplementation },
    { "", "currentPos", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getCurrentPos, (REALproc)xsip_setCurrentPos },
    { "", "anchor", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getAnchor, (REALproc)xsip_setAnchor },
    { "", "selectionStart", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getSelectionStart, (REALproc)xsip_setSelectionStart },
    { "", "selectionEnd", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getSelectionEnd, (REALproc)xsip_setSelectionEnd },
    { "", "hideSelection", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly, REALnoImplementation, (REALproc)xsip_hideSelection },
    { "", "seltext", "String", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getSeltext, REALnoImplementation },
    { "", "selectionIsRectangle", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_selectionIsRectangle, REALnoImplementation },
    { "", "selectionMode", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getSelectionMode, (REALproc)xsip_setSelectionMode },
    { "", "mouseSelectionRectangularSwitch", "Boolean", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getMouseSelectionRectangularSwitch, (REALproc)xsip_setMouseSelectionRectangularSwitch },
    /*
     * sci-lexer.h
     */
    { "", "lexer", "Integer", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getLexer, (REALproc)xsip_setLexer },
    { "", "lexerLanguage", "String", REALconsoleSafe  | REALpropRuntimeOnly, (REALproc)xsip_getLexerLanguage, (REALproc)xsip_setLexerLanguage },
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
    { (REALproc) xsim_getMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginTypeN,   REALnoImplementation, "MarginType(margin as Integer, assigns marginType as Integer)" },
    { (REALproc) xsim_getMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginWidthN,  REALnoImplementation, "MarginWidth(margin as Integer, assigns pixelWidth as Integer)" },
    { (REALproc) xsim_getMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer) as Color" },
    { (REALproc) xsim_setMarginBackN,   REALnoImplementation, "MarginBackcolor(margin as Integer, assigns back as Color)" },
    { (REALproc) xsim_getMarginMaskN,   REALnoImplementation, "MarginMask(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginMaskN,   REALnoImplementation, "MarginMask(margin as Integer, assigns mask as Integer)" },
    { (REALproc) xsim_getMarginSensitiveN,   REALnoImplementation, "MarginSensitive(margin as Integer) as Boolean" },
    { (REALproc) xsim_setMarginSensitiveN,   REALnoImplementation, "MarginSensitive(margin as Integer, assigns sensitive as Boolean)" },
    { (REALproc) xsim_getMarginCursorN,   REALnoImplementation, "MarginCursor(margin as Integer) as Integer" },
    { (REALproc) xsim_setMarginCursorN,   REALnoImplementation, "MarginCursor(margin as Integer, assigns cursor as Integer)" },
    { (REALproc) xsim_marginGetText,   REALnoImplementation, "MarginText(line as Integer) as String" },
    { (REALproc) xsim_marginSetText,   REALnoImplementation, "MarginText(line as Integer, assigns text as String)" },
    { (REALproc) xsim_marginGetStyle,   REALnoImplementation, "MarginStyle(line as Integer) as Integer" },
    { (REALproc) xsim_marginSetStyle,   REALnoImplementation, "MarginStyle(line as Integer, assigns style as Integer)" },
    { (REALproc) xsim_marginGetStyles,   REALnoImplementation, "MarginStyleStr(line as Integer) as String" },
    { (REALproc) xsim_marginSetStyles,   REALnoImplementation, "MarginStyleStr(line as Integer, assigns styles as String)" },

    { (REALproc) xsim_setFoldMarginColour,   REALnoImplementation, "FoldMarginColour(useSetting as Boolean, back as Color)" },
    { (REALproc) xsim_setFoldMarginHiColour,   REALnoImplementation, "FoldMarginHiColour(useSetting as Boolean, fore as Color)" },
    { (REALproc) xsim_marginTextClearAll,   REALnoImplementation, "MarginTextClearAll()" },
    /*
     * sci-selection.h
     */
    { (REALproc) xsim_setSel,                       REALnoImplementation, "SetSel(anchor as Integer, caret as Integer)" },
    { (REALproc) xsim_gotoPos,                      REALnoImplementation, "GotoPosition(caret as Integer)" },
    { (REALproc) xsim_gotoLine,                     REALnoImplementation, "GotoLine(line as Integer)" },
    { (REALproc) xsim_setEmptySelection,            REALnoImplementation, "EmptySelection(caret as Integer)" },
    { (REALproc) xsim_selectAll,                    REALnoImplementation, "SelectAll()" },
    { (REALproc) xsim_lineFromPosition,             REALnoImplementation, "LineFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_positionFromLine,             REALnoImplementation, "PositionFromLine(line as Integer) as Integer" },
    { (REALproc) xsim_getLineEndPosition,           REALnoImplementation, "LineEndPosition(line as Integer) as Integer" },
    { (REALproc) xsim_lineLength,                   REALnoImplementation, "LineLength(line as Integer) as Integer" },
    { (REALproc) xsim_getColumn,                    REALnoImplementation, "GetColumn(pos as Integer) as Integer" },
    { (REALproc) xsim_findColumn,                   REALnoImplementation, "FindColumn(line as Integer, column as Integer) as Integer" },
    { (REALproc) xsim_positionFromPoint,            REALnoImplementation, "PositionFromPoint(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_positionFromPointClose,       REALnoImplementation, "PositionFromPointClose(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_charPositionFromPoint,        REALnoImplementation, "CharPositionFromPoint(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_charPositionFromPointClose,   REALnoImplementation, "CharPositionFromPointClose(x as Integer, y as Integer) as Integer" },
    { (REALproc) xsim_pointXFromPosition,           REALnoImplementation, "PointXFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_pointYFromPosition,           REALnoImplementation, "PointYFromPosition(pos as Integer) as Integer" },
    { (REALproc) xsim_getCurLine,                   REALnoImplementation, "GetCurLineText(length as Integer) as String" },
    { (REALproc) xsim_getLineSelStartPosition,      REALnoImplementation, "GetLineSelStartPosition(line as Integer) as Integer" },
    { (REALproc) xsim_getLineSelEndPosition,        REALnoImplementation, "GetLineSelEndPosition(line as Integer) as Integer" },
    { (REALproc) xsim_moveCaretInsideView,          REALnoImplementation, "MoveCaretInsideView()" },
    { (REALproc) xsim_positionBefore,               REALnoImplementation, "PositionBefore(pos as Integer) as Integer" },
    { (REALproc) xsim_positionAfter,                REALnoImplementation, "PositionAfter(pos as Integer) as Integer" },
    { (REALproc) xsim_positionRelative,             REALnoImplementation, "PositionRelative(pos as Integer, relative as Integer) as Integer" },
    { (REALproc) xsim_countCharacters,              REALnoImplementation, "CountCharacters(posStart as Integer, posEnd as Integer) as Integer" },
    { (REALproc) xsim_textWidth,                    REALnoImplementation, "TextWidth(style as Integer, text as String) as Integer" },
    { (REALproc) xsim_textHeight,                   REALnoImplementation, "TextHeight(line as Integer) as Integer" },
    { (REALproc) xsim_chooseCaretX,                 REALnoImplementation, "ChooseCaretX()" },
    { (REALproc) xsim_moveSelectedLinesUp,          REALnoImplementation, "MoveSelectedLinesUp()" },
    { (REALproc) xsim_moveSelectedLinesDown,        REALnoImplementation, "MoveSelectedLinesDown()" },
    /*
     * sci-lexer.h
     */
    { (REALproc) xsim_colourise,            REALnoImplementation, "Colourise(posStart as Integer, posEnd as Integer)" },
    { (REALproc) xsim_changeLexerState,     REALnoImplementation, "ChangeLexerState(posStart as Integer, posEnd as Integer) as Integer" },
    { (REALproc) xsim_setKeywords,          REALnoImplementation, "SetKeywords(keywordSet as Integer, keywords as String)" },
    { (REALproc) xsim_describeKeywordSets,  REALnoImplementation, "DescribeKeywordSets(description as String) as Integer" },
    { (REALproc) xsim_setProperty,          REALnoImplementation, "SetProperty(key as String, value as String)" },
    { (REALproc) xsim_getProperty,          REALnoImplementation, "GetProperty(key as String) as String" },
    { (REALproc) xsim_loadLexerLibrary,     REALnoImplementation, "LoadLexerLibrary(path as String)" },
    { (REALproc) xsim_propertyNames,        REALnoImplementation, "PropertyNames() as String" },
    { (REALproc) xsim_propertyType,         REALnoImplementation, "PropertyType(name as String) as Integer" },
    { (REALproc) xsim_describeProperty,     REALnoImplementation, "DescribeProperty(name as String) as String" },
    { (REALproc) xsim_getPropertyExpanded,  REALnoImplementation, "GetPropertyExpanded(key as String, value as String) as Integer" },
    { (REALproc) xsim_getPropertyInt,       REALnoImplementation, "GetPropertyInt(key as String, defaultValue as Integer) as Integer" },
    /*
     * sci-marker.h
     */
    { (REALproc) xsim_markerDefine, REALnoImplementation, "MarkerDefine(markerNumber as Integer, markerSymbol as Integer)" },
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
    0,                                  // enumCount
#endif
    // end of structure
};

void registerPlugin(void)
{
    REALRegisterControl(&xsiControl);
}
