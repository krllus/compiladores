%{
/* CODE BLOCK */
#include <stdio.h>
#include "sintatico.hpp"

char ERROR_INVALID_CHARACTER [] = "CARACTERE INVALIDO";
char ERROR_NOT_ENDING_COMMENT []= "COMENTARIO NAO TERMINA";
char ERROR_MULTILINE_COMMENT []	= "CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA";

int yylex(void);
void yyerror (char const *s);

%}
/* DEFINITIONS SECTION */

DIGIT	[0-9]
CHAR 	[a-zA-Z]
ID 	  	[_a-zA-Z][_a-zA-Z0-9]*

/* create a new state */
%s IN_COMMENT	

/* allow use the yyline variable as line counter */
%option yylineno

%%
	/* RULES SECTION */

	/* State that represent the comments in the code */
<IN_COMMENT>{
	"*/"      	{ BEGIN(INITIAL);}
    [^*\n]+   	{ /* eat comment in chunks */ }
    "*"       	{ /* eat the lone star */ }
    \n 			{ yyerror(ERROR_MULTILINE_COMMENT); }
}

	/* Initial state, already defined by default */
<INITIAL>{

	/* handle comments in the language */
	"/*"		{ BEGIN(IN_COMMENT); }
	"//".* 		{ /* ignore comments */ }

	/* reserved words in the language */
	"car"		{ return(CAR);}
	"e"			{ return(E_OP);}
	"enquanto"	{ return(ENQUANTO);}
	"entao"		{ return(ENTAO);}
	"escreva"	{ return(ESCREVA);}
	"execute"	{ return(EXECUTE);}
	"int"		{ return(INT);}
	"leia"		{ return(LEIA);}
	"novalinha"	{ return(NOVALINHA);}
	"programa"	{ return(PROGRAMA);}
	"retorne"	{ return(RETORNE);}
	"se"		{ return(SE);}
	"senao"		{ return(SENAO);}
	"ou"		{ return(OU_OP);}

	['].[']		{ return(CARCONST);}
	["].*["]	{ return(CADEIACAR);}
	{DIGIT}+   	{ return(INTCONST);}
	{ID}+		{ return(ID);}

	"<="		{ return(LE_OP);}
	">="		{ return(GE_OP);}
	"=="		{ return(EQ_OP);}
	"!="		{ return(NE_OP);}
	";"			{ return(';');}
	"{"			{ return('{');}
	"}"			{ return('}');}
	","			{ return(',');}
	":"			{ return(':');}
	"="			{ return('=');}
	"("			{ return('(');}
	")"			{ return(')');}
	"["			{ return('[');}
	"]"			{ return(']');}
	"!"			{ return('!');}
	"-"			{ return('-');}
	"+"			{ return('+');}
	"*"			{ return('*');}
	"/"			{ return('/');}
	"%"			{ return('%');}
	"<"			{ return('<');}
	">"			{ return('>');}
	"?"			{ return('?');}

	\n 			{ /* consume new line */ } 			
	[ \t\v\f]	{ /* eat useless characters */ }

	.			{ yyerror(ERROR_INVALID_CHARACTER); }
}

%%

int yywrap(){
	return 1;
}