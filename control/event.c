#include "event.h"
#include <string.h>

static REALcontrolInstance me;
static fpStyleNeeded RaiseStyleNeeded = NULL;
static fpCharAdded RaiseCharAdded = NULL;
static fpEvent RaiseSavePointReached = NULL;
static fpEvent RaiseSavePointLeft = NULL;
static fpEvent RaiseModifyAtTempTro = NULL;
static fpScnKey RaiseScnKey = NULL;
static fpDoubleClick RaiseDoubleClick = NULL;
static fpUpdateUI RaiseUpdateUI = NULL;
static fpModified RaiseModified = NULL;
static fpMacroRecord RaiseMacroRecord = NULL;
static fpMarginClick RaiseMarginClick = NULL;
static fpNeedShown RaiseNeedShown = NULL;
static fpEvent RaisePainted = NULL;
static fpUserListSelection RaiseUserListSelection = NULL;
static fpUriDropped RaiseUriDropped = NULL;
static fpDwellStart RaiseDwellStart = NULL;
static fpDwellEnd RaiseDwellEnd = NULL;
static fpEvent RaiseZoom = NULL;
static fpHotspotClick RaiseHotspotClick = NULL;
static fpHotspotDoubleClick RaiseHotspotDoubleClick = NULL;
static fpCallTipClick RaiseCallTipClick = NULL;
static fpAutocSelection RaiseAutocSelection = NULL;
static fpIndicatorClick RaiseIndicatorClick = NULL;
static fpIndicatorRelease RaiseIndicatorRelease = NULL;
static fpEvent RaiseAutocCancelled = NULL;
static fpEvent RaiseAutocCharDeleted = NULL;
static fpHotspotReleaseClick RaiseHotspotReleaseClick = NULL;
static fpEvent RaiseFocusIn = NULL;
static fpEvent RaiseFocusOut = NULL;
static fpAutocCompleted RaiseAutocCompleted = NULL;
static fpEvent RaiseMarginRightClick = NULL;

void xsi_registerEventFunction(REALcontrolInstance ctl)
{
    me = ctl;

    RaiseStyleNeeded = (fpStyleNeeded)REALGetEventInstance(ctl, &xsiControl.events[scn_StyleNeeded]);
    RaiseCharAdded = (fpCharAdded)REALGetEventInstance(ctl, &xsiControl.events[scn_CharAdded]);
    RaiseSavePointReached = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_SavePointReached]);
    RaiseSavePointLeft = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_SavePointLeft]);
    RaiseModifyAtTempTro = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_ModifyAtTempTro]);
    RaiseScnKey = (fpScnKey)REALGetEventInstance(ctl, &xsiControl.events[scn_ScnKey]);
    RaiseDoubleClick = (fpDoubleClick)REALGetEventInstance(ctl, &xsiControl.events[scn_DoubleClick]);
    RaiseUpdateUI = (fpUpdateUI)REALGetEventInstance(ctl, &xsiControl.events[scn_UpdateUI]);
    RaiseModified = (fpModified)REALGetEventInstance(ctl, &xsiControl.events[scn_Modified]);
    RaiseMacroRecord = (fpMacroRecord)REALGetEventInstance(ctl, &xsiControl.events[scn_MacroRecord]);
    RaiseMarginClick = (fpMarginClick)REALGetEventInstance(ctl, &xsiControl.events[scn_MarginClick]);
    RaiseNeedShown = (fpNeedShown)REALGetEventInstance(ctl, &xsiControl.events[scn_NeedShown]);
    RaisePainted = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_painted]);
    RaiseUserListSelection = (fpUserListSelection)REALGetEventInstance(ctl, &xsiControl.events[scn_UserListSelection]);
    RaiseUriDropped = (fpUriDropped)REALGetEventInstance(ctl, &xsiControl.events[scn_UriDropped]);
    RaiseDwellStart = (fpDwellStart)REALGetEventInstance(ctl, &xsiControl.events[scn_DwellStart]);
    RaiseDwellEnd = (fpDwellEnd)REALGetEventInstance(ctl, &xsiControl.events[scn_DwellEnd]);
    RaiseZoom = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_Zoom]);
    RaiseHotspotClick = (fpHotspotClick)REALGetEventInstance(ctl, &xsiControl.events[scn_HotspotClick]);
    RaiseHotspotDoubleClick =
        (fpHotspotDoubleClick)REALGetEventInstance(ctl, &xsiControl.events[scn_HotspotDoubleClick]);
    RaiseCallTipClick = (fpCallTipClick)REALGetEventInstance(ctl, &xsiControl.events[scn_CallTipClick]);
    RaiseAutocSelection = (fpAutocSelection)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocSelection]);
    RaiseIndicatorClick = (fpIndicatorClick)REALGetEventInstance(ctl, &xsiControl.events[scn_IndicatorClick]);
    RaiseIndicatorRelease = (fpIndicatorRelease)REALGetEventInstance(ctl, &xsiControl.events[scn_IndicatorRelease]);
    RaiseAutocCancelled = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocCancelled]);
    RaiseAutocCharDeleted = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocCharDeleted]);
    RaiseHotspotReleaseClick =
        (fpHotspotReleaseClick)REALGetEventInstance(ctl, &xsiControl.events[scn_HotspotReleaseClick]);
    RaiseFocusIn = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_FocusIn]);
    RaiseFocusOut = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_FocusOut]);
    RaiseAutocCompleted = (fpAutocCompleted)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocCompleted]);
    RaiseMarginRightClick = (fpEvent)REALGetEventInstance(ctl, &xsiControl.events[scn_MarginRightClick]);
}

void sci_eventHandler(ScintillaObject* sci, gint controlID, SCNotification* notif, gpointer userData)
{
    switch(notif->nmhdr.code) {
    case SCN_STYLENEEDED:
        if(RaiseStyleNeeded) {
            RaiseStyleNeeded(me, notif->position);
        }
        break;

    case SCN_CHARADDED:
        if(RaiseCharAdded)
            RaiseCharAdded(me, notif->ch);
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

    case SCN_KEY:
        if(RaiseScnKey)
            RaiseScnKey(me, notif->ch);
        break;

    case SCN_DOUBLECLICK:
        if(RaiseDoubleClick)
            RaiseDoubleClick(me, notif->position, notif->modifiers);
        break;

    case SCN_UPDATEUI:
        if(RaiseUpdateUI)
            RaiseUpdateUI(me, notif->updated);
        break;

    case SCN_MODIFIED:
        if(RaiseModified) {
            REALstring txt = REALBuildStringWithEncoding(notif->text, notif->length, kREALTextEncodingUTF8);
            RaiseModified(me, notif->position, notif->modificationType, txt, notif->length, notif->linesAdded,
                          notif->line, notif->foldLevelNow, notif->foldLevelPrev, notif->token,
                          notif->annotationLinesAdded);
        }
        break;

    case SCN_MACRORECORD:
        if(RaiseMacroRecord)
            RaiseMacroRecord(me, notif->message, notif->wParam, notif->lParam);
        break;

    case SCN_MARGINCLICK:
        if(RaiseMarginClick)
            RaiseMarginClick(me, notif->position, notif->margin);
        break;

    case SCN_NEEDSHOWN:
        if(RaiseNeedShown)
            RaiseNeedShown(me, notif->position);
        break;

    case SCN_PAINTED:
        if(RaisePainted)
            RaisePainted(me);
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

    case SCN_URIDROPPED:
        if(RaiseUriDropped) {
            int len = notif->length;
            if(len <= 0)
                len = strlen(notif->text);
            REALstring txt = REALBuildStringWithEncoding(notif->text, len, kREALTextEncodingUTF8);
            RaiseUriDropped(me, txt);
        }
        break;

    case SCN_DWELLSTART:
        if(RaiseDwellStart)
            RaiseDwellStart(me, notif->position, notif->x, notif->y);
        break;

    case SCN_DWELLEND:
        if(RaiseDwellEnd)
            RaiseDwellEnd(me, notif->position, notif->x, notif->y);
        break;

    case SCN_ZOOM:
        if(RaiseZoom)
            RaiseZoom(me);
        break;

    case SCN_HOTSPOTCLICK:
        if(RaiseHotspotClick)
            RaiseHotspotClick(me, notif->position, notif->modifiers);
        break;

    case SCN_HOTSPOTDOUBLECLICK:
        if(RaiseHotspotDoubleClick)
            RaiseHotspotDoubleClick(me, notif->position, notif->modifiers);
        break;

    case SCN_CALLTIPCLICK:
        if(RaiseCallTipClick)
            RaiseCallTipClick(me, notif->position);
        break;

    case SCN_AUTOCSELECTION:
        if(RaiseAutocSelection)
            RaiseAutocSelection(me, notif->position, notif->ch, notif->listCompletionMethod);
        break;

    case SCN_INDICATORCLICK:
        if(RaiseIndicatorClick)
            RaiseIndicatorClick(me, notif->position, notif->modifiers);
        break;

    case SCN_INDICATORRELEASE:
        if(RaiseIndicatorRelease)
            RaiseIndicatorRelease(me, notif->position, notif->modifiers);
        break;

    case SCN_AUTOCCANCELLED:
        if(RaiseAutocCancelled)
            RaiseAutocCancelled(me);
        break;

    case SCN_AUTOCCHARDELETED:
        if(RaiseAutocCharDeleted)
            RaiseAutocCharDeleted(me);
        break;

    case SCN_HOTSPOTRELEASECLICK:
        if(RaiseHotspotReleaseClick)
            RaiseHotspotReleaseClick(me, notif->position, notif->modifiers);
        break;

    case SCN_FOCUSIN:
        if(RaiseFocusIn)
            RaiseFocusIn(me);
        break;

    case SCN_FOCUSOUT:
        if(RaiseFocusOut)
            RaiseFocusOut(me);
        break;

    case SCN_AUTOCCOMPLETED:
        if(RaiseAutocCompleted)
            RaiseAutocCompleted(me, notif->ch, notif->listCompletionMethod);
        break;

    case SCN_MARGINRIGHTCLICK:
        if(RaiseMarginRightClick)
            RaiseMarginRightClick(me);
        break;

    default:
        return;
        break;
    }
}
