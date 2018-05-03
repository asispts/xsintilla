#ifndef CLASSES_LEXER_H
#define CLASSES_LEXER_H

#include "xsintilla.h"

REALclassDefinition xsiLexerDef;

typedef struct {
    REALcontrolInstance ctl;
} xsiLexerData;

void lexer_setcontrol(REALobject instance, REALcontrolInstance ctl);

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
int lexer_getLexer(REALobject instance);
void lexer_setLexer(REALobject instance, long rbUnused, int lexer);
REALstring lexer_getLexerLanguage(REALobject instance);
void lexer_setLexerLanguage(REALobject instance, long rbUnused, REALstring language);

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
void lexer_colourise(REALobject instance, int posStart, int posEnd);
int lexer_changeLexerState(REALobject instance, int posStart, int posEnd);
void lexer_setKeywords(REALobject instance, int keywordSet, REALstring keywords);
REALstring lexer_describeKeywordSets(REALobject instance);
void lexer_setProperty(REALobject instance, REALstring key, REALstring value);
REALstring lexer_getProperty(REALobject instance, REALstring key);
void lexer_loadLexerLibrary(REALobject instance, REALstring path);
REALstring lexer_propertyNames(REALobject instance);
int lexer_propertyType(REALobject instance, REALstring name);
REALstring lexer_describeProperty(REALobject instance, REALstring name);
int lexer_getPropertyExpanded(REALobject instance, REALstring key, REALstring value);
int lexer_getPropertyInt(REALobject instance, REALstring key, int defaultValue);
REALstring lexer_getSubstyleBases(REALobject instance);
int lexer_distanceToSecondaryStyles(REALobject instance);
int lexer_allocateSubstyles(REALobject instance, int styleBase, int numberStyles);
void lexer_freeSubstyles(REALobject instance);
int lexer_getSubstylesStart(REALobject instance, int styleBase);
int lexer_getSubstylesLength(REALobject instance, int styleBase);
int lexer_getStyleFromSubstyle(REALobject instance, int subStyle);
int lexer_getPrimaryStyleFromStyle(REALobject instance, int style);
void lexer_setIdentifiers(REALobject instance, int style, REALstring identifiers);
int lexer_privateLexerCall(REALobject instance, int operation, int pointer);

#endif // CLASSES_LEXER_H
