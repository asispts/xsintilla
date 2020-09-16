#include "api_style.h"

void api_styleResetDefault(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLERESETDEFAULT, 0, 0);
}

void api_styleClearAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLECLEARALL, 0, 0);
}

void api_styleSetFont(REALcontrolInstance ctl, int style, REALstring fontName)
{
    char* name = REALGetStringContents(fontName, NULL);
    xsi_ssm(xsciObj(ctl), SCI_STYLESETFONT, (uptr_t)style, (sptr_t)name);
}

REALstring api_styleGetFont(REALcontrolInstance ctl, int style)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_STYLEGETFONT, (uptr_t)style, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_STYLEGETFONT, (uptr_t)style, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void api_styleSetSize(REALcontrolInstance ctl, int style, int sizePoints)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETSIZE, (uptr_t)style, (sptr_t)sizePoints);
}

int api_styleGetSize(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETSIZE, (uptr_t)style, 0);
}

void api_styleSetWeight(REALcontrolInstance ctl, int style, int weight)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETWEIGHT, (uptr_t)style, (sptr_t)weight);
}

int api_styleGetWeight(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETWEIGHT, (uptr_t)style, 0);
}

void api_styleSetFore(REALcontrolInstance ctl, int style, RBColor fore)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETFORE, (uptr_t)style, (sptr_t)xsi_invertColor(fore));
}

RBColor api_styleGetFore(REALcontrolInstance ctl, int style)
{
    return xsi_invertColor(xsi_ssm(xsciObj(ctl), SCI_STYLEGETFORE, (uptr_t)style, 0));
}

void api_styleSetBack(REALcontrolInstance ctl, int style, RBColor back)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETBACK, (uptr_t)style, (sptr_t)xsi_invertColor(back));
}

RBColor api_styleGetBack(REALcontrolInstance ctl, int style)
{
    return xsi_invertColor(xsi_ssm(xsciObj(ctl), SCI_STYLEGETBACK, (uptr_t)style, 0));
}

void api_styleSetVisible(REALcontrolInstance ctl, int style, bool visible)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETVISIBLE, (uptr_t)style, (sptr_t)visible);
}

bool api_styleGetVisible(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETVISIBLE, (uptr_t)style, 0);
}

void api_styleSetSizeFractional(REALcontrolInstance ctl, int style, int sizeHundredthPoints)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETSIZEFRACTIONAL, (uptr_t)style, (sptr_t)sizeHundredthPoints);
}

int api_styleGetSizeFractional(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETSIZEFRACTIONAL, (uptr_t)style, 0);
}

void api_styleSetBold(REALcontrolInstance ctl, int style, bool bold)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETBOLD, (uptr_t)style, (sptr_t)bold);
}

bool api_styleGetBold(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETBOLD, (uptr_t)style, 0);
}

void api_styleSetItalic(REALcontrolInstance ctl, int style, bool italic)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETITALIC, (uptr_t)style, (sptr_t)italic);
}

bool api_styleGetItalic(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETITALIC, (uptr_t)style, 0);
}

void api_styleSetUnderline(REALcontrolInstance ctl, int style, bool underline)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETUNDERLINE, (uptr_t)style, (sptr_t)underline);
}

bool api_styleGetUnderline(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETUNDERLINE, (uptr_t)style, 0);
}

void api_styleSetEOLFilled(REALcontrolInstance ctl, int style, bool eolFilled)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETEOLFILLED, (uptr_t)style, (sptr_t)eolFilled);
}

bool api_styleGetEOLFilled(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETEOLFILLED, (uptr_t)style, 0);
}

void api_styleSetCharacterSet(REALcontrolInstance ctl, int style, int characterSet)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETCHARACTERSET, (uptr_t)style, (sptr_t)characterSet);
}

int api_styleGetCharacterSet(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETCHARACTERSET, (uptr_t)style, 0);
}

void api_styleSetCase(REALcontrolInstance ctl, int style, int caseVisible)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETCASE, (uptr_t)style, (sptr_t)caseVisible);
}

int api_styleGetCase(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETCASE, (uptr_t)style, 0);
}

void api_styleSetChangeable(REALcontrolInstance ctl, int style, bool changeable)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETCHANGEABLE, (uptr_t)style, (sptr_t)changeable);
}

bool api_styleGetChangeable(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETCHANGEABLE, (uptr_t)style, 0);
}

void api_styleSetHotspot(REALcontrolInstance ctl, int style, bool hotspot)
{
    xsi_ssm(xsciObj(ctl), SCI_STYLESETHOTSPOT, (uptr_t)style, (sptr_t)hotspot);
}

bool api_styleGetHotspot(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_STYLEGETHOTSPOT, (uptr_t)style, 0);
}
