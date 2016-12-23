#ifndef XSINTILLA_EVENT_H
#define XSINTILLA_EVENT_H

#include "xsintilla.h"

void xsi_registerEventFunction(REALcontrolInstance ctl);
void sci_eventHandler(ScintillaObject *sci, gint controlID,
                      SCNotification *scinotify, gpointer userData);

// function pointer for event definition
typedef void (*fpVoidEvent)(REALcontrolInstance);
typedef void (*fpVoidEventInt)(REALcontrolInstance, int);

// Events definition
enum xsi_events {
    xse_StyleNeeded,
    xse_CharAdded
};

#endif //XSINTILLA_EVENT_H
