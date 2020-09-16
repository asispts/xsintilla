#include "api_margin.h"

void api_setMargins(REALcontrolInstance ctl, int margins)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINS, (uptr_t)margins, 0);
}

int api_getMargins(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINS, 0, 0);
}

void api_setMarginLeft(REALcontrolInstance ctl, int pixelWidth)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINLEFT, 0, (sptr_t)pixelWidth);
}

int api_getMarginLeft(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINLEFT, 0, 0);
}

void api_setMarginRight(REALcontrolInstance ctl, int pixelWidth)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINRIGHT, 0, (sptr_t)pixelWidth);
}

int api_getMarginRight(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINRIGHT, 0, 0);
}

void api_marginSetStyleOffset(REALcontrolInstance ctl, int style)
{
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETSTYLEOFFSET, (uptr_t)style, 0);
}

int api_marginGetStyleOffset(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARGINGETSTYLEOFFSET, 0, 0);
}

void api_setMarginOptions(REALcontrolInstance ctl, int marginOptions)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINOPTIONS, (uptr_t)marginOptions, 0);
}

int api_getMarginOptions(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINOPTIONS, 0, 0);
}

void api_setMarginTypeN(REALcontrolInstance ctl, int margin, int marginType)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINTYPEN, (uptr_t)margin, (sptr_t)marginType);
}

int api_getMarginTypeN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINTYPEN, (uptr_t)margin, 0);
}

void api_setMarginWidthN(REALcontrolInstance ctl, int margin, int pixelWidth)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINWIDTHN, (uptr_t)margin, (sptr_t)pixelWidth);
}

int api_getMarginWidthN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINWIDTHN, (uptr_t)margin, 0);
}

void api_setMarginBackN(REALcontrolInstance ctl, int margin, RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINBACKN, (uptr_t)margin, (sptr_t)xsi_invertColor(back));
}

RBColor api_getMarginBackN(REALcontrolInstance ctl, int margin)
{
    return xsi_invertColor(xsi_ssm(xsciObj(ctl), SCI_GETMARGINBACKN, (uptr_t)margin, 0));
}

void api_setMarginMaskN(REALcontrolInstance ctl, int margin, int mask)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINMASKN, (uptr_t)margin, (sptr_t)mask);
}

int api_getMarginMaskN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINMASKN, (uptr_t)margin, 0);
}

void api_setMarginSensitiveN(REALcontrolInstance ctl, int margin, bool sensitive)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINSENSITIVEN, (uptr_t)margin, (sptr_t)sensitive);
}

bool api_getMarginSensitiveN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINSENSITIVEN, (uptr_t)margin, 0);
}

void api_setMarginCursorN(REALcontrolInstance ctl, int margin, int cursor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMARGINCURSORN, (uptr_t)margin, (sptr_t)cursor);
}

int api_getMarginCursorN(REALcontrolInstance ctl, int margin)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMARGINCURSORN, (uptr_t)margin, 0);
}

void api_marginSetText(REALcontrolInstance ctl, int line, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETTEXT, (uptr_t)line, (sptr_t)txt);
}

REALstring api_marginGetText(REALcontrolInstance ctl, int line)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_MARGINGETTEXT, (uptr_t)line, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_MARGINGETTEXT, (uptr_t)line, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void api_marginSetStyle(REALcontrolInstance ctl, int line, int style)
{
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETSTYLE, (uptr_t)line, (sptr_t)style);
}

int api_marginGetStyle(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_MARGINGETSTYLE, (uptr_t)line, 0);
}

void api_marginSetStyles(REALcontrolInstance ctl, int line, REALstring styles)
{
    char* sty = REALGetStringContents(styles, NULL);
    xsi_ssm(xsciObj(ctl), SCI_MARGINSETSTYLES, (uptr_t)line, (sptr_t)sty);
}

REALstring api_marginGetStyles(REALcontrolInstance ctl, int line)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_MARGINGETSTYLES, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_MARGINGETSTYLES, (uptr_t)line, (sptr_t)buffer);
    return xsi_toREALstring(buffer, len, false);
}

void api_marginTextClearAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MARGINTEXTCLEARALL, 0, 0);
}

void api_setFoldMarginColour(REALcontrolInstance ctl, bool useSetting, RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_SETFOLDMARGINCOLOUR, (uptr_t)useSetting, (sptr_t)xsi_invertColor(back));
}

void api_setFoldMarginHiColour(REALcontrolInstance ctl, bool useSetting, RBColor fore)
{
    xsi_ssm(xsciObj(ctl), SCI_SETFOLDMARGINHICOLOUR, (uptr_t)useSetting, (sptr_t)xsi_invertColor(fore));
}
