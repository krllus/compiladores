%{

#include <stdio.h>

int chars = 0;
int words = 0;
int lines = 0;

void yyerror (char const *s);

%}

%s IN_COMMENT

%%

<IN_COMMENT>{
	"*/"      	BEGIN(INITIAL);
    [^*\n]+   	// eat comment in chunks
    "*"       	// eat the lone star
    \n 			yylineno++;
}

<INITIAL>{

	"/*"		BEGIN(IN_COMMENT);
		
	[a-zA-Z]+	{ words++; chars += strlen(yytext); }
	\n 			{ chars++; lines++; }
	.			{ chars++; }	
}


%%

int yywrap(){
	return 1;
}

void yyerror (char const *s) {
	fprintf (stderr, "%s\n", s);
}


// main, apenas para testes
main(int argc, char **argv){
	yylex();
	printf("linhas: %8d\npalavras: %8d\ncaracteres: %8d\n", lines, words, chars);
}

