#include "style-html-def.h"

//+++++++++++++++++++++++++++++++++
// Constants
//+++++++++++++++++++++++++++++++++
REALconstant xsiHTMLConstDef[] = {
    // HTML, XML, and ASP
    {"H_DEFAULT as Integer = 0"},          //
    {"H_TAG as Integer = 1"},              //
    {"H_TAGUNKNOWN as Integer = 2"},       //
    {"H_ATTRIBUTEUNKNOWN as Integer = 3"}, //
    {"H_NUMBER as Integer = 5"},           //
    {"H_DOUBLESTRING as Integer = 6"},     //
    {"H_SINGLESTRING as Integer = 7"},     //
    {"H_OTHER as Integer = 8"},            //
    {"H_COMMENT as Integer = 9"},          //
    {"H_ENTITY as Integer = 10"},          //
    {"H_TAGEND as Integer = 11"},          //
    {"H_XMLSTART as Integer = 12"},        //
    {"H_XMLEND as Integer = 13"},          //
    {"H_SCRIPT as Integer = 14"},          //
    {"H_ASP as Integer = 15"},             //
    {"H_ASPAT as Integer = 16"},           //
    {"H_CDATA as Integer = 17"},           //
    {"H_QUESTION as Integer = 18"},        //
    {"H_VALUE as Integer = 19"},           //
    {"H_XCCOMMENT as Integer = 20"},       //

    // SGML
    {"SGML_DEFAULT as Integer = 21"},           //
    {"SGML_COMMAND as Integer = 22"},           //
    {"SGML_1ST_PARAM as Integer = 23"},         //
    {"SGML_DOUBLESTRING as Integer = 24"},      //
    {"SGML_SIMPLESTRING as Integer = 25"},      //
    {"SGML_ERROR as Integer = 26"},             //
    {"SGML_SPECIAL as Integer = 27"},           //
    {"SGML_ENTITY as Integer = 28"},            //
    {"SGML_COMMENT as Integer = 29"},           //
    {"SGML_1ST_PARAM_COMMENT as Integer = 30"}, //
    {"SGML_BLOCK_DEFAULT as Integer = 31"},     //

    // Embedded Javascript
    {"JS_START as Integer = 40"},        //
    {"JS_DEFAULT as Integer = 41"},      //
    {"JS_COMMENT as Integer = 42"},      //
    {"JS_COMMENTLINE as Integer = 43"},  //
    {"JS_COMMENTDOC as Integer = 44"},   //
    {"JS_NUMBER as Integer = 45"},       //
    {"JS_WORD as Integer = 46"},         //
    {"JS_KEYWORD as Integer = 47"},      //
    {"JS_DOUBLESTRING as Integer = 48"}, //
    {"JS_SINGLESTRING as Integer = 49"}, //
    {"JS_SYMBOLS as Integer = 50"},      //
    {"JS_STRINGEOL as Integer = 51"},    //
    {"JS_REGEX as Integer = 52"},        //

    // ASP Javascript
    {"JA_START as Integer = 55"},        //
    {"JA_DEFAULT as Integer = 56"},      //
    {"JA_COMMENT as Integer = 57"},      //
    {"JA_COMMENTLINE as Integer = 58"},  //
    {"JA_COMMENTDOC as Integer = 59"},   //
    {"JA_NUMBER as Integer = 60"},       //
    {"JA_WORD as Integer = 61"},         //
    {"JA_KEYWORD as Integer = 62"},      //
    {"JA_DOUBLESTRING as Integer = 63"}, //
    {"JA_SINGLESTRING as Integer = 64"}, //
    {"JA_SYMBOLS as Integer = 65"},      //
    {"JA_STRINGEOL as Integer = 66"},    //
    {"JA_REGEX as Integer = 67"},        //

    // Embedded VBScript
    {"HB_START as Integer = 70"},       //
    {"HB_DEFAULT as Integer = 71"},     //
    {"HB_COMMENTLINE as Integer = 72"}, //
    {"HB_NUMBER as Integer = 73"},      //
    {"HB_WORD as Integer = 74"},        //
    {"HB_STRING as Integer = 75"},      //
    {"HB_IDENTIFIER as Integer = 76"},  //
    {"HB_STRINGEOL as Integer = 77"},   //

    // ASP VBScript
    {"BA_START as Integer = 80"},       //
    {"BA_DEFAULT as Integer = 81"},     //
    {"BA_COMMENTLINE as Integer = 82"}, //
    {"BA_NUMBER as Integer = 83"},      //
    {"BA_WORD as Integer = 84"},        //
    {"BA_STRING as Integer = 85"},      //
    {"BA_IDENTIFIER as Integer = 86"},  //
    {"BA_STRINGEOL as Integer = 87"},   //

    // Embedded Python
    {"PY_START as Integer = 90"},        //
    {"PY_DEFAULT as Integer = 91"},      //
    {"PY_COMMENTLINE as Integer = 92"},  //
    {"PY_NUMBER as Integer = 93"},       //
    {"PY_STRING as Integer = 94"},       //
    {"PY_CHARACTER as Integer = 95"},    //
    {"PY_WORD as Integer = 96"},         //
    {"PY_TRIPLE as Integer = 97"},       //
    {"PY_TRIPLEDOUBLE as Integer = 98"}, //
    {"PY_CLASSNAME as Integer = 99"},    //
    {"PY_DEFNAME as Integer = 100"},     //
    {"PY_OPERATOR as Integer = 101"},    //
    {"PY_IDENTIFIER as Integer = 102"},  //

    // ASP Python
    {"PA_START as Integer = 105"},        //
    {"PA_DEFAULT as Integer = 106"},      //
    {"PA_COMMENTLINE as Integer = 107"},  //
    {"PA_NUMBER as Integer = 108"},       //
    {"PA_STRING as Integer = 109"},       //
    {"PA_CHARACTER as Integer = 110"},    //
    {"PA_WORD as Integer = 111"},         //
    {"PA_TRIPLE as Integer = 112"},       //
    {"PA_TRIPLEDOUBLE as Integer = 113"}, //
    {"PA_CLASSNAME as Integer = 114"},    //
    {"PA_DEFNAME as Integer = 115"},      //
    {"PA_OPERATOR as Integer = 116"},     //
    {"PA_IDENTIFIER as Integer = 117"},   //

    // PHP
    {"PHP_COMPLEX_VARIABLE as Integer = 104"}, //
    {"PHP_DEFAULT as Integer = 118"},          //
    {"PHP_HSTRING as Integer = 119"},          //
    {"PHP_SIMPLESTRING as Integer = 120"},     //
    {"PHP_WORD as Integer = 121"},             //
    {"PHP_NUMBER as Integer = 122"},           //
    {"PHP_VARIABLE as Integer = 123"},         //
    {"PHP_COMMENT as Integer = 124"},          //
    {"PHP_COMMENTLINE as Integer = 125"},      //
    {"PHP_HSTRING_VARIABLE as Integer = 126"}, //
    {"PHP_OPERATOR as Integer = 127"},         //
};

REALclassDefinition xsiStyleHTMLDef = {
    kCurrentREALControlVersion,                     // version
    "xsiHTML",                                      // name
    NULL,                                           // superName
    0,                                              // dataSize
    0,                                              // forSystemUse
    NULL,                                           // constructor
    NULL,                                           // destructor
    NULL,                                           // properties
    0,                                              // propertyCount
    NULL,                                           // methods
    0,                                              // methodCount
    NULL,                                           // events
    0,                                              // eventCount
    NULL,                                           // eventInstances
    0,                                              // eventInstanceCount
    NULL,                                           // interfaces
    NULL,                                           // attributes
    0,                                              // attributeCount
    xsiHTMLConstDef,                                // constants
    sizeof(xsiHTMLConstDef) / sizeof(REALconstant), // constantCount
    0,                                              // mFlags
    NULL,                                           // sharedProperties
    0,                                              // sharedPropertyCount
    NULL,                                           // sharedMethods
    0,                                              // sharedMethodCount; // End RB2006r4 stuff
#if kCurrentREALControlVersion >= 11
    NULL, // delegates
    0,    // delegateCount
    NULL, // enums
    0,    // enumCount
#endif
};

void registerStyleHTML(void)
{
    REALRegisterClass(&xsiStyleHTMLDef);
}
