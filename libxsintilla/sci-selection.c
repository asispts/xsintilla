#include "stdlib.h"
#include "sci-selection.h"


/*=========================
 * properties
 * ========================*/
int xsip_getTextLength(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETTEXTLENGTH, 0, 0);
}

int xsip_getLength(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLENGTH, 0, 0);
}

int xsip_getLineCount(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINECOUNT, 0, 0);
}

int xsip_lineOnScreen(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINESONSCREEN, 0, 0);
}

bool xsip_getModify(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMODIFY, 0, 0);
}

int xsip_getCurrentPos(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETCURRENTPOS, 0, 0);
}

void xsip_setCurrentPos(REALcontrolInstance ctl, int unused, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETCURRENTPOS, caret, 0);
}

int xsip_getAnchor(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETANCHOR, 0, 0);
}

void xsip_setAnchor(REALcontrolInstance ctl, int unused, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETANCHOR, anchor, 0);
}

void xsip_setSelectionStart(REALcontrolInstance ctl, int unused, int anchor)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONSTART, anchor, 0);
}

int xsip_getSelectionStart(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONSTART, 0, 0);
}

void xsip_setSelectionEnd(REALcontrolInstance ctl, int unused, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONEND, caret, 0);
}

int xsip_getSelectionEnd(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONEND, 0, 0);
}

void xsip_hideSelection(REALcontrolInstance ctl, int unused, bool hide)
{
    xsi_ssm(xsciObj(ctl), SCI_HIDESELECTION, hide, 0);
}

REALstring xsip_getSeltext(REALcontrolInstance ctl, int unused)
{
    char *text = malloc(5*1024);
    int length = xsi_ssm(xsciObj(ctl), SCI_GETSELTEXT, 0, (sptr_t)text);
    REALstring txt = REALBuildStringWithEncoding(text, length, kREALTextEncodingUTF8);
    REALLockString(txt);
    free(text);
    return txt;
}

bool xsip_selectionIsRectangle(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_SELECTIONISRECTANGLE, 0, 0);
}

void xsip_setSelectionMode(REALcontrolInstance ctl, int unused, int mode)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSELECTIONMODE, mode, 0);
}

int xsip_getSelectionMode(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSELECTIONMODE, 0, 0);
}

void xsip_setMouseSelectionRectangularSwitch(REALcontrolInstance ctl, int unused, bool mouseSwitch)
{
    xsi_ssm(xsciObj(ctl), SCI_SETMOUSESELECTIONRECTANGULARSWITCH, mouseSwitch, 0);
}

bool xsip_getMouseSelectionRectangularSwitch(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETMOUSESELECTIONRECTANGULARSWITCH, 0, 0);
}


/*=========================
 * methods
 * ========================*/
void xsim_setSel(REALcontrolInstance ctl, int anchor, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETSEL, anchor, caret);
}

void xsim_gotoPos(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_GOTOPOS, caret, 0);
}

void xsim_gotoLine(REALcontrolInstance ctl, int line)
{
    xsi_ssm(xsciObj(ctl), SCI_GOTOLINE, line, 0);
}

void xsim_setEmptySelection(REALcontrolInstance ctl, int caret)
{
    xsi_ssm(xsciObj(ctl), SCI_SETEMPTYSELECTION, caret, 0);
}

void xsim_selectAll(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_SELECTALL, 0, 0);
}

int xsim_lineFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINEFROMPOSITION, pos, 0);
}

int xsim_positionFromLine(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMLINE, line, 0);
}

int xsim_getLineEndPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINEENDPOSITION, line, 0);
}

int xsim_lineLength(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_LINELENGTH, line, 0);
}

int xsim_getColumn(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETCOLUMN, pos, 0);
}

int xsim_findColumn(REALcontrolInstance ctl, int line, int column)
{
    return xsi_ssm(xsciObj(ctl), SCI_FINDCOLUMN, line, column);
}

int xsim_positionFromPoint(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMPOINT, x, y);
}

int xsim_positionFromPointClose(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONFROMPOINTCLOSE, x, y);
}

int xsim_charPositionFromPoint(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHARPOSITIONFROMPOINT, x, y);
}

int xsim_charPositionFromPointClose(REALcontrolInstance ctl, int x, int y)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHARPOSITIONFROMPOINTCLOSE, x, y);
}

int xsim_pointXFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POINTXFROMPOSITION, pos, 0);
}

int xsim_pointYFromPosition(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POINTYFROMPOSITION, pos, 0);
}

REALstring xsim_getCurLine(REALcontrolInstance ctl, int length)
{
    char *text = malloc(length+1);
    int retLen = xsi_ssm(xsciObj(ctl), SCI_GETCURLINE, length, (sptr_t)text);
    REALstring txt = REALBuildStringWithEncoding(text, retLen, kREALTextEncodingUTF8);
    REALLockString(txt);
    free(text);
    return txt;
}

int xsim_getLineSelStartPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINESELSTARTPOSITION, line, 0);
}

int xsim_getLineSelEndPosition(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLINESELENDPOSITION, line, 0);
}

void xsim_moveCaretInsideView(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_MOVECARETINSIDEVIEW, 0, 0);
}

int xsim_positionBefore(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONBEFORE, pos, 0);
}

int xsim_positionAfter(REALcontrolInstance ctl, int pos)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONAFTER, pos, 0);
}

int xsim_positionRelative(REALcontrolInstance ctl, int pos, int relative)
{
    return xsi_ssm(xsciObj(ctl), SCI_POSITIONRELATIVE, pos, relative);
}

int xsim_countCharacters(REALcontrolInstance ctl, int start, int end)
{
    return xsi_ssm(xsciObj(ctl), SCI_COUNTCHARACTERS, start, end);
}

int xsim_textWidth(REALcontrolInstance ctl, int style, REALstring text)
{
    char *txt = REALGetStringContents(text, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_TEXTWIDTH, style, (sptr_t)txt);
}

int xsim_textHeight(REALcontrolInstance ctl, int line)
{
    return xsi_ssm(xsciObj(ctl), SCI_TEXTHEIGHT, line, 0);
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
