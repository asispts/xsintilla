#include "xsi-behaviour.h"
#include "xsi-event.h"
#include "XojoGraphics.h"

RBInteger getHandle(REALcontrolInstance ctl)
{
    RBInteger handle = 0;
    REALGetPropValueInteger((REALobject)ctl, "Handle", &handle);
    if (handle == 0) {
        fprintf(stderr, "Can't get control handle.\n");
        return 0;
    }
    return handle;
}

void resizeControl(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);

    Rect r = xsi_getRect(ctl);
    int width = r.right - r.left;
    int height = r.bottom - r.top;
    if (width <= 0 || height <= 0) return;
    gtk_fixed_move(GTK_FIXED(data->canvasCont), data->editor, r.left, r.top);
    gtk_widget_set_size_request(data->editor, width, height);
}

void Constructor(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);
    data->editor = scintilla_new();
    data->sci = SCINTILLA(data->editor);

    g_signal_connect(data->sci, SCINTILLA_NOTIFY,
                     G_CALLBACK(sci_eventHandler), NULL);
}

void Destructor(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);
    data->editor = NULL;
    data->sci = NULL;
}

void OnOpen(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);
    RBInteger handle = getHandle(ctl);
    if (handle == 0) return;

    GtkWidget *canvas = (GtkWidget *) handle;
    data->canvasCont = (GtkContainer *) gtk_widget_get_parent(canvas);

    gtk_container_add(data->canvasCont, data->editor);
    scintilla_set_id(data->sci, 0);
    gtk_widget_show(data->editor);
    gtk_widget_grab_focus(data->editor);

    xsi_ssm(data->sci, SCI_STYLECLEARALL, 0, 0);
    resizeControl(ctl);

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
    if (changedField == kBoundsChanged) {
        resizeControl(ctl);
    }
}
