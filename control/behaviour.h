#ifndef CONTROL_BEHAVIOUR_H
#define CONTROL_BEHAVIOUR_H

#include "xsintilla.h"

void Constructor(REALcontrolInstance ctl);
void Destructor(REALcontrolInstance ctl);
void OnOpen(REALcontrolInstance ctl);
void OnDrawOffscreen(REALcontrolInstance ctl, REALgraphics g);
void CanvasSizeRequest(GtkWidget* widget, GtkRequisition* requisition, gpointer user_data);
void CanvasSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data);
void ScintillaSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data);
void FixedSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data);

#endif  // CONTROL_BEHAVIOUR_H
