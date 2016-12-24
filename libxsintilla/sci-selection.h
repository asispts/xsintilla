//=================================
//Selection and information
//=================================

#ifndef SCI_SELECTION_H
#define SCI_SELECTION_H

#include "xsintilla.h"

//methods
int xsim_getTextLength(REALcontrolInstance ctl);
int xsim_getLength(REALcontrolInstance ctl);
int xsim_getLineCount(REALcontrolInstance ctl);
int xsim_lineOnScreen(REALcontrolInstance ctl);
bool xsim_getModify(REALcontrolInstance ctl);
void xsim_setSel(REALcontrolInstance ctl, int anchor, int caret);
void xsim_gotoPos(REALcontrolInstance ctl, int caret);
void xsim_gotoLine(REALcontrolInstance ctl, int line);
int xsim_getCurrentPos(REALcontrolInstance ctl);
void xsim_setCurrentPos(REALcontrolInstance ctl, int caret);
int xsim_getAnchor(REALcontrolInstance ctl);
void xsim_setAnchor(REALcontrolInstance ctl, int anchor);
void xsim_setSelectionStart(REALcontrolInstance ctl, int anchor);
int xsim_getSelectionStart(REALcontrolInstance ctl);
void xsim_setSelectionEnd(REALcontrolInstance ctl, int caret);
int xsim_getSelectionEnd(REALcontrolInstance ctl);
void xsim_setEmptySelection(REALcontrolInstance ctl, int caret);
void xsim_selectAll(REALcontrolInstance ctl);
int xsim_lineFromPosition(REALcontrolInstance ctl, int pos);
int xsim_positionFromLine(REALcontrolInstance ctl, int line);
int xsim_getLineEndPosition(REALcontrolInstance ctl, int line);
int xsim_lineLength(REALcontrolInstance ctl, int line);
int xsim_getColumn(REALcontrolInstance ctl, int pos);
int xsim_findColumn(REALcontrolInstance ctl, int line, int column);
int xsim_positionFromPoint(REALcontrolInstance ctl, int x, int y);
int xsim_positionFromPointClose(REALcontrolInstance ctl, int x, int y);
int xsim_charPositionFromPoint(REALcontrolInstance ctl, int x, int y);
int xsim_charPositionFromPointClose(REALcontrolInstance ctl, int x, int y);
int xsim_pointXFromPosition(REALcontrolInstance ctl, int pos);
int xsim_pointYFromPosition(REALcontrolInstance ctl, int pos);
void xsim_hideSelection(REALcontrolInstance ctl, bool hide);
REALstring xsim_getSeltext(REALcontrolInstance ctl);
REALstring xsim_getCurLine(REALcontrolInstance ctl, int length);
bool xsim_selectionIsRectangle(REALcontrolInstance ctl);
void xsim_setSelectionMode(REALcontrolInstance ctl, int selectionMode);
int xsim_getSelectionMode(REALcontrolInstance ctl);
int xsim_getLineSelStartPosition(REALcontrolInstance ctl, int line);
int xsim_getLineSelEndPosition(REALcontrolInstance ctl, int line);
void xsim_moveCaretInsideView(REALcontrolInstance ctl);
int xsim_positionBefore(REALcontrolInstance ctl, int pos);
int xsim_positionAfter(REALcontrolInstance ctl, int pos);
int xsim_positionRelative(REALcontrolInstance ctl, int pos, int relative);
int xsim_countCharacters(REALcontrolInstance ctl, int start, int end);
int xsim_textWidth(REALcontrolInstance ctl, int style, REALstring text);
int xsim_textHeight(REALcontrolInstance ctl, int line);
void xsim_chooseCaretX(REALcontrolInstance ctl);
void xsim_moveSelectedLinesUp(REALcontrolInstance ctl);
void xsim_moveSelectedLinesDown(REALcontrolInstance ctl);
void xsim_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, bool mouseSwitch);
bool xsim_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl);


#endif //SCI_SELECTION_H
