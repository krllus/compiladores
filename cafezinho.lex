%{
	int chars = 0;
	int words = 0;
	int lines = 0;
%}

%%

"/*"                                    { comment(); }
"//".*                                    { /* consume //-comment */ }

[a-zA-Z]+  { words++; chars += strlen(yytext); }
\n         { chars++; lines++; }
.          { chars++; }

%%

int yywrap(){
	return 1;
}

// codigo que trata de comentarios
static void comment(void){
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}

// main, apenas para testes
main(int argc, char **argv){
	yylex();
	printf("linhas: %8d\n palavras: %8d\ncaracteres: %8d\n", lines, words, chars);
}

