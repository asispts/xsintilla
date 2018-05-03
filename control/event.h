#ifndef CONTROL_EVENT_H
#define CONTROL_EVENT_H

#include "xsintilla.h"

// void xsi_registerEventFunction(REALcontrolInstance ctl);
void sci_eventHandler(ScintillaObject* sci, gint controlID, SCNotification* scinotify, REALcontrolInstance ctl);

// Events definition
enum xsi_events {
    ctl_MouseDown,
    scn_StyleNeeded,         // SCN_STYLENEEDED 2000
    scn_CharAdded,           // SCN_CHARADDED 2001
    scn_SavePointReached,    // SCN_SAVEPOINTREACHED 2002
    scn_SavePointLeft,       // SCN_SAVEPOINTLEFT 2003
    scn_ModifyAtTempTro,     // SCN_MODIFYATTEMPTRO 2004
    scn_ScnKey,              // SCN_KEY 2005
    scn_DoubleClick,         // SCN_DOUBLECLICK 2006
    scn_UpdateUI,            // SCN_UPDATEUI 2007
    scn_Modified,            // SCN_MODIFIED 2008
    scn_MacroRecord,         // SCN_MACRORECORD 2009
    scn_MarginClick,         // SCN_MARGINCLICK 2010
    scn_NeedShown,           // SCN_NEEDSHOWN 2011
    scn_painted,             // SCN_PAINTED 2013
    scn_UserListSelection,   // SCN_USERLISTSELECTION 2014
    scn_UriDropped,          // SCN_URIDROPPED 2015
    scn_DwellStart,          // SCN_DWELLSTART 2016
    scn_DwellEnd,            // SCN_DWELLEND 2017
    scn_Zoom,                // SCN_ZOOM 2018
    scn_HotspotClick,        // SCN_HOTSPOTCLICK 2019
    scn_HotspotDoubleClick,  // SCN_HOTSPOTDOUBLECLICK 2020
    scn_CallTipClick,        // SCN_CALLTIPCLICK 2021
    scn_AutocSelection,      // SCN_AUTOCSELECTION 2022
    scn_IndicatorClick,      // SCN_INDICATORCLICK 2023
    scn_IndicatorRelease,    // SCN_INDICATORRELEASE 2024
    scn_AutocCancelled,      // SCN_AUTOCCANCELLED 2025
    scn_AutocCharDeleted,    // SCN_AUTOCCHARDELETED 2026
    scn_HotspotReleaseClick, // SCN_HOTSPOTRELEASECLICK 2027
    scn_FocusIn,             // SCN_FOCUSIN 2028
    scn_FocusOut,            // SCN_FOCUSOUT 2029
    scn_AutocCompleted,      // SCN_AUTOCCOMPLETED 2030
    scn_MarginRightClick,    // SCN_MARGINRIGHTCLICK 2031
};

#endif // CONTROL_EVENT_H
