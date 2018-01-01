#ifndef CONTROL_EVENT_H
#define CONTROL_EVENT_H

#include "xsintilla.h"

void xsi_registerEventFunction(REALcontrolInstance ctl);
void sci_eventHandler(ScintillaObject* sci, gint controlID, SCNotification* scinotify, gpointer userData);

//+++++++++++++++++++++++++++++++++
// Control Events
//+++++++++++++++++++++++++++++++++
// used for
// SCN_SAVEPOINTREACHED, SCN_SAVEPOINTLEFT, SCN_MODIFYATTEMPTRO
// SCN_PAINTED, SCN_ZOOM, SCN_AUTOCCANCELLED, SCN_AUTOCCHARDELETED
// SCN_FOCUSIN, SCN_FOCUSOUT, SCN_MARGINRIGHTCLICK
typedef void (*fpEvent)(REALcontrolInstance);

typedef void (*fpStyleNeeded)(REALcontrolInstance, Sci_Position);
typedef void (*fpCharAdded)(REALcontrolInstance, int);
typedef void (*fpScnKey)(REALcontrolInstance, int);
typedef void (*fpDoubleClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpUpdateUI)(REALcontrolInstance, int);
typedef void (*fpModified)(REALcontrolInstance,
                           Sci_Position,
                           int,
                           REALstring,
                           Sci_Position,
                           Sci_Position,
                           Sci_Position,
                           int,
                           int,
                           int,
                           Sci_Position);
typedef void (*fpMacroRecord)(REALcontrolInstance, int, int, int);
typedef void (*fpMarginClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpNeedShown)(REALcontrolInstance, Sci_Position);
typedef void (*fpUserListSelection)(REALcontrolInstance, Sci_Position, int, REALstring, int, int);
typedef void (*fpUriDropped)(REALcontrolInstance, REALstring);
typedef void (*fpDwellStart)(REALcontrolInstance, Sci_Position, int, int);
typedef void (*fpDwellEnd)(REALcontrolInstance, Sci_Position, int, int);
typedef void (*fpHotspotClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpHotspotDoubleClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpCallTipClick)(REALcontrolInstance, Sci_Position);
typedef void (*fpAutocSelection)(REALcontrolInstance, Sci_Position, int, int);
typedef void (*fpIndicatorClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpIndicatorRelease)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpHotspotReleaseClick)(REALcontrolInstance, Sci_Position, int);
typedef void (*fpAutocCompleted)(REALcontrolInstance, int, int);

// Events definition
enum xsi_events {
    scn_StyleNeeded,          // SCN_STYLENEEDED 2000
    scn_CharAdded,            // SCN_CHARADDED 2001
    scn_SavePointReached,     // SCN_SAVEPOINTREACHED 2002
    scn_SavePointLeft,        // SCN_SAVEPOINTLEFT 2003
    scn_ModifyAtTempTro,      // SCN_MODIFYATTEMPTRO 2004
    scn_ScnKey,               // SCN_KEY 2005
    scn_DoubleClick,          // SCN_DOUBLECLICK 2006
    scn_UpdateUI,             // SCN_UPDATEUI 2007
    scn_Modified,             // SCN_MODIFIED 2008
    scn_MacroRecord,          // SCN_MACRORECORD 2009
    scn_MarginClick,          // SCN_MARGINCLICK 2010
    scn_NeedShown,            // SCN_NEEDSHOWN 2011
    scn_painted,              // SCN_PAINTED 2013
    scn_UserListSelection,    // SCN_USERLISTSELECTION 2014
    scn_UriDropped,           // SCN_URIDROPPED 2015
    scn_DwellStart,           // SCN_DWELLSTART 2016
    scn_DwellEnd,             // SCN_DWELLEND 2017
    scn_Zoom,                 // SCN_ZOOM 2018
    scn_HotspotClick,         // SCN_HOTSPOTCLICK 2019
    scn_HotspotDoubleClick,   // SCN_HOTSPOTDOUBLECLICK 2020
    scn_CallTipClick,         // SCN_CALLTIPCLICK 2021
    scn_AutocSelection,       // SCN_AUTOCSELECTION 2022
    scn_IndicatorClick,       // SCN_INDICATORCLICK 2023
    scn_IndicatorRelease,     // SCN_INDICATORRELEASE 2024
    scn_AutocCancelled,       // SCN_AUTOCCANCELLED 2025
    scn_AutocCharDeleted,     // SCN_AUTOCCHARDELETED 2026
    scn_HotspotReleaseClick,  // SCN_HOTSPOTRELEASECLICK 2027
    scn_FocusIn,              // SCN_FOCUSIN 2028
    scn_FocusOut,             // SCN_FOCUSOUT 2029
    scn_AutocCompleted,       // SCN_AUTOCCOMPLETED 2030
    scn_MarginRightClick,     // SCN_MARGINRIGHTCLICK 2031
};

#endif  // CONTROL_EVENT_H
