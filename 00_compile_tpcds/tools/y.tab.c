#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "qgen.y"
/* 
 * Legal Notice 
 * 
 * This document and associated source code (the "Work") is a part of a 
 * benchmark specification maintained by the TPC. 
 * 
 * The TPC reserves all right, title, and interest to the Work as provided 
 * under U.S. and international laws, including without limitation all patent 
 * and trademark rights therein. 
 * 
 * No Warranty 
 * 
 * 1.1 TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THE INFORMATION 
 *     CONTAINED HEREIN IS PROVIDED "AS IS" AND WITH ALL FAULTS, AND THE 
 *     AUTHORS AND DEVELOPERS OF THE WORK HEREBY DISCLAIM ALL OTHER 
 *     WARRANTIES AND CONDITIONS, EITHER EXPRESS, IMPLIED OR STATUTORY, 
 *     INCLUDING, BUT NOT LIMITED TO, ANY (IF ANY) IMPLIED WARRANTIES, 
 *     DUTIES OR CONDITIONS OF MERCHANTABILITY, OF FITNESS FOR A PARTICULAR 
 *     PURPOSE, OF ACCURACY OR COMPLETENESS OF RESPONSES, OF RESULTS, OF 
 *     WORKMANLIKE EFFORT, OF LACK OF VIRUSES, AND OF LACK OF NEGLIGENCE. 
 *     ALSO, THERE IS NO WARRANTY OR CONDITION OF TITLE, QUIET ENJOYMENT, 
 *     QUIET POSSESSION, CORRESPONDENCE TO DESCRIPTION OR NON-INFRINGEMENT 
 *     WITH REGARD TO THE WORK. 
 * 1.2 IN NO EVENT WILL ANY AUTHOR OR DEVELOPER OF THE WORK BE LIABLE TO 
 *     ANY OTHER PARTY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO THE 
 *     COST OF PROCURING SUBSTITUTE GOODS OR SERVICES, LOST PROFITS, LOSS 
 *     OF USE, LOSS OF DATA, OR ANY INCIDENTAL, CONSEQUENTIAL, DIRECT, 
 *     INDIRECT, OR SPECIAL DAMAGES WHETHER UNDER CONTRACT, TORT, WARRANTY,
 *     OR OTHERWISE, ARISING IN ANY WAY OUT OF THIS OR ANY OTHER AGREEMENT 
 *     RELATING TO THE WORK, WHETHER OR NOT SUCH AUTHOR OR DEVELOPER HAD 
 *     ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. 
 * 
 * Contributors:
 * Gradient Systems
 */
#include "config.h"
#include "porting.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef WIN32
#include <io.h>
#pragma warning(disable: 4305)
#endif

#include "StringBuffer.h"
#include "expr.h"
#include "grammar_support.h"
#include "keywords.h"
#include "substitution.h"
#include "error_msg.h"
#include "tables.h"
#include "qgen_params.h"
#include "tdefs.h"
#include "query_handler.h"
#include "list.h"
#include "dist.h"
#include "scaling.h"


#define DEBUG0(l, fmt) 				if (l <= verbose) printf(fmt)
#define DEBUG1(l, fmt, arg)			if (l <= verbose) printf(fmt, arg)
#define DEBUG2(l, fmt, arg, arg2)	if (l <= verbose) printf(fmt, arg, arg2)

extern file_ref_t file_stack[];

int yylex(void);

#ifdef WIN32
int yyparse(void);
#endif

/* GLOBAL VARIABLES */
int verbose = 0,
	j,
	nRetCode;
ds_key_t i;
char tmpstr[128];
segment_t *pSegment;
substitution_t *pSub;
#line 87 "qgen.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int		intval;
    char	*strval;
	expr_t	*exprval;
	list_t  *list;
    } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 117 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TOK_INT 257
#define TOK_LITERAL 258
#define TOK_PATH 259
#define TOK_DECIMAL 260
#define TOK_ID 261
#define TOK_SQL 262
#define KW_DEFINE 263
#define KW_RANDOM 264
#define KW_UNIFORM 265
#define KW_RANGE 266
#define KW_DATE 267
#define KW_INCLUDE 268
#define KW_TEXT 269
#define KW_DIST 270
#define KW_LIST 271
#define KW_ROWCOUNT 272
#define KW_BEGIN 273
#define KW_END 274
#define KW_SALES 275
#define KW_RETURNS 276
#define KW_DISTMEMBER 277
#define KW_DISTWEIGHT 278
#define KW_QUERY 279
#define KW_STREAM 280
#define KW_TEMPLATE 281
#define KW_SEED 282
#define KW_SCALE 283
#define KW_SCALE_STEP 284
#define KW_SET 285
#define KW_ADD 286
#define KW_NAMES 287
#define KW_TYPES 288
#define KW_WEIGHTS 289
#define KW_INT 290
#define KW_VARCHAR 291
#define KW_DECIMAL 292
#define KW_LIMIT 293
#define KW_LIMITA 294
#define KW_LIMITB 295
#define KW_LIMITC 296
#define KW_ULIST 297
#define WITH 298
#define UMINUS 299
#define TCAST 300
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   15,   15,   14,   14,   14,   14,   16,   16,   19,
   20,   20,   22,   22,   22,   25,   25,   25,   23,   23,
   23,   24,   24,   21,   21,   26,   29,   29,   29,   27,
   27,   28,   28,   17,   17,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    5,    5,    5,    5,    2,
    2,    2,    2,    7,    7,    6,    6,    6,    8,    8,
    8,    9,    9,    9,    9,   13,   13,   12,   18,   30,
   30,   30,   30,   31,   31,   31,   31,   31,   31,   31,
   31,   31,   11,   11,   11,   11,   10,
};
static const short yylen[] = {                            2,
    1,    1,    2,    1,    1,    1,    1,    3,    5,    5,
    1,    2,    5,    7,    9,    1,    1,    1,    0,    1,
    3,    1,    3,    1,    2,    7,    1,    1,    1,    1,
    3,    1,    3,    5,    5,    1,    3,    1,    1,    1,
    1,    3,    5,    4,    1,    1,    4,    4,    4,    4,
    6,    3,    6,    6,    6,    3,    3,    3,    3,    1,
    1,    3,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    5,    2,    1,
    1,    2,    2,    4,    5,    3,    3,    3,    3,    3,
    3,    3,    0,    2,    2,    2,    1,
};
static const short yydefred[] = {                         0,
   81,    0,    0,    0,    0,    0,    2,    0,    4,    5,
    6,    7,    0,   80,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,   83,   79,   82,
    0,    0,    0,    0,    0,    0,   86,   87,   88,   89,
   90,   91,   92,   97,    0,    8,   39,   38,   65,   69,
    0,   64,    0,   66,    0,    0,   70,   71,   67,   68,
   45,    0,    0,    0,    0,   40,   46,    0,    0,   41,
    0,    0,    0,   11,    0,   96,   94,   95,   84,    0,
    0,    0,    0,    0,    0,    0,    0,   72,   74,   73,
   75,    0,    0,    0,    0,    0,   34,    0,    0,   35,
    0,    0,    0,    0,    0,   12,   24,   85,    9,    0,
    0,   76,    0,    0,    0,   52,    0,    0,    0,   42,
    0,    0,   58,   59,   61,    0,    0,    0,    0,    0,
    0,    0,    0,   25,    0,    0,   49,    0,    0,   50,
    0,    0,    0,   44,   48,    0,   47,    0,    0,    0,
    0,   27,   28,   29,    0,   30,    0,    0,   77,    0,
    0,    0,   43,   63,    0,    0,   22,    0,   16,   17,
   18,    0,   20,   13,    0,    0,   55,    0,   54,   51,
   53,    0,    0,    0,    0,    0,    0,    0,   31,   78,
    0,   23,   14,   21,    0,    0,    0,    0,   26,   15,
};
static const short yydgoto[] = {                          6,
  128,  126,   65,   66,   67,   68,   69,   70,   92,   46,
   36,  112,  113,    7,    8,    9,   10,   11,   12,   73,
  105,   74,  172,  168,  173,  107,  155,  188,  156,   13,
   14,
};
static const short yysindex[] = {                       -35,
    0, -247, -250, -252, -233,    0,    0,  -35,    0,    0,
    0,    0,  -54,    0,  -21,  -14,  -18,  -44,  -45,  -29,
  -23,   -6,   -4,   -2,    6,  -53,    0,    0,    0,    0,
  -17, -185, -206,   47, -241,   12,    0,    0,    0,    0,
    0,    0,    0,    0, -149,    0,    0,    0,    0,    0,
   71,    0,  101,    0,  103,  107,    0,    0,    0,    0,
    0,  111,  112, -230,   35,    0,    0,  113,  114,    0,
   97, -143, -267,    0,   62,    0,    0,    0,    0,   95,
  -17,   36,  -17, -100,  119,  -17,  -43,    0,    0,    0,
    0,   68,  -17,  -17,  -17,  -17,    0,  -87,  -17,    0,
  102,  104,  105,  122, -122,    0,    0,    0,    0,   41,
  -91,    0,   74,   53,   76,    0,   59,   47,   75,    0,
  -30,  -30,    0,    0,    0,   78,   65,   80,   65,  129,
  132,  -84, -203,    0,  -82,  137,    0,   36,  -81,    0,
  -72,  -70,   99,    0,    0,  -46,    0,  -17,  -68, -142,
  135,    0,    0,    0,  -20,    0,  154,  -59,    0,  158,
  159,  160,    0,    0,   65,   65,    0,   -5,    0,    0,
    0,   82,    0,    0, -189, -203,    0,   77,    0,    0,
    0,  -68,  -58,  145, -142,    0,  162,  166,    0,    0,
   84,    0,    0,    0, -144,  150,  157,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,  217,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  140,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  140,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  140,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  140,    0,    0,
   17,   22,    0,    0,    0,    0,   86,    0,   88,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   90,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   92,   94,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   96,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   98,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,  -73,    0,    0,    0,    0,    0,    0,  177,
  -28,  106,    0,  226,    0,    0,    0,    0,    0,    0,
    0,  163,    0,   57,   58,  141,   67,    0, -161,    0,
  232,
};
#define YYTABLESIZE 280
static const short yytable[] = {                          5,
   10,   35,   35,   64,   29,   75,   45,  110,   18,  114,
   17,   95,  117,   15,  189,   76,   96,   72,  104,  121,
  122,  123,  124,  176,  127,  129,   19,   20,   21,   22,
   87,   77,   78,  189,   26,   10,    4,  175,  183,   31,
   33,   23,   24,   25,   64,   16,   32,   37,   88,   89,
   90,   91,  182,  152,  153,    4,  154,   56,  119,   56,
   56,   56,   57,   38,   57,   57,   57,  186,  153,   39,
  154,   71,  165,   64,  166,   56,   95,   93,   72,   94,
   57,   96,   95,   93,  135,   94,   40,   96,   41,  143,
   42,   10,   35,   97,   95,   93,  139,   94,   43,   96,
   95,   93,  142,   94,   79,   96,   95,   93,   44,   94,
   81,   96,  198,  153,  137,  154,  140,  138,  145,  141,
  147,  146,  184,  148,  197,  185,   60,  183,   36,   60,
   19,   36,   62,   19,   37,   62,   32,   37,   33,   27,
   82,   27,   83,  101,  102,  103,   84,  169,  170,  171,
   85,   86,   98,   99,  108,  100,  109,  115,  111,  116,
  120,  133,  130,  104,  131,  132,  136,  144,  149,   47,
   48,  150,  151,  125,  157,  160,   49,   50,   51,   52,
  158,   53,   54,   55,   56,  161,  162,   57,   58,   59,
   60,  163,  167,  174,  177,   61,   62,  178,  179,  180,
  181,  190,  192,  193,   44,  195,  196,   28,  199,   63,
   47,   48,   34,  118,  164,  200,    1,   49,   50,   51,
   52,   80,   53,   54,   55,   56,    1,    2,   57,   58,
   59,   60,   93,   27,    3,  106,   61,   62,  191,   47,
   48,  187,  194,  159,   30,  134,   49,   50,   51,   52,
   63,   53,   54,   55,   56,    0,    0,   57,   58,   59,
   60,    0,   10,   10,    0,   61,   62,    0,    0,    0,
   10,    0,    0,    0,    0,    0,    0,    0,    0,   63,
};
static const short yycheck[] = {                         35,
    0,   46,   46,   91,   59,   34,   60,   81,  261,   83,
  261,   42,   86,  261,  176,  257,   47,  285,  286,   93,
   94,   95,   96,   44,   98,   99,  279,  280,  281,  282,
  261,  273,  274,  195,  268,   35,   91,   58,   44,   61,
   59,  294,  295,  296,   91,  293,   61,   93,  279,  280,
  281,  282,   58,  257,  258,   91,  260,   41,   87,   43,
   44,   45,   41,   93,   43,   44,   45,  257,  258,   93,
  260,  257,  146,   91,  148,   59,   42,   43,  285,   45,
   59,   47,   42,   43,   44,   45,   93,   47,   93,  118,
   93,   91,   46,   59,   42,   43,   44,   45,   93,   47,
   42,   43,   44,   45,   93,   47,   42,   43,  258,   45,
   40,   47,  257,  258,   41,  260,   41,   44,   41,   44,
   41,   44,   41,   44,   41,   44,   41,   44,   41,   44,
   41,   44,   41,   44,   41,   44,   41,   44,   41,   44,
   40,   44,   40,  287,  288,  289,   40,  290,  291,  292,
   40,   40,   40,   40,   93,   59,   62,  258,  123,   41,
   93,   40,   61,  286,   61,   61,  258,   93,   40,  257,
  258,   40,  257,  261,  257,  257,  264,  265,  266,  267,
   44,  269,  270,  271,  272,  258,  257,  275,  276,  277,
  278,   93,  261,   59,   41,  283,  284,  257,   41,   41,
   41,  125,  261,   59,  258,   44,   41,  262,   59,  297,
  257,  258,  257,  257,  261,   59,    0,  264,  265,  266,
  267,   45,  269,  270,  271,  272,  262,  263,  275,  276,
  277,  278,   93,    8,  270,   73,  283,  284,  182,  257,
  258,  175,  185,  138,   13,  105,  264,  265,  266,  267,
  297,  269,  270,  271,  272,   -1,   -1,  275,  276,  277,
  278,   -1,  262,  263,   -1,  283,  284,   -1,   -1,   -1,
  270,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  297,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 300
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'#'",0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,
0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TOK_INT","TOK_LITERAL",
"TOK_PATH","TOK_DECIMAL","TOK_ID","TOK_SQL","KW_DEFINE","KW_RANDOM",
"KW_UNIFORM","KW_RANGE","KW_DATE","KW_INCLUDE","KW_TEXT","KW_DIST","KW_LIST",
"KW_ROWCOUNT","KW_BEGIN","KW_END","KW_SALES","KW_RETURNS","KW_DISTMEMBER",
"KW_DISTWEIGHT","KW_QUERY","KW_STREAM","KW_TEMPLATE","KW_SEED","KW_SCALE",
"KW_SCALE_STEP","KW_SET","KW_ADD","KW_NAMES","KW_TYPES","KW_WEIGHTS","KW_INT",
"KW_VARCHAR","KW_DECIMAL","KW_LIMIT","KW_LIMITA","KW_LIMITB","KW_LIMITC",
"KW_ULIST","WITH","UMINUS","TCAST",
};
static const char *yyrule[] = {
"$accept : workload_spec",
"workload_spec : statement_list",
"statement_list : statement",
"statement_list : statement_list statement",
"statement : include_statement",
"statement : define_statement",
"statement : query_statement",
"statement : dist_statement",
"include_statement : '#' KW_INCLUDE path",
"include_statement : '#' KW_INCLUDE '<' path '>'",
"dist_statement : KW_DIST TOK_ID ';' dist_argument_list dist_members_list",
"dist_argument_list : dist_argument",
"dist_argument_list : dist_argument_list dist_argument",
"dist_argument : KW_SET KW_WEIGHTS '=' TOK_INT ';'",
"dist_argument : KW_SET KW_TYPES '=' '(' dist_type_list ')' ';'",
"dist_argument : KW_SET KW_NAMES '=' '(' dist_name_list ':' dist_name_list ')' ';'",
"dist_type : KW_INT",
"dist_type : KW_VARCHAR",
"dist_type : KW_DECIMAL",
"dist_type_list :",
"dist_type_list : dist_type",
"dist_type_list : dist_type_list ',' dist_type",
"dist_name_list : TOK_ID",
"dist_name_list : dist_name_list ',' TOK_ID",
"dist_members_list : dist_member",
"dist_members_list : dist_members_list dist_member",
"dist_member : KW_ADD '(' dist_value_list ':' dist_weight_list ')' ';'",
"dist_value : TOK_INT",
"dist_value : TOK_LITERAL",
"dist_value : TOK_DECIMAL",
"dist_value_list : dist_value",
"dist_value_list : dist_value_list ',' dist_value",
"dist_weight_list : TOK_INT",
"dist_weight_list : dist_value_list ',' TOK_INT",
"define_statement : KW_DEFINE TOK_ID '=' expr ';'",
"define_statement : KW_DEFINE KW_LIMIT '=' TOK_INT ';'",
"comma_expr_list : expr",
"comma_expr_list : comma_expr_list ',' expr",
"expr : TOK_LITERAL",
"expr : TOK_INT",
"expr : function_call",
"expr : keyword_expr",
"expr : '[' keyword_value ']'",
"expr : '[' TOK_ID TOK_INT opt_substitution_suffix ']'",
"expr : '[' TOK_ID opt_substitution_suffix ']'",
"expr : KW_SCALE",
"expr : arithmetic_expr",
"function_call : function_name '(' comma_expr_list ')'",
"function_call : dist_function_name '(' dist_expr_list ')'",
"function_call : KW_TEXT '(' replacement_list ')'",
"function_call : KW_ROWCOUNT '(' TOK_LITERAL ')'",
"function_call : KW_ROWCOUNT '(' TOK_LITERAL ',' TOK_LITERAL ')'",
"function_call : KW_SCALE_STEP '(' ')'",
"function_call : KW_ULIST '(' expr ',' TOK_INT ')'",
"function_call : KW_LIST '(' expr ',' TOK_INT ')'",
"function_call : KW_RANGE '(' expr ',' TOK_INT ')'",
"arithmetic_expr : expr '+' expr",
"arithmetic_expr : expr '-' expr",
"arithmetic_expr : expr '*' expr",
"arithmetic_expr : expr '/' expr",
"dist_expr_list : expr",
"dist_expr_list : TOK_ID",
"dist_expr_list : dist_expr_list ',' expr",
"dist_expr_list : dist_expr_list ',' TOK_ID",
"function_name : KW_DATE",
"function_name : KW_RANDOM",
"dist_function_name : KW_DIST",
"dist_function_name : KW_DISTMEMBER",
"dist_function_name : KW_DISTWEIGHT",
"keyword_expr : KW_UNIFORM",
"keyword_expr : KW_SALES",
"keyword_expr : KW_RETURNS",
"keyword_value : KW_QUERY",
"keyword_value : KW_TEMPLATE",
"keyword_value : KW_STREAM",
"keyword_value : KW_SEED",
"replacement_list : replacement",
"replacement_list : replacement_list ',' replacement",
"replacement : '{' TOK_LITERAL ',' TOK_INT '}'",
"query_statement : query_component_list ';'",
"query_component_list : substitution",
"query_component_list : TOK_SQL",
"query_component_list : query_component_list substitution",
"query_component_list : query_component_list TOK_SQL",
"substitution : '[' TOK_ID opt_substitution_suffix ']'",
"substitution : '[' TOK_ID TOK_INT opt_substitution_suffix ']'",
"substitution : '[' KW_QUERY ']'",
"substitution : '[' KW_STREAM ']'",
"substitution : '[' KW_TEMPLATE ']'",
"substitution : '[' KW_SEED ']'",
"substitution : '[' KW_LIMITA ']'",
"substitution : '[' KW_LIMITB ']'",
"substitution : '[' KW_LIMITC ']'",
"opt_substitution_suffix :",
"opt_substitution_suffix : '.' KW_BEGIN",
"opt_substitution_suffix : '.' KW_END",
"opt_substitution_suffix : '.' TOK_INT",
"path : TOK_LITERAL",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 571 "qgen.y"


#line 521 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 160 "qgen.y"
	{
							AddQuerySegment(pCurrentQuery, "\n");
							AddQuerySubstitution(pCurrentQuery, "_END", 0, 0);
							AddQuerySegment(pCurrentQuery, "\n");
						}
break;
case 3:
#line 169 "qgen.y"
	{
							if (is_set("DEBUG"))
							{
								if (yystack.l_mark[0].intval != KW_DEFINE)
								{
									printf("STATUS: parsed %s statement at line %d\n", 
										(yystack.l_mark[0].intval == TOK_SQL)?"SQL":KeywordText(yystack.l_mark[0].intval), pCurrentFile->line_number);
								}
							}
						}
break;
case 4:
#line 181 "qgen.y"
	{yyval.intval = KW_INCLUDE; }
break;
case 5:
#line 182 "qgen.y"
	{yyval.intval = KW_DEFINE; }
break;
case 6:
#line 183 "qgen.y"
	{yyval.intval = TOK_SQL; }
break;
case 7:
#line 184 "qgen.y"
	{yyval.intval = KW_DIST; }
break;
case 8:
#line 193 "qgen.y"
	{
					if (include_file(yystack.l_mark[0].strval, pCurrentQuery) < 0)
						yyerror("File include failed");
					}
break;
case 9:
#line 198 "qgen.y"
	{
					yywarn("System include not supported; using relative pathing");
					if (include_file(yystack.l_mark[-1].strval, pCurrentQuery) < 0)
						yyerror("File include failed");
					}
break;
case 34:
#line 259 "qgen.y"
	{
						defineSubstitution(pCurrentQuery, yystack.l_mark[-3].strval, yystack.l_mark[-1].exprval);
						if (is_set("DEBUG"))
							printf("STATUS: DEFINED %s\n", yystack.l_mark[-3].strval);
						}
break;
case 35:
#line 265 "qgen.y"
	{
						pSub = findSubstitution(pCurrentQuery, "_LIMIT", 0);
						sprintf(tmpstr, "%d", yystack.l_mark[-1].intval);
						ResetBuffer(pSub->pAssignment->Value.pBuf);
						AddBuffer(pSub->pAssignment->Value.pBuf, tmpstr);
						if (is_set("DEBUG"))
							printf("STATUS: SET LIMIT\n");
						}
break;
case 36:
#line 277 "qgen.y"
	{
						yyval.list = makeList(L_FL_TAIL, NULL);
						addList(yyval.list, yystack.l_mark[0].exprval);
						}
break;
case 37:
#line 282 "qgen.y"
	{
						addList(yystack.l_mark[-2].list, yystack.l_mark[0].exprval);
						yyval.list = yystack.l_mark[-2].list;
						}
break;
case 38:
#line 289 "qgen.y"
	{
						yyval.exprval = MakeStringConstant(yystack.l_mark[0].strval);
						}
break;
case 39:
#line 293 "qgen.y"
	{
						yyval.exprval = MakeIntConstant(yystack.l_mark[0].intval);
						}
break;
case 41:
#line 298 "qgen.y"
	{
						yyval.exprval = MakeIntConstant(yystack.l_mark[0].intval);
						yyval.exprval->nFlags |= EXPR_FL_KEYWORD;
						}
break;
case 42:
#line 303 "qgen.y"
	{
						yyval.exprval = getKeywordValue(yystack.l_mark[-1].intval);
						}
break;
case 43:
#line 307 "qgen.y"
	{
						yyval.exprval = MakeVariableReference(yystack.l_mark[-3].strval, yystack.l_mark[-2].intval);
						}
break;
case 44:
#line 311 "qgen.y"
	{
						yyval.exprval = MakeVariableReference(yystack.l_mark[-2].strval, yystack.l_mark[-1].intval);
						}
break;
case 45:
#line 315 "qgen.y"
	{
						yyval.exprval = MakeIntConstant(get_int("SCALE"));
						}
break;
case 47:
#line 322 "qgen.y"
	{
						yyval.exprval = MakeFunctionCall(yystack.l_mark[-3].intval, yystack.l_mark[-1].list);
						}
break;
case 48:
#line 326 "qgen.y"
	{
						yyval.exprval = MakeFunctionCall(yystack.l_mark[-3].intval, yystack.l_mark[-1].list);
						}
break;
case 49:
#line 330 "qgen.y"
	{
						yyval.exprval = MakeFunctionCall(KW_TEXT, yystack.l_mark[-1].list);
						}
break;
case 50:
#line 334 "qgen.y"
	{
						i = GetTableNumber(yystack.l_mark[-1].strval);
						if (i == -1)
						{
							i = distsize(yystack.l_mark[-1].strval);
							if (i == -1)
								ReportError(QERR_BAD_NAME, yystack.l_mark[-1].strval, 1);
						}
						else
							i = getIDCount(i);
						yyval.exprval = MakeIntConstant(i);
						}
break;
case 51:
#line 347 "qgen.y"
	{
						/* TODO: Need to convert this to DSS_HUGE */
						i = GetTableNumber(yystack.l_mark[-3].strval);
						if (i == -1)
						{
							i = distsize(yystack.l_mark[-3].strval);
							if (i == -1)
								ReportError(QERR_BAD_NAME, yystack.l_mark[-3].strval, 1);
						}
						j = GetTableNumber(yystack.l_mark[-1].strval);
						if (i == -1)
							ReportError(QERR_BAD_NAME, yystack.l_mark[-1].strval, 1);
						i = (int)getIDCount(i);
						j = (int)getIDCount(j);
						yyval.exprval = MakeIntConstant((i>j)?j:i);
						}
break;
case 52:
#line 364 "qgen.y"
	{
						yyval.exprval = MakeIntConstant(getScaleSlot(get_int("SCALE")) + 1);
						}
break;
case 53:
#line 368 "qgen.y"
	{
						yyval.exprval = MakeListExpr(KW_ULIST, yystack.l_mark[-3].exprval, yystack.l_mark[-1].intval);
						}
break;
case 54:
#line 372 "qgen.y"
	{
						yyval.exprval = MakeListExpr(KW_LIST, yystack.l_mark[-3].exprval, yystack.l_mark[-1].intval);
						}
break;
case 55:
#line 376 "qgen.y"
	{
						yyval.exprval = MakeListExpr(KW_RANGE, yystack.l_mark[-3].exprval, yystack.l_mark[-1].intval);
						}
break;
case 56:
#line 382 "qgen.y"
	{
						yyval.exprval = makeArithmeticExpr(OP_ADD, yystack.l_mark[-2].exprval, yystack.l_mark[0].exprval);
						}
break;
case 57:
#line 386 "qgen.y"
	{
						yyval.exprval = makeArithmeticExpr(OP_SUBTRACT, yystack.l_mark[-2].exprval, yystack.l_mark[0].exprval);
						}
break;
case 58:
#line 390 "qgen.y"
	{
						yyval.exprval = makeArithmeticExpr(OP_MULTIPLY, yystack.l_mark[-2].exprval, yystack.l_mark[0].exprval);
						}
break;
case 59:
#line 394 "qgen.y"
	{
						yyval.exprval = makeArithmeticExpr(OP_DIVIDE, yystack.l_mark[-2].exprval, yystack.l_mark[0].exprval);
						}
break;
case 60:
#line 399 "qgen.y"
	{
						yyval.list = makeList(L_FL_TAIL, NULL);
						addList(yyval.list, yystack.l_mark[0].exprval);
						}
break;
case 61:
#line 404 "qgen.y"
	{
						yyval.list = makeList(L_FL_TAIL, NULL);
						addList(yyval.list, MakeStringConstant(yystack.l_mark[0].strval));
						}
break;
case 62:
#line 409 "qgen.y"
	{
						addList(yystack.l_mark[-2].list, yystack.l_mark[0].exprval);
						yyval.list = yystack.l_mark[-2].list;
						}
break;
case 63:
#line 414 "qgen.y"
	{
						addList(yystack.l_mark[-2].list, MakeStringConstant(yystack.l_mark[0].strval));
						yyval.list = yystack.l_mark[-2].list;
						}
break;
case 64:
#line 420 "qgen.y"
	{yyval.intval = KW_DATE;}
break;
case 65:
#line 421 "qgen.y"
	{yyval.intval = KW_RANDOM;}
break;
case 66:
#line 424 "qgen.y"
	{yyval.intval = KW_DIST;}
break;
case 67:
#line 425 "qgen.y"
	{yyval.intval = KW_DISTMEMBER;}
break;
case 68:
#line 426 "qgen.y"
	{yyval.intval = KW_DISTWEIGHT;}
break;
case 69:
#line 429 "qgen.y"
	{yyval.intval = KW_UNIFORM;}
break;
case 70:
#line 430 "qgen.y"
	{yyval.intval = KW_SALES;}
break;
case 71:
#line 431 "qgen.y"
	{yyval.intval = KW_RETURNS;}
break;
case 72:
#line 434 "qgen.y"
	{yyval.intval = KW_QUERY;}
break;
case 73:
#line 435 "qgen.y"
	{yyval.intval = KW_TEMPLATE;}
break;
case 74:
#line 436 "qgen.y"
	{yyval.intval = KW_STREAM;}
break;
case 75:
#line 437 "qgen.y"
	{yyval.intval = KW_SEED;}
break;
case 76:
#line 441 "qgen.y"
	{
						yyval.list = makeList(L_FL_TAIL, NULL);
						addList(yyval.list, yystack.l_mark[0].exprval);
						}
break;
case 77:
#line 446 "qgen.y"
	{
						addList(yyval.list, yystack.l_mark[0].exprval);
						yyval.list = yystack.l_mark[-2].list;
						}
break;
case 78:
#line 453 "qgen.y"
	{
						yyval.exprval = MakeReplacement(yystack.l_mark[-3].strval, yystack.l_mark[-1].intval);
						}
break;
case 79:
#line 466 "qgen.y"
	{
							pSegment = getTail(pCurrentQuery->SegmentList);
							pSegment->flags |= QS_EOS;
							}
break;
case 81:
#line 475 "qgen.y"
	{
							if ((nRetCode = AddQuerySegment(pCurrentQuery, yystack.l_mark[0].strval)) != 0)
								yyerror("SQL parse failed");
							}
break;
case 83:
#line 482 "qgen.y"
	{
							if ((nRetCode = AddQuerySegment(pCurrentQuery, yystack.l_mark[0].strval)) != 0)
								yyerror("SQL parse failed");
							}
break;
case 84:
#line 489 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, yystack.l_mark[-2].strval, 0, yystack.l_mark[-1].intval)) < 0)
								{
								sprintf(tmpstr, "Substitution match failed on %s", yystack.l_mark[-2].strval);
								yyerror(tmpstr);
								}
						}
break;
case 85:
#line 497 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, yystack.l_mark[-3].strval, yystack.l_mark[-2].intval, yystack.l_mark[-1].intval)) < 0)
								{
								sprintf(tmpstr, "Substitution match failed on %s", yystack.l_mark[-3].strval);
								yyerror(tmpstr);
								}
						}
break;
case 86:
#line 505 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_QUERY", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
break;
case 87:
#line 512 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_STREAM", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
break;
case 88:
#line 519 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_TEMPLATE", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
break;
case 89:
#line 526 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_SEED", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
break;
case 90:
#line 533 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_LIMITA", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
break;
case 91:
#line 540 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_LIMITB", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
break;
case 92:
#line 547 "qgen.y"
	{
							if ((nRetCode = AddQuerySubstitution(pCurrentQuery, "_LIMITC", 0, 0)) < 0)
								{
								yyerror("Lookup of predefined constant failed");
								}
						}
break;
case 93:
#line 555 "qgen.y"
	{yyval.intval = 0;}
break;
case 94:
#line 556 "qgen.y"
	{yyval.intval = 0;}
break;
case 95:
#line 557 "qgen.y"
	{yyval.intval = 1;}
break;
case 96:
#line 558 "qgen.y"
	{yyval.intval = yystack.l_mark[0].intval;}
break;
case 97:
#line 566 "qgen.y"
	{ yyval.strval = yystack.l_mark[0].strval; }
break;
#line 1175 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
