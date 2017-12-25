#ifndef CONTROL_BEHAVIOUR_H
#define CONTROL_BEHAVIOUR_H

#include "xsintilla.h"

void Constructor(REALcontrolInstance ctl);
void Destructor(REALcontrolInstance ctl);
void OnOpen(REALcontrolInstance ctl);
void OnDrawOffscreen(REALcontrolInstance ctl, REALgraphics g);
void OnStateChanged(REALcontrolInstance, uint32_t changedField);

#endif  // CONTROL_BEHAVIOUR_H
