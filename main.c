#include "definition.h"

// classes
#include "lexer-definition.h"
#include "margin-definition.h"
#include "style-definition.h"

// constants
#include "style-html-def.h"

void PluginEntry()
{
    // classes
    registerClassMargin();
    registerClassLexer();
    registerClassStyledef();

    // constants
    registerStyleHTML();

    // control plugin
    registerPlugin();
}
