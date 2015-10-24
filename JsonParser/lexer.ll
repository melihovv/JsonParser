/*!
 *\file lexer.ll
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of lexical analyzer.
 */

/*! Scan only one file. */
%option noyywrap

/*! Don't optimize lexer for console input */
%option never-interactive

/*!
 * Causes the default rule (that unmatched scanner input is echoed to stdout)
 * to be suppressed.
 */
%option nodefault

/*! Generate c++ class. */
%option c++
/*! Class name. */
%option yyclass="Lexer"

/* Generate debug output. Disable this for release version. */
/*%option debug*/

%{
    #include "lexer.h"

    /*!
     * Each time yylex is invoked, the begin position is moved onto the end 
     * position.
     */
    #define YY_USER_ACTION loc.columns(yyleng);

    /*!
     * In our case yyterminate() must return Parser::symbol_type instead of
     * 0.
     */
    #define yyterminate() {return Json::Parser::make_END(loc);}

    /*! Don't include unistd.h, which is not availible under MSVC++. */
    #define YY_NO_UNISTD_H
%}

boolean true|false

digit1to9 [1-9]
digit [0-9]
digits {digit}+
int [-]?({digit}|{digit1to9}{digits})
frac [.]{digits}
exp {e}{digits}
e [eE][+-]?
number {int}|{int}{frac}|{int}{exp}|{int}{frac}{exp}

UnicodeEscapeSequence u[0-9A-Fa-f]{4}
EscapeCharacter ["\\/bfnrt]
EscapeSequence {EscapeCharacter}|{UnicodeEscapeSequence}
StringCharacter [^"\\]|\\{EscapeSequence}
string \"{StringCharacter}*\"

blank [ \t\r]
%%

%{
    /*! Tokens' location. */
    static melihovv::Json::Parser::location_type loc(&driver.fileName);
    loc.step();
%}

"{" {return Json::Parser::make_LBRACE(loc);}
"}" {return Json::Parser::make_RBRACE(loc);}
"[" {return Json::Parser::make_LBRACKET(loc);}
"]" {return Json::Parser::make_RBRACKET(loc);}
"," {return Json::Parser::make_COMMA(loc);}
":" {return Json::Parser::make_COLON(loc);}

"null" {return Json::Parser::make_NULL(loc);}
{boolean} {
    return Json::Parser::make_BOOLEAN(
        strcmp(yytext, "true") == 0 ? true : false,
        loc
    );
}
{number} {return Json::Parser::make_NUMBER(std::stold(yytext), loc);}
{string} {
    std::string result(yytext + 1);
    return Json::Parser::make_STRING(result.erase(result.size() - 1, 1), loc);
}

{blank}+ {loc.step();}
\n {
    loc.lines(yyleng);
    loc.step();
}
. {
    driver.addError(loc, std::string("Strange symbol: ") + yytext);
}

<<EOF>> {
    loc.initialize(&driver.fileName);
    yyterminate();
}

%%
