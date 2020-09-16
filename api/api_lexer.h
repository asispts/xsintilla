#ifndef API_LEXER_H
#define API_LEXER_H

#include "xsintilla.h"

void api_setLexer(REALcontrolInstance ctl, int lexer);
int api_getLexer(REALcontrolInstance ctl);
void api_setLexerLanguage(REALcontrolInstance ctl, REALstring language);
REALstring api_getLexerLanguage(REALcontrolInstance ctl);
void api_colourise(REALcontrolInstance ctl, int posStart, int posEnd);
int api_changeLexerState(REALcontrolInstance ctl, int posStart, int posEnd);
REALstring api_describeKeywordSets(REALcontrolInstance ctl);
void api_setKeywords(REALcontrolInstance ctl, int keywordSet, REALstring keywords);
void api_setProperty(REALcontrolInstance ctl, REALstring key, REALstring value);
REALstring api_getProperty(REALcontrolInstance ctl, REALstring key);
void api_loadLexerLibrary(REALcontrolInstance ctl, REALstring path);
REALstring api_propertyNames(REALcontrolInstance ctl);
int api_propertyType(REALcontrolInstance ctl, REALstring name);
REALstring api_describeProperty(REALcontrolInstance ctl, REALstring name);
int api_getPropertyExpanded(REALcontrolInstance ctl, REALstring key, REALstring value);
int api_getPropertyInt(REALcontrolInstance ctl, REALstring key, int defaultValue);
REALstring api_getSubstyleBases(REALcontrolInstance ctl);
int api_distanceToSecondaryStyles(REALcontrolInstance ctl);
int api_allocateSubstyles(REALcontrolInstance ctl, int styleBase, int numberStyles);
void api_freeSubstyles(REALcontrolInstance ctl);
int api_getSubstylesStart(REALcontrolInstance ctl, int styleBase);
int api_getSubstylesLength(REALcontrolInstance ctl, int styleBase);
int api_getStyleFromSubstyle(REALcontrolInstance ctl, int subStyle);
int api_getPrimaryStyleFromStyle(REALcontrolInstance ctl, int style);
void api_setIdentifiers(REALcontrolInstance ctl, int style, REALstring identifiers);
int api_privateLexerCall(REALcontrolInstance ctl, int operation, int pointer);

#endif // API_LEXER_H
