#include "definition.h"

// classes
#include "lexer-definition.h"
#include "margin-definition.h"

void PluginEntry()
{
    registerClassMargin();
    registerClassLexer();
    registerPlugin();
}
