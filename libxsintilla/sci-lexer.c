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

void xsim_setProperty(REALcontrolInstance ctl, REALstring key, REALstring value)
{
    char *ckey = REALGetStringContents(key, NULL);
    char *cvalue = REALGetStringContents(value, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETPROPERTY, (sptr_t)ckey, (sptr_t)cvalue);
}

REALstring xsim_getProperty(REALcontrolInstance ctl, REALstring key)
{
    char *ckey = REALGetStringContents(key, NULL);
    char *txtBuffer = malloc(5*1024);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_GETPROPERTY, (sptr_t)ckey, (sptr_t)txtBuffer);
    REALstring value = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(value);
    free(txtBuffer);
    return value;
}

void xsim_loadLexerLibrary(REALcontrolInstance ctl, REALstring path)
{
    char *cpath = REALGetStringContents(path, NULL);
    xsi_ssm(xsciObj(ctl), SCI_LOADLEXERLIBRARY, 0, (sptr_t)cpath);
}

REALstring xsim_propertyNames(REALcontrolInstance ctl)
{
    char *txtBuffer = malloc(5*1024);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_PROPERTYNAMES, 0, (sptr_t)txtBuffer);
    REALstring name = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(name);
    free(txtBuffer);
    return name;
}

int xsim_propertyType(REALcontrolInstance ctl, REALstring name)
{
    char *cname = REALGetStringContents(name, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_PROPERTYTYPE, 0, (sptr_t)cname);
}

REALstring xsim_describeProperty(REALcontrolInstance ctl, REALstring name)
{
    char *txtBuffer = malloc(5*1024);
    char *cname = REALGetStringContents(name, NULL);
    int txtLength = xsi_ssm(xsciObj(ctl), SCI_DESCRIBEPROPERTY, (sptr_t)cname, (sptr_t)txtBuffer);
    REALstring desc = REALBuildStringWithEncoding(txtBuffer, txtLength, kREALTextEncodingUTF8);
    REALLockString(desc);
    free(txtBuffer);
    return desc;
}

int xsim_getPropertyExpanded(REALcontrolInstance ctl, REALstring key, REALstring value)
{
    char *ckey = REALGetStringContents(key, NULL);
    char *cvalue = REALGetStringContents(value, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_GETPROPERTYEXPANDED, (sptr_t)ckey, (sptr_t)cvalue);
}

int xsim_getPropertyInt(REALcontrolInstance ctl, REALstring key, int defaultValue)
{
    char *ckey = REALGetStringContents(key, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_GETPROPERTYINT, (sptr_t)ckey, defaultValue);
}
