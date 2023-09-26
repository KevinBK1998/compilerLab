/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
