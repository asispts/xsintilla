#ifndef PROPERTIES_EVENT_H
#define PROPERTIES_EVENT_H

#include "xsintilla.h"

void xsip_setModeEventMask(REALcontrolInstance ctl, long rbUnused, int eventMask);
int xsip_getModeEventMask(REALcontrolInstance ctl);

void xsip_setMouseDwellTime(REALcontrolInstance ctl, long rbUnused, int period);
int xsip_getMouseDwellTime(REALcontrolInstance ctl);

void xsip_setIdentifier(REALcontrolInstance ctl, long rbUnused, int identifier);
int xsip_getIdentifier(REALcontrolInstance ctl);

#endif  // PROPERTIES_EVENT_H
