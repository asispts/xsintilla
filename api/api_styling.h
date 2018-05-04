#ifndef API_STYLING_H
#define API_STYLING_H

#include "xsintilla.h"

int api_getEndStyled(REALcontrolInstance ctl);
void api_startStyling(REALcontrolInstance ctl, int start);
void api_setStyling(REALcontrolInstance ctl, int start, int style);
void api_setStylingEx(REALcontrolInstance ctl, int length, REALstring styles);
void api_setIdleStyling(REALcontrolInstance ctl, int idleStyling);
int api_getIdleStyling(REALcontrolInstance ctl);
void api_setLineState(REALcontrolInstance ctl, int line, int state);
int api_getLineState(REALcontrolInstance ctl, int line);
int api_getMaxLineState(REALcontrolInstance ctl);

#endif // API_STYLING_H
