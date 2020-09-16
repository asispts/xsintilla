#include "definition.h"

// constants
#include "lexerconst.h"
#include "lexhtmlconst.h"

void PluginEntry()
{
    // constants
    registerXsiLexer();
    registerXsiLexHTML();

    // control plugin
    registerPlugin();
}
