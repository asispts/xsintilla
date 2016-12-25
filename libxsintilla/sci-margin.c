#include "sci-margin.h"

/*=========================
 * properties
 * ========================*/
void xsip_setMargins(REALcontrolInstance ctl, int unused, int margins)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINS, margins, 0);
}

int xsip_getMargins(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINS, 0, 0);
}


/*=========================
 * methods
 * ========================*/
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
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINBACKN, margin, xsi_invertColor(back));
}

RBColor xsim_getMarginBackN(REALcontrolInstance ctl, int margin)
{
    return xsi_invertColor(xsi_ssm(xsciObj(ctl), SCI_GETMARGINBACKN, margin, 0));
}

void xsim_setMarginMaskN(REALcontrolInstance ctl, int margin, int mask)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINMASKN, margin, mask);
}

int xsim_getMarginMaskN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINMASKN, margin, 0);
}
