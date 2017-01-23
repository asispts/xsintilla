//======================================
//Styling
//======================================

#ifndef SCI_STYLING_H
#define SCI_STYLING_H

#include "xsintilla.h"

int xsim_getEndStyled(REALcontrolInstance ctl);
void xsim_startStyling(REALcontrolInstance ctl, int start);
void xsim_setStyling(REALcontrolInstance ctl, int length, int style);

#endif //SCI_STYLING_H
