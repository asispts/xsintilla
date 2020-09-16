//======================================
//Markers
//======================================

#ifndef SCI_MARKER_H
#define SCI_MARKER_H

#include "xsintilla.h"

//properties
void xsip_rgbaImageSetWidth(REALcontrolInstance ctl, int unused, int width);
void xsip_rgbaImageSetHeight(REALcontrolInstance ctl, int unused, int height);
void xsip_rgbaImageSetScale(REALcontrolInstance ctl, int unused, int scalePercent);
void xsip_markerEnableHighlight(REALcontrolInstance ctl, int unused, bool enabled);

//methods
void xsim_markerDefine(REALcontrolInstance ctl, int markerNumber, int markerSymbol);
void xsim_markerSetFore(REALcontrolInstance ctl, int markerNumber, RBColor fore);
void xsim_markerSetBack(REALcontrolInstance ctl, int markerNumber, RBColor back);
void xsim_markerSetBackSelected(REALcontrolInstance ctl, int markerNumber, RBColor back);
void xsim_markerDefineRgbaImage(REALcontrolInstance ctl, int markerNumber, REALstring pixels);
int xsim_markerSymbolDefined(REALcontrolInstance ctl, int markerNumber);
int xsim_markerAdd(REALcontrolInstance ctl, int line, int markerNumber);
void xsim_markerAddSet(REALcontrolInstance ctl, int line, int markerNumber);
void xsim_markerDelete(REALcontrolInstance ctl, int line, int markerNumber);
void xsim_markerDeleteAll(REALcontrolInstance ctl, int markerNumber);
int xsim_markerGet(REALcontrolInstance ctl, int line);
int xsim_markerNext(REALcontrolInstance ctl, int lineStart, int markerMask);
int xsim_markerPrevious(REALcontrolInstance ctl, int lineStart, int markerMask);

#endif //SCI_MARKER_H
