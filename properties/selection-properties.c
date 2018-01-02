#include <stdlib.h>
#include "selection-properties.h"

int xsip_getCurrentPos(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETCURRENTPOS, 0, 0);
}

void xsip_setCurrentPos(REALcontrolInstance ctl, long rbUnused, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETCURRENTPOS, (uptr_t)caret, 0);
}

int xsip_getAnchor(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETANCHOR, 0, 0);
}

void xsip_setAnchor(REALcontrolInstance ctl, long rbUnused, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETANCHOR, (uptr_t)anchor, 0);
}

void xsip_setSelectionStart(REALcontrolInstance ctl, long rbUnused, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONSTART, (uptr_t)anchor, 0);
}

int xsip_getSelectionStart(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONSTART, 0, 0);
}

void xsip_setSelectionEnd(REALcontrolInstance ctl, long rbUnused, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONEND, (uptr_t)caret, 0);
}

int xsip_getSelectionEnd(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONEND, 0, 0);
}

void xsip_setSelectionMode(REALcontrolInstance ctl, long rbUnused, int mode)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONMODE, (uptr_t)mode, 0);
}

int xsip_getSelectionMode(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONMODE, 0, 0);
}

void xsip_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, long rbUnused, bool mouseSwitch)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMOUSESELECTIONRECTANGULARSWITCH, (uptr_t)mouseSwitch, 0);
}

bool xsip_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMOUSESELECTIONRECTANGULARSWITCH, 0, 0);
}
