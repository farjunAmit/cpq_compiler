/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_CPL_TAB_H_INCLUDED
# define YY_YY_CPL_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 88 "cpl.y"

    enum typeForNumbers {INTTYPE, FLOATTYPE};
    enum operator{PLUS, MINUS, MUL, DIV};
    enum comparisonOperator{EQUAL, NOTEQUAL, SMALL, BIG, SEQUAL, BEQUAL};

    typedef struct labels {
    int number;
    char l;
    }* label;

    typedef struct tempResults{
      int number;
      char * name;
    }*tempResult;

    /*אני צריך להוסיף מבנה לכל משתנה גזירה */
    typedef struct structForBoolean{
      label conditionLabel;
      tempResult result;
    }*booleanAttribute;

    typedef struct structForExpression{
      char *variable;
      enum typeForNumbers type;
      tempResult result;
    }*expressionAttribute;


/* Line 2058 of yacc.c  */
#line 75 "cpl.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CASE = 258,
     DEFAULT = 259,
     ELSE = 260,
     FLOAT = 261,
     IF = 262,
     INPUT = 263,
     INT = 264,
     OUTPUT = 265,
     WHILE = 266,
     RELOP = 267,
     ADDOP = 268,
     MULOP = 269,
     OR = 270,
     AND = 271,
     NOT = 272,
     CAST = 273,
     ID = 274,
     NUM = 275
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 116 "cpl.y"

    booleanAttribute boolAtt; 
    expressionAttribute expAtt;
    tempResult result;
    char *variable;
    label lval;
    enum typeForNumbers tval;
    enum operator modifierOpp;
    enum comparisonOperator compraisonOpp;



/* Line 2058 of yacc.c  */
#line 123 "cpl.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_CPL_TAB_H_INCLUDED  */
