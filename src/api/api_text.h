#ifndef API_TEXT_H
#define API_TEXT_H

#include "xsintilla.h"

REALstring api_getText(REALcontrolInstance ctl);
void api_setText(REALcontrolInstance ctl, REALstring text);
void api_setSavePoint(REALcontrolInstance ctl);
REALstring api_getLine(REALcontrolInstance ctl, int line);
void api_replaceSel(REALcontrolInstance ctl, REALstring text);
void api_setReadonly(REALcontrolInstance ctl, bool readOnly);
bool api_getReadonly(REALcontrolInstance ctl);
void api_allocate(REALcontrolInstance ctl, int bytes);
void api_addText(REALcontrolInstance ctl, int length, REALstring text);
void api_appendText(REALcontrolInstance ctl, int length, REALstring text);
void api_insertText(REALcontrolInstance ctl, int pos, REALstring text);
void api_clearAll(REALcontrolInstance ctl);
void api_deleteRange(REALcontrolInstance ctl, int start, int lengthDelete);
void api_clearDocumentStyle(REALcontrolInstance ctl);
REALstring api_getCharAt(REALcontrolInstance ctl, int pos);
int api_getStyleAt(REALcontrolInstance ctl, int pos);
void api_releaseAllExtendedStyles(REALcontrolInstance ctl);
int api_allocateExtendedStyles(REALcontrolInstance ctl, int numberStyles);
REALstring api_getTextRange(REALcontrolInstance ctl, Sci_PositionCR cpMin, Sci_PositionCR cpMax);
REALstring api_targetAsUtf8(REALcontrolInstance ctl);
REALstring api_encodeFromUtf8(REALcontrolInstance ctl, int length, REALstring utf8);
void api_addStyledText(REALcontrolInstance ctl, int length, REALstring styled_text);
REALstring api_getStyledText(REALcontrolInstance ctl, Sci_PositionCR cpMin, Sci_PositionCR cpMax);
void api_changeInsertion(REALcontrolInstance ctl, int length, REALstring text);

#endif // API_TEXT_H
