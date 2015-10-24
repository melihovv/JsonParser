/*!
 *\file parser.yy
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of syntax analyzer.
 */

/*! Require bison >=3.0.4. */
%require "3.0.4"

/*! Use c++ skeleton file. */
%skeleton "lalr1.cc"

/*! Generate header file. */
%defines

/*! For parser trace. Disable this for release version. */
//%debug

/*! Verbose error messages. */
%error-verbose

/*! Enable location tracking. */
%locations
%initial-action
{
    @$.begin.filename = @$.end.filename = &driver.fileName;
};

%define api.namespace {melihovv::Json}
%define parser_class_name {Parser}
%parse-param {melihovv::Json::Lexer& lexer}
%parse-param {melihovv::Json::Driver& driver}
%lex-param {melihovv::Json::Driver& driver}

%code requires {
    #include <string>
    #include <list>
    #include "driver.h"
    #include "error.h"
    #include "document.h"

    namespace melihovv {
        namespace Json {
            class Lexer;
            class Error;
            class Driver;
        }
    }
}

%code {
    #include "lexer.h"

    #define yylex(x) lexer.mylex(x)

    void melihovv::Json::Parser::error(
            const location_type& location,
            const std::string& message
        )
    {
        driver.addError(location, message);
    }
}

/*! Generate constructor functions for tokens. */
%define api.token.constructor

/*! Use variants instead of union. */
%define api.value.type variant

/*! Issue runtime assertions to catch invalid uses. */
%define parse.assert

/*!
 * Add a prefix to the token names when generating their definition in the
 * target language.
 */
%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    LBRACE "{"
    RBRACE "}"
    LBRACKET "["
    RBRACKET "]"
    COMMA ","
    COLON ":"
    NULL "NULL"
    <bool> BOOLEAN
    <long double> NUMBER
    <std::string> STRING
;

%type<Value> Value;
%type<std::pair<std::string, Value>> Pair;
%type<std::map<std::string, Value>> Members;
%type<Object> Object;
%type<std::vector<Value>> Elements;
%type<Array> Array;

%start Json

%%
Json
    : Object {driver.document = Document($1);}
    | Array {driver.document = Document($1);}
    ;

Object
    : "{" "}"
    | "{" Members "}" {$$ = Object($2);}
    ;

Members
    : Pair {$$.insert($1);}
    | Members "," Pair {$1.insert($3); $$ = $1;}
    ;

Pair
    : STRING ":" Value {$$ = std::make_pair($1, $3);}
    ;

Array
    : "[" "]"
    | "[" Elements "]" {$$ = Array($2);}
    ;

Elements
    : Value {$$.push_back($1);}
    | Elements "," Value {$1.push_back($3); $$ = $1;}
    ;

Value
    : STRING {$$ = Value($1);}
    | NUMBER {$$ = Value($1);}
    | Object {$$ = Value($1);}
    | Array {$$ = Value($1);}
    | BOOLEAN {$$ = Value($1);}
    | NULL {$$ = Value();}
    ;
%%
