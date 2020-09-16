#ifndef API_SELECTION_H
#define API_SELECTION_H

#include "xsintilla.h"

int api_getTextLength(REALcontrolInstance ctl);
int api_getLength(REALcontrolInstance ctl);
int api_getLineCount(REALcontrolInstance ctl);
int api_lineOnScreen(REALcontrolInstance ctl);
bool api_getModify(REALcontrolInstance ctl);
int api_getCurrentPos(REALcontrolInstance ctl);
void api_setCurrentPos(REALcontrolInstance ctl, int caret);
int api_getAnchor(REALcontrolInstance ctl);
void api_setAnchor(REALcontrolInstance ctl, int anchor);
void api_setSelectionStart(REALcontrolInstance ctl, int anchor);
int api_getSelectionStart(REALcontrolInstance ctl);
void api_setSelectionEnd(REALcontrolInstance ctl, int caret);
int api_getSelectionEnd(REALcontrolInstance ctl);
void api_hideSelection(REALcontrolInstance ctl, bool hide);
REALstring api_getSeltext(REALcontrolInstance ctl);
bool api_selectionIsRectangle(REALcontrolInstance ctl);
void api_setSelectionMode(REALcontrolInstance ctl, int selectionMode);
int api_getSelectionMode(REALcontrolInstance ctl);
void api_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, bool mouseSwitch);
bool api_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl);
void api_setSel(REALcontrolInstance ctl, int anchor, int caret);
void api_gotoPos(REALcontrolInstance ctl, int caret);
void api_gotoLine(REALcontrolInstance ctl, int line);
void api_setEmptySelection(REALcontrolInstance ctl, int caret);
void api_selectAll(REALcontrolInstance ctl);
int api_lineFromPosition(REALcontrolInstance ctl, int pos);
int api_positionFromLine(REALcontrolInstance ctl, int line);
int api_getLineEndPosition(REALcontrolInstance ctl, int line);
int api_lineLength(REALcontrolInstance ctl, int line);
int api_getColumn(REALcontrolInstance ctl, int pos);
int api_findColumn(REALcontrolInstance ctl, int line, int column);
int api_positionFromPoint(REALcontrolInstance ctl, int x, int y);
int api_positionFromPointClose(REALcontrolInstance ctl, int x, int y);
int api_charPositionFromPoint(REALcontrolInstance ctl, int x, int y);
int api_charPositionFromPointClose(REALcontrolInstance ctl, int x, int y);
int api_pointXFromPosition(REALcontrolInstance ctl, int pos);
int api_pointYFromPosition(REALcontrolInstance ctl, int pos);
REALstring api_getCurLine(REALcontrolInstance ctl);
int api_getLineSelStartPosition(REALcontrolInstance ctl, int line);
int api_getLineSelEndPosition(REALcontrolInstance ctl, int line);
void api_moveCaretInsideView(REALcontrolInstance ctl);
int api_positionBefore(REALcontrolInstance ctl, int pos);
int api_positionAfter(REALcontrolInstance ctl, int pos);
int api_positionRelative(REALcontrolInstance ctl, int pos, int relative);
int api_countCharacters(REALcontrolInstance ctl, int start, int end);
int api_textWidth(REALcontrolInstance ctl, int style, REALstring text);
int api_textHeight(REALcontrolInstance ctl, int line);
void api_chooseCaretX(REALcontrolInstance ctl);
void api_moveSelectedLinesUp(REALcontrolInstance ctl);
void api_moveSelectedLinesDown(REALcontrolInstance ctl);

#endif // API_SELECTION_H
