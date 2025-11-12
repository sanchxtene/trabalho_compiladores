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
#line 10 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;

#line 81 "parser.c"

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
  YYSYMBOL_TK_TIPO = 3,                    /* TK_TIPO  */
  YYSYMBOL_TK_VAR = 4,                     /* TK_VAR  */
  YYSYMBOL_TK_SENAO = 5,                   /* TK_SENAO  */
  YYSYMBOL_TK_DECIMAL = 6,                 /* TK_DECIMAL  */
  YYSYMBOL_TK_SE = 7,                      /* TK_SE  */
  YYSYMBOL_TK_INTEIRO = 8,                 /* TK_INTEIRO  */
  YYSYMBOL_TK_ATRIB = 9,                   /* TK_ATRIB  */
  YYSYMBOL_TK_RETORNA = 10,                /* TK_RETORNA  */
  YYSYMBOL_TK_SETA = 11,                   /* TK_SETA  */
  YYSYMBOL_TK_ENQUANTO = 12,               /* TK_ENQUANTO  */
  YYSYMBOL_TK_COM = 13,                    /* TK_COM  */
  YYSYMBOL_TK_OC_LE = 14,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 15,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 16,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 17,                  /* TK_OC_NE  */
  YYSYMBOL_TK_ID = 18,                     /* TK_ID  */
  YYSYMBOL_TK_LI_INTEIRO = 19,             /* TK_LI_INTEIRO  */
  YYSYMBOL_TK_LI_DECIMAL = 20,             /* TK_LI_DECIMAL  */
  YYSYMBOL_TK_ER = 21,                     /* TK_ER  */
  YYSYMBOL_22_ = 22,                       /* ';'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_24_ = 24,                       /* '['  */
  YYSYMBOL_25_ = 25,                       /* ']'  */
  YYSYMBOL_26_ = 26,                       /* '('  */
  YYSYMBOL_27_ = 27,                       /* ')'  */
  YYSYMBOL_28_ = 28,                       /* '|'  */
  YYSYMBOL_29_ = 29,                       /* '&'  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_37_ = 37,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_cria_escopo = 40,               /* cria_escopo  */
  YYSYMBOL_remove_escopo = 41,             /* remove_escopo  */
  YYSYMBOL_remove_escopo_funcao = 42,      /* remove_escopo_funcao  */
  YYSYMBOL_lista = 43,                     /* lista  */
  YYSYMBOL_elemento = 44,                  /* elemento  */
  YYSYMBOL_tipo = 45,                      /* tipo  */
  YYSYMBOL_literal = 46,                   /* literal  */
  YYSYMBOL_declaracao_variavel_top = 47,   /* declaracao_variavel_top  */
  YYSYMBOL_declaracao_funcao = 48,         /* declaracao_funcao  */
  YYSYMBOL_cabecalho = 49,                 /* cabecalho  */
  YYSYMBOL_lista_opcional_parametros = 50, /* lista_opcional_parametros  */
  YYSYMBOL_lista_parametros = 51,          /* lista_parametros  */
  YYSYMBOL_parametro = 52,                 /* parametro  */
  YYSYMBOL_corpo = 53,                     /* corpo  */
  YYSYMBOL_cs_bloco_de_comandos = 54,      /* cs_bloco_de_comandos  */
  YYSYMBOL_sequencia = 55,                 /* sequencia  */
  YYSYMBOL_comando_simples = 56,           /* comando_simples  */
  YYSYMBOL_cs_declaracao_variavel = 57,    /* cs_declaracao_variavel  */
  YYSYMBOL_cs_comando_atribuicao = 58,     /* cs_comando_atribuicao  */
  YYSYMBOL_cs_chamada_funcao = 59,         /* cs_chamada_funcao  */
  YYSYMBOL_argumentos = 60,                /* argumentos  */
  YYSYMBOL_lista_expressoes = 61,          /* lista_expressoes  */
  YYSYMBOL_cs_retorno = 62,                /* cs_retorno  */
  YYSYMBOL_cs_controle_fluxo = 63,         /* cs_controle_fluxo  */
  YYSYMBOL_condicional = 64,               /* condicional  */
  YYSYMBOL_senao_opcional = 65,            /* senao_opcional  */
  YYSYMBOL_repeticao = 66,                 /* repeticao  */
  YYSYMBOL_expressao = 67,                 /* expressao  */
  YYSYMBOL_expr_or = 68,                   /* expr_or  */
  YYSYMBOL_expr_and = 69,                  /* expr_and  */
  YYSYMBOL_expr_eq = 70,                   /* expr_eq  */
  YYSYMBOL_expr_rel = 71,                  /* expr_rel  */
  YYSYMBOL_expr_add = 72,                  /* expr_add  */
  YYSYMBOL_expr_mul = 73,                  /* expr_mul  */
  YYSYMBOL_expr_unary = 74,                /* expr_unary  */
  YYSYMBOL_expr_primary = 75               /* expr_primary  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    37,     2,     2,     2,    36,    29,     2,
      26,    27,    34,    32,    23,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
      30,     2,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,    25,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    64,    66,    67,    68,    76,    77,    89,
      90,    92,    93,    95,    96,    99,   109,   136,   153,   154,
     155,   157,   158,   160,   169,   172,   175,   176,   190,   191,
     192,   193,   194,   195,   201,   208,   229,   257,   348,   349,
     351,   352,   356,   376,   377,   380,   392,   393,   396,   406,
     409,   416,   419,   426,   430,   437,   444,   448,   455,   462,
     469,   476,   479,   486,   493,   496,   503,   510,   517,   520,
     521,   522,   523,   525,   536,   537,   538
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_TIPO", "TK_VAR",
  "TK_SENAO", "TK_DECIMAL", "TK_SE", "TK_INTEIRO", "TK_ATRIB",
  "TK_RETORNA", "TK_SETA", "TK_ENQUANTO", "TK_COM", "TK_OC_LE", "TK_OC_GE",
  "TK_OC_EQ", "TK_OC_NE", "TK_ID", "TK_LI_INTEIRO", "TK_LI_DECIMAL",
  "TK_ER", "';'", "','", "'['", "']'", "'('", "')'", "'|'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept", "programa",
  "cria_escopo", "remove_escopo", "remove_escopo_funcao", "lista",
  "elemento", "tipo", "literal", "declaracao_variavel_top",
  "declaracao_funcao", "cabecalho", "lista_opcional_parametros",
  "lista_parametros", "parametro", "corpo", "cs_bloco_de_comandos",
  "sequencia", "comando_simples", "cs_declaracao_variavel",
  "cs_comando_atribuicao", "cs_chamada_funcao", "argumentos",
  "lista_expressoes", "cs_retorno", "cs_controle_fluxo", "condicional",
  "senao_opcional", "repeticao", "expressao", "expr_or", "expr_and",
  "expr_eq", "expr_rel", "expr_add", "expr_mul", "expr_unary",
  "expr_primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-4)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,    12,    33,   -98,    -2,    24,     7,    -3,   -98,   -98,
      14,    32,    44,   -98,    33,     3,   -98,   -98,    44,   -98,
     -98,    -4,   -98,   -98,    35,    37,    -1,    50,     2,   -98,
      52,     3,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,    60,    70,    71,    58,   -98,    73,    -1,    57,   -98,
     -98,    -1,    -1,    -1,    -1,   -98,   -98,    75,    59,    56,
      40,     9,    36,    31,   -98,   -98,    -1,    -1,    -1,   -98,
     -98,    58,    44,   -98,    60,    44,    61,    62,   -98,   -98,
     -98,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,   -98,    64,   -98,    69,
     -98,   -98,    80,   -98,   -98,   -98,    56,    40,     9,     9,
      36,    36,    36,    36,    31,    31,   -98,   -98,   -98,   -98,
     -98,    -1,    51,    14,    14,   -98,   -98,   -98,   -98,    81,
     -98,   -98,   -98,    14,   -98,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,     7,     9,    10,
       0,     0,     0,     5,     0,    26,     6,    24,     0,    11,
      12,    20,     2,     8,     0,     0,     0,     0,     0,    31,
       0,    26,    28,    33,    30,    29,    32,    43,    44,    16,
      15,     0,     0,     0,    19,    21,     0,     0,    73,    14,
      13,     0,     0,     0,     0,    74,    76,     0,    49,    51,
      53,    56,    61,    64,    68,    72,     0,     0,    39,    25,
      27,    18,     0,    17,     0,     0,     0,     0,    69,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,    40,
      23,    22,    34,     4,    75,    42,    50,    52,    54,    55,
      59,    60,    57,    58,    62,    63,    65,    66,    67,     4,
      37,     0,     0,     0,     0,    41,    35,     5,     5,    46,
      48,     4,    45,     0,     5,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -97,   -80,   -98,    82,   -98,   -17,   -28,   -98,
     -98,   -98,   -98,    54,    23,   -98,   -10,    67,   -98,   -98,
     -98,    18,   -98,   -22,   -98,   -98,   -98,   -98,   -98,   -21,
     -98,    19,    17,   -12,   -27,   -16,   -50,   -98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    22,    39,     6,     7,    21,    55,     8,
       9,    10,    43,    44,    45,    16,    29,    30,    31,    32,
      33,    56,    97,    98,    35,    36,    37,   132,    38,    99,
      58,    59,    60,    61,    62,    63,    64,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    40,    78,    79,    80,    57,   123,    24,    -3,    41,
      25,    67,     3,    26,    42,    27,    11,    48,    49,    50,
      14,    28,   124,    86,    87,    51,    76,    15,    68,    13,
      77,    52,    53,    34,   133,    12,    54,     4,    15,    88,
      89,    18,   116,   117,   118,    95,    96,   129,   130,    34,
      19,     5,    20,    46,   135,   100,    84,    85,   102,   110,
     111,   112,   113,    47,   105,    92,    93,    94,    90,    91,
      49,    50,   108,   109,   114,   115,    66,    69,    42,    72,
      73,    74,    75,    68,    81,    83,   131,    82,   103,   104,
     119,   120,   121,   122,   126,    71,    23,   101,    70,   125,
     107,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,   134
};

static const yytype_int16 yycheck[] =
{
      10,    18,    52,    53,    54,    26,   103,     4,     0,    13,
       7,     9,     0,    10,    18,    12,    18,    18,    19,    20,
      23,    18,   119,    14,    15,    26,    47,    24,    26,    22,
      51,    32,    33,    15,   131,    11,    37,     4,    24,    30,
      31,     9,    92,    93,    94,    66,    67,   127,   128,    31,
       6,    18,     8,    18,   134,    72,    16,    17,    75,    86,
      87,    88,    89,    26,    81,    34,    35,    36,    32,    33,
      19,    20,    84,    85,    90,    91,    26,    25,    18,     9,
       9,    23,     9,    26,     9,    29,     5,    28,    27,    27,
      27,    27,    23,    13,   122,    41,    14,    74,    31,   121,
      83,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    40,     0,     4,    18,    43,    44,    47,    48,
      49,    18,    11,    22,    23,    24,    53,    54,     9,     6,
       8,    45,    41,    43,     4,     7,    10,    12,    18,    54,
      55,    56,    57,    58,    59,    62,    63,    64,    66,    42,
      45,    13,    18,    50,    51,    52,    18,    26,    18,    19,
      20,    26,    32,    33,    37,    46,    59,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    26,     9,    26,    25,
      55,    51,     9,     9,    23,     9,    67,    67,    74,    74,
      74,     9,    28,    29,    16,    17,    14,    15,    30,    31,
      32,    33,    34,    35,    36,    67,    67,    60,    61,    67,
      45,    52,    45,    27,    27,    45,    69,    70,    71,    71,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    27,
      27,    23,    13,    40,    40,    61,    46,    54,    54,    41,
      41,     5,    65,    40,    54,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    41,    42,    43,    43,    44,
      44,    45,    45,    46,    46,    47,    48,    49,    50,    50,
      50,    51,    51,    52,    53,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    59,    60,    60,
      61,    61,    62,    63,    63,    64,    65,    65,    66,    67,
      68,    68,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    71,    72,    72,    72,    73,    73,    73,    73,    74,
      74,    74,    74,    75,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     0,     0,     0,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     3,     5,     2,     1,
       0,     1,     3,     3,     1,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     4,     6,     3,     4,     1,     0,
       1,     3,     4,     1,     1,     8,     0,     4,     7,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     1,     1,     1,     3,     1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: cria_escopo lista ';' remove_escopo  */
#line 63 "parser.y"
                                              { arvore = (yyvsp[-2].no); }
#line 1505 "parser.c"
    break;

  case 3: /* programa: %empty  */
#line 64 "parser.y"
                 { arvore = NULL; }
#line 1511 "parser.c"
    break;

  case 4: /* cria_escopo: %empty  */
#line 66 "parser.y"
                    { push_scope(); }
#line 1517 "parser.c"
    break;

  case 5: /* remove_escopo: %empty  */
#line 67 "parser.y"
                      { pop_scope(); }
#line 1523 "parser.c"
    break;

  case 6: /* remove_escopo_funcao: %empty  */
#line 68 "parser.y"
                             { free(current_function_name);
				current_function_name = NULL; 
				print_scope_stack();
				pop_scope();
			     }
#line 1533 "parser.c"
    break;

  case 7: /* lista: elemento  */
#line 76 "parser.y"
                { (yyval.no) = (yyvsp[0].no); }
#line 1539 "parser.c"
    break;

  case 8: /* lista: elemento ',' lista  */
#line 77 "parser.y"
                          { if ((yyvsp[-2].no) == NULL) {
				(yyval.no) = (yyvsp[0].no);
			    } else {
				(yyval.no) = (yyvsp[-2].no);
				if ((yyvsp[0].no) != NULL) {
					asd_add_child((yyval.no), (yyvsp[0].no));
				}
			    }
			  }
#line 1553 "parser.c"
    break;

  case 9: /* elemento: declaracao_variavel_top  */
#line 89 "parser.y"
                                  { (yyval.no) = (yyvsp[0].no); }
#line 1559 "parser.c"
    break;

  case 10: /* elemento: declaracao_funcao  */
#line 90 "parser.y"
                            { (yyval.no) = (yyvsp[0].no); }
#line 1565 "parser.c"
    break;

  case 11: /* tipo: TK_DECIMAL  */
#line 92 "parser.y"
                 { (yyval.no) = asd_new("tipo", TYPE_DECIMAL); }
#line 1571 "parser.c"
    break;

  case 12: /* tipo: TK_INTEIRO  */
#line 93 "parser.y"
                 { (yyval.no) = asd_new("tipo", TYPE_INTEIRO); }
#line 1577 "parser.c"
    break;

  case 13: /* literal: TK_LI_DECIMAL  */
#line 95 "parser.y"
                       { (yyval.no) = asd_new((yyvsp[0].valor_lexico)->valor, TYPE_DECIMAL); free((yyvsp[0].valor_lexico)->valor); free((yyvsp[0].valor_lexico));}
#line 1583 "parser.c"
    break;

  case 14: /* literal: TK_LI_INTEIRO  */
#line 96 "parser.y"
                       { (yyval.no) = asd_new((yyvsp[0].valor_lexico)->valor, TYPE_INTEIRO); free((yyvsp[0].valor_lexico)->valor); free((yyvsp[0].valor_lexico));}
#line 1589 "parser.c"
    break;

  case 15: /* declaracao_variavel_top: TK_VAR TK_ID TK_ATRIB tipo  */
#line 100 "parser.y"
                        { (yyval.no) = NULL;
			       insert_symbol((yyvsp[-2].valor_lexico)->valor, NATURE_ID, (yyvsp[0].no)->type, NULL);
			       free((yyvsp[-2].valor_lexico)->valor);
			       free((yyvsp[-2].valor_lexico));
			       asd_free((yyvsp[0].no));
			}
#line 1600 "parser.c"
    break;

  case 16: /* declaracao_funcao: cabecalho corpo remove_escopo_funcao  */
#line 110 "parser.y"
                  { (yyval.no) = (yyvsp[-2].no);
			 if((yyvsp[-1].no) != NULL) {
				asd_add_child((yyval.no), (yyvsp[-1].no));
			 }

			// Printa os parametros declarados no escopo da funcao
			Symbol *sym = lookup_symbol((yyvsp[-2].no)->label);
			Argument *arg = sym->args;
			if (arg == NULL) {
				fprintf(stderr, "Função '%s' declarada sem parâmetros", (yyvsp[-2].no)->label);
			} else {
				fprintf(stderr, "Função '%s' declarada com os parâmetros: ", (yyvsp[-2].no)->label);
				while (arg != NULL) {
					fprintf(stderr, "%s (%d), ", arg->name, arg->type);  // debug
					arg = arg->next;
				}
			}

			fprintf(stderr, "\n");
		  }
#line 1625 "parser.c"
    break;

  case 17: /* cabecalho: TK_ID TK_SETA tipo lista_opcional_parametros TK_ATRIB  */
#line 137 "parser.y"
          { (yyval.no) = asd_new((yyvsp[-4].valor_lexico)->valor, (yyvsp[-2].no)->type);
		 insert_symbol((yyvsp[-4].valor_lexico)->valor, NATURE_FUNCAO, (yyvsp[-2].no)->type, (yyvsp[-1].argument));
		 current_function_name = strdup((yyvsp[-4].valor_lexico)->valor);
		 push_scope();
		
		 // Adiciona a lista de parametros ao escopo interno da funcao	 
		 Argument *arg = (yyvsp[-1].argument);
		 while (arg) {
			insert_symbol(arg->name, NATURE_ID, arg->type, NULL);
			arg = arg->next;
		 }
		 free((yyvsp[-4].valor_lexico)->valor);
		 free((yyvsp[-4].valor_lexico));
		 asd_free((yyvsp[-2].no));
	  }
#line 1645 "parser.c"
    break;

  case 18: /* lista_opcional_parametros: TK_COM lista_parametros  */
#line 153 "parser.y"
                                                   { (yyval.argument) = (yyvsp[0].argument); }
#line 1651 "parser.c"
    break;

  case 19: /* lista_opcional_parametros: lista_parametros  */
#line 154 "parser.y"
                                            { (yyval.argument) = (yyvsp[0].argument); }
#line 1657 "parser.c"
    break;

  case 20: /* lista_opcional_parametros: %empty  */
#line 155 "parser.y"
                                  { (yyval.argument) = NULL; }
#line 1663 "parser.c"
    break;

  case 21: /* lista_parametros: parametro  */
#line 157 "parser.y"
                             { (yyval.argument) = (yyvsp[0].argument); }
#line 1669 "parser.c"
    break;

  case 22: /* lista_parametros: lista_parametros ',' parametro  */
#line 158 "parser.y"
                                                 { (yyval.argument) = append_argument((yyvsp[-2].argument), (yyvsp[0].argument)); }
#line 1675 "parser.c"
    break;

  case 23: /* parametro: TK_ID TK_ATRIB tipo  */
#line 160 "parser.y"
                               { (yyval.argument) = create_argument((yyvsp[-2].valor_lexico)->valor, (yyvsp[0].no)->type);
				 free((yyvsp[-2].valor_lexico)->valor);
				 free((yyvsp[-2].valor_lexico));
				 asd_free((yyvsp[0].no));
			       }
#line 1685 "parser.c"
    break;

  case 24: /* corpo: cs_bloco_de_comandos  */
#line 169 "parser.y"
                            { (yyval.no) = (yyvsp[0].no); }
#line 1691 "parser.c"
    break;

  case 25: /* cs_bloco_de_comandos: '[' sequencia ']'  */
#line 172 "parser.y"
                                        { (yyval.no) = (yyvsp[-1].no); }
#line 1697 "parser.c"
    break;

  case 26: /* sequencia: %empty  */
#line 175 "parser.y"
                  { (yyval.no) = NULL; }
#line 1703 "parser.c"
    break;

  case 27: /* sequencia: comando_simples sequencia  */
#line 177 "parser.y"
                { if ((yyvsp[0].no) == NULL){
			(yyval.no) = (yyvsp[-1].no);
		  } else {
			if ((yyvsp[-1].no) == NULL) {
				(yyval.no) = (yyvsp[0].no);
			} else {
				asd_add_child((yyvsp[-1].no), (yyvsp[0].no));
				(yyval.no) = (yyvsp[-1].no);
			}
		  }
		}
#line 1719 "parser.c"
    break;

  case 28: /* comando_simples: cs_declaracao_variavel  */
#line 190 "parser.y"
                                         { (yyval.no) = (yyvsp[0].no); }
#line 1725 "parser.c"
    break;

  case 29: /* comando_simples: cs_retorno  */
#line 191 "parser.y"
                             { (yyval.no) = (yyvsp[0].no); }
#line 1731 "parser.c"
    break;

  case 30: /* comando_simples: cs_chamada_funcao  */
#line 192 "parser.y"
                                    { (yyval.no) = (yyvsp[0].no); }
#line 1737 "parser.c"
    break;

  case 31: /* comando_simples: cs_bloco_de_comandos  */
#line 193 "parser.y"
                                       { (yyval.no) = (yyvsp[0].no); }
#line 1743 "parser.c"
    break;

  case 32: /* comando_simples: cs_controle_fluxo  */
#line 194 "parser.y"
                                    { (yyval.no) = (yyvsp[0].no); }
#line 1749 "parser.c"
    break;

  case 33: /* comando_simples: cs_comando_atribuicao  */
#line 195 "parser.y"
                                        { (yyval.no) = (yyvsp[0].no); }
#line 1755 "parser.c"
    break;

  case 34: /* cs_declaracao_variavel: TK_VAR TK_ID TK_ATRIB tipo  */
#line 202 "parser.y"
                         { (yyval.no) = NULL;
				insert_symbol((yyvsp[-2].valor_lexico)->valor, NATURE_ID, (yyvsp[0].no)->type, NULL);
				free((yyvsp[-2].valor_lexico)->valor);
				free((yyvsp[-2].valor_lexico));
				asd_free((yyvsp[0].no)); 
			 }
#line 1766 "parser.c"
    break;

  case 35: /* cs_declaracao_variavel: TK_VAR TK_ID TK_ATRIB tipo TK_COM literal  */
#line 209 "parser.y"
                        { (yyval.no) = asd_new("com", (yyvsp[-2].no)->type);
			       insert_symbol((yyvsp[-4].valor_lexico)->valor, NATURE_ID, (yyvsp[-2].no)->type, NULL);
			        if ((yyvsp[-2].no)->type == TYPE_INTEIRO && (yyvsp[0].no)->type == TYPE_DECIMAL){
					fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'inteiro' e recebeu um literal do tipo 'decimal' (linha %d)\n", (yyvsp[-4].valor_lexico)->valor, (yyvsp[-4].valor_lexico)->linha);
					exit(ERR_WRONG_TYPE);	
				}
				if ((yyvsp[-2].no)->type == TYPE_DECIMAL && (yyvsp[0].no)->type == TYPE_INTEIRO){
					fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'decimal' e recebeu um literal do tipo 'inteiro' (linha %d)\n", (yyvsp[-4].valor_lexico)->valor, (yyvsp[-4].valor_lexico)->linha);
					exit(ERR_WRONG_TYPE);	
				}
			       asd_tree_t *id_node = asd_new((yyvsp[-4].valor_lexico)->valor, (yyvsp[-2].no)->type);
			       asd_add_child((yyval.no), id_node); 
			       asd_add_child((yyval.no), (yyvsp[0].no));
			       free((yyvsp[-4].valor_lexico)->valor);
			       free((yyvsp[-4].valor_lexico));
			       asd_free((yyvsp[-2].no)); 
			}
#line 1788 "parser.c"
    break;

  case 36: /* cs_comando_atribuicao: TK_ID TK_ATRIB expressao  */
#line 230 "parser.y"
                        {Symbol *sym = lookup_symbol((yyvsp[-2].valor_lexico)->valor);
			 if (!sym) {
				fprintf(stderr, "Erro: variável '%s' não declarada (linha %d)\n", (yyvsp[-2].valor_lexico)->valor, (yyvsp[-2].valor_lexico)->linha);
				exit(ERR_UNDECLARED);
			 }
			 if (sym->nature != NATURE_ID) {
				fprintf(stderr, "Erro: o id '%s' já foi declarado como funcao (linha %d)\n", (yyvsp[-2].valor_lexico)->valor, (yyvsp[-2].valor_lexico)->linha);
				exit(ERR_FUNCTION);	
			 }
			 if (sym->type == TYPE_INTEIRO && (yyvsp[0].no)->type == TYPE_DECIMAL){
				fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'inteiro' e recebeu uma expressao do tipo 'decimal' (linha %d)\n", (yyvsp[-2].valor_lexico)->valor, (yyvsp[-2].valor_lexico)->linha);
				exit(ERR_WRONG_TYPE);	
			 }
			 if (sym->type == TYPE_DECIMAL && (yyvsp[0].no)->type == TYPE_INTEIRO){
				fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'decimal' e recebeu uma expressao do tipo 'inteiro' (linha %d)\n", (yyvsp[-2].valor_lexico)->valor, (yyvsp[-2].valor_lexico)->linha);
				exit(ERR_WRONG_TYPE);	
			 }     
			 (yyval.no) = asd_new(":=", sym->type);
			      asd_tree_t *id_node = asd_new((yyvsp[-2].valor_lexico)->valor, sym->type);
			      free((yyvsp[-2].valor_lexico)->valor);
			      free((yyvsp[-2].valor_lexico));
			      asd_add_child((yyval.no), id_node);
			      asd_add_child((yyval.no), (yyvsp[0].no));
			 }
#line 1817 "parser.c"
    break;

  case 37: /* cs_chamada_funcao: TK_ID '(' argumentos ')'  */
#line 258 "parser.y"
                        { Symbol *sym = lookup_symbol((yyvsp[-3].valor_lexico)->valor);
			  if (!sym) {
				fprintf(stderr, "Erro: função '%s' não declarada (linha %d)\n", (yyvsp[-3].valor_lexico)->valor, (yyvsp[-3].valor_lexico)->linha);
				exit(ERR_UNDECLARED);
			  }
			  if (sym->nature != NATURE_FUNCAO) {
				fprintf(stderr, "Erro: o id '%s' foi declarado como variavel (linha %d)\n", (yyvsp[-3].valor_lexico)->valor, (yyvsp[-3].valor_lexico)->linha);
				exit(ERR_VARIABLE);	
			  }

			  // Verifica o numero de argumentos
			  Argument *param = sym->args;
			  size_t param_count = 0;
			  if (param == NULL) {
				fprintf(stderr, "Função '%s' declarada sem parâmetros\n", (yyvsp[-3].valor_lexico)->valor);
			  } else {
				fprintf(stderr, "Função '%s' declarada com parâmetros:\n", (yyvsp[-3].valor_lexico)->valor);
				while (param) {
					fprintf(stderr, "  %s (tipo %s)\n", param->name, type_to_string(param->type));
					param_count++;
					param = param->next;
				}
			  }
			  
			  // Conta argumentos passados
			  size_t arg_count = 0;
			  asd_tree_t *args = (yyvsp[-1].no);
			  
			  while (args != NULL) {
				arg_count++;

				fprintf(stderr, "   Argumento %zu: tipo %s\n", arg_count, type_to_string(args->type));

				// segue apenas se o filho realmente existe
				if (args->number_of_children > 0 && args->children != NULL && args->children[0] != NULL) {
					args = args->children[0];
				} else {
					args = NULL;
				}
			  }
			  
			  fprintf(stderr, "Numero de argumentos passados para a funcao '%s': %zu\n", (yyvsp[-3].valor_lexico)->valor, arg_count);

			  // Verifica se o num de args esta certo
			  if (arg_count < param_count) {
				fprintf(stderr, "Erro: número insuficiente de argumentos na chamada da função '%s' (linha %d)\n", (yyvsp[-3].valor_lexico)->valor, (yyvsp[-3].valor_lexico)->linha);
				exit(ERR_MISSING_ARGS);
			  }
			  if (arg_count > param_count) {
				fprintf(stderr, "Erro: número excessivo de argumentos na chamada da função '%s' (linha %d)\n", (yyvsp[-3].valor_lexico)->valor, (yyvsp[-3].valor_lexico)->linha);
				exit(ERR_EXCESS_ARGS);
			  }

			  // verifica os tipos dos argumentos
			  args = (yyvsp[-1].no);
			  param = sym->args;
			  while (args != NULL && param != NULL) {
				asd_tree_t *expr = (args->children ? args->children[0] : args);
		                if (!expr) break;

		                if (expr->type != param->type) {
					fprintf(stderr, "Erro: tipo incompatível no argumento '%s' da função '%s' (linha %d)\n"
						"Esperado: %s, recebido: %s\n",
						param->name, sym->name, (yyvsp[-3].valor_lexico)->linha,
						type_to_string(param->type),
						type_to_string(expr->type));
					exit(ERR_WRONG_TYPE_ARGS);
		                }

				// Avanca para o prox argumento
				if (args->children != NULL) {
					args = args->children[0]; 
				} else {
					args = NULL; 
				}
				param = param->next; // Avanca para o proóximo parametro
			  }

			  size_t len = strlen("call ") + strlen((yyvsp[-3].valor_lexico)->valor) + 1;
			  char *nome = malloc(len);
			  sprintf(nome, "call %s", (yyvsp[-3].valor_lexico)->valor);
			  (yyval.no) = asd_new(nome, sym->type);
			       if ((yyvsp[-1].no) != NULL) {
					asd_add_child((yyval.no), (yyvsp[-1].no));
			       }
			       free((yyvsp[-3].valor_lexico)->valor);
			       free((yyvsp[-3].valor_lexico));
			       free(nome); }
#line 1910 "parser.c"
    break;

  case 38: /* argumentos: lista_expressoes  */
#line 348 "parser.y"
                              { (yyval.no) = (yyvsp[0].no); }
#line 1916 "parser.c"
    break;

  case 39: /* argumentos: %empty  */
#line 349 "parser.y"
                              { (yyval.no) = NULL; }
#line 1922 "parser.c"
    break;

  case 40: /* lista_expressoes: expressao  */
#line 351 "parser.y"
                            { (yyval.no) = (yyvsp[0].no); }
#line 1928 "parser.c"
    break;

  case 41: /* lista_expressoes: expressao ',' lista_expressoes  */
#line 352 "parser.y"
                                                 { (yyval.no) = (yyvsp[-2].no); 
						   asd_add_child((yyvsp[-2].no), (yyvsp[0].no)); }
#line 1935 "parser.c"
    break;

  case 42: /* cs_retorno: TK_RETORNA expressao TK_ATRIB tipo  */
#line 357 "parser.y"
                { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type){
			fprintf(stderr, "Erro: na função '%s' o tipo da expressao de retorno e o tipo do retorno são diferentes\n", current_function_name);
			exit(ERR_WRONG_TYPE);
		  }

		  Symbol *func_sym = lookup_symbol(current_function_name);
		  if (func_sym->type != (yyvsp[-2].no)->type) {
			fprintf(stderr, "Erro: tipo de retorno incorreto na função '%s' (esperado: %s, encontrado: %s)\n",
				current_function_name,
				type_to_string(func_sym->type),
				type_to_string((yyvsp[-2].no)->type));
				exit(ERR_WRONG_TYPE);
		  }  
		  (yyval.no) = asd_new("retorna", (yyvsp[0].no)->type);
			asd_add_child((yyval.no), (yyvsp[-2].no));
			asd_free((yyvsp[0].no));
		}
#line 1957 "parser.c"
    break;

  case 43: /* cs_controle_fluxo: condicional  */
#line 376 "parser.y"
                               { (yyval.no) = (yyvsp[0].no); }
#line 1963 "parser.c"
    break;

  case 44: /* cs_controle_fluxo: repeticao  */
#line 377 "parser.y"
                             { (yyval.no) = (yyvsp[0].no); }
#line 1969 "parser.c"
    break;

  case 45: /* condicional: TK_SE '(' expressao ')' cria_escopo cs_bloco_de_comandos remove_escopo senao_opcional  */
#line 381 "parser.y"
                { (yyval.no) = asd_new("se", (yyvsp[-5].no)->type);
			asd_add_child((yyval.no), (yyvsp[-5].no));
			if ((yyvsp[-2].no) != NULL) {
				asd_add_child((yyval.no), (yyvsp[-2].no));
			}
			if ((yyvsp[0].no) != NULL) {
				asd_add_child((yyval.no), (yyvsp[0].no));
			} 
		}
#line 1983 "parser.c"
    break;

  case 46: /* senao_opcional: %empty  */
#line 392 "parser.y"
                       { (yyval.no) = NULL; }
#line 1989 "parser.c"
    break;

  case 47: /* senao_opcional: TK_SENAO cria_escopo cs_bloco_de_comandos remove_escopo  */
#line 393 "parser.y"
                                                                        { (yyval.no) = (yyvsp[-1].no); }
#line 1995 "parser.c"
    break;

  case 48: /* repeticao: TK_ENQUANTO '(' expressao ')' cria_escopo cs_bloco_de_comandos remove_escopo  */
#line 397 "parser.y"
                { (yyval.no) = asd_new("enquanto", (yyvsp[-4].no)->type);
			asd_add_child((yyval.no), (yyvsp[-4].no));
			if ((yyvsp[-1].no) != NULL) {
				asd_add_child((yyval.no), (yyvsp[-1].no));
			}
		}
#line 2006 "parser.c"
    break;

  case 49: /* expressao: expr_or  */
#line 406 "parser.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 2012 "parser.c"
    break;

  case 50: /* expr_or: expr_or '|' expr_and  */
#line 409 "parser.y"
                       { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '|'\n");
				exit(ERR_WRONG_TYPE);
			 }
			 (yyval.no) = asd_new("|", TYPE_INTEIRO);
				asd_add_child((yyval.no), (yyvsp[-2].no));
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2024 "parser.c"
    break;

  case 51: /* expr_or: expr_and  */
#line 416 "parser.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 2030 "parser.c"
    break;

  case 52: /* expr_and: expr_and '&' expr_eq  */
#line 419 "parser.y"
                       { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '&'\n");
				exit(ERR_WRONG_TYPE);
			 }
			 (yyval.no) = asd_new("&", TYPE_INTEIRO);
				asd_add_child((yyval.no), (yyvsp[-2].no));
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2042 "parser.c"
    break;

  case 53: /* expr_and: expr_eq  */
#line 426 "parser.y"
          { (yyval.no) = (yyvsp[0].no); }
#line 2048 "parser.c"
    break;

  case 54: /* expr_eq: expr_eq TK_OC_EQ expr_rel  */
#line 430 "parser.y"
                            { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '=='\n");
					exit(ERR_WRONG_TYPE);
				}
				(yyval.no) = asd_new("==", TYPE_INTEIRO);
					asd_add_child((yyval.no), (yyvsp[-2].no));
					asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2060 "parser.c"
    break;

  case 55: /* expr_eq: expr_eq TK_OC_NE expr_rel  */
#line 437 "parser.y"
                            { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '!='\n");
					exit(ERR_WRONG_TYPE);
				}
				(yyval.no) = asd_new("!=", TYPE_INTEIRO);
					asd_add_child((yyval.no), (yyvsp[-2].no));
					asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2072 "parser.c"
    break;

  case 56: /* expr_eq: expr_rel  */
#line 444 "parser.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 2078 "parser.c"
    break;

  case 57: /* expr_rel: expr_rel '<' expr_add  */
#line 448 "parser.y"
                        { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '>'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  (yyval.no) = asd_new("<", TYPE_INTEIRO);
				asd_add_child((yyval.no), (yyvsp[-2].no));
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2090 "parser.c"
    break;

  case 58: /* expr_rel: expr_rel '>' expr_add  */
#line 455 "parser.y"
                        { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '>'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  (yyval.no) = asd_new(">", TYPE_INTEIRO);
				asd_add_child((yyval.no), (yyvsp[-2].no));
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2102 "parser.c"
    break;

  case 59: /* expr_rel: expr_rel TK_OC_LE expr_add  */
#line 462 "parser.y"
                             { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '<='\n");
					exit(ERR_WRONG_TYPE);
				}
				(yyval.no) = asd_new("<=", TYPE_INTEIRO);
					asd_add_child((yyval.no), (yyvsp[-2].no));
					asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2114 "parser.c"
    break;

  case 60: /* expr_rel: expr_rel TK_OC_GE expr_add  */
#line 469 "parser.y"
                             { if ((yyvsp[-2].no)->type !=  (yyvsp[0].no)->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '>='\n");
					exit(ERR_WRONG_TYPE);
				}
				(yyval.no) = asd_new(">=", TYPE_INTEIRO);
					asd_add_child((yyval.no), (yyvsp[-2].no));
					asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2126 "parser.c"
    break;

  case 61: /* expr_rel: expr_add  */
#line 476 "parser.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 2132 "parser.c"
    break;

  case 62: /* expr_add: expr_add '+' expr_mul  */
#line 479 "parser.y"
                        { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '+'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  (yyval.no) = asd_new("+", (yyvsp[-2].no)->type);
				  asd_add_child((yyval.no), (yyvsp[-2].no));
				  asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2144 "parser.c"
    break;

  case 63: /* expr_add: expr_add '-' expr_mul  */
#line 486 "parser.y"
                        { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '-'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  (yyval.no) = asd_new("-", (yyvsp[-2].no)->type);
				asd_add_child((yyval.no), (yyvsp[-2].no));
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2156 "parser.c"
    break;

  case 64: /* expr_add: expr_mul  */
#line 493 "parser.y"
           { (yyval.no) = (yyvsp[0].no); }
#line 2162 "parser.c"
    break;

  case 65: /* expr_mul: expr_mul '*' expr_unary  */
#line 496 "parser.y"
                          { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '*'\n");
				exit(ERR_WRONG_TYPE);
			    }
			    (yyval.no) = asd_new("*", (yyvsp[-2].no)->type);
				asd_add_child((yyval.no), (yyvsp[-2].no)); 
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2174 "parser.c"
    break;

  case 66: /* expr_mul: expr_mul '/' expr_unary  */
#line 503 "parser.y"
                          { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '/'\n");
				exit(ERR_WRONG_TYPE);
			    }
			    (yyval.no) = asd_new("/", (yyvsp[-2].no)->type);
				asd_add_child((yyval.no), (yyvsp[-2].no)); 
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2186 "parser.c"
    break;

  case 67: /* expr_mul: expr_mul '%' expr_unary  */
#line 510 "parser.y"
                          { if ((yyvsp[-2].no)->type != (yyvsp[0].no)->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '%%'\n");
				exit(ERR_WRONG_TYPE);
			    }
			    (yyval.no) = asd_new("%", (yyvsp[-2].no)->type);
				asd_add_child((yyval.no), (yyvsp[-2].no));
				asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2198 "parser.c"
    break;

  case 68: /* expr_mul: expr_unary  */
#line 517 "parser.y"
             { (yyval.no) = (yyvsp[0].no); }
#line 2204 "parser.c"
    break;

  case 69: /* expr_unary: '+' expr_unary  */
#line 520 "parser.y"
                 { (yyval.no) = asd_new("+", (yyvsp[0].no)->type); asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2210 "parser.c"
    break;

  case 70: /* expr_unary: '-' expr_unary  */
#line 521 "parser.y"
                 { (yyval.no) = asd_new("-", (yyvsp[0].no)->type); asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2216 "parser.c"
    break;

  case 71: /* expr_unary: '!' expr_unary  */
#line 522 "parser.y"
                 { (yyval.no) = asd_new("!", (yyvsp[0].no)->type); asd_add_child((yyval.no), (yyvsp[0].no)); }
#line 2222 "parser.c"
    break;

  case 72: /* expr_unary: expr_primary  */
#line 523 "parser.y"
               { (yyval.no) = (yyvsp[0].no); }
#line 2228 "parser.c"
    break;

  case 73: /* expr_primary: TK_ID  */
#line 525 "parser.y"
                    {   Symbol *sym = lookup_symbol((yyvsp[0].valor_lexico)->valor);
			if (!sym) {
				fprintf(stderr, "Erro: variável '%s' não declarada (linha %d)\n", (yyvsp[0].valor_lexico)->valor, (yyvsp[0].valor_lexico)->linha);
				exit(ERR_UNDECLARED);
			}
			if (sym->nature != NATURE_ID) {
				fprintf(stderr, "Erro: o id '%s' foi declarado como funcao (linha %d)\n", (yyvsp[0].valor_lexico)->valor, (yyvsp[0].valor_lexico)->linha);
				exit(ERR_FUNCTION);	
			}
			(yyval.no) = asd_new((yyvsp[0].valor_lexico)->valor, sym->type);
				free((yyvsp[0].valor_lexico)->valor); free((yyvsp[0].valor_lexico)); }
#line 2244 "parser.c"
    break;

  case 74: /* expr_primary: literal  */
#line 536 "parser.y"
                      { (yyval.no) = (yyvsp[0].no); }
#line 2250 "parser.c"
    break;

  case 75: /* expr_primary: '(' expressao ')'  */
#line 537 "parser.y"
                                { (yyval.no) = (yyvsp[-1].no); }
#line 2256 "parser.c"
    break;

  case 76: /* expr_primary: cs_chamada_funcao  */
#line 538 "parser.y"
                                { (yyval.no) = (yyvsp[0].no); }
#line 2262 "parser.c"
    break;


#line 2266 "parser.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 541 "parser.y"


void yyerror (char const *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}

