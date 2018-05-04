#include "api_event.h"

void api_setModeEventMask(REALcontrolInstance ctl, int eventMask)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMODEVENTMASK, (uptr_t)eventMask, 0);
}

int api_getModeEventMask(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMODEVENTMASK, 0, 0);
}

void api_setMouseDwellTime(REALcontrolInstance ctl, int period)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMOUSEDWELLTIME, (uptr_t)period, 0);
}

int api_getMouseDwellTime(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMOUSEDWELLTIME, 0, 0);
}

void api_setIdentifier(REALcontrolInstance ctl, int identifier)
{
    xsi_ssm(xsciObj(ctl), SCI_SETIDENTIFIER, (uptr_t)identifier, 0);
}

int api_getIdentifier(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETIDENTIFIER, 0, 0);
}
