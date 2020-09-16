#ifndef API_MARGIN_H
#define API_MARGIN_H

#include "xsintilla.h"

void api_setMargins(REALcontrolInstance ctl, int margins);
int api_getMargins(REALcontrolInstance ctl);
void api_setMarginLeft(REALcontrolInstance ctl, int pixelWidth);
int api_getMarginLeft(REALcontrolInstance ctl);
void api_setMarginRight(REALcontrolInstance ctl, int pixelWidth);
int api_getMarginRight(REALcontrolInstance ctl);
void api_marginSetStyleOffset(REALcontrolInstance ctl, int style);
int api_marginGetStyleOffset(REALcontrolInstance ctl);
void api_setMarginOptions(REALcontrolInstance ctl, int marginOptions);
int api_getMarginOptions(REALcontrolInstance ctl);
void api_setMarginTypeN(REALcontrolInstance ctl, int margin, int marginType);
int api_getMarginTypeN(REALcontrolInstance ctl, int margin);
void api_setMarginWidthN(REALcontrolInstance ctl, int margin, int pixelWidth);
int api_getMarginWidthN(REALcontrolInstance ctl, int margin);
void api_setMarginBackN(REALcontrolInstance ctl, int margin, RBColor back);
RBColor api_getMarginBackN(REALcontrolInstance ctl, int margin);
void api_setMarginMaskN(REALcontrolInstance ctl, int margin, int mask);
int api_getMarginMaskN(REALcontrolInstance ctl, int margin);
void api_setMarginSensitiveN(REALcontrolInstance ctl, int margin, bool sensitive);
bool api_getMarginSensitiveN(REALcontrolInstance ctl, int margin);
void api_setMarginCursorN(REALcontrolInstance ctl, int margin, int cursor);
int api_getMarginCursorN(REALcontrolInstance ctl, int margin);
void api_marginSetText(REALcontrolInstance ctl, int line, REALstring text);
REALstring api_marginGetText(REALcontrolInstance ctl, int line);
void api_marginSetStyle(REALcontrolInstance ctl, int line, int style);
int api_marginGetStyle(REALcontrolInstance ctl, int line);
void api_marginSetStyles(REALcontrolInstance ctl, int line, REALstring styles);
REALstring api_marginGetStyles(REALcontrolInstance ctl, int line);
void api_marginTextClearAll(REALcontrolInstance ctl);
void api_setFoldMarginColour(REALcontrolInstance ctl, bool useSetting, RBColor back);
void api_setFoldMarginHiColour(REALcontrolInstance ctl, bool useSetting, RBColor fore);

#endif // API_MARGIN_H
