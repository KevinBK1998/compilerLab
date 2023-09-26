/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntax.y" /* yacc.c:339  */

/*Parser to identify syntax and create AST
  Stage 7:
  1.Built-in fns include read(),write(),alloc(),initialize(),free()
  2.Global Declarations,Functions,Local Declarations added
  3.All user defined function definitions, if any, should be given before main()
  4.Two fundamental datatypes-int & str
  5.All user defined type definitions, if any, should be given before global declarations
  6.Adding class defnitions
  7.Member Fn declaration,definition,type checking finished
  8.Fixed Bug:type name,class name can be defined as variable name
  9.Denied use of member variables in non member functions
  10.Member fns have access to member variables also
  To-Do
  1.Error:Passing variables to a multi argument member fncall gives segmentation fault
  2.Error:Omitting return statements

*/
#include<stdio.h>
#include<stdlib.h>
#include "exptree.c"
//#include "assembler.c"
#define YYSTYPE node*
extern FILE* yyin;

#line 92 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    IF = 260,
    THEN = 261,
    ELSE = 262,
    ENDIF = 263,
    WHILE = 264,
    DO = 265,
    FREE = 266,
    ENDWHILE = 267,
    REPEAT = 268,
    UNTIL = 269,
    BREAK = 270,
    STR = 271,
    TYPE = 272,
    INIT = 273,
    NULL_VAL = 274,
    SELF = 275,
    NEW_KEY = 276,
    CONTINUE = 277,
    BEG = 278,
    READ = 279,
    WRITE = 280,
    END = 281,
    ALLOC = 282,
    DECL = 283,
    INT_TYPE = 284,
    STR_TYPE = 285,
    ENDDECL = 286,
    MAIN = 287,
    RETF = 288,
    ENDTYPE = 289,
    ENDCLASS = 290,
    CLASS = 291,
    DEL = 292,
    OR = 293,
    AND = 294,
    EQTO = 295,
    NTEQ = 296,
    GTEQ = 297,
    LSEQ = 298,
    NOT = 299
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define IF 260
#define THEN 261
#define ELSE 262
#define ENDIF 263
#define WHILE 264
#define DO 265
#define FREE 266
#define ENDWHILE 267
#define REPEAT 268
#define UNTIL 269
#define BREAK 270
#define STR 271
#define TYPE 272
#define INIT 273
#define NULL_VAL 274
#define SELF 275
#define NEW_KEY 276
#define CONTINUE 277
#define BEG 278
#define READ 279
#define WRITE 280
#define END 281
#define ALLOC 282
#define DECL 283
#define INT_TYPE 284
#define STR_TYPE 285
#define ENDDECL 286
#define MAIN 287
#define RETF 288
#define ENDTYPE 289
#define ENDCLASS 290
#define CLASS 291
#define DEL 292
#define OR 293
#define AND 294
#define EQTO 295
#define NTEQ 296
#define GTEQ 297
#define LSEQ 298
#define NOT 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   897

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    52,     2,     2,
      57,    58,    50,    48,    38,    49,    54,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
      46,    39,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    40,    41,    42,    43,    45,    47,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    58,    59,    61,    62,    64,    65,    67,
      68,    69,    70,    72,    73,    74,    75,    77,    78,    79,
      80,    82,    83,    85,    86,    88,    89,    90,    91,    93,
      94,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   107,   108,   110,   111,   113,   114,   116,   117,   119,
     120,   122,   123,   125,   126,   127,   129,   131,   133,   134,
     136,   137,   138,   139,   141,   143,   145,   147,   148,   149,
     150,   151,   152,   153,   154,   156,   157,   159,   160,   161,
     162,   163,   164,   166,   167,   169,   170,   172,   173,   175,
     177,   178,   180,   181,   182,   183,   184,   186,   188,   189,
     191,   192,   194,   195,   196,   197,   198,   199,   201,   202,
     203,   204,   205,   206,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   231,   232,   234,   235,
     236,   238,   239,   240,   242,   243,   245,   246,   247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "DO", "FREE", "ENDWHILE", "REPEAT", "UNTIL", "BREAK",
  "STR", "TYPE", "INIT", "NULL_VAL", "SELF", "NEW_KEY", "CONTINUE", "BEG",
  "READ", "WRITE", "END", "ALLOC", "DECL", "INT_TYPE", "STR_TYPE",
  "ENDDECL", "MAIN", "RETF", "ENDTYPE", "ENDCLASS", "CLASS", "DEL", "','",
  "'='", "OR", "AND", "EQTO", "NTEQ", "'>'", "GTEQ", "'<'", "LSEQ", "'+'",
  "'-'", "'*'", "'/'", "'%'", "NOT", "'.'", "'['", "']'", "'('", "')'",
  "'{'", "'}'", "';'", "$accept", "start", "tree", "main", "Mdef",
  "Mmfdef", "def", "mfdef", "code", "stms", "uncnd", "brk", "cont", "stm",
  "Gdecl", "Ldecl", "Cdecl", "Gmdcl", "Lmdcl", "Cmdcl", "type", "typeDef",
  "classDef", "udtype", "mclass", "Gdcl", "Ldcl", "Cdcl", "Gvlist",
  "Lvlist", "Cvlist", "plist", "ctrl", "inp", "opt", "asg", "dmaf", "ret",
  "delmem", "freemem", "ifstm", "whilestm", "exp", "lvaL", "fld", "mf",
  "id", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    44,    61,
     293,   294,   295,   296,    62,   297,    60,   298,    43,    45,
      42,    47,    37,   299,    46,    91,    93,    40,    41,   123,
     125,    59
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     286,     2,   278,    -7,    24,    68,  -120,  -120,   117,    -9,
     130,    75,     5,  -120,  -120,  -120,  -120,   298,   145,  -120,
     122,   123,    13,  -120,    -7,  -120,   117,  -120,   185,  -120,
     117,   130,   117,   228,   144,  -120,  -120,  -120,   -41,   -15,
     135,   183,   158,  -120,  -120,  -120,   167,  -120,   117,   117,
    -120,   117,     4,   230,  -120,   228,   232,     0,   235,  -120,
     202,   341,     6,   183,    52,  -120,  -120,   117,  -120,  -120,
    -120,  -120,   -12,    14,   196,  -120,   250,   -26,    46,   187,
    -120,   431,   259,  -120,  -120,    59,  -120,   264,    88,   220,
      56,  -120,   280,  -120,  -120,  -120,  -120,   228,  -120,   288,
     134,   408,   460,   240,   269,  -120,  -120,   238,    23,  -120,
    -120,   244,  -120,    95,   187,   246,  -120,   302,   265,  -120,
      70,    89,   165,   165,   603,   266,   603,   255,   273,   263,
     287,   292,   295,  -120,   165,   311,   433,   299,   347,  -120,
    -120,  -120,  -120,  -120,  -120,   328,   336,  -120,  -120,   356,
     345,  -120,  -120,   515,  -120,   340,   208,   398,  -120,   260,
    -120,   344,   269,   187,  -120,  -120,  -120,   402,   165,  -120,
     312,  -120,  -120,   355,   165,   165,   313,   357,  -120,  -120,
     334,   463,   403,  -120,  -120,    34,   488,   396,   628,   364,
     410,   628,    34,   165,   626,    34,   363,   366,  -120,  -120,
    -120,  -120,  -120,  -120,   267,   421,  -120,  -120,  -120,    77,
     374,   377,   101,  -120,   379,   380,   269,  -120,   796,   443,
     165,   445,  -120,   758,   603,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   446,   603,
     165,   165,    18,   394,   165,   165,   628,   393,  -120,   628,
      33,   405,   777,  -120,   118,   407,   628,   628,   399,   412,
     414,   416,  -120,  -120,   648,  -120,  -120,   268,   187,   420,
    -120,  -120,   422,  -120,   423,   813,   103,   427,  -120,   383,
     188,   825,   836,   845,   845,   528,   528,   466,   466,   261,
     261,  -120,  -120,  -120,   429,   518,   482,   670,   692,  -120,
    -120,   714,   736,  -120,   434,   444,   448,  -120,  -120,   628,
     628,   449,   500,   453,  -120,  -120,  -120,   104,   464,   269,
     187,  -120,   165,   165,  -120,   165,   603,   459,   603,   465,
     165,   471,   473,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,   480,   479,  -120,  -120,  -120,   481,   487,   269,   128,
     813,   133,   548,   531,  -120,   578,   540,  -120,   136,  -120,
    -120,  -120,  -120,  -120,   489,  -120,  -120,   493,   499,   501,
     503,  -120,  -120,  -120,  -120,  -120,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,    12,     0,     0,
       0,     0,     0,    65,    63,    64,    52,     0,     0,    58,
       0,     0,     0,     1,    63,    11,     0,    16,     0,    10,
       0,     0,     0,     0,     0,    66,    51,    57,    84,     0,
       0,     0,     0,    67,     9,    15,     0,     8,     0,     0,
       7,     0,     0,     0,    60,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     6,     4,     0,     5,    69,
      59,    86,     0,     0,     0,    82,     0,     0,    80,     0,
      56,     0,     0,    62,    73,     0,    18,     0,     0,     0,
       0,     3,     0,    75,    68,    83,    94,     0,    81,     0,
       0,     0,     0,     0,     0,    55,    61,    92,     0,    72,
      17,     0,    71,     0,     0,     0,    85,     0,     0,    78,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,    32,
      43,    44,    45,    46,    47,     0,     0,    95,    96,     0,
     146,   147,    54,     0,    14,     0,     0,     0,    76,     0,
      70,     0,     0,     0,    93,    79,    77,     0,     0,   144,
     155,   145,   143,     0,     0,     0,     0,   140,   141,   142,
       0,     0,     0,    33,    34,     0,     0,     0,    38,     0,
       0,    42,     0,     0,     0,     0,     0,     0,    27,    31,
      28,    29,    48,    49,     0,     0,    53,    13,    91,     0,
      89,     0,     0,    21,     0,     0,     0,   149,     0,     0,
     158,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,   150,    40,
       0,     0,     0,   107,     0,     0,    37,    41,     0,     0,
       0,     0,   105,   106,     0,   148,    90,     0,     0,     0,
      22,    20,     0,   154,   149,   157,     0,   150,   138,     0,
       0,   135,   136,   133,   134,   130,   132,   129,   131,   124,
     125,   126,   127,   128,   148,     0,     0,     0,     0,   110,
     111,     0,     0,    50,     0,     0,     0,   108,   109,    35,
      39,     0,     0,     0,   101,   100,    88,     0,     0,     0,
       0,    19,   158,     0,   139,   158,     0,     0,     0,     0,
     158,     0,     0,   120,   121,   122,   123,    97,    98,    99,
     102,   155,     0,   103,    87,    25,     0,     0,     0,     0,
     156,     0,     0,     0,   113,     0,     0,   114,     0,   118,
     119,   104,    26,    24,     0,   152,   153,     0,     0,     0,
       0,   151,    23,   112,   115,   116,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,   193,    48,   462,   195,   -72,   -93,   -51,
    -119,   468,   470,   -96,   121,  -112,   502,  -120,   -50,  -120,
      -2,  -120,   558,  -120,  -120,   567,   -49,   509,  -120,  -120,
    -120,   -63,  -120,  -120,  -120,  -120,  -120,  -120,   388,   390,
    -120,  -120,   106,  -120,   -59,  -120,   -79,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    26,    85,    27,    86,   103,   136,
     182,   183,   184,   139,     8,   104,    62,    17,    52,    81,
      28,     9,    10,    12,    22,    19,    54,    83,    39,    72,
     108,    77,   140,   141,   142,   143,   261,   144,   145,   146,
     147,   148,   275,   149,   177,   178,   179,   276
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      18,    90,   162,    70,    13,    73,    11,   187,    13,    34,
      13,   155,    97,   110,    56,    18,    57,    42,    13,     2,
       3,   161,   151,    58,    70,    20,    92,     4,    21,    14,
      15,    53,    98,    14,    15,    14,    15,   120,   121,    35,
     199,   110,   150,    14,    15,   151,    59,   151,    43,    93,
      53,   216,   153,    53,   129,    76,    13,   151,    75,    82,
      87,   157,    76,    13,    69,   150,    84,   150,    23,   214,
     215,    53,   205,   181,    94,   186,   299,   150,    48,    82,
      51,    14,    15,    87,   158,   199,    87,   205,    14,    15,
     199,   304,    13,   209,    97,   117,   212,    67,    76,    13,
      53,    99,   151,   100,    70,   280,   243,   151,    97,   151,
      89,    87,   151,   251,   115,    97,   255,    14,    15,   109,
     296,    13,   150,   272,    14,    15,   242,   150,   166,   150,
      30,    32,   150,   250,    33,   266,   254,   246,    13,    97,
     249,   323,    97,   167,   168,   151,    24,    15,   112,    38,
     199,    53,    49,   199,    76,   160,   319,    76,     2,   269,
     151,   324,   344,    14,    15,   150,   323,   151,   169,   170,
     151,   323,   205,   279,   323,   318,   307,   151,   151,    40,
     150,   171,    41,   199,   172,   173,   365,   150,   295,    46,
     150,   366,   119,    60,   371,   328,   329,   150,   150,   199,
     151,    25,    29,    55,   317,   309,   310,   353,   348,   356,
     101,    61,    13,   199,   199,   102,   151,    63,   174,    44,
     150,    45,   175,    47,    64,    50,   346,   347,   176,   180,
     151,   151,    13,   342,    71,    74,   150,    14,    15,    78,
     194,    65,    66,    45,    68,   349,    45,   151,   351,   151,
     150,   150,    95,   358,    96,   364,   199,    14,    15,   199,
      91,    79,    45,   107,    13,    76,   208,   150,   111,   150,
     169,   170,    13,   151,   218,   352,   151,   355,   125,   114,
     222,   223,    13,   171,   116,   258,   172,   173,   259,    14,
      15,   118,   101,   150,   260,   156,   150,    14,    15,   252,
     154,   159,    13,     1,   135,   163,   164,    14,    15,    16,
     264,   235,   236,   237,     2,     3,   188,   190,   211,   224,
     174,   165,     4,   185,   175,   200,   316,    14,    15,    36,
     189,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   239,    13,   297,   298,   191,   192,
     301,   302,   193,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   219,   168,   195,   220,
      14,    15,    80,   201,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   121,   122,   202,
     326,   327,   123,   124,   125,   204,   126,   203,   196,   205,
     207,   128,   210,   129,   213,   197,   217,   131,   132,   221,
     245,   238,   121,   122,   248,   241,   134,   123,   124,   125,
     135,   126,   247,   127,   256,   265,   128,   257,   129,   350,
     130,   267,   131,   132,   133,    13,   268,   121,   122,   270,
     271,   134,   123,   124,   125,   135,   126,   274,   196,   277,
     294,   128,   300,   129,   303,   197,   311,   131,   132,   198,
      14,    15,   105,   305,    13,   308,   134,   121,   122,   312,
     135,   313,   123,   124,   125,   240,   126,   314,   196,   320,
     322,   128,   321,   129,   325,   197,   330,   131,   132,    14,
      15,   152,   121,   122,   332,   337,   134,   123,   124,   125,
     135,   126,   244,   196,   341,   338,   128,   340,   129,   339,
     197,   343,   131,   132,   233,   234,   235,   236,   237,    13,
     354,   134,   121,   122,   345,   135,   357,   123,   124,   125,
     331,   126,   359,   196,   360,   168,   128,   361,   129,   368,
     197,   362,   131,   132,    14,    15,   206,   363,   370,   372,
     113,   134,   121,   122,   373,   135,   367,   123,   124,   125,
     374,   126,   375,   196,   376,    88,   128,    31,   129,   137,
     197,   138,   131,   132,   231,   232,   233,   234,   235,   236,
     237,   134,   121,   122,    37,   135,   369,   123,   124,   125,
     106,   126,   262,   196,   263,     0,   128,     0,   129,     0,
     197,     0,   131,   132,     0,     0,     0,   121,   122,     0,
       0,   134,   123,   124,   125,   135,   126,     0,   127,     0,
       0,   128,     0,   129,     0,   130,     0,   131,   132,     0,
       0,     0,   121,   122,     0,     0,   134,   123,   124,   125,
     135,   126,     0,     0,     0,     0,   128,     0,   129,     0,
       0,     0,   131,   132,     0,     0,     0,     0,     0,     0,
       0,   134,     0,     0,     0,   135,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,     0,     0,     0,     0,     0,     0,     0,   315,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,     0,     0,     0,     0,     0,     0,     0,
       0,   333,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     0,     0,     0,     0,     0,
       0,     0,     0,   334,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,     0,     0,     0,
       0,     0,     0,     0,     0,   335,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,     0,     0,     0,     0,     0,     0,   336,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,     0,     0,     0,     0,   278,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,     0,     0,     0,     0,   306,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,     0,
       0,     0,   273,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   229,
     230,   231,   232,   233,   234,   235,   236,   237
};

static const yytype_int16 yycheck[] =
{
       2,    64,   114,    52,     4,    55,     4,   126,     4,     4,
       4,   104,    38,    85,    55,    17,    57,     4,     4,    28,
      29,   114,   101,    38,    73,    32,    38,    36,     4,    29,
      30,    33,    58,    29,    30,    29,    30,   100,     4,    34,
     136,   113,   101,    29,    30,   124,    61,   126,    35,    61,
      52,   163,   102,    55,    20,    57,     4,   136,    58,    61,
      62,    38,    64,     4,    60,   124,    60,   126,     0,   162,
     163,    73,    54,   124,    60,   126,    58,   136,    30,    81,
      32,    29,    30,    85,    61,   181,    88,    54,    29,    30,
     186,    58,     4,   156,    38,    97,   159,    49,   100,     4,
     102,    55,   181,    57,   153,   224,   185,   186,    38,   188,
      58,   113,   191,   192,    58,    38,   195,    29,    30,    60,
     239,     4,   181,   216,    29,    30,   185,   186,    58,   188,
       9,    10,   191,   192,    59,    58,   195,   188,     4,    38,
     191,    38,    38,    54,    55,   224,    29,    30,    60,     4,
     246,   153,    31,   249,   156,    60,   268,   159,    28,    58,
     239,    58,    58,    29,    30,   224,    38,   246,     3,     4,
     249,    38,    54,   224,    38,   268,    58,   256,   257,    57,
     239,    16,    59,   279,    19,    20,    58,   246,   239,     4,
     249,    58,    58,    58,    58,     7,     8,   256,   257,   295,
     279,     8,     9,    59,   267,   256,   257,   326,   320,   328,
      23,    28,     4,   309,   310,    28,   295,    59,    53,    26,
     279,    26,    57,    30,    57,    32,   319,   320,   122,   123,
     309,   310,     4,   312,     4,     3,   295,    29,    30,     4,
     134,    48,    49,    48,    51,   322,    51,   326,   325,   328,
     309,   310,    56,   330,     4,   348,   352,    29,    30,   355,
      67,    59,    67,     4,     4,   267,    58,   326,     4,   328,
       3,     4,     4,   352,   168,   326,   355,   328,    11,    59,
     174,   175,     4,    16,     4,    18,    19,    20,    21,    29,
      30,     3,    23,   352,    27,    57,   355,    29,    30,   193,
      60,    57,     4,    17,    37,    59,     4,    29,    30,    31,
     204,    50,    51,    52,    28,    29,    61,    54,    58,     6,
      53,    56,    36,    57,    57,    26,    58,    29,    30,    31,
      57,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,    10,     4,   240,   241,    61,    57,
     244,   245,    57,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    54,    55,    57,    57,
      29,    30,    31,    26,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     4,     5,    61,
       7,     8,     9,    10,    11,    39,    13,    61,    15,    54,
      60,    18,     4,    20,    60,    22,     4,    24,    25,    54,
      14,    54,     4,     5,     4,    12,    33,     9,    10,    11,
      37,    13,    58,    15,    61,     4,    18,    61,    20,   323,
      22,    57,    24,    25,    26,     4,    59,     4,     5,    60,
      60,    33,     9,    10,    11,    37,    13,     4,    15,     4,
       4,    18,    58,    20,    61,    22,    57,    24,    25,    26,
      29,    30,    31,    58,     4,    58,    33,     4,     5,    57,
      37,    57,     9,    10,    11,    12,    13,    61,    15,    59,
      57,    18,    60,    20,    57,    22,    57,    24,    25,    29,
      30,    31,     4,     5,    12,    61,    33,     9,    10,    11,
      37,    13,    14,    15,     4,    61,    18,    58,    20,    61,
      22,    58,    24,    25,    48,    49,    50,    51,    52,     4,
      61,    33,     4,     5,    60,    37,    61,     9,    10,    11,
      12,    13,    61,    15,    61,    55,    18,    58,    20,     8,
      22,    60,    24,    25,    29,    30,    31,    60,     8,    60,
      88,    33,     4,     5,    61,    37,     8,     9,    10,    11,
      61,    13,    61,    15,    61,    63,    18,     9,    20,   101,
      22,   101,    24,    25,    46,    47,    48,    49,    50,    51,
      52,    33,     4,     5,    17,    37,     8,     9,    10,    11,
      81,    13,   204,    15,   204,    -1,    18,    -1,    20,    -1,
      22,    -1,    24,    25,    -1,    -1,    -1,     4,     5,    -1,
      -1,    33,     9,    10,    11,    37,    13,    -1,    15,    -1,
      -1,    18,    -1,    20,    -1,    22,    -1,    24,    25,    -1,
      -1,    -1,     4,     5,    -1,    -1,    33,     9,    10,    11,
      37,    13,    -1,    -1,    -1,    -1,    18,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    37,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    -1,
      -1,    -1,    56,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    28,    29,    36,    63,    64,    65,    76,    83,
      84,     4,    85,     4,    29,    30,    31,    79,    82,    87,
      32,     4,    86,     0,    29,    65,    66,    68,    82,    65,
      76,    84,    76,    59,     4,    34,    31,    87,     4,    90,
      57,    59,     4,    35,    65,    68,     4,    65,    66,    76,
      65,    66,    80,    82,    88,    59,    55,    57,    38,    61,
      58,    28,    78,    59,    57,    65,    65,    66,    65,    60,
      88,     4,    91,    80,     3,    58,    82,    93,     4,    59,
      31,    81,    82,    89,    60,    67,    69,    82,    78,    58,
      93,    65,    38,    61,    60,    56,     4,    38,    58,    55,
      57,    23,    28,    70,    77,    31,    89,     4,    92,    60,
      69,     4,    60,    67,    59,    58,     4,    82,     3,    58,
      93,     4,     5,     9,    10,    11,    13,    15,    18,    20,
      22,    24,    25,    26,    33,    37,    71,    73,    74,    75,
      94,    95,    96,    97,    99,   100,   101,   102,   103,   105,
     106,   108,    31,    80,    60,    70,    57,    38,    61,    57,
      60,    70,    77,    59,     4,    56,    58,    54,    55,     3,
       4,    16,    19,    20,    53,    57,   104,   106,   107,   108,
     104,    71,    72,    73,    74,    57,    71,    72,    61,    57,
      54,    61,    57,    57,   104,    57,    15,    22,    26,    75,
      26,    26,    61,    61,    39,    54,    31,    60,    58,    93,
       4,    58,    93,    60,    70,    70,    77,     4,   104,    54,
      57,    54,   104,   104,     6,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    54,    10,
      12,    12,   106,   108,    14,    14,    71,    58,     4,    71,
     106,   108,   104,    61,   106,   108,    61,    61,    18,    21,
      27,    98,   100,   101,   104,     4,    58,    57,    59,    58,
      60,    60,    70,    56,     4,   104,   109,     4,    58,    71,
      72,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,     4,    71,    72,   104,   104,    58,
      58,   104,   104,    61,    58,    58,    58,    58,    58,    71,
      71,    57,    57,    57,    61,    61,    58,    93,    70,    77,
      59,    60,    57,    38,    58,    57,     7,     8,     7,     8,
      57,    12,    12,    61,    61,    61,    61,    61,    61,    61,
      58,     4,   108,    58,    58,    60,    70,    70,    77,   109,
     104,   109,    71,    72,    61,    71,    72,    61,   109,    61,
      61,    58,    60,    60,    70,    58,    58,     8,     8,     8,
       8,    58,    60,    61,    61,    61,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    73,    73,    74,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    83,    84,    85,    85,
      86,    86,    86,    86,    87,    88,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      97,    97,    98,    98,    98,    98,    98,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     4,     4,     4,     3,     3,     3,
       2,     2,     1,     8,     7,     2,     1,     2,     1,     9,
       8,     7,     8,     9,     8,     7,     8,     3,     3,     3,
       2,     2,     1,     1,     1,     4,     3,     3,     2,     4,
       3,     3,     2,     1,     1,     1,     1,     1,     2,     2,
       4,     3,     2,     3,     2,     3,     2,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     3,     3,     5,     4,
       6,     5,     5,     4,     3,     3,     3,     6,     5,     6,
       3,     4,     3,     4,     1,     3,     1,     6,     5,     3,
       4,     3,     1,     4,     2,     1,     1,     5,     5,     5,
       4,     4,     3,     3,     4,     1,     1,     3,     4,     4,
       4,     4,     8,     6,     6,     8,     8,     8,     6,     6,
       5,     5,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     6,     6,     6,     4,     1,     3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 45 "syntax.y" /* yacc.c:1646  */
    {return (yyvsp[0]);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefLinkNode((yyvsp[-1]),(yyvsp[0]));}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 48 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 49 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefLinkNode((yyvsp[-1]),(yyvsp[0]));}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefLinkNode((yyvsp[-1]),(yyvsp[0]));}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 51 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 52 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 53 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefLinkNode((yyvsp[-1]),(yyvsp[0]));}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 54 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 55 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 56 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 58 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefNode(makeDType((yyvsp[-7])),(yyvsp[-6]),NULL,(yyvsp[-2]),(yyvsp[-1]));}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 59 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefNode(makeDType((yyvsp[-6])),(yyvsp[-5]),NULL,NULL,(yyvsp[-1]));}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 61 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefLinkNode((yyvsp[-1]),(yyvsp[0]));}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 62 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 64 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefLinkNode((yyvsp[-1]),(yyvsp[0]));}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 65 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 67 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefNode((yyvsp[-8]),(yyvsp[-7]),(yyvsp[-5]),(yyvsp[-2]),(yyvsp[-1]));}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 68 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefNode((yyvsp[-7]),(yyvsp[-6]),(yyvsp[-4]),NULL,(yyvsp[-1]));}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 69 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefNode((yyvsp[-6]),(yyvsp[-5]),NULL,NULL,(yyvsp[-1]));}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 70 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnDefNode((yyvsp[-7]),(yyvsp[-6]),NULL,(yyvsp[-2]),(yyvsp[-1]));}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 72 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeMemFnNode((yyvsp[-8]),(yyvsp[-7]),(yyvsp[-5]),(yyvsp[-2]),(yyvsp[-1]));}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 73 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeMemFnNode((yyvsp[-7]),(yyvsp[-6]),(yyvsp[-4]),NULL,(yyvsp[-1]));}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 74 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeMemFnNode((yyvsp[-6]),(yyvsp[-5]),NULL,NULL,(yyvsp[-1]));}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 75 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeMemFnNode((yyvsp[-7]),(yyvsp[-6]),NULL,(yyvsp[-2]),(yyvsp[-1]));}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 77 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 78 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 79 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 82 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeConNode((yyvsp[-1]),(yyvsp[0]));}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 83 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 85 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 86 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 88 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode((yyvsp[-3]),(yyvsp[0]),BREAK_LOOP);}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 89 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode(NULL,(yyvsp[0]),BREAK_LOOP);}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 90 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode((yyvsp[-2]),NULL,BREAK_LOOP);}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 91 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode(NULL,NULL,BREAK_LOOP);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 93 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode((yyvsp[-3]),(yyvsp[0]),CONT_LOOP);}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 94 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode(NULL,(yyvsp[0]),CONT_LOOP);}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 95 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode((yyvsp[-2]),NULL,CONT_LOOP);}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 96 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeUNode(NULL,NULL,CONT_LOOP);}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 98 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 99 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 100 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 101 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 102 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 103 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 104 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 105 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNode4DMA(DMA_INIT);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 107 "syntax.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 108 "syntax.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 110 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 111 "syntax.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 113 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 114 "syntax.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 119 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkLDecLines((yyvsp[-1]),(yyvsp[0]));}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 120 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 122 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkLDecLines((yyvsp[-1]),(yyvsp[0]));}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 123 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 125 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeDType((yyvsp[0]));}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 126 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeDType((yyvsp[0]));}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 127 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeDType((yyvsp[0]));}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 133 "syntax.y" /* yacc.c:1646  */
    {createNewDType((yyvsp[-3]),(yyvsp[-1]));}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 134 "syntax.y" /* yacc.c:1646  */
    {createNewDType((yyvsp[-3]),(yyvsp[-1]));}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 136 "syntax.y" /* yacc.c:1646  */
    {createNewClass((yyvsp[-4]),(yyvsp[-2]),(yyvsp[-1]));}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 137 "syntax.y" /* yacc.c:1646  */
    {createNewClass((yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 138 "syntax.y" /* yacc.c:1646  */
    {createNewClass((yyvsp[-4]),(yyvsp[-2]),(yyvsp[-1]));}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 139 "syntax.y" /* yacc.c:1646  */
    {createNewClass((yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 141 "syntax.y" /* yacc.c:1646  */
    {GDeclare((yyvsp[-2]),(yyvsp[-1]));}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 143 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeALocDecLine((yyvsp[-2]),(yyvsp[-1]));}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 145 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeALocDecLine((yyvsp[-2]),(yyvsp[-1]));}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 147 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode((yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 148 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode((yyvsp[-4]),(yyvsp[-2]),NULL);}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 149 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeGDeclLineNode((yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 150 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeGDeclLineNode((yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 151 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode(NULL,(yyvsp[-3]),(yyvsp[-1]));}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 152 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode(NULL,(yyvsp[-2]),NULL);}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 153 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeGDeclLineNode(NULL,(yyvsp[-3]),(yyvsp[-1]));}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 154 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeGDeclLineNode(NULL,(yyvsp[0]),NULL);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 156 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeLDeclLineNode((yyvsp[-2]),(yyvsp[0]));}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 157 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeLDeclLineNode(NULL,(yyvsp[0]));}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 159 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode((yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 160 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode((yyvsp[-4]),(yyvsp[-2]),NULL);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 161 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeLDeclLineNode((yyvsp[-2]),(yyvsp[0]));}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 162 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode(NULL,(yyvsp[-3]),(yyvsp[-1]));}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 163 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnLinkNode(NULL,(yyvsp[-2]),NULL);}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 164 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeLDeclLineNode(NULL,(yyvsp[0]));}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 166 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeParamLinkNode((yyvsp[-3]),(yyvsp[-1]),(yyvsp[0]));}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 167 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeParamLinkNode(NULL,(yyvsp[-1]),(yyvsp[0]));}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 169 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 170 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 172 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeIONode(IO_READ,(yyvsp[-2]));}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 173 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeIONode(IO_READ,(yyvsp[-2]));}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 175 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeIONode(IO_WRITE,(yyvsp[-2]));}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 177 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("=",(yyvsp[-3]),(yyvsp[-1]));}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 178 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("=",(yyvsp[-3]),(yyvsp[-1]));}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 180 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNode4DMA(DMA_INIT);}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 181 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNode4DMA(DMA_ALLOC);}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 182 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNewNode((yyvsp[-1]));}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 183 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 184 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 186 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeRetNode((yyvsp[-1]));}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 188 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNode4DMAFree((yyvsp[-1]));}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 189 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNode4DMAFree((yyvsp[-1]));}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 191 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNode4DMAFree((yyvsp[-1]));}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 192 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNode4DMAFree((yyvsp[-1]));}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 194 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-6]),(yyvsp[-4]),(yyvsp[-2]),IF_ELSE);}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 195 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-4]),(yyvsp[-2]),NULL,SIMPLE_IF);}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 196 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-4]),(yyvsp[-2]),NULL,SIMPLE_IF);}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 197 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-6]),(yyvsp[-4]),(yyvsp[-2]),IF_ELSE);}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 198 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-6]),(yyvsp[-4]),(yyvsp[-2]),IF_ELSE);}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 199 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-6]),(yyvsp[-4]),(yyvsp[-2]),IF_ELSE);}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 201 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-4]),(yyvsp[-2]),NULL,WHILE_LOOP);}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 202 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-4]),(yyvsp[-2]),NULL,WHILE_LOOP);}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 203 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-3]),(yyvsp[-1]),NULL,DO_LOOP);}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 204 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-3]),(yyvsp[-1]),NULL,DO_LOOP);}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 205 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-3]),(yyvsp[-1]),NULL,REPEAT_LOOP);}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 206 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeCtrlNode((yyvsp[-3]),(yyvsp[-1]),NULL,REPEAT_LOOP);}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 208 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("+",(yyvsp[-2]),(yyvsp[0]));}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 209 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("-",(yyvsp[-2]),(yyvsp[0]));}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 210 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("*",(yyvsp[-2]),(yyvsp[0]));}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 211 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("/",(yyvsp[-2]),(yyvsp[0]));}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 212 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("%%",(yyvsp[-2]),(yyvsp[0]));}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 213 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("<",(yyvsp[-2]),(yyvsp[0]));}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 214 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode(">",(yyvsp[-2]),(yyvsp[0]));}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 215 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("=<",(yyvsp[-2]),(yyvsp[0]));}
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 216 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("=>",(yyvsp[-2]),(yyvsp[0]));}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 217 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("==",(yyvsp[-2]),(yyvsp[0]));}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 218 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("=!",(yyvsp[-2]),(yyvsp[0]));}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 219 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("L|",(yyvsp[-2]),(yyvsp[0]));}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 220 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("L&",(yyvsp[-2]),(yyvsp[0]));}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 221 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeOpNode("!",(yyvsp[0]),NULL);}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 222 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 223 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeFnCallNode((yyvsp[-3]),(yyvsp[-1]));}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 224 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 225 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 226 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 227 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeNullNode();}
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 228 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 229 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 231 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 232 "syntax.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 234 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkFldNode((yyvsp[-2]),(yyvsp[0]));}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 235 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkFldNode((yyvsp[-2]),(yyvsp[0]));}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 236 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkFldNode((yyvsp[-2]),(yyvsp[0]));}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 238 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkFldNode((yyvsp[-5]),makeMemFnCallNode((yyvsp[-3]),(yyvsp[-1])));}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 239 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkFldNode((yyvsp[-5]),makeMemFnCallNode((yyvsp[-3]),(yyvsp[-1])));}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 240 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkFldNode((yyvsp[-5]),makeMemFnCallNode((yyvsp[-3]),(yyvsp[-1])));}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 242 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkIdNode((yyvsp[-3]),(yyvsp[-1]));}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 243 "syntax.y" /* yacc.c:1646  */
    {(yyval)=linkIdNode((yyvsp[0]),NULL);}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 245 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeArgLinkNode((yyvsp[-2]),(yyvsp[0]));}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 246 "syntax.y" /* yacc.c:1646  */
    {(yyval)=makeArgLinkNode(NULL,(yyvsp[0]));}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 247 "syntax.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2570 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 249 "syntax.y" /* yacc.c:1906  */


yyerror(char *err){
   	printf("Parse Error:%s\n",err);
    remove("x.xobj");
    exit(1);
}
int main(int argc,char *argv[]){
    yyin=fopen(argv[1],"r");
    yyparse();
    //codeAsmble(yyparse());
   	return 1;
}
