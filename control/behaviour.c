#include <stdio.h>
#include <stdlib.h>
#include "XojoGraphics.h"
#include "behaviour.h"
#include "event.h"

// classes
#include "lexer.h"
#include "margin.h"
#include "style.h"

RBInteger getHandle(REALcontrolInstance ctl)
{
    RBInteger handle = 0;
    REALGetPropValueInteger((REALobject)ctl, "Handle", &handle);
    return handle;
}

void Constructor(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);
    data->editor = scintilla_new();
    data->sci = SCINTILLA(data->editor);

    // init margin class
    data->margin = REALnewInstanceWithClass(REALGetClassRef(xsiMarginDef.name));
    margin_setcontrol(data->margin, ctl);

    // init lexer class
    data->lexer = REALnewInstanceWithClass(REALGetClassRef(xsiLexerDef.name));
    lexer_setcontrol(data->lexer, ctl);

    // init styledef class
    data->style = REALnewInstanceWithClass(REALGetClassRef(xsiStyleDef.name));
    style_setcontrol(data->style, ctl);
}

void Destructor(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);
    data->editor = NULL;
    data->sci = NULL;
    data->margin = NULL;
    data = NULL;
}

void OnOpen(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);

    RBInteger handle = getHandle(ctl);
    if(handle == 0)
        return;

    GtkWidget* canvas = (GtkWidget*)handle;
    GtkWidget* fixed = (GtkWidget*)gtk_widget_get_parent(canvas);
    gtk_fixed_put(GTK_FIXED(fixed), data->editor, 0, 0);

    g_signal_connect(G_OBJECT(canvas), "size-allocate", G_CALLBACK(CanvasSizeAllocate), data);

    GtkWidget* eventBox = (GtkWidget*)gtk_widget_get_parent(canvas);
    while(gtk_widget_is_toplevel(eventBox) == false) {
        if(GTK_IS_EVENT_BOX(eventBox) == true) {
            // listen to size-allocate event
            g_signal_connect(G_OBJECT(eventBox), "size-allocate", G_CALLBACK(EventBoxSizeAllocate), NULL);
            break;
        }
        eventBox = (GtkWidget*)gtk_widget_get_parent(eventBox);
    }
    g_signal_connect(data->sci, SCINTILLA_NOTIFY, G_CALLBACK(sci_eventHandler), NULL);

    gtk_widget_show_all(data->editor);
    xsi_ssm(data->sci, SCI_STYLECLEARALL, 0, 0);
    xsi_registerEventFunction(ctl);
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

void CanvasSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data)
{
    GtkContainer* canvasCont = (GtkContainer*)gtk_widget_get_parent(widget);
    xsiControlData* data = (xsiControlData*)user_data;

    int x = allocation->x;
    int y = allocation->y;
    int w = allocation->width;
    int h = allocation->height;
    int parentX = GTK_WIDGET(canvasCont)->allocation.x;
    int parentY = GTK_WIDGET(canvasCont)->allocation.y;

    int relX = x - parentX;
    int relY = y - parentY;

    if(parentX >= x)
        relX = parentX - x;
    if(parentY >= y)
        relY = parentY - y;

    if(x == 0)
        relX = 0;
    if(y == 0)
        relY = 0;

    gtk_widget_set_size_request(data->editor, w, h);
    gtk_fixed_move(GTK_FIXED(canvasCont), data->editor, relX, relY);
}

void EventBoxSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data)
{
    if((allocation->x != 0) || (allocation->y != 0)) {
        GtkWidget* parent = (GtkWidget*)gtk_widget_get_parent(widget);
        gtk_fixed_move(GTK_FIXED(parent), widget, 0, 0);
    }
}
