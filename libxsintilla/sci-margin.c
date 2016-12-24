#include "sci-margin.h"

void xsim_setMargins(REALcontrolInstance ctl, int unused, int margins)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINS, margins, 0);
}

int xsim_getMargins(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINS, 0, 0);
}

void xsim_setMarginTypeN(REALcontrolInstance ctl, int margin, int marginType)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINTYPEN, margin, marginType);
}

int xsim_getMarginTypeN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINTYPEN, margin, 0);
}

void xsim_setMarginWidthN(REALcontrolInstance ctl, int margin, int pixelWidth)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINWIDTHN, margin, pixelWidth);
}

int xsim_getMarginWidthN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINWIDTHN, margin, 0);
}

void xsim_setMarginBackN(REALcontrolInstance ctl, int margin, RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINBACKN, margin, back);
}

RBColor xsim_getMarginBackN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINBACKN, margin, 0);
}
