#include "stdlib.h"
#include "sci-text.h"

void xsip_setReadonly(REALcontrolInstance ctl, int unused,  bool readOnly)
{
    xsiControlData *data = xsi_getControlData(ctl);
    xsi_ssm(data->sci, SCI_SETREADONLY, readOnly, 0);
}

bool xsip_getReadonly(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETREADONLY, 0, 0);
}

REALstring xsip_getText(REALcontrolInstance ctl, int unused)
{
    int length = xsi_ssm(xsciObj(ctl), SCI_GETTEXTLENGTH, 0, 0);
    char *txtBuffer = malloc(length+1);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_GETTEXT, length+1, (sptr_t)txtBuffer);
    REALstring txt = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(txt);
    free(txtBuffer);
    return txt;
}

void xsip_setText(REALcontrolInstance ctl, int unused, REALstring text)
{
    char *txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETTEXT, 0, (sptr_t)txt);
}

void xsim_setSavePoint(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSAVEPOINT, 0, 0);
}

REALstring xsim_getLine(REALcontrolInstance ctl, int line)
{
    char *txtBuffer = malloc(5*1024);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_GETLINE, line, (sptr_t)txtBuffer);
    REALstring txt = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(txt);
    free(txtBuffer);
    return txt;
}

void xsim_replaceSel(REALcontrolInstance ctl, REALstring text)
{
    char *txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_REPLACESEL, 0, (sptr_t)txt);
}

void xsim_allocate(REALcontrolInstance ctl, int bytes)
{
    xsi_ssm(xsciObj(ctl), SCI_ALLOCATE, bytes, 0);
}

void xsim_addText(REALcontrolInstance ctl, int length, REALstring text)
{
    char *txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_ADDTEXT, length, (sptr_t)txt);
}

void xsim_appendText(REALcontrolInstance ctl, int length, REALstring text)
{
    char *txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_APPENDTEXT, length, (sptr_t)txt);
}

void xsim_insertText(REALcontrolInstance ctl, int pos, REALstring text)
{
    char *txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_INSERTTEXT, pos, (sptr_t)txt);
}

void xsim_clearAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_CLEARALL, 0, 0);
}

void xsim_deleteRange(REALcontrolInstance ctl, int start, int lengthDelete)
{
    xsi_ssm(xsciObj(ctl), SCI_DELETERANGE, start, lengthDelete);
}

void xsim_clearDocumentStyle(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_CLEARDOCUMENTSTYLE, 0, 0);
}

REALstring xsim_getCharAt(REALcontrolInstance ctl, int pos)
{
    char chr = xsi_ssm(xsciObj(ctl), SCI_GETCHARAT, pos, 0);
    REALstring text = REALBuildStringWithEncoding(&chr, 1, kREALTextEncodingUTF8);
    REALLockString(text);
    return text;
}

int xsim_getStyleAt(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSTYLEAT, pos, 0);
}

void xsim_releaseAllExtendedStyles(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_RELEASEALLEXTENDEDSTYLES, 0, 0);
}

int xsim_allocateExtendedStyles(REALcontrolInstance ctl, int numberStyles)
{
    return xsi_ssm(xsciObj(ctl), SCI_ALLOCATEEXTENDEDSTYLES, numberStyles, 0);
}
