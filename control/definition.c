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
    {"kSTYLE_MAX as Integer = 255"},            // STYLE_MAX 255
    {"kMARKER_MAX as Integer = 31"},            // MARKER_MAX 31
    {"kMAX_MARGIN as Integer = 4"},             // SC_MAX_MARGIN 4
    {"kKEYWORDSET_MAX as Integer = 8"},         // KEYWORDSET_MAX 8
    {"kCP_UTF8 as Integer = 65001"},            // SC_CP_UTF8 65001
    {"kTIME_FOREVER as Integer = 10000000"},    // SC_TIME_FOREVER 10000000
    {"kFONT_SIZE_MULTIPLIER as Integer = 100"}, // SC_FONT_SIZE_MULTIPLIER 100
    {"kUNDO_MAY_COALESCE as Integer = 1"},      // UNDO_MAY_COALESCE 1

    // Style definition
    {"kSTYLE_DEFAULT as Integer = 32"},         // STYLE_DEFAULT 32
    {"kSTYLE_LINENUMBER as Integer = 33"},      // STYLE_LINENUMBER 33
    {"kSTYLE_BRACELIGHT as Integer = 34"},      // STYLE_BRACELIGHT 34
    {"kSTYLE_BRACEBAD as Integer = 35"},        // STYLE_BRACEBAD 35
    {"kSTYLE_CONTROLCHAR as Integer = 36"},     // STYLE_CONTROLCHAR 36
    {"kSTYLE_INDENTGUIDE as Integer = 37"},     // STYLE_INDENTGUIDE 37
    {"kSTYLE_CALLTIP as Integer = 38"},         // STYLE_CALLTIP 38
    {"kSTYLE_FOLDDISPLAYTEXT as Integer = 39"}, // STYLE_FOLDDISPLAYTEXT 39
    {"kSTYLE_LASTPREDEFINED as Integer = 39"},  // STYLE_LASTPREDEFINED 39

    // used in SCI_PROPERTYTYPE
    {"kTYPE_BOOLEAN as Integer = 0"}, // SC_TYPE_BOOLEAN 0
    {"kTYPE_INTEGER as Integer = 1"}, // SC_TYPE_INTEGER 1
    {"kTYPE_STRING as Integer = 2"},  // SC_TYPE_STRING 2

    // used in SCI_SETMARGINTYPEN
    {"kMARGIN_SYMBOL as Integer = 0"}, // SC_MARGIN_SYMBOL 0
    {"kMARGIN_NUMBER as Integer = 1"}, // SC_MARGIN_NUMBER 1
    {"kMARGIN_BACK as Integer = 2"},   // SC_MARGIN_BACK 2
    {"kMARGIN_FORE as Integer = 3"},   // SC_MARGIN_FORE 3
    {"kMARGIN_TEXT as Integer = 4"},   // SC_MARGIN_TEXT 4
    {"kMARGIN_RTEXT as Integer = 5"},  // SC_MARGIN_RTEXT 5
    {"kMARGIN_COLOUR as Integer = 6"}, // SC_MARGIN_COLOUR 6

    // used in SCI_SETMARGINOPTIONS
    {"kMARGINOPTION_NONE as Integer = 0"},          // SC_MARGINOPTION_NONE 0
    {"kMARGINOPTION_SUBLINESELECT as Integer = 1"}, // SC_MARGINOPTION_SUBLINESELECT 1

    // used in SCI_MARKERDEFINE
    {"kMARK_CIRCLE as Integer = 0"},                // SC_MARK_CIRCLE 0
    {"kMARK_ROUNDRECT as Integer = 1"},             // SC_MARK_ROUNDRECT 1
    {"kMARK_ARROW as Integer = 2"},                 // SC_MARK_ARROW 2
    {"kMARK_SMALLRECT as Integer = 3"},             // SC_MARK_SMALLRECT 3
    {"kMARK_SHORTARROW as Integer = 4"},            // SC_MARK_SHORTARROW 4
    {"kMARK_EMPTY as Integer = 5"},                 // SC_MARK_EMPTY 5
    {"kMARK_ARROWDOWN as Integer = 6"},             // SC_MARK_ARROWDOWN 6
    {"kMARK_MINUS as Integer = 7"},                 // SC_MARK_MINUS 7
    {"kMARK_PLUS as Integer = 8"},                  // SC_MARK_PLUS 8
    {"kMARK_VLINE as Integer = 9"},                 // SC_MARK_VLINE 9
    {"kMARK_LCORNER as Integer = 10"},              // SC_MARK_LCORNER 10
    {"kMARK_TCORNER as Integer = 11"},              // SC_MARK_TCORNER 11
    {"kMARK_BOXPLUS as Integer = 12"},              // SC_MARK_BOXPLUS 12
    {"kMARK_BOXPLUSCONNECTED as Integer = 13"},     // SC_MARK_BOXPLUSCONNECTED 13
    {"kMARK_BOXMINUS as Integer = 14"},             // SC_MARK_BOXMINUS 14
    {"kMARK_BOXMINUSCONNECTED as Integer = 15"},    // SC_MARK_BOXMINUSCONNECTED 15
    {"kMARK_LCORNERCURVE as Integer = 16"},         // SC_MARK_LCORNERCURVE 16
    {"kMARK_TCORNERCURVE as Integer = 17"},         // SC_MARK_TCORNERCURVE 17
    {"kMARK_CIRCLEPLUS as Integer = 18"},           // SC_MARK_CIRCLEPLUS 18
    {"kMARK_CIRCLEPLUSCONNECTED as Integer = 19"},  // SC_MARK_CIRCLEPLUSCONNECTED 19
    {"kMARK_CIRCLEMINUS as Integer = 20"},          // SC_MARK_CIRCLEMINUS 20
    {"kMARK_CIRCLEMINUSCONNECTED as Integer = 21"}, // SC_MARK_CIRCLEMINUSCONNECTED 21
    {"kMARK_BACKGROUND as Integer = 22"},           // SC_MARK_BACKGROUND 22
    {"kMARK_DOTDOTDOT as Integer = 23"},            // SC_MARK_DOTDOTDOT 23
    {"kMARK_ARROWS as Integer = 24"},               // SC_MARK_ARROWS 24
    {"kMARK_PIXMAP as Integer = 25"},               // SC_MARK_PIXMAP 25
    {"kMARK_FULLRECT as Integer = 26"},             // SC_MARK_FULLRECT 26
    {"kMARK_LEFTRECT as Integer = 27"},             // SC_MARK_LEFTRECT 27
    {"kMARK_AVAILABLE as Integer = 28"},            // SC_MARK_AVAILABLE 28
    {"kMARK_UNDERLINE as Integer = 29"},            // SC_MARK_UNDERLINE 29
    {"kMARK_RGBAIMAGE as Integer = 30"},            // SC_MARK_RGBAIMAGE 30
    {"kMARK_BOOKMARK as Integer = 31"},             // SC_MARK_BOOKMARK 31
    {"kMARK_CHARACTER as Integer = 10000"},         // SC_MARK_CHARACTER 10000
    {"kMARKNUM_FOLDEREND as Integer = 25"},         // SC_MARKNUM_FOLDEREND 25
    {"kMARKNUM_FOLDEROPENMID as Integer = 26"},     // SC_MARKNUM_FOLDEROPENMID 26
    {"kMARKNUM_FOLDERMIDTAIL as Integer = 27"},     // SC_MARKNUM_FOLDERMIDTAIL 27
    {"kMARKNUM_FOLDERTAIL as Integer = 28"},        // SC_MARKNUM_FOLDERTAIL 28
    {"kMARKNUM_FOLDERSUB as Integer = 29"},         // SC_MARKNUM_FOLDERSUB 29
    {"kMARKNUM_FOLDER as Integer = 30"},            // SC_MARKNUM_FOLDER 30
    {"kMARKNUM_FOLDEROPEN as Integer = 31"},        // SC_MARKNUM_FOLDEROPEN 31
    {"kMASK_FOLDERS as Integer = &hFE000000"},      // SC_MASK_FOLDERS 0xFE000000

    // used in SCI_SETSTATUS
    {"kSTATUS_OK as Integer = 0"},         // SC_STATUS_OK 0
    {"kSTATUS_FAILURE as Integer = 1"},    // SC_STATUS_FAILURE 1
    {"kSTATUS_BADALLOC as Integer = 2"},   // SC_STATUS_BADALLOC 2
    {"kSTATUS_WARN_START as Integer = 3"}, // SC_STATUS_WARN_START 1000
    {"kSTATUS_WARN_REGEX as Integer = 4"}, // SC_STATUS_WARN_REGEX 1001

    // used in SCI_SETSELECTIONMODE
    {"kSEL_STREAM as Integer = 0"},    // SC_SEL_STREAM 0
    {"kSEL_RECTANGLE as Integer = 1"}, // SC_SEL_RECTANGLE 1
    {"kSEL_LINES as Integer = 2"},     // SC_SEL_LINES 2
    {"kSEL_THIN as Integer = 3"},      // SC_SEL_THIN 3

    // used in SCI_SETIDLESTYLING
    {"kIDLESTYLING_NONE as Integer = 0"},         // SC_IDLESTYLING_NONE 0
    {"kIDLESTYLING_TOVISIBLE as Integer = 1"},    // SC_IDLESTYLING_TOVISIBLE 1
    {"kIDLESTYLING_AFTERVISIBLE as Integer = 2"}, // SC_IDLESTYLING_AFTERVISIBLE 2
    {"kIDLESTYLING_ALL as Integer = 3"},          // SC_IDLESTYLING_ALL 3

    // used in SCI_SETFOLDLEVEL
    {"kFOLDLEVEL_BASE as Integer = &h400"},        // SC_FOLDLEVELBASE 0x400
    {"kFOLDLEVEL_WHITEFLAG as Integer = &h1000"},  // SC_FOLDLEVELWHITEFLAG 0x1000
    {"kFOLDLEVEL_HEADERFLAG as Integer = &h2000"}, // SC_FOLDLEVELHEADERFLAG 0x2000
    {"kFOLDLEVEL_NUMBERMASK as Integer = &h0FFF"}, // SC_FOLDLEVELNUMBERMASK 0x0FFF

    // used in SCI_FOLDLINE
    {"kFOLDACTION_CONTRACT as Integer = 0"}, // SC_FOLDACTION_CONTRACT 0
    {"kFOLDACTION_EXPAND as Integer = 1"},   // SC_FOLDACTION_EXPAND 1
    {"kFOLDACTION_TOGGLE as Integer = 2"},   // SC_FOLDACTION_TOGGLE 2

    // used in SCI_SETAUTOMATICFOLD
    {"kAUTOMATICFOLD_SHOW as Integer = &h0001"},   // SC_AUTOMATICFOLD_SHOW 0x0001
    {"kAUTOMATICFOLD_CLICK as Integer = &h0002"},  // SC_AUTOMATICFOLD_CLICK 0x0002
    {"kAUTOMATICFOLD_CHANGE as Integer = &h0004"}, // SC_AUTOMATICFOLD_CHANGE 0x0004

    // used in SCI_SETFOLDFLAGS
    {"kFOLDFLAG_LINEBEFORE_EXPANDED as Integer = &h0002"},   // SC_FOLDFLAG_LINEBEFORE_EXPANDED 0x0002
    {"kFOLDFLAG_LINEBEFORE_CONTRACTED as Integer = &h0004"}, // SC_FOLDFLAG_LINEBEFORE_CONTRACTED 0x0004
    {"kFOLDFLAG_LINEAFTER_EXPANDED as Integer = &h0008"},    // SC_FOLDFLAG_LINEAFTER_EXPANDED 0x0008
    {"kFOLDFLAG_LINEAFTER_CONTRACTED as Integer = &h0010"},  // SC_FOLDFLAG_LINEAFTER_CONTRACTED 0x0010
    {"kFOLDFLAG_LEVELNUMBERS as Integer = &h0040"},          // SC_FOLDFLAG_LEVELNUMBERS 0x0040
    {"kFOLDFLAG_LINESTATE as Integer = &h0080"},             // SC_FOLDFLAG_LINESTATE 0x0080

    // used in SCI_SETCURSOR & SCI_SETMARGINCURSORN
    {"kCURSOR_NORMAL as Integer = -1"},       // SC_CURSORNORMAL -1
    {"kCURSOR_ARROW as Integer = 2"},         // SC_CURSORARROW 2
    {"kCURSOR_WAIT as Integer = 4"},          // SC_CURSORWAIT 4
    {"kCURSOR_REVERSE_ARROW as Integer = 7"}, // SC_CURSORREVERSEARROW 7

    // used in SCI_SETVIEWWS
    {"kWS_INVISIBLE as Integer = 0"},           // SCWS_INVISIBLE 0
    {"kWS_VISIBLEALWAYS as Integer = 1"},       // SCWS_VISIBLEALWAYS 1
    {"kWS_VISIBLEAFTERINDENT as Integer = 2"},  // SCWS_VISIBLEAFTERINDENT 2
    {"kWS_VISIBLEONLYININDENT as Integer = 3"}, // SCWS_VISIBLEONLYININDENT 3

    // used in SCI_SETTABDRAWMODE
    {"kTAB_LONGARROW as Integer = 0"}, // SCTD_LONGARROW 0
    {"kTAB_STRIKEOUT as Integer = 1"}, // SCTD_STRIKEOUT 1

    // used in SCI_SETEOLMODE
    {"kEOL_CRLF as Integer = 0"}, // SC_EOL_CRLF 0
    {"kEOL_CR as Integer = 1"},   // SC_EOL_CR 1
    {"kEOL_LF as Integer = 2"},   // SC_EOL_LF 2

    // used in SCI_SETIMEINTERACTION
    {"kIME_WINDOWED as Integer = 0"}, // SC_IME_WINDOWED 0
    {"kIME_INLINE as Integer = 1"},   // SC_IME_INLINE 1

    // used in SCI_STYLESETCHARACTERSET
    {"kCHARSET_ANSI as Integer = 0"},          // SC_CHARSET_ANSI 0
    {"kCHARSET_DEFAULT as Integer = 1"},       // SC_CHARSET_DEFAULT 1
    {"kCHARSET_BALTIC as Integer = 186"},      // SC_CHARSET_BALTIC 186
    {"kCHARSET_CHINESEBIG5 as Integer = 136"}, // SC_CHARSET_CHINESEBIG5 136
    {"kCHARSET_EASTEUROPE as Integer = 238"},  // SC_CHARSET_EASTEUROPE 238
    {"kCHARSET_GB2312 as Integer = 134"},      // SC_CHARSET_GB2312 134
    {"kCHARSET_GREEK as Integer = 161"},       // SC_CHARSET_GREEK 161
    {"kCHARSET_HANGUL as Integer = 129"},      // SC_CHARSET_HANGUL 129
    {"kCHARSET_MAC as Integer = 77"},          // SC_CHARSET_MAC 77
    {"kCHARSET_OEM as Integer = 255"},         // SC_CHARSET_OEM 255
    {"kCHARSET_RUSSIAN as Integer = 204"},     // SC_CHARSET_RUSSIAN 204
    {"kCHARSET_OEM866 as Integer = 866"},      // SC_CHARSET_OEM866 866
    {"kCHARSET_CYRILLIC as Integer = 1251"},   // SC_CHARSET_CYRILLIC 1251
    {"kCHARSET_SHIFTJIS as Integer = 128"},    // SC_CHARSET_SHIFTJIS 128
    {"kCHARSET_SYMBOL as Integer = 2"},        // SC_CHARSET_SYMBOL 2
    {"kCHARSET_TURKISH as Integer = 162"},     // SC_CHARSET_TURKISH 162
    {"kCHARSET_JOHAB as Integer = 130"},       // SC_CHARSET_JOHAB 130
    {"kCHARSET_HEBREW as Integer = 177"},      // SC_CHARSET_HEBREW 177
    {"kCHARSET_ARABIC as Integer = 178"},      // SC_CHARSET_ARABIC 178
    {"kCHARSET_VIETNAMESE as Integer = 163"},  // SC_CHARSET_VIETNAMESE 163
    {"kCHARSET_THAI as Integer = 222"},        // SC_CHARSET_THAI 222
    {"kCHARSET_8859_15 as Integer = 1000"},    // SC_CHARSET_8859_15 1000

    // used in SCI_STYLESETCASE
    {"kCASE_MIXED as Integer = 0"}, // SC_CASE_MIXED 0
    {"kCASE_UPPER as Integer = 1"}, // SC_CASE_UPPER 1
    {"kCASE_LOWER as Integer = 2"}, // SC_CASE_LOWER 2
    {"kCASE_CAMEL as Integer = 3"}, // SC_CASE_CAMEL 3

    // used in SCI_STYLESETWEIGHT
    {"kWEIGHT_NORMAL as Integer = 400"},   // SC_WEIGHT_NORMAL 400
    {"kWEIGHT_SEMIBOLD as Integer = 600"}, // SC_WEIGHT_SEMIBOLD 600
    {"kWEIGHT_BOLD as Integer = 700"},     // SC_WEIGHT_BOLD 700

    // used in SCI_INDICSETSTYLE
    {"kINDIC_PLAIN as Integer = 0"},             // INDIC_PLAIN 0
    {"kINDIC_SQUIGGLE as Integer = 1"},          // INDIC_SQUIGGLE 1
    {"kINDIC_TT as Integer = 2"},                // INDIC_TT 2
    {"kINDIC_DIAGONAL as Integer = 3"},          // INDIC_DIAGONAL 3
    {"kINDIC_STRIKE as Integer = 4"},            // INDIC_STRIKE 4
    {"kINDIC_HIDDEN as Integer = 5"},            // INDIC_HIDDEN 5
    {"kINDIC_BOX as Integer = 6"},               // INDIC_BOX 6
    {"kINDIC_ROUNDBOX as Integer = 7"},          // INDIC_ROUNDBOX 7
    {"kINDIC_STRAIGHTBOX as Integer = 8"},       // INDIC_STRAIGHTBOX 8
    {"kINDIC_DASH as Integer = 9"},              // INDIC_DASH 9
    {"kINDIC_DOTS as Integer = 10"},             // INDIC_DOTS 10
    {"kINDIC_SQUIGGLELOW as Integer = 11"},      // INDIC_SQUIGGLELOW 11
    {"kINDIC_DOTBOX as Integer = 12"},           // INDIC_DOTBOX 12
    {"kINDIC_SQUIGGLEPIXMAP as Integer = 13"},   // INDIC_SQUIGGLEPIXMAP 13
    {"kINDIC_COMPOSITIONTHICK as Integer = 14"}, // INDIC_COMPOSITIONTHICK 14
    {"kINDIC_COMPOSITIONTHIN as Integer = 15"},  // INDIC_COMPOSITIONTHIN 15
    {"kINDIC_FULLBOX as Integer = 16"},          // INDIC_FULLBOX 16
    {"kINDIC_TEXTFORE as Integer = 17"},         // INDIC_TEXTFORE 17
    {"kINDIC_POINT as Integer = 18"},            // INDIC_POINT 18
    {"kINDIC_POINTCHARACTER as Integer = 19"},   // INDIC_POINTCHARACTER 19
    {"kINDIC_IME as Integer = 32"},              // INDIC_IME 32
    {"kINDIC_IME_MAX as Integer = 35"},          // INDIC_IME_MAX 35
    {"kINDIC_MAX as Integer = 35"},              // INDIC_MAX 35
    {"kINDIC_CONTAINER as Integer = 8"},         // INDIC_CONTAINER 8

    // used in SCI_INDICSETFLAGS
    {"kINDICVALUE_BIT as Integer = &h1000000"}, // SC_INDICVALUEBIT 0x1000000
    {"kINDICVALUE_MASK as Integer = &hFFFFFF"}, // SC_INDICVALUEMASK 0xFFFFFF
    {"kINDICFLAG_VALUEFORE as Integer = 1"},    // SC_INDICFLAG_VALUEFORE 1

    // used in SCI_SETINDENTATIONGUIDES
    {"kINDENT_NONE as Integer = 0"},        // SC_IV_NONE 0
    {"kINDENT_REAL as Integer = 1"},        // SC_IV_REAL 1
    {"kINDENT_LOOKFORWARD as Integer = 2"}, // SC_IV_LOOKFORWARD 2
    {"kINDENT_LOOKBOTH as Integer = 3"},    // SC_IV_LOOKBOTH 3

    // used in SCI_SETPRINTCOLOURMODE
    {"kPRINT_NORMAL as Integer = 0"},                 // SC_PRINT_NORMAL 0
    {"kPRINT_INVERTLIGHT as Integer = 1"},            // SC_PRINT_INVERTLIGHT 1
    {"kPRINT_BLACKONWHITE as Integer = 2"},           // SC_PRINT_BLACKONWHITE 2
    {"kPRINT_COLOURONWHITE as Integer = 3"},          // SC_PRINT_COLOURONWHITE 3
    {"kPRINT_COLOURONWHITEDEFAULTBG as Integer = 4"}, // SC_PRINT_COLOURONWHITEDEFAULTBG 4

    // used in SCI_SETSEARCHFLAGS
    {"kFIND_WHOLEWORD as Integer = &h2"},         // SCFIND_WHOLEWORD 0x2
    {"kFIND_MATCHCASE as Integer = &h4"},         // SCFIND_MATCHCASE 0x4
    {"kFIND_WORDSTART as Integer = &h00100000"},  // SCFIND_WORDSTART 0x00100000
    {"kFIND_REGEXP as Integer = &h00200000"},     // SCFIND_REGEXP 0x00200000
    {"kFIND_POSIX as Integer = &h00400000"},      // SCFIND_POSIX 0x00400000
    {"kFIND_CXX11REGEX as Integer = &h00800000"}, // SCFIND_CXX11REGEX 0x00800000

    // used in SCI_SETPRINTWRAPMODE
    {"kWRAP_NONE as Integer = 0"},       // SC_WRAP_NONE 0
    {"kWRAP_WORD as Integer = 1"},       // SC_WRAP_WORD 1
    {"kWRAP_CHAR as Integer = 2"},       // SC_WRAP_CHAR 2
    {"kWRAP_WHITESPACE as Integer = 3"}, // SC_WRAP_WHITESPACE 3

    // used in SCI_SETWRAPVISUALFLAGS
    {"kWRAPVISUALFLAG_NONE as Integer = &h0000"},   // SC_WRAPVISUALFLAG_NONE 0x0000
    {"kWRAPVISUALFLAG_END as Integer = &h0001"},    // SC_WRAPVISUALFLAG_END 0x0001
    {"kWRAPVISUALFLAG_START as Integer = &h0002"},  // SC_WRAPVISUALFLAG_START 0x0002
    {"kWRAPVISUALFLAG_MARGIN as Integer = &h0004"}, // SC_WRAPVISUALFLAG_MARGIN 0x0004

    // used in SCI_SETWRAPVISUALFLAGSLOCATION
    {"kWRAPVISUALFLAGLOC_DEFAULT as Integer = &h0000"},       // SC_WRAPVISUALFLAGLOC_DEFAULT 0x0000
    {"kWRAPVISUALFLAGLOC_END_BY_TEXT as Integer = &h0001"},   // SC_WRAPVISUALFLAGLOC_END_BY_TEXT 0x0001
    {"kWRAPVISUALFLAGLOC_START_BY_TEXT as Integer = &h0002"}, // SC_WRAPVISUALFLAGLOC_START_BY_TEXT 0x0002

    // used in SCI_SETWRAPINDENTMODE
    {"kWRAPINDENT_FIXED as Integer = 0"},  // SC_WRAPINDENT_FIXED 0
    {"kWRAPINDENT_SAME as Integer = 1"},   // SC_WRAPINDENT_SAME 1
    {"kWRAPINDENT_INDENT as Integer = 2"}, // SC_WRAPINDENT_INDENT 2

    // used in SCI_SETLAYOUTCACHE
    {"kCACHE_NONE as Integer = 0"},     // SC_CACHE_NONE 0
    {"kCACHE_CARET as Integer = 1"},    // SC_CACHE_CARET 1
    {"kCACHE_PAGE as Integer = 2"},     // SC_CACHE_PAGE 2
    {"kCACHE_DOCUMENT as Integer = 3"}, // SC_CACHE_DOCUMENT 3

    // used in SCI_SETTWOPHASEDRAW
    {"kPHASES_ONE as Integer = 0"},      // SC_PHASES_ONE 0
    {"kPHASES_TWO as Integer = 1"},      // SC_PHASES_TWO 1
    {"kPHASES_MULTIPLE as Integer = 2"}, // SC_PHASES_MULTIPLE 2

    // used in SCI_SETFONTQUALITY
    {"kFONT_QUALITY_MASK as Integer = &hf"},        // SC_EFF_QUALITY_MASK 0xF
    {"kFONT_QUALITY_DEFAULT as Integer = 0"},       // SC_EFF_QUALITY_DEFAULT 0
    {"kFONT_QUALITY_ANTIALIASED as Integer = 1"},   // SC_EFF_QUALITY_NON_ANTIALIASED 1
    {"kFONT_QUALITY_ANTIALIASED as Integer = 2"},   // SC_EFF_QUALITY_ANTIALIASED 2
    {"kFONT_QUALITY_LCD_OPTIMIZED as Integer = 3"}, // SC_EFF_QUALITY_LCD_OPTIMIZED 3

    // used in SCI_SETMULTIPASTE
    {"kMULTIPASTE_ONCE as Integer = 0"}, // SC_MULTIPASTE_ONCE 0
    {"kMULTIPASTE_EACH as Integer = 1"}, // SC_MULTIPASTE_EACH 1

    // used in SCI_SETACCESSIBILITY
    {"kACCESSIBILITY_DISABLED as Integer = 0"}, // SC_ACCESSIBILITY_DISABLED 0
    {"kACCESSIBILITY_ENABLED as Integer = 1"},  // SC_ACCESSIBILITY_ENABLED 1

    // used in SCI_SETEDGEMODE
    {"kEDGE_NONE as Integer = 0"},       // EDGE_NONE 0
    {"kEDGE_LINE as Integer = 1"},       // EDGE_LINE 1
    {"kEDGE_BACKGROUND as Integer = 2"}, // EDGE_BACKGROUND 2
    {"kEDGE_MULTILINE as Integer = 3"},  // EDGE_MULTILINE 3

    // used in SCI_USEPOPUP
    {"kPOPUP_NEVER as Integer = 0"}, // SC_POPUP_NEVER 0
    {"kPOPUP_ALL as Integer = 1"},   // SC_POPUP_ALL 1
    {"kPOPUP_TEXT as Integer = 2"},  // SC_POPUP_TEXT 2

    // used in SCI_SETVISIBLEPOLICY
    {"kVISIBLE_SLOP as Integer = &h01"},   // VISIBLE_SLOP 0x01
    {"kVISIBLE_STRICT as Integer = &h04"}, // VISIBLE_STRICT 0x04

    // used in SCI_SETXCARETPOLICY
    {"kCARET_SLOP as Integer = &h01"},   // CARET_SLOP 0x01
    {"kCARET_STRICT as Integer = &h04"}, // CARET_STRICT 0x04
    {"kCARET_JUMPS as Integer = &h10"},  // CARET_JUMPS 0x10
    {"kCARET_EVEN as Integer = &h08"},   // CARET_EVEN 0x08

    // used in SCI_AUTOCSETCASEINSENSITIVEBEHAVIOUR
    {"kCASEINSENSITIVEBEHAVIOUR_RESPECTCASE as Integer = 0"}, // SC_CASEINSENSITIVEBEHAVIOUR_RESPECTCASE 0
    {"kCASEINSENSITIVEBEHAVIOUR_IGNORECASE as Integer = 1"},  // SC_CASEINSENSITIVEBEHAVIOUR_IGNORECASE 1

    // used in SCI_AUTOCSETMULTI
    {"kMULTIAUTOC_ONCE as Integer = 0"}, // SC_MULTIAUTOC_ONCE 0
    {"kMULTIAUTOC_EACH as Integer = 1"}, // SC_MULTIAUTOC_EACH 1

    // used in SCI_AUTOCSETORDER
    {"kORDER_PRESORTED as Integer = 0"},   // SC_ORDER_PRESORTED 0
    {"kORDER_PERFORMSORT as Integer = 1"}, // SC_ORDER_PERFORMSORT 1
    {"kORDER_CUSTOM as Integer = 2"},      // SC_ORDER_CUSTOM 2

    // used in SCI_SETADDITIONALSELALPHA(alpha alpha)
    {"kALPHA_TRANSPARENT as Integer = 0"}, // SC_ALPHA_TRANSPARENT 0
    {"kALPHA_OPAQUE as Integer = 255"},    // SC_ALPHA_OPAQUE 255
    {"kALPHA_NOALPHA as Integer = 256"},   // SC_ALPHA_NOALPHA 256

    // used in SCI_SETCARETSTYLE
    {"kCARETSTYLE_LINE as Integer = 1"},  // CARETSTYLE_LINE 1
    {"kCARETSTYLE_BLOCK as Integer = 2"}, // CARETSTYLE_BLOCK 2

    // used in SCI_ANNOTATIONSETVISIBLE
    {"kANNOTATION_HIDDEN as Integer = 0"},   // ANNOTATION_HIDDEN 0
    {"kANNOTATION_STANDARD as Integer = 1"}, // ANNOTATION_STANDARD 1
    {"kANNOTATION_BOXED as Integer = 2"},    // ANNOTATION_BOXED 2
    {"kANNOTATION_INDENTED as Integer = 3"}, // ANNOTATION_INDENTED 3

    // used in SCI_SETVIRTUALSPACEOPTIONS
    {"kVIRTUAL_NONE as Integer = 0"},                 // SCVS_NONE 0
    {"kVIRTUAL_RECTANGULARSELECTION as Integer = 1"}, // SCVS_RECTANGULARSELECTION 1
    {"kVIRTUAL_USERACCESSIBLE as Integer = 2"},       // SCVS_USERACCESSIBLE 2
    {"kVIRTUAL_NOWRAPLINESTART as Integer = 4"},      // SCVS_NOWRAPLINESTART 4

    // used in SCI_SETTECHNOLOGY
    {"kTECHNOLOGY_DEFAULT as Integer = 0"},           // SC_TECHNOLOGY_DEFAULT 0
    {"kTECHNOLOGY_DIRECTWRITE as Integer = 1"},       // SC_TECHNOLOGY_DIRECTWRITE 1
    {"kTECHNOLOGY_DIRECTWRITERETAIN as Integer = 2"}, // SC_TECHNOLOGY_DIRECTWRITERETAIN 2
    {"kTECHNOLOGY_DIRECTWRITEDC as Integer = 3"},     // SC_TECHNOLOGY_DIRECTWRITEDC 3

    // used in SCI_GETLINEENDTYPESSUPPORTED
    {"kLINE_END_TYPE_DEFAULT as Integer = 0"}, // SC_LINE_END_TYPE_DEFAULT 0
    {"kLINE_END_TYPE_UNICODE as Integer = 1"}, // SC_LINE_END_TYPE_UNICODE 1

    // Value of SCNotification.modificationType
    {"kMOD_INSERTTEXT as Integer = &h1"},           // SC_MOD_INSERTTEXT 0x1
    {"kMOD_DELETETEXT as Integer = &h2"},           // SC_MOD_DELETETEXT 0x2
    {"kMOD_CHANGESTYLE as Integer = &h4"},          // SC_MOD_CHANGESTYLE 0x4
    {"kMOD_CHANGEFOLD as Integer = &h8"},           // SC_MOD_CHANGEFOLD 0x8
    {"kMOD_PERFORMED_USER as Integer = &h10"},      // SC_PERFORMED_USER 0x10
    {"kMOD_PERFORMED_UNDO as Integer = &h20"},      // SC_PERFORMED_UNDO 0x20
    {"kMOD_PERFORMED_REDO as Integer = &h40"},      // SC_PERFORMED_REDO 0x40
    {"kMOD_MULTISTEPUNDOREDO as Integer = &h80"},   // SC_MULTISTEPUNDOREDO 0x80
    {"kMOD_LASTSTEPINUNDOREDO as Integer = &h100"}, // SC_LASTSTEPINUNDOREDO 0x100
    {"kMOD_CHANGEMARKER as Integer = &h200"},       // SC_MOD_CHANGEMARKER 0x200
    {"kMOD_BEFOREINSERT as Integer = &h400"},       // SC_MOD_BEFOREINSERT 0x400
    {"kMOD_BEFOREDELETE  as Integer = &h800"},      // SC_MOD_BEFOREDELETE 0x800
    {"kMOD_MULTILINEUNDOREDO as Integer = &h1000"}, // SC_MULTILINEUNDOREDO 0x1000
    {"kMOD_STARTACTION as Integer = &h2000"},       // SC_STARTACTION 0x2000
    {"kMOD_CHANGEINDICATOR as Integer = &h4000"},   // SC_MOD_CHANGEINDICATOR 0x4000
    {"kMOD_CHANGELINESTATE as Integer = &h8000"},   // SC_MOD_CHANGELINESTATE 0x8000
    {"kMOD_CHANGEMARGIN as Integer = &h10000"},     // SC_MOD_CHANGEMARGIN 0x10000
    {"kMOD_CHANGEANNOTATION as Integer = &h20000"}, // SC_MOD_CHANGEANNOTATION 0x20000
    {"kMOD_CONTAINER as Integer = &h40000"},        // SC_MOD_CONTAINER 0x40000
    {"kMOD_LEXERSTATE as Integer = &h80000"},       // SC_MOD_LEXERSTATE 0x80000
    {"kMOD_INSERTCHECK as Integer = &h100000"},     // SC_MOD_INSERTCHECK 0x100000
    {"kMOD_CHANGETABSTOPS as Integer = &h200000"},  // SC_MOD_CHANGETABSTOPS 0x200000
    {"kMOD_EVENTMASKALL as Integer = &h3FFFFF"},    // SC_MODEVENTMASKALL 0x3FFFFF

    // used in SCN_UPDATEUI
    {"kUPDATE_CONTENT as Integer = &h1"},   // SC_UPDATE_CONTENT 0x1
    {"kUPDATE_SELECTION as Integer = &h2"}, // SC_UPDATE_SELECTION 0x2
    {"kUPDATE_V_SCROLL as Integer = &h4"},  // SC_UPDATE_V_SCROLL 0x4
    {"kUPDATE_H_SCROLL as Integer = &h8"},  // SC_UPDATE_H_SCROLL 0x8

    // keyDefinition
    {"SCK_DOWN as Integer = 300"},     // SCK_DOWN 300
    {"SCK_UP as Integer = 301"},       // SCK_UP 301
    {"SCK_LEFT as Integer = 302"},     // SCK_LEFT 302
    {"SCK_RIGHT as Integer = 303"},    // SCK_RIGHT 303
    {"SCK_HOME as Integer = 304"},     // SCK_HOME 304
    {"SCK_END as Integer = 305"},      // SCK_END 305
    {"SCK_PRIOR as Integer = 306"},    // SCK_PRIOR 306
    {"SCK_NEXT as Integer = 307"},     // SCK_NEXT 307
    {"SCK_DELETE as Integer = 308"},   // SCK_DELETE 308
    {"SCK_INSERT as Integer = 309"},   // SCK_INSERT 309
    {"SCK_ESCAPE as Integer = 7"},     // SCK_ESCAPE 7
    {"SCK_BACK as Integer = 8"},       // SCK_BACK 8
    {"SCK_TAB as Integer = 9"},        // SCK_TAB 9
    {"SCK_RETURN as Integer = 13"},    // SCK_RETURN 13
    {"SCK_ADD as Integer = 310"},      // SCK_ADD 310
    {"SCK_SUBTRACT as Integer = 311"}, // SCK_SUBTRACT 311
    {"SCK_DIVIDE as Integer = 312"},   // SCK_DIVIDE 312
    {"SCK_WIN as Integer = 313"},      // SCK_WIN 313
    {"SCK_RWIN as Integer = 314"},     // SCK_RWIN 314
    {"SCK_MENU as Integer = 315"},     // SCK_MENU 315
    {"SCMOD_NORM as Integer = 0"},     // SCMOD_NORM 0
    {"SCMOD_SHIFT as Integer = 1"},    // SCMOD_SHIFT 1
    {"SCMOD_CTRL as Integer = 2"},     // SCMOD_CTRL 2
    {"SCMOD_ALT as Integer = 4"},      // SCMOD_ALT 4
    {"SCMOD_SUPER as Integer = 8"},    // SCMOD_SUPER 8
    {"SCMOD_META as Integer = 16"},    // SCMOD_META 16

    // used in SCN_AUTOCSELECTION
    {"kAC_FILLUP as Integer = 1"},      // SC_AC_FILLUP 1
    {"kAC_DOUBLECLICK as Integer = 2"}, // SC_AC_DOUBLECLICK 2
    {"kAC_TAB as Integer = 3"},         // SC_AC_TAB 3
    {"kAC_NEWLINE as Integer = 4"},     // SC_AC_NEWLINE 4
    {"kAC_COMMAND as Integer = 5"},     // SC_AC_COMMAND 5
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
    NULL,                                              // properties
    0,                                                 // propertyCount
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
    NULL,                                              // enums
    0,                                                 // enumCount
#endif
    // end of structure
};

void registerPlugin(void)
{
    REALRegisterControl(&xsiControl);
}
