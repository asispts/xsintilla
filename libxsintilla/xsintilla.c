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
