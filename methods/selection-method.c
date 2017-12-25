#include <stdlib.h>
#include "selection-method.h"

void xsim_setSel(REALcontrolInstance ctl, int anchor, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSEL, (uptr_t)anchor, (uptr_t)caret);
}

void xsim_gotoPos(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_GOTOPOS, (uptr_t)caret, 0);
}

void xsim_gotoLine(REALcontrolInstance ctl, int line)
{
    xsi_ssm(xsciObj(ctl), SCI_GOTOLINE, (uptr_t)line, 0);
}

void xsim_setEmptySelection(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETEMPTYSELECTION, (uptr_t)caret, 0);
}

void xsim_selectAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_SELECTALL, 0, 0);
}

int xsim_lineFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINEFROMPOSITION, (uptr_t)pos, 0);
}

int xsim_positionFromLine(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMLINE, (uptr_t)line, 0);
}

int xsim_getLineEndPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINEENDPOSITION, (uptr_t)line, 0);
}

int xsim_lineLength(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINELENGTH, (uptr_t)line, 0);
}

int xsim_getColumn(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETCOLUMN, (uptr_t)pos, 0);
}

int xsim_findColumn(REALcontrolInstance ctl, int line, int column)
{
    return xsi_ssm(xsciObj(ctl), SCI_FINDCOLUMN, (uptr_t)line, (uptr_t)column);
}

int xsim_positionFromPoint(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMPOINT, (uptr_t)x, (sptr_t)y);
}

int xsim_positionFromPointClose(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMPOINTCLOSE, (uptr_t)x, (sptr_t)y);
}

int xsim_charPositionFromPoint(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHARPOSITIONFROMPOINT, (uptr_t)x, (uptr_t)y);
}

int xsim_charPositionFromPointClose(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHARPOSITIONFROMPOINTCLOSE, (uptr_t)x, (uptr_t)y);
}

int xsim_pointXFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POINTXFROMPOSITION, (uptr_t)pos, 0);
}

int xsim_pointYFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POINTYFROMPOSITION, (uptr_t)pos, 0);
}

REALstring xsim_getCurLine(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_GETCURLINE, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    int textLen = len;
    len = xsi_ssm(xsciObj(ctl), SCI_GETCURLINE, (uptr_t)len, (sptr_t)buffer);

    // has 0 character
    return xsi_toREALstring(buffer, textLen, true);
}

int xsim_getLineSelStartPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINESELSTARTPOSITION, (uptr_t)line, 0);
}

int xsim_getLineSelEndPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINESELENDPOSITION, (uptr_t)line, 0);
}

void xsim_moveCaretInsideView(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MOVECARETINSIDEVIEW, 0, 0);
}

int xsim_positionBefore(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONBEFORE, (uptr_t)pos, 0);
}

int xsim_positionAfter(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONAFTER, (uptr_t)pos, 0);
}

int xsim_positionRelative(REALcontrolInstance ctl, int pos, int relative)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONRELATIVE, (uptr_t)pos, (uptr_t)relative);
}

int xsim_countCharacters(REALcontrolInstance ctl, int start, int end)
{
    return xsi_ssm(xsciObj(ctl), SCI_COUNTCHARACTERS, (uptr_t)start, (uptr_t)end);
}

int xsim_textWidth(REALcontrolInstance ctl, int style, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_TEXTWIDTH, (uptr_t)style, (sptr_t)txt);
}

int xsim_textHeight(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_TEXTHEIGHT, (uptr_t)line, 0);
}

void xsim_chooseCaretX(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_CHOOSECARETX, 0, 0);
}
void xsim_moveSelectedLinesUp(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MOVESELECTEDLINESUP, 0, 0);
}

void xsim_moveSelectedLinesDown(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MOVESELECTEDLINESDOWN, 0, 0);
}
