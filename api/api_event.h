#ifndef API_EVENT_H
#define API_EVENT_H

#include "xsintilla.h"

void api_setModeEventMask(REALcontrolInstance ctl, int eventMask);
int api_getModeEventMask(REALcontrolInstance ctl);

void api_setMouseDwellTime(REALcontrolInstance ctl, int period);
int api_getMouseDwellTime(REALcontrolInstance ctl);

void api_setIdentifier(REALcontrolInstance ctl, int identifier);
int api_getIdentifier(REALcontrolInstance ctl);

#endif // API_EVENT_H
