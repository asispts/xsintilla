#include "event.h"
#include <string.h>

typedef void (*fpCtl)(REALcontrolInstance);
typedef void (*fpCtli)(REALcontrolInstance, int);
typedef void (*fpCtlii)(REALcontrolInstance, int, int);
typedef void (*fpCtliii)(REALcontrolInstance, int, int, int);
typedef void (*fpUriDropped)(REALcontrolInstance, REALstring);
typedef void (*fpUserListSelection)(REALcontrolInstance, Sci_Position, int, REALstring, int, int);
typedef void (*fpModified)(REALcontrolInstance, int, int, REALstring, int, int, int, int, int, int, int);

void sci_eventHandler(ScintillaObject* sci, gint controlID, SCNotification* notif, REALcontrolInstance ctl)
{
    switch(notif->nmhdr.code) {
    case SCN_STYLENEEDED: {
        fpCtli styleNeeded = (fpCtli)REALGetEventInstance(ctl, &xsiControl.events[scn_StyleNeeded]);
        if(styleNeeded)
            styleNeeded(ctl, (int)notif->position);
        break;
    }

    case SCN_CHARADDED: {
        fpCtli charAdded = (fpCtli)REALGetEventInstance(ctl, &xsiControl.events[scn_CharAdded]);
        if(charAdded)
            charAdded(ctl, notif->ch);
        break;
    }

    case SCN_SAVEPOINTREACHED: {
        fpCtl savePointReached = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_SavePointReached]);
        if(savePointReached)
            savePointReached(ctl);
        break;
    }

    case SCN_SAVEPOINTLEFT: {
        fpCtl savePointLeft = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_SavePointLeft]);
        if(savePointLeft)
            savePointLeft(ctl);
        break;
    }

    case SCN_MODIFYATTEMPTRO: {
        fpCtl modifyAtTempTro = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_ModifyAtTempTro]);
        if(modifyAtTempTro)
            modifyAtTempTro(ctl);
        break;
    }

    case SCN_KEY: {
        fpCtli scnKey = (fpCtli)REALGetEventInstance(ctl, &xsiControl.events[scn_ScnKey]);
        if(scnKey)
            scnKey(ctl, notif->ch);
        break;
    }

    case SCN_DOUBLECLICK: {
        fpCtlii doubleClick = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_DoubleClick]);
        if(doubleClick)
            doubleClick(ctl, notif->position, notif->modifiers);
        break;
    }

    case SCN_UPDATEUI: {
        fpCtli updateUI = (fpCtli)REALGetEventInstance(ctl, &xsiControl.events[scn_UpdateUI]);
        if(updateUI)
            updateUI(ctl, notif->updated);
        break;
    }

    case SCN_MODIFIED: {
        fpModified modified = (fpModified)REALGetEventInstance(ctl, &xsiControl.events[scn_Modified]);
        if(modified) {
            REALstring text = REALBuildStringWithEncoding(notif->text, notif->length, kREALTextEncodingUTF8);
            REALLockString(text);
            modified(ctl, notif->position, notif->modificationType, text, notif->length, notif->linesAdded, notif->line,
                     notif->foldLevelNow, notif->foldLevelPrev, notif->token, notif->annotationLinesAdded);
        }
        break;
    }

    case SCN_MACRORECORD: {
        fpCtliii macroRecord = (fpCtliii)REALGetEventInstance(ctl, &xsiControl.events[scn_MacroRecord]);
        if(macroRecord)
            macroRecord(ctl, notif->message, notif->wParam, notif->lParam);
        break;
    }

    case SCN_MARGINCLICK: {
        fpCtlii marginClick = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_MarginClick]);
        if(marginClick)
            marginClick(ctl, notif->position, notif->margin);
        break;
    }

    case SCN_NEEDSHOWN: {
        fpCtli needShown = (fpCtli)REALGetEventInstance(ctl, &xsiControl.events[scn_NeedShown]);
        if(needShown)
            needShown(ctl, notif->position);
        break;
    }
    case SCN_PAINTED: {
        fpCtl painted = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_painted]);
        if(painted)
            painted(ctl);
        break;
    }

    case SCN_USERLISTSELECTION: {
        fpUserListSelection userListSelection =
            (fpUserListSelection)REALGetEventInstance(ctl, &xsiControl.events[scn_UserListSelection]);
        if(userListSelection) {
            int len = notif->length;
            if(len <= 0)
                len = strlen(notif->text);
            REALstring text = REALBuildStringWithEncoding(notif->text, len, kREALTextEncodingUTF8);
            REALLockString(text);
            userListSelection(ctl, notif->position, notif->ch, text, notif->listType, notif->listCompletionMethod);
        }
        break;
    }

    case SCN_URIDROPPED: {
        fpUriDropped uriDropped = (fpUriDropped)REALGetEventInstance(ctl, &xsiControl.events[scn_UriDropped]);
        if(uriDropped) {
            int len = notif->length;
            if(len <= 0)
                len = strlen(notif->text);
            REALstring text = REALBuildStringWithEncoding(notif->text, len, kREALTextEncodingUTF8);
            REALLockString(text);
            uriDropped(ctl, text);
        }
        break;
    }

    case SCN_DWELLSTART: {
        fpCtliii dwellStart = (fpCtliii)REALGetEventInstance(ctl, &xsiControl.events[scn_DwellStart]);
        if(dwellStart)
            dwellStart(ctl, notif->position, notif->x, notif->y);
        break;
    }

    case SCN_DWELLEND: {
        fpCtliii dwellEnd = (fpCtliii)REALGetEventInstance(ctl, &xsiControl.events[scn_DwellEnd]);
        if(dwellEnd)
            dwellEnd(ctl, notif->position, notif->x, notif->y);
        break;
    }

    case SCN_ZOOM: {
        fpCtl zoom = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_Zoom]);
        if(zoom)
            zoom(ctl);
        break;
    }

    case SCN_HOTSPOTCLICK: {
        fpCtlii hotspotClick = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_HotspotClick]);
        if(hotspotClick)
            hotspotClick(ctl, notif->position, notif->modifiers);
        break;
    }

    case SCN_HOTSPOTDOUBLECLICK: {
        fpCtlii hotspotDoubleClick = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_HotspotDoubleClick]);
        if(hotspotDoubleClick)
            hotspotDoubleClick(ctl, notif->position, notif->modifiers);
        break;
    }

    case SCN_CALLTIPCLICK: {
        fpCtli callTipClick = (fpCtli)REALGetEventInstance(ctl, &xsiControl.events[scn_CallTipClick]);
        if(callTipClick)
            callTipClick(ctl, notif->position);
        break;
    }

    case SCN_AUTOCSELECTION: {
        fpCtliii autocSelection = (fpCtliii)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocSelection]);
        if(autocSelection)
            autocSelection(ctl, notif->position, notif->ch, notif->listCompletionMethod);
        break;
    }

    case SCN_INDICATORCLICK: {
        fpCtlii indicatorClick = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_IndicatorClick]);
        if(indicatorClick)
            indicatorClick(ctl, notif->position, notif->modifiers);
        break;
    }

    case SCN_INDICATORRELEASE: {
        fpCtlii indicatorRelease = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_IndicatorRelease]);
        if(indicatorRelease)
            indicatorRelease(ctl, notif->position, notif->modifiers);
        break;
    }

    case SCN_AUTOCCANCELLED: {
        fpCtl autocCancelled = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocCancelled]);
        if(autocCancelled)
            autocCancelled(ctl);
        break;
    }

    case SCN_AUTOCCHARDELETED: {
        fpCtl autocCharDeleted = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocCharDeleted]);
        if(autocCharDeleted)
            autocCharDeleted(ctl);
        break;
    }

    case SCN_HOTSPOTRELEASECLICK: {
        fpCtlii hotspotReleaseClick = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_HotspotReleaseClick]);
        if(hotspotReleaseClick)
            hotspotReleaseClick(ctl, notif->position, notif->modifiers);
        break;
    }

    case SCN_FOCUSIN: {
        fpCtl focusIn = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_FocusIn]);
        if(focusIn)
            focusIn(ctl);
        break;
    }

    case SCN_FOCUSOUT: {
        fpCtl focusOut = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_FocusOut]);
        if(focusOut)
            focusOut(ctl);
        break;
    }

    case SCN_AUTOCCOMPLETED: {
        fpCtlii autocCompleted = (fpCtlii)REALGetEventInstance(ctl, &xsiControl.events[scn_AutocCompleted]);
        if(autocCompleted)
            autocCompleted(ctl, notif->ch, notif->listCompletionMethod);
        break;
    }

    case SCN_MARGINRIGHTCLICK: {
        fpCtl marginRightClick = (fpCtl)REALGetEventInstance(ctl, &xsiControl.events[scn_MarginRightClick]);
        if(marginRightClick)
            marginRightClick(ctl);
        break;
    }

    default:
        return;
    }
}
