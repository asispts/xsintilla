#include <stdlib.h>
#include "text-method.h"

void xsim_setSavePoint(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSAVEPOINT, 0, 0);
}

REALstring xsim_getLine(REALcontrolInstance ctl, int line)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_LINELENGTH, line, 0);

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_GETLINE, (uptr_t)line, (sptr_t)buffer);

    // The buffer is not terminated by a 0 character
    return xsi_toREALstring(buffer, len, false);
}

void xsim_replaceSel(REALcontrolInstance ctl, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_REPLACESEL, 0, (sptr_t)txt);
}

void xsim_allocate(REALcontrolInstance ctl, int bytes)
{
    xsi_ssm(xsciObj(ctl), SCI_ALLOCATE, (uptr_t)bytes, 0);
}

void xsim_addText(REALcontrolInstance ctl, int length, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_ADDTEXT, (uptr_t)length, (sptr_t)txt);
}

void xsim_appendText(REALcontrolInstance ctl, int length, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_APPENDTEXT, (uptr_t)length, (sptr_t)txt);
}

void xsim_insertText(REALcontrolInstance ctl, int pos, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_INSERTTEXT, (uptr_t)pos, (sptr_t)txt);
}

void xsim_clearAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_CLEARALL, 0, 0);
}

void xsim_deleteRange(REALcontrolInstance ctl, int start, int lengthDelete)
{
    xsi_ssm(xsciObj(ctl), SCI_DELETERANGE, (uptr_t)start, (uptr_t)lengthDelete);
}

void xsim_clearDocumentStyle(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_CLEARDOCUMENTSTYLE, 0, 0);
}

REALstring xsim_getCharAt(REALcontrolInstance ctl, int pos)
{
    char chr = (char)xsi_ssm(xsciObj(ctl), SCI_GETCHARAT, (uptr_t)pos, 0);
    REALstring text = REALBuildStringWithEncoding(&chr, 1, kREALTextEncodingUTF8);
    REALLockString(text);
    return text;
}

int xsim_getStyleAt(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSTYLEAT, (uptr_t)pos, 0);
}

void xsim_releaseAllExtendedStyles(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_RELEASEALLEXTENDEDSTYLES, 0, 0);
}

int xsim_allocateExtendedStyles(REALcontrolInstance ctl, int numberStyles)
{
    return xsi_ssm(xsciObj(ctl), SCI_ALLOCATEEXTENDEDSTYLES, (uptr_t)numberStyles, 0);
}

REALstring xsim_getTextRange(REALcontrolInstance ctl, Sci_PositionCR cpMin, Sci_PositionCR cpMax)
{
    if((cpMin < 0) || (cpMin >= cpMax))
        return NULL;

    long numBytes = 0;

    if(cpMax < 0) {
        // always contain \0
        long endPos = xsi_ssm(xsciObj(ctl), SCI_GETLENGTH, 0, 0);
        endPos = endPos - 1;
        if(endPos <= cpMin)
            return NULL;

        numBytes = endPos - cpMin;
    } else {
        numBytes = cpMax - cpMin;
    }

    if(numBytes <= 0) {
        return NULL;
    }

    struct Sci_TextRange tr;
    tr.chrg.cpMin = cpMin;
    tr.chrg.cpMax = cpMax;

    tr.lpstrText = malloc(numBytes + 1);
    long numChars = xsi_ssm(xsciObj(ctl), SCI_GETTEXTRANGE, 0, (sptr_t)&tr);

    // returned text not including terminating 0
    return xsi_toREALstring(tr.lpstrText, numChars, false);
}

REALstring xsim_targetAsUtf8(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_TARGETASUTF8, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_TARGETASUTF8, 0, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

REALstring xsim_encodeFromUtf8(REALcontrolInstance ctl, int length, REALstring utf8)
{
    char* txt = REALGetStringContents(utf8, NULL);

    xsi_ssm(xsciObj(ctl), SCI_SETLENGTHFORENCODE, length, 0);
    int len = xsi_ssm(xsciObj(ctl), SCI_ENCODEDFROMUTF8, (uptr_t)txt, 0);
    if(len == 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_ENCODEDFROMUTF8, (uptr_t)txt, (sptr_t)buffer);

    // let this code
    if(len == 0) {
        free(buffer);
        return NULL;
    }

    REALstring text = REALBuildStringWithEncoding(buffer, len, kREALTextEncodingUTF8);
    REALLockString(text);
    free(buffer);
    return text;
}

void xsim_addStyledText(REALcontrolInstance ctl, int length, REALstring styled_text)
{
    char* txt = REALGetStringContents(styled_text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_ADDSTYLEDTEXT, (uptr_t)length, (sptr_t)txt);
}

REALstring xsim_getStyledText(REALcontrolInstance ctl, Sci_PositionCR cpMin, Sci_PositionCR cpMax)
{
    if((cpMin < 0) || (cpMin >= cpMax))
        return NULL;

    long numBytes = 0;

    if(cpMax < 0) {
        // always contain \0
        long endPos = xsi_ssm(xsciObj(ctl), SCI_GETLENGTH, 0, 0);
        endPos = endPos - 1;
        if(endPos <= cpMin)
            return NULL;

        numBytes = endPos - cpMin;
    } else {
        numBytes = cpMax - cpMin;
    }

    if(numBytes <= 0) {
        return NULL;
    }

    struct Sci_TextRange tr;
    tr.chrg.cpMin = cpMin;
    tr.chrg.cpMax = cpMax;

    tr.lpstrText = malloc(numBytes + 2);  // termintated with 00
    long numChars = xsi_ssm(xsciObj(ctl), SCI_GETSTYLEDTEXT, 0, (sptr_t)&tr);

    // let this code
    if(numChars < 1) {
        free(tr.lpstrText);
        return NULL;
    }

    REALstring text = REALBuildStringWithEncoding(tr.lpstrText, numChars, kREALTextEncodingUTF8);
    REALLockString(text);
    free(tr.lpstrText);
    return text;
}

void xsim_changeInsertion(REALcontrolInstance ctl, int length, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(ctl), SCI_CHANGEINSERTION, (uptr_t)length, (sptr_t)txt);
}
