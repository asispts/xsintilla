#ifndef PROPERTIES_TEXT_H
#define PROPERTIES_TEXT_H

#include "xsintilla.h"

void xsip_setReadonly(REALcontrolInstance ctl, long rbUnused, bool readOnly);
bool xsip_getReadonly(REALcontrolInstance ctl);
REALstring xsip_getText(REALcontrolInstance ctl);
void xsip_setText(REALcontrolInstance ctl, long rbUnused, REALstring text);

#endif  // PROPERTIES_TEXT_H
