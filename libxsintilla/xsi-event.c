#include "xsi-event.h"

static REALcontrolInstance me;
static fpVoidEvent RaiseStyleNeeded = NULL;
static fpVoidEventInt RaiseCharAdded = NULL;

void xsi_registerEventFunction(REALcontrolInstance ctl)
{
    me = ctl;
    RaiseStyleNeeded = (fpVoidEvent) REALGetEventInstance(ctl, &xsiControl.events[xse_StyleNeeded]);
    RaiseCharAdded = (fpVoidEventInt) REALGetEventInstance(ctl, &xsiControl.events[xse_CharAdded]);

}

void sci_eventHandler(ScintillaObject *sci, gint controlID,
                      SCNotification *scinotify, gpointer userData)
{
    (void) *sci;
    (void) controlID;
    (void) userData;

    switch (scinotify->nmhdr.code) {
    case SCN_STYLENEEDED:
        if (RaiseStyleNeeded) RaiseStyleNeeded(me);
        break;
        // UI specific events
    case SCN_UPDATEUI:
    case SCN_PAINTED:
        break;
    case SCN_CHARADDED:
        if(RaiseCharAdded) RaiseCharAdded(me, scinotify->ch);
        break;
        // Others
    case SCN_SAVEPOINTREACHED:
    case SCN_SAVEPOINTLEFT:
    case SCN_MODIFYATTEMPTRO:
    case SCN_KEY:
    case SCN_DOUBLECLICK:
    case SCN_MODIFIED:
    case SCN_MACRORECORD:
    case SCN_MARGINCLICK:
    case SCN_NEEDSHOWN:
    case SCN_USERLISTSELECTION:
    case SCN_URIDROPPED:
    case SCN_DWELLSTART:
    case SCN_DWELLEND:
    case SCN_ZOOM:
    case SCN_HOTSPOTCLICK:
    case SCN_HOTSPOTDOUBLECLICK:
    case SCN_CALLTIPCLICK:
    case SCN_AUTOCSELECTION:
    case SCN_INDICATORCLICK:
    case SCN_INDICATORRELEASE:
    case SCN_AUTOCCANCELLED:
    case SCN_AUTOCCHARDELETED:
    case SCN_HOTSPOTRELEASECLICK:
    case SCN_FOCUSIN:
    case SCN_FOCUSOUT:
    case SCN_AUTOCCOMPLETED:
        //break;
    default:
        fprintf(stderr, "sci_eventHandler: code = %i\n", scinotify->nmhdr.code);
        break;
    }

}
