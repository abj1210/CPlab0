/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"

    #define YYSTYPE tree_node*
    #include<stdio.h>
    
    #include "syntax_tree.h"
    #include "lex.yy.c"
    #include "flex.h"
    
    #define ERROR_MSG(line, msg, errrul) if(errstate==1){\
        fprintf(stderr, " Missing %s (rule %d at line %d)\n",msg, errrul, line);\
        errstate=0;\
        }
    #define EXP_ACTIONS1(EXPNAME, out, loc, e1) out=make_line_node(EXPNAME, loc.first_line);add_node(out, e1);
    #define EXP_ACTIONS2(EXPNAME, out, loc, e1, e2) \
        EXP_ACTIONS1(EXPNAME, out, loc, e1)\
        add_node(out, e2); 
    #define EXP_ACTIONS3(EXPNAME, out, loc, e1, e2, e3) \
        EXP_ACTIONS2(EXPNAME, out, loc, e1, e2)\
        add_node(out, e3);
    #define EXP_ACTIONS4(EXPNAME, out, loc, e1, e2, e3, e4) \
        EXP_ACTIONS3(EXPNAME, out, loc, e1, e2, e3)\
        add_node(out, e4); 
    #define EXP_ACTIONS5(EXPNAME, out, loc, e1, e2, e3, e4, e5) \
        EXP_ACTIONS4(EXPNAME, out, loc, e1, e2, e3, e4)\
        add_node(out, e5);
    #define EXP_ACTIONS6(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6) \
        EXP_ACTIONS5(EXPNAME, out, loc, e1, e2, e3, e4, e5)\
        add_node(out, e6); 
    #define EXP_ACTIONS7(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6, e7) \
        EXP_ACTIONS6(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6)\
        add_node(out, e7);

    int yyerror(char* msg);
    int errstate=0;
    

#line 108 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMI = 3,                       /* SEMI  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_RELGT = 6,                      /* RELGT  */
  YYSYMBOL_RELLT = 7,                      /* RELLT  */
  YYSYMBOL_RELGE = 8,                      /* RELGE  */
  YYSYMBOL_RELLE = 9,                      /* RELLE  */
  YYSYMBOL_RELEQ = 10,                     /* RELEQ  */
  YYSYMBOL_RELNE = 11,                     /* RELNE  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_STAR = 14,                      /* STAR  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_DOT = 18,                       /* DOT  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_ITYPE = 20,                     /* ITYPE  */
  YYSYMBOL_FTYPE = 21,                     /* FTYPE  */
  YYSYMBOL_LP = 22,                        /* LP  */
  YYSYMBOL_RP = 23,                        /* RP  */
  YYSYMBOL_LB = 24,                        /* LB  */
  YYSYMBOL_RB = 25,                        /* RB  */
  YYSYMBOL_LC = 26,                        /* LC  */
  YYSYMBOL_RC = 27,                        /* RC  */
  YYSYMBOL_STRUCT = 28,                    /* STRUCT  */
  YYSYMBOL_RETURN = 29,                    /* RETURN  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_INT = 33,                       /* INT  */
  YYSYMBOL_FLOAT = 34,                     /* FLOAT  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_REL = 36,                       /* REL  */
  YYSYMBOL_TYPE = 37,                      /* TYPE  */
  YYSYMBOL_RELOP = 38,                     /* RELOP  */
  YYSYMBOL_UMINUS = 39,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 40,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_ExtDefList = 43,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 44,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 45,                /* ExtDecList  */
  YYSYMBOL_Specifier = 46,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 47,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 48,                    /* OptTag  */
  YYSYMBOL_Tag = 49,                       /* Tag  */
  YYSYMBOL_VarDec = 50,                    /* VarDec  */
  YYSYMBOL_FunDec = 51,                    /* FunDec  */
  YYSYMBOL_VarList = 52,                   /* VarList  */
  YYSYMBOL_ParamDec = 53,                  /* ParamDec  */
  YYSYMBOL_CompSt = 54,                    /* CompSt  */
  YYSYMBOL_StmtList = 55,                  /* StmtList  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_DefList = 57,                   /* DefList  */
  YYSYMBOL_Def = 58,                       /* Def  */
  YYSYMBOL_DecList = 59,                   /* DecList  */
  YYSYMBOL_Dec = 60,                       /* Dec  */
  YYSYMBOL_Exp = 61,                       /* Exp  */
  YYSYMBOL_Args = 62                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    90,    90,    92,    93,    95,    96,    97,    98,   100,
     101,   104,   105,   107,   108,   110,   111,   113,   115,   116,
     117,   119,   120,   121,   123,   124,   126,   130,   131,   132,
     134,   135,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   148,   149,   151,   152,   154,   155,   157,   158,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   180,   181
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMI", "COMMA",
  "ASSIGN", "RELGT", "RELLT", "RELGE", "RELLE", "RELEQ", "RELNE", "PLUS",
  "MINUS", "STAR", "DIV", "AND", "OR", "DOT", "NOT", "ITYPE", "FTYPE",
  "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT", "RETURN", "IF", "ELSE",
  "WHILE", "INT", "FLOAT", "ID", "REL", "TYPE", "RELOP", "UMINUS",
  "LOWER_THAN_ELSE", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "OptTag", "Tag", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList",
  "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,     6,   -25,   -58,    16,   -58,    14,     4,   -58,   -58,
      -6,     0,   -58,   -58,   -58,    25,   -58,    30,    51,    23,
      17,    18,   -58,   -58,   124,   -58,     5,    27,    44,    40,
     -58,    53,     5,    54,    63,   -58,     5,    57,    79,    59,
     -58,   -58,    76,   -58,    53,    86,   -58,    33,    99,   100,
     -58,   -58,    83,   -58,   -16,   -58,    22,   299,   299,   299,
     299,    81,    87,   -58,   -58,    89,   -58,    90,    86,   169,
     299,   -58,     5,   -58,   -58,    70,    70,   217,   185,   132,
     136,   292,   -58,   -58,   -58,   299,   299,   299,   299,   299,
     299,   299,    88,   299,   299,   273,   -58,   -58,   -58,   -58,
     231,   -58,   245,   -58,   202,    91,   273,   305,   305,    70,
      70,   112,   286,   -58,   259,   273,   109,   109,   299,   -58,
     -58,    98,   -58,   -58,   109,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,    11,     0,     2,     0,     0,    12,     8,
      17,     0,    14,     1,     4,     0,     6,    18,     0,     9,
       0,     0,    23,    20,     0,     5,     0,     0,     0,     0,
       7,     0,     0,     0,     0,    22,     0,     0,    25,     0,
      18,    10,     0,    28,    29,     0,    44,    47,     0,    45,
      13,    42,    26,    21,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    65,    66,    64,    33,     0,     0,     0,
       0,    43,     0,    24,    38,    58,    59,     0,     0,     0,
       0,     0,    27,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    46,    57,    34,    39,
       0,    40,     0,    61,    68,     0,    49,    53,    54,    55,
      56,    50,    51,    63,     0,    52,     0,     0,     0,    60,
      62,    35,    37,    67,     0,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   126,   -58,   108,    11,   -58,   -58,   -58,   -28,
     -58,    92,   -58,   120,    82,   -38,    29,   -58,    84,   -58,
     -57,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    18,    32,     8,    11,    12,    19,
      20,    37,    38,    66,    67,    68,    33,    34,    48,    49,
      69,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      75,    76,    77,    78,    47,    15,    39,    16,    52,     9,
      10,     7,     2,    95,    -3,     1,    13,     7,    28,    31,
     -16,     3,   100,   102,   104,    74,    21,    26,   106,   107,
     108,   109,   110,   111,   112,    36,   114,   115,    70,    17,
      40,    44,     2,    29,    47,   -41,     2,    27,    22,    43,
      23,     3,    24,   -41,    25,     3,    46,    27,    45,   -41,
      42,   104,   -41,    51,    31,    36,   -41,   -41,     2,   -41,
     -41,    43,   -41,   -41,   -41,   -41,   -41,     3,   121,   122,
      53,    50,   -41,    54,    23,   -41,   125,    56,    92,   -41,
     -41,     2,   -41,   -41,    93,   -41,   -41,   -41,   -41,    57,
       3,    55,    71,    79,    72,    58,    94,    27,    59,    80,
      56,    81,    29,   -30,   119,    60,    61,    82,    62,    63,
      64,    65,    57,   113,    86,    87,    88,    89,    58,   124,
      92,    59,    14,    99,    41,    29,    93,   101,    60,    61,
      30,    62,    63,    64,    65,    57,    73,    35,    94,    57,
      83,    58,     2,   123,    59,    58,    96,     0,    59,     0,
       0,     3,     0,     0,     0,    63,    64,    65,     0,    63,
      64,    65,    84,     0,    85,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    98,     0,
      85,     0,     0,    93,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,     0,    94,   118,    85,     0,    93,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    94,    85,     0,     0,     0,    93,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    85,     0,    94,     0,
      97,    93,     0,    86,    87,    88,    89,    90,    91,    92,
      85,     0,     0,    94,   116,    93,     0,    86,    87,    88,
      89,    90,    91,    92,    85,     0,     0,    94,   117,    93,
       0,    86,    87,    88,    89,    90,    91,    92,    85,     0,
       0,    94,     0,    93,   120,    86,    87,    88,    89,    90,
      91,    92,     0,     0,     0,    94,     0,    93,    86,    87,
      88,    89,    90,     0,    92,    57,     0,     0,     0,    94,
      93,    58,    57,     0,    59,   103,     0,     0,    58,    88,
      89,    59,    94,    92,     0,    63,    64,    65,     0,    93,
       0,     0,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    94
};

static const yytype_int8 yycheck[] =
{
      57,    58,    59,    60,    32,     1,     1,     3,    36,     3,
      35,     0,    28,    70,     0,     1,     0,     6,     1,     1,
      26,    37,    79,    80,    81,     3,    26,     4,    85,    86,
      87,    88,    89,    90,    91,    24,    93,    94,     5,    35,
      35,     1,    28,    26,    72,    27,    28,    24,    23,    27,
      25,    37,    22,    13,     3,    37,     3,    24,    29,    19,
      33,   118,    22,    34,     1,    54,    26,    27,    28,    29,
      30,    27,    32,    33,    34,    35,    13,    37,   116,   117,
      23,    27,    19,     4,    25,    22,   124,     1,    18,    26,
      27,    28,    29,    30,    24,    32,    33,    34,    35,    13,
      37,    25,     3,    22,     4,    19,    36,    24,    22,    22,
       1,    22,    26,    27,    23,    29,    30,    27,    32,    33,
      34,    35,    13,    35,    12,    13,    14,    15,    19,    31,
      18,    22,     6,     1,    26,    26,    24,     1,    29,    30,
      20,    32,    33,    34,    35,    13,    54,    23,    36,    13,
      68,    19,    28,   118,    22,    19,    72,    -1,    22,    -1,
      -1,    37,    -1,    -1,    -1,    33,    34,    35,    -1,    33,
      34,    35,     3,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,     3,    -1,
       5,    -1,    -1,    24,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    -1,    36,     4,     5,    -1,    24,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    36,     5,    -1,    -1,    -1,    24,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,     5,    -1,    36,    -1,
      23,    24,    -1,    12,    13,    14,    15,    16,    17,    18,
       5,    -1,    -1,    36,    23,    24,    -1,    12,    13,    14,
      15,    16,    17,    18,     5,    -1,    -1,    36,    23,    24,
      -1,    12,    13,    14,    15,    16,    17,    18,     5,    -1,
      -1,    36,    -1,    24,    25,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    36,    -1,    24,    12,    13,
      14,    15,    16,    -1,    18,    13,    -1,    -1,    -1,    36,
      24,    19,    13,    -1,    22,    23,    -1,    -1,    19,    14,
      15,    22,    36,    18,    -1,    33,    34,    35,    -1,    24,
      -1,    -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    28,    37,    42,    43,    44,    46,    47,     3,
      35,    48,    49,     0,    43,     1,     3,    35,    45,    50,
      51,    26,    23,    25,    22,     3,     4,    24,     1,    26,
      54,     1,    46,    57,    58,    23,    46,    52,    53,     1,
      35,    45,    33,    27,     1,    57,     3,    50,    59,    60,
      27,    57,    50,    23,     4,    25,     1,    13,    19,    22,
      29,    30,    32,    33,    34,    35,    54,    55,    56,    61,
       5,     3,     4,    52,     3,    61,    61,    61,    61,    22,
      22,    22,    27,    55,     3,     5,    12,    13,    14,    15,
      16,    17,    18,    24,    36,    61,    59,    23,     3,     1,
      61,     1,    61,    23,    61,    62,    61,    61,    61,    61,
      61,    61,    61,    35,    61,    61,    23,    23,     4,    23,
      25,    56,    56,    62,    31,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    49,    50,    50,
      50,    51,    51,    51,    52,    52,    53,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     2,     1,
       3,     1,     1,     5,     2,     0,     1,     1,     1,     4,
       2,     4,     3,     2,     3,     1,     2,     4,     2,     2,
       0,     2,     2,     1,     3,     5,     7,     5,     2,     3,
       3,     0,     2,     3,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       4,     3,     4,     3,     1,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 90 "parser.y"
                     {EXP_ACTIONS1("Program", yyval, (yyloc), yyvsp[0]) add_node(NULL, yyval);}
#line 1396 "parser.tab.c"
    break;

  case 3: /* ExtDefList: %empty  */
#line 92 "parser.y"
             {yyval=NULL;}
#line 1402 "parser.tab.c"
    break;

  case 4: /* ExtDefList: ExtDef ExtDefList  */
#line 93 "parser.y"
                            {EXP_ACTIONS2("ExtDefList", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1408 "parser.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 95 "parser.y"
                                   {EXP_ACTIONS3("ExtDef", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1414 "parser.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 96 "parser.y"
                         {EXP_ACTIONS2("ExtDef", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1420 "parser.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 97 "parser.y"
                                  {EXP_ACTIONS3("ExtDef", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1426 "parser.tab.c"
    break;

  case 8: /* ExtDef: error SEMI  */
#line 98 "parser.y"
                    {ERROR_MSG((yylsp[-1]).first_line,"\";\" ", 98)}
#line 1432 "parser.tab.c"
    break;

  case 9: /* ExtDecList: VarDec  */
#line 100 "parser.y"
                    {EXP_ACTIONS1("ExtDecList", yyval, (yyloc), yyvsp[0])}
#line 1438 "parser.tab.c"
    break;

  case 10: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 101 "parser.y"
                                  {EXP_ACTIONS3("ExtDecList", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1444 "parser.tab.c"
    break;

  case 11: /* Specifier: TYPE  */
#line 104 "parser.y"
                 {EXP_ACTIONS1("Specifier", yyval, (yyloc), yyvsp[0])}
#line 1450 "parser.tab.c"
    break;

  case 12: /* Specifier: StructSpecifier  */
#line 105 "parser.y"
                          {EXP_ACTIONS1("Specifier", yyval, (yyloc), yyvsp[0])}
#line 1456 "parser.tab.c"
    break;

  case 13: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 107 "parser.y"
                                              {EXP_ACTIONS5("StructSpecifier", yyval, (yyloc), yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1462 "parser.tab.c"
    break;

  case 14: /* StructSpecifier: STRUCT Tag  */
#line 108 "parser.y"
                     {EXP_ACTIONS2("StructSpecifier", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1468 "parser.tab.c"
    break;

  case 15: /* OptTag: %empty  */
#line 110 "parser.y"
         {yyval=NULL;}
#line 1474 "parser.tab.c"
    break;

  case 16: /* OptTag: ID  */
#line 111 "parser.y"
             {EXP_ACTIONS1("OptTag", yyval, (yyloc), yyvsp[0])}
#line 1480 "parser.tab.c"
    break;

  case 17: /* Tag: ID  */
#line 113 "parser.y"
         {EXP_ACTIONS1("Tag", yyval, (yyloc), yyvsp[0])}
#line 1486 "parser.tab.c"
    break;

  case 18: /* VarDec: ID  */
#line 115 "parser.y"
            {EXP_ACTIONS1("VarDec", yyval, (yyloc), yyvsp[0])}
#line 1492 "parser.tab.c"
    break;

  case 19: /* VarDec: VarDec LB INT RB  */
#line 116 "parser.y"
                           {EXP_ACTIONS4("VarDec", yyval, (yyloc), yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1498 "parser.tab.c"
    break;

  case 20: /* VarDec: error RB  */
#line 117 "parser.y"
                   {ERROR_MSG((yylsp[-1]).first_line,"\"]\" ", 117)}
#line 1504 "parser.tab.c"
    break;

  case 21: /* FunDec: ID LP VarList RP  */
#line 119 "parser.y"
                          {EXP_ACTIONS4("FunDec", yyval, (yyloc), yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1510 "parser.tab.c"
    break;

  case 22: /* FunDec: ID LP RP  */
#line 120 "parser.y"
                   {EXP_ACTIONS3("FunDec", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1516 "parser.tab.c"
    break;

  case 23: /* FunDec: error RP  */
#line 121 "parser.y"
                   {ERROR_MSG((yylsp[-1]).first_line,"\")\" ", 120)}
#line 1522 "parser.tab.c"
    break;

  case 24: /* VarList: ParamDec COMMA VarList  */
#line 123 "parser.y"
                                 {EXP_ACTIONS3("VarList", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1528 "parser.tab.c"
    break;

  case 25: /* VarList: ParamDec  */
#line 124 "parser.y"
                   {EXP_ACTIONS1("VarList", yyval, (yyloc), yyvsp[0])}
#line 1534 "parser.tab.c"
    break;

  case 26: /* ParamDec: Specifier VarDec  */
#line 126 "parser.y"
                            {EXP_ACTIONS2("ParamDec", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1540 "parser.tab.c"
    break;

  case 27: /* CompSt: LC DefList StmtList RC  */
#line 130 "parser.y"
                                {EXP_ACTIONS4("CompSt", yyval, (yyloc), yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1546 "parser.tab.c"
    break;

  case 28: /* CompSt: error RC  */
#line 131 "parser.y"
                   {ERROR_MSG((yylsp[-1]).first_line,"\"{\" ", 130)}
#line 1552 "parser.tab.c"
    break;

  case 29: /* CompSt: LC error  */
#line 132 "parser.y"
                   {ERROR_MSG((yylsp[0]).first_line,"\"}\" ", 131)}
#line 1558 "parser.tab.c"
    break;

  case 30: /* StmtList: %empty  */
#line 134 "parser.y"
           {yyval=NULL;}
#line 1564 "parser.tab.c"
    break;

  case 31: /* StmtList: Stmt StmtList  */
#line 135 "parser.y"
                        {EXP_ACTIONS2("StmtList", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1570 "parser.tab.c"
    break;

  case 32: /* Stmt: Exp SEMI  */
#line 137 "parser.y"
                {EXP_ACTIONS2("Stmt", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1576 "parser.tab.c"
    break;

  case 33: /* Stmt: CompSt  */
#line 138 "parser.y"
                 {EXP_ACTIONS1("Stmt", yyval, (yyloc), yyvsp[0])}
#line 1582 "parser.tab.c"
    break;

  case 34: /* Stmt: RETURN Exp SEMI  */
#line 139 "parser.y"
                          {EXP_ACTIONS3("Stmt", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1588 "parser.tab.c"
    break;

  case 35: /* Stmt: IF LP Exp RP Stmt  */
#line 140 "parser.y"
                            {EXP_ACTIONS5("Stmt", yyval, (yyloc), yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1594 "parser.tab.c"
    break;

  case 36: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 141 "parser.y"
                                      {EXP_ACTIONS7("Stmt", yyval, (yyloc), yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1600 "parser.tab.c"
    break;

  case 37: /* Stmt: WHILE LP Exp RP Stmt  */
#line 142 "parser.y"
                               {EXP_ACTIONS5("Stmt", yyval, (yyloc), yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1606 "parser.tab.c"
    break;

  case 38: /* Stmt: error SEMI  */
#line 143 "parser.y"
                    {ERROR_MSG((yylsp[-1]).first_line,"\";\" ", 141)}
#line 1612 "parser.tab.c"
    break;

  case 39: /* Stmt: IF LP error  */
#line 144 "parser.y"
                      {ERROR_MSG((yylsp[-2]).first_line,"\")\" ", 142)}
#line 1618 "parser.tab.c"
    break;

  case 40: /* Stmt: WHILE LP error  */
#line 145 "parser.y"
                         {ERROR_MSG((yylsp[-2]).first_line,"\")\" ", 143)}
#line 1624 "parser.tab.c"
    break;

  case 41: /* DefList: %empty  */
#line 148 "parser.y"
          {yyval=NULL;}
#line 1630 "parser.tab.c"
    break;

  case 42: /* DefList: Def DefList  */
#line 149 "parser.y"
                      {EXP_ACTIONS2("DefList", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1636 "parser.tab.c"
    break;

  case 43: /* Def: Specifier DecList SEMI  */
#line 151 "parser.y"
                             {EXP_ACTIONS3("Def", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1642 "parser.tab.c"
    break;

  case 44: /* Def: error SEMI  */
#line 152 "parser.y"
                    {ERROR_MSG((yylsp[-1]).first_line,"\";\" ", 149)}
#line 1648 "parser.tab.c"
    break;

  case 45: /* DecList: Dec  */
#line 154 "parser.y"
              {EXP_ACTIONS1("DecList", yyval, (yyloc), yyvsp[0])}
#line 1654 "parser.tab.c"
    break;

  case 46: /* DecList: Dec COMMA DecList  */
#line 155 "parser.y"
                            {EXP_ACTIONS3("DecList", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1660 "parser.tab.c"
    break;

  case 47: /* Dec: VarDec  */
#line 157 "parser.y"
             {EXP_ACTIONS1("Dec", yyval, (yyloc), yyvsp[0])}
#line 1666 "parser.tab.c"
    break;

  case 48: /* Dec: VarDec ASSIGN Exp  */
#line 158 "parser.y"
                            {EXP_ACTIONS3("Dec", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1672 "parser.tab.c"
    break;

  case 49: /* Exp: Exp ASSIGN Exp  */
#line 161 "parser.y"
                     {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1678 "parser.tab.c"
    break;

  case 50: /* Exp: Exp AND Exp  */
#line 162 "parser.y"
                      {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1684 "parser.tab.c"
    break;

  case 51: /* Exp: Exp OR Exp  */
#line 163 "parser.y"
                     {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1690 "parser.tab.c"
    break;

  case 52: /* Exp: Exp REL Exp  */
#line 164 "parser.y"
                      {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1696 "parser.tab.c"
    break;

  case 53: /* Exp: Exp PLUS Exp  */
#line 165 "parser.y"
                       {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1702 "parser.tab.c"
    break;

  case 54: /* Exp: Exp MINUS Exp  */
#line 166 "parser.y"
                        {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1708 "parser.tab.c"
    break;

  case 55: /* Exp: Exp STAR Exp  */
#line 167 "parser.y"
                       {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1714 "parser.tab.c"
    break;

  case 56: /* Exp: Exp DIV Exp  */
#line 168 "parser.y"
                      {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1720 "parser.tab.c"
    break;

  case 57: /* Exp: LP Exp RP  */
#line 169 "parser.y"
                    {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1726 "parser.tab.c"
    break;

  case 58: /* Exp: MINUS Exp  */
#line 170 "parser.y"
                                 {EXP_ACTIONS2("Exp", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1732 "parser.tab.c"
    break;

  case 59: /* Exp: NOT Exp  */
#line 171 "parser.y"
                  {EXP_ACTIONS2("Exp", yyval, (yyloc), yyvsp[-1], yyvsp[0])}
#line 1738 "parser.tab.c"
    break;

  case 60: /* Exp: ID LP Args RP  */
#line 172 "parser.y"
                        {EXP_ACTIONS4("Exp", yyval, (yyloc), yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1744 "parser.tab.c"
    break;

  case 61: /* Exp: ID LP RP  */
#line 173 "parser.y"
                   {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1750 "parser.tab.c"
    break;

  case 62: /* Exp: Exp LB Exp RB  */
#line 174 "parser.y"
                        {EXP_ACTIONS4("Exp", yyval, (yyloc), yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1756 "parser.tab.c"
    break;

  case 63: /* Exp: Exp DOT ID  */
#line 175 "parser.y"
                     {EXP_ACTIONS3("Exp", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1762 "parser.tab.c"
    break;

  case 64: /* Exp: ID  */
#line 176 "parser.y"
             {EXP_ACTIONS1("Exp", yyval, (yyloc), yyvsp[0])}
#line 1768 "parser.tab.c"
    break;

  case 65: /* Exp: INT  */
#line 177 "parser.y"
              {EXP_ACTIONS1("Exp", yyval, (yyloc), yyvsp[0])}
#line 1774 "parser.tab.c"
    break;

  case 66: /* Exp: FLOAT  */
#line 178 "parser.y"
                {EXP_ACTIONS1("Exp", yyval, (yyloc), yyvsp[0])}
#line 1780 "parser.tab.c"
    break;

  case 67: /* Args: Exp COMMA Args  */
#line 180 "parser.y"
                      {EXP_ACTIONS3("Args", yyval, (yyloc), yyvsp[-2], yyvsp[-1], yyvsp[0])}
#line 1786 "parser.tab.c"
    break;

  case 68: /* Args: Exp  */
#line 181 "parser.y"
              {EXP_ACTIONS1("Args", yyval, (yyloc), yyvsp[0])}
#line 1792 "parser.tab.c"
    break;


#line 1796 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 184 "parser.y"

int yyerror(char* msg) {
    errstate=1;
    fprintf(stderr, "Error type B at Line %d:", yylloc.first_line);
    set_errstate();
    return 0;
}
