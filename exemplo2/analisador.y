/**
 * Hugo de Almeida Ribeiro
**/

%code requires{
    #include "arvre/nos.h"
    #include "arvre/tipos.h"
}

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "arvre/nos.h"
    #include "arvre/tipos.h"

    using namespace std;

    extern int lineno;
    extern FILE* yyin;
    extern int yylex(void);

    int error = 0;
    void yyerror(const char* s);

    No* raiz;
%}

%union{
    int inteiro;
    char* str;
    No* no;
};

%token <inteiro> INTCONST
%token <str> CARCONST
%token <str> CADEIACAR
%token <str> ID
%token INT CAR
%token PROGRAMA RETORNE LEIA ESCREVA
%token NOVALINHA SE ENTAO SENAO OU_OP E_OP
%token EQ_OP NE_OP GE_OP LE_OP
%token ENQUANTO EXECUTE

%type <no> Programa DeclFuncVar DeclProg DeclVar DeclFunc ListaParametros ListaParametrosCont Bloco
%type <no> ListaDeclVar Tipo ListaComando Expr AssignExpr OrExpr AndExpr EqExpr
%type <no> DesigExpr AddExpr MulExpr UnExpr LValueExpr PrimExpr ListExpr
%type <no> Comando CondExpr

%%

Programa:
    DeclFuncVar DeclProg {$$ = new NoBinario(NO_PROGRAMA, $1, $2); raiz = $$; /** CHAMAR SEMANTICA AQUI**/};

DeclFuncVar:
    Tipo ID DeclVar ';' DeclFuncVar {
										No* aux = new NoFolha(NO_ID, $2);
										$$ = new NoQuartenario(NO_LISTADECLVAR, $1, aux, $3, $5);
									}|
    Tipo ID'['INTCONST']' DeclVar ';' DeclFuncVar {
							No* aux1 = new NoFolha(NO_DECLID, $2);
							No* aux2 = new NoFolha(NO_INTCONST, to_string($4));
							No* aux3 = new NoBinario(NO_DECLVETOR, aux1, aux2);
							$$ = new NoQuartenario(NO_LISTADECLVAR, $1, aux3, $6, $8);
						}|
    Tipo ID DeclFunc DeclFuncVar {
					No* aux = new NoFolha(NO_DECLID, $2);
					$$ = new NoQuartenario(NO_DECLFUNCVAR, $1, aux, $3, $4);
				}| {$$ = NULL;};

DeclProg :
    PROGRAMA Bloco {$$ = new NoUnario(NO_DECLPROGRAMA, $2);};

DeclVar :
    ',' ID DeclVar {
			No* aux = new NoFolha(NO_DECLID, $2);
			$$ = new NoBinario(NO_DECLVAR, aux, $3);
		}|
    ',' ID'['INTCONST']' DeclVar {
					No* aux1 = new NoFolha(NO_DECLID, $2);
					No* aux2 = new NoFolha(NO_INTCONST, to_string($4));
					No* aux3 = new NoBinario(NO_DECLVETOR, aux1, aux2);
					$$ = new NoBinario(NO_DECLVAR, aux3, $6);
				}| 
	{$$ = NULL;};

DeclFunc :
    '('ListaParametros')' Bloco {$$ = new NoBinario(NO_DECLFUNC, $2, $4);};

ListaParametros :
    ListaParametrosCont {$$ = $1;}|
	{$$ = NULL;} ;

ListaParametrosCont :
    Tipo ID {
		No* aux = new NoFolha(NO_DECLID, $2);
		$$ = new NoTernario(NO_LISTAPARAMS, $1, aux, NULL);
	}|
    Tipo ID'['']' {
			No* aux1 = new NoFolha(NO_DECLID, $2);
			No* aux2 = new NoUnario(NO_VETORPARAMS, aux1);
			$$ = new NoTernario(NO_LISTAPARAMS, $1, aux2 , NULL);
		}|
    Tipo ID ',' ListaParametrosCont {
					No* aux = new NoFolha(NO_DECLID, $2);
					$$ = new NoTernario(NO_LISTAPARAMS, $1, aux, $4);
				}|
    Tipo ID'['']' ',' ListaParametrosCont {
						No* aux1 = new NoFolha(NO_DECLID, $2);
						No* aux2 = new NoUnario(NO_VETORPARAMS, aux1);
						$$ = new NoTernario(NO_LISTAPARAMS, $1, aux2, $6);
					};

Bloco :
    '{' ListaDeclVar ListaComando '}' {$$ = new NoBinario(NO_BLOCO, $2, $3 );}|
    '{' ListaDeclVar '}' {$$ = $2;};

ListaDeclVar:
    Tipo ID DeclVar ';' ListaDeclVar {
					No* aux = new NoFolha(NO_DECLID, $2);
					$$ = new NoQuartenario(NO_LISTADECLVAR, $1, aux, $3, $5);
					}|
    Tipo ID'['INTCONST']' DeclVar ';' ListaDeclVar {
							No* aux1 = new NoFolha(NO_DECLID, $2);
							No* aux2 = new NoFolha(NO_INTCONST, to_string($4));
							No* aux3 = new NoBinario(NO_DECLVETOR, aux1, aux2);
							$$ = new NoQuartenario(NO_LISTADECLVAR, $1, aux3, $6, $8);
						}|
	{$$ = NULL;} ;

Tipo :
    INT {$$ = new No(NO_TIPO_INT);}|
    CAR {$$ = new No(NO_TIPO_CAR);};

ListaComando: 
    Comando {$$ = $1;}|
    Comando ListaComando {$$ = new NoBinario(NO_LISTACOMANDOS, $1, $2);};

Comando:
    ';' {$$ = new No(NO_COMANDOVAZIO);}|
    Expr ';' {$$ = $1;}|
    RETORNE Expr ';' {$$ = new NoUnario(NO_RETORNO, $2);}|
    LEIA LValueExpr ';' {$$ = new NoUnario(NO_LEIA, $2);}|
    ESCREVA CADEIACAR ';' {
				No* aux = new NoFolha(NO_CADEIACAR, $2);
				$$ = new NoUnario(NO_ESCREVA, aux);
			}|
    ESCREVA Expr ';' {$$ = new NoUnario(NO_ESCREVA, $2);}|
    NOVALINHA {$$ = new No(NO_NOVALINHA);}|
    SE '(' Expr ')' ENTAO Comando {$$ = new NoBinario(NO_SEENTAO, $3, $6);}|
    SE '(' Expr ')' ENTAO Comando SENAO Comando {$$ = new NoTernario(NO_SEENTAOSENAO, $3, $6, $8);}|
    ENQUANTO '(' Expr ')' EXECUTE Comando {$$ = new NoBinario(NO_ENQUANTO, $3, $6);}|
    Bloco {$$ = $1;};

Expr:
    AssignExpr {$$ = $1;};

AssignExpr:
    CondExpr {$$ = $1;}|
    LValueExpr '=' AssignExpr {$$ = new NoExprBinaria(OP_ASSIGN, $1, $3);};

CondExpr:
    OrExpr {$$ = $1;}|
    OrExpr '?' Expr ':' CondExpr {$$ = new NoTernario(NO_SEENTAOSENAO, $1, $3, $5);};

OrExpr:
    OrExpr OU_OP AndExpr {$$ = new NoExprBinaria(OP_OU, $1, $3);}|
    AndExpr {$$ = $1;};

AndExpr:
    AndExpr E_OP EqExpr {$$ = new NoExprBinaria(OP_E, $1, $3);}|
    EqExpr {$$ = $1;};

EqExpr:
    EqExpr EQ_OP DesigExpr {$$ = new NoExprBinaria(OP_EQ, $1, $3);}|
    EqExpr NE_OP DesigExpr {$$ = new NoExprBinaria(OP_DIFF, $1, $3);}|
    DesigExpr {$$ = $1;};

DesigExpr:
    DesigExpr '<' AddExpr {$$ = new NoExprBinaria(OP_MENOR, $1, $3);}|
    DesigExpr '>' AddExpr {$$ = new NoExprBinaria(OP_MAIOR, $1, $3);}|
    DesigExpr GE_OP AddExpr {$$ = new NoExprBinaria(OP_GEQ, $1, $3);}|
    DesigExpr LE_OP AddExpr {$$ = new NoExprBinaria(OP_LEQ, $1, $3);}|
    AddExpr {$$ = $1;};

AddExpr:
    AddExpr '+' MulExpr {$$ = new NoExprBinaria(OP_MAIS, $1, $3);}|
    AddExpr '-' MulExpr {$$ = new NoExprBinaria(OP_MENOS, $1, $3);}|
    MulExpr {$$ = $1;};

MulExpr:
    MulExpr '*' UnExpr {$$ = new NoExprBinaria(OP_MULT, $1, $3);}|
    MulExpr '/' UnExpr {$$ = new NoExprBinaria(OP_DIV, $1, $3);}|
    MulExpr '%' UnExpr {$$ = new NoExprBinaria(OP_MOD, $1, $3);}|
    UnExpr {$$ = $1;};

UnExpr:
    '-'PrimExpr {$$ = new NoExprUnaria(OP_NEG, $2);}|
    '!'PrimExpr {$$ = new NoExprUnaria(OP_NAO, $2);}|
    PrimExpr {$$ = $1;};

LValueExpr:
    ID'[' Expr ']'{
			No* aux = new NoFolha(NO_ID, $1);
			$$ = new NoBinario(NO_VETOR, aux, $3);
		}|
    ID {$$ = new NoFolha(NO_ID, $1);};

PrimExpr:
    ID'(' ListExpr ')' {
				No* aux = new NoFolha(NO_ID, $1);
				$$ = new NoBinario(NO_FUNCAO, aux, $3);
			}|
    ID'('')'{
		No* aux = new NoFolha(NO_ID, $1);
		$$ = new NoBinario(NO_FUNCAO, aux, NULL);
	}|
    ID'[' Expr ']' {
			No* aux = new NoFolha(NO_ID, $1);
			$$ = new NoBinario(NO_VETOR, aux, $3);
		}|
    ID {$$ = new NoFolha(NO_ID, $1);}|
    CARCONST {$$ = new NoFolha(NO_CARCONST, $1);}|
    INTCONST {$$ = new NoFolha(NO_INTCONST, to_string($1));}|
    '(' Expr ')' {$$ = $2;};

ListExpr:
    AssignExpr {$$ = $1;}|
    ListExpr ',' AssignExpr {$$ = new NoBinario(NO_LISTAEXPR, $1, $3);};

%%

main(int argc, char* argv[]) {
    if(argc > 1){
    	yyin = fopen(argv[1], "r");

        if(!yyin){
	    printf("%s: IMPOSSÍVEL ABRIR ARQUIVO %s\n", argv[0], argv[1]);
	    exit(-1);
	}
        yyparse();
	if(error){
            printf("LÉXICA OU SINTÁTICAMENTE INCORRETO\n");
	    //destroi árvore!
	}
        else{
	    printf("LÉXICA E SINTÁTICAMENTE CORRETO\n");
	    imprime_nos(raiz);
	    cout << "\n";
	    chop(raiz);
	}
   } else {
	printf("%s: SEM ARQUIVO DE ENTRADA\n", argv[0]);
	exit(-1);
    }
}

void yyerror(const char *s) {
    error = 1;
    printf("ERRO: %s NA LINHA %d\n", s, lineno);
}
