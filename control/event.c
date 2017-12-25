#include <stdio.h>
#include <string.h>
#include "event.h"

static REALcontrolInstance me;
static fpAutocCompleted RaiseAutocCompleted = NULL;
static fpAutocSelection RaiseAutocSelection = NULL;
static fpCallTipClick RaiseCallTipClick = NULL;
static fpCharAdded RaiseCharAdded = NULL;
static fpDoubleClick RaiseDoubleClick = NULL;
static fpDwellEnd RaiseDwellEnd = NULL;
static fpDwellStart RaiseDwellStart = NULL;
static fpHotspotClick RaiseHotspotClick = NULL;
static fpHotspotDoubleClick RaiseHotspotDoubleClick = NULL;
static fpHotspotReleaseClick RaiseHotspotReleaseClick = NULL;
static fpIndicatorClick RaiseIndicatorClick = NULL;
static fpIndicatorRelease RaiseIndicatorRelease = NULL;
static fpScnKey RaiseScnKey = NULL;
static fpMacroRecord RaiseMacroRecord = NULL;
static fpMarginClick RaiseMarginClick = NULL;
static fpModified RaiseModified = NULL;
static fpNeedShown RaiseNeedShown = NULL;
static fpStyleNeeded RaiseStyleNeeded = NULL;
static fpUpdateUI RaiseUpdateUI = NULL;
static fpUriDropped RaiseUriDropped = NULL;
static fpUserListSelection RaiseUserListSelection = NULL;

static fpEvent RaiseSavePointReached = NULL;
static fpEvent RaiseSavePointLeft = NULL;
static fpEvent RaiseModifyAtTempTro = NULL;
static fpEvent RaiseZoom = NULL;
static fpEvent RaiseAutocCancelled = NULL;
static fpEvent RaiseAutocCharDeleted = NULL;
static fpEvent RaiseFocusIn = NULL;
static fpEvent RaiseFocusOut = NULL;
static fpEvent RaiseMarginRightClick = NULL;
static fpEvent RaisePainted = NULL;

void xsi_registerEventFunction(REALcontrolInstance ctl)
{
    me = ctl;
    RaiseAutocCompleted = (fpAutocCompleted)REALGetEventInstance(ctl, &xsiControl.events[xse_AutocCompleted]);
    RaiseAutocSelection = (fpAutocSelection)REALGetEventInstance(ctl, &xsiControl.events[xse_AutocSelection]);
    RaiseCallTipClick = (fpCallTipClick)REALGetEventInstance(ctl, &xsiControl.events[xse_CallTipClick]);
    RaiseCharAdded = (fpCharAdded)REALGetEventInstance(ctl, &xsiControl.events[xse_CharAdded]);
    RaiseDoubleClick = (fpDoubleClick)REALGetEventInstance(ctl, &xsiControl.events[xse_DoubleClick]);
    RaiseDwellEnd = (fpDwellEnd)REALGetEventInstance(ctl, &xsiControl.events[xse_DwellEnd]);
    RaiseDwellStart = (fpDwellStart)REALGetEventInstance(ctl, &xsiControl.events[xse_DwellStart]);
    RaiseHotspotClick = (fpHotspotClick)REALGetEventInstance(ctl, &xsiControl.events[xse_HotspotClick]);
    RaiseHotspotDoubleClick =
        (fpHotspotDoubleClick)REALGetEventInstance(ctl, &xsiControl.events[xse_HotspotDoubleClick]);
    RaiseHotspotReleaseClick =
        (fpHotspotReleaseClick)REALGetEventInstance(ctl, &xsiControl.events[xse_HotspotReleaseClick]);
    RaiseIndicatorClick = (fpIndicatorClick)REALGetEventInstance(ctl, &xsiControl.events[xse_IndicatorClick]);
    RaiseIndicatorRelease = (fpIndicatorRelease)REALGetEventInstance(ctl, &xsiControl.events[xse_IndicatorRelease]);
    RaiseScnKey = (fpScnKey)REALGetEventInstance(ctl, &xsiControl.events[xse_ScnKey]);
    RaiseMacroRecord = (fpMacroRecord)REALGetEventInstance(ctl, &xsiControl.events[xse_MacroRecord]);
    RaiseMarginClick = (fpMarginClick)REALGetEventInstance(ctl, &xsiControl.events[xse_MarginClick]);
    RaiseModified = (fpModified)REALGetEventInstance(ctl, &xsiControl.events[xse_Modified]);
    RaiseNeedShown = (fpNeedShown)REALGetEventInstance(ctl, &xsiControl.events[xse_NeedShown]);
    RaiseStyleNeeded = (fpStyleNeeded)REALGetEventInstance(ctl, &xsiControl.events[xse_StyleNeeded]);
    RaiseUpdateUI = (fpUpdateUI)REALGetEventInstance(ctl, &xsiControl.events[xse_UpdateUI]);
    RaiseUriDropped = (fpUriDropped)REALGetEventInstance(ctl, &xsiControl.events[xse_UriDropped]);
    RaiseUserListSelection = (fpUserListSelection)REALGetEventInstance(ctl, &xsiControl.events[xse_UserListSelection]);

    RaiseSavePointReached = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_SavePointReached]);
    RaiseSavePointLeft = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_SavePointLeft]);
    RaiseModifyAtTempTro = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_ModifyAtTempTro]);
    RaiseZoom = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_Zoom]);
    RaiseAutocCancelled = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_AutocCancelled]);
    RaiseAutocCharDeleted = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_AutocCharDeleted]);
    RaiseFocusIn = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_FocusIn]);
    RaiseFocusOut = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_FocusOut]);
    RaiseMarginRightClick = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_MarginRightClick]);
    RaisePainted = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[xse_painted]);
}

void sci_eventHandler(ScintillaObject* sci, gint controlID, SCNotification* notif, gpointer userData)
{
    (void)*sci;
    (void)controlID;
    (void)userData;

    switch(notif->nmhdr.code) {
    case SCN_AUTOCCOMPLETED:
        if(RaiseAutocCompleted)
            RaiseAutocCompleted(me, notif->ch, notif->listCompletionMethod);
        break;
    case SCN_AUTOCSELECTION:
        if(RaiseAutocSelection)
            RaiseAutocSelection(me, notif->position, notif->ch, notif->listCompletionMethod);
        break;
    case SCN_CALLTIPCLICK:
        if(RaiseCallTipClick)
            RaiseCallTipClick(me, notif->position);
        break;
    case SCN_CHARADDED:
        if(RaiseCharAdded)
            RaiseCharAdded(me, notif->ch);
        break;
    case SCN_DOUBLECLICK:
        if(RaiseDoubleClick)
            RaiseDoubleClick(me, notif->position, notif->modifiers);
        break;
    case SCN_DWELLEND:
        if(RaiseDwellEnd)
            RaiseDwellEnd(me, notif->position, notif->x, notif->y);
        break;
    case SCN_DWELLSTART:
        if(RaiseDwellStart)
            RaiseDwellStart(me, notif->position, notif->x, notif->y);
        break;
    case SCN_HOTSPOTCLICK:
        if(RaiseHotspotClick)
            RaiseHotspotClick(me, notif->position, notif->modifiers);
        break;
    case SCN_HOTSPOTDOUBLECLICK:
        if(RaiseHotspotDoubleClick)
            RaiseHotspotDoubleClick(me, notif->position, notif->modifiers);
        break;
    case SCN_HOTSPOTRELEASECLICK:
        if(RaiseHotspotReleaseClick)
            RaiseHotspotReleaseClick(me, notif->position, notif->modifiers);
        break;
    case SCN_INDICATORCLICK:
        if(RaiseIndicatorClick)
            RaiseIndicatorClick(me, notif->position, notif->modifiers);
        break;
    case SCN_INDICATORRELEASE:
        if(RaiseIndicatorRelease)
            RaiseIndicatorRelease(me, notif->position, notif->modifiers);
        break;
    case SCN_KEY:
        if(RaiseScnKey)
            RaiseScnKey(me, notif->ch);
        break;
    case SCN_MACRORECORD:
        if(RaiseMacroRecord)
            RaiseMacroRecord(me, notif->message, notif->wParam, notif->lParam);
        break;
    case SCN_MARGINCLICK:
        if(RaiseMarginClick)
            RaiseMarginClick(me, notif->position, notif->margin);
        break;
    case SCN_MODIFIED:
        if(RaiseModified) {
            REALstring txt = REALBuildStringWithEncoding(notif->text, notif->length, kREALTextEncodingUTF8);
            RaiseModified(me, notif->position, notif->modificationType, txt, notif->length, notif->linesAdded,
                          notif->line, notif->foldLevelNow, notif->foldLevelPrev, notif->token,
                          notif->annotationLinesAdded);
        }
        break;
    case SCN_NEEDSHOWN:
        if(RaiseNeedShown)
            RaiseNeedShown(me, notif->position);
        break;
    case SCN_STYLENEEDED:
        if(RaiseStyleNeeded)
            RaiseStyleNeeded(me, notif->position);
        break;
    case SCN_UPDATEUI:
        if(RaiseUpdateUI)
            RaiseUpdateUI(me, notif->updated);
        break;
    case SCN_URIDROPPED:
        if(RaiseUriDropped) {
            int len = notif->length;
            if(len <= 0)
                len = strlen(notif->text);
            REALstring txt = REALBuildStringWithEncoding(notif->text, len, kREALTextEncodingUTF8);
            RaiseUriDropped(me, txt);
        }
        break;
    case SCN_USERLISTSELECTION:
        if(RaiseUserListSelection) {
            int len = notif->length;
            if(len <= 0)
                len = strlen(notif->text);
            REALstring txt = REALBuildStringWithEncoding(notif->text, len, kREALTextEncodingUTF8);
            RaiseUserListSelection(me, notif->position, notif->ch, txt, notif->listType, notif->listCompletionMethod);
        }
        break;

    case SCN_SAVEPOINTREACHED:
        if(RaiseSavePointReached)
            RaiseSavePointReached(me);
        break;
    case SCN_SAVEPOINTLEFT:
        if(RaiseSavePointLeft)
            RaiseSavePointLeft(me);
        break;
    case SCN_MODIFYATTEMPTRO:
        if(RaiseModifyAtTempTro)
            RaiseModifyAtTempTro(me);
        break;
    case SCN_ZOOM:
        if(RaiseZoom)
            RaiseZoom(me);
        break;
    case SCN_AUTOCCANCELLED:
        if(RaiseAutocCancelled)
            RaiseAutocCancelled(me);
        break;
    case SCN_AUTOCCHARDELETED:
        if(RaiseAutocCharDeleted)
            RaiseAutocCharDeleted(me);
        break;
    case SCN_FOCUSIN:
        if(RaiseFocusIn)
            RaiseFocusIn(me);
        break;
    case SCN_FOCUSOUT:
        if(RaiseFocusOut)
            RaiseFocusOut(me);
        break;
    case SCN_MARGINRIGHTCLICK:
        if(RaiseMarginRightClick)
            RaiseMarginRightClick(me);
        break;
    case SCN_PAINTED:
        if(RaisePainted)
            RaisePainted(me);
        break;
    default:
        return;
        break;
    }
}
