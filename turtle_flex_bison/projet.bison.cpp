/* A Bison parser, made by GNU Bison 3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "turtle.bison" /* yacc.c:338  */



#include "turtle_class.h"


// FLEX
extern FILE *yyin;
extern int yylex ();
int yyerror(const char *s) { printf("%s\n", s); return 0;}


// map des variables
map<string, double> variables;

// fichier dans lequel on affiche

// fstream file("bite.html", ios_base::out);
fstream file("./turtle.svg", ios_base::out);

// Stockage des instructions
vector<pair<int,double>> instructions;

// Stockage des couleurs
map<int, vector<string>> zoli ;
map<int, int> colorcount;

// Stockage des labels pour les goto
map<string, int> labels ;
string labelTosearch;

// Stockage des FOR on stock l'ic et le nombre de rep
map<int, int> fors ;


size_t ic = 0;   // compteur instruction 
inline void ins(int c, double d) { instructions.push_back(make_pair(c, d)); ic++;};

	



template< typename T >
std::string int_to_hex( T i )
{
	std::stringstream stream;
	  stream << std::setfill ('0') << std::setw(2) 
	<< std::hex << i;
	return stream.str();
}


typedef struct adr {
	int ic_goto; 
	int ic_false;
} t_adresse; 



#line 129 "projet.bison.cpp" /* yacc.c:338  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
   by #include "projet.bison.hpp".  */
#ifndef YY_YY_PROJET_BISON_HPP_INCLUDED
# define YY_YY_PROJET_BISON_HPP_INCLUDED
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
    SI = 258,
    ALORS = 259,
    SINON = 260,
    FINSI = 261,
    JMP = 262,
    JNZ = 263,
    OUT = 264,
    LABEL = 265,
    GOTO = 266,
    STRING = 267,
    NUMBER = 268,
    IDENTIFIER = 269,
    VAR = 270,
    POUR = 271,
    FAIRE = 272,
    FINPOUR = 273,
    PATH = 274,
    ENDPATH = 275,
    TAILLE = 276,
    LARGEUR = 277,
    COULEUR = 278,
    COULEURRGB = 279,
    FORWARD = 280,
    ROTATE = 281,
    PENDOWN = 282,
    PENUP = 283,
    GOTOXY = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 62 "turtle.bison" /* yacc.c:353  */

	double valeur;
	char nom[100];
	t_adresse adresse;
	char chaine[100];

#line 209 "projet.bison.cpp" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJET_BISON_HPP_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  33
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  69

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    32,    30,     2,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   118,   118,   119,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   138,
     141,   145,   138,   148,   149,   148,   151,   154,   155,   156,
     157,   158,   159,   160
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SI", "ALORS", "SINON", "FINSI", "JMP",
  "JNZ", "OUT", "LABEL", "GOTO", "STRING", "NUMBER", "IDENTIFIER", "VAR",
  "POUR", "FAIRE", "FINPOUR", "PATH", "ENDPATH", "TAILLE", "LARGEUR",
  "COULEUR", "COULEURRGB", "FORWARD", "ROTATE", "PENDOWN", "PENUP",
  "GOTOXY", "'+'", "'-'", "'*'", "'/'", "'\\n'", "'='", "'('", "')'",
  "$accept", "bloc", "instruction", "$@1", "$@2", "$@3", "$@4", "$@5",
  "expression", YY_NULLPTR
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
      43,    45,    42,    47,    10,    61,    40,    41
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -45,    30,   -45,    -7,   -11,    10,   -45,   -30,    -9,   -45,
     -45,    -7,    -7,   -10,    -7,    -7,   -45,   -45,    -7,    -7,
      -2,   -13,   -45,    83,   -45,   -45,    -7,    -7,    68,   -13,
     -45,    68,   -13,   -13,    68,    58,   -45,    -7,    -7,    -7,
      -7,   -45,   -13,    75,   -13,    68,   -13,   -45,     6,     6,
     -45,   -45,    41,   -45,   -13,    13,    31,   -45,   -45,    51,
      51,    55,    45,    34,   -45,   -45,    51,    63,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    26,     1,     0,     0,     0,    32,    33,     0,    10,
      11,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     4,    33,     0,     7,     8,     0,     0,     0,    13,
      16,     0,    14,    15,     0,     0,     2,     0,     0,     0,
       0,    19,    18,     0,    12,     0,     9,    31,    27,    28,
      29,    30,     0,    23,    17,     0,     0,     3,     3,    20,
      24,     0,     0,     0,    25,     3,    21,     0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -44,   -45,   -45,   -45,   -45,   -45,   -45,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    20,    52,    61,    67,    56,    62,    21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      23,    24,    30,     6,    22,    26,     6,    22,    28,    29,
      31,    32,    33,    59,    60,    34,    35,    37,    38,    39,
      40,    66,    25,    42,    43,    44,    19,    27,    45,    19,
       2,    46,    36,     3,    48,    49,    50,    51,    39,    40,
       4,     5,    54,     6,     7,    55,     8,    57,    58,     9,
      10,    11,    12,    13,     3,    14,    15,    16,    17,    18,
      63,     4,     5,    64,     6,     7,    19,     8,    65,    68,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     6,    22,     0,     0,   -26,     0,    19,    37,    38,
      39,    40,     0,     0,     0,    47,     0,     0,    37,    38,
      39,    40,     0,     0,    19,    37,    38,    39,    40,     0,
       0,     0,    53,    37,    38,    39,    40,    41
};

static const yytype_int8 yycheck[] =
{
       3,    12,    12,    13,    14,    35,    13,    14,    11,    12,
      13,    14,    15,    57,    58,    18,    19,    30,    31,    32,
      33,    65,    12,    26,    27,    28,    36,    36,    31,    36,
       0,    34,    34,     3,    37,    38,    39,    40,    32,    33,
      10,    11,    45,    13,    14,     4,    16,    34,    17,    19,
      20,    21,    22,    23,     3,    25,    26,    27,    28,    29,
       5,    10,    11,    18,    13,    14,    36,    16,    34,     6,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    13,    14,    -1,    -1,    34,    -1,    36,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    36,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,     0,     3,    10,    11,    13,    14,    16,    19,
      20,    21,    22,    23,    25,    26,    27,    28,    29,    36,
      40,    46,    14,    46,    12,    12,    35,    36,    46,    46,
      12,    46,    46,    46,    46,    46,    34,    30,    31,    32,
      33,    34,    46,    46,    46,    46,    46,    37,    46,    46,
      46,    46,    41,    37,    46,     4,    44,    34,    17,    39,
      39,    42,    45,     5,    18,    34,    39,    43,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      42,    43,    40,    44,    45,    40,    40,    46,    46,    46,
      46,    46,    46,    46
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     1,     1,     1,     2,     2,     3,
       1,     1,     3,     2,     2,     2,     2,     4,     3,     0,
       0,     0,    13,     0,     0,     9,     0,     3,     3,     3,
       3,     3,     1,     1
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    default: /* Avoid compiler warnings. */
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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
        case 4:
#line 122 "turtle.bison" /* yacc.c:1645  */
    { ins(OUT,0); 	                                                            }
#line 1340 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 5:
#line 123 "turtle.bison" /* yacc.c:1645  */
    { ins(PENDOWN, 0);                                                          }
#line 1346 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 6:
#line 124 "turtle.bison" /* yacc.c:1645  */
    { ins(PENUP  , 0);                                                          }
#line 1352 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 7:
#line 125 "turtle.bison" /* yacc.c:1645  */
    { labels[(yyvsp[0].chaine)] = ic; ins(LABEL  , 0);			                                }
#line 1358 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 8:
#line 126 "turtle.bison" /* yacc.c:1645  */
    { labelTosearch=(yyvsp[0].chaine); ins(GOTO  , 0);			                                }
#line 1364 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 9:
#line 127 "turtle.bison" /* yacc.c:1645  */
    { ins(GOTOXY   , 0);                                                        }
#line 1370 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 10:
#line 128 "turtle.bison" /* yacc.c:1645  */
    { ins(PATH 	   , 0);                                                        }
#line 1376 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 11:
#line 129 "turtle.bison" /* yacc.c:1645  */
    { ins(ENDPATH  , 0);                                                        }
#line 1382 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 12:
#line 130 "turtle.bison" /* yacc.c:1645  */
    { ins(TAILLE , 0); /*cout << "taille " << $2 << ' ' << $3 << endl;    */    }
#line 1388 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 13:
#line 131 "turtle.bison" /* yacc.c:1645  */
    { ins(LARGEUR, 0); /*cout << "avance " << $2 << endl;     */                }
#line 1394 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 14:
#line 132 "turtle.bison" /* yacc.c:1645  */
    { ins(FORWARD, 0); /*cout << "avance " << $2 << endl;     */                }
#line 1400 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 15:
#line 133 "turtle.bison" /* yacc.c:1645  */
    { ins(ROTATE , 0); /*cout << "tourne " << $2 << endl;     */                }
#line 1406 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 16:
#line 134 "turtle.bison" /* yacc.c:1645  */
    { ins(COULEUR, 0); zoli[ic-1].push_back((yyvsp[0].chaine));  								}
#line 1412 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 17:
#line 135 "turtle.bison" /* yacc.c:1645  */
    { ins(COULEURRGB, 0);														}
#line 1418 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 18:
#line 136 "turtle.bison" /* yacc.c:1645  */
    { ins(VAR , 0); 															}
#line 1424 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 19:
#line 138 "turtle.bison" /* yacc.c:1645  */
    { (yyvsp[-2].adresse).ic_goto = ic;  
					   ins (JNZ,0);
					   }
#line 1432 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 20:
#line 141 "turtle.bison" /* yacc.c:1645  */
    { (yyvsp[-6].adresse).ic_false = ic;
					   ins (JMP,0);
					   instructions[(yyvsp[-6].adresse).ic_goto].second = ic;  
					   }
#line 1441 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 21:
#line 145 "turtle.bison" /* yacc.c:1645  */
    { instructions[(yyvsp[-10].adresse).ic_false].second = ic; }
#line 1447 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 22:
#line 146 "turtle.bison" /* yacc.c:1645  */
    {   }
#line 1453 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 23:
#line 148 "turtle.bison" /* yacc.c:1645  */
    { fors[ic]=(yyvsp[-1].valeur); ins(POUR  , 0); }
#line 1459 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 24:
#line 149 "turtle.bison" /* yacc.c:1645  */
    {   }
#line 1465 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 25:
#line 150 "turtle.bison" /* yacc.c:1645  */
    { ins(FINPOUR  , 0);  }
#line 1471 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 27:
#line 154 "turtle.bison" /* yacc.c:1645  */
    { ins('+', 0);}
#line 1477 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 28:
#line 155 "turtle.bison" /* yacc.c:1645  */
    { ins('-', 0);}
#line 1483 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 29:
#line 156 "turtle.bison" /* yacc.c:1645  */
    { ins('*', 0);}
#line 1489 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 30:
#line 157 "turtle.bison" /* yacc.c:1645  */
    { ins('/', 0);}
#line 1495 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 31:
#line 158 "turtle.bison" /* yacc.c:1645  */
    { }
#line 1501 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 32:
#line 159 "turtle.bison" /* yacc.c:1645  */
    { ins(NUMBER, (yyvsp[0].valeur));}
#line 1507 "projet.bison.cpp" /* yacc.c:1645  */
    break;

  case 33:
#line 160 "turtle.bison" /* yacc.c:1645  */
    { ins(IDENTIFIER, variables[(yyvsp[0].nom)]);}
#line 1513 "projet.bison.cpp" /* yacc.c:1645  */
    break;


#line 1517 "projet.bison.cpp" /* yacc.c:1645  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
#line 165 "turtle.bison" /* yacc.c:1903  */



// Pour imprimer le code généré de manière plus lisible 
string nom(int instruction){
switch (instruction){
	case '+'     	: return "ADD";
	case '-'     	: return "SUB";
	case '*'     	: return "MUL";
	case '/'     	: return "DIV";
	case NUMBER  	: return "NUM";
	case LABEL  	: return "LBL";
	case GOTO   	: return "GOT";
	case GOTOXY  	: return "GXY";
	case PATH	  	: return "PTH";
	case ENDPATH  	: return "EPH";
	case TAILLE  	: return "TAL";
	case LARGEUR  	: return "LRG";
	case IDENTIFIER : return "IDE";
	case VAR 		: return "VAR";
	case COULEUR  	: return "CLR";
	case COULEURRGB : return "RGB";
	case FORWARD  	: return "FWD";
	case PENDOWN	: return "PDN";
	case PENUP	  	: return "PUP";
	case ROTATE		: return "ROT";
	case POUR     	: return "FOR";	
	case FINPOUR  	: return "FFR";	
	case OUT     	: return "OUT";	
	case JNZ     	: return "JNZ";   // Jump if not zero
	case JMP     	: return "JMP";   // Unconditional Jump
	default  		: return to_string (instruction);
}
}

void print_program(){
	cout << "==== CODE GENERE ====" << endl;
	int i = 0;
	for (auto ins : instructions )
		cout << i++ << '\t' << nom(ins.first) << "\t" << ins.second << endl;
	cout << "=====================" << endl;  
}

double depiler(vector<double> &pile) {
	double t = pile[pile.size()-1];
  //cout << "Dépiler " << t << endl; 
	pile.pop_back();
	return t;
}


void run_program(turtle my_turtle){
	vector<double> pile; 
	double x,y;
	double r,g,b;
	string c;

	cout << "===== EXECUTION =====" << endl;
	ic = 0;
	while ( ic < instructions.size() ){
		auto ins = instructions[ic];
		cout << ic << '\t' << nom(ins.first) << "\t" << ins.second << endl;

		switch(ins.first){

			case '+':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y+x);
			ic++;
			break;
			
			case '-':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y-x);
			ic++;
			break;

			case '*':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y*x);
			ic++;
			break;

			case '/':
			x = depiler(pile);
			y = depiler(pile);
			pile.push_back(y/x);
			ic++;
			break;

			case FORWARD:
			x = depiler(pile);
			if(my_turtle.penDown){
				if(!my_turtle.path){
					::file << "<line x1='"<< my_turtle.x << "' y1='"<< my_turtle.y << "' x2='" << my_turtle.x+cos(my_turtle.theta)*x <<"' y2='"<< my_turtle.y+sin(my_turtle.theta)*x <<"' fill='#00FF00' stroke=" << my_turtle.couleur << " stroke-width=\"" << my_turtle.largeur << "\" stroke-miterlimit='10' stroke-dasharray='1000' stroke-dashoffset='0' > </line>  \n" ;
					// file << "<line x1='"<< x << "' y1='"<< y << "' x2='" << x+cos(theta)*$2 <<"' y2='"<< y+sin(theta)*$2 <<"'  fill='#FFFFFF' stroke='#000000' stroke-width='4' stroke-miterlimit='10' stroke-dasharray='1000' stroke-dashoffset='0'><animate attributeName='x' from='0' to='200' dur='5s' /><animate attributeType='CSS' attributeName='stroke-dashoffset' from='1000' to='0' dur='5s' <!--begin='" << 2*trait <<"s;'--> /><!--animate id='op' attributeType='CSS' attributeName='opacity'from='1' to='0' dur='1s' begin='0s' /--> </line>" ;
				}
				else{
					::file << my_turtle.x+cos(my_turtle.theta)*x << " " << my_turtle.y+sin(my_turtle.theta)*x << " " ;
				}

			}
			my_turtle.avancer(x);

			ic++;
			break;

			case NUMBER :
			pile.push_back(ins.second);
			ic++;
			break;
			
			case LARGEUR :
			x = depiler(pile);
			my_turtle.largeur = x;
			ic++;
			break;

			case LABEL :
			ic++;
			break;

			case GOTO :
			
			if(labels[labelTosearch]){
				std::cout << labelTosearch  << " " << labels[labelTosearch]  << '\n';
				ic  = labels[labelTosearch]  ;
			}
			ic++;
			break;

			case PENDOWN :
			my_turtle.baisser();
			ic++;
			break;

			case PENUP :
			my_turtle.lever();
			ic++;
			break;

			case GOTOXY :
			x = depiler(pile);
			y = depiler(pile);

			my_turtle.x = x;
			my_turtle.y = y; 
			ic++;
			break;

			case PATH	  :
			my_turtle.path = true ;
			::file << "<path d=\"M" << my_turtle.x << " " << my_turtle.y << " "   ;							
			break;

			case ENDPATH  :
			my_turtle.path = false ;
			::file << "stroke=\"" << my_turtle.couleur <<"\" stroke-width=\"" << my_turtle.largeur << "\" fill=\"" << my_turtle.couleur << "\" />"    ;		
			break;


			case TAILLE :
			x = depiler(pile);
			y = depiler(pile);

			my_turtle.taile_x= x;
			my_turtle.taile_y= y; 
			ic++;
			break;

			case COULEUR :
			
			my_turtle.couleur= zoli[ic][colorcount[ic]++]; 
			ic++;
			break;


			case COULEURRGB :
			r = depiler(pile);
			g = depiler(pile);
			b = depiler(pile);
			std::cout << r << " " << g << " " << b  << std::endl;
			zoli[ic].push_back("\"#"+int_to_hex((int)r%255)+
									 int_to_hex((int)g%255)+
				   				     int_to_hex((int)b%255)+ "\"");
			my_turtle.couleur= zoli[ic][colorcount[ic]++]; 
			ic++;
			break;





			case ROTATE :
			x = depiler(pile);
			my_turtle.tourner(x);
			ic++;
			break;
			
			case IDENTIFIER :
			pile.push_back(ins.second);
			ic++;
			break;

			case VAR :

			// x = depiler(pile);
			// variables[ins.first] = x;
			// pile.push_back(x);

			ic++;
			break;

			case POUR : // TO DO
			ic++;
			break;

			case FINPOUR : {
				auto it = fors.rbegin();
				if(it->second >= 0){
					ic = it->first;
					it->second--;
				}
				else{
					ic++;
				}
				break;			
			}

			case JMP :
			ic = ins.second;
			break;

			case JNZ :
			x = depiler(pile);
			ic = ( x ? ic + 1 : ins.second);
			break;

			case OUT :
				cout << "Résultat : " << depiler(pile) << endl;
				ic++;
				break;
			
			default :
			std::cout << "oups :" << ic << "\t" << nom(ins.first) << std::endl;
		}
	}
	cout << "=====================" << endl;
	return;  
}




int main(int argc, char **argv) {

	
	// on ajoute l'entête du fichier
	file << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n<svg width='200mm' height='200mm' viewBox='0 0 1000 1000' id='svg1'>\n" ;
	
	// on crée la turtle
	turtle my_turtle;
	
	// initialisation de la couleur sur Noir
	zoli[0].push_back("\"#000000\"");
	colorcount[0] = 0;


	if ( argc > 1 )
		yyin = fopen( argv[1], "r" );
	else
		yyin = stdin;

	yyparse();

	print_program();

	run_program(my_turtle);

	file << "</svg>\n";

} 
