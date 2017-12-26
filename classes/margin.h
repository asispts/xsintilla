#ifndef CLASSES_MARGIN_H
#define CLASSES_MARGIN_H

#include "xsintilla.h"

REALclassDefinition xsiMarginDef;

typedef struct {
    REALcontrolInstance ctl;
} xsiMarginData;

void margin_setcontrol(REALobject instance, REALcontrolInstance ctl);

// Scintilla API

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
void margin_setMargins(REALobject instance, long rbUnused, int margins);
int margin_getMargins(REALobject instance);
void margin_setMarginLeft(REALobject instance, long rbUnused, int pixelWidth);
int margin_getMarginLeft(REALobject instance);
void margin_setMarginRight(REALobject instance, long rbUnused, int pixelWidth);
int margin_getMarginRight(REALobject instance);
void margin_marginSetStyleOffset(REALobject instance, long rbUnused, int style);
int margin_marginGetStyleOffset(REALobject instance);
void margin_setMarginOptions(REALobject instance, long rbUnused, int marginOptions);
int margin_getMarginOptions(REALobject instance);

//+++++++++++++++++++++++++++++++++
// Computed Properties
//+++++++++++++++++++++++++++++++++
void margin_marginSetText(REALobject instance, int line, REALstring text);
REALstring margin_marginGetText(REALobject instance, int line);
void margin_marginSetStyle(REALobject instance, int line, int style);
int margin_marginGetStyle(REALobject instance, int line);
void margin_marginSetStyles(REALobject instance, int line, REALstring styles);
REALstring margin_marginGetStyles(REALobject instance, int line);

void margin_setMarginTypeN(REALobject instance, int margin, int marginType);
int margin_getMarginTypeN(REALobject instance, int margin);
void margin_setMarginWidthN(REALobject instance, int margin, int pixelWidth);
int margin_getMarginWidthN(REALobject instance, int margin);
void margin_setMarginBackN(REALobject instance, int margin, RBColor back);
RBColor margin_getMarginBackN(REALobject instance, int margin);
void margin_setMarginMaskN(REALobject instance, int margin, int mask);
int margin_getMarginMaskN(REALobject instance, int margin);
void margin_setMarginSensitiveN(REALobject instance, int margin, bool sensitive);
bool margin_getMarginSensitiveN(REALobject instance, int margin);
void margin_setMarginCursorN(REALobject instance, int margin, int cursor);
int margin_getMarginCursorN(REALobject instance, int margin);

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
void margin_marginTextClearAll(REALobject instance);
void margin_setFoldMarginColour(REALobject instance, bool useSetting, RBColor back);
void margin_setFoldMarginHiColour(REALobject instance, bool useSetting, RBColor fore);

#endif  // CLASSES_MARGIN_H
