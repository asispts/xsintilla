//======================================
//Margins
//======================================

#ifndef SCI_MARGIN_H
#define SCI_MARGIN_H

#include "xsintilla.h"

//properties
void xsip_setMargins(REALcontrolInstance ctl, int unused, int margins);
int xsip_getMargins(REALcontrolInstance ctl, int unused);
void xsip_setMarginLeft(REALcontrolInstance ctl, int unused, int pixelWidth);
int xsip_getMarginLeft(REALcontrolInstance ctl, int unused);
void xsip_setMarginRight(REALcontrolInstance ctl, int unused, int pixelWidth);
int xsip_getMarginRight(REALcontrolInstance ctl, int unused);
void xsip_marginSetStyleOffset(REALcontrolInstance ctl, int unused, int style);
int xsip_marginGetStyleOffset(REALcontrolInstance ctl, int unused);
void xsip_setMarginOptions(REALcontrolInstance ctl, int unused, int marginOptions);
int xsip_getMarginOptions(REALcontrolInstance ctl, int unused);


//computed methods
void xsim_setMarginTypeN(REALcontrolInstance ctl, int margin, int marginType);
int xsim_getMarginTypeN(REALcontrolInstance ctl, int margin);
void xsim_setMarginWidthN(REALcontrolInstance ctl, int margin, int pixelWidth);
int xsim_getMarginWidthN(REALcontrolInstance ctl, int margin);
void xsim_setMarginBackN(REALcontrolInstance ctl, int margin, RBColor back);
RBColor xsim_getMarginBackN(REALcontrolInstance ctl, int margin);
void xsim_setMarginMaskN(REALcontrolInstance ctl, int margin, int mask);
int xsim_getMarginMaskN(REALcontrolInstance ctl, int margin);
void xsim_setMarginSensitiveN(REALcontrolInstance ctl, int margin, bool sensitive);
bool xsim_getMarginSensitiveN(REALcontrolInstance ctl, int margin);
void xsim_setMarginCursorN(REALcontrolInstance ctl, int margin, int cursor);
int xsim_getMarginCursorN(REALcontrolInstance ctl, int margin);

void xsim_marginSetText(REALcontrolInstance ctl, int line, REALstring text);
REALstring xsim_marginGetText(REALcontrolInstance ctl, int line);
void xsim_marginSetStyle(REALcontrolInstance ctl, int line, int style);
int xsim_marginGetStyle(REALcontrolInstance ctl, int line);
void xsim_marginSetStyles(REALcontrolInstance ctl, int line, REALstring styles);
REALstring xsim_marginGetStyles(REALcontrolInstance ctl, int line);
void xsim_marginTextClearAll(REALcontrolInstance ctl);


//methods
void xsim_setFoldMarginColour(REALcontrolInstance ctl, bool useSetting, RBColor back);
void xsim_setFoldMarginHiColour(REALcontrolInstance ctl, bool useSetting, RBColor fore);


#endif //SCI_MARGIN_H
