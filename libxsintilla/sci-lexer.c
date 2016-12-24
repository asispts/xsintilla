#include <stdlib.h>
#include "sci-lexer.h"

/*=========================
 * properties
 * ========================*/
int xsip_getLexer(REALcontrolInstance ctl, int unused)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLEXER, 0, 0);
}

void xsip_setLexer(REALcontrolInstance ctl, int unused, int lexer)
{
    xsi_ssm(xsciObj(ctl), SCI_SETLEXER, lexer, 0);
}

REALstring xsip_getLexerLanguage(REALcontrolInstance ctl, int unused)
{
    char *txtBuffer = malloc(1024);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_GETLEXERLANGUAGE, 1024, (sptr_t)txtBuffer);
    REALstring lang = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(lang);
    free(txtBuffer);
    return lang;
}

void xsip_setLexerLanguage(REALcontrolInstance ctl, int unused, REALstring language)
{
    char *lang = REALGetStringContents(language, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETLEXERLANGUAGE, 0, (sptr_t)lang);
}


/*=========================
 * methods
 * ========================*/
void xsim_colourise(REALcontrolInstance ctl, int posStart, int posEnd)
{
    xsi_ssm(xsciObj(ctl), SCI_COLOURISE, posStart, posEnd);
}

int xsim_changeLexerState(REALcontrolInstance ctl, int posStart, int posEnd)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHANGELEXERSTATE, posStart, posEnd);
}

void xsim_setKeywords(REALcontrolInstance ctl, int keywordSet, REALstring keywords)
{
    char *key = REALGetStringContents(keywords, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETKEYWORDS, keywordSet, (sptr_t)key);
}

int xsim_describeKeywordSets(REALcontrolInstance ctl, REALstring description)
{
    char *desc = REALGetStringContents(description, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_DESCRIBEKEYWORDSETS, 0, (sptr_t)desc);
}
