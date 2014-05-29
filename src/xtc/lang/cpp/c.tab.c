
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */


/* Line 189 of yacc.c  */
#line 73 "c.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO = 258,
     DOUBLE = 259,
     INT = 260,
     STRUCT = 261,
     BREAK = 262,
     ELSE = 263,
     LONG = 264,
     SWITCH = 265,
     CASE = 266,
     ENUM = 267,
     REGISTER = 268,
     TYPEDEF = 269,
     CHAR = 270,
     EXTERN = 271,
     RETURN = 272,
     UNION = 273,
     CONST = 274,
     FLOAT = 275,
     SHORT = 276,
     UNSIGNED = 277,
     CONTINUE = 278,
     FOR = 279,
     SIGNED = 280,
     VOID = 281,
     DEFAULT = 282,
     GOTO = 283,
     SIZEOF = 284,
     VOLATILE = 285,
     DO = 286,
     IF = 287,
     STATIC = 288,
     WHILE = 289,
     IDENTIFIER = 290,
     STRINGliteral = 291,
     FLOATINGconstant = 292,
     INTEGERconstant = 293,
     CHARACTERconstant = 294,
     OCTALconstant = 295,
     HEXconstant = 296,
     TYPEDEFname = 297,
     ARROW = 298,
     ICR = 299,
     DECR = 300,
     LS = 301,
     RS = 302,
     LE = 303,
     GE = 304,
     EQ = 305,
     NE = 306,
     ANDAND = 307,
     OROR = 308,
     ELLIPSIS = 309,
     MULTassign = 310,
     DIVassign = 311,
     MODassign = 312,
     PLUSassign = 313,
     MINUSassign = 314,
     LSassign = 315,
     RSassign = 316,
     ANDassign = 317,
     ERassign = 318,
     ORassign = 319,
     LPAREN = 320,
     RPAREN = 321,
     COMMA = 322,
     HASH = 323,
     DHASH = 324,
     LBRACE = 325,
     RBRACE = 326,
     LBRACK = 327,
     RBRACK = 328,
     DOT = 329,
     AND = 330,
     STAR = 331,
     PLUS = 332,
     MINUS = 333,
     NEGATE = 334,
     NOT = 335,
     DIV = 336,
     MOD = 337,
     LT = 338,
     GT = 339,
     XOR = 340,
     PIPE = 341,
     QUESTION = 342,
     COLON = 343,
     SEMICOLON = 344,
     ASSIGN = 345,
     ASMSYM = 346,
     _BOOL = 347,
     _COMPLEX = 348,
     RESTRICT = 349,
     __ALIGNOF = 350,
     __ALIGNOF__ = 351,
     ASM = 352,
     __ASM = 353,
     __ASM__ = 354,
     AT = 355,
     USD = 356,
     __ATTRIBUTE = 357,
     __ATTRIBUTE__ = 358,
     __BUILTIN_OFFSETOF = 359,
     __BUILTIN_TYPES_COMPATIBLE_P = 360,
     __BUILTIN_VA_ARG = 361,
     __BUILTIN_VA_LIST = 362,
     __COMPLEX__ = 363,
     __CONST = 364,
     __CONST__ = 365,
     __EXTENSION__ = 366,
     INLINE = 367,
     __INLINE = 368,
     __INLINE__ = 369,
     __LABEL__ = 370,
     __RESTRICT = 371,
     __RESTRICT__ = 372,
     __SIGNED = 373,
     __SIGNED__ = 374,
     __THREAD = 375,
     TYPEOF = 376,
     __TYPEOF = 377,
     __TYPEOF__ = 378,
     __VOLATILE = 379,
     __VOLATILE__ = 380,
     PPNUM = 381
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "c.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4869

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  176
/* YYNRULES -- Number of rules.  */
#define YYNRULES  562
/* YYNRULES -- Number of states.  */
#define YYNSTATES  941

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      19,    21,    24,    32,    41,    44,    48,    52,    56,    60,
      63,    67,    71,    75,    79,    82,    86,    90,    94,    98,
     106,   115,   119,   123,   127,   131,   135,   139,   143,   147,
     151,   155,   159,   163,   165,   168,   172,   176,   180,   184,
     191,   198,   207,   214,   221,   230,   232,   234,   236,   238,
     240,   242,   244,   246,   248,   250,   252,   255,   258,   260,
     263,   265,   267,   269,   271,   273,   275,   277,   279,   281,
     283,   285,   287,   289,   291,   293,   295,   297,   299,   301,
     304,   307,   310,   313,   315,   318,   321,   324,   327,   330,
     333,   335,   338,   341,   344,   347,   350,   352,   355,   358,
     361,   364,   367,   370,   372,   375,   378,   381,   386,   391,
     393,   395,   397,   400,   403,   406,   409,   411,   414,   417,
     420,   422,   424,   426,   428,   430,   432,   434,   436,   438,
     440,   442,   444,   446,   448,   450,   452,   454,   456,   458,
     460,   462,   464,   466,   468,   475,   483,   486,   494,   503,
     507,   509,   511,   512,   515,   518,   521,   524,   527,   529,
     533,   538,   542,   547,   550,   552,   555,   557,   558,   560,
     563,   568,   574,   577,   583,   590,   596,   603,   607,   614,
     622,   624,   628,   632,   636,   637,   640,   642,   646,   648,
     652,   654,   657,   662,   667,   669,   672,   677,   679,   682,
     687,   692,   694,   697,   702,   704,   708,   711,   713,   715,
     717,   720,   722,   725,   726,   729,   731,   734,   738,   743,
     745,   747,   750,   751,   755,   758,   760,   762,   764,   767,
     771,   777,   780,   783,   787,   793,   796,   798,   800,   802,
     804,   806,   808,   811,   813,   815,   818,   822,   826,   831,
     833,   838,   844,   847,   851,   855,   860,   865,   867,   871,
     873,   875,   877,   879,   882,   886,   889,   893,   898,   900,
     904,   906,   908,   911,   915,   922,   926,   931,   933,   935,
     937,   939,   945,   946,   948,   951,   955,   960,   962,   965,
     968,   972,   976,   980,   984,   989,   991,   993,   995,   997,
     999,  1001,  1003,  1008,  1013,  1020,  1024,  1029,  1030,  1032,
    1034,  1037,  1041,  1043,  1047,  1048,  1051,  1053,  1055,  1057,
    1059,  1062,  1065,  1071,  1079,  1085,  1091,  1099,  1109,  1113,
    1118,  1121,  1124,  1128,  1130,  1132,  1134,  1136,  1138,  1140,
    1143,  1145,  1147,  1149,  1153,  1155,  1157,  1159,  1166,  1172,
    1174,  1179,  1183,  1188,  1192,  1196,  1199,  1202,  1204,  1211,
    1213,  1217,  1219,  1222,  1225,  1228,  1231,  1236,  1238,  1240,
    1242,  1244,  1246,  1253,  1260,  1263,  1268,  1271,  1273,  1275,
    1278,  1280,  1282,  1284,  1286,  1288,  1290,  1292,  1297,  1299,
    1303,  1307,  1311,  1313,  1317,  1321,  1323,  1327,  1331,  1333,
    1337,  1341,  1345,  1349,  1351,  1355,  1359,  1361,  1365,  1367,
    1371,  1373,  1377,  1379,  1383,  1385,  1389,  1391,  1397,  1402,
    1404,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,
    1426,  1428,  1430,  1431,  1433,  1435,  1439,  1441,  1442,  1444,
    1446,  1449,  1456,  1458,  1460,  1461,  1463,  1466,  1471,  1472,
    1475,  1479,  1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,
    1497,  1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,
    1517,  1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,
    1557,  1559,  1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,
    1577,  1579,  1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,
    1597,  1599,  1601,  1603,  1605,  1607,  1609,  1611,  1614,  1619,
    1620,  1622,  1628,  1635,  1642,  1650,  1656,  1660,  1662,  1663,
    1665,  1667,  1671,  1676,  1684,  1685,  1687,  1689,  1693,  1703,
    1705,  1709,  1711,  1713,  1715,  1716,  1717,  1718,  1719,  1720,
    1721,  1722,  1723
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     128,     0,    -1,   129,    -1,    -1,   129,   130,    -1,   132,
      -1,   139,    -1,   281,    -1,   131,    -1,    89,    -1,   133,
      -1,   111,   133,    -1,   134,   301,    70,   228,   232,   299,
      71,    -1,   135,   301,   234,    70,   228,   232,   299,    71,
      -1,   211,   296,    -1,   143,   211,   294,    -1,   144,   211,
     294,    -1,   145,   211,   294,    -1,   146,   211,   294,    -1,
     217,   296,    -1,   143,   217,   294,    -1,   144,   217,   294,
      -1,   145,   217,   294,    -1,   146,   217,   294,    -1,   217,
     296,    -1,   143,   217,   294,    -1,   144,   217,   294,    -1,
     145,   217,   294,    -1,   146,   217,   294,    -1,   137,   301,
      70,   228,   232,   299,    71,    -1,   138,   301,   234,    70,
     228,   232,   299,    71,    -1,   143,   211,   294,    -1,   144,
     211,   294,    -1,   145,   211,   294,    -1,   146,   211,   294,
      -1,   143,   217,   294,    -1,   144,   217,   294,    -1,   145,
     217,   294,    -1,   146,   217,   294,    -1,   143,   217,   294,
      -1,   144,   217,   294,    -1,   145,   217,   294,    -1,   146,
     217,   294,    -1,   140,    -1,   111,   140,    -1,   155,   302,
      89,    -1,   156,   302,    89,    -1,   142,   302,    89,    -1,
     141,   302,    89,    -1,   145,   211,   294,   283,   273,   192,
      -1,   146,   211,   294,   283,   273,   192,    -1,   141,    67,
     273,   211,   295,   283,   273,   192,    -1,   143,   202,   294,
     283,   273,   192,    -1,   144,   202,   294,   283,   273,   192,
      -1,   142,    67,   273,   202,   295,   283,   273,   192,    -1,
     153,    -1,   155,    -1,   157,    -1,   163,    -1,   159,    -1,
     154,    -1,   156,    -1,   158,    -1,   164,    -1,   160,    -1,
     166,    -1,   146,   166,    -1,   145,   147,    -1,   148,    -1,
     146,   148,    -1,   148,    -1,   166,    -1,   149,    -1,   150,
      -1,   151,    -1,   275,    -1,   152,    -1,    19,    -1,   109,
      -1,   110,    -1,    30,    -1,   124,    -1,   125,    -1,    94,
      -1,   116,    -1,   117,    -1,   112,    -1,   113,    -1,   114,
      -1,   154,   166,    -1,   145,   167,    -1,   153,   147,    -1,
     153,   167,    -1,   167,    -1,   146,   167,    -1,   154,   148,
      -1,   154,   167,    -1,   156,   166,    -1,   145,   170,    -1,
     155,   147,    -1,   170,    -1,   146,   170,    -1,   156,   148,
      -1,   158,   166,    -1,   145,    42,    -1,   157,   147,    -1,
      42,    -1,   146,    42,    -1,   158,   148,    -1,   160,   166,
      -1,   145,   161,    -1,   159,   147,    -1,   159,   161,    -1,
     161,    -1,   146,   161,    -1,   160,   148,    -1,   160,   161,
      -1,   162,    65,   191,    66,    -1,   162,    65,   271,    66,
      -1,   121,    -1,   122,    -1,   123,    -1,   164,   166,    -1,
     145,   165,    -1,   163,   147,    -1,   163,   165,    -1,   165,
      -1,   146,   165,    -1,   164,   148,    -1,   164,   165,    -1,
     107,    -1,    14,    -1,    16,    -1,    33,    -1,     3,    -1,
      13,    -1,    26,    -1,    15,    -1,    21,    -1,     5,    -1,
       9,    -1,    20,    -1,     4,    -1,   168,    -1,    22,    -1,
      92,    -1,   169,    -1,    25,    -1,   118,    -1,   119,    -1,
      93,    -1,   108,    -1,   171,    -1,   181,    -1,   172,   298,
      70,   173,   299,    71,    -1,   172,   190,   298,    70,   173,
     299,    71,    -1,   172,   190,    -1,   172,   274,   298,    70,
     173,   299,    71,    -1,   172,   274,   190,   298,    70,   173,
     299,    71,    -1,   172,   274,   190,    -1,     6,    -1,    18,
      -1,    -1,   173,   174,    -1,   176,    89,    -1,   175,    89,
      -1,   146,    89,    -1,   144,    89,    -1,    89,    -1,   146,
     178,   273,    -1,   175,    67,   178,   273,    -1,   144,   177,
     273,    -1,   176,    67,   177,   273,    -1,   202,   179,    -1,
     180,    -1,   211,   179,    -1,   180,    -1,    -1,   180,    -1,
      88,   272,    -1,    12,    70,   182,    71,    -1,    12,   190,
      70,   182,    71,    -1,    12,   190,    -1,    12,    70,   182,
      67,    71,    -1,    12,   190,    70,   182,    67,    71,    -1,
      12,   274,    70,   182,    71,    -1,    12,   274,   190,    70,
     182,    71,    -1,    12,   274,   190,    -1,    12,   274,    70,
     182,    67,    71,    -1,    12,   274,   190,    70,   182,    67,
      71,    -1,   183,    -1,   182,    67,   183,    -1,    35,   297,
     184,    -1,    42,   297,   184,    -1,    -1,    90,   272,    -1,
     186,    -1,   186,    67,    54,    -1,   187,    -1,   186,    67,
     187,    -1,   143,    -1,   143,   219,    -1,   143,   211,   294,
     273,    -1,   143,   205,   294,   273,    -1,   145,    -1,   145,
     219,    -1,   145,   211,   294,   273,    -1,   144,    -1,   144,
     219,    -1,   144,   211,   294,   273,    -1,   144,   205,   294,
     273,    -1,   146,    -1,   146,   219,    -1,   146,   211,   294,
     273,    -1,   189,    -1,   188,    67,   189,    -1,    35,   296,
      -1,    35,    -1,    42,    -1,   144,    -1,   144,   219,    -1,
     146,    -1,   146,   219,    -1,    -1,    90,   193,    -1,   194,
      -1,   197,   194,    -1,    70,   196,    71,    -1,    70,   196,
     193,    71,    -1,   268,    -1,   196,    -1,   196,   193,    -1,
      -1,   196,   193,    67,    -1,   198,    90,    -1,   200,    -1,
     201,    -1,   199,    -1,   198,   199,    -1,    72,   272,    73,
      -1,    72,   272,    54,   272,    73,    -1,    74,    35,    -1,
      74,    42,    -1,    72,   272,    73,    -1,    72,   272,    54,
     272,    73,    -1,    35,    88,    -1,   203,    -1,   211,    -1,
     204,    -1,   208,    -1,   205,    -1,    42,    -1,    42,   220,
      -1,   206,    -1,   207,    -1,    76,   205,    -1,    76,   146,
     205,    -1,    65,   206,    66,    -1,    65,   206,    66,   220,
      -1,   209,    -1,    76,    65,   210,    66,    -1,    76,   146,
      65,   210,    66,    -1,    76,   208,    -1,    76,   146,   208,
      -1,    65,   208,    66,    -1,    65,   210,   220,    66,    -1,
      65,   208,    66,   220,    -1,    42,    -1,    65,   210,    66,
      -1,   212,    -1,   213,    -1,   215,    -1,   214,    -1,    76,
     211,    -1,    76,   146,   211,    -1,   215,   220,    -1,    65,
     213,    66,    -1,    65,   213,    66,   220,    -1,   216,    -1,
      65,   215,    66,    -1,    35,    -1,   218,    -1,    76,   217,
      -1,    76,   146,   217,    -1,   215,    65,   298,   188,   300,
      66,    -1,    65,   217,    66,    -1,    65,   217,    66,   220,
      -1,   223,    -1,   224,    -1,   220,    -1,   222,    -1,    65,
     298,   221,   300,    66,    -1,    -1,   185,    -1,    72,    73,
      -1,    72,   272,    73,    -1,   222,    72,   272,    73,    -1,
      76,    -1,    76,   146,    -1,    76,   219,    -1,    76,   146,
     219,    -1,    65,   223,    66,    -1,    65,   224,    66,    -1,
      65,   220,    66,    -1,    65,   223,    66,   220,    -1,   226,
      -1,   227,    -1,   235,    -1,   236,    -1,   237,    -1,   238,
      -1,   284,    -1,   190,    88,   273,   225,    -1,    11,   272,
      88,   225,    -1,    11,   272,    54,   272,    88,   225,    -1,
      27,    88,   225,    -1,    70,   228,   232,    71,    -1,    -1,
     229,    -1,   230,    -1,   229,   230,    -1,   115,   231,    89,
      -1,    35,    -1,   231,    67,    35,    -1,    -1,   232,   233,
      -1,   139,    -1,   225,    -1,   136,    -1,   139,    -1,   234,
     139,    -1,   270,    89,    -1,    32,    65,   271,    66,   225,
      -1,    32,    65,   271,    66,   225,     8,   225,    -1,    10,
      65,   271,    66,   225,    -1,    34,    65,   271,    66,   225,
      -1,    31,   225,    34,    65,   271,    66,    89,    -1,    24,
      65,   270,    89,   270,    89,   270,    66,   225,    -1,    28,
     190,    89,    -1,    28,    76,   271,    89,    -1,    23,    89,
      -1,     7,    89,    -1,    17,   270,    89,    -1,    37,    -1,
      38,    -1,    40,    -1,    41,    -1,    39,    -1,    36,    -1,
     240,    36,    -1,   242,    -1,   239,    -1,   240,    -1,    65,
     271,    66,    -1,   244,    -1,   243,    -1,    35,    -1,   106,
      65,   268,    67,   191,    66,    -1,    65,   298,   227,   299,
      66,    -1,   241,    -1,   245,    72,   271,    73,    -1,   245,
      65,    66,    -1,   245,    65,   247,    66,    -1,   245,    74,
     190,    -1,   245,    43,   190,    -1,   245,    44,    -1,   245,
      45,    -1,   246,    -1,    65,   191,    66,    70,   195,    71,
      -1,   268,    -1,   247,    67,   268,    -1,   245,    -1,    44,
     248,    -1,    45,   248,    -1,   255,   256,    -1,    29,   248,
      -1,    29,    65,   191,    66,    -1,   254,    -1,   252,    -1,
     251,    -1,   250,    -1,   249,    -1,   105,    65,   191,    67,
     191,    66,    -1,   104,    65,   191,    67,   245,    66,    -1,
     111,   256,    -1,   253,    65,   191,    66,    -1,   253,   248,
      -1,    96,    -1,    95,    -1,    52,    35,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
     248,    -1,    65,   191,    66,   256,    -1,   256,    -1,   257,
      76,   256,    -1,   257,    81,   256,    -1,   257,    82,   256,
      -1,   257,    -1,   258,    77,   257,    -1,   258,    78,   257,
      -1,   258,    -1,   259,    46,   258,    -1,   259,    47,   258,
      -1,   259,    -1,   260,    83,   259,    -1,   260,    84,   259,
      -1,   260,    48,   259,    -1,   260,    49,   259,    -1,   260,
      -1,   261,    50,   260,    -1,   261,    51,   260,    -1,   261,
      -1,   262,    75,   261,    -1,   262,    -1,   263,    85,   262,
      -1,   263,    -1,   264,    86,   263,    -1,   264,    -1,   265,
      52,   264,    -1,   265,    -1,   266,    53,   265,    -1,   266,
      -1,   266,    87,   271,    88,   267,    -1,   266,    87,    88,
     267,    -1,   267,    -1,   248,   269,   268,    -1,    90,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      -1,   271,    -1,   268,    -1,   271,    67,   268,    -1,   267,
      -1,    -1,   274,    -1,   275,    -1,   274,   275,    -1,   276,
      65,    65,   277,    66,    66,    -1,   102,    -1,   103,    -1,
      -1,   278,    -1,   280,   279,    -1,   278,    67,   280,   279,
      -1,    -1,    65,    66,    -1,    65,   247,    66,    -1,    35,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    34,    -1,    91,    -1,    92,    -1,    93,
      -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,    98,
      -1,    99,    -1,   102,    -1,   103,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,
      -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,
      -1,   116,    -1,   117,    -1,   118,    -1,   119,    -1,   120,
      -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,
      -1,   282,    89,    -1,   293,    65,   240,    66,    -1,    -1,
     282,    -1,   293,    65,   285,    66,    89,    -1,   293,    28,
      65,   291,    66,    89,    -1,   293,   148,    65,   285,    66,
      89,    -1,   240,    88,   286,    88,   286,    88,   290,    -1,
     240,    88,   286,    88,   286,    -1,   240,    88,   286,    -1,
     240,    -1,    -1,   287,    -1,   288,    -1,   287,    67,   288,
      -1,   240,    65,   271,    66,    -1,    72,   280,    73,   240,
      65,   271,    66,    -1,    -1,   290,    -1,   240,    -1,   290,
      67,   240,    -1,   240,    88,   286,    88,   286,    88,   289,
      88,   292,    -1,   189,    -1,   292,    67,   189,    -1,    97,
      -1,    98,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   164,   166,   170,   171,   172,   173,   177,
     181,   182,   186,   187,   191,   192,   193,   194,   195,   197,
     198,   199,   200,   201,   205,   206,   207,   208,   209,   216,
     217,   221,   222,   223,   224,   226,   227,   228,   229,   233,
     234,   235,   236,   272,   273,   277,   278,   279,   280,   287,
     288,   289,   293,   294,   295,   299,   300,   301,   302,   303,
     307,   308,   309,   310,   311,   315,   316,   317,   321,   322,
     326,   327,   331,   332,   333,   334,   335,   339,   340,   341,
     345,   346,   347,   351,   352,   353,   357,   358,   359,   363,
     364,   365,   366,   370,   371,   372,   373,   377,   378,   379,
     383,   384,   385,   390,   391,   392,   396,   397,   398,   402,
     403,   404,   405,   409,   410,   411,   412,   416,   417,   421,
     422,   423,   427,   428,   429,   430,   434,   435,   436,   437,
     441,   445,   446,   447,   448,   449,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   467,   468,   469,
     473,   474,   478,   479,   483,   484,   486,   487,   488,   490,
     494,   495,   498,   500,   504,   505,   506,   507,   508,   512,
     513,   517,   518,   523,   524,   528,   529,   532,   534,   538,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     560,   561,   565,   566,   569,   571,   575,   576,   580,   581,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   606,   607,   611,   615,   616,   620,
     621,   622,   623,   626,   628,   632,   633,   642,   643,   644,
     648,   649,   652,   653,   657,   658,   659,   663,   664,   668,
     669,   670,   671,   675,   676,   680,   684,   685,   689,   693,
     694,   698,   699,   700,   707,   708,   709,   713,   714,   721,
     722,   723,   725,   726,   730,   731,   732,   736,   737,   741,
     745,   746,   750,   751,   752,   756,   757,   758,   762,   763,
     767,   771,   772,   773,   777,   778,   779,   783,   784,   785,
     789,   790,   793,   795,   799,   800,   801,   805,   806,   807,
     808,   812,   813,   814,   815,   821,   822,   823,   824,   825,
     826,   827,   831,   832,   833,   834,   845,   848,   850,   854,
     855,   859,   863,   864,   867,   868,   872,   873,   874,   878,
     879,   888,   892,   893,   894,   898,   899,   900,   905,   906,
     907,   908,   909,   916,   917,   921,   922,   923,   928,   929,
     935,   936,   937,   938,   939,   940,   944,   948,   952,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   967,   971,
     972,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   990,   994,   998,  1002,  1003,  1007,  1008,  1012,
    1016,  1017,  1018,  1019,  1020,  1021,  1025,  1026,  1030,  1031,
    1032,  1033,  1037,  1038,  1039,  1043,  1044,  1045,  1049,  1050,
    1051,  1052,  1053,  1057,  1058,  1059,  1063,  1064,  1068,  1069,
    1073,  1074,  1078,  1079,  1083,  1084,  1088,  1089,  1091,  1096,
    1097,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1114,  1116,  1120,  1121,  1125,  1128,  1130,  1134,
    1135,  1139,  1143,  1144,  1147,  1149,  1153,  1154,  1157,  1159,
    1160,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1224,  1225,  1226,  1227,  1228,  1229,  1235,  1239,  1242,
    1244,  1248,  1250,  1251,  1255,  1256,  1257,  1258,  1261,  1263,
    1267,  1268,  1272,  1273,  1276,  1278,  1282,  1283,  1287,  1291,
    1292,  1296,  1297,  1298,  1307,  1310,  1313,  1316,  1319,  1322,
    1325,  1328,  1331
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "DOUBLE", "INT", "STRUCT",
  "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM", "REGISTER", "TYPEDEF",
  "CHAR", "EXTERN", "RETURN", "UNION", "CONST", "FLOAT", "SHORT",
  "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID", "DEFAULT", "GOTO",
  "SIZEOF", "VOLATILE", "DO", "IF", "STATIC", "WHILE", "IDENTIFIER",
  "STRINGliteral", "FLOATINGconstant", "INTEGERconstant",
  "CHARACTERconstant", "OCTALconstant", "HEXconstant", "TYPEDEFname",
  "ARROW", "ICR", "DECR", "LS", "RS", "LE", "GE", "EQ", "NE", "ANDAND",
  "OROR", "ELLIPSIS", "MULTassign", "DIVassign", "MODassign", "PLUSassign",
  "MINUSassign", "LSassign", "RSassign", "ANDassign", "ERassign",
  "ORassign", "LPAREN", "RPAREN", "COMMA", "HASH", "DHASH", "LBRACE",
  "RBRACE", "LBRACK", "RBRACK", "DOT", "AND", "STAR", "PLUS", "MINUS",
  "NEGATE", "NOT", "DIV", "MOD", "LT", "GT", "XOR", "PIPE", "QUESTION",
  "COLON", "SEMICOLON", "ASSIGN", "ASMSYM", "_BOOL", "_COMPLEX",
  "RESTRICT", "__ALIGNOF", "__ALIGNOF__", "ASM", "__ASM", "__ASM__", "AT",
  "USD", "__ATTRIBUTE", "__ATTRIBUTE__", "__BUILTIN_OFFSETOF",
  "__BUILTIN_TYPES_COMPATIBLE_P", "__BUILTIN_VA_ARG", "__BUILTIN_VA_LIST",
  "__COMPLEX__", "__CONST", "__CONST__", "__EXTENSION__", "INLINE",
  "__INLINE", "__INLINE__", "__LABEL__", "__RESTRICT", "__RESTRICT__",
  "__SIGNED", "__SIGNED__", "__THREAD", "TYPEOF", "__TYPEOF", "__TYPEOF__",
  "__VOLATILE", "__VOLATILE__", "PPNUM", "$accept", "TranslationUnit",
  "ExternalDeclarationList", "ExternalDeclaration", "EmptyDefinition",
  "FunctionDefinitionExtension", "FunctionDefinition",
  "FunctionDeclarator", "FunctionOldPrototype", "NestedFunctionDefinition",
  "NestedFunctionDeclarator", "NestedFunctionOldPrototype",
  "DeclarationExtension", "Declaration", "DefaultDeclaringList",
  "DeclaringList", "DeclarationSpecifier", "TypeSpecifier",
  "DeclarationQualifierList", "TypeQualifierList", "DeclarationQualifier",
  "TypeQualifier", "ConstQualifier", "VolatileQualifier",
  "RestrictQualifier", "FunctionSpecifier", "BasicDeclarationSpecifier",
  "BasicTypeSpecifier", "SUEDeclarationSpecifier", "SUETypeSpecifier",
  "TypedefDeclarationSpecifier", "TypedefTypeSpecifier",
  "TypeofDeclarationSpecifier", "TypeofTypeSpecifier", "Typeofspecifier",
  "Typeofkeyword", "VarArgDeclarationSpecifier", "VarArgTypeSpecifier",
  "VarArgTypeName", "StorageClass", "BasicTypeName", "SignedKeyword",
  "ComplexKeyword", "ElaboratedTypeName", "StructOrUnionSpecifier",
  "StructOrUnion", "StructDeclarationList", "StructDeclaration",
  "StructDefaultDeclaringList", "StructDeclaringList", "StructDeclarator",
  "StructIdentifierDeclarator", "BitFieldSizeOpt", "BitFieldSize",
  "EnumSpecifier", "EnumeratorList", "Enumerator", "EnumeratorValueOpt",
  "ParameterTypeList", "ParameterList", "ParameterDeclaration",
  "IdentifierList", "Identifier", "IdentifierOrTypedefName", "TypeName",
  "InitializerOpt", "DesignatedInitializer", "Initializer",
  "InitializerList", "MatchedInitializerList", "Designation",
  "DesignatorList", "Designator", "ObsoleteArrayDesignation",
  "ObsoleteFieldDesignation", "Declarator", "TypedefDeclarator",
  "TypedefDeclaratorMain", "ParameterTypedefDeclarator",
  "CleanTypedefDeclarator", "CleanPostfixTypedefDeclarator",
  "ParenTypedefDeclarator", "ParenPostfixTypedefDeclarator",
  "SimpleParenTypedefDeclarator", "IdentifierDeclarator",
  "IdentifierDeclaratorMain", "UnaryIdentifierDeclarator",
  "PostfixIdentifierDeclarator", "ParenIdentifierDeclarator",
  "SimpleDeclarator", "OldFunctionDeclarator",
  "PostfixOldFunctionDeclarator", "AbstractDeclarator",
  "PostfixingAbstractDeclarator", "ParameterTypeListOpt",
  "ArrayAbstractDeclarator", "UnaryAbstractDeclarator",
  "PostfixAbstractDeclarator", "Statement", "LabeledStatement",
  "CompoundStatement", "LocalLabelDeclarationListOpt",
  "LocalLabelDeclarationList", "LocalLabelDeclaration", "LocalLabelList",
  "DeclarationOrStatementList", "DeclarationOrStatement",
  "DeclarationList", "ExpressionStatement", "SelectionStatement",
  "IterationStatement", "JumpStatement", "Constant", "StringLiteralList",
  "PrimaryExpression", "PrimaryIdentifier", "VariableArgumentAccess",
  "StatementAsExpression", "PostfixExpression", "CompoundLiteral",
  "ArgumentExpressionList", "UnaryExpression",
  "TypeCompatibilityExpression", "OffsetofExpression",
  "ExtensionExpression", "AlignofExpression", "Alignofkeyword",
  "LabelAddressExpression", "Unaryoperator", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "ShiftExpression",
  "RelationalExpression", "EqualityExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression", "LogicalAndExpression",
  "LogicalORExpression", "ConditionalExpression", "AssignmentExpression",
  "AssignmentOperator", "ExpressionOpt", "Expression",
  "ConstantExpression", "AttributeSpecifierListOpt",
  "AttributeSpecifierList", "AttributeSpecifier", "AttributeKeyword",
  "AttributeListOpt", "AttributeList", "AttributeExpressionOpt", "Word",
  "AssemblyDefinition", "AssemblyExpression", "AssemblyExpressionOpt",
  "AssemblyStatement", "Assemblyargument", "AssemblyoperandsOpt",
  "Assemblyoperands", "Assemblyoperand", "AssemblyclobbersOpt",
  "Assemblyclobbers", "AssemblyGotoargument", "AssemblyJumpLabels",
  "AsmKeyword", "BindIdentifier", "BindIdentifierInList", "BindVar",
  "BindEnum", "EnterScope", "ExitScope", "ExitReentrantScope",
  "ReenterScope", "KillReentrantScope", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   127,   128,   129,   129,   130,   130,   130,   130,   131,
     132,   132,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   135,   135,   135,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     138,   138,   138,   139,   139,   140,   140,   140,   140,   141,
     141,   141,   142,   142,   142,   143,   143,   143,   143,   143,
     144,   144,   144,   144,   144,   145,   145,   145,   146,   146,
     147,   147,   148,   148,   148,   148,   148,   149,   149,   149,
     150,   150,   150,   151,   151,   151,   152,   152,   152,   153,
     153,   153,   153,   154,   154,   154,   154,   155,   155,   155,
     156,   156,   156,   157,   157,   157,   158,   158,   158,   159,
     159,   159,   159,   160,   160,   160,   160,   161,   161,   162,
     162,   162,   163,   163,   163,   163,   164,   164,   164,   164,
     165,   166,   166,   166,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   168,   168,   168,
     169,   169,   170,   170,   171,   171,   171,   171,   171,   171,
     172,   172,   173,   173,   174,   174,   174,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     182,   182,   183,   183,   184,   184,   185,   185,   186,   186,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   187,   188,   188,   189,   190,   190,   191,
     191,   191,   191,   192,   192,   193,   193,   194,   194,   194,
     195,   195,   196,   196,   197,   197,   197,   198,   198,   199,
     199,   199,   199,   200,   200,   201,   202,   202,   203,   204,
     204,   205,   205,   205,   206,   206,   206,   207,   207,   208,
     208,   208,   208,   208,   209,   209,   209,   210,   210,   211,
     212,   212,   213,   213,   213,   214,   214,   214,   215,   215,
     216,   217,   217,   217,   218,   218,   218,   219,   219,   219,
     220,   220,   221,   221,   222,   222,   222,   223,   223,   223,
     223,   224,   224,   224,   224,   225,   225,   225,   225,   225,
     225,   225,   226,   226,   226,   226,   227,   228,   228,   229,
     229,   230,   231,   231,   232,   232,   233,   233,   233,   234,
     234,   235,   236,   236,   236,   237,   237,   237,   238,   238,
     238,   238,   238,   239,   239,   239,   239,   239,   240,   240,
     241,   241,   241,   241,   241,   241,   242,   243,   244,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   246,   247,
     247,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   249,   250,   251,   252,   252,   253,   253,   254,
     255,   255,   255,   255,   255,   255,   256,   256,   257,   257,
     257,   257,   258,   258,   258,   259,   259,   259,   260,   260,
     260,   260,   260,   261,   261,   261,   262,   262,   263,   263,
     264,   264,   265,   265,   266,   266,   267,   267,   267,   268,
     268,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   270,   270,   271,   271,   272,   273,   273,   274,
     274,   275,   276,   276,   277,   277,   278,   278,   279,   279,
     279,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   281,   282,   283,
     283,   284,   284,   284,   285,   285,   285,   285,   286,   286,
     287,   287,   288,   288,   289,   289,   290,   290,   291,   292,
     292,   293,   293,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     7,     8,     2,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     7,
       8,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     3,     3,     3,     3,     6,
       6,     8,     6,     6,     8,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     4,     4,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     7,     2,     7,     8,     3,
       1,     1,     0,     2,     2,     2,     2,     2,     1,     3,
       4,     3,     4,     2,     1,     2,     1,     0,     1,     2,
       4,     5,     2,     5,     6,     5,     6,     3,     6,     7,
       1,     3,     3,     3,     0,     2,     1,     3,     1,     3,
       1,     2,     4,     4,     1,     2,     4,     1,     2,     4,
       4,     1,     2,     4,     1,     3,     2,     1,     1,     1,
       2,     1,     2,     0,     2,     1,     2,     3,     4,     1,
       1,     2,     0,     3,     2,     1,     1,     1,     2,     3,
       5,     2,     2,     3,     5,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     3,     3,     4,     1,
       4,     5,     2,     3,     3,     4,     4,     1,     3,     1,
       1,     1,     1,     2,     3,     2,     3,     4,     1,     3,
       1,     1,     2,     3,     6,     3,     4,     1,     1,     1,
       1,     5,     0,     1,     2,     3,     4,     1,     2,     2,
       3,     3,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     6,     3,     4,     0,     1,     1,
       2,     3,     1,     3,     0,     2,     1,     1,     1,     1,
       2,     2,     5,     7,     5,     5,     7,     9,     3,     4,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     3,     1,     1,     1,     6,     5,     1,
       4,     3,     4,     3,     3,     2,     2,     1,     6,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     6,     6,     2,     4,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     3,     1,     0,     1,     1,
       2,     6,     1,     1,     0,     1,     2,     4,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     0,
       1,     5,     6,     6,     7,     5,     3,     1,     0,     1,
       1,     3,     4,     7,     0,     1,     1,     3,     9,     1,
       3,     1,     1,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,     0,     2,     1,   134,   142,   139,   160,   140,     0,
     135,   131,   137,   132,   161,    77,   141,   138,   144,   147,
     136,    80,   133,   280,   106,     0,     0,     9,   145,   150,
      83,   551,   552,   553,   452,   453,   130,   151,    78,    79,
       0,    86,    87,    88,    84,    85,   148,   149,   119,   120,
     121,    81,    82,     4,     8,     5,    10,   561,   561,     6,
      43,   562,   562,     0,     0,     0,     0,    68,    72,    73,
      74,    76,    55,    60,    56,    61,    57,    62,    59,    64,
     113,     0,    58,    63,   126,    65,    93,   143,   146,   100,
     152,   558,   153,   556,   269,   270,   272,   271,   278,   556,
     281,    75,     0,     7,     0,     0,   217,   218,     0,   182,
       0,   449,     0,     0,     0,     0,   273,   282,    11,    44,
       0,     0,   447,     0,   447,     0,   251,     0,     0,   554,
     246,   248,   250,   253,   254,   249,   259,   247,   554,   554,
     247,   554,   104,    67,    70,   110,   123,    71,    90,    98,
     554,   554,   107,    69,   114,   127,    66,    94,   101,   554,
     554,    91,    92,    95,    89,    96,    99,     0,   102,    97,
       0,   105,   108,   103,   111,   112,   115,   116,   109,     0,
     124,   125,   128,   129,   122,   156,   558,     0,    14,   558,
       0,   275,   290,    24,     0,   527,     0,   557,   557,     0,
     190,     0,     0,   187,   450,   276,   279,   285,   274,   283,
     317,     0,   329,     0,     0,     0,     0,     0,     0,   448,
      48,     0,    47,   558,   252,   267,     0,     0,     0,     0,
       0,     0,   255,   262,   529,    15,    25,   529,    16,    26,
     529,    27,   529,    28,    45,    46,     0,   356,   348,   343,
     344,   347,   345,   346,     0,     0,     0,   558,   390,   391,
     392,   393,   394,   395,   388,   387,     0,     0,     0,     0,
     219,   221,    60,    61,    62,    64,    63,     0,   351,   352,
     359,   350,   355,   354,   371,   367,   396,   381,   380,   379,
     378,     0,   377,     0,   398,   402,   405,   408,   413,   416,
     418,   420,   422,   424,   426,   429,   444,     0,     0,   159,
       0,   162,   292,   294,   396,   446,     0,     0,   454,     0,
     194,   194,     0,   180,     0,     0,     0,   277,   286,     0,
     324,   318,   319,     0,     0,   247,   271,     0,     0,   554,
     554,   317,   330,   555,   555,   292,     0,   257,   264,     0,
       0,     0,   256,   263,   530,   447,   447,   447,   447,   558,
     375,   558,   372,   373,   389,     0,     0,     0,     0,     0,
       0,   384,   558,   297,   220,   289,   287,   288,   222,   117,
     349,     0,   365,   366,     0,     0,     0,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   431,     0,   558,
     386,   374,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,   162,     0,   162,   559,   556,   200,   207,
     204,   211,    56,    61,   293,   196,   198,   560,   214,   560,
     295,     0,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   461,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,     0,   455,
     458,   528,     0,   192,   193,   183,   191,     0,   181,     0,
     185,     0,   322,     0,   442,   320,     0,     0,     0,     0,
       0,   529,   529,   324,   529,   529,   268,   258,   266,   265,
     260,     0,   223,   223,   223,   223,     0,     0,     0,   353,
     317,   559,     0,     0,     0,     0,     0,     0,   298,   299,
     364,   361,     0,   369,     0,   363,   430,     0,   399,   400,
     401,   403,   404,   406,   407,   411,   412,   409,   410,   414,
     415,   417,   419,   421,   423,   425,     0,     0,   445,   559,
     162,   559,   168,     0,     0,   163,     0,     0,     0,   216,
     558,   297,   554,   554,   201,   554,   554,   208,   558,   297,
     554,   205,   554,   212,     0,     0,     0,     0,   296,     0,
       0,     0,   456,   195,   184,   188,     0,   186,     0,   321,
       0,     0,     0,   442,     0,     0,     0,     0,   442,     0,
       0,   356,   106,     0,   328,   561,   561,   326,     0,     0,
       0,     0,     0,   327,   305,   306,   325,   307,   308,   309,
     310,     0,   443,   311,     0,     0,     0,   442,   447,   447,
     261,     0,    52,    53,    49,    50,   376,     0,   232,   397,
     324,     0,     0,     0,     0,   303,   301,   302,   300,   362,
       0,   360,   385,   428,     0,     0,   559,     0,     0,   167,
     447,   174,   177,   166,   447,   176,   177,     0,   165,     0,
     164,   154,   298,   447,   447,   447,   447,   298,   447,   447,
     197,   199,   215,   284,   291,   451,   458,   459,     0,   189,
     323,   341,     0,     0,     0,   340,   442,   442,     0,     0,
       0,     0,     0,     0,     0,   247,   554,   247,   554,   554,
     554,   554,   554,   447,   331,     0,     0,     0,    12,     0,
     223,   223,   356,   232,     0,     0,   224,   225,     0,     0,
     237,   235,   236,   229,     0,   230,   442,   358,     0,     0,
       0,   304,   370,   427,   155,     0,   157,   179,   171,   173,
     178,   169,   175,   447,   447,   203,   202,   210,   209,   206,
     213,   457,   460,     0,     0,   442,   342,     0,   315,     0,
     338,     0,     0,     0,   317,     0,    31,    39,    32,    40,
     529,    41,   529,    42,   442,     0,   537,     0,     0,    13,
      51,    54,   245,     0,     0,   241,   242,   226,     0,   234,
     238,   368,   231,   316,   383,   382,   357,   158,   170,   172,
     442,     0,   313,   442,   339,     0,   442,   442,   324,   317,
     312,     0,     0,   538,     0,     0,   227,     0,     0,   243,
       0,   233,   334,   442,     0,     0,   332,   335,   442,   324,
     538,     0,     0,     0,   536,   539,   540,   531,     0,   228,
       0,     0,   239,   314,   442,     0,   442,     0,   442,     0,
     532,     0,     0,   538,     0,   533,   244,     0,     0,   336,
     333,    29,     0,   538,     0,     0,   535,   541,   240,   442,
      30,     0,     0,   542,     0,   337,   544,     0,   546,   534,
       0,   545,     0,     0,     0,   543,   547,   549,   548,     0,
     550
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    53,    54,    55,    56,    57,    58,   644,
     645,   646,   647,    60,    61,    62,   213,   270,   215,   271,
     143,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   426,   595,   596,   597,
     700,   704,   789,   701,    92,   199,   200,   513,   434,   435,
     436,   437,   438,   652,   277,   672,   766,   767,   774,   775,
     768,   769,   770,   771,   772,   129,   130,   131,   132,   133,
     134,   135,   136,   229,   116,    94,    95,    96,   336,    98,
     114,   100,   559,   375,   439,   192,   376,   377,   653,   654,
     655,   330,   331,   332,   523,   524,   656,   217,   657,   658,
     659,   660,   278,   279,   280,   281,   282,   283,   284,   285,
     562,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   398,   661,   662,   316,   218,   219,   101,   102,
     508,   509,   622,   510,   103,   354,   357,   663,   827,   884,
     885,   886,   930,   929,   862,   938,   664,   234,   534,   188,
     320,   345,   598,   616,   120,   123
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -753
static const yytype_int16 yypact[] =
{
    -753,    48,  1879,  -753,  -753,  -753,  -753,  -753,  -753,   299,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,   167,  3710,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    2248,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,    46,    66,   262,   262,  2371,  2494,  -753,  -753,  -753,
    -753,  -753,  1937,  1937,  2067,  2067,  2306,  2306,  1125,  1125,
    -753,    42,  2190,  2190,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,    60,  -753,  -753,  -753,  -753,  -753,    93,  -753,  -753,
    -753,  -753,   101,  -753,   -18,   114,  -753,  -753,   139,    19,
     361,  -753,    85,   341,   116,  3710,  -753,  -753,  -753,  -753,
     161,  2938,   -68,   -16,   -68,   168,   365,   272,  3848,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,   218,  -753,  -753,
     218,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,   212,  -753,  -753,
     226,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  3340,
    -753,  -753,  -753,  -753,  -753,   250,    60,   255,  -753,  -753,
    4280,  -753,   267,   281,   277,  -753,   329,  -753,  -753,   146,
    -753,   139,   139,   300,  -753,   365,  -753,   365,  -753,  -753,
     326,  3218,  -753,   358,   358,  2617,  2740,  2781,   170,   -68,
    -753,   358,  -753,  -753,  -753,  -753,   272,   386,   391,   365,
     272,  3887,  -753,  -753,   431,  -753,   409,   431,  -753,   411,
     178,   435,   282,   437,  -753,  -753,  4580,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  4658,  4658,   455,  3340,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,   446,   493,   495,  4680,
     259,  3584,  2429,  3407,  3407,  1178,  1580,   496,  -753,   531,
    -753,  -753,  -753,  -753,   537,  -753,  1508,  -753,  -753,  -753,
    -753,  4758,  -753,  4680,  -753,   450,    16,   374,    52,   426,
     511,   486,   507,   543,   103,  -753,  -753,   419,   533,   250,
     535,  -753,  3061,  -753,  -753,  -753,   548,  4680,  1633,     8,
     526,   526,    28,  -753,   163,   222,   139,  -753,  -753,   593,
    -753,   326,  -753,   404,  3904,  -753,   365,   170,  3957,  -753,
    -753,   326,  -753,  -753,  -753,  3218,   384,   365,   365,   569,
     444,   272,  -753,  -753,  -753,   -68,   -68,   -68,   -68,  3340,
    -753,  3340,  -753,  -753,  -753,   571,   454,   570,  3747,  3747,
    4680,  -753,   259,  4013,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,   420,  -753,  -753,  4302,  4680,   420,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  4680,  3340,
    -753,  -753,  4680,  4680,  4680,  4680,  4680,  4680,  4680,  4680,
    4680,  4680,  4680,  4680,  4680,  4680,  4680,  4680,  4680,  4680,
    4380,  -753,  4680,  -753,   576,  -753,  3625,  -753,   257,   257,
    2002,  2125,  2306,  2306,  -753,   582,  -753,   585,  -753,  -753,
    -753,   581,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,  -753,  -753,  -753,  -753,  -753,   598,   616,
     627,  -753,  4680,  -753,  -753,  -753,  -753,    83,  -753,    86,
    -753,   297,  -753,   130,  1387,  -753,   404,   561,   404,  3989,
    3957,   431,   431,  -753,   431,   431,  -753,  -753,  -753,  -753,
    -753,   606,   638,   638,   638,   638,   630,   651,  4402,  -753,
     326,  -753,   667,   672,   677,   687,   690,   691,  4013,  -753,
    -753,  -753,   490,  -753,   283,  -753,  -753,   694,  -753,  -753,
    -753,   450,   450,    16,    16,   374,   374,   374,   374,    52,
      52,   426,   511,   486,   507,   543,  4680,    21,  -753,  3625,
    -753,  3625,  -753,    22,  3462,  -753,   162,   189,   693,  -753,
      10,  3786,  -753,  -753,  -753,  -753,  -753,  -753,   332,  3180,
    -753,  -753,  -753,  -753,  3095,   726,   696,   699,  -753,   700,
    1633,  4480,  -753,  -753,  -753,  -753,   166,  -753,   735,  -753,
     683,   706,  4680,  4680,   684,   713,   701,    41,  4124,   719,
     723,   702,   704,  1756,  -753,  -753,  -753,  -753,   262,   262,
    2371,  2494,   708,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    -753,   712,   736,  -753,  2562,   731,   404,  1387,   -68,   -68,
    -753,  1277,  -753,  -753,  -753,  -753,   734,   734,  -753,  -753,
    -753,   739,   954,  3747,  3747,  -753,   365,  -753,  -753,  -753,
    4680,  -753,   734,  -753,  4680,   737,  3625,   740,  4680,  -753,
     -68,  -753,   718,  -753,   -68,  -753,   718,    99,  -753,   203,
    -753,  -753,  3786,   -68,   -68,   -68,   -68,  3180,   -68,   -68,
    -753,  -753,  -753,  -753,  -753,  -753,   627,  -753,   525,  -753,
    -753,  -753,  4680,     4,   721,  -753,  4680,  4124,  4680,   728,
     773,  4680,  4680,   742,  2938,   218,  -753,   218,  -753,  -753,
    -753,  -753,  -753,   -68,  -753,   750,   329,   758,  -753,   754,
     638,   638,   738,  -753,  4680,   464,  -753,  -753,  4558,   354,
    -753,  -753,  -753,  -753,   756,  1277,  1510,  -753,   428,   762,
     763,  -753,  -753,  -753,  -753,   760,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,   -68,   -68,  -753,  -753,  -753,  -753,  -753,
    -753,  -753,  -753,   558,  4680,  4124,  -753,   743,  -753,   207,
    -753,   770,   578,   634,   326,  2904,  -753,   766,  -753,   769,
     313,   772,   368,   774,  4124,   329,    20,   782,   329,  -753,
    -753,  -753,  -753,  4202,   152,  -753,  -753,  -753,  4680,  -753,
    -753,  -753,   786,  -753,  -753,  -753,  -753,  -753,  -753,  -753,
    4124,   783,  -753,  4680,  -753,  4680,  4124,  4124,  -753,   326,
    -753,    24,   788,     7,   771,   792,  -753,   369,  4680,   429,
     160,  -753,  -753,  4124,   781,   637,   866,  -753,  1387,  -753,
       7,   793,  1633,   157,   796,   818,  -753,  -753,   798,  -753,
     815,  4680,  -753,  -753,  4680,   800,  4124,   819,  1387,   803,
    -753,   821,  4680,     7,     7,  -753,   489,   831,   826,  -753,
    -753,  -753,   835,     7,   329,   645,   824,  -753,  -753,  4124,
    -753,   827,   204,  -753,   329,  -753,   329,  4680,   531,   840,
     829,   840,   666,   329,   726,  -753,   531,  -753,   842,   726,
    -753
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -753,  -753,  -753,  -753,  -753,  -753,   879,  -753,  -753,  -753,
    -753,  -753,     3,   -33,  -753,  -753,     0,    -1,     1,    -2,
     -23,   790,  -753,  -753,  -753,  -753,  -753,   534,  -295,   602,
    -753,   654,  -753,   678,    12,  -753,  -753,   682,   604,    65,
      87,  -753,  -753,    57,  -753,  -753,  -392,  -753,  -753,  -753,
     213,   214,   217,  -522,  -753,  -165,  -296,   603,  -753,  -753,
     311,  -753,  -585,     6,  -192,  -476,  -752,   164,  -753,   174,
    -753,  -753,   169,  -753,  -753,   -10,  -753,  -753,    55,   127,
    -753,   -81,  -753,  -205,   201,  -753,   408,  -753,   449,  -753,
      40,  -753,  -258,   580,  -753,  -753,  -350,  -345,   263,  -753,
     562,  -332,  -753,   600,  -753,  -481,  -753,   197,  -753,  -753,
    -753,  -753,  -753,  -178,  -753,  -753,  -753,  -753,   260,  -753,
     322,   136,  -753,  -753,  -753,  -753,  -753,  -753,  -753,  -208,
     195,   342,   249,   338,   529,   530,   528,   536,   532,  -753,
    -128,   399,  -753,  -604,  -173,    82,   -96,    23,     5,  -753,
    -753,  -753,   223,  -600,  -753,   946,  -226,  -753,   125,  -525,
    -753,    51,  -753,    30,  -753,  -753,     2,   235,   613,   -80,
     764,   109,   292,   519,   -48,   243
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -563
static const yytype_int16 yytable[] =
{
      66,    64,    63,    65,   105,    59,   307,   119,   355,   533,
     121,   356,   374,   378,   111,   109,   358,   432,   319,   193,
     726,   346,   556,   842,   115,   350,   516,   557,   221,   734,
     722,   589,   110,   591,    34,    35,   324,   325,    66,    64,
      63,    65,    99,   248,   380,    23,   228,   233,     3,   161,
     432,   166,   667,   171,   139,   174,   380,    23,   804,   180,
     380,   371,   315,   197,   126,   365,   117,   673,   674,   675,
     198,   195,   705,   220,   511,   600,   106,   145,   154,   882,
      99,   867,   190,   107,   366,   401,   601,   333,   422,   201,
     175,   177,   805,   405,   406,   106,   111,   185,   334,   515,
     409,   410,   107,   138,   141,   151,   160,   179,   863,   694,
     698,   699,   880,   122,   186,   204,   203,   738,   197,   216,
     214,   197,   149,   158,   212,   198,   231,   111,   198,   111,
     147,   156,   807,   124,    23,   411,   412,   147,   164,   147,
     169,   147,   173,   147,   178,   228,   541,   147,   184,   228,
     353,   205,   148,   157,   624,   209,   419,   625,   189,   162,
     165,   521,    34,    35,   337,   190,   194,   546,   117,   547,
     604,   607,   611,   613,   197,   338,   552,   553,   119,   196,
     790,   198,   207,   232,   790,   705,   366,   698,   366,   315,
     420,   204,   309,   380,   568,   569,   570,   628,   696,   776,
     187,   197,    23,    93,   139,    23,   868,   567,   198,   216,
     214,   344,   564,   322,   891,   216,   214,   323,   680,   629,
     342,   516,   902,   516,   204,   869,   366,   145,   154,   707,
     517,   210,    25,   892,   518,   337,   105,   729,    23,   105,
     380,    93,   105,    26,   105,   126,   338,   587,   -17,   874,
     556,   708,   228,   233,   227,   557,   709,   222,   556,   542,
     543,   544,   545,   557,   137,   140,   150,   159,   333,   927,
     228,   209,   149,   158,   422,    31,    32,    33,   710,   334,
     147,   156,   901,   154,   830,   831,   352,   177,  -554,   519,
     908,   698,    23,   520,   308,   310,   854,    23,   312,   126,
     688,   244,   148,   157,   126,   125,   358,    23,   668,   669,
     431,   429,   428,   430,   225,   245,   208,   167,   170,   432,
    -558,   346,   600,   350,   372,   311,   314,   127,   158,   190,
     516,   190,   529,   601,   106,   373,   530,   226,   128,   317,
     679,   107,   318,   431,   429,   428,   430,   599,   128,   937,
     422,   -19,   -18,   227,   940,   899,   691,   227,   157,   165,
     111,   111,   111,   111,   626,   248,   367,    23,   627,   108,
     326,   558,   235,   236,   237,   238,   239,   878,   916,    31,
      32,    33,   360,   -33,   315,   240,   241,   560,   921,   232,
     362,   363,   565,    23,   242,   243,   106,   608,   898,   441,
     126,    34,    35,   107,   190,   314,   189,   206,   609,   166,
      31,    32,    33,   190,   335,   335,   339,   340,   424,   343,
     407,   408,   335,   333,   594,   593,   838,   400,   765,   314,
     223,   202,   208,   112,   334,   371,   871,   190,   -34,    23,
     889,   329,   145,   154,   839,   228,   225,   228,   353,   223,
     536,    97,   347,   314,   688,   106,   190,   348,   693,   688,
     227,   541,   107,    34,    35,    31,    32,    33,   367,   526,
     367,   381,   382,   383,   113,    97,   413,   414,   227,   -20,
     334,   -21,   858,   602,   605,   421,   422,   149,   158,    97,
     364,   779,   780,   384,   844,   147,   156,   147,   169,   835,
     385,  -239,   386,  -239,   315,   -22,   836,   -23,   367,   223,
     540,   368,    97,    97,    97,    97,   190,   148,   157,  -239,
     549,   422,   651,   649,   648,   650,   402,   879,    31,    32,
      33,   403,   404,   105,   105,   112,   105,   105,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   689,   690,   369,   803,
     370,  -240,   379,  -240,    97,   809,   783,   380,   812,   813,
     315,   416,   760,   761,   531,   532,   113,    97,   826,  -240,
     381,   382,   383,   702,   352,   228,   415,   594,   593,   594,
     593,   802,   690,   417,   623,   418,   358,   743,   744,   712,
     571,   572,   384,   423,   788,   425,   154,   717,   791,   385,
     119,   386,   431,   429,   428,   430,   512,   795,   796,   797,
     798,   440,   799,   800,   850,   422,   223,   206,   522,   603,
     606,   610,   612,   190,   112,   539,   315,   548,   112,   139,
     550,   216,   214,   739,   856,   422,   590,   861,   314,   614,
     826,   158,   615,   227,   618,   227,   232,   824,   575,   576,
     577,   578,   145,   154,   619,   651,   649,   648,   650,   146,
     155,   223,   670,   111,   111,   113,   315,   191,   190,   113,
      97,   157,   875,   620,   314,   883,   181,   183,   746,   748,
     750,   752,   621,   191,   594,   593,   676,   848,   849,   702,
     857,   422,   883,   895,   422,   111,   224,   149,   158,   111,
     315,   923,   422,   272,   733,   147,   156,   677,   111,   111,
     111,   111,   314,   111,   111,   883,   883,   227,   671,   915,
     208,   208,   935,   422,   682,   883,   922,   148,   157,   683,
     315,   112,   216,   214,   684,   112,   928,   212,   928,   573,
     574,   579,   580,   685,   932,   936,   686,   687,   111,   112,
     692,   427,   723,   315,   711,   724,   725,   352,   314,   554,
     730,   732,   731,   735,   651,   649,   648,   650,   736,   314,
     787,   273,   527,   563,   741,   327,   527,   328,   742,   737,
    -217,   272,  -218,   227,   335,   706,   753,   566,   111,   111,
     113,   754,   758,   422,   678,   777,   698,   811,   784,   349,
     806,   786,   814,   216,   214,   825,   665,   810,   342,   146,
     155,   588,   105,   828,   105,   829,   832,   841,   845,   846,
     314,   847,   853,   274,   314,   855,   -35,   713,   714,   -36,
     715,   716,   -37,   681,   -38,   718,   834,   719,   864,   745,
     747,   749,   751,   871,   881,   144,   153,   275,   888,   273,
     887,   276,   144,   163,   144,   168,   144,   172,   144,   176,
     894,   873,   144,   182,   896,   155,   651,   649,   648,   650,
     183,   695,   900,   697,   903,   904,   851,   905,   906,   909,
     911,   913,   919,   272,   914,   272,   651,   649,   648,   650,
     314,   740,   272,   272,   918,   153,   920,   933,   706,   939,
     335,   274,   924,   208,   433,   926,   191,   934,   208,   118,
     870,   793,   794,   792,   514,   721,   349,   537,   538,   551,
     349,   525,   837,   272,   112,   275,   112,   833,   840,   276,
     314,   815,   778,   728,   581,   583,   582,   433,   104,   801,
     890,   585,   555,   865,   584,   917,   931,   535,   617,   759,
     272,   273,   321,   273,     0,     0,     0,     0,     0,     0,
     273,   273,     0,   907,   314,   527,     0,   527,     0,     0,
     816,   817,   818,   819,   820,   821,   822,   823,   785,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
     808,   273,     0,     0,   314,   144,   153,     0,   112,     0,
       0,     0,     0,   274,     0,   274,   112,     0,     0,   361,
     563,   153,   274,   274,     0,     0,     0,   314,   273,     0,
       0,     0,     0,     0,   146,   155,     0,   275,     0,   275,
       0,   276,     0,   276,     0,     0,   275,   275,     0,   527,
     276,   276,     0,   274,     0,     0,     0,   527,     0,     0,
     268,   153,   163,   168,   172,   176,   182,     0,   852,     0,
     773,     0,     0,     0,   112,     0,     0,   275,     0,     0,
     274,   276,     0,     0,     0,     0,     0,   860,     0,   782,
       0,     0,     0,     0,     0,     0,     0,    97,    97,    97,
      97,     0,     0,     0,   275,     0,     0,   191,   276,     0,
       0,     0,     0,   872,     0,   527,     0,     0,     0,   876,
     877,   349,     0,   272,     0,   272,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,   893,     0,    10,    11,
       0,    13,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,    22,   910,
       0,     0,     0,     0,     0,     0,     0,   773,     0,     0,
     897,     0,     0,     0,   773,     0,     0,     0,     0,     0,
     555,     0,   925,     0,     0,     0,     0,     0,   555,     0,
     912,   273,     0,   273,     0,     0,     0,    15,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,   433,   272,   272,    30,
     144,   153,   144,   168,     0,     0,     0,    34,    35,     0,
     272,     0,   773,     0,    38,    39,     0,    41,    42,    43,
       0,    44,    45,   274,     0,   274,    48,    49,    50,    51,
      52,     0,     0,     0,   146,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   781,   275,     0,   275,
       0,   276,    30,   276,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,   273,   273,    38,    39,     0,
      41,    42,    43,     0,    44,    45,     0,     0,   273,    48,
      49,    50,    51,    52,     0,     0,   246,     0,     0,     0,
       0,     0,   762,   248,   249,   250,   251,   252,   253,   153,
     153,   254,   255,     0,     0,     0,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,   274,   274,     0,
       0,     0,   257,     0,     0,     0,     0,   763,   153,   764,
     274,   765,   258,   259,   260,   261,   262,   263,     0,     0,
       0,   275,   275,     0,     0,   276,   276,     0,     0,     0,
       0,     0,   264,   265,   275,     0,     0,     0,   276,     0,
       0,   266,   267,   268,   153,     0,     0,     0,   269,     0,
       4,     5,     6,     7,   630,     0,     8,   631,   632,     9,
      10,    11,    12,    13,   633,    14,    15,    16,    17,    18,
     634,   635,    19,    20,   636,   637,   246,    21,   638,   639,
      22,   640,   641,   248,   249,   250,   251,   252,   253,   642,
       0,   254,   255,     0,     0,     0,     0,     0,     0,   256,
     144,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,   757,     0,     0,   550,  -559,     0,
       0,     0,   258,   259,   260,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,   264,   265,    31,    32,    33,     0,     0,    34,
      35,   266,   267,   268,    36,    37,    38,    39,   643,    41,
      42,    43,   153,    44,    45,    46,    47,   153,    48,    49,
      50,    51,    52,     4,     5,     6,     7,   630,     0,     8,
     631,   632,     9,    10,    11,    12,    13,   633,    14,    15,
      16,    17,    18,   634,   635,    19,    20,   636,   637,   246,
      21,   638,   639,    22,   640,   641,   248,   249,   250,   251,
     252,   253,   642,     0,   254,   255,     0,     0,     0,     0,
       0,     0,   256,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,     0,     0,   257,     0,     0,     0,     0,
     550,   843,     0,     0,     0,   258,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,   397,    15,
       0,     0,    28,    29,    30,   264,   265,    31,    32,    33,
      21,     0,    34,    35,   266,   267,   268,    36,    37,    38,
      39,   643,    41,    42,    43,     0,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,     0,    36,     0,    38,
      39,     0,    41,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,   476,   477,   478,   479,   480,
     481,   482,   483,     0,     0,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,     4,
       5,     6,     7,     0,     0,     8,     0,     0,     9,    10,
      11,    12,    13,     0,    14,    15,    16,    17,    18,     0,
       0,    19,    20,     0,     0,   246,    21,     0,     0,    22,
       0,   247,   248,   249,   250,   251,   252,   253,    24,     0,
     254,   255,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
      30,   264,   265,     0,     0,     0,     0,     0,    34,    35,
     266,   267,   268,    36,    37,    38,    39,   269,    41,    42,
      43,     0,    44,    45,    46,    47,     0,    48,    49,    50,
      51,    52,     4,     5,     6,     7,     0,     0,     8,     0,
       0,     9,    10,    11,    12,    13,     0,    14,    15,    16,
      17,    18,     0,     0,    19,    20,     0,     0,     0,    21,
       0,     0,    22,     0,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,     0,    25,     0,     8,     0,     0,     0,
      10,    11,    12,    13,     0,    26,    15,    16,    17,    18,
       0,     0,    19,    20,     0,     0,     0,    21,    27,     0,
      22,    28,    29,    30,     0,     0,    31,    32,    33,     0,
       0,    34,    35,     0,     0,     0,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,     0,
      48,    49,    50,    51,    52,     4,     5,     6,     7,     0,
       0,     8,     0,     0,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,     0,     0,    19,    20,    28,
      29,    30,    21,     0,     0,    22,     0,    23,     0,    34,
      35,     0,     0,     0,   142,    37,    38,    39,     0,    41,
      42,    43,     0,    44,    45,    46,    47,     0,     0,     0,
       0,    51,    52,     0,     0,     0,     0,   608,     0,     0,
       4,     0,     0,     0,   190,     0,     0,     0,   609,     0,
      10,    11,     0,    13,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,    21,     0,     0,
      22,     0,     0,     0,    34,    35,     0,     0,     0,    36,
      37,    38,    39,     0,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,     4,     5,
       6,     7,     0,     0,     8,     0,     0,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,     0,     0,
      19,    20,     0,     0,     0,    21,  -562,     0,    22,     0,
      23,    30,     0,     0,     0,     0,     0,   152,     0,    34,
      35,     0,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,    44,    45,     0,     0,     0,     0,     0,
     608,    51,    52,     4,     0,     0,     0,   190,     0,     0,
       0,   609,     0,    10,    11,     0,    13,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      21,     0,     0,    22,     0,     0,     0,    34,    35,     0,
       0,     0,    36,    37,    38,    39,     0,    41,    42,    43,
       0,    44,    45,    46,    47,     0,    48,    49,    50,    51,
      52,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     0,     0,    19,    20,     0,     0,     0,    21,     0,
       0,    22,     0,    23,    30,     0,     0,     0,     0,     0,
      24,     0,    34,    35,     0,     0,     0,    36,     0,    38,
      39,     0,    41,    42,    43,     0,    44,    45,     0,     4,
       0,     0,     0,    25,    51,    52,     0,     0,     0,    10,
      11,     0,    13,     0,    26,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,    22,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,    36,    37,    38,    39,     0,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,     0,     0,    19,    20,     0,     0,
      30,    21,     0,     0,    22,     0,    23,     0,    34,    35,
       0,     0,     0,   142,     0,    38,    39,     0,    41,    42,
      43,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      51,    52,     0,     5,     6,     0,    25,     0,     8,     0,
       0,     0,     0,     0,    12,     0,     0,    26,    15,    16,
      17,    18,     0,     0,    19,    20,     0,     0,     0,    21,
       0,     0,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,    36,    37,
      38,    39,     0,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,     0,     0,    19,
      20,    28,    29,    30,    21,     0,     0,    22,     0,    23,
       0,    34,    35,     0,     0,     0,   152,    37,    38,    39,
       0,    41,    42,    43,     0,    44,    45,    46,    47,     0,
       0,     0,     0,    51,    52,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    28,    29,    30,     0,
     755,     0,    21,     0,     0,     0,    34,    35,     0,     0,
       0,    36,    37,    38,    39,     0,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
       4,     5,     6,     7,     0,     0,     8,   756,     0,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
       0,     0,    19,    20,     0,     0,     0,    21,     0,     0,
      22,     0,    23,     0,     0,     0,    30,     0,     0,   142,
       0,     0,     0,     0,    34,    35,     0,     0,     0,     0,
       0,    38,    39,     0,    41,    42,    43,     0,    44,    45,
       0,     0,   337,     0,     0,     0,    51,    52,     0,     0,
       0,     0,     0,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,     0,     0,    36,    37,    38,    39,     0,    41,
      42,    43,     0,    44,    45,    46,    47,     0,    48,    49,
      50,    51,    52,     4,     5,     6,     7,     0,     0,     8,
       0,     0,     9,    10,    11,    12,    13,     0,    14,    15,
      16,    17,    18,     0,     0,    19,    20,     0,     0,     0,
      21,     0,     0,    22,     0,    23,     0,     0,     0,     0,
       0,     0,   152,     0,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,     0,   337,    19,    20,     0,     0,
       0,    21,     0,     0,    22,     0,   338,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,     0,    36,    37,    38,
      39,   341,    41,    42,    43,     0,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,    36,    37,
      38,    39,   211,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,     4,     5,     6,
       7,     0,     0,     8,     0,     0,     9,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,     0,     0,    19,
      20,     0,     0,     0,    21,     0,     0,    22,     0,     0,
       0,     4,     5,     6,     7,     0,    24,     8,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     0,     0,    19,    20,     0,     0,     0,    21,     0,
       0,    22,     0,     0,   859,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,    36,    37,    38,    39,   211,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,    36,    37,    38,    39,   211,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,     4,     5,     6,     7,     0,     0,
       8,     0,     0,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,     0,     0,    19,    20,     0,     0,
       0,    21,     0,     0,    22,     0,   427,     0,     4,     5,
       6,     7,     0,    24,     8,     0,     0,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,     0,     0,
      19,    20,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   720,
       0,     0,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,    36,    37,
      38,    39,     0,    41,    42,    43,     0,    44,    45,    46,
      47,     0,    48,    49,    50,    51,    52,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    15,
       0,     0,    36,    37,    38,    39,     0,    41,    42,    43,
      21,    44,    45,    46,    47,    23,    48,    49,    50,    51,
      52,     4,     5,     6,     7,     0,     0,     8,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     0,     0,    19,    20,   608,     0,     0,    21,     0,
       0,    22,   190,     0,     0,     0,   609,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,     0,     0,     0,    38,
      39,     0,    41,    42,    43,     0,    44,    45,     0,     0,
       0,     0,     0,     0,    51,    52,     0,     0,     0,     0,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,    36,    37,    38,    39,     0,
      41,    42,    43,     0,    44,    45,    46,    47,     0,    48,
      49,    50,    51,    52,     5,     6,     7,     0,     0,     8,
       0,     0,     9,     0,     0,    12,     0,     0,    14,    15,
      16,    17,    18,     0,     0,    19,    20,     0,     0,   246,
      21,     0,     0,     0,     0,   247,   248,   249,   250,   251,
     252,   253,    24,     0,   254,   255,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,    28,    29,    30,   264,   265,    21,     0,     0,
       0,     0,    34,    35,   266,   267,   268,    36,    37,    38,
      39,   269,    41,    42,    43,     0,    44,    45,    46,    47,
       0,    48,    49,    50,    51,    52,     5,     6,     7,     0,
       0,     8,     0,     0,     9,     0,     0,    12,     0,     0,
      14,    15,    16,    17,    18,     0,     0,    19,    20,     0,
       0,     0,    21,     0,     0,     0,     0,    23,     0,     0,
       0,    30,     0,     0,   152,     0,     0,     0,     0,    34,
      35,     0,     0,     0,     0,     0,    38,    39,     0,    41,
      42,    43,     0,    44,    45,     0,     0,   337,     0,     0,
       0,    51,    52,     0,     0,     0,     0,     0,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     698,   703,     0,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,    34,    35,     0,     0,     0,    36,
      37,    38,    39,     0,    41,    42,    43,     0,    44,    45,
      46,    47,     0,    48,    49,    50,    51,    52,     5,     6,
       7,     0,     0,     8,     0,     0,     9,     0,     0,    12,
       0,     0,    14,    15,    16,    17,    18,     0,     0,    19,
      20,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,     5,
       6,     7,     0,     0,     8,     0,     0,     9,     0,     0,
      12,     0,     0,    14,    15,    16,    17,    18,     0,   372,
      19,    20,     0,     0,     0,    21,   190,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
       0,    36,    37,    38,    39,     0,    41,    42,    43,     0,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
       0,     0,     0,     0,   592,     0,     0,    28,    29,    30,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    15,
       0,     0,    36,    37,    38,    39,     0,    41,    42,    43,
      21,    44,    45,    46,    47,    23,    48,    49,    50,    51,
      52,     5,     6,     7,     0,     0,     8,     0,     0,     9,
       0,     0,    12,     0,     0,    14,    15,    16,    17,    18,
       0,     0,    19,    20,     0,    25,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    15,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,    21,     0,     0,    38,
      39,    23,    41,    42,    43,     0,    44,    45,   126,     0,
       0,     0,     0,     0,    51,    52,     0,     0,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,    34,
      35,   600,     0,     0,    36,    37,    38,    39,   190,    41,
      42,    43,   601,    44,    45,    46,    47,    15,    48,    49,
      50,    51,    52,     0,     0,     0,     0,     0,    21,     0,
      30,     0,     0,    23,     0,     0,     0,     0,    34,    35,
     126,     0,     0,     0,     0,    38,    39,     0,    41,    42,
      43,     0,    44,    45,     0,     0,    15,     0,     0,     0,
      51,    52,     0,   230,     0,     0,     0,    21,     0,     0,
       0,     0,    23,    15,   128,     0,     0,     0,     0,   126,
       0,     0,     0,     0,    21,     0,     0,     0,     0,    23,
       0,     0,    30,     0,     0,     0,   126,     0,     0,     0,
      34,    35,   351,     0,     0,     0,     0,    38,    39,     0,
      41,    42,    43,   128,    44,    45,     0,     0,     0,   528,
       0,     0,    51,    52,     0,     0,    15,     0,     0,     0,
     334,    30,     0,     0,     0,     0,     0,    21,     0,    34,
      35,     0,    23,     0,     0,     0,    38,    39,    30,    41,
      42,    43,     0,    44,    45,     0,    34,    35,    15,     0,
       0,    51,    52,    38,    39,     0,    41,    42,    43,    21,
      44,    45,   337,     0,    23,     0,     0,     0,    51,    52,
       0,   126,    15,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,   666,     0,     0,     0,     0,    34,
      35,     0,     0,     0,     0,   334,    38,    39,     0,    41,
      42,    43,     0,    44,    45,     0,     0,     0,   372,     0,
       0,    51,    52,    30,     0,   190,     0,     0,     0,   373,
       0,    34,    35,     0,     0,     0,     0,     0,    38,    39,
       0,    41,    42,    43,     0,    44,    45,    30,     0,     0,
       0,     0,     0,    51,    52,    34,    35,     0,     0,     0,
       0,     0,    38,    39,     0,    41,    42,    43,     0,    44,
      45,   630,     0,     0,   631,   632,     0,    51,    52,     0,
       0,   633,     0,     0,     0,     0,     0,   634,   635,     0,
       0,   636,   637,   246,     0,   638,   639,     0,   640,   641,
     248,   249,   250,   251,   252,   253,   107,     0,   254,   255,
       0,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,     0,     0,     0,   550,     0,     0,     0,     0,   258,
     259,   260,   261,   262,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     265,    31,    32,    33,     0,     0,     0,     0,   266,   267,
     268,   246,     0,     0,     0,   269,     0,   762,   248,   249,
     250,   251,   252,   253,     0,     0,   254,   255,     0,     0,
       0,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,     0,     0,
       0,     0,   763,   866,   764,     0,   765,   258,   259,   260,
     261,   262,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   265,     0,
       0,     0,     0,     0,     0,     0,   266,   267,   268,   246,
       0,     0,     0,   269,     0,   247,   248,   249,   250,   251,
     252,   253,     0,     0,   254,   255,     0,     0,     0,     0,
       0,   246,   256,     0,     0,     0,     0,   247,   248,   249,
     250,   251,   252,   253,     0,   257,   254,   255,     0,     0,
       0,     0,     0,   313,   256,   258,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,     0,   257,   561,     0,
       0,     0,     0,     0,     0,   264,   265,   258,   259,   260,
     261,   262,   263,     0,   266,   267,   268,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,   264,   265,     0,
       0,     0,     0,     0,     0,     0,   266,   267,   268,   246,
       0,     0,     0,   269,     0,   247,   248,   249,   250,   251,
     252,   253,     0,     0,   254,   255,     0,     0,     0,     0,
       0,   246,   256,     0,     0,     0,     0,   247,   248,   249,
     250,   251,   252,   253,     0,   257,   254,   255,     0,     0,
       0,     0,     0,     0,   256,   258,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,     0,   257,   586,     0,
       0,     0,   678,     0,     0,   264,   265,   258,   259,   260,
     261,   262,   263,     0,   266,   267,   268,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,   264,   265,     0,
       0,     0,     0,     0,     0,     0,   266,   267,   268,   246,
       0,     0,     0,   269,     0,   247,   248,   249,   250,   251,
     252,   253,     0,     0,   254,   255,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,   727,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   265,     0,     0,     0,
       0,     0,     0,     0,   266,   267,   268,   246,     0,     0,
       0,   269,     0,   247,   248,   249,   250,   251,   252,   253,
       0,     0,   254,   255,     0,     0,     0,     0,     0,   246,
     256,     0,     0,     0,     0,   247,   248,   249,   250,   251,
     252,   253,     0,   257,   254,   255,     0,     0,   763,     0,
       0,     0,   256,   258,   259,   260,   261,   262,   263,     0,
       0,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   258,   259,   260,   261,   262,
     263,     0,   266,   267,   268,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,   264,   265,     0,     0,     0,
       0,     0,     0,     0,   266,   267,   268,   246,     0,     0,
       0,   269,     0,   247,   248,   249,   250,   251,   252,   253,
       0,     0,   254,   255,     0,     0,     0,     0,     0,   246,
     256,     0,     0,     0,     0,   247,   248,   249,   250,   251,
     252,   253,     0,   361,   254,   255,     0,     0,     0,     0,
       0,     0,   256,   258,   259,   260,   261,   262,   263,     0,
       0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,   264,   265,   258,   259,   260,   261,   262,
     263,     0,   266,   267,   268,     0,     0,     0,     0,   269,
       0,     0,     0,     0,     0,   264,   265,     0,     0,     0,
       0,     0,     0,     0,   266,   267,   268,   246,     0,     0,
       0,   269,     0,   247,   248,   249,   250,   251,   252,   253,
       0,     0,   254,   255,     0,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,   260,   261,   262,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   265,     0,     0,     0,     0,     0,
       0,     0,   266,   267,   268,     0,     0,     0,     0,   269
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,     2,     2,   179,    40,   234,   341,
      58,   237,   270,   271,     9,     9,   242,   312,   196,    99,
     620,   226,   372,   775,    26,   230,   322,   372,   124,   633,
     615,   423,     9,   425,   102,   103,   201,   202,    40,    40,
      40,    40,     2,    36,    36,    35,   127,   128,     0,    72,
     345,    74,   533,    76,    64,    78,    36,    35,    54,    82,
      36,   269,   190,    35,    42,   257,    26,   543,   544,   545,
      42,    89,   594,    89,    66,    65,    35,    65,    66,    72,
      40,   833,    72,    42,   257,   293,    76,    65,    67,    70,
      78,    79,    88,    77,    78,    35,    91,    91,    76,    71,
      48,    49,    42,    63,    64,    65,    66,    65,    88,    88,
      88,    89,    88,    67,    91,   110,   110,    76,    35,   121,
     121,    35,    65,    66,   121,    42,   128,   122,    42,   124,
      65,    66,   736,    67,    35,    83,    84,    72,    73,    74,
      75,    76,    77,    78,    79,   226,   351,    82,    83,   230,
     231,    66,    65,    66,    71,   115,    53,    71,    65,    72,
      73,   326,   102,   103,    65,    72,    65,   359,   128,   361,
     428,   429,   430,   431,    35,    76,   368,   369,   211,    65,
     702,    42,    66,   128,   706,   707,   359,    88,   361,   317,
      87,   186,   186,    36,   402,   403,   404,    67,   590,   680,
      91,    35,    35,     2,   214,    35,    54,   399,    42,   211,
     211,   221,   385,    67,    54,   217,   217,    71,   550,    89,
     217,   517,    65,   519,   219,    73,   399,   215,   216,    67,
      67,    70,    65,    73,    71,    65,   234,    71,    35,   237,
      36,    40,   240,    76,   242,    42,    76,   420,    70,   853,
     600,    89,   333,   334,   127,   600,    67,    89,   608,   355,
     356,   357,   358,   608,    63,    64,    65,    66,    65,    65,
     351,   231,   215,   216,    67,    97,    98,    99,    89,    76,
     215,   216,   882,   271,   760,   761,   231,   275,    70,    67,
     894,    88,    35,    71,   185,   186,    89,    35,   189,    42,
     558,    89,   215,   216,    42,    62,   532,    35,   534,   535,
     312,   312,   312,   312,    42,    89,   115,    74,    75,   614,
      70,   526,    65,   528,    65,    70,   190,    65,   271,    72,
     626,    72,   334,    76,    35,    76,   338,    65,    76,    72,
     548,    42,    65,   345,   345,   345,   345,   427,    76,   934,
      67,    70,    70,   226,   939,   880,    73,   230,   271,   272,
     355,   356,   357,   358,    67,    36,   257,    35,    71,    70,
      70,   373,   137,   138,   139,   140,   141,   858,   903,    97,
      98,    99,   246,    70,   512,   150,   151,   381,   913,   334,
     254,   255,   386,    35,   159,   160,    35,    65,   879,   317,
      42,   102,   103,    42,    72,   269,    65,    66,    76,   432,
      97,    98,    99,    72,   213,   214,   215,   216,   309,   218,
      46,    47,   221,    65,   426,   426,    72,   291,    74,   293,
      65,    70,   231,    25,    76,   643,    67,    72,    70,    35,
      71,   115,   430,   431,    90,   526,    42,   528,   529,    65,
      66,     2,    66,   317,   712,    35,    72,    66,   586,   717,
     333,   666,    42,   102,   103,    97,    98,    99,   359,    65,
     361,    43,    44,    45,    25,    26,    50,    51,   351,    70,
      76,    70,   814,   428,   429,    66,    67,   430,   431,    40,
      35,   683,   684,    65,    66,   430,   431,   432,   433,    35,
      72,    72,    74,    74,   632,    70,    42,    70,   399,    65,
      66,    65,    63,    64,    65,    66,    72,   430,   431,    90,
      66,    67,   524,   524,   524,   524,    76,   859,    97,    98,
      99,    81,    82,   531,   532,   127,   534,   535,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,    66,    67,    65,   732,
      65,    72,    66,    74,   115,   738,   694,    36,   741,   742,
     698,    85,   668,   669,   339,   340,   127,   128,   756,    90,
      43,    44,    45,   593,   529,   666,    75,   589,   589,   591,
     591,    66,    67,    86,   512,    52,   822,   645,   646,   601,
     405,   406,    65,    70,   700,    70,   594,   609,   704,    72,
     643,    74,   614,   614,   614,   614,    90,   713,   714,   715,
     716,    73,   718,   719,    66,    67,    65,    66,    35,   428,
     429,   430,   431,    72,   226,    66,   764,    66,   230,   649,
      70,   643,   643,   637,    66,    67,    70,   825,   512,    67,
     828,   594,    67,   526,    73,   528,   601,   753,   409,   410,
     411,   412,   650,   651,    66,   667,   667,   667,   667,    65,
      66,    65,    66,   668,   669,   226,   804,    97,    72,   230,
     231,   594,   855,    67,   548,   863,    82,    83,   648,   649,
     650,   651,    65,   113,   696,   696,    66,   793,   794,   709,
      66,    67,   880,    66,    67,   700,   126,   650,   651,   704,
     838,    66,    67,   179,   632,   650,   651,    66,   713,   714,
     715,   716,   586,   718,   719,   903,   904,   600,    90,   902,
     529,   530,    66,    67,    67,   913,   914,   650,   651,    67,
     868,   333,   744,   744,    67,   337,   924,   744,   926,   407,
     408,   413,   414,    66,   927,   933,    66,    66,   753,   351,
      66,    35,    66,   891,    71,    66,    66,   712,   632,   370,
      35,    65,    89,    89,   776,   776,   776,   776,    65,   643,
     698,   179,   333,   384,    65,   205,   337,   207,    65,    88,
      88,   257,    88,   666,   593,   594,    88,   398,   793,   794,
     351,    89,    71,    67,    70,    66,    88,    34,    71,   229,
      89,    71,    70,   815,   815,    65,   524,    89,   815,   215,
     216,   422,   820,    65,   822,    71,    88,    71,    66,    66,
     694,    71,    89,   179,   698,    65,    70,   602,   603,    70,
     605,   606,    70,   551,    70,   610,   764,   612,    66,   648,
     649,   650,   651,    67,    66,    65,    66,   179,    66,   257,
      89,   179,    72,    73,    74,    75,    76,    77,    78,    79,
      89,    88,    82,    83,     8,   271,   878,   878,   878,   878,
     276,   589,    89,   591,    88,    67,   804,    89,    73,    89,
      71,    88,    66,   359,    73,   361,   898,   898,   898,   898,
     764,   638,   368,   369,    73,   115,    71,    67,   707,    67,
     709,   257,    88,   712,   312,    88,   336,    88,   717,    40,
     838,   707,   709,   706,   321,   614,   346,   347,   348,   367,
     350,   331,   768,   399,   526,   257,   528,   763,   769,   257,
     804,   744,   682,   621,   415,   417,   416,   345,     2,   726,
     868,   419,   372,   828,   418,   904,   926,   344,   439,   667,
     426,   359,   198,   361,    -1,    -1,    -1,    -1,    -1,    -1,
     368,   369,    -1,   891,   838,   526,    -1,   528,    -1,    -1,
     745,   746,   747,   748,   749,   750,   751,   752,   696,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
     737,   399,    -1,    -1,   868,   215,   216,    -1,   600,    -1,
      -1,    -1,    -1,   359,    -1,   361,   608,    -1,    -1,    65,
     621,   231,   368,   369,    -1,    -1,    -1,   891,   426,    -1,
      -1,    -1,    -1,    -1,   430,   431,    -1,   359,    -1,   361,
      -1,   359,    -1,   361,    -1,    -1,   368,   369,    -1,   600,
     368,   369,    -1,   399,    -1,    -1,    -1,   608,    -1,    -1,
     106,   271,   272,   273,   274,   275,   276,    -1,   805,    -1,
     671,    -1,    -1,    -1,   666,    -1,    -1,   399,    -1,    -1,
     426,   399,    -1,    -1,    -1,    -1,    -1,   824,    -1,   690,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   648,   649,   650,
     651,    -1,    -1,    -1,   426,    -1,    -1,   527,   426,    -1,
      -1,    -1,    -1,   850,    -1,   666,    -1,    -1,    -1,   856,
     857,   541,    -1,   589,    -1,   591,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   873,    -1,    13,    14,
      -1,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,   896,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,    -1,    -1,
     878,    -1,    -1,    -1,   775,    -1,    -1,    -1,    -1,    -1,
     600,    -1,   919,    -1,    -1,    -1,    -1,    -1,   608,    -1,
     898,   589,    -1,   591,    -1,    -1,    -1,    19,   594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   614,   683,   684,    94,
     430,   431,   432,   433,    -1,    -1,    -1,   102,   103,    -1,
     696,    -1,   833,    -1,   109,   110,    -1,   112,   113,   114,
      -1,   116,   117,   589,    -1,   591,   121,   122,   123,   124,
     125,    -1,    -1,    -1,   650,   651,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   686,   589,    -1,   591,
      -1,   589,    94,   591,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,   683,   684,   109,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,    -1,   696,   121,
     122,   123,   124,   125,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,   529,
     530,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   683,   684,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    70,   558,    72,
     696,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,   683,   684,    -1,    -1,   683,   684,    -1,    -1,    -1,
      -1,    -1,    95,    96,   696,    -1,    -1,    -1,   696,    -1,
      -1,   104,   105,   106,   594,    -1,    -1,    -1,   111,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
     650,   651,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,   664,    -1,    -1,    70,    71,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   712,   116,   117,   118,   119,   717,   121,   122,
     123,   124,   125,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    19,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      30,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,   119,
      -1,   121,   122,   123,   124,   125,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,   107,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     3,
       4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    -1,    -1,    29,    30,    -1,    -1,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   116,   117,   118,   119,    -1,   121,   122,   123,
     124,   125,     3,     4,     5,     6,    -1,    -1,     9,    -1,
      -1,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    65,    -1,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    -1,    76,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    89,    -1,
      33,    92,    93,    94,    -1,    -1,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,   117,   118,   119,    -1,
     121,   122,   123,   124,   125,     3,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    92,
      93,    94,    30,    -1,    -1,    33,    -1,    35,    -1,   102,
     103,    -1,    -1,    -1,    42,   108,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,   124,   125,    -1,    -1,    -1,    -1,    65,    -1,    -1,
       3,    -1,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    30,    -1,    -1,
      33,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,   112,   113,   114,    -1,   116,   117,
     118,   119,    -1,   121,   122,   123,   124,   125,     3,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    89,    -1,    33,    -1,
      35,    94,    -1,    -1,    -1,    -1,    -1,    42,    -1,   102,
     103,    -1,    -1,    -1,    -1,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
      65,   124,   125,     3,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    13,    14,    -1,    16,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      30,    -1,    -1,    33,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,   107,   108,   109,   110,    -1,   112,   113,   114,
      -1,   116,   117,   118,   119,    -1,   121,   122,   123,   124,
     125,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    94,    -1,    -1,    -1,    -1,    -1,
      42,    -1,   102,   103,    -1,    -1,    -1,   107,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,     3,
      -1,    -1,    -1,    65,   124,   125,    -1,    -1,    -1,    13,
      14,    -1,    16,    -1,    76,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      94,    30,    -1,    -1,    33,    -1,    35,    -1,   102,   103,
      -1,    -1,    -1,    42,    -1,   109,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
     124,   125,    -1,     4,     5,    -1,    65,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    76,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,    -1,   121,   122,   123,   124,   125,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    92,    93,    94,    30,    -1,    -1,    33,    -1,    35,
      -1,   102,   103,    -1,    -1,    -1,    42,   108,   109,   110,
      -1,   112,   113,   114,    -1,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      28,    -1,    30,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,   112,   113,   114,    -1,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
       3,     4,     5,     6,    -1,    -1,     9,    65,    -1,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    -1,    -1,    -1,    94,    -1,    -1,    42,
      -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,
      -1,   109,   110,    -1,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    65,    -1,    -1,    -1,   124,   125,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,   118,   119,    -1,   121,   122,
     123,   124,   125,     3,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    65,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,
     110,    70,   112,   113,   114,    -1,   116,   117,   118,   119,
      -1,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,   116,   117,   118,
     119,    -1,   121,   122,   123,   124,   125,     3,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    42,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,     3,     4,     5,     6,    -1,    -1,
       9,    -1,    -1,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    -1,    35,    -1,     3,     4,
       5,     6,    -1,    42,     9,    -1,    -1,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,   112,   113,   114,    -1,   116,   117,   118,
     119,    -1,   121,   122,   123,   124,   125,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    19,
      -1,    -1,   107,   108,   109,   110,    -1,   112,   113,   114,
      30,   116,   117,   118,   119,    35,   121,   122,   123,   124,
     125,     3,     4,     5,     6,    -1,    -1,     9,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    65,    -1,    -1,    30,    -1,
      -1,    33,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    -1,    -1,    -1,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,   110,    -1,
     112,   113,   114,    -1,   116,   117,   118,   119,    -1,   121,
     122,   123,   124,   125,     4,     5,     6,    -1,    -1,     9,
      -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    30,    -1,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,   119,
      -1,   121,   122,   123,   124,   125,     4,     5,     6,    -1,
      -1,     9,    -1,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    94,    -1,    -1,    42,    -1,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,    -1,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,    -1,    65,    -1,    -1,
      -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,   112,   113,   114,    -1,   116,   117,
     118,   119,    -1,   121,   122,   123,   124,   125,     4,     5,
       6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,     4,
       5,     6,    -1,    -1,     9,    -1,    -1,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    22,    -1,    65,
      25,    26,    -1,    -1,    -1,    30,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,   107,   108,   109,   110,    -1,   112,   113,   114,    -1,
     116,   117,   118,   119,    -1,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    19,
      -1,    -1,   107,   108,   109,   110,    -1,   112,   113,   114,
      30,   116,   117,   118,   119,    35,   121,   122,   123,   124,
     125,     4,     5,     6,    -1,    -1,     9,    -1,    -1,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    26,    -1,    65,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    19,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,    -1,    -1,    30,    -1,    -1,   109,
     110,    35,   112,   113,   114,    -1,   116,   117,    42,    -1,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
     103,    65,    -1,    -1,   107,   108,   109,   110,    72,   112,
     113,   114,    76,   116,   117,   118,   119,    19,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      94,    -1,    -1,    35,    -1,    -1,    -1,    -1,   102,   103,
      42,    -1,    -1,    -1,    -1,   109,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    19,    -1,    -1,    -1,
     124,   125,    -1,    65,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    19,    76,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    94,    -1,    -1,    -1,    42,    -1,    -1,    -1,
     102,   103,    65,    -1,    -1,    -1,    -1,   109,   110,    -1,
     112,   113,   114,    76,   116,   117,    -1,    -1,    -1,    65,
      -1,    -1,   124,   125,    -1,    -1,    19,    -1,    -1,    -1,
      76,    94,    -1,    -1,    -1,    -1,    -1,    30,    -1,   102,
     103,    -1,    35,    -1,    -1,    -1,   109,   110,    94,   112,
     113,   114,    -1,   116,   117,    -1,   102,   103,    19,    -1,
      -1,   124,   125,   109,   110,    -1,   112,   113,   114,    30,
     116,   117,    65,    -1,    35,    -1,    -1,    -1,   124,   125,
      -1,    42,    19,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    65,    -1,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,    76,   109,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,    -1,    -1,    65,    -1,
      -1,   124,   125,    94,    -1,    72,    -1,    -1,    -1,    76,
      -1,   102,   103,    -1,    -1,    -1,    -1,    -1,   109,   110,
      -1,   112,   113,   114,    -1,   116,   117,    94,    -1,    -1,
      -1,    -1,    -1,   124,   125,   102,   103,    -1,    -1,    -1,
      -1,    -1,   109,   110,    -1,   112,   113,   114,    -1,   116,
     117,     7,    -1,    -1,    10,    11,    -1,   124,   125,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,   104,   105,
     106,    29,    -1,    -1,    -1,   111,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    29,
      -1,    -1,    -1,   111,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    29,    52,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    65,    44,    45,    -1,    -1,
      -1,    -1,    -1,    73,    52,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    75,    76,    77,
      78,    79,    80,    -1,   104,   105,   106,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    29,
      -1,    -1,    -1,   111,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    29,    52,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    65,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    65,    88,    -1,
      -1,    -1,    70,    -1,    -1,    95,    96,    75,    76,    77,
      78,    79,    80,    -1,   104,   105,   106,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,    29,
      -1,    -1,    -1,   111,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,    29,    -1,    -1,
      -1,   111,    -1,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    29,
      52,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    65,    44,    45,    -1,    -1,    70,    -1,
      -1,    -1,    52,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    75,    76,    77,    78,    79,
      80,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,    29,    -1,    -1,
      -1,   111,    -1,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    29,
      52,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    65,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    75,    76,    77,    78,    79,
      80,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,    29,    -1,    -1,
      -1,   111,    -1,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,   111
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   128,   129,     0,     3,     4,     5,     6,     9,    12,
      13,    14,    15,    16,    18,    19,    20,    21,    22,    25,
      26,    30,    33,    35,    42,    65,    76,    89,    92,    93,
      94,    97,    98,    99,   102,   103,   107,   108,   109,   110,
     111,   112,   113,   114,   116,   117,   118,   119,   121,   122,
     123,   124,   125,   130,   131,   132,   133,   134,   135,   139,
     140,   141,   142,   143,   144,   145,   146,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   181,   211,   212,   213,   214,   215,   216,   217,
     218,   275,   276,   281,   282,   293,    35,    42,    70,   190,
     274,   275,   213,   215,   217,   146,   211,   217,   133,   140,
     301,   301,    67,   302,    67,   302,    42,    65,    76,   202,
     203,   204,   205,   206,   207,   208,   209,   211,   217,   202,
     211,   217,    42,   147,   148,   161,   165,   166,   167,   170,
     211,   217,    42,   148,   161,   165,   166,   167,   170,   211,
     217,   147,   167,   148,   166,   167,   147,   302,   148,   166,
     302,   147,   148,   166,   147,   161,   148,   161,   166,    65,
     147,   165,   148,   165,   166,   190,   274,   298,   296,    65,
      72,   220,   222,   296,    65,    89,    65,    35,    42,   182,
     183,    70,    70,   190,   275,    66,    66,    66,   211,   217,
      70,   111,   139,   143,   144,   145,   146,   234,   273,   274,
      89,   273,    89,    65,   220,    42,    65,   206,   208,   210,
      65,   146,   205,   208,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,    89,    89,    29,    35,    36,    37,
      38,    39,    40,    41,    44,    45,    52,    65,    75,    76,
      77,    78,    79,    80,    95,    96,   104,   105,   106,   111,
     144,   146,   154,   156,   158,   160,   164,   191,   239,   240,
     241,   242,   243,   244,   245,   246,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   271,   298,   190,
     298,    70,   298,    73,   248,   267,   272,    72,    65,   240,
     297,   297,    67,    71,   182,   182,    70,   220,   220,   115,
     228,   229,   230,    65,    76,   211,   215,    65,    76,   211,
     211,    70,   139,   211,   202,   298,   210,    66,    66,   220,
     210,    65,   205,   208,   282,   283,   283,   283,   283,    65,
     248,    65,   248,   248,    35,   191,   271,   298,    65,    65,
      65,   256,    65,    76,   219,   220,   223,   224,   219,    66,
      36,    43,    44,    45,    65,    72,    74,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    90,   269,    65,
     248,   256,    76,    81,    82,    77,    78,    46,    47,    48,
      49,    83,    84,    50,    51,    75,    85,    86,    52,    53,
      87,    66,    67,    70,   298,    70,   173,    35,   143,   144,
     145,   146,   155,   156,   185,   186,   187,   188,   189,   221,
      73,   272,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   277,   278,
     280,    66,    90,   184,   184,    71,   183,    67,    71,    67,
      71,   182,    35,   231,   232,   230,    65,   215,    65,   146,
     146,   294,   294,   228,   295,   295,    66,   220,   220,    66,
      66,   210,   273,   273,   273,   273,   191,   191,    66,    66,
      70,   227,   191,   191,   268,   220,   223,   224,   146,   219,
     190,    66,   247,   268,   271,   190,   268,   191,   256,   256,
     256,   257,   257,   258,   258,   259,   259,   259,   259,   260,
     260,   261,   262,   263,   264,   265,    88,   271,   268,   173,
      70,   173,    89,   144,   146,   174,   175,   176,   299,   296,
      65,    76,   205,   211,   219,   205,   211,   219,    65,    76,
     211,   219,   211,   219,    67,    67,   300,   300,    73,    66,
      67,    65,   279,   272,    71,    71,    67,    71,    67,    89,
       7,    10,    11,    17,    23,    24,    27,    28,    31,    32,
      34,    35,    42,   111,   136,   137,   138,   139,   143,   144,
     145,   146,   190,   225,   226,   227,   233,   235,   236,   237,
     238,   270,   271,   284,   293,   299,    65,   232,   283,   283,
      66,    90,   192,   192,   192,   192,    66,    66,    70,   256,
     228,   299,    67,    67,    67,    66,    66,    66,   219,    66,
      67,    73,    66,   267,    88,   299,   173,   299,    88,    89,
     177,   180,   202,    89,   178,   180,   211,    67,    89,    67,
      89,    71,   146,   294,   294,   294,   294,   146,   294,   294,
      54,   187,   189,    66,    66,    66,   280,    66,   247,    71,
      35,    89,    65,   272,   270,    89,    65,    88,    76,   190,
     225,    65,    65,   301,   301,   211,   217,   211,   217,   211,
     217,   211,   217,    88,    89,    28,    65,   148,    71,   299,
     273,   273,    35,    70,    72,    74,   193,   194,   197,   198,
     199,   200,   201,   268,   195,   196,   232,    66,   245,   191,
     191,   220,   268,   267,    71,   299,    71,   272,   273,   179,
     180,   273,   179,   178,   177,   273,   273,   273,   273,   273,
     273,   279,    66,   271,    54,    88,    89,   270,   225,   271,
      89,    34,   271,   271,    70,   234,   294,   294,   294,   294,
     294,   294,   294,   294,   273,    65,   240,   285,    65,    71,
     192,   192,    88,   196,   272,    35,    42,   194,    72,    90,
     199,    71,   193,    71,    66,    66,    66,    71,   273,   273,
      66,   272,   225,    89,    89,    65,    66,    66,   228,    70,
     225,   240,   291,    88,    66,   285,    71,   193,    54,    73,
     272,    67,   225,    88,   270,   271,   225,   225,   232,   228,
      88,    66,    72,   240,   286,   287,   288,    89,    66,    71,
     272,    54,    73,   225,    89,    66,     8,   299,   232,   286,
      89,   280,    65,    88,    67,    89,    73,   272,   270,    89,
     225,    71,   299,    88,    73,   271,   286,   288,    73,    66,
      71,   286,   240,    66,    88,   225,    88,    65,   240,   290,
     289,   290,   271,    67,    88,    66,   240,   189,   292,    67,
     189
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
      

/* Line 1455 of yacc.c  */
#line 3208 "c.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



