/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 371 of yacc.c  */
#line 68 "cpl.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cpl.tab.h".  */
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
/* Line 387 of yacc.c  */
#line 90 "cpl.y"

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


/* Line 387 of yacc.c  */
#line 129 "cpl.tab.c"

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
/* Line 387 of yacc.c  */
#line 118 "cpl.y"

    booleanAttribute boolAtt; 
    expressionAttribute expAtt;
    tempResult result;
    char *variable;
    label lval;
    enum typeForNumbers tval;
    enum operator modifierOpp;
    enum comparisonOperator compraisonOpp;



/* Line 387 of yacc.c  */
#line 177 "cpl.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 205 "cpl.tab.c"
/* Unqualified %code blocks.  */
/* Line 391 of yacc.c  */
#line 1 "cpl.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define STRLEN_FOR_CPL_1VAR 7
  #define STRLEN_FOR_CPL_2VAR 8
  #define STRLEN_FOR_CPL_3VAR 9
  #define STRLEN_FOR_LABELS 2
  #define GET_FILE_NAME_LENGTH(filename) strlen(filename) + 5
  extern int yylex (void);
  void yyerror (const char *s);

  /*define structs and enums*/

  typedef struct LinkedList {
    char *cplCommand; 
    struct LinkedList* next;
  }* node;

  typedef struct LinkedListForSymbole{
    enum typeForNumbers type;
    char * id;
    struct LinkedListForSymbole *next;
  }* symboleTable;

  /*end define struct and enums*/

  /*function signature*/
  void wirteCPLtoFile(char *targerFileName);
  int digitsInNum(int num);
  int isFloat(char * number);
  node createNode();
  symboleTable createSymboleTableNode();
  expressionAttribute creatNewExpression();
  booleanAttribute creatNewBool();
  void updateType(symboleTable startPoint, enum typeForNumbers idType);
  symboleTable searchInTable(char * id);
  void printSymboleTable();
  char * getExpType(expressionAttribute expr);
  void moveLast();
  void moveEndTable();
  label newLabel();
  void addLabel(label L);
  tempResult newTemp();
  char * tempForCasting(char *id);
  char * tempToString(tempResult tr);
  /*end function signature*/

  /*start cpl function signature*/
  void addJUMP(label L);
  void addRPRT(char * id);
  void addIPRT(char * id);
  void addRINP(char * id);
  void addIINP(char * id);
  void addJMPZ(label L, tempResult r1);
  void addRTOI(tempResult rt, char *id);
  void addITOR(tempResult rt, char *id);
  void addRASN(char * id ,char * var);
  void addIASN(char * id ,char * var);
  void addRADD(tempResult rt, char * var1, char *var2);
  void addIADD(tempResult rt, char * var1, char *var2);
  void addRSUB(tempResult rt, char * var1, char *var2);
  void addISUB(tempResult rt, char * var1, char *var2);
  void addRMLT(tempResult rt, char * var1, char *var2);
  void addRDIV(tempResult rt, char * var1, char *var2);
  void addIMLT(tempResult rt, char * var1, char *var2);
  void addIDIV(tempResult rt, char * var1, char *var2);
  void addREQL(tempResult rt, char * var1, char *var2);
  void addIEQL(tempResult rt, char * var1, char *var2);
  void addRNQL(tempResult rt, char * var1, char *var2);
  void addINQL(tempResult rt, char * var1, char *var2);
  void addRLSS(tempResult rt, char * var1, char *var2);
  void addILSS(tempResult rt, char * var1, char *var2);
  void addRGRT(tempResult rt, char * var1, char *var2);
  void addIGRT(tempResult rt, char * var1, char *var2);
  /*end cpl function signature*/

  /*global variable*/
  node head;
  node last;
  symboleTable startTable;
  symboleTable currentSymbole;
  symboleTable endTable;
  int errorCheck = 0;
  int label_counter = 0;
  int temp_result_counter = 0;
  /*end global variable*/


/* Line 391 of yacc.c  */
#line 299 "cpl.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   77

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNRULES -- Number of states.  */
#define YYNSTATES  86

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    26,     2,     2,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    21,    22,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    11,    17,    19,    21,
      25,    27,    29,    31,    33,    35,    37,    39,    44,    50,
      56,    57,    58,    69,    70,    71,    80,    84,    87,    88,
      92,    94,    98,   100,   105,   109,   113,   115,   119,   121,
     125,   130,   132,   134
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    53,    -1,    39,    40,    -1,    -1,
      -1,    41,    42,    21,    37,    22,    -1,     9,    -1,     6,
      -1,    42,    23,    19,    -1,    19,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    50,    -1,    53,    -1,    19,
      24,    36,    22,    -1,     8,    25,    19,    26,    22,    -1,
      10,    25,    36,    26,    22,    -1,    -1,    -1,     7,    30,
      25,    31,    26,    48,    43,    49,     5,    43,    -1,    -1,
      -1,    11,    30,    51,    25,    31,    26,    52,    43,    -1,
      27,    54,    28,    -1,    54,    43,    -1,    -1,    31,    15,
      32,    -1,    32,    -1,    32,    16,    33,    -1,    33,    -1,
      17,    25,    31,    26,    -1,    36,    12,    36,    -1,    36,
      13,    35,    -1,    35,    -1,    35,    14,    34,    -1,    34,
      -1,    25,    36,    26,    -1,    18,    25,    36,    26,    -1,
      19,    -1,    20,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   155,   155,   160,   161,   164,   164,   169,   170,   173,
     177,   184,   185,   186,   187,   188,   189,   192,   215,   230,
     240,   242,   240,   249,   250,   249,   256,   258,   259,   262,
     268,   270,   276,   279,   283,   348,   382,   385,   419,   422,
     423,   447,   455,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CASE", "DEFAULT", "ELSE", "FLOAT", "IF",
  "INPUT", "INT", "OUTPUT", "WHILE", "RELOP", "ADDOP", "MULOP", "OR",
  "AND", "NOT", "CAST", "ID", "NUM", "':'", "';'", "','", "'='", "'('",
  "')'", "'{'", "'}'", "$accept", "create_label", "boolexpr", "boolterm",
  "boolfactor", "factor", "term", "expression", "type", "program",
  "declarations", "declaration", "$@1", "idlist", "stmt",
  "assignment_stmt", "input_stmt", "output_stmt", "if_stmt", "$@2", "$@3",
  "while_stmt", "$@4", "$@5", "stmt_block", "stmtlist", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    58,    59,    44,    61,    40,    41,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    38,    39,    39,    41,    40,    37,    37,    42,
      42,    43,    43,    43,    43,    43,    43,    44,    45,    46,
      48,    49,    47,    51,    52,    50,    53,    54,    54,    31,
      31,    32,    32,    33,    33,    36,    36,    35,    35,    34,
      34,    34,    34,    30
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     0,     5,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       0,     0,    10,     0,     0,     8,     3,     2,     0,     3,
       1,     3,     1,     4,     3,     3,     1,     3,     1,     3,
       4,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     5,     1,    28,     3,     0,     2,     0,    10,
       0,    43,     0,     0,    43,     0,    26,    27,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,     0,    23,
       0,     8,     7,     0,     9,     0,     0,     0,    41,    42,
       0,    38,    36,     0,     0,     0,     6,     0,     0,    30,
      32,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,    20,     0,     0,    18,     0,    39,    37,    35,
      19,     0,     0,    29,     0,    31,    34,    40,    24,    33,
      21,     0,     0,    25,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    26,    48,    49,    50,    41,    42,    51,    33,     1,
       2,     5,     6,    10,    17,    18,    19,    20,    21,    74,
      82,    22,    44,    81,    23,     8
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yytype_int8 yypact[] =
{
     -44,    29,   -26,   -44,   -44,   -44,    20,   -44,    -4,   -44,
      33,   -44,    27,    30,   -44,    34,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    31,    38,    35,    40,    28,   -44,
      28,   -44,   -44,    39,   -44,    25,    36,    41,   -44,   -44,
      28,   -44,    49,    -8,    42,    13,   -44,    43,    -6,    48,
     -44,    21,    47,    28,    -5,    28,    28,    50,    25,   -44,
      25,    25,   -44,    25,    28,   -44,     6,   -44,   -44,    49,
     -44,     1,     2,    48,     3,   -44,    52,   -44,   -44,   -44,
     -44,     3,    65,   -44,     3,   -44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,    57,    -9,    12,    11,    22,    19,   -28,   -44,   -44,
     -44,   -44,   -44,   -44,   -43,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,    74,   -44
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,     4,    45,    11,    12,    56,    13,    14,    56,    61,
      11,    12,    54,    13,    14,    15,    61,    61,    57,    56,
      62,    67,    15,     4,    16,    66,    56,    78,    79,     3,
       4,    80,    77,    64,    56,    59,    76,    31,    83,     9,
      32,    85,    47,    37,    38,    39,    37,    38,    39,    71,
      40,    72,    27,    40,    24,    28,    25,    34,    30,    36,
      35,    46,    52,    55,    63,    56,    53,    58,    60,    65,
      84,    29,    70,    73,    75,    69,     7,    68
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
      28,    27,    30,     7,     8,    13,    10,    11,    13,    15,
       7,     8,    40,    10,    11,    19,    15,    15,    26,    13,
      26,    26,    19,    27,    28,    53,    13,    26,    26,     0,
      27,    74,    26,    12,    13,    22,    64,     6,    81,    19,
       9,    84,    17,    18,    19,    20,    18,    19,    20,    58,
      25,    60,    25,    25,    21,    25,    23,    19,    24,    19,
      25,    22,    26,    14,    16,    13,    25,    25,    25,    22,
       5,    14,    22,    61,    63,    56,     2,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,    27,    40,    41,    53,    54,    19,
      42,     7,     8,    10,    11,    19,    28,    43,    44,    45,
      46,    47,    50,    53,    21,    23,    30,    25,    25,    30,
      24,     6,     9,    37,    19,    25,    19,    18,    19,    20,
      25,    34,    35,    36,    51,    36,    22,    17,    31,    32,
      33,    36,    26,    25,    36,    14,    13,    26,    25,    22,
      25,    15,    26,    16,    12,    22,    36,    26,    34,    35,
      22,    31,    31,    32,    48,    33,    36,    26,    26,    26,
      43,    52,    49,    43,     5,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 156 "cpl.y"
    { last -> cplCommand = (char *) malloc(sizeof(char)*strlen("\tHALT\n\0"));
                      strcpy(last -> cplCommand,"\tHALT\n");}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 164 "cpl.y"
    {currentSymbole = endTable;}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 166 "cpl.y"
    {updateType(currentSymbole, (yyvsp[(4) - (5)].tval));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 169 "cpl.y"
    {enum typeForNumbers i = INTTYPE; (yyval.tval) = i;}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 170 "cpl.y"
    {enum typeForNumbers f = FLOATTYPE; (yyval.tval) = f;}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 174 "cpl.y"
    { if(searchInTable((yyvsp[(3) - (3)].variable))!=NULL) yyerror("cant use same id twice");
                      endTable -> id = (yyvsp[(3) - (3)].variable); 
                      moveEndTable();}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 178 "cpl.y"
    { if(searchInTable((yyvsp[(1) - (1)].variable))!=NULL) yyerror("cant use same id twice");
                        endTable -> id = (yyvsp[(1) - (1)].variable);
                        moveEndTable();
                    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 193 "cpl.y"
    { symboleTable temp = searchInTable((yyvsp[(1) - (4)].variable)); 
                      char * expressionVariable;
                      enum typeForNumbers type; 
                      if(temp==NULL)
                        yyerror("not valid ID");
                      else 
                        {
                          type = temp -> type;
                          if(type ==  INTTYPE && (yyvsp[(3) - (4)].expAtt)->type == FLOATTYPE)
                            yyerror("It is not possible to assign a float to an int");
                          else{
                            expressionVariable = getExpType((yyvsp[(3) - (4)].expAtt));
                            if(type == FLOATTYPE)
                              addRASN((yyvsp[(1) - (4)].variable),expressionVariable);
                            if(type == INTTYPE)
                              addIASN((yyvsp[(1) - (4)].variable),expressionVariable);
                          }

                        }
                    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 216 "cpl.y"
    { symboleTable temp = searchInTable((yyvsp[(3) - (5)].variable)); 
                      enum typeForNumbers type;
                      if(temp==NULL)
                        yyerror("not valid ID");
                      else{
                        type = temp -> type;
                        if(type == FLOATTYPE)
                          addRINP((yyvsp[(3) - (5)].variable));
                        if(type == INTTYPE)
                          addIINP((yyvsp[(3) - (5)].variable)); 
                      }
                    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 231 "cpl.y"
    { char * expressionVariable;
                      expressionVariable = getExpType((yyvsp[(3) - (5)].expAtt));
                      if((yyvsp[(3) - (5)].expAtt) -> type == FLOATTYPE)
                        addRPRT(expressionVariable);
                      if((yyvsp[(3) - (5)].expAtt) -> type == INTTYPE)
                        addIPRT(expressionVariable);
                    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 240 "cpl.y"
    {addJMPZ((yyvsp[(4) - (5)].boolAtt) -> conditionLabel, (yyvsp[(4) - (5)].boolAtt)->result);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 242 "cpl.y"
    {addJUMP((yyvsp[(2) - (7)].lval));
                      addLabel((yyvsp[(4) - (7)].boolAtt)->conditionLabel);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 246 "cpl.y"
    {addLabel((yyvsp[(2) - (10)].lval));}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 249 "cpl.y"
    {addLabel((yyvsp[(2) - (2)].lval));}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 250 "cpl.y"
    {addJMPZ((yyvsp[(5) - (6)].boolAtt) -> conditionLabel, (yyvsp[(5) - (6)].boolAtt)->result);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 252 "cpl.y"
    { addJUMP((yyvsp[(2) - (8)].lval));
                      addLabel((yyvsp[(5) - (8)].boolAtt)->conditionLabel);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 263 "cpl.y"
    {
                      addIADD((yyvsp[(1) - (3)].boolAtt)->result,tempToString((yyvsp[(1) - (3)].boolAtt)->result), tempToString((yyvsp[(3) - (3)].boolAtt)->result));
                      addIGRT((yyvsp[(1) - (3)].boolAtt)->result,tempToString((yyvsp[(1) - (3)].boolAtt)->result),"0");
                      (yyval.boolAtt) = (yyvsp[(1) - (3)].boolAtt);
                    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 268 "cpl.y"
    {(yyval.boolAtt)=(yyvsp[(1) - (1)].boolAtt);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 271 "cpl.y"
    {
                      addIADD((yyvsp[(1) - (3)].boolAtt)->result,tempToString((yyvsp[(1) - (3)].boolAtt)->result), tempToString((yyvsp[(3) - (3)].boolAtt)->result));
                      addIEQL((yyvsp[(1) - (3)].boolAtt)->result,tempToString((yyvsp[(1) - (3)].boolAtt)->result),"2");
                      (yyval.boolAtt) = (yyvsp[(1) - (3)].boolAtt);
                    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 276 "cpl.y"
    {(yyval.boolAtt)=(yyvsp[(1) - (1)].boolAtt);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 280 "cpl.y"
    { addIEQL((yyvsp[(3) - (4)].boolAtt)->result,tempToString((yyvsp[(3) - (4)].boolAtt)->result),"0");
                      (yyval.boolAtt)=(yyvsp[(3) - (4)].boolAtt);
                    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 284 "cpl.y"
    { (yyval.boolAtt)=creatNewBool();
                      char *expressionVariable1, *expressionVariable2;
                      int isFlaot = 0;
                      tempResult temp = newTemp();
                      tempResult tempForComplex;
                      expressionVariable1 = getExpType((yyvsp[(1) - (3)].expAtt));
                      expressionVariable2 = getExpType((yyvsp[(3) - (3)].expAtt));

                      if((yyvsp[(1) - (3)].expAtt)->type == INTTYPE && (yyvsp[(3) - (3)].expAtt) ->type == FLOATTYPE){
                        expressionVariable1 = tempForCasting(expressionVariable1);
                        isFlaot = 1;
                      }
                      if((yyvsp[(3) - (3)].expAtt)->type == INTTYPE && (yyvsp[(1) - (3)].expAtt) -> type == FLOATTYPE){
                        expressionVariable2 = tempForCasting(expressionVariable2);
                        isFlaot = 1;
                      }
                      if((yyvsp[(3) - (3)].expAtt)->type == FLOATTYPE && (yyvsp[(3) - (3)].expAtt)->type == FLOATTYPE) isFlaot = 1;

                      if(isFlaot){
                        if((yyvsp[(2) - (3)].compraisonOpp) == EQUAL)
                          addREQL(temp,expressionVariable1,expressionVariable2);
                        if((yyvsp[(2) - (3)].compraisonOpp) ==  NOTEQUAL)
                          addRNQL(temp,expressionVariable1,expressionVariable2);
                        if((yyvsp[(2) - (3)].compraisonOpp) == SMALL)
                          addRLSS(temp,expressionVariable1,expressionVariable2); 
                        if((yyvsp[(2) - (3)].compraisonOpp) == BIG)
                          addRGRT(temp,expressionVariable1,expressionVariable2); 
                        if((yyvsp[(2) - (3)].compraisonOpp) ==  SEQUAL){
                          tempForComplex = newTemp();
                          addREQL(temp,expressionVariable1,expressionVariable2);
                          addRLSS(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                        if((yyvsp[(2) - (3)].compraisonOpp) == BEQUAL){
                          tempForComplex = newTemp();
                          addREQL(temp,expressionVariable1,expressionVariable2);
                          addRGRT(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                      }
                      else{
                        if((yyvsp[(2) - (3)].compraisonOpp) == EQUAL)
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                        if((yyvsp[(2) - (3)].compraisonOpp) ==  NOTEQUAL)
                          addINQL(temp,expressionVariable1,expressionVariable2);
                        if((yyvsp[(2) - (3)].compraisonOpp) == SMALL)
                          addILSS(temp,expressionVariable1,expressionVariable2); 
                        if((yyvsp[(2) - (3)].compraisonOpp) == BIG)
                          addIGRT(temp,expressionVariable1,expressionVariable2); 
                        if((yyvsp[(2) - (3)].compraisonOpp) ==  SEQUAL){
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                          addILSS(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp)); 
                        }
                        if((yyvsp[(2) - (3)].compraisonOpp) == BEQUAL){
                          addIEQL(temp,expressionVariable1,expressionVariable2);
                          addIGRT(tempForComplex, expressionVariable1,expressionVariable2);
                          addIADD(temp,tempToString(tempForComplex), tempToString(temp));
                        }
                      }
                      (yyval.boolAtt)->result=temp;
                    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 349 "cpl.y"
    { char *termVariable, *expressionVariable;
                      tempResult temp = newTemp();
                      expressionVariable = getExpType((yyvsp[(1) - (3)].expAtt));
                      termVariable = getExpType((yyvsp[(3) - (3)].expAtt));

                      if((yyvsp[(2) - (3)].modifierOpp)==PLUS){
                        if((yyvsp[(1) - (3)].expAtt)->type == FLOATTYPE || (yyvsp[(3) - (3)].expAtt)->type == FLOATTYPE){
                          if((yyvsp[(1) - (3)].expAtt)->type == INTTYPE) expressionVariable = tempForCasting(expressionVariable);
                          if((yyvsp[(3) - (3)].expAtt)->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          addRADD(temp, expressionVariable, termVariable);
                          (yyval.expAtt)->type = FLOATTYPE;
                        }
                        else{
                          addIADD(temp, expressionVariable, termVariable);
                          (yyval.expAtt)->type = INTTYPE;
                        } 
                      }

                      if((yyvsp[(2) - (3)].modifierOpp)==MINUS){
                        if((yyvsp[(1) - (3)].expAtt)->type == FLOATTYPE || (yyvsp[(3) - (3)].expAtt)->type == FLOATTYPE){
                          if((yyvsp[(1) - (3)].expAtt)->type == INTTYPE) expressionVariable = tempForCasting(expressionVariable);
                          if((yyvsp[(3) - (3)].expAtt)->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          addRSUB(temp, expressionVariable, termVariable);
                          (yyval.expAtt)->type = FLOATTYPE;
                        }
                        else{
                          addISUB(temp, expressionVariable, termVariable);
                          (yyval.expAtt)->type = INTTYPE;
                        } 
                      }
                      (yyval.expAtt) = (yyvsp[(1) - (3)].expAtt);
                      (yyval.expAtt)->result = temp;
                    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 382 "cpl.y"
    {(yyval.expAtt)=(yyvsp[(1) - (1)].expAtt);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 386 "cpl.y"
    { char *termVariable, *factorVariable;
                      tempResult temp = newTemp();
                      termVariable = getExpType((yyvsp[(1) - (3)].expAtt));
                      factorVariable = getExpType((yyvsp[(3) - (3)].expAtt));

                      if((yyvsp[(2) - (3)].modifierOpp)==MUL){
                        if((yyvsp[(1) - (3)].expAtt)->type == FLOATTYPE || (yyvsp[(3) - (3)].expAtt)->type == FLOATTYPE){
                          if((yyvsp[(1) - (3)].expAtt)->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          if((yyvsp[(3) - (3)].expAtt)->type == INTTYPE) factorVariable = tempForCasting(termVariable);
                          addRMLT(temp, termVariable, factorVariable);
                          (yyval.expAtt)->type = FLOATTYPE;
                        }
                        else{
                          addIMLT(temp, termVariable, factorVariable);
                          (yyval.expAtt)->type = INTTYPE;
                        } 
                      }

                      if((yyvsp[(2) - (3)].modifierOpp)==DIV){
                        if((yyvsp[(1) - (3)].expAtt)->type == FLOATTYPE || (yyvsp[(3) - (3)].expAtt)->type == FLOATTYPE){
                          if((yyvsp[(1) - (3)].expAtt)->type == INTTYPE) termVariable = tempForCasting(termVariable);
                          if((yyvsp[(3) - (3)].expAtt)->type == INTTYPE) factorVariable = tempForCasting(factorVariable);
                          addRDIV(temp, termVariable, factorVariable);
                          (yyval.expAtt)->type = FLOATTYPE;
                        }
                        else{
                          addIDIV(temp, termVariable, factorVariable);
                          (yyval.expAtt)->type = INTTYPE;
                        } 
                      }
                      (yyval.expAtt) = (yyvsp[(1) - (3)].expAtt);
                      (yyval.expAtt)->result = temp;
                    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 419 "cpl.y"
    {(yyval.expAtt) = (yyvsp[(1) - (1)].expAtt);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 422 "cpl.y"
    {(yyval.expAtt) = (yyvsp[(2) - (3)].expAtt);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 424 "cpl.y"
    { extern int yylineno;
                      char *expressionVariable = getExpType((yyvsp[(3) - (4)].expAtt));
                      tempResult temp = newTemp();
                      if((yyvsp[(1) - (4)].tval) == INTTYPE){
                        if((yyvsp[(3) - (4)].expAtt) -> type == INTTYPE){
                          printf("WARNING: in line: %d TRY TO CAST INT TO INT\n", yylineno);
                          addIASN(tempToString(temp),expressionVariable);
                        }
                        else
                          addITOR(temp,expressionVariable);
                      }
                      if((yyvsp[(1) - (4)].tval) == FLOATTYPE){
                        if((yyvsp[(3) - (4)].expAtt) -> type == FLOATTYPE){
                          printf("WARNING: in line:%d TRY TO CAST FLAOT TO FLAOT\n", yylineno);
                          addRASN(tempToString(temp),expressionVariable);
                        }
                        else
                          addRTOI(temp,expressionVariable);
                      }
                      (yyval.expAtt) = (yyvsp[(3) - (4)].expAtt);
                      (yyval.expAtt) -> result = temp;
                      (yyval.expAtt) ->type = (yyvsp[(1) - (4)].tval); 
                    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 447 "cpl.y"
    {(yyval.expAtt) = creatNewExpression();
                        (yyval.expAtt)->variable = (yyvsp[(1) - (1)].variable);
                        (yyval.expAtt) -> result = NULL;
                        symboleTable temp = searchInTable((yyvsp[(1) - (1)].variable)); 
                        if(temp==NULL)
                          yyerror("not valid ID");
                        else 
                          (yyval.expAtt)->type = temp->type;}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 455 "cpl.y"
    {(yyval.expAtt)=creatNewExpression(); (yyval.expAtt)->type = (isFloat((yyvsp[(1) - (1)].variable))) ? FLOATTYPE : INTTYPE; (yyval.expAtt)->variable = (yyvsp[(1) - (1)].variable);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 458 "cpl.y"
    { (yyval.lval) = newLabel();}
    break;


/* Line 1792 of yacc.c  */
#line 1949 "cpl.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 460 "cpl.y"

int main (int argc, char **argv)
{
  extern FILE *yyin; /* defined by flex */
  char *sourceFileName;
  char *fileType;
  char targetFileName[GET_FILE_NAME_LENGTH(argv[1])];
  head = createNode();
  last = head;
  startTable = createSymboleTableNode();
  endTable = startTable;
  
  if (argc != 2) {
     fprintf (stderr, "Usage: %s <input-file-name>\n", argv[0]);
	 return 1;
  }
  yyin = fopen (argv [1], "r");
  if (yyin == NULL) {
       fprintf (stderr, "failed to open %s\n", argv[1]);
	   return 2;
  }

  sourceFileName = strtok(argv[1],".");
  fileType = strtok(NULL,"");
  if(strcmp(fileType,"ou")){
    fprintf(stderr,"failed to open %s.%s, file name have to end with ou\n", argv[1],fileType);
    return 3;
  } 

  yyparse ();

/*print the list*/
  strcpy(targetFileName,sourceFileName);
  strcpy(targetFileName+strlen(sourceFileName),".qud");
  wirteCPLtoFile(targetFileName);
  fclose (yyin);
  return 0;
}

void wirteCPLtoFile(char *targetFileName){
  FILE *qudFile;
  if(!errorCheck){
    qudFile = fopen(targetFileName,"w");
    while(head != NULL){
      fprintf(qudFile,"%s", head->cplCommand);
      head = head -> next;}
  }
  fprintf(qudFile,"Amit Farjun");
  fprintf(stderr,"Amit Farjun\n");
}

node createNode(){
  node temp; 
  temp = (node)malloc(sizeof(struct LinkedList));
  temp->next = NULL;
  return temp;
}

symboleTable createSymboleTableNode(){
  symboleTable temp;
  temp = (symboleTable)malloc(sizeof(struct LinkedListForSymbole));
  temp -> id =NULL;
  temp -> next = NULL;
  return temp;
}
expressionAttribute creatNewExpression(){
  expressionAttribute temp;
  temp = (expressionAttribute)malloc(sizeof(struct structForExpression));
  temp -> variable = NULL;
  temp -> result = NULL;
}

booleanAttribute creatNewBool(){
  booleanAttribute temp;
  temp = (booleanAttribute)malloc(sizeof(struct structForBoolean));
  temp -> conditionLabel = newLabel();
  temp -> result = NULL;
}

void updateType(symboleTable startPoint, enum typeForNumbers idType){
  symboleTable temp = startPoint;
  while(temp != endTable){
    temp -> type = idType;
    temp = temp-> next;
  }
}

symboleTable searchInTable(char * id){
  symboleTable temp = startTable;
  while(temp -> id != NULL){
    if(!strcmp(id, temp -> id))
      return temp;
    else
      temp = temp -> next;
  }
  return NULL;
}

void printSymboleTable(){
  symboleTable temp = startTable;
  while(temp -> id != NULL){
    printf("%s",temp -> id );
    if(temp -> type == FLOATTYPE) printf(" float\n");
    else printf(" int\n");
    temp = temp -> next;
  }
}

char * getExpType(expressionAttribute expr){
  char * expressionVariable;
  if(expr->result == NULL)
    expressionVariable = expr->variable;
  else
    expressionVariable = tempToString(expr->result);
  return expressionVariable;
}

void moveLast(){
  last -> next = createNode();
  last = last -> next;
}

void moveEndTable(){
  endTable -> next = createSymboleTableNode();
  endTable = endTable -> next;
}

label newLabel(){
  label temp;
  temp = (label)malloc(sizeof(struct labels));
  temp -> number = ++label_counter;
  temp -> l = 'L';
  return temp;
}

tempResult newTemp(){
  tempResult temp;
  temp = (tempResult)malloc(sizeof(struct tempResults));
  temp -> number = ++temp_result_counter;
  temp -> name = "t";
  while(searchInTable(tempToString(temp))!=NULL) temp -> number = ++temp_result_counter;
  return temp;
}
char *tempForCasting(char *id){
  tempResult tr = newTemp();
  addITOR(tr, id);
  return tempToString(tr);
}

char * tempToString(tempResult tr){
  char * temp;
  temp = (char *)malloc(sizeof(char)*(digitsInNum(tr->number)+strlen(tr->name)+1));
  sprintf(temp,"%s%d",tr->name,tr->number);
  return temp;
}

int digitsInNum(int num){
  int counter = 1;
  while(num > 10){
    counter++;
    num = num / 10;
  }
  return counter;
}

int isFloat(char *number){
  char * currentNum = number;
  for(char * currentNum = number; *currentNum != '\0'; currentNum++)
    if(*currentNum == '.')
      return 1;
  return 0;
}

/*cpl command function*/
void addJUMP(label L){
  int labelDigits = digitsInNum(L->number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(labelDigits+STRLEN_FOR_CPL_1VAR+2));
  sprintf(last->cplCommand,"\tJUMP %c%d\n", L->l, L->number);
  moveLast();
}

void addRPRT(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tRPRT %s\n",id);
  moveLast();
}

void addIPRT(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tIPRT %s\n",id);
  moveLast();
}

void addRINP(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tRINP %s\n",id);
  moveLast();
}

void addIINP(char * id){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id) + STRLEN_FOR_CPL_1VAR + 1));
  sprintf(last->cplCommand,"\tIINP %s\n",id);
  moveLast();
}

void addJMPZ(label L, tempResult r1){
  int labelDigits = digitsInNum(L->number);
  int tempDigits = digitsInNum(r1 -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(labelDigits + tempDigits + strlen(r1->name) + STRLEN_FOR_CPL_2VAR + 2));
  sprintf(last->cplCommand,"\tJMPZ %c%d %s%d\n", L->l, L->number, r1->name, r1->number);
  moveLast();
}

void addRASN(char * id ,char * var){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id)+strlen(var)+STRLEN_FOR_CPL_2VAR+1));
  sprintf(last->cplCommand,"\tRASN %s %s\n", id, var);
  moveLast();
}

void addIASN(char * id ,char * var){
  last -> cplCommand=(char *)malloc(sizeof(char)*(strlen(id)+strlen(var)+ STRLEN_FOR_CPL_2VAR +1 ));
  sprintf(last->cplCommand,"\tIASN %s %s\n", id, var);
  moveLast();
}

void addITOR(tempResult rt, char *id){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(id)+STRLEN_FOR_CPL_2VAR + 1));
  sprintf(last->cplCommand,"\tITOR %s%d %s\n", rt->name, rt->number, id);
  moveLast();
}

void addRTOI(tempResult rt, char *id){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(id)+STRLEN_FOR_CPL_2VAR + 1));
  sprintf(last->cplCommand,"\tRTOI %s%d %s\n", rt->name, rt->number, id);
  moveLast();
}

void addRADD(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRADD %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIADD(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIADD %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addRSUB(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRSUB %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addISUB(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tISUB %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRMLT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRMLT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRDIV(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRDIV %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIMLT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIMLT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}
void addIDIV(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIDIV %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addREQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tREQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIEQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIEQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRNQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRNQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addINQL(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tINQL %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRLSS(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRLSS %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addILSS(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tILSS %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addRGRT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tRGRT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addIGRT(tempResult rt, char * var1, char *var2){
  int tempDigits = digitsInNum(rt -> number);
  last -> cplCommand=(char *)malloc(sizeof(char)*(tempDigits+strlen(rt->name)+strlen(var1)+strlen(var2)+STRLEN_FOR_CPL_3VAR + 1));
  sprintf(last->cplCommand,"\tIGRT %s%d %s %s\n", rt->name, rt->number, var1, var2);
  moveLast();
}

void addLabel(label L)
{
  int labelDigits = digitsInNum(L->number);
  last->cplCommand = (char *)malloc(sizeof(char)*(labelDigits+STRLEN_FOR_LABELS+2));
  sprintf(last->cplCommand,"%c%d:\n",L->l, L->number);
  moveLast();
}

void yyerror (const char *s)
{
  extern int yylineno;
  errorCheck = 1;
  fprintf (stderr, "error in line %d: %s\n", yylineno,s);
}