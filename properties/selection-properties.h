#ifndef PROPERTIES_SELECTION_H
#define PROPERTIES_SELECTION_H

#include "xsintilla.h"

int xsip_getTextLength(REALcontrolInstance ctl);
int xsip_getLength(REALcontrolInstance ctl);
int xsip_getLineCount(REALcontrolInstance ctl);
int xsip_lineOnScreen(REALcontrolInstance ctl);
bool xsip_getModify(REALcontrolInstance ctl);
int xsip_getCurrentPos(REALcontrolInstance ctl);
void xsip_setCurrentPos(REALcontrolInstance ctl, int caret);
int xsip_getAnchor(REALcontrolInstance ctl);
void xsip_setAnchor(REALcontrolInstance ctl, int anchor);
void xsip_setSelectionStart(REALcontrolInstance ctl, int anchor);
int xsip_getSelectionStart(REALcontrolInstance ctl);
void xsip_setSelectionEnd(REALcontrolInstance ctl, int caret);
int xsip_getSelectionEnd(REALcontrolInstance ctl);
void xsip_hideSelection(REALcontrolInstance ctl, bool hide);
REALstring xsip_getSeltext(REALcontrolInstance ctl);
bool xsip_selectionIsRectangle(REALcontrolInstance ctl);
void xsip_setSelectionMode(REALcontrolInstance ctl, int selectionMode);
int xsip_getSelectionMode(REALcontrolInstance ctl);
void xsip_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, bool mouseSwitch);
bool xsip_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl);

#endif  // PROPERTIES_SELECTION_H
