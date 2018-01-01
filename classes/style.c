#include <stdlib.h>
#include "style.h"

void style_setcontrol(REALobject instance, REALcontrolInstance ctl)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    self->ctl = ctl;
}

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
int styling_getEndStyled(REALobject instance)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETENDSTYLED, 0, 0);
}

void styling_setIdleStyling(REALobject instance, long rbUnused, int idleStyling)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETIDLESTYLING, (uptr_t)idleStyling, 0);
}

int styling_getIdleStyling(REALobject instance)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETIDLESTYLING, 0, 0);
}

int styling_getMaxLineState(REALobject instance)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETMAXLINESTATE, 0, 0);
}

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
void style_styleResetDefault(REALobject instance)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLERESETDEFAULT, 0, 0);
}

void style_styleClearAll(REALobject instance)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLECLEARALL, 0, 0);
}

void style_styleSetFont(REALobject instance, int style, REALstring fontName)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);

    char* name = REALGetStringContents(fontName, NULL);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETFONT, (uptr_t)style, (sptr_t)name);
}

REALstring style_styleGetFont(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);

    int len = xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETFONT, (uptr_t)style, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETFONT, (uptr_t)style, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void style_styleSetSize(REALobject instance, int style, int sizePoints)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETSIZE, (uptr_t)style, (sptr_t)sizePoints);
}

int style_styleGetSize(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETSIZE, (uptr_t)style, 0);
}

void style_styleSetSizeFractional(REALobject instance, int style, int sizeHundredthPoints)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETSIZEFRACTIONAL, (uptr_t)style, (sptr_t)sizeHundredthPoints);
}

int style_styleGetSizeFractional(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETSIZEFRACTIONAL, (uptr_t)style, 0);
}

void style_styleSetBold(REALobject instance, int style, bool bold)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETBOLD, (uptr_t)style, (sptr_t)bold);
}

bool style_styleGetBold(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETBOLD, (uptr_t)style, 0);
}

void style_styleSetWeight(REALobject instance, int style, int weight)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETWEIGHT, (uptr_t)style, (sptr_t)weight);
}

int style_styleGetWeight(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETWEIGHT, (uptr_t)style, 0);
}

void style_styleSetItalic(REALobject instance, int style, bool italic)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETITALIC, (uptr_t)style, (sptr_t)italic);
}

bool style_styleGetItalic(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETITALIC, (uptr_t)style, 0);
}

void style_styleSetUnderline(REALobject instance, int style, bool underline)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETUNDERLINE, (uptr_t)style, (sptr_t)underline);
}

bool style_styleGetUnderline(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETUNDERLINE, (uptr_t)style, 0);
}

void style_styleSetFore(REALobject instance, int style, RBColor fore)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETFORE, (uptr_t)style, (sptr_t)xsi_invertColor(fore));
}

RBColor style_styleGetFore(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_invertColor(xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETFORE, (uptr_t)style, 0));
}

void style_styleSetBack(REALobject instance, int style, RBColor back)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETBACK, (uptr_t)style, (sptr_t)xsi_invertColor(back));
}

RBColor style_styleGetBack(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_invertColor(xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETBACK, (uptr_t)style, 0));
}

void style_styleSetEOLFilled(REALobject instance, int style, bool eolFilled)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETEOLFILLED, (uptr_t)style, (sptr_t)eolFilled);
}

bool style_styleGetEOLFilled(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETEOLFILLED, (uptr_t)style, 0);
}

void style_styleSetCharacterSet(REALobject instance, int style, int characterSet)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETCHARACTERSET, (uptr_t)style, (sptr_t)characterSet);
}

int style_styleGetCharacterSet(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETCHARACTERSET, (uptr_t)style, 0);
}

void style_styleSetCase(REALobject instance, int style, int caseVisible)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETCASE, (uptr_t)style, (sptr_t)caseVisible);
}

int style_styleGetCase(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETCASE, (uptr_t)style, 0);
}

void style_styleSetVisible(REALobject instance, int style, bool visible)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETVISIBLE, (uptr_t)style, (sptr_t)visible);
}

bool style_styleGetVisible(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETVISIBLE, (uptr_t)style, 0);
}

void style_styleSetChangeable(REALobject instance, int style, bool changeable)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETCHANGEABLE, (uptr_t)style, (sptr_t)changeable);
}

bool style_styleGetChangeable(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETCHANGEABLE, (uptr_t)style, 0);
}

void style_styleSetHotspot(REALobject instance, int style, bool hotspot)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STYLESETHOTSPOT, (uptr_t)style, (sptr_t)hotspot);
}

bool style_styleGetHotspot(REALobject instance, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_STYLEGETHOTSPOT, (uptr_t)style, 0);
}

void styling_startStyling(REALobject instance, int start)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_STARTSTYLING, (uptr_t)start, 0);
}
void styling_setStyling(REALobject instance, int start, int style)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETSTYLING, (uptr_t)start, (sptr_t)style);
}

void styling_setStylingEx(REALobject instance, int length, REALstring styles)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);

    char* value = REALGetStringContents(styles, NULL);
    xsi_ssm(xsciObj(self->ctl), SCI_SETSTYLINGEX, (uptr_t)length, (sptr_t)value);
}

void styling_setLineState(REALobject instance, int line, int state)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETLINESTATE, (uptr_t)line, (sptr_t)state);
}

int styling_getLineState(REALobject instance, int line)
{
    xsiStyleData* self = REALGetClassData(instance, &xsiStyleDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETLINESTATE, (uptr_t)line, 0);
}
