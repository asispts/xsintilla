#ifndef METHOD_SELECTION_H
#define METHOD_SELECTION_H

#include "xsintilla.h"

int xsip_getTextLength(REALcontrolInstance ctl);
int xsip_getLength(REALcontrolInstance ctl);
int xsip_getLineCount(REALcontrolInstance ctl);
int xsip_lineOnScreen(REALcontrolInstance ctl);
bool xsip_getModify(REALcontrolInstance ctl);
void xsip_hideSelection(REALcontrolInstance ctl, long rbUnused, bool hide);
REALstring xsip_getSeltext(REALcontrolInstance ctl);
bool xsip_selectionIsRectangle(REALcontrolInstance ctl);
void xsim_setSel(REALcontrolInstance ctl, int anchor, int caret);
void xsim_gotoPos(REALcontrolInstance ctl, int caret);
void xsim_gotoLine(REALcontrolInstance ctl, int line);
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
REALstring xsim_getCurLine(REALcontrolInstance ctl);
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

#endif  // METHOD_SELECTION_H
