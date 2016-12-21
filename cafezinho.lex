%{
/* CODE BLOCK */
#include <stdio.h>
#include "sintatico.hpp"

char ERROR_INVALID_CHARACTER [] = "CARACTERE INVALIDO";
char ERROR_NOT_ENDING_COMMENT []= "COMENTARIO NAO TERMINA";
char ERROR_MULTILINE_STRING []	= "CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA";

int yylex(void);
void yyerror (char const *s);

// MAX_STR_CONST = 2048
char string_buf[2048];
char *string_buf_ptr;

%}
/* DEFINITIONS SECTION */

DIGIT	[0-9]
CHAR 	[a-zA-Z]
ID 	  	[_a-zA-Z][_a-zA-Z0-9]*
L		[a-zA-Z_]

/* create new states */
%s IN_COMMENT
%s IN_STRING

/* allow use the yyline variable as line counter */
%option yylineno

%%	/* RULES SECTION */
	/* State that represent the comments in the code */
<IN_COMMENT>{
	"*"+"/"			{ BEGIN(INITIAL); }
	[^*\n]*			{ /* eat anything that's not a '*' */ }
	"*"+[^*/\n]*	{ /* eat up '*'s not followed by '/'s */ }
	\n 				{ /* consume new line */ }
	<<EOF>>			{ yyerror(ERROR_NOT_ENDING_COMMENT); }
}
	/**
	 * http://flex.sourceforge.net/manual/Start-Conditions.html
	 */
<IN_STRING>{
	\"		{ 	
		/* saw closing quote - all done */
	    BEGIN(INITIAL);		   
	    *string_buf_ptr = '\0';
	    
	    yylval.sval = (char*) malloc (strlen(yytext)+1);
		strcpy(yylval.sval, yytext);
	    
	    return (CADEIACAR);
	    /* return string constant token type and value to parser */
		}
	
	\n 		{
		/* error - unterminated string constant */
		yyerror(ERROR_MULTILINE_STRING);
		}   	             	

	\\n  *string_buf_ptr++ = '\n';
	\\t  *string_buf_ptr++ = '\t';
    \\r  *string_buf_ptr++ = '\r';
	\\b  *string_buf_ptr++ = '\b';
	\\f  *string_buf_ptr++ = '\f';

	\\(.|\n)  *string_buf_ptr++ = yytext[1];
	[^\\\n\"]+	{
		char *yptr = yytext;
		while( *yptr) { *string_buf_ptr++ = *yptr++; }
		}
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

	['].[']		{ 
		yylval.sval = (char*) malloc (strlen(yytext)+1);
		strcpy(yylval.sval, yytext);

		return(CARCONST);
	}	
	\"			{ string_buf_ptr = string_buf; BEGIN(IN_STRING); }
	/**
	 * c string_literal:
	 * http://www.lysator.liu.se/c/ANSI-C-grammar-l.html
	 * http://www.lysator.liu.se/c/ANSI-C-grammar-y.html
	 * L?\"(\\.|[^\\"])*\"	{ return(CADEIACAR); }
	 */

	{DIGIT}+   	{
		yylval.sval = (char*) malloc (strlen(yytext)+1);
		strcpy(yylval.sval, yytext);

		return(INTCONST);
	}
	{ID}+		{ 
		yylval.sval = (char*) malloc (strlen(yytext)+1);
		strcpy(yylval.sval, yytext);
		
		return(ID);
	}

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
