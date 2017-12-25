#include <stdio.h>
#include <stdlib.h>
#include "XojoGraphics.h"
#include "behaviour.h"
#include "event.h"

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
}

void Destructor(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);
    data->editor = NULL;
    data->sci = NULL;
    data = NULL;
}

void OnOpen(REALcontrolInstance ctl)
{
    xsiControlData* data = xsi_getControlData(ctl);
    RBInteger handle = getHandle(ctl);
    if(handle == 0)
        return;

    GtkWidget* canvas = (GtkWidget*)handle;
    GtkContainer* canvasCont = (GtkContainer*)gtk_widget_get_parent(canvas);

    // @TODO: Fix this x and y values
    gtk_fixed_put(GTK_FIXED(canvasCont), data->editor, 0, 0);

    // g_signal_connect(G_OBJECT(canvas), "size-request", G_CALLBACK(CanvasSizeRequest), data->editor);
    g_signal_connect(G_OBJECT(canvas), "size-allocate", G_CALLBACK(CanvasSizeAllocate), data);

    g_signal_connect(G_OBJECT(data->editor), "size-allocate", G_CALLBACK(ScintillaSizeAllocate), NULL);
    g_signal_connect(G_OBJECT(canvasCont), "size-allocate", G_CALLBACK(FixedSizeAllocate), NULL);

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
    const gchar* typename = G_OBJECT_TYPE_NAME(widget);

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

    printf("x = %d, y = %d, w = %d, h = %d, name = %s, parentX = %d, parentY = %d; [Canvas]\n", x, y, w, h, typename,
           parentX, parentY);

    // GtkWidget* editor = (GtkWidget*)user_data;

    gtk_widget_set_size_request(data->editor, w, h);
    gtk_fixed_move(GTK_FIXED(canvasCont), data->editor, relX, relY);
    // gtk_widget_size_allocate(data->editor, allocation);

    // gtk_fixed_put(GTK_FIXED(canvasCont), data->editor, x, y);
    // gtk_widget_set_size_request(data->editor, w, h);
    // gtk_widget_size_allocate(data->editor, allocation);

    // GtkAllocation* sciAlloc;

    // sciAlloc->x = allocation->x;
    // sciAlloc->y = allocation->y;
    // sciAlloc->width = allocation->width;
    // sciAlloc->height = allocation->height;

    // gtk_widget_set_size_request(editor, w, h);
    // gtk_widget_size_allocate(editor, allocation);

    // gtk_fixed_move(GTK_FIXED(canvasCont), editor, x, y);
}

void ScintillaSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data)
{
    int x = allocation->x;
    int y = allocation->y;
    int w = allocation->width;
    int h = allocation->height;
    const gchar* typename = G_OBJECT_TYPE_NAME(widget);

    printf("x = %d, y = %d, w = %d, h = %d, name = %s; [Scintilla]\n", x, y, w, h, typename);
}

void FixedSizeAllocate(GtkWidget* widget, GdkRectangle* allocation, gpointer user_data)
{
    int x = allocation->x;
    int y = allocation->y;
    int w = allocation->width;
    int h = allocation->height;
    const gchar* typename = G_OBJECT_TYPE_NAME(widget);

    printf("x = %d, y = %d, w = %d, h = %d, name = %s; [Fixed]\n", x, y, w, h, typename);
}

void CanvasSizeRequest(GtkWidget* widget, GtkRequisition* requisition, gpointer user_data)
{
    // GtkContainer* canvasCont = (GtkContainer*)gtk_widget_get_parent(widget);
    // GtkWidget* editor = (GtkWidget*)user_data;

    // int x = allocation->x;
    // int y = allocation->y;
    // int w = allocation->width;
    // int h = allocation->height;
    // const gchar* typename = G_OBJECT_CLASS_NAME(widget);
    // const gchar* parent = G_OBJECT_TYPE_NAME(canvasCont);

    // printf("x = %d, y = %d, w = %d, h = %d, name = %s, parent = %s; [Canvas]\n", x, y, w, h, typename, parent);

    // GtkAllocation* sciAlloc;

    // sciAlloc->x = allocation->x;
    // sciAlloc->y = allocation->y;
    // sciAlloc->width = allocation->width;
    // sciAlloc->height = allocation->height;

    // gtk_widget_set_size_request(editor, w, h);
    // gtk_widget_size_allocate(editor, allocation);

    // gtk_fixed_move(GTK_FIXED(canvasCont), editor, x, y);
}
