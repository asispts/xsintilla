#include "sci-marker.h"

/*=========================
 * properties
 * ========================*/
void xsip_rgbaImageSetWidth(REALcontrolInstance ctl, int unused, int width)
{
    xsi_ssm(xsciObj(ctl), SCI_RGBAIMAGESETWIDTH, width, 0);
}

void xsip_rgbaImageSetHeight(REALcontrolInstance ctl, int unused, int height)
{
    xsi_ssm(xsciObj(ctl), SCI_RGBAIMAGESETHEIGHT, height, 0);
}

void xsip_rgbaImageSetScale(REALcontrolInstance ctl, int unused, int scalePercent)
{
    xsi_ssm(xsciObj(ctl), SCI_RGBAIMAGESETSCALE, scalePercent, 0);
}

void xsip_markerEnableHighlight(REALcontrolInstance ctl, int unused, bool enabled)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERENABLEHIGHLIGHT, enabled, 0);
}

/*=========================
 * methods
 * ========================*/
void xsim_markerDefine(REALcontrolInstance ctl, int markerNumber, int markerSymbol)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERDEFINE, markerNumber, markerSymbol);
}

void xsim_markerSetFore(REALcontrolInstance ctl, int markerNumber, RBColor fore)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERSETFORE, markerNumber, xsi_invertColor(fore));
}

void xsim_markerSetBack(REALcontrolInstance ctl, int markerNumber, RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERSETBACK, markerNumber, xsi_invertColor(back));
}

void xsim_markerSetBackSelected(REALcontrolInstance ctl, int markerNumber,
                                RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERSETBACKSELECTED, markerNumber,
            xsi_invertColor(back));
}

void xsim_markerDefineRgbaImage(REALcontrolInstance ctl, int markerNumber,
                                REALstring pixels)
{
    char *px = REALGetStringContents(pixels, NULL);
    xsi_ssm(xsciObj(ctl), SCI_MARKERDEFINERGBAIMAGE, markerNumber, (sptr_t)px);
}

int xsim_markerSymbolDefined(REALcontrolInstance ctl, int markerNumber)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARKERSYMBOLDEFINED, markerNumber, 0);
}

int xsim_markerAdd(REALcontrolInstance ctl, int line, int markerNumber)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARKERADD, line, markerNumber);
}

void xsim_markerAddSet(REALcontrolInstance ctl, int line, int markerNumber)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERADDSET, line, markerNumber);
}

void xsim_markerDelete(REALcontrolInstance ctl, int line, int markerNumber)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERDELETE, line, markerNumber);
}

void xsim_markerDeleteAll(REALcontrolInstance ctl, int markerNumber)
{
    xsi_ssm(xsciObj(ctl), SCI_MARKERDELETEALL, markerNumber, 0);
}

int xsim_markerGet(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARKERGET, line, 0);
}

int xsim_markerNext(REALcontrolInstance ctl, int lineStart, int markerMask)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARKERNEXT, lineStart, markerMask);
}

int xsim_markerPrevious(REALcontrolInstance ctl, int lineStart, int markerMask)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARKERPREVIOUS, lineStart, markerMask);
}
