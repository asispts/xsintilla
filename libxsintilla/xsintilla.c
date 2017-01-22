#include "xsintilla.h"

xsiControlData *xsi_getControlData(REALcontrolInstance ctl)
{
    return REALGetControlData(ctl, &xsiControl);
}

Rect xsi_getRect(REALcontrolInstance ctl)
{
    Rect rect;
    REALGetControlBounds(ctl, &rect);
    return rect;
}

sptr_t xsi_ssm(ScintillaObject *sci, unsigned int iMessage,
               uptr_t wParam, sptr_t lParam)
{
    return scintilla_send_message(sci, iMessage, wParam, lParam);
}

ScintillaObject *xsciObj(REALcontrolInstance ctl)
{
    xsiControlData *data = xsi_getControlData(ctl);
    return data->sci;
}

RBColor xsi_invertColor(RBColor color)
{
    int r = ( color >> 16 ) & 0xFF;
    int g = ( color >> 8 ) & 0xFF;
    int b = color & 0xFF;

    // right conversion formula
    // (r << 16) + (g << 8) + b;

    //based on scintilla documentation
    return r | (g << 8) | (b << 16);
}

// Only for testing
char *widgetType(GtkWidget *widget)
{
    /*
     * Widget
     */
    if (GTK_IS_MISC(widget)) {
        return "GtkMisc";
    }

    if (GTK_IS_CALENDAR(widget)) {
        return "GtkCalendar";
    }

    if (GTK_IS_CELL_VIEW(widget)) {
        return "GtkCellView";
    }

    if (GTK_IS_DRAWING_AREA(widget)) {
        return "GtkDrawingArea";
    }

    if (GTK_IS_ENTRY(widget)) {
        return "GtkEntry";
    }

    /*
     * Container
     */
    if (GTK_IS_BIN(widget)) {
        return "GtkBin";
    }
    if (GTK_IS_VBOX(widget)) {
        return "GtkVBox";
    }
    if (GTK_IS_HBOX(widget)) {
        return "GtkHBox";
    }
    if (GTK_IS_BOX(widget)) {
        return "GtkBox";
    }
    if (GTK_IS_FIXED(widget)) {
        return "GtkFixed";
    }
    if (GTK_IS_PANED(widget)) {
        return "GtkPaned";
    }
    if (GTK_IS_ICON_VIEW(widget)) {
        return "GtkIconView";
    }
    if (GTK_IS_LAYOUT(widget)) {
        return "GtkLayout";
    }
    if (GTK_IS_NOTEBOOK(widget)) {
        return "GtkNotebook";
    }
    if (GTK_IS_TABLE(widget)) {
        return "GtkTable";
    }

    if (GTK_IS_CONTAINER(widget)) {
        return "GtkContainer";
    }

    if (GTK_IS_WIDGET(widget)) {
        return "GtkWidget";
    }
    return "Unknown";
}
