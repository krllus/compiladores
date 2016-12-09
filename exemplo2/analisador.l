/**
 * Hugo de Almeida Ribeiro
**/

DIGITO		[0-9]
ID		[_a-zA-Z][_a-zA-Z0-9]*

%{
    #include "sintatico.hpp"
    
    using namespace std;
    int lineno = 1;

    extern void yyerror(const char* s);

    void lineno_inc(){
        lineno++;
    }
%}

%%

\"				{
					register int at;
					char *cadeiacar = NULL;
					int count = 1;
					for ( ; ; ){
						while ((at = yyinput()) != '\"' && at != '\n' && at != EOF ){
							count++;
							cadeiacar = (char*)realloc(cadeiacar, count * sizeof(char));
							if(cadeiacar == NULL){
								printf("FALHA AO ALOCAR MEMÓRIA PARA CADEIACAR!");
								exit(-3);
							}
							cadeiacar[count-2] = at;
						}

						if (at == '\"'){
							cadeiacar[count-1] = '\0';
							yylval.str = cadeiacar;
							return(CADEIACAR);
						}

						if(at == '\n'){
							free(cadeiacar);
							yyerror("CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA");
							break;
						}

						if (at == EOF){
							free(cadeiacar);
							yyerror("CADEIA DE CARACTERES NÃO TERMINA");
							break;
						}
					}
				}
			

"/*"				{
					register int c;
					for ( ; ; ){
						while ( (c = yyinput()) != '*' && c != EOF );

						if ( c == '*' ){
							while ( (c = yyinput()) == '*' );

							if ( c == '/' )
								break;
						}

						if ( c == EOF ){
							yyerror("COMENTÁRIO NÃO TERMINA");
							break;
						}
					}
				}

"car"				{return(CAR);}
"e"				{return(E_OP);}
"enquanto"			{return(ENQUANTO);}
"entao"				{return(ENTAO);}
"escreva"			{return(ESCREVA);}
"execute"			{return(EXECUTE);}
"int"				{return(INT);}
"leia"				{return(LEIA);}
"novalinha"			{return(NOVALINHA);}
"programa"			{return(PROGRAMA);}
"retorne"			{return(RETORNE);}
"se"				{return(SE);}
"senao"				{return(SENAO);}
"ou"				{return(OU_OP);}

['].[']				{
					yylval.str = strdup(yytext);
					return(CARCONST);
				}

{DIGITO}+		   	{
					yylval.str = strdup(yytext);
					return(INTCONST);
				}

{ID}+				{
					yylval.str = strdup(yytext);
					return(ID);
				}

"<="				{return(LE_OP);}
">="				{return(GE_OP);}
"=="				{return(EQ_OP);}
"!="				{return(NE_OP);}
";"				{return(';');}
"{"				{return('{');}
"}"				{return('}');}
","				{return(',');}
":"				{return(':');}
"="				{return('=');}
"("				{return('(');}
")"				{return(')');}
"["				{return('[');}
"]"				{return(']');}
"!"				{return('!');}
"-"				{return('-');}
"+"				{return('+');}
"*"				{return('*');}
"/"				{return('/');}
"%"				{return('%');}
"<"				{return('<');}
">"				{return('>');}
"?"				{return('?');}

\n				{lineno_inc();}

[ \t\v\f]

.				{yyerror("CARACTERE INVÁLIDO");}

%%

int yywrap(){
	return 1;
}