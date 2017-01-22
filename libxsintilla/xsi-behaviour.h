#ifndef XSINTILLA_BEHAVIOUR_H
#define XSINTILLA_BEHAVIOUR_H

#include "xsintilla.h"

void Constructor(REALcontrolInstance ctl);
void Destructor(REALcontrolInstance ctl);
void OnOpen(REALcontrolInstance ctl);
void OnDrawOffscreen(REALcontrolInstance ctl, REALgraphics g);
void OnStateChanged(REALcontrolInstance, uint32_t changedField);
#endif //XSINTILLA_BEHAVIOUR_H
