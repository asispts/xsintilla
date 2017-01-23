#ifndef XSINTILLA_EVENT_H
#define XSINTILLA_EVENT_H

#include "xsintilla.h"

void xsi_registerEventFunction(REALcontrolInstance ctl);
void sci_eventHandler(ScintillaObject *sci, gint controlID,
                      SCNotification *scinotify, gpointer userData);

// function pointer for event definition
typedef void (*fpAutocCompleted)(REALcontrolInstance, int, int);
typedef void (*fpAutocSelection)(REALcontrolInstance, Sci_Position, int, int);
typedef void (*fpCallTipClick)(REALcontrolInstance, Sci_Position);
typedef void (*fpCharAdded)(REALcontrolInstance, int);
typedef void (*fpDoubleClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpDwellEnd)(REALcontrolInstance, Sci_Position, int,int);
typedef void (*fpDwellStart)(REALcontrolInstance, Sci_Position, int,int);
typedef void (*fpHotspotClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpHotspotDoubleClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpHotspotReleaseClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpIndicatorClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpIndicatorRelease)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpScnKey)(REALcontrolInstance, int);
typedef void (*fpMacroRecord)(REALcontrolInstance, int, int, int);
typedef void (*fpMarginClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpModified)(REALcontrolInstance, Sci_Position, int, REALstring, Sci_Position, Sci_Position, Sci_Position, int, int, int, Sci_Position);
typedef void (*fpNeedShown)(REALcontrolInstance, Sci_Position);
typedef void (*fpStyleNeeded)(REALcontrolInstance, Sci_Position);
typedef void (*fpUpdateUI)(REALcontrolInstance, int);
typedef void (*fpUriDropped)(REALcontrolInstance, REALstring);
typedef void (*fpUserListSelection)(REALcontrolInstance, Sci_Position, int, REALstring, int, int);


// Events definition
enum xsi_events {
    xse_AutocCompleted,
    xse_AutocSelection,
    xse_CallTipClick,
    xse_CharAdded,
    xse_DoubleClick,
    xse_DwellEnd,
    xse_DwellStart,
    xse_HotspotClick,
    xse_HotspotDoubleClick,
    xse_HotspotReleaseClick,
    xse_IndicatorClick,
    xse_IndicatorRelease,
    xse_ScnKey,
    xse_MacroRecord,
    xse_MarginClick,
    xse_Modified,
    xse_NeedShown,
    xse_StyleNeeded,
    xse_UpdateUI,
    xse_UriDropped,
    xse_UserListSelection,
};

#endif //XSINTILLA_EVENT_H
