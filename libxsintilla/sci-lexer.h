//======================================
//Lexer
//======================================

#ifndef SCI_LEXER_H
#define SCI_LEXER_H

#include "xsintilla.h"

//properties
int xsip_getLexer(REALcontrolInstance ctl, int unused);
void xsip_setLexer(REALcontrolInstance ctl, int unused, int lexer);
REALstring xsip_getLexerLanguage(REALcontrolInstance ctl, int unused);
void xsip_setLexerLanguage(REALcontrolInstance ctl, int unused, REALstring language);

//methods
void xsim_colourise(REALcontrolInstance ctl, int posStart, int posEnd);
int xsim_changeLexerState(REALcontrolInstance ctl, int posStart, int posEnd);
void xsim_setKeywords(REALcontrolInstance ctl, int keywordSet, REALstring keywords);
int xsim_describeKeywordSets(REALcontrolInstance ctl, REALstring description);

#endif //SCI_LEXER_H
