#include <stdio.h>
#include <stdlib.h>
#include "margin.h"

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
void margin_setcontrol(REALobject instance, REALcontrolInstance ctl)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    self->ctl = ctl;
}

void margin_setMargins(REALobject instance, long rbUnused, int margins)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINS, (uptr_t)margins, 0);
}

int margin_getMargins(REALobject instance)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINS, 0, 0);
}

void margin_setMarginLeft(REALobject instance, long rbUnused, int pixelWidth)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINLEFT, 0, (sptr_t)pixelWidth);
}

int margin_getMarginLeft(REALobject instance)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINLEFT, 0, 0);
}

void margin_setMarginRight(REALobject instance, long rbUnused, int pixelWidth)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINRIGHT, 0, (sptr_t)pixelWidth);
}

int margin_getMarginRight(REALobject instance)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINRIGHT, 0, 0);
}

void margin_marginSetStyleOffset(REALobject instance, long rbUnused, int style)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_MARGINSETSTYLEOFFSET, (uptr_t)style, 0);
}

int margin_marginGetStyleOffset(REALobject instance)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_MARGINGETSTYLEOFFSET, 0, 0);
}

void margin_setMarginOptions(REALobject instance, long rbUnused, int marginOptions)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINOPTIONS, (uptr_t)marginOptions, 0);
}

int margin_getMarginOptions(REALobject instance)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINOPTIONS, 0, 0);
}

//+++++++++++++++++++++++++++++++++
// Computed Properties
//+++++++++++++++++++++++++++++++++
void margin_marginSetText(REALobject instance, int line, REALstring text)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);

    char* txt = REALGetStringContents(text, NULL);
    xsi_ssm(xsciObj(self->ctl), SCI_MARGINSETTEXT, (uptr_t)line, (sptr_t)txt);
}

REALstring margin_marginGetText(REALobject instance, int line)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);

    int len = xsi_ssm(xsciObj(self->ctl), SCI_MARGINGETTEXT, (uptr_t)line, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(self->ctl), SCI_MARGINGETTEXT, (uptr_t)line, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void margin_marginSetStyle(REALobject instance, int line, int style)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_MARGINSETSTYLE, (uptr_t)line, (sptr_t)style);
}

int margin_marginGetStyle(REALobject instance, int line)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_MARGINGETSTYLE, (uptr_t)line, 0);
}

void margin_marginSetStyles(REALobject instance, int line, REALstring styles)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);

    char* sty = REALGetStringContents(styles, NULL);
    xsi_ssm(xsciObj(self->ctl), SCI_MARGINSETSTYLES, (uptr_t)line, (sptr_t)sty);
    printf("margin_marginSetStyles::styles = %s\n", sty);
}

REALstring margin_marginGetStyles(REALobject instance, int line)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);

    int len = xsi_ssm(xsciObj(self->ctl), SCI_MARGINGETSTYLES, 0, 0);
    if(len <= 0) {
        printf("margin_marginGetStyles: Failed, len = %d\n", len);
        return NULL;
    }

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(self->ctl), SCI_MARGINGETSTYLES, (uptr_t)line, (sptr_t)buffer);

    printf("margin_marginGetStyles::buffer = %s, len = %d\n", buffer, len);
    return xsi_toREALstring(buffer, len, false);
}

void margin_setMarginTypeN(REALobject instance, int margin, int marginType)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINTYPEN, (uptr_t)margin, (sptr_t)marginType);
}

int margin_getMarginTypeN(REALobject instance, int margin)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINTYPEN, (uptr_t)margin, 0);
}

void margin_setMarginWidthN(REALobject instance, int margin, int pixelWidth)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINWIDTHN, (uptr_t)margin, (sptr_t)pixelWidth);
}

int margin_getMarginWidthN(REALobject instance, int margin)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINWIDTHN, (uptr_t)margin, 0);
}

void margin_setMarginBackN(REALobject instance, int margin, RBColor back)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINBACKN, (uptr_t)margin, (sptr_t)xsi_invertColor(back));
}

RBColor margin_getMarginBackN(REALobject instance, int margin)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_invertColor(xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINBACKN, (uptr_t)margin, 0));
}

void margin_setMarginMaskN(REALobject instance, int margin, int mask)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINMASKN, (uptr_t)margin, (sptr_t)mask);
}

int margin_getMarginMaskN(REALobject instance, int margin)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINMASKN, (uptr_t)margin, 0);
}

void margin_setMarginSensitiveN(REALobject instance, int margin, bool sensitive)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINSENSITIVEN, (uptr_t)margin, (sptr_t)sensitive);
}

bool margin_getMarginSensitiveN(REALobject instance, int margin)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINSENSITIVEN, (uptr_t)margin, 0);
}

void margin_setMarginCursorN(REALobject instance, int margin, int cursor)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETMARGINCURSORN, (uptr_t)margin, (sptr_t)cursor);
}

int margin_getMarginCursorN(REALobject instance, int margin)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMARGINCURSORN, (uptr_t)margin, 0);
}

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
void margin_marginTextClearAll(REALobject instance)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_MARGINTEXTCLEARALL, 0, 0);
}

void margin_setFoldMarginColour(REALobject instance, bool useSetting, RBColor back)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETFOLDMARGINCOLOUR, (uptr_t)useSetting, (sptr_t)xsi_invertColor(back));
}

void margin_setFoldMarginHiColour(REALobject instance, bool useSetting, RBColor fore)
{
    xsiMarginData* self = REALGetClassData(instance, &xsiMarginDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETFOLDMARGINHICOLOUR, (uptr_t)useSetting, (sptr_t)xsi_invertColor(fore));
}
