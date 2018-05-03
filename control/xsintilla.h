#ifndef CONTROL_XSINTILLA_H
#define CONTROL_XSINTILLA_H

#include "SciLexer.h"
#include "Scintilla.h"
#include "rb_plugin.h"
#include <gtk/gtk.h>
#define PLAT_GTK 1
#include "ScintillaWidget.h"

REALcontrol xsiControl;

typedef struct {
    GtkWidget* editor;
    ScintillaObject* sci;
    REALobject margin;
    REALobject lexer;
    REALobject style;
} xsiControlData;

xsiControlData* xsi_getControlData(REALcontrolInstance ctl);
Rect xsi_getRect(REALcontrolInstance ctl);
sptr_t xsi_ssm(ScintillaObject*, unsigned int, uptr_t, sptr_t);
ScintillaObject* xsciObj(REALcontrolInstance ctl);
RBColor xsi_invertColor(RBColor color);
REALstring xsi_toREALstring(char* buffer, int length, bool nullTerminated);

REALobject xsi_getMarginObject(REALcontrolInstance ctl);
REALobject xsi_getLexerObject(REALcontrolInstance ctl);
REALobject xsi_getStyleObject(REALcontrolInstance ctl);

#endif // CONTROL_XSINTILLA_H
