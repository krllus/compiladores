/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTCONST = 258,
     ID = 259,
     CARCONST = 260,
     CADEIACAR = 261,
     PROGRAMA = 262,
     RETORNE = 263,
     INT = 264,
     CAR = 265,
     LEIA = 266,
     ESCREVA = 267,
     SE = 268,
     ENTAO = 269,
     SENAO = 270,
     ENQUANTO = 271,
     OU_OP = 272,
     E_OP = 273,
     EQ_OP = 274,
     NE_OP = 275,
     GE_OP = 276,
     LE_OP = 277,
     NOVALINHA = 278,
     EXECUTE = 279
   };
#endif
/* Tokens.  */
#define INTCONST 258
#define ID 259
#define CARCONST 260
#define CADEIACAR 261
#define PROGRAMA 262
#define RETORNE 263
#define INT 264
#define CAR 265
#define LEIA 266
#define ESCREVA 267
#define SE 268
#define ENTAO 269
#define SENAO 270
#define ENQUANTO 271
#define OU_OP 272
#define E_OP 273
#define EQ_OP 274
#define NE_OP 275
#define GE_OP 276
#define LE_OP 277
#define NOVALINHA 278
#define EXECUTE 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "cafezinho.yac"
{
    int integer;
    Node * node;
    char * str;
}
/* Line 1529 of yacc.c.  */
#line 103 "sintatico.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

