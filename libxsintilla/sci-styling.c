#include "sci-styling.h"

int xsim_getEndStyled(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETENDSTYLED, 0, 0);
}

void xsim_startStyling(REALcontrolInstance ctl, int start)
{
    xsi_ssm(xsciObj(ctl), SCI_STARTSTYLING, start, 0);
}

void xsim_setStyling(REALcontrolInstance ctl, int length, int style)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSTYLING, length, style);
}
