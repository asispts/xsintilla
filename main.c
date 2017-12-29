#include "definition.h"

// classes
#include "lexer-definition.h"
#include "margin-definition.h"
#include "style-definition.h"

void PluginEntry()
{
    // classes
    registerClassMargin();
    registerClassLexer();
    registerClassStyledef();

    // control plugin
    registerPlugin();
}
