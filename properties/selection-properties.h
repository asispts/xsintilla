#ifndef PROPERTIES_SELECTION_H
#define PROPERTIES_SELECTION_H

#include "xsintilla.h"

int xsip_getCurrentPos(REALcontrolInstance ctl);
void xsip_setCurrentPos(REALcontrolInstance ctl, long rbUnused, int caret);

int xsip_getAnchor(REALcontrolInstance ctl);
void xsip_setAnchor(REALcontrolInstance ctl, long rbUnused, int anchor);

void xsip_setSelectionStart(REALcontrolInstance ctl, long rbUnused, int anchor);
int xsip_getSelectionStart(REALcontrolInstance ctl);

void xsip_setSelectionEnd(REALcontrolInstance ctl, long rbUnused, int caret);
int xsip_getSelectionEnd(REALcontrolInstance ctl);

void xsip_setSelectionMode(REALcontrolInstance ctl, long rbUnused, int selectionMode);
int xsip_getSelectionMode(REALcontrolInstance ctl);

void xsip_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, long rbUnused, bool mouseSwitch);
bool xsip_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl);

#endif  // PROPERTIES_SELECTION_H
