#ifndef SCI_AUTOC_H
#define SCI_AUTOC_H

#include "xsintilla.h"

//properties
void xsip_autocSetIgnoreCase(REALcontrolInstance ctl, int unused, bool ignoreCase);
bool xsip_autocGetIgnoreCase(REALcontrolInstance ctl, int unused);

void xsip_autocSetSeparator(REALcontrolInstance ctl, int unused, int separatorCharacter);
int xsip_autocGetSeparator(REALcontrolInstance ctl, int unused);

void xsip_autocSetCancelAtStart(REALcontrolInstance ctl, int unused, bool cancel);
bool xsip_autocGetCancelAtStart(REALcontrolInstance ctl, int unused);

void xsip_autocSetChooseSingle(REALcontrolInstance ctl, int unused, bool chooseSingle);
bool xsip_autocGetChooseSingle(REALcontrolInstance ctl, int unused);

void xsip_autocSetCaseInsensitiveBehaviour(REALcontrolInstance ctl, int unused, int behaviour);
int xsip_autocGetCaseInsensitiveBehaviour(REALcontrolInstance ctl, int unused);

void xsip_autocSetMulti(REALcontrolInstance ctl, int unused, int multi);
int xsip_autocGetMulti(REALcontrolInstance ctl, int unused);

void xsip_autocSetOrder(REALcontrolInstance ctl, int unused, int order);
int xsip_autocGetOrder(REALcontrolInstance ctl, int unused);

void xsip_autocSetAutoHide(REALcontrolInstance ctl, int unused, bool autoHide);
bool xsip_autocGetAutoHide(REALcontrolInstance ctl, int unused);

void xsip_autocSetDropRestOfWord(REALcontrolInstance ctl, int unused, bool dropRestOfWord);
bool xsip_autocGetDropRestOfWord(REALcontrolInstance ctl, int unused);

void xsip_autocSetTypeSeparator(REALcontrolInstance ctl, int unused, int separatorCharacter);
int xsip_autocGetTypeSeparator(REALcontrolInstance ctl, int unused);

void xsip_autocSetMaxHeight(REALcontrolInstance ctl, int unused, int rowCount);
int xsip_autocGetMaxHeight(REALcontrolInstance ctl, int unused);

void xsip_autocSetMaxWidth(REALcontrolInstance ctl, int unused, int characterCount);
int xsip_autocGetMaxWidth(REALcontrolInstance ctl, int unused);


//methods
void xsim_autocShow(REALcontrolInstance ctl, int lengthEntered, REALstring itemList);
void xsim_autocCancel(REALcontrolInstance ctl);
bool xsim_autocActive(REALcontrolInstance ctl);
void xsim_autocComplete(REALcontrolInstance ctl);
int xsim_autocPosStart(REALcontrolInstance ctl);
void xsim_autocStops(REALcontrolInstance ctl, REALstring characterSet);
void xsim_autocSelect(REALcontrolInstance ctl, REALstring select);
int xsim_autocGetCurrent(REALcontrolInstance ctl);
REALstring xsim_autocGetCurrentText(REALcontrolInstance ctl);
void xsim_autocSetFillUps(REALcontrolInstance ctl, REALstring characterSet);

#endif //SCI_AUTOC_H
