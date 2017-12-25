//=================================
// Text retrieval and modification
//=================================

#ifndef METHOD_TEXT_H
#define METHOD_TEXT_H

#include "xsintilla.h"

void xsim_setSavePoint(REALcontrolInstance ctl);
REALstring xsim_getLine(REALcontrolInstance ctl, int line);
void xsim_replaceSel(REALcontrolInstance ctl, REALstring text);
void xsim_allocate(REALcontrolInstance ctl, int bytes);
void xsim_addText(REALcontrolInstance ctl, int length, REALstring text);
void xsim_appendText(REALcontrolInstance ctl, int length, REALstring text);
void xsim_insertText(REALcontrolInstance ctl, int pos, REALstring text);
void xsim_clearAll(REALcontrolInstance ctl);
void xsim_deleteRange(REALcontrolInstance ctl, int start, int lengthDelete);
void xsim_clearDocumentStyle(REALcontrolInstance ctl);
REALstring xsim_getCharAt(REALcontrolInstance ctl, int pos);
int xsim_getStyleAt(REALcontrolInstance ctl, int pos);
void xsim_releaseAllExtendedStyles(REALcontrolInstance ctl);
int xsim_allocateExtendedStyles(REALcontrolInstance ctl, int numberStyles);
REALstring xsim_getTextRange(REALcontrolInstance ctl, Sci_PositionCR cpMin, Sci_PositionCR cpMax);
REALstring xsim_targetAsUtf8(REALcontrolInstance ctl);
REALstring xsim_encodeFromUtf8(REALcontrolInstance ctl, int length, REALstring utf8);
void xsim_addStyledText(REALcontrolInstance ctl, int length, REALstring styled_text);
REALstring xsim_getStyledText(REALcontrolInstance ctl, Sci_PositionCR cpMin, Sci_PositionCR cpMax);
void xsim_changeInsertion(REALcontrolInstance ctl, int length, REALstring text);

#endif  // METHOD_TEXT_H
