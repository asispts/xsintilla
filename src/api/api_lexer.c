#include "api_lexer.h"

void api_setLexer(REALcontrolInstance ctl, int lexer)
{
    xsi_ssm(xsciObj(ctl), SCI_SETLEXER, (uptr_t)lexer, 0);
}

int api_getLexer(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETLEXER, 0, 0);
}

void api_setLexerLanguage(REALcontrolInstance ctl, REALstring language)
{
    char* lang = REALGetStringContents(language, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETLEXERLANGUAGE, 0, (sptr_t)lang);
}

REALstring api_getLexerLanguage(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_GETLEXERLANGUAGE, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_GETLEXERLANGUAGE, (uptr_t)len, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void api_colourise(REALcontrolInstance ctl, int posStart, int posEnd)
{
    xsi_ssm(xsciObj(ctl), SCI_COLOURISE, (uptr_t)posStart, (sptr_t)posEnd);
}

int api_changeLexerState(REALcontrolInstance ctl, int posStart, int posEnd)
{
    return xsi_ssm(xsciObj(ctl), SCI_CHANGELEXERSTATE, (uptr_t)posStart, (sptr_t)posEnd);
}

REALstring api_describeKeywordSets(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_DESCRIBEKEYWORDSETS, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_DESCRIBEKEYWORDSETS, 0, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void api_setKeywords(REALcontrolInstance ctl, int keywordSet, REALstring keywords)
{
    char* keys = REALGetStringContents(keywords, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETKEYWORDS, (uptr_t)keywordSet, (sptr_t)keys);
}

void api_setProperty(REALcontrolInstance ctl, REALstring key, REALstring value)
{
    char* ckey = REALGetStringContents(key, NULL);
    char* cvalue = REALGetStringContents(value, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETPROPERTY, (sptr_t)ckey, (sptr_t)cvalue);
}

REALstring api_getProperty(REALcontrolInstance ctl, REALstring key)
{
    char* ckey = REALGetStringContents(key, NULL);

    int len = xsi_ssm(xsciObj(ctl), SCI_GETPROPERTY, (sptr_t)ckey, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_GETPROPERTY, (sptr_t)ckey, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void api_loadLexerLibrary(REALcontrolInstance ctl, REALstring path)
{
    char* cpath = REALGetStringContents(path, NULL);
    xsi_ssm(xsciObj(ctl), SCI_LOADLEXERLIBRARY, 0, (sptr_t)cpath);
}

REALstring api_propertyNames(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_PROPERTYNAMES, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_PROPERTYNAMES, 0, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

int api_propertyType(REALcontrolInstance ctl, REALstring name)
{
    char* cname = REALGetStringContents(name, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_PROPERTYTYPE, 0, (sptr_t)cname);
}

REALstring api_describeProperty(REALcontrolInstance ctl, REALstring name)
{
    char* cname = REALGetStringContents(name, NULL);

    int len = xsi_ssm(xsciObj(ctl), SCI_DESCRIBEPROPERTY, (sptr_t)cname, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_DESCRIBEPROPERTY, (sptr_t)cname, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

int api_getPropertyExpanded(REALcontrolInstance ctl, REALstring key, REALstring value)
{
    char* ckey = REALGetStringContents(key, NULL);
    char* cvalue = REALGetStringContents(value, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_GETPROPERTYEXPANDED, (sptr_t)ckey, (sptr_t)cvalue);
}

int api_getPropertyInt(REALcontrolInstance ctl, REALstring key, int defaultValue)
{
    char* ckey = REALGetStringContents(key, NULL);
    return xsi_ssm(xsciObj(ctl), SCI_GETPROPERTYINT, (sptr_t)ckey, (uptr_t)defaultValue);
}

REALstring api_getSubstyleBases(REALcontrolInstance ctl)
{
    int len = xsi_ssm(xsciObj(ctl), SCI_GETSUBSTYLEBASES, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(ctl), SCI_DESCRIBEPROPERTY, 0, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

int api_distanceToSecondaryStyles(REALcontrolInstance ctl)
{
    return xsi_ssm(xsciObj(ctl), SCI_DISTANCETOSECONDARYSTYLES, 0, 0);
}

int api_allocateSubstyles(REALcontrolInstance ctl, int styleBase, int numberStyles)
{
    return xsi_ssm(xsciObj(ctl), SCI_ALLOCATESUBSTYLES, (uptr_t)styleBase, (sptr_t)numberStyles);
}

void api_freeSubstyles(REALcontrolInstance ctl)
{
    xsi_ssm(xsciObj(ctl), SCI_FREESUBSTYLES, 0, 0);
}

int api_getSubstylesStart(REALcontrolInstance ctl, int styleBase)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSUBSTYLESSTART, (uptr_t)styleBase, 0);
}

int api_getSubstylesLength(REALcontrolInstance ctl, int styleBase)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSUBSTYLESLENGTH, (uptr_t)styleBase, 0);
}

int api_getStyleFromSubstyle(REALcontrolInstance ctl, int subStyle)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETSTYLEFROMSUBSTYLE, (uptr_t)subStyle, 0);
}

int api_getPrimaryStyleFromStyle(REALcontrolInstance ctl, int style)
{
    return xsi_ssm(xsciObj(ctl), SCI_GETPRIMARYSTYLEFROMSTYLE, (uptr_t)style, 0);
}

void api_setIdentifiers(REALcontrolInstance ctl, int style, REALstring identifiers)
{
    char* id = REALGetStringContents(identifiers, NULL);
    xsi_ssm(xsciObj(ctl), SCI_SETIDENTIFIERS, (uptr_t)style, (sptr_t)id);
}

int api_privateLexerCall(REALcontrolInstance ctl, int operation, int pointer)
{
    return xsi_ssm(xsciObj(ctl), SCI_PRIVATELEXERCALL, (uptr_t)operation, (sptr_t)pointer);
}
