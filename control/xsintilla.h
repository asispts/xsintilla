#ifndef CONTROL_XSINTILLA_H
#define CONTROL_XSINTILLA_H

#include <gtk/gtk.h>
#include "SciLexer.h"
#include "Scintilla.h"
#include "rb_plugin.h"
#define PLAT_GTK 1
#include "ScintillaWidget.h"

REALcontrol xsiControl;

typedef struct {
    GtkWidget* editor;
    ScintillaObject* sci;
    GtkContainer* canvasCont;
    GtkWidget* canvas;
} xsiControlData;

xsiControlData* xsi_getControlData(REALcontrolInstance ctl);
Rect xsi_getRect(REALcontrolInstance ctl);
sptr_t xsi_ssm(ScintillaObject*, unsigned int, uptr_t, sptr_t);
ScintillaObject* xsciObj(REALcontrolInstance ctl);
RBColor xsi_invertColor(RBColor color);
char* JoinString(const char* dest, const char* source);

#endif  // CONTROL_XSINTILLA_H
