#include "modplugin.h"
#include "modsclex.h"
#include "modscstyle.h"
#include "modscmargintype.h"
#include "modscmarker.h"

void PluginEntry()
{
    registerSclex();
    registerScstyle();
    registerScmarginType();
    registerScmarker();
    registerPlugin();
}
