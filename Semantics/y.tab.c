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
#line 7 "cminus.y"

#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *

static char * savedName; /* for use in assignments */
static int savedType;
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int savedNum;
static int savedOp;
static int yylex(void); // added 11/2/11 to ensure no conflict with lex
static int yyerror(char* s);


#line 92 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    WHILE = 259,                   /* WHILE  */
    RETURN = 260,                  /* RETURN  */
    INT = 261,                     /* INT  */
    VOID = 262,                    /* VOID  */
    INTARRAY = 263,                /* INTARRAY  */
    VOIDARRAY = 264,               /* VOIDARRAY  */
    NUM = 265,                     /* NUM  */
    ID = 266,                      /* ID  */
    ENDFILE = 267,                 /* ENDFILE  */
    ERROR = 268,                   /* ERROR  */
    EQ = 269,                      /* EQ  */
    NE = 270,                      /* NE  */
    LT = 271,                      /* LT  */
    LE = 272,                      /* LE  */
    GT = 273,                      /* GT  */
    GE = 274,                      /* GE  */
    LPAREN = 275,                  /* LPAREN  */
    RPAREN = 276,                  /* RPAREN  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    LCURLY = 279,                  /* LCURLY  */
    RCURLY = 280,                  /* RCURLY  */
    SEMI = 281,                    /* SEMI  */
    COMMA = 282,                   /* COMMA  */
    IFONLY = 283,                  /* IFONLY  */
    PARAMONLY = 284,               /* PARAMONLY  */
    ELSE = 285,                    /* ELSE  */
    PLUS = 286,                    /* PLUS  */
    MINUS = 287,                   /* MINUS  */
    TIMES = 288,                   /* TIMES  */
    OVER = 289,                    /* OVER  */
    ASSIGN = 290                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define WHILE 259
#define RETURN 260
#define INT 261
#define VOID 262
#define INTARRAY 263
#define VOIDARRAY 264
#define NUM 265
#define ID 266
#define ENDFILE 267
#define ERROR 268
#define EQ 269
#define NE 270
#define LT 271
#define LE 272
#define GT 273
#define GE 274
#define LPAREN 275
#define RPAREN 276
#define LBRACE 277
#define RBRACE 278
#define LCURLY 279
#define RCURLY 280
#define SEMI 281
#define COMMA 282
#define IFONLY 283
#define PARAMONLY 284
#define ELSE 285
#define PLUS 286
#define MINUS 287
#define TIMES 288
#define OVER 289
#define ASSIGN 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_WHILE = 4,                      /* WHILE  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_INTARRAY = 8,                   /* INTARRAY  */
  YYSYMBOL_VOIDARRAY = 9,                  /* VOIDARRAY  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_ENDFILE = 12,                   /* ENDFILE  */
  YYSYMBOL_ERROR = 13,                     /* ERROR  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_LPAREN = 20,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 21,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_LCURLY = 24,                    /* LCURLY  */
  YYSYMBOL_RCURLY = 25,                    /* RCURLY  */
  YYSYMBOL_SEMI = 26,                      /* SEMI  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_IFONLY = 28,                    /* IFONLY  */
  YYSYMBOL_PARAMONLY = 29,                 /* PARAMONLY  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MINUS = 32,                     /* MINUS  */
  YYSYMBOL_TIMES = 33,                     /* TIMES  */
  YYSYMBOL_OVER = 34,                      /* OVER  */
  YYSYMBOL_ASSIGN = 35,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_declaration_list = 38,          /* declaration_list  */
  YYSYMBOL_declaration = 39,               /* declaration  */
  YYSYMBOL_id = 40,                        /* id  */
  YYSYMBOL_num = 41,                       /* num  */
  YYSYMBOL_var_declaration = 42,           /* var_declaration  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_type_specifier = 44,            /* type_specifier  */
  YYSYMBOL_func_declaration = 45,          /* func_declaration  */
  YYSYMBOL_46_2 = 46,                      /* @2  */
  YYSYMBOL_params = 47,                    /* params  */
  YYSYMBOL_param_list = 48,                /* param_list  */
  YYSYMBOL_param = 49,                     /* param  */
  YYSYMBOL_compound_stmt = 50,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 51,        /* local_declarations  */
  YYSYMBOL_statement_list = 52,            /* statement_list  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_expression_stmt = 54,           /* expression_stmt  */
  YYSYMBOL_return_stmt = 55,               /* return_stmt  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_var = 57,                       /* var  */
  YYSYMBOL_58_3 = 58,                      /* @3  */
  YYSYMBOL_simple_expression = 59,         /* simple_expression  */
  YYSYMBOL_relop = 60,                     /* relop  */
  YYSYMBOL_additive_expression = 61,       /* additive_expression  */
  YYSYMBOL_62_4 = 62,                      /* @4  */
  YYSYMBOL_addop = 63,                     /* addop  */
  YYSYMBOL_term = 64,                      /* term  */
  YYSYMBOL_65_5 = 65,                      /* @5  */
  YYSYMBOL_mulop = 66,                     /* mulop  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_call = 68,                      /* call  */
  YYSYMBOL_69_6 = 69,                      /* @6  */
  YYSYMBOL_args = 70,                      /* args  */
  YYSYMBOL_arg_list = 71,                  /* arg_list  */
  YYSYMBOL_selection_stmt = 72,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 73             /* iteration_stmt  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   98

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    56,    66,    69,    70,    72,    77,    85,
      93,    92,   110,   111,   113,   113,   127,   128,   132,   142,
     144,   150,   160,   167,   177,   180,   190,   193,   194,   195,
     196,   197,   199,   200,   202,   206,   213,   220,   222,   223,
     223,   233,   240,   242,   243,   244,   245,   246,   247,   249,
     249,   258,   260,   261,   263,   263,   273,   276,   277,   279,
     280,   281,   282,   289,   289,   297,   298,   300,   310,   313,
     318,   325
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "WHILE",
  "RETURN", "INT", "VOID", "INTARRAY", "VOIDARRAY", "NUM", "ID", "ENDFILE",
  "ERROR", "EQ", "NE", "LT", "LE", "GT", "GE", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LCURLY", "RCURLY", "SEMI", "COMMA", "IFONLY",
  "PARAMONLY", "ELSE", "PLUS", "MINUS", "TIMES", "OVER", "ASSIGN",
  "$accept", "program", "declaration_list", "declaration", "id", "num",
  "var_declaration", "$@1", "type_specifier", "func_declaration", "@2",
  "params", "param_list", "param", "compound_stmt", "local_declarations",
  "statement_list", "statement", "expression_stmt", "return_stmt",
  "expression", "var", "@3", "simple_expression", "relop",
  "additive_expression", "@4", "addop", "term", "@5", "mulop", "factor",
  "call", "@6", "args", "arg_list", "selection_stmt", "iteration_stmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -85,   -85,    13,    -2,   -85,   -85,    15,   -85,   -85,
     -85,   -85,   -14,   -85,    25,    29,    53,    45,   -85,    46,
      34,    15,    49,    26,   -85,    47,    50,    52,    -2,   -85,
      48,   -85,   -85,   -85,   -85,    -2,   -85,    15,     4,    51,
      58,    59,    11,    28,   -85,   -85,    22,   -85,   -85,   -85,
     -85,   -85,    54,    55,   -85,    43,    32,   -85,   -85,   -85,
     -85,    28,    28,   -85,    56,    60,   -85,    63,   -85,    28,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,    28,   -85,
     -85,   -85,   -85,    64,    65,   -85,   -85,    28,    28,   -85,
     -85,    36,    28,    28,    30,    30,    61,   -85,    66,    62,
      32,   -85,    67,   -85,   -85,   -85,    28,    30,   -85,   -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    13,     0,     2,     4,     5,     0,     6,     1,
       3,     7,    10,     9,     0,     0,     0,     0,     8,     0,
      13,     0,     0,    16,    19,     0,    20,     0,     0,    11,
       0,    24,    15,    18,    21,    26,    23,     0,     0,    10,
       0,     0,     0,     0,    22,    33,    38,    62,    28,    25,
      27,    31,     0,    60,    37,    42,    51,    56,    61,    29,
      30,     0,     0,    34,     0,     0,    39,     0,    32,     0,
      48,    47,    44,    43,    45,    46,    52,    53,     0,    49,
      57,    58,    54,     0,     0,    35,    59,     0,    66,    36,
      60,    41,     0,     0,     0,     0,     0,    68,     0,    65,
      50,    55,    69,    71,    40,    64,     0,     0,    67,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -85,   -85,   -85,    84,    -5,    75,    57,   -85,     8,   -85,
     -85,   -85,   -85,    68,    71,   -85,   -85,   -84,   -85,   -85,
     -42,   -75,   -85,   -85,   -85,    16,   -85,   -85,     1,   -85,
     -85,     2,   -85,   -85,   -85,   -85,   -85,   -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    46,    47,     6,    14,     7,     8,
      15,    22,    23,    24,    48,    35,    38,    49,    50,    51,
      52,    53,    87,    54,    78,    55,    92,    79,    56,    93,
      82,    57,    58,    67,    98,    99,    59,    60
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    65,    12,    90,     1,     2,   -14,    40,    41,    42,
     102,   103,    13,     9,    18,    11,    26,    90,    90,    83,
      84,    18,    11,   109,    43,    21,    11,    89,    31,    44,
      45,    43,    39,    40,    41,    42,    21,    63,    18,    11,
      18,    11,   -63,    37,    66,    96,    97,    16,    43,    17,
      43,     1,    20,    28,    31,   -17,    45,    70,    71,    72,
      73,    74,    75,    18,   108,    80,    81,    76,    77,    25,
      27,    34,    30,    29,    76,    77,    31,    13,    61,    62,
      68,    86,    85,    88,   104,    94,    95,   105,    10,   106,
      69,    19,    36,   100,    91,   101,    33,   107,    32
};

static const yytype_int8 yycheck[] =
{
      42,    43,     7,    78,     6,     7,    20,     3,     4,     5,
      94,    95,    26,     0,    10,    11,    21,    92,    93,    61,
      62,    10,    11,   107,    20,    17,    11,    69,    24,    25,
      26,    20,    37,     3,     4,     5,    28,    26,    10,    11,
      10,    11,    20,    35,    22,    87,    88,    22,    20,    20,
      20,     6,     7,    27,    24,    21,    26,    14,    15,    16,
      17,    18,    19,    10,   106,    33,    34,    31,    32,    23,
      21,    23,    22,    26,    31,    32,    24,    26,    20,    20,
      26,    21,    26,    20,    23,    21,    21,    21,     4,    27,
      35,    16,    35,    92,    78,    93,    28,    30,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    37,    38,    39,    42,    44,    45,     0,
      39,    11,    40,    26,    43,    46,    22,    20,    10,    41,
       7,    44,    47,    48,    49,    23,    40,    21,    27,    26,
      22,    24,    50,    49,    23,    51,    42,    44,    52,    40,
       3,     4,     5,    20,    25,    26,    40,    41,    50,    53,
      54,    55,    56,    57,    59,    61,    64,    67,    68,    72,
      73,    20,    20,    26,    56,    56,    22,    69,    26,    35,
      14,    15,    16,    17,    18,    19,    31,    32,    60,    63,
      33,    34,    66,    56,    56,    26,    21,    58,    20,    56,
      57,    61,    62,    65,    21,    21,    56,    56,    70,    71,
      64,    67,    53,    53,    23,    21,    27,    30,    56,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    41,    42,
      43,    42,    44,    44,    46,    45,    47,    47,    48,    48,
      49,    49,    50,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    58,
      57,    59,    59,    60,    60,    60,    60,    60,    60,    62,
      61,    61,    63,    63,    65,    64,    64,    66,    66,    67,
      67,    67,    67,    69,    68,    70,    70,    71,    71,    72,
      72,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       0,     7,     1,     1,     0,     7,     1,     1,     3,     1,
       2,     4,     4,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     2,     1,     2,     3,     3,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     1,     1,     1,     0,     4,     1,     1,     1,     3,
       1,     1,     1,     0,     5,     1,     0,     3,     1,     5,
       7,     5
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
  case 2: /* program: declaration_list  */
#line 54 "cminus.y"
                          { savedTree = yyvsp[0]; }
#line 1337 "y.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 56 "cminus.y"
                                                { 
                    YYSTYPE t = yyvsp[-1];
                     if (t != NULL) {
                       while (t->sibling != NULL) { t = t->sibling; }
                       t->sibling = yyvsp[0];
                       yyval = yyvsp[-1];
                     } else {
                       yyval = yyvsp[0];
                     }
                   }
#line 1352 "y.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 66 "cminus.y"
                               { yyval = yyvsp[0]; }
#line 1358 "y.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 69 "cminus.y"
                             { yyval = yyvsp[0]; }
#line 1364 "y.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 70 "cminus.y"
                              { yyval = yyvsp[0]; }
#line 1370 "y.tab.c"
    break;

  case 7: /* id: ID  */
#line 72 "cminus.y"
       { 
       savedName = copyString(tokenString);
       savedLineNo = lineno;
     }
#line 1379 "y.tab.c"
    break;

  case 8: /* num: NUM  */
#line 77 "cminus.y"
         { 
    savedNum = atoi(copyString(tokenString));
    savedLineNo = lineno;
    yyval = newExprNode(ConstExpr);
    yyval->lineno=lineno;
    yyval->val=atoi(copyString(tokenString));
  }
#line 1391 "y.tab.c"
    break;

  case 9: /* var_declaration: type_specifier id SEMI  */
#line 86 "cminus.y"
                 {
                   yyval = newDecNode(VarDec);
                   yyval->lineno = savedLineNo; /* Use the saved line number */
                   yyval->name = copyString(savedName);
                   yyval->type = savedType;
                 }
#line 1402 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 93 "cminus.y"
                 {
                   /* Capture the line number of the identifier */
                   savedLineNo = lineno;
                 }
#line 1411 "y.tab.c"
    break;

  case 11: /* var_declaration: type_specifier id $@1 LBRACE num RBRACE SEMI  */
#line 98 "cminus.y"
                 { 
                   yyval = newDecNode(ArrDec);
                   yyval->child[0] = yyvsp[-6];
                   yyval->child[1] = yyvsp[-2]; /* Note: shifted from $4 to $5 due to the added action */
                   yyval->lineno = savedLineNo; /* Use the saved line number */
                   yyval->name = copyString(savedName);
                   if (savedType == Integer)
                     yyval->type = IntegerArray;
                   else
                     yyval->type = VoidArray;
                 }
#line 1427 "y.tab.c"
    break;

  case 12: /* type_specifier: INT  */
#line 110 "cminus.y"
                    { savedType=Integer; }
#line 1433 "y.tab.c"
    break;

  case 13: /* type_specifier: VOID  */
#line 111 "cminus.y"
                     { savedType=Void; }
#line 1439 "y.tab.c"
    break;

  case 14: /* @2: %empty  */
#line 113 "cminus.y"
                                     {
                   yyval = newDecNode(FuncDec);
                   yyval->lineno = lineno;
                   yyval->name = copyString(savedName);
                   yyval->type = savedType;
                 }
#line 1450 "y.tab.c"
    break;

  case 15: /* func_declaration: type_specifier id @2 LPAREN params RPAREN compound_stmt  */
#line 120 "cminus.y"
                 { yyval = yyvsp[-4];
                   yyval->child[0] = yyvsp[-6];
                   yyval->child[1] = yyvsp[-2];
                   yyval->child[2] = yyvsp[0];
                 }
#line 1460 "y.tab.c"
    break;

  case 16: /* params: param_list  */
#line 127 "cminus.y"
                   { yyval = yyvsp[0]; }
#line 1466 "y.tab.c"
    break;

  case 17: /* params: VOID  */
#line 128 "cminus.y"
             { yyval = newDecNode(ParamDec);
           yyval->type = Void;
         }
#line 1474 "y.tab.c"
    break;

  case 18: /* param_list: param_list COMMA param  */
#line 132 "cminus.y"
                                   { 
              YYSTYPE t = yyvsp[-2];
              if (t != NULL) {
                while (t->sibling != NULL) { t = t->sibling; }
                t->sibling = yyvsp[0];
                yyval = yyvsp[-2];
              } else {
                yyval = yyvsp[-1];
              }
            }
#line 1489 "y.tab.c"
    break;

  case 19: /* param_list: param  */
#line 142 "cminus.y"
                  { yyval = yyvsp[0]; }
#line 1495 "y.tab.c"
    break;

  case 20: /* param: type_specifier id  */
#line 144 "cminus.y"
                          { 
          yyval = newDecNode(ParamDec);
          yyval->child[0] = yyvsp[-1];
          yyval->type=savedType;
          yyval->name = copyString(savedName);
        }
#line 1506 "y.tab.c"
    break;

  case 21: /* param: type_specifier id LBRACE RBRACE  */
#line 150 "cminus.y"
                                        { 
          yyval = newDecNode(ArrParamDec);
          yyval->child[0] = yyvsp[-3];
          if (savedType == Integer)
            yyval->type=IntegerArray;
          else
            yyval->type=VoidArray;
          yyval->name = copyString(savedName);
        }
#line 1520 "y.tab.c"
    break;

  case 22: /* compound_stmt: LCURLY local_declarations statement_list RCURLY  */
#line 160 "cminus.y"
                                                               { 
          yyval = newStmtNode(CompoundStmt);
          yyval->name = copyString("compound");
          yyval->child[0] = yyvsp[-2];
          yyval->child[1] = yyvsp[-1];
      }
#line 1531 "y.tab.c"
    break;

  case 23: /* local_declarations: local_declarations var_declaration  */
#line 167 "cminus.y"
                                                      { 
                      YYSTYPE t = yyvsp[-1];
                       if (t != NULL) {
                         while (t->sibling != NULL) { t = t->sibling; }
                         t->sibling = yyvsp[0];
                         yyval = yyvsp[-1];
                       } else {
                         yyval = yyvsp[0];
                       }
                     }
#line 1546 "y.tab.c"
    break;

  case 24: /* local_declarations: %empty  */
#line 177 "cminus.y"
                     { yyval = NULL; }
#line 1552 "y.tab.c"
    break;

  case 25: /* statement_list: statement_list statement  */
#line 180 "cminus.y"
                                          { 
                   YYSTYPE t = yyvsp[-1];
                   if (t != NULL) {
                     while (t->sibling != NULL) { t = t->sibling; }
                    t->sibling = yyvsp[0];
                    yyval = yyvsp[-1];
                   } else {
                     yyval = yyvsp[0];
                   }
                 }
#line 1567 "y.tab.c"
    break;

  case 26: /* statement_list: %empty  */
#line 190 "cminus.y"
                 { yyval = NULL; }
#line 1573 "y.tab.c"
    break;

  case 27: /* statement: expression_stmt  */
#line 193 "cminus.y"
                           { yyval = yyvsp[0]; }
#line 1579 "y.tab.c"
    break;

  case 28: /* statement: compound_stmt  */
#line 194 "cminus.y"
                         { yyval = yyvsp[0]; }
#line 1585 "y.tab.c"
    break;

  case 29: /* statement: selection_stmt  */
#line 195 "cminus.y"
                          { yyval = yyvsp[0]; }
#line 1591 "y.tab.c"
    break;

  case 30: /* statement: iteration_stmt  */
#line 196 "cminus.y"
                          { yyval = yyvsp[0]; }
#line 1597 "y.tab.c"
    break;

  case 31: /* statement: return_stmt  */
#line 197 "cminus.y"
                       { yyval = yyvsp[0]; }
#line 1603 "y.tab.c"
    break;

  case 32: /* expression_stmt: expression SEMI  */
#line 199 "cminus.y"
                                 { yyval = yyvsp[-1]; }
#line 1609 "y.tab.c"
    break;

  case 33: /* expression_stmt: SEMI  */
#line 200 "cminus.y"
                      { yyval = 0; }
#line 1615 "y.tab.c"
    break;

  case 34: /* return_stmt: RETURN SEMI  */
#line 202 "cminus.y"
                         { 
              yyval = newStmtNode(ReturnStmt);
              yyval->type=Void;
            }
#line 1624 "y.tab.c"
    break;

  case 35: /* return_stmt: RETURN expression SEMI  */
#line 206 "cminus.y"
                                    { 
             yyval = newStmtNode(ReturnStmt);
             yyval->type = Integer;
             yyval->child[0] = yyvsp[-1];
             yyval->name = copyString("return");
            }
#line 1635 "y.tab.c"
    break;

  case 36: /* expression: var ASSIGN expression  */
#line 213 "cminus.y"
                                  { 
            yyval = newExprNode(AssignExpr);
            yyval->child[0] = yyvsp[-2];
            yyval->child[1] = yyvsp[0];
            yyval->name = copyString("expression");
            yyval->lineno = savedLineNo;
          }
#line 1647 "y.tab.c"
    break;

  case 37: /* expression: simple_expression  */
#line 220 "cminus.y"
                              { yyval = yyvsp[0]; }
#line 1653 "y.tab.c"
    break;

  case 38: /* var: id  */
#line 222 "cminus.y"
        { yyval = newExprNode(IdExpr); yyval->name=copyString(savedName); yyval->type=savedType; }
#line 1659 "y.tab.c"
    break;

  case 39: /* @3: %empty  */
#line 223 "cminus.y"
               {
      yyval = newExprNode(IdExpr);
      yyval->name=copyString(savedName); 
      yyval->type=Integer;
    }
#line 1669 "y.tab.c"
    break;

  case 40: /* var: id LBRACE @3 expression RBRACE  */
#line 228 "cminus.y"
                      { 
      yyval = yyvsp[-2];
      yyval->child[0] = yyvsp[-1];
    }
#line 1678 "y.tab.c"
    break;

  case 41: /* simple_expression: additive_expression relop additive_expression  */
#line 233 "cminus.y"
                                                                 { 
                     yyval = newExprNode(OpExpr);
                     yyval->child[0] = yyvsp[-2];
                     yyval->child[1] = yyvsp[0];
                     yyval->op = savedOp;
                     yyval->name = copyString("simple_expression");
                   }
#line 1690 "y.tab.c"
    break;

  case 42: /* simple_expression: additive_expression  */
#line 240 "cminus.y"
                                       { yyval = yyvsp[0]; }
#line 1696 "y.tab.c"
    break;

  case 43: /* relop: LE  */
#line 242 "cminus.y"
          { savedOp = LE; }
#line 1702 "y.tab.c"
    break;

  case 44: /* relop: LT  */
#line 243 "cminus.y"
          { savedOp = LT; }
#line 1708 "y.tab.c"
    break;

  case 45: /* relop: GT  */
#line 244 "cminus.y"
          { savedOp = GT; }
#line 1714 "y.tab.c"
    break;

  case 46: /* relop: GE  */
#line 245 "cminus.y"
          { savedOp = GE; }
#line 1720 "y.tab.c"
    break;

  case 47: /* relop: NE  */
#line 246 "cminus.y"
          { savedOp = NE; }
#line 1726 "y.tab.c"
    break;

  case 48: /* relop: EQ  */
#line 247 "cminus.y"
          { savedOp = EQ; }
#line 1732 "y.tab.c"
    break;

  case 49: /* @4: %empty  */
#line 249 "cminus.y"
                                               {
                        yyval = newExprNode(OpExpr);
                        yyval->name = copyString("additive_expression");
                        yyval->op=savedOp;
                    }
#line 1742 "y.tab.c"
    break;

  case 50: /* additive_expression: additive_expression addop @4 term  */
#line 253 "cminus.y"
                           { 
                         yyval = yyvsp[-1];
                         yyval -> child[0] = yyvsp[-3];
                         yyval -> child[1] = yyvsp[0];
                    }
#line 1752 "y.tab.c"
    break;

  case 51: /* additive_expression: term  */
#line 258 "cminus.y"
                          { yyval = yyvsp[0]; }
#line 1758 "y.tab.c"
    break;

  case 52: /* addop: PLUS  */
#line 260 "cminus.y"
            { savedOp = PLUS; }
#line 1764 "y.tab.c"
    break;

  case 53: /* addop: MINUS  */
#line 261 "cminus.y"
             { savedOp = MINUS; }
#line 1770 "y.tab.c"
    break;

  case 54: /* @5: %empty  */
#line 263 "cminus.y"
                 {
yyval=newExprNode(OpExpr);
yyval->op=savedOp;  
}
#line 1779 "y.tab.c"
    break;

  case 55: /* term: term mulop @5 factor  */
#line 267 "cminus.y"
       { 
  yyval = yyvsp[-1];
  yyval->child[0]=yyvsp[-3]; 
  yyval->child[1]=yyvsp[0]; 
  
  }
#line 1790 "y.tab.c"
    break;

  case 56: /* term: factor  */
#line 273 "cminus.y"
             { yyval = yyvsp[0]; }
#line 1796 "y.tab.c"
    break;

  case 57: /* mulop: TIMES  */
#line 276 "cminus.y"
             { savedOp = TIMES; }
#line 1802 "y.tab.c"
    break;

  case 58: /* mulop: OVER  */
#line 277 "cminus.y"
            { savedOp = OVER; }
#line 1808 "y.tab.c"
    break;

  case 59: /* factor: LPAREN expression RPAREN  */
#line 279 "cminus.y"
                                 { yyval = yyvsp[-1]; }
#line 1814 "y.tab.c"
    break;

  case 60: /* factor: var  */
#line 280 "cminus.y"
            { yyval = yyvsp[0]; }
#line 1820 "y.tab.c"
    break;

  case 61: /* factor: call  */
#line 281 "cminus.y"
             { yyval = yyvsp[0]; }
#line 1826 "y.tab.c"
    break;

  case 62: /* factor: num  */
#line 282 "cminus.y"
            { 
           yyval = newExprNode(ConstExpr);
           yyval->type = Integer;
           yyval->val = atoi(copyString(tokenString));
         }
#line 1836 "y.tab.c"
    break;

  case 63: /* @6: %empty  */
#line 289 "cminus.y"
         {
  yyval = newExprNode(CallExpr);
  yyval->name = copyString(savedName);
}
#line 1845 "y.tab.c"
    break;

  case 64: /* call: id @6 LPAREN args RPAREN  */
#line 292 "cminus.y"
                     { 
  yyval = yyvsp[-3];
  yyval->child[0] = yyvsp[-1];
}
#line 1854 "y.tab.c"
    break;

  case 65: /* args: arg_list  */
#line 297 "cminus.y"
               { yyval=yyvsp[0]; }
#line 1860 "y.tab.c"
    break;

  case 66: /* args: %empty  */
#line 298 "cminus.y"
      { yyval = NULL; }
#line 1866 "y.tab.c"
    break;

  case 67: /* arg_list: arg_list COMMA expression  */
#line 300 "cminus.y"
                                    { 
   YYSTYPE t = yyvsp[-2];
             if (t != NULL) {
               while (t->sibling != NULL) { t = t->sibling; }
               t->sibling = yyvsp[0];
               yyval = yyvsp[-2];
             } else {
               yyval = yyvsp[0];
             }
}
#line 1881 "y.tab.c"
    break;

  case 68: /* arg_list: expression  */
#line 310 "cminus.y"
                     {yyval = yyvsp[0];}
#line 1887 "y.tab.c"
    break;

  case 69: /* selection_stmt: IF LPAREN expression RPAREN statement  */
#line 313 "cminus.y"
                                                      { 
                  yyval = newStmtNode(IfStmt);
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
                }
#line 1897 "y.tab.c"
    break;

  case 70: /* selection_stmt: IF LPAREN expression RPAREN statement ELSE statement  */
#line 318 "cminus.y"
                                                                     { 
                  yyval = newStmtNode(IfElseStmt);
                  yyval->child[0] = yyvsp[-4];
                  yyval->child[1] = yyvsp[-2];
                  yyval->child[2] = yyvsp[0];
                }
#line 1908 "y.tab.c"
    break;

  case 71: /* iteration_stmt: WHILE LPAREN expression RPAREN statement  */
#line 325 "cminus.y"
                                                         { 
                  yyval = newStmtNode(WhileStmt);
                  yyval->child[0] = yyvsp[-2];
                  yyval->child[1] = yyvsp[0];
                }
#line 1918 "y.tab.c"
    break;


#line 1922 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 331 "cminus.y"



int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

