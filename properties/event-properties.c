#include "event-properties.h"

void xsip_setModeEventMask(REALcontrolInstance ctl, long rbUnused, int eventMask)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMODEVENTMASK, (uptr_t)eventMask, 0);
}

int xsip_getModeEventMask(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMODEVENTMASK, 0, 0);
}

void xsip_setMouseDwellTime(REALcontrolInstance ctl, long rbUnused, int period)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMOUSEDWELLTIME, (uptr_t)period, 0);
}

int xsip_getMouseDwellTime(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMOUSEDWELLTIME, 0, 0);
}

void xsip_setIdentifier(REALcontrolInstance ctl, long rbUnused, int identifier)
{
    xsi_ssm(xsciObj(ctl), SCI_SETIDENTIFIER, (uptr_t)identifier, 0);
}

int xsip_getIdentifier(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETIDENTIFIER, 0, 0);
}
