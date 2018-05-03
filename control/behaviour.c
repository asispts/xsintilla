#include "XojoGraphics.h"
#include "behaviour.h"
#include "event.h"
#include <stdio.h>
#include <stdlib.h>

// classes
#include "lexer.h"
#include "margin.h"
#include "style.h"

typedef RBBoolean (*fpMouseDown)(REALcontrolInstance, int, int);

// gtk event to fix position bug inside TabPanel or PagePanel on Linux
void EventBoxSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data)
{
    if((allocation->x != 0) || (allocation->y != 0)) {
        GtkWidget* parent = (GtkWidget*)gtk_widget_get_parent(widget);
        if(GTK_IS_FIXED(parent)) {
            gtk_fixed_move(GTK_FIXED(parent), widget, 0, 0);
        }
    }
}

typedef void (*SetFocusFunc)(REALcontrolInstance);
void ctlSetFocus(REALcontrolInstance ctl)
{
    SetFocusFunc fn = (SetFocusFunc)REALLoadObjectMethod(ctl, "SetFocus()");
    if(fn)
        fn(ctl);
}

// used to raise mousedown event
gboolean SciEventButtonPress(GtkWidget* widget, GdkEventButton* event, REALcontrolInstance ctl)
{
    if(event->button == 1) { // left click
        ctlSetFocus(ctl);    // required
        fpMouseDown RaiseMouseDown = (fpMouseDown)REALGetEventInstance(ctl, &xsiControl.events[ctl_MouseDown]);

        if(RaiseMouseDown) {
            return RaiseMouseDown(ctl, event->x, event->y);
        }
    }
    return false;
}

void Constructor(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);

    data->editor = scintilla_new();
    data->sci = SCINTILLA(data->editor);
    scintilla_set_id(data->sci, 0);

    // init margin class
    data->margin = REALnewInstanceWithClass(REALGetClassRef(xsiMarginDef.name));
    margin_setcontrol(data->margin, ctl);

    // init lexer class
    data->lexer = REALnewInstanceWithClass(REALGetClassRef(xsiLexerDef.name));
    lexer_setcontrol(data->lexer, ctl);

    // init styledef class
    data->style = REALnewInstanceWithClass(REALGetClassRef(xsiStyleDef.name));
    style_setcontrol(data->style, ctl);

    g_signal_connect(data->sci, SCINTILLA_NOTIFY, G_CALLBACK(sci_eventHandler), ctl);
    g_signal_connect(G_OBJECT(data->editor), "button-press-event", G_CALLBACK(SciEventButtonPress), ctl);
}

void OnClose(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);

    free(data->margin);
    free(data->style);
    free(data->lexer);
}

void OnOpen(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);

    // xsi_registerEventFunction(ctl);
    xsi_ssm(data->sci, SCI_STYLECLEARALL, 0, 0);

    GtkWidget* parent = (GtkWidget*)gtk_widget_get_parent(data->editor);
    while(parent != NULL && gtk_widget_is_toplevel(parent) == false) {
        if(GTK_IS_EVENT_BOX(parent)) {
            GtkWidget* notebook = (GtkWidget*)gtk_widget_get_parent(parent);
            while(notebook != NULL && gtk_widget_is_toplevel(notebook) == false) {
                if(GTK_IS_NOTEBOOK(notebook)) {
                    g_signal_connect(G_OBJECT(parent), "size-allocate", G_CALLBACK(EventBoxSizeAllocate), NULL);
                    break;
                }
                notebook = (GtkWidget*)gtk_widget_get_parent(notebook);
            }
            break;
        }
        parent = (GtkWidget*)gtk_widget_get_parent(parent);
    }

    ctlSetFocus(ctl); // required
}

void OnDrawOffscreen(REALcontrolInstance ctl, REALgraphics g)
{
    Rect r = xsi_getRect(ctl);
    int width = r.right - r.left;
    int height = r.bottom - r.top;
    if(width <= 0 || height <= 0)
        return;

    graphics_SetForeColor(g, 0xFFFFFF);
    graphics_FillRect(g, r.left, r.top, width, height);
    graphics_SetForeColor(g, 0);
    graphics_DrawRect(g, r.left, r.top, width, height);
}

void* OnControlHandleGetter(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);
    return (void*)data->editor;
}

RBBoolean OnKeyDownFunction(REALcontrolInstance ctl, int charCode, int keyCode, int modifiers)
{
    if(keyCode == SCK_TAB) {
        xsi_ssm(xsciObj(ctl), SCI_TAB, 0, 0);
        return true;
    }
    return false;
}
