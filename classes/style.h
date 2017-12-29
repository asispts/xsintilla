#ifndef CLASSES_STYLE_H
#define CLASSES_STYLE_H

#include "xsintilla.h"

REALclassDefinition xsiStyleDef;

typedef struct {
    REALcontrolInstance ctl;
} xsiStyleData;

void style_setcontrol(REALobject instance, REALcontrolInstance ctl);

// Scintilla API

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
void style_styleResetDefault(REALobject instance);
void style_styleClearAll(REALobject instance);

void style_styleSetFont(REALobject instance, int style, REALstring fontName);
REALstring style_styleGetFont(REALobject instance, int style);

void style_styleSetSize(REALobject instance, int style, int sizePoints);
int style_styleGetSize(REALobject instance, int style);

void style_styleSetSizeFractional(REALobject instance, int style, int sizeHundredthPoints);
int style_styleGetSizeFractional(REALobject instance, int style);

void style_styleSetBold(REALobject instance, int style, bool bold);
bool style_styleGetBold(REALobject instance, int style);

void style_styleSetWeight(REALobject instance, int style, int weight);
int style_styleGetWeight(REALobject instance, int style);

void style_styleSetItalic(REALobject instance, int style, bool italic);
bool style_styleGetItalic(REALobject instance, int style);

void style_styleSetUnderline(REALobject instance, int style, bool underline);
bool style_styleGetUnderline(REALobject instance, int style);

void style_styleSetFore(REALobject instance, int style, RBColor fore);
RBColor style_styleGetFore(REALobject instance, int style);

void style_styleSetBack(REALobject instance, int style, RBColor back);
RBColor style_styleGetBack(REALobject instance, int style);

void style_styleSetEOLFilled(REALobject instance, int style, bool eolFilled);
bool style_styleGetEOLFilled(REALobject instance, int style);

void style_styleSetCharacterSet(REALobject instance, int style, int characterSet);
int style_styleGetCharacterSet(REALobject instance, int style);

void style_styleSetCase(REALobject instance, int style, int caseVisible);
int style_styleGetCase(REALobject instance, int style);

void style_styleSetVisible(REALobject instance, int style, bool visible);
bool style_styleGetVisible(REALobject instance, int style);

void style_styleSetChangeable(REALobject instance, int style, bool changeable);
bool style_styleGetChangeable(REALobject instance, int style);

void style_styleSetHotspot(REALobject instance, int style, bool hotspot);
bool style_styleGetHotspot(REALobject instance, int style);

#endif  // CLASSES_STYLE_H
