#include "api_styling.h"

int api_getEndStyled(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETENDSTYLED, 0, 0);
}

void api_startStyling(REALcontrolInstance ctl, int start)
{
    xsi_ssm(xsciObj(ctl), SCI_STARTSTYLING, (uptr_t)start, 0);
}

void api_setStyling(REALcontrolInstance ctl, int start, int style)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSTYLING, (uptr_t)start, (sptr_t)style);
}

void api_setStylingEx(REALcontrolInstance ctl, int length, REALstring styles)
{
    char* value = REALGetStringContents(styles, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETSTYLINGEX, (uptr_t)length, (sptr_t)value);
}

void api_setIdleStyling(REALcontrolInstance ctl, int idleStyling)
{
    xsi_ssm(xsciObj(ctl), SCI_SETIDLESTYLING, (uptr_t)idleStyling, 0);
}

int api_getIdleStyling(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETIDLESTYLING, 0, 0);
}

void api_setLineState(REALcontrolInstance ctl, int line, int state)
{
    xsi_ssm(xsciObj(ctl), SCI_SETLINESTATE, (uptr_t)line, (sptr_t)state);
}

int api_getLineState(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINESTATE, (uptr_t)line, 0);
}

int api_getMaxLineState(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMAXLINESTATE, 0, 0);
}
