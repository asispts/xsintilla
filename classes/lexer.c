#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

void lexer_setcontrol(REALobject instance, REALcontrolInstance ctl)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    self->ctl = ctl;
}

//+++++++++++++++++++++++++++++++++
// Properties
//+++++++++++++++++++++++++++++++++
int lexer_getLexer(REALobject instance)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETLEXER, 0, 0);
}

void lexer_setLexer(REALobject instance, long rbUnused, int lexer)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    xsi_ssm(xsciObj(self->ctl), SCI_SETLEXER, (uptr_t)lexer, 0);
}

REALstring lexer_getLexerLanguage(REALobject instance)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);

    int len = xsi_ssm(xsciObj(self->ctl), SCI_GETLEXERLANGUAGE, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(self->ctl), SCI_GETLEXERLANGUAGE, (uptr_t)len, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void lexer_setLexerLanguage(REALobject instance, long rbUnused, REALstring language)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* lang = REALGetStringContents(language, NULL);
    printf("lexer_setLexerLanguage::lang = %s\n", lang);
    xsi_ssm(xsciObj(self->ctl), SCI_SETLEXERLANGUAGE, 0, (sptr_t)lang);
}

//+++++++++++++++++++++++++++++++++
// Methods
//+++++++++++++++++++++++++++++++++
void lexer_colourise(REALobject instance, int posStart, int posEnd)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    xsi_ssm(xsciObj(self->ctl), SCI_COLOURISE, (uptr_t)posStart, (sptr_t)posEnd);
}

int lexer_changeLexerState(REALobject instance, int posStart, int posEnd)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    return xsi_ssm(xsciObj(self->ctl), SCI_CHANGELEXERSTATE, (uptr_t)posStart, (sptr_t)posEnd);
}

void lexer_setKeywords(REALobject instance, int keywordSet, REALstring keywords)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* keys = REALGetStringContents(keywords, NULL);
    xsi_ssm(xsciObj(self->ctl), SCI_SETKEYWORDS, (uptr_t)keywordSet, (sptr_t)keys);
}

int lexer_describeKeywordSets(REALobject instance, REALstring description)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* desc = REALGetStringContents(description, NULL);
    return xsi_ssm(xsciObj(self->ctl), SCI_DESCRIBEKEYWORDSETS, 0, (sptr_t)desc);
}

void lexer_setProperty(REALobject instance, REALstring key, REALstring value)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* ckey = REALGetStringContents(key, NULL);
    char* cvalue = REALGetStringContents(value, NULL);
    xsi_ssm(xsciObj(self->ctl), SCI_SETPROPERTY, (sptr_t)ckey, (sptr_t)cvalue);
}

REALstring lexer_getProperty(REALobject instance, REALstring key)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* ckey = REALGetStringContents(key, NULL);

    int len = xsi_ssm(xsciObj(self->ctl), SCI_GETPROPERTY, (sptr_t)ckey, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(self->ctl), SCI_GETPROPERTY, (sptr_t)ckey, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

void lexer_loadLexerLibrary(REALobject instance, REALstring path)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* cpath = REALGetStringContents(path, NULL);
    xsi_ssm(xsciObj(self->ctl), SCI_LOADLEXERLIBRARY, 0, (sptr_t)cpath);
}

REALstring lexer_propertyNames(REALobject instance)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);

    int len = xsi_ssm(xsciObj(self->ctl), SCI_PROPERTYNAMES, 0, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(self->ctl), SCI_PROPERTYNAMES, 0, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

int lexer_propertyType(REALobject instance, REALstring name)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* cname = REALGetStringContents(name, NULL);
    return xsi_ssm(xsciObj(self->ctl), SCI_PROPERTYTYPE, 0, (sptr_t)cname);
}

REALstring lexer_describeProperty(REALobject instance, REALstring name)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* cname = REALGetStringContents(name, NULL);

    int len = xsi_ssm(xsciObj(self->ctl), SCI_DESCRIBEPROPERTY, (sptr_t)cname, 0);
    if(len <= 0)
        return NULL;

    char* buffer = malloc(len + 1);
    len = xsi_ssm(xsciObj(self->ctl), SCI_DESCRIBEPROPERTY, (sptr_t)cname, (sptr_t)buffer);

    return xsi_toREALstring(buffer, len, false);
}

int lexer_getPropertyExpanded(REALobject instance, REALstring key, REALstring value)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* ckey = REALGetStringContents(key, NULL);
    char* cvalue = REALGetStringContents(value, NULL);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETPROPERTYEXPANDED, (sptr_t)ckey, (sptr_t)cvalue);
}

int lexer_getPropertyInt(REALobject instance, REALstring key, int defaultValue)
{
    xsiLexerData* self = REALGetClassData(instance, &xsiLexerDef);
    char* ckey = REALGetStringContents(key, NULL);
    return xsi_ssm(xsciObj(self->ctl), SCI_GETPROPERTYINT, (sptr_t)ckey, (uptr_t)defaultValue);
}
