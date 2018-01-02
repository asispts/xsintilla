#include "error-properties.h"

void xsip_setStatus(REALcontrolInstance ctl, long rbUnused, int status)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSTATUS, status, 0);
}
int xsip_getStatus(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSTATUS, 0, 0);
}
