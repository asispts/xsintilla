//=================================
// Text retrieval and modification
//=================================

#ifndef PROPERTIES_TEXT_H
#define PROPERTIES_TEXT_H

#include "xsintilla.h"

void xsip_setReadonly(REALcontrolInstance ctl, int unused, bool readOnly);
bool xsip_getReadonly(REALcontrolInstance ctl, int unused);
REALstring xsip_getText(REALcontrolInstance ctl, int unused);
void xsip_setText(REALcontrolInstance ctl, int unused, REALstring text);

#endif  // PROPERTIES_TEXT_H
