//======================================
//Style definition
//======================================

#ifndef SCI_STYLEDEF_H
#define SCI_STYLEDEF_H

#include "xsintilla.h"

//methods
void xsim_styleResetDefault(REALcontrolInstance ctl);
void xsim_styleClearAll(REALcontrolInstance ctl);

void xsim_styleSetFont(REALcontrolInstance ctl, int style, REALstring fontName);
REALstring xsim_styleGetFont(REALcontrolInstance ctl, int style);

void xsim_styleSetSize(REALcontrolInstance ctl, int style, int sizePoints);
int xsim_styleGetSize(REALcontrolInstance ctl, int style);

void xsim_styleSetWeight(REALcontrolInstance ctl, int style, int weight);
int xsim_styleGetWeight(REALcontrolInstance ctl, int style);

void xsim_styleSetFore(REALcontrolInstance ctl, int style, RBColor fore);
RBColor xsim_styleGetFore(REALcontrolInstance ctl, int style);

void xsim_styleSetBack(REALcontrolInstance ctl, int style, RBColor back);
RBColor xsim_styleGetBack(REALcontrolInstance ctl, int style);

void xsim_styleSetVisible(REALcontrolInstance ctl, int style, bool visible);
bool xsim_styleGetVisible(REALcontrolInstance ctl, int style);



//void xsim_styleSetSizeFractional(REALcontrolInstance ctl, int style, int sizeHundredthPoints);
//int xsim_styleGetSizeFractional(REALcontrolInstance ctl, int style);
//void xsim_styleSetBold(REALcontrolInstance ctl, int style, bool bold);
//bool xsim_styleGetBold(REALcontrolInstance ctl, int style);
//void xsim_styleSetItalic(REALcontrolInstance ctl, int style, bool italic);
//bool xsim_styleGetItalic(REALcontrolInstance ctl, int style);
//void xsim_styleSetUnderline(REALcontrolInstance ctl, int style, bool underline);
//bool xsim_styleGetUnderline(REALcontrolInstance ctl, int style);
//void xsim_styleSetEOLFilled(REALcontrolInstance ctl, int style, bool eolFilled);
//bool xsim_styleGetEOLFilled(REALcontrolInstance ctl, int style);
//void xsim_styleSetCharacterSet(REALcontrolInstance ctl, int style, int characterSet);
//int xsim_styleGetCharacterSet(REALcontrolInstance ctl, int style);
//void xsim_styleSetCase(REALcontrolInstance ctl, int style, int caseVisible);
//int xsim_styleGetCase(REALcontrolInstance ctl, int style);
//void xsim_styleSetChangeable(REALcontrolInstance ctl, int style, bool changeable);
//bool xsim_styleGetChangeable(REALcontrolInstance ctl, int style);
//void xsim_styleSetHotspot(REALcontrolInstance ctl, int style, bool hotspot);
//bool xsim_styleGetHotspot(REALcontrolInstance ctl, int style);

#endif //SCI_STYLEDEF_H
