#ifndef API_STYLE_H
#define API_STYLE_H

#include "xsintilla.h"

void api_styleResetDefault(REALcontrolInstance ctl);
void api_styleClearAll(REALcontrolInstance ctl);
void api_styleSetFont(REALcontrolInstance ctl, int style, REALstring fontName);
REALstring api_styleGetFont(REALcontrolInstance ctl, int style);
void api_styleSetSize(REALcontrolInstance ctl, int style, int sizePoints);
int api_styleGetSize(REALcontrolInstance ctl, int style);
void api_styleSetWeight(REALcontrolInstance ctl, int style, int weight);
int api_styleGetWeight(REALcontrolInstance ctl, int style);
void api_styleSetFore(REALcontrolInstance ctl, int style, RBColor fore);
RBColor api_styleGetFore(REALcontrolInstance ctl, int style);
void api_styleSetBack(REALcontrolInstance ctl, int style, RBColor back);
RBColor api_styleGetBack(REALcontrolInstance ctl, int style);
void api_styleSetVisible(REALcontrolInstance ctl, int style, bool visible);
bool api_styleGetVisible(REALcontrolInstance ctl, int style);
void api_styleSetSizeFractional(REALcontrolInstance ctl, int style, int sizeHundredthPoints);
int api_styleGetSizeFractional(REALcontrolInstance ctl, int style);
void api_styleSetBold(REALcontrolInstance ctl, int style, bool bold);
bool api_styleGetBold(REALcontrolInstance ctl, int style);
void api_styleSetItalic(REALcontrolInstance ctl, int style, bool italic);
bool api_styleGetItalic(REALcontrolInstance ctl, int style);
void api_styleSetUnderline(REALcontrolInstance ctl, int style, bool underline);
bool api_styleGetUnderline(REALcontrolInstance ctl, int style);
void api_styleSetEOLFilled(REALcontrolInstance ctl, int style, bool eolFilled);
bool api_styleGetEOLFilled(REALcontrolInstance ctl, int style);
void api_styleSetCharacterSet(REALcontrolInstance ctl, int style, int characterSet);
int api_styleGetCharacterSet(REALcontrolInstance ctl, int style);
void api_styleSetCase(REALcontrolInstance ctl, int style, int caseVisible);
int api_styleGetCase(REALcontrolInstance ctl, int style);
void api_styleSetChangeable(REALcontrolInstance ctl, int style, bool changeable);
bool api_styleGetChangeable(REALcontrolInstance ctl, int style);
void api_styleSetHotspot(REALcontrolInstance ctl, int style, bool hotspot);
bool api_styleGetHotspot(REALcontrolInstance ctl, int style);

#endif // API_STYLE_H
