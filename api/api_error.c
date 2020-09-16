#include "api_error.h"

void api_setStatus(REALcontrolInstance ctl, int status)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSTATUS, (uptr_t)status, 0);
}
int api_getStatus(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSTATUS, 0, 0);
}
