#include <stdlib.h>
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

void xsip_setMarginLeft(REALcontrolInstance ctl, int unused, int pixelWidth)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINLEFT, 0, pixelWidth);
}

int xsip_getMarginLeft(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINLEFT, 0, 0);
}

void xsip_setMarginRight(REALcontrolInstance ctl, int unused, int pixelWidth)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINRIGHT, 0, pixelWidth);
}

int xsip_getMarginRight(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINRIGHT, 0, 0);
}

void xsip_marginSetStyleOffset(REALcontrolInstance ctl, int unused, int style)
{
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETSTYLEOFFSET, style, 0);
}

int xsip_marginGetStyleOffset(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARGINGETSTYLEOFFSET, 0, 0);
}

void xsip_setMarginOptions(REALcontrolInstance ctl, int unused, int marginOptions)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINOPTIONS, marginOptions, 0);
}

int xsip_getMarginOptions(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINOPTIONS, 0, 0);
}


/*=========================
 * assigns methods
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

void xsim_setMarginSensitiveN(REALcontrolInstance ctl, int margin, bool sensitive)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINSENSITIVEN, margin, sensitive);
}

bool xsim_getMarginSensitiveN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINSENSITIVEN, margin, 0);
}

void xsim_setMarginCursorN(REALcontrolInstance ctl, int margin, int cursor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINCURSORN, margin, cursor);
}

int xsim_getMarginCursorN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINCURSORN, margin, 0);
}

void xsim_marginSetText(REALcontrolInstance ctl, int line, REALstring text)
{
    char *txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETTEXT, line, (sptr_t)txt);
}

REALstring xsim_marginGetText(REALcontrolInstance ctl, int line)
{
    char *txtBuffer = malloc(1024);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_MARGINGETTEXT, 1024, (sptr_t)txtBuffer);
    REALstring text = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(text);
    free(txtBuffer);
    return text;
}

void xsim_marginSetStyle(REALcontrolInstance ctl, int line, int style)
{
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETSTYLE, line, style);
}

int xsim_marginGetStyle(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARGINGETSTYLE, line, 0);
}

void xsim_marginSetStyles(REALcontrolInstance ctl, int line, REALstring styles)
{
    char *sty = REALGetStringContents(styles, NULL);
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETSTYLES, line, (sptr_t)sty);
}

REALstring xsim_marginGetStyles(REALcontrolInstance ctl, int line)
{
    char *txtBuffer = malloc(1024);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_MARGINGETSTYLES, 1024, (sptr_t)txtBuffer);
    REALstring sty = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(sty);
    free(txtBuffer);
    return sty;
}




/*=========================
 * methods
 * ========================*/
void xsim_marginTextClearAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MARGINTEXTCLEARALL, 0, 0);
}

void xsim_setFoldMarginColour(REALcontrolInstance ctl, bool useSetting, RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_SETFOLDMARGINCOLOUR, useSetting, xsi_invertColor(back));
}

void xsim_setFoldMarginHiColour(REALcontrolInstance ctl, bool useSetting, RBColor fore)
{
    xsi_ssm(xsciObj(ctl), SCI_SETFOLDMARGINHICOLOUR, useSetting, xsi_invertColor(fore));
}
