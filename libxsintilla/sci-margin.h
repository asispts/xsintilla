//======================================
//Margins
//======================================

#ifndef SCI_MARGIN_H
#define SCI_MARGIN_H

#include "xsintilla.h"

//properties
void xsim_setMargins(REALcontrolInstance ctl, int unused, int margins);
int xsim_getMargins(REALcontrolInstance ctl, int unused);

//computed methods
void xsim_setMarginTypeN(REALcontrolInstance ctl, int margin, int marginType);
int xsim_getMarginTypeN(REALcontrolInstance ctl, int margin);
void xsim_setMarginWidthN(REALcontrolInstance ctl, int margin, int pixelWidth);
int xsim_getMarginWidthN(REALcontrolInstance ctl, int margin);
void xsim_setMarginBackN(REALcontrolInstance ctl, int margin, RBColor back);
RBColor xsim_getMarginBackN(REALcontrolInstance ctl, int margin);

#endif //SCI_MARGIN_H
