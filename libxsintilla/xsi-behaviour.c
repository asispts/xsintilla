#include "xsi-behaviour.h"
#include "xsi-event.h"
#include "XojoGraphics.h"
#include <stdio.h>
#include <stdlib.h>

RBInteger getHandle(REALcontrolInstance ctl)
{
    RBInteger handle = 0;
    REALGetPropValueInteger((REALobject)ctl, "Handle", &handle);
    return handle;
}

void resizeControl(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);

    Rect r = xsi_getRect(ctl);
    int width = r.right - r.left;
    int height = r.bottom - r.top;
    if (width <= 0 || height <= 0) return;

    GtkAllocation alCont;
    GtkAllocation alCanvas;

    gtk_widget_get_allocation(GTK_WIDGET(data->canvasCont), &alCont);
    gtk_widget_get_allocation(data->canvas, &alCanvas);

    int xx = 0;
    int yy = 0;
    if ((alCanvas.x == -1) && (alCanvas.width == 1)) {
        xx = r.left;
        yy = r.top;
    } else {
        xx = alCanvas.x - alCont.x;
        yy = alCanvas.y - alCont.y;

        if (alCanvas.x < alCont.x) xx = alCanvas.x;
        if (alCanvas.y < alCont.y) yy = alCanvas.y;
    }

    gtk_fixed_move(GTK_FIXED(data->canvasCont), data->editor, xx, yy);
    gtk_widget_set_size_request(data->editor, width, height);
}

void Constructor(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);
    data->editor = scintilla_new();
    data->sci = SCINTILLA(data->editor);
}

void Destructor(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);
    data->editor = NULL;
    data->sci = NULL;
    data = NULL;
}

void OnOpen(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);
    RBInteger handle = getHandle(ctl);
    if (handle == 0) return;

    data->canvas = (GtkWidget *) handle;
    data->canvasCont = (GtkContainer *) gtk_widget_get_parent(data->canvas);

    Rect r = xsi_getRect(ctl);
    int width = r.right - r.left;
    int height = r.bottom - r.top;

    gtk_fixed_put(GTK_FIXED(data->canvasCont), data->editor, r.left, r.top);
    gtk_widget_set_size_request(data->editor, width, height);
    scintilla_set_id(data->sci, 0);
    gtk_widget_show_all(data->editor);
    gtk_widget_grab_focus(data->editor);
    xsi_ssm(data->sci, SCI_STYLECLEARALL, 0, 0);

    g_signal_connect(data->sci, SCINTILLA_NOTIFY,
                     G_CALLBACK(sci_eventHandler), NULL);
    xsi_registerEventFunction(ctl);
}

void OnDrawOffscreen(REALcontrolInstance ctl, REALgraphics g)
{
    Rect r = xsi_getRect(ctl);
    int width = r.right - r.left;
    int height = r.bottom - r.top;
    if (width <= 0 || height <= 0) return;

    graphics_SetForeColor(g, 0xFFFFFF);
    graphics_FillRect(g, r.left, r.top, width, height);
    graphics_SetForeColor(g, 0);
    graphics_DrawRect(g, r.left, r.top, width, height);
}

void OnStateChanged(REALcontrolInstance ctl, uint32_t changedField)
{
    if (changedField == kBoundsChanged || changedField == kEnabledChanged) {
        resizeControl(ctl);
    }
}
