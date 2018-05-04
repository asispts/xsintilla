// Control headers
#include "behaviour.h"
#include "definition.h"
#include "event.h"
#include "xsintilla.h"

// API
#include "api_error.h"
#include "api_event.h"
#include "api_lexer.h"
#include "api_margin.h"
#include "api_selection.h"
#include "api_style.h"
#include "api_styling.h"
#include "api_text.h"

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
REALproperty xsiProperties[] = {
    // group, name, type, flags, getter, setter, param, editor, enumCount, enumEntries, attributeCount, attributes

    //    /*+++++++++++++++++++++++++
    //     * sci-marker.h
    //     +++++++++++++++++++++++++*/
    //    {"", "rgbaImageSetWidth", "Integer", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_rgbaImageSetWidth},
    //    {"", "rgbaImageSetHeight", "Integer", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_rgbaImageSetHeight},
    //    {"", "rgbaImageSetScale", "Integer", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_rgbaImageSetScale},
    //    {"", "markerEnableHighlight", "Boolean", REALpropRuntimeOnly, REALnoImplementation,
    //     (REALproc)xsip_markerEnableHighlight},
    //
    //    /*+++++++++++++++++++++++++
    //     * sci-autoc.h
    //     +++++++++++++++++++++++++*/
    //    {"", "autocIgnoreCase", "Boolean", REALpropRuntimeOnly, (REALproc)xsip_autocGetIgnoreCase,
    //     (REALproc)xsip_autocSetIgnoreCase},
    //    {"", "autocSeparator", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetSeparator,
    //     (REALproc)xsip_autocSetSeparator},
    //    {"", "autocCancelAtStart", "Boolean", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetCancelAtStart,
    //     (REALproc)xsip_autocSetCancelAtStart},
    //    {"", "autocChooseSingle", "Boolean", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetChooseSingle,
    //     (REALproc)xsip_autocSetChooseSingle},
    //    {"", "autocCaseInsensitiveBehaviour", "Integer", REALpropRuntimeOnly,
    //     (REALproc)xsip_autocGetCaseInsensitiveBehaviour, (REALproc)xsip_autocSetCaseInsensitiveBehaviour},
    //    {"", "autocMulti", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetMulti,
    //     (REALproc)xsip_autocSetMulti},
    //    {"", "autocOrder", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetOrder,
    //     (REALproc)xsip_autocSetOrder},
    //    {"", "autocAutoHide", "Boolean", REALpropRuntimeOnly, (REALproc)xsip_autocGetAutoHide,
    //     (REALproc)xsip_autocSetAutoHide},
    //    {"", "autocDropRestOfWord", "Boolean", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetDropRestOfWord,
    //     (REALproc)xsip_autocSetDropRestOfWord},
    //    {"", "autocTypeSeparator", "Integer", REALpropRuntimeOnly,
    //    (REALproc)xsip_autocGetTypeSeparator,
    //     (REALproc)xsip_autocSetTypeSeparator},
    //    {"", "autocMaxHeight", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetMaxHeight,
    //     (REALproc)xsip_autocSetMaxHeight},
    //    {"", "autocMaxWidth", "Integer", REALpropRuntimeOnly, (REALproc)xsip_autocGetMaxWidth,
    //     (REALproc)xsip_autocSetMaxWidth},
};

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
REALmethodDefinition xsiMethods[] = {
    //+++++++++++++++++++++++++++++++++
    // Computed Properties
    //+++++++++++++++++++++++++++++++++
    /*
     *  Text API
     ====================*/
    {(REALproc)api_setText, REALnoImplementation, "Text(assigns value as String)"},
    {(REALproc)api_getText, REALnoImplementation, "Text() as String"},
    {(REALproc)api_setReadonly, REALnoImplementation, "Readonly(assigns value as Boolean)"},
    {(REALproc)api_getReadonly, REALnoImplementation, "ReadOnly() as Boolean"},

    /*
     *  Error API
     ====================*/
    {(REALproc)api_setStatus, REALnoImplementation, "Status(assigns value as Integer)"},
    {(REALproc)api_getStatus, REALnoImplementation, "Status() as Integer"},

    /*
     *  Event API
     ====================*/
    {(REALproc)api_setModeEventMask, REALnoImplementation, "ModeEventMask(assigns eventMask as Integer)"},
    {(REALproc)api_getModeEventMask, REALnoImplementation, "ModeEventMask() as Integer"},
    {(REALproc)api_setMouseDwellTime, REALnoImplementation, "MouseDwellTime(assigns period as Integer)"},
    {(REALproc)api_getMouseDwellTime, REALnoImplementation, "MouseDwellTime() as Integer"},
    {(REALproc)api_setIdentifier, REALnoImplementation, "Identifier(assigns value as Integer)"},
    {(REALproc)api_getIdentifier, REALnoImplementation, "Identifier() as Integer"},

    /*
     *  Selection API
     ====================*/
    {(REALproc)api_setCurrentPos, REALnoImplementation, "CurrentPos(assigns caret as Integer)"},
    {(REALproc)api_getCurrentPos, REALnoImplementation, "CurrentPos() as Integer"},
    {(REALproc)api_setAnchor, REALnoImplementation, "Anchor(assigns value as Integer)"},
    {(REALproc)api_getAnchor, REALnoImplementation, "Anchor() as Integer"},
    {(REALproc)api_setSelectionStart, REALnoImplementation, "SelectionStart(assigns anchor as Integer)"},
    {(REALproc)api_getSelectionStart, REALnoImplementation, "SelectionStart() as Integer"},
    {(REALproc)api_setSelectionEnd, REALnoImplementation, "SelectionEnd(assigns caret as Integer)"},
    {(REALproc)api_getSelectionEnd, REALnoImplementation, "SelectionEnd() as Integer"},
    {(REALproc)api_setSelectionMode, REALnoImplementation, "SelectionMode(assigns mode as Integer)"},
    {(REALproc)api_getSelectionMode, REALnoImplementation, "SelectionMode() as Integer"},
    {(REALproc)api_setMouseSelectionRectangularSwitch, REALnoImplementation,
     "MouseSelectionRectangularSwitch(assigns mouseSwitch as Integer)"},
    {(REALproc)api_getMouseSelectionRectangularSwitch, REALnoImplementation,
     "MouseSelectionRectangularSwitch() as Integer"},

    /*
     *  Styling API
     ====================*/
    {(REALproc)api_setIdleStyling, REALnoImplementation, "IdleStyling(assigns value as Integer)"},
    {(REALproc)api_getIdleStyling, REALnoImplementation, "IdleStyling() as Integer"},
    {(REALproc)api_setLineState, REALnoImplementation, "LineState(line as Integer, assigns state as Integer)"},
    {(REALproc)api_getLineState, REALnoImplementation, "LineState(line as Integer) as Integer"},

    /*
     *  Style API
     ====================*/
    {(REALproc)api_styleSetFont, REALnoImplementation, "StyleFont(style as Integer, assigns fontName as String)"},
    {(REALproc)api_styleGetFont, REALnoImplementation, "StyleFont(style as Integer) as String"},
    {(REALproc)api_styleSetSize, REALnoImplementation, "StyleSize(style as Integer, assigns sizePoints as Integer)"},
    {(REALproc)api_styleGetSize, REALnoImplementation, "StyleSize(style as Integer) as Integer"},
    {(REALproc)api_styleSetWeight, REALnoImplementation, "StyleWeight(style as Integer, assigns weight as Integer)"},
    {(REALproc)api_styleGetWeight, REALnoImplementation, "StyleWeight(style as Integer) as Integer"},
    {(REALproc)api_styleSetFore, REALnoImplementation, "StyleFore(style as Integer, assigns fore as Color)"},
    {(REALproc)api_styleGetFore, REALnoImplementation, "StyleFore(style as Integer) as Color"},
    {(REALproc)api_styleSetBack, REALnoImplementation, "StyleBack(style as Integer, assigns back as Color)"},
    {(REALproc)api_styleGetBack, REALnoImplementation, "StyleBack(style as Integer) as Color"},
    {(REALproc)api_styleSetVisible, REALnoImplementation, "StyleVisible(style as Integer, assigns visible as Boolean)"},
    {(REALproc)api_styleGetVisible, REALnoImplementation, "StyleVisible(style as Integer) as Boolean"},
    {(REALproc)api_styleSetSizeFractional, REALnoImplementation,
     "StyleSizeFractional(style as Integer, assigns size as Integer)"},
    {(REALproc)api_styleGetSizeFractional, REALnoImplementation, "StyleSizeFractional(style as Integer) as Integer"},
    {(REALproc)api_styleSetBold, REALnoImplementation, "StyleBold(style as Integer, assigns bold as Boolean)"},
    {(REALproc)api_styleGetBold, REALnoImplementation, "StyleBold(style as Integer) as Boolean"},
    {(REALproc)api_styleSetItalic, REALnoImplementation, "StyleItalic(style as Integer, assigns italic as Boolean)"},
    {(REALproc)api_styleGetItalic, REALnoImplementation, "StyleItalic(style as Integer) as Boolean"},
    {(REALproc)api_styleSetUnderline, REALnoImplementation,
     "StyleUnderline(style as Integer, assigns underline as Boolean)"},
    {(REALproc)api_styleGetUnderline, REALnoImplementation, "StyleUnderline(style as Integer) as Boolean"},
    {(REALproc)api_styleSetEOLFilled, REALnoImplementation,
     "StyleEOLFilled(style as Integer, assigns eolFilled as Boolean)"},
    {(REALproc)api_styleGetEOLFilled, REALnoImplementation, "StyleEOLFilled(style as Integer) as Boolean"},
    {(REALproc)api_styleSetCharacterSet, REALnoImplementation,
     "StyleCharacterSet(style as Integer, assigns charSet as Integer)"},
    {(REALproc)api_styleGetCharacterSet, REALnoImplementation, "StyleCharacterSet(style as Integer) as Integer"},
    {(REALproc)api_styleSetCase, REALnoImplementation, "StyleCase(style as Integer, assigns caseVisible as Integer)"},
    {(REALproc)api_styleGetCase, REALnoImplementation, "StyleCase(style as Integer) as Integer"},
    {(REALproc)api_styleSetChangeable, REALnoImplementation,
     "StyleChangeable(style as Integer, assigns change as Boolean)"},
    {(REALproc)api_styleGetChangeable, REALnoImplementation, "StyleChangeable(style as Integer) as Boolean"},
    {(REALproc)api_styleSetHotspot, REALnoImplementation, "StyleHotspot(style as Integer, assigns hotspot as Boolean)"},
    {(REALproc)api_styleGetHotspot, REALnoImplementation, "StyleHotspot(style as Integer) as Boolean"},

    /*
     *  Margin API
     ====================*/
    {(REALproc)api_setMarginLeft, REALnoImplementation, "MarginLeft(assigns pixelWidth as Integer)"},
    {(REALproc)api_getMarginLeft, REALnoImplementation, "MarginLeft() as Integer"},
    {(REALproc)api_setMarginRight, REALnoImplementation, "MarginRight(assigns pixelWidth as Integer)"},
    {(REALproc)api_getMarginRight, REALnoImplementation, "MarginRight() as Integer"},
    {(REALproc)api_marginSetStyleOffset, REALnoImplementation, "MarginStyleOffset(assigns style as Integer)"},
    {(REALproc)api_marginGetStyleOffset, REALnoImplementation, "MarginStyleOffset() as Integer"},
    {(REALproc)api_setMarginOptions, REALnoImplementation, "MarginOptions(assigns options as Integer)"},
    {(REALproc)api_getMarginOptions, REALnoImplementation, "MarginOptions() as Integer"},
    {(REALproc)api_setMarginTypeN, REALnoImplementation, "MarginTypeN(margin as  Integer, assigns type as Integer)"},
    {(REALproc)api_getMarginTypeN, REALnoImplementation, "MarginTypeN(margin as  Integer) as Integer"},
    {(REALproc)api_setMarginWidthN, REALnoImplementation, "MarginWidthN(margin as  Integer, assigns pixel as Integer)"},
    {(REALproc)api_getMarginWidthN, REALnoImplementation, "MarginWidthN(margin as  Integer) as Integer"},
    {(REALproc)api_setMarginBackN, REALnoImplementation, "MarginBackN(margin as  Integer, assigns back as Color)"},
    {(REALproc)api_getMarginBackN, REALnoImplementation, "MarginBackN(margin as  Integer) as Color"},
    {(REALproc)api_setMarginMaskN, REALnoImplementation, "MarginMaskN(margin as  Integer, assigns mask as Integer)"},
    {(REALproc)api_getMarginMaskN, REALnoImplementation, "MarginMaskN(margin as  Integer) as Integer"},
    {(REALproc)api_setMarginSensitiveN, REALnoImplementation,
     "MarginSensitiveN(margin as  Integer, assigns sensitive as Boolean)"},
    {(REALproc)api_getMarginSensitiveN, REALnoImplementation, "MarginSensitiveN(margin as  Integer) as Boolean"},
    {(REALproc)api_setMarginCursorN, REALnoImplementation,
     "MarginCursorN(margin as  Integer, assigns cursor as Integer)"},
    {(REALproc)api_getMarginCursorN, REALnoImplementation, "MarginCursorN(margin as  Integer) as Integer"},
    {(REALproc)api_marginSetText, REALnoImplementation, "MarginText(line as Integer, assigns text as String)"},
    {(REALproc)api_marginGetText, REALnoImplementation, "MarginText(line as Integer) as String"},
    {(REALproc)api_marginSetStyle, REALnoImplementation, "MarginStyle(line as Integer, assigns style as Integer)"},
    {(REALproc)api_marginGetStyle, REALnoImplementation, "MarginStyle(line as Integer) as Integer"},
    {(REALproc)api_marginSetStyles, REALnoImplementation,
     "MarginStyleString(line as Integer, assigns styles as String)"},
    {(REALproc)api_marginGetStyles, REALnoImplementation, "MarginStyleString(line as Integer) as String"},

    /*
     *  Lexer API
     ====================*/
    {(REALproc)api_setLexer, REALnoImplementation, "Lexer(assigns value as Integer)"},
    {(REALproc)api_getLexer, REALnoImplementation, "Lexer() as Integer"},
    {(REALproc)api_setLexerLanguage, REALnoImplementation, "LexerLanguage(assigns language as String)"},
    {(REALproc)api_getLexerLanguage, REALnoImplementation, "LexerLanguage() as String"},

    //+++++++++++++++++++++++++++++++++
    // Methods
    //+++++++++++++++++++++++++++++++++
    /*
     *  Text API
     ============*/
    {(REALproc)api_setSavePoint, REALnoImplementation, "SetSavePoint()"},
    {(REALproc)api_getLine, REALnoImplementation, "GetLine(lineNum as Integer) as String"},
    {(REALproc)api_replaceSel, REALnoImplementation, "ReplaceSel(text as String)"},
    {(REALproc)api_allocate, REALnoImplementation, "Allocate(bytes as Integer)"},
    {(REALproc)api_addText, REALnoImplementation, "AddText(length as Integer, text as String)"},
    {(REALproc)api_appendText, REALnoImplementation, "AppendText(length as Integer, text as String)"},
    {(REALproc)api_insertText, REALnoImplementation, "InsertText(pos as Integer, text as String)"},
    {(REALproc)api_clearAll, REALnoImplementation, "ClearAll()"},
    {(REALproc)api_deleteRange, REALnoImplementation, "DeleteRange(start as Integer, lengthDelete as Integer)"},
    {(REALproc)api_clearDocumentStyle, REALnoImplementation, "ClearDocumentStyle()"},
    {(REALproc)api_getCharAt, REALnoImplementation, "GetCharAt(pos as Integer) as String"},
    {(REALproc)api_getStyleAt, REALnoImplementation, "GetStyleAt(pos as Integer) as Integer"},
    {(REALproc)api_releaseAllExtendedStyles, REALnoImplementation, "ReleaseAllExtendedStyle()"},
    {(REALproc)api_allocateExtendedStyles, REALnoImplementation,
     "AllocateExtendedStyles(numberStyles as Integer) as Integer"},
    {(REALproc)api_getTextRange, REALnoImplementation, "TextRange(startPos as Integer, endPos as Integer) as String"},
    {(REALproc)api_targetAsUtf8, REALnoImplementation, "TargetAsUTF8() as String"},
    {(REALproc)api_encodeFromUtf8, REALnoImplementation, "EncodeFromUTF8(length as Integer, utf8 as String) as String"},
    {(REALproc)api_addStyledText, REALnoImplementation, "AddStyledText(length as Integer, styled_text as String)"},
    {(REALproc)api_getStyledText, REALnoImplementation,
     "GetStyledText(startPos as Integer, endPos as Integer) as String"},
    {(REALproc)api_changeInsertion, REALnoImplementation, "ChangeInsertion(length as Integer, text as String)"},

    /*
     *  Selection API
     ====================*/
    {(REALproc)api_getTextLength, REALnoImplementation, "GetTextLength() as Integer"},
    {(REALproc)api_getLength, REALnoImplementation, "GetLength() as Integer"},
    {(REALproc)api_getLineCount, REALnoImplementation, "GetLineCount() as Integer"},
    {(REALproc)api_lineOnScreen, REALnoImplementation, "LineOnScreen() as Integer"},
    {(REALproc)api_getModify, REALnoImplementation, "GetModify() as Boolean"},
    {(REALproc)api_hideSelection, REALnoImplementation, "HideSelection(hide as Integer)"},
    {(REALproc)api_getSeltext, REALnoImplementation, "GetSelText() as String"},
    {(REALproc)api_selectionIsRectangle, REALnoImplementation, "SelectionIsRectangle() as Boolean"},
    {(REALproc)api_setSel, REALnoImplementation, "SetSel(anchor as Integer, caret as Integer)"},
    {(REALproc)api_gotoPos, REALnoImplementation, "GotoPos(caret as Integer)"},
    {(REALproc)api_gotoLine, REALnoImplementation, "GotoLine(line as Integer)"},
    {(REALproc)api_setEmptySelection, REALnoImplementation, "SetEmptySelection(caret as Integer)"},
    {(REALproc)api_selectAll, REALnoImplementation, "SelectAll()"},
    {(REALproc)api_lineFromPosition, REALnoImplementation, "LineFromPosition(pos as Integer) as Integer"},
    {(REALproc)api_positionFromLine, REALnoImplementation, "PositionFromLine(line as Integer) as Integer"},
    {(REALproc)api_getLineEndPosition, REALnoImplementation, "GetLineEndPosition(line as Integer) as Integer"},
    {(REALproc)api_lineLength, REALnoImplementation, "LineLength(line as Integer) as Integer"},
    {(REALproc)api_getColumn, REALnoImplementation, "GetColumn(pos as Integer) as Integer"},
    {(REALproc)api_findColumn, REALnoImplementation, "FindColumn(line as Integer, column as Integer) as Integer "},
    {(REALproc)api_positionFromPoint, REALnoImplementation, "PositionFromPoint(x as Integer, y as Integer) as Integer"},
    {(REALproc)api_positionFromPointClose, REALnoImplementation,
     "PositionFromPointClose(x as Integer, y as Integer) as Integer"},
    {(REALproc)api_charPositionFromPoint, REALnoImplementation,
     "CharPositionFromPoint(x as Integer, y as Integer) as Integer"},
    {(REALproc)api_charPositionFromPointClose, REALnoImplementation,
     "CharPositionFromPointClose(x as Integer, y as Integer) as Integer"},
    {(REALproc)api_pointXFromPosition, REALnoImplementation, "PointXFromPosition(pos as Integer) as Integer"},
    {(REALproc)api_pointYFromPosition, REALnoImplementation, "PointYFromPosition(pos as Integer) as Integer"},
    {(REALproc)api_getCurLine, REALnoImplementation, "GetCurLine() as String"},
    {(REALproc)api_getLineSelStartPosition, REALnoImplementation,
     "GetLineSelStartPosition(line as Integer) as Integer"},
    {(REALproc)api_getLineSelEndPosition, REALnoImplementation, "GetLineSelEndPosition(line as Integer) as Integer "},
    {(REALproc)api_moveCaretInsideView, REALnoImplementation, "MoveCaretInsideView()"},
    {(REALproc)api_positionBefore, REALnoImplementation, "PositionBefore(pos as Integer) as Integer"},
    {(REALproc)api_positionAfter, REALnoImplementation, "PositionAfter(pos as Integer) as Integer"},
    {(REALproc)api_positionRelative, REALnoImplementation,
     "PositionRelative(pos as Integer, relative as Integer) as Integer"},
    {(REALproc)api_countCharacters, REALnoImplementation,
     "CountCharacters(posStart as Integer, posEnd as Integer) as Integer"},
    {(REALproc)api_textWidth, REALnoImplementation, "TextWidth(style as Integer, text as String) as Integer"},
    {(REALproc)api_textHeight, REALnoImplementation, "TextHeight(line as Integer) as Integer"},
    {(REALproc)api_chooseCaretX, REALnoImplementation, "ChooseCaretX()"},
    {(REALproc)api_moveSelectedLinesUp, REALnoImplementation, "MoveSelectedLinesUp()"},
    {(REALproc)api_moveSelectedLinesDown, REALnoImplementation, "MoveSelectedLinesDown()"},

    /*
     *  Styling API
     ====================*/
    {(REALproc)api_getEndStyled, REALnoImplementation, "GetEndStyled() as Integer"},
    {(REALproc)api_startStyling, REALnoImplementation, "StartStyling(start as Integer)"},
    {(REALproc)api_setStyling, REALnoImplementation, "SetStyling(start as Integer, style as Integer)"},
    {(REALproc)api_setStylingEx, REALnoImplementation, "SetStylingEx(length as Integer, styles as String)"},
    {(REALproc)api_getMaxLineState, REALnoImplementation, "GetMaxLineState() as Integer"},

    /*
     *  Style API
     ====================*/
    {(REALproc)api_styleResetDefault, REALnoImplementation, "StyleResetDefault()"},
    {(REALproc)api_styleClearAll, REALnoImplementation, "StyleClearAll()"},

    /*
     *  Margin API
     ====================*/
    {(REALproc)api_setMargins, REALnoImplementation, "SetMargins(margins as Integer)"},
    {(REALproc)api_getMargins, REALnoImplementation, "GetMargins() as Integer"},
    {(REALproc)api_marginTextClearAll, REALnoImplementation, "MarginTextClearAll"},
    {(REALproc)api_setFoldMarginColour, REALnoImplementation, "MarginFoldColour(useSetting as Boolean, back as Color)"},
    {(REALproc)api_setFoldMarginHiColour, REALnoImplementation,
     "MarginFoldHiColour(useSetting as Boolean, fore as Color)"},

    /*
     *  Lexer API
     ====================*/
    {(REALproc)api_colourise, REALnoImplementation, "Colourise(posStart as Integer, posEnd as Integer)"},
    {(REALproc)api_changeLexerState, REALnoImplementation, "ChangeLexerState(posStart as Integer, posEnd as Integer)"},
    {(REALproc)api_describeKeywordSets, REALnoImplementation, "DescribeKeywordSets() as String"},
    {(REALproc)api_setKeywords, REALnoImplementation, "SetKeywords(keywordSet as Integer, keywords as String)"},
    {(REALproc)api_setProperty, REALnoImplementation, "SetProperty(key as String, value as String)"},
    {(REALproc)api_getProperty, REALnoImplementation, "GetProperty(key as String) as String"},
    {(REALproc)api_loadLexerLibrary, REALnoImplementation, "LoadLexerLibrary(path as String)"},
    {(REALproc)api_propertyNames, REALnoImplementation, "PropertyNames() as String"},
    {(REALproc)api_propertyType, REALnoImplementation, "PropertyType(name as String) as Integer"},
    {(REALproc)api_describeProperty, REALnoImplementation, "DescribeProperty(name as String) as String"},
    {(REALproc)api_getPropertyExpanded, REALnoImplementation, "GetPropertyExpanded(key as String, value as String)"},
    {(REALproc)api_getPropertyInt, REALnoImplementation, "GetPropertyInt(key as String, defaultValue as Integer)"},
    {(REALproc)api_getSubstyleBases, REALnoImplementation, "GetSubstyleBases() as String"},
    {(REALproc)api_distanceToSecondaryStyles, REALnoImplementation, "DistanceToSecondaryStyles() as Integer"},
    {(REALproc)api_allocateSubstyles, REALnoImplementation,
     "AllocateSubstyles(styleBase as Integer, numberStyles as Integer)"},
    {(REALproc)api_freeSubstyles, REALnoImplementation, "FreeSubstyles()"},
    {(REALproc)api_getSubstylesStart, REALnoImplementation, "GetSubstylesStart(styleBase as Integer) as Integer"},
    {(REALproc)api_getSubstylesLength, REALnoImplementation, "GetSubstylesLength(styleBase as Integer) as Integer"},
    {(REALproc)api_getStyleFromSubstyle, REALnoImplementation, "GetStyleFromSubstyle(subStyle as Integer) as Integer"},
    {(REALproc)api_getPrimaryStyleFromStyle, REALnoImplementation,
     "GetPrimaryStyleFromStyle(style as Integer) as Integer"},
    {(REALproc)api_setIdentifiers, REALnoImplementation, "SetIdentifiers(style as Integer, identifiers as String)"},
    {(REALproc)api_privateLexerCall, REALnoImplementation,
     "PrivateLexerCall(operation as Integer, pointer as Integer)"},

    //
    //    /*+++++++++++++++++++++++++
    //     * sci-marker.h
    //     +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_markerDefine, REALnoImplementation,
    //     "MarkerDefine(markerNumber as ScMarkNum, markerSymbol as ScMarker)"},
    //    {(REALproc)xsim_markerSetFore, REALnoImplementation,
    //     "MarkerSetFore(markerNumber as ScMarkNum, assigns fore as Color)"},
    //    {(REALproc)xsim_markerSetBack, REALnoImplementation,
    //     "MarkerSetBack(markerNumber as ScMarkNum, assigns back as Color)"},
    //    {(REALproc)xsim_markerSetBackSelected, REALnoImplementation,
    //     "MarkerSetBackSelected(markerNumber as ScMarkNum, assigns back as Color)"},
    //    {(REALproc)xsim_markerDefineRgbaImage, REALnoImplementation,
    //     "MarkerDefineRgbaImage(markerNumber as ScMarkNum, assigns pixel as String)"},
    //    {(REALproc)xsim_markerSymbolDefined, REALnoImplementation,
    //     "MarkerSymbolDefined(markerNumber as ScMarkNum) as Integer"},
    //    {(REALproc)xsim_markerAdd, REALnoImplementation,
    //     "MarkerAdd(line as Integer, markerNumber as ScMarkNum) as Integer"},
    //    {(REALproc)xsim_markerAddSet, REALnoImplementation, "MarkerAddSet(line as Integer, markerNumber as
    //    ScMarkNum)"},
    //    {(REALproc)xsim_markerDelete, REALnoImplementation, "MarkerDelete(line as Integer, markerNumber as
    //    ScMarkNum)"},
    //    {(REALproc)xsim_markerDeleteAll, REALnoImplementation, "MarkerDeleteAll(markerNumber as ScMarkNum)"},
    //    {(REALproc)xsim_markerGet, REALnoImplementation, "MarkerGet(line as Integer) as Integer"},
    //    {(REALproc)xsim_markerNext, REALnoImplementation,
    //     "MarkerNext(lineStart as Integer, markerMask as Integer) as Integer"},
    //    {(REALproc)xsim_markerPrevious, REALnoImplementation,
    //     "MarkerPrevious(lineStart as Integer, markerMask as Integer) as Integer"},
    //
    //    /*+++++++++++++++++++++++++
    //     * sci-autoc.h
    //     +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_autocShow, REALnoImplementation, "AutocShow(lengthEntered as Integer, itemList as
    //    String)"},
    //    {(REALproc)xsim_autocCancel, REALnoImplementation, "AutocCancel()"},
    //    {(REALproc)xsim_autocActive, REALnoImplementation, "AutocActive() as Boolean"},
    //    {(REALproc)xsim_autocComplete, REALnoImplementation, "AutocComplete()"},
    //    {(REALproc)xsim_autocPosStart, REALnoImplementation, "AutocPosStart() as Integer"},
    //    {(REALproc)xsim_autocStops, REALnoImplementation, "AutocStops(characterSet as String)"},
    //    {(REALproc)xsim_autocSelect, REALnoImplementation, "AutocSelect(selectText as String)"},
    //    {(REALproc)xsim_autocGetCurrent, REALnoImplementation, "AutocGetCurrent()"},
    //    {(REALproc)xsim_autocGetCurrentText, REALnoImplementation, "AutocGetCurrentText() as String"},
    //    {(REALproc)xsim_autocSetFillUps, REALnoImplementation, "AutocSetFillUps(characterSet as String)"},
    //    /*+++++++++++++++++++++++++
    //     * sci-words.h
    //     +++++++++++++++++++++++++*/
    //    {(REALproc)xsim_wordStartPosition, REALnoImplementation,
    //     "WordStartPosition(pos as Integer, onlyWordCharacters as Boolean) as Integer"},
};

//+++++++++++++++++++++++++++++++++
// Events
//+++++++++++++++++++++++++++++++++
REALevent xsiEvents[] = {
    // declaration, forSystemUse, attributeCount, attributes
    {"MouseDown(x as Integer, y as Integer) as Boolean"},
    {"StyleNeeded(position as Integer)"},
    {"CharAdded(ch as Integer)"},
    {"SavePointReached()"},
    {"SavePointLeft()"},
    {"ModifyAttemptReadonly()"},
    {"ScnKey(ch as Integer)"},
    {"DoubleClick(position as Integer, modifiers as Integer)"},
    {"UpdateUI(updated as Integer)"},
    {"Modified(pos as Integer, type as Integer, text as String, length as Integer, linesAdded as Integer, "
     "line as Integer, foldNow as Integer, foldPrev as Integer, token as Integer, changeAnnot as Integer)"},
    {"MacroRecord(message as Integer, wParam as Integer, lParam as Integer)"},
    {"MarginClick(position as Integer, margin as Integer)"},
    {"NeedShown(position as Integer)"},
    {"Painted()"},
    {"UserListSelection(position as Integer, ch as Integer, text as String, listType as Integer, "
     "listCompletionMethod as Integer)"},
    {"UriDropped(text as String)"},
    {"DwellStart(position as Integer, x as Integer, y as Integer)"},
    {"DwellEnd(position as Integer, x as Integer, y as Integer)"},
    {"Zoom()"},
    {"HotspotClick(position as Integer, modifiers as Integer)"},
    {"HotspotDoubleClick(position as Integer, modifiers as Integer)"},
    {"CallTipClick(position as Integer)"},
    {"AutocSelection(position as Integer, ch as Integer, listCompletionMethod as Integer)"},
    {"IndicatorClick(position as Integer, modifiers as Integer)"},
    {"IndicatorRelease(position as Integer, modifiers as Integer)"},
    {"AutocCancelled()"},
    {"AutocCharDeleted()"},
    {"HotspotReleaseClick(position as Integer, modifiers as Integer)"},
    {"FocusIn()"},
    {"FocusOut()"},
    {"AutocCompleted(ch as Integer, listCompletionMethod as Integer)"},
    {"MarginRightClick()"},
};

//+++++++++++++++++++++++++++++++++
// Behaviour
//+++++++++++++++++++++++++++++++++
REALcontrolBehaviour xsiBehavior = {
    Constructor,           // constructorFunction
    NULL,                  // destructorFunction
    NULL,                  // redrawFunction
    NULL,                  // clickFunction
    NULL,                  // mouseDragFunction
    NULL,                  // mouseUpFunction
    NULL,                  // gainedFocusFunction
    NULL,                  // lostFocusFunction
    OnKeyDownFunction,     // keyDownFunction
    OnOpen,                // openFunction
    NULL,                  // closeFunction
    NULL,                  // backgroundIdleFunction
    OnDrawOffscreen,       // drawOffscreenFunction
    NULL,                  // setSpecialBackground
    NULL,                  // constantChanging
    NULL,                  // droppedNewInstance
    NULL,                  // mouseEnterFunction
    NULL,                  // mouseExitFunction
    NULL,                  // mouseMoveFunction
    NULL,                  // stateChangedFunction
    NULL,                  // actionEventFunction
    OnControlHandleGetter, // controlHandleGetter
    NULL,                  // mouseWheelFunction
    NULL,                  // enableMenuItemsFunction
    NULL,                  // menuItemActionFunction
    NULL,                  // controlAcceptFocus
    NULL,                  // keyUpFunction
    NULL,                  // redrawWithRectsFunction
    NULL,                  // unfilteredKeyDownFunction
    NULL,                  // scaleFactorChangedFunction
    NULL,                  // reserved2
    NULL                   // reserved3
    // end of struct
};

//+++++++++++++++++++++++++++++++++
// Constants
//+++++++++++++++++++++++++++++++++
REALconstant xsiConstant[] = {
    {"StyleMax as Integer = 255"},          // STYLE_MAX 255
    {"MarkerMax as Integer = 31"},          // MARKER_MAX 31
    {"MaskFolder as Integer = &hFE000000"}, // SC_MASK_FOLDERS 0xFE000000
};

//+++++++++++++++++++++++++++++++++
// Enumerations
//+++++++++++++++++++++++++++++++++
static const char* enumSelection[] = {
    "STREAM = 0",    // SC_SEL_STREAM=0
    "RECTANGLE = 1", // SC_SEL_RECTANGLE=1
    "LINES = 2",     // SC_SEL_LINES=2
    "THIN = 3",      // SC_SEL_THIN=3
};

REALenum EnumDef[] = {
    // name, type, mFlags, fields, numFields, attributeCount, attributes
    {"eSelection", "Int8", REALScopePublic, enumSelection, 4},
};

//+++++++++++++++++++++++++++++++++
// xsintilla Control
//+++++++++++++++++++++++++++++++++
REALcontrol xsiControl = {
    kCurrentREALControlVersion,                        // version
    "xsintilla",                                       // name
    sizeof(xsiControlData),                            // dataSize
    REALcontrolAcceptFocus,                            // flags
    128,                                               // toolbarPICT
    128,                                               // toolbarDownPICT
    100,                                               // defaultWidth
    100,                                               // defaultHeight
    xsiProperties,                                     // properties
    sizeof(xsiProperties) / sizeof(REALproperty),      // propertyCount
    xsiMethods,                                        // methods
    sizeof(xsiMethods) / sizeof(REALmethodDefinition), // methodCount
    xsiEvents,                                         // events
    sizeof(xsiEvents) / sizeof(REALevent),             // eventCount
    &xsiBehavior,                                      // behaviour
    0,                                                 // forSystemUse, always zero
    NULL,                                              // eventInstances
    0,                                                 // eventInstanceCount
    NULL,                                              // interfaces
    NULL,                                              // attributes
    0,                                                 // attributeCount
    xsiConstant,                                       // constants
    sizeof(xsiConstant) / sizeof(REALconstant),        // constantCount
#if kCurrentREALControlVersion >= 11                   // since Xojo 2013R1
    NULL,                                              // sharedProperties
    0,                                                 // sharedPropertyCount
    NULL,                                              // sharedMethods
    0,                                                 // sharedMethodCount
    NULL,                                              // delegates
    0,                                                 // delegateCount
    EnumDef,                                           // enums
    sizeof(EnumDef) / sizeof(REALenum),                // enumCount
#endif
    // end of structure
};

void registerPlugin(void)
{
    REALRegisterControl(&xsiControl);
}
