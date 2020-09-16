#include "api_selection.h"

int api_getTextLength(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETTEXTLENGTH, 0, 0);
}

int api_getLength(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLENGTH, 0, 0);
}

int api_getLineCount(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINECOUNT, 0, 0);
}

int api_lineOnScreen(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINESONSCREEN, 0, 0);
}

bool api_getModify(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMODIFY, 0, 0);
}

int api_getCurrentPos(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETCURRENTPOS, 0, 0);
}

void api_setCurrentPos(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETCURRENTPOS, (uptr_t)caret, 0);
}

int api_getAnchor(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETANCHOR, 0, 0);
}

void api_setAnchor(REALcontrolInstance ctl, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETANCHOR, (uptr_t)anchor, 0);
}

void api_setSelectionStart(REALcontrolInstance ctl, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONSTART, (uptr_t)anchor, 0);
}

int api_getSelectionStart(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONSTART, 0, 0);
}

void api_setSelectionEnd(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONEND, (uptr_t)caret, 0);
}

int api_getSelectionEnd(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONEND, 0, 0);
}

void api_hideSelection(REALcontrolInstance ctl, bool hide)
{
    xsi_ssm(xsciObj(ctl), SCI_HIDESELECTION, (uptr_t)hide, 0);
}

REALstring api_getSeltext(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_GETSELTEXT, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_GETSELTEXT, 0, (sptr_t)buffer);

    // has a terminated NULL character
    return xsi_toREALstring(buffer, len, true);
}

bool api_selectionIsRectangle(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_SELECTIONISRECTANGLE, 0, 0);
}

void api_setSelectionMode(REALcontrolInstance ctl, int mode)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONMODE, (uptr_t)mode, 0);
}

int api_getSelectionMode(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONMODE, 0, 0);
}

void api_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, bool mouseSwitch)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMOUSESELECTIONRECTANGULARSWITCH, (uptr_t)mouseSwitch, 0);
}

bool api_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMOUSESELECTIONRECTANGULARSWITCH, 0, 0);
}

void api_setSel(REALcontrolInstance ctl, int anchor, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSEL, (uptr_t)anchor, (uptr_t)caret);
}

void api_gotoPos(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_GOTOPOS, (uptr_t)caret, 0);
}

void api_gotoLine(REALcontrolInstance ctl, int line)
{
    xsi_ssm(xsciObj(ctl), SCI_GOTOLINE, (uptr_t)line, 0);
}

void api_setEmptySelection(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETEMPTYSELECTION, (uptr_t)caret, 0);
}

void api_selectAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_SELECTALL, 0, 0);
}

int api_lineFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINEFROMPOSITION, (uptr_t)pos, 0);
}

int api_positionFromLine(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMLINE, (uptr_t)line, 0);
}

int api_getLineEndPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINEENDPOSITION, (uptr_t)line, 0);
}

int api_lineLength(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINELENGTH, (uptr_t)line, 0);
}

int api_getColumn(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETCOLUMN, (uptr_t)pos, 0);
}

int api_findColumn(REALcontrolInstance ctl, int line, int column)
{
    return xsi_ssm(xsciObj(ctl), SCI_FINDCOLUMN, (uptr_t)line, (uptr_t)column);
}

int api_positionFromPoint(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMPOINT, (uptr_t)x, (sptr_t)y);
}

int api_positionFromPointClose(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMPOINTCLOSE, (uptr_t)x, (sptr_t)y);
}

int api_charPositionFromPoint(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHARPOSITIONFROMPOINT, (uptr_t)x, (uptr_t)y);
}

int api_charPositionFromPointClose(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHARPOSITIONFROMPOINTCLOSE, (uptr_t)x, (uptr_t)y);
}

int api_pointXFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POINTXFROMPOSITION, (uptr_t)pos, 0);
}

int api_pointYFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POINTYFROMPOSITION, (uptr_t)pos, 0);
}

REALstring api_getCurLine(REALcontrolInstance ctl)
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

int api_getLineSelStartPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINESELSTARTPOSITION, (uptr_t)line, 0);
}

int api_getLineSelEndPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINESELENDPOSITION, (uptr_t)line, 0);
}

void api_moveCaretInsideView(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MOVECARETINSIDEVIEW, 0, 0);
}

int api_positionBefore(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONBEFORE, (uptr_t)pos, 0);
}

int api_positionAfter(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONAFTER, (uptr_t)pos, 0);
}

int api_positionRelative(REALcontrolInstance ctl, int pos, int relative)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONRELATIVE, (uptr_t)pos, (uptr_t)relative);
}

int api_countCharacters(REALcontrolInstance ctl, int start, int end)
{
    return xsi_ssm(xsciObj(ctl), SCI_COUNTCHARACTERS, (uptr_t)start, (uptr_t)end);
}

int api_textWidth(REALcontrolInstance ctl, int style, REALstring text)
{
    char* txt = REALGetStringContents(text, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_TEXTWIDTH, (uptr_t)style, (sptr_t)txt);
}

int api_textHeight(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_TEXTHEIGHT, (uptr_t)line, 0);
}

void api_chooseCaretX(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_CHOOSECARETX, 0, 0);
}
void api_moveSelectedLinesUp(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MOVESELECTEDLINESUP, 0, 0);
}

void api_moveSelectedLinesDown(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MOVESELECTEDLINESDOWN, 0, 0);
}
