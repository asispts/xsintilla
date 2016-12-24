//=================================
//Text retrieval and modification
//=================================

#ifndef SCI_TEXT_H
#define SCI_TEXT_H

#include "xsintilla.h"

//properties
void xsip_setReadonly(REALcontrolInstance ctl, int unused, bool readOnly);
bool xsip_getReadonly(REALcontrolInstance ctl, int unused);
REALstring xsip_getText(REALcontrolInstance ctl, int unused);
void xsip_setText(REALcontrolInstance ctl, int unused, REALstring text);

//methods
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

//int xsim_targetAsUtf8(REALcontrolInstance ctl, char *s);
//int xsim_encodeFromUtf8(REALcontrolInstance ctl, const char *utf8, char *encoded);
//void xsim_setLengthForEncode(REALcontrolInstance ctl, int bytes);
//void xsim_changeInsertion(REALcontrolInstance ctl, int length, const char *text);
//int xsim_getTextRange(REALcontrolInstance ctl, struct Sci_TextRange *tr);
//void xsim_addStyledText(REALcontrolInstance ctl, int length, cell *c);
//int xsim_getStyledText(REALcontrolInstance ctl, struct Sci_TextRange *tr);
#endif //SCI_TEXT_H
