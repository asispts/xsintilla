#include "modplugin.h"
#include "modsclex.h"
#include "modenums.h"
#include "modscstyle.h"

void PluginEntry()
{
    registerSclex();
    registerEnums();
    registerScstyle();
    registerPlugin();
}
