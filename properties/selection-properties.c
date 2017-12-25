#include <stdlib.h>
#include "selection-properties.h"

int xsip_getTextLength(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETTEXTLENGTH, 0, 0);
}

int xsip_getLength(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLENGTH, 0, 0);
}

int xsip_getLineCount(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINECOUNT, 0, 0);
}

int xsip_lineOnScreen(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINESONSCREEN, 0, 0);
}

bool xsip_getModify(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMODIFY, 0, 0);
}

int xsip_getCurrentPos(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETCURRENTPOS, 0, 0);
}

void xsip_setCurrentPos(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETCURRENTPOS, (uptr_t)caret, 0);
}

int xsip_getAnchor(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETANCHOR, 0, 0);
}

void xsip_setAnchor(REALcontrolInstance ctl, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETANCHOR, (uptr_t)anchor, 0);
}

void xsip_setSelectionStart(REALcontrolInstance ctl, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONSTART, (uptr_t)anchor, 0);
}

int xsip_getSelectionStart(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONSTART, 0, 0);
}

void xsip_setSelectionEnd(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONEND, (uptr_t)caret, 0);
}

int xsip_getSelectionEnd(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONEND, 0, 0);
}

void xsip_hideSelection(REALcontrolInstance ctl, bool hide)
{
    xsi_ssm(xsciObj(ctl), SCI_HIDESELECTION, (uptr_t)hide, 0);
}

REALstring xsip_getSeltext(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_GETSELTEXT, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_GETSELTEXT, 0, (sptr_t)buffer);

    // has a terminated NULL character
    return xsi_toREALstring(buffer, len, true);
}

bool xsip_selectionIsRectangle(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_SELECTIONISRECTANGLE, 0, 0);
}

void xsip_setSelectionMode(REALcontrolInstance ctl, int mode)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONMODE, (uptr_t)mode, 0);
}

int xsip_getSelectionMode(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONMODE, 0, 0);
}

void xsip_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, bool mouseSwitch)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMOUSESELECTIONRECTANGULARSWITCH, (uptr_t)mouseSwitch, 0);
}

bool xsip_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMOUSESELECTIONRECTANGULARSWITCH, 0, 0);
}
