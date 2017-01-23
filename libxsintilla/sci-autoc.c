#include "sci-autoc.h"

/*=========================
 * properties
 * ========================*/
void xsip_autocSetIgnoreCase(REALcontrolInstance ctl, int unused, bool ignoreCase)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETIGNORECASE, ignoreCase, 0);
}
bool xsip_autocGetIgnoreCase(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETIGNORECASE, 0, 0);
}

void xsip_autocSetSeparator(REALcontrolInstance ctl, int unused, int separatorCharacter)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETSEPARATOR, separatorCharacter, 0);
}
int xsip_autocGetSeparator(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETSEPARATOR, 0, 0);
}

void xsip_autocSetCancelAtStart(REALcontrolInstance ctl, int unused, bool cancel)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETCANCELATSTART, cancel, 0);
}
bool xsip_autocGetCancelAtStart(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETCANCELATSTART, 0, 0);
}

void xsip_autocSetChooseSingle(REALcontrolInstance ctl, int unused, bool chooseSingle)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETCHOOSESINGLE, chooseSingle, 0);
}
bool xsip_autocGetChooseSingle(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETCHOOSESINGLE, 0, 0);
}

void xsip_autocSetCaseInsensitiveBehaviour(REALcontrolInstance ctl, int unused, int behaviour)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETCASEINSENSITIVEBEHAVIOUR, behaviour, 0);
}
int xsip_autocGetCaseInsensitiveBehaviour(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETCASEINSENSITIVEBEHAVIOUR, 0, 0);
}

void xsip_autocSetMulti(REALcontrolInstance ctl, int unused, int multi)

{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETMULTI, multi, 0);
}
int xsip_autocGetMulti(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETMULTI, 0, 0);
}

void xsip_autocSetOrder(REALcontrolInstance ctl, int unused, int order)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETORDER, order, 0);
}
int xsip_autocGetOrder(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETORDER, 0, 0);
}

void xsip_autocSetAutoHide(REALcontrolInstance ctl, int unused, bool autoHide)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETAUTOHIDE, autoHide, 0);
}
bool xsip_autocGetAutoHide(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETAUTOHIDE, 0, 0);
}

void xsip_autocSetDropRestOfWord(REALcontrolInstance ctl, int unused, bool dropRestOfWord)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETDROPRESTOFWORD, dropRestOfWord, 0);
}
bool xsip_autocGetDropRestOfWord(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETDROPRESTOFWORD, 0, 0);
}

void xsip_autocSetTypeSeparator(REALcontrolInstance ctl, int unused, int separatorCharacter)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETTYPESEPARATOR, separatorCharacter, 0);
}
int xsip_autocGetTypeSeparator(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETTYPESEPARATOR, 0, 0);
}

void xsip_autocSetMaxHeight(REALcontrolInstance ctl, int unused, int rowCount)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETMAXHEIGHT, rowCount, 0);
}
int xsip_autocGetMaxHeight(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETMAXHEIGHT, 0, 0);
}

void xsip_autocSetMaxWidth(REALcontrolInstance ctl, int unused, int characterCount)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETMAXWIDTH, characterCount, 0);
}
int xsip_autocGetMaxWidth(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETMAXWIDTH, 0, 0);
}



/*=========================
 * methods
 * ========================*/
void xsim_autocShow(REALcontrolInstance ctl, int lengthEntered, REALstring itemList)
{
    char *item = REALGetStringContents(itemList, NULL);
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSHOW, lengthEntered, (sptr_t)item);
}

void xsim_autocCancel(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCCANCEL, 0, 0);
}

bool xsim_autocActive(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCACTIVE, 0, 0);
}

void xsim_autocComplete(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_AUTOCCOMPLETE, 0, 0);
}

int xsim_autocPosStart(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCPOSSTART, 0, 0);
}

void xsim_autocStops(REALcontrolInstance ctl, REALstring characterSet)
{
    char *chrSet = REALGetStringContents(characterSet, NULL);
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSTOPS, 0, (sptr_t)chrSet);
}

void xsim_autocSelect(REALcontrolInstance ctl, REALstring select)
{
    char *chrSelect = REALGetStringContents(select, NULL);
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSELECT, 0, (sptr_t)chrSelect);
}

int xsim_autocGetCurrent(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETCURRENT, 0, 0);
}

int xsim_autocGetCurrentText(REALcontrolInstance ctl, REALstring text)
{
    char *chrText = REALGetStringContents(text, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_AUTOCGETCURRENTTEXT, 0, (sptr_t)chrText);
}

void xsim_autocSetFillUps(REALcontrolInstance ctl, REALstring characterSet)
{
    char *chrSet = REALGetStringContents(characterSet, NULL);
    xsi_ssm(xsciObj(ctl), SCI_AUTOCSETFILLUPS, 0, (sptr_t)chrSet);
}
