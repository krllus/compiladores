DIGIT	[0-9]
CHAR 	[a-zA-Z]
ID 	  	[_a-zA-Z][_a-zA-Z0-9]*

%{
/* CODE BLOCK */
#include <stdio.h>

char ERROR_INVALID_CHARACTER [] = "CARACTERE INVALIDO";
char ERROR_NOT_ENDING_COMMENT []= "COMENTARIO NAO TERMINA";
char ERROR_MULTILINE_COMMENT []	= "CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA";

int chars = 0;
int words = 0;
int lines = 0;

void yyerror (char const *s);
void print (char const *s);

%}
/* DEFINITIONS SECTION */

/* create a new state */
%s IN_COMMENT	

/* allow use the yyline variable as line counter */
%option yylineno	

%%
	/* RULES SECTION */

	/* State that represent the comments in the code */
<IN_COMMENT>{
	"*/"      	BEGIN(INITIAL);
    [^*\n]+   	// eat comment in chunks
    "*"       	// eat the lone star
    \n 			{yyerror(ERROR_MULTILINE_COMMENT); }
}

	/* Initial state, already defined by default */
<INITIAL>{

	/* handle comments in the language */
	"/*"		BEGIN(IN_COMMENT);

	/* reserved words in the language */
	"car"			{ print("CARACTERE");}
	"enquanto"		{ print("ENQUANTO");}
	"entao"			{ print("ENTAO");}
	"escreva"		{ print("ESCREVA");}
	"execute"		{ print("EXECUTE");}
	"int"			{ print("INTEIRO");}
	"leia"			{ print("LEIA");}
	"novalinha"		{ print("NOVALINHA");}
	"programa"		{ print("PROGRAMA");}
	"retorne"		{ print("RETORNE");}
	"se"			{ print("SE");}
	"senao"			{ print("SENAO");}
	"ou"			{ print("OU");}

	{CHAR}+			{ words++; chars += strlen(yytext); }	
	{DIGIT}+		{ print("DIGIT");}
	{ID}+ 			{ print("ID");}

	\n 				{ lines++; }
	[ \t\v\f]		{ /* eat useless characters */}

	.				{ chars++; yyerror(ERROR_INVALID_CHARACTER);}
}

%%

int yywrap(){
	return 1;
}

void yyerror (char const *s) {
	fprintf (stderr, "ERROR: %s, Line[%d]\n", s,yylineno);
}

void print (char const *s){
	printf("%s\n", s);
}

/*
 * main, created just for test purposes
 */
main(int argc, char **argv){
	yylex();
	printf("linhas: %8d\npalavras: %8d\ncaracteres: %8d\n", lines, words, chars);
}