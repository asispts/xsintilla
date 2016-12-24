#include "stdlib.h"
#include "sci-styledef.h"

void xsim_styleResetDefault(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLERESETDEFAULT, 0, 0);
}

void xsim_styleClearAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLECLEARALL, 0, 0);
}

void xsim_styleSetFont(REALcontrolInstance ctl, int style, REALstring fontName)
{
    char *name = REALGetStringContents(fontName, NULL);
    xsi_ssm(xsciObj(ctl), SCI_STYLESETFONT, style, (sptr_t)name);
}

REALstring xsim_styleGetFont(REALcontrolInstance ctl, int style)
{
    char *txtBuffer = malloc(1024);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_STYLEGETFONT, style, (sptr_t)txtBuffer);
    REALstring fontName = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(fontName);
    free(txtBuffer);
    return fontName;
}

void xsim_styleSetSize(REALcontrolInstance ctl, int style, int sizePoints)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETSIZE, style, sizePoints);
}

int xsim_styleGetSize(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETSIZE, style, 0);
}

void xsim_styleSetWeight(REALcontrolInstance ctl, int style, int weight)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETWEIGHT, style, weight);
}

int xsim_styleGetWeight(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETWEIGHT, style, 0);
}

void xsim_styleSetFore(REALcontrolInstance ctl, int style, RBColor fore)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETFORE, style, fore);
}

RBColor xsim_styleGetFore(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETFORE, style, 0);
}

void xsim_styleSetBack(REALcontrolInstance ctl, int style, RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETBACK, style, back);
}

RBColor xsim_styleGetBack(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETBACK, style, 0);
}

void xsim_styleSetVisible(REALcontrolInstance ctl, int style, bool visible)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETVISIBLE, style, visible);
}

bool xsim_styleGetVisible(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETVISIBLE, style, 0);
}
