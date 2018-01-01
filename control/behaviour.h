#ifndef CONTROL_BEHAVIOUR_H
#define CONTROL_BEHAVIOUR_H

#include "xsintilla.h"

#define XSINTILLA_DEBUG 1

void Constructor(REALcontrolInstance ctl);
void OnOpen(REALcontrolInstance ctl);
void OnClose(REALcontrolInstance ctl);
void OnDrawOffscreen(REALcontrolInstance ctl, REALgraphics g);
void* OnControlHandleGetter(REALcontrolInstance ctl);

// GTK callback
void EventBoxSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data);

#endif  // CONTROL_BEHAVIOUR_H
