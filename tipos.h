#ifndef _tipos_h
#define _tipos_h

typedef enum{
	lstStmt, 
	If, While, Do, 
	Num, 
	Mais, Mult, Menor, Igual, MenorIgual} 
	TespecieOperador;

//Definicao de um no da arvore abstrata.
typedef struct operador{
    TespecieOperador tipoOperador;// for, if, id, etc
    int  linha;
    char* lexema; // utilizado apenas em nos da especie Num para armazenar o lexa do numero
    struct operador* filho1;
    struct operador* filho2;
} Toperador;

typedef enum _NodeType{
	NO_PROGRAMA,
	NO_DECLPROGRAMA,
	NO_DECLFUNCVAR,
	NO_DECLFUNC,
	NO_DECLVAR,
	NO_LISTACOMANDOS,
	NO_LISTADECLVAR,
	NO_LISTAPARAMS,
	NO_BLOCO,
	NO_FUNCAO,
	NO_VETORPARAMS,
	NO_SEENTAO,
	NO_SEENTAOSENAO,
	NO_ENQUANTO,
	NO_RETORNO,
	NO_ESCREVA,
	NO_LEIA,
	NO_COMANDOVAZIO,
	NO_NOVALINHA,
	NO_LISTAEXPR,
	NO_EXPR_UNARIA,
	NO_EXPR_BINARIA,
	NO_TIPO_CAR,
	NO_TIPO_INT,
	NO_DECLID,
	NO_DECLVETOR,
	NO_ID,
	NO_VETOR,
	NO_INTCONST,
	NO_CARCONST,
	NO_CADEIACAR,
} NodeType;

typedef enum _OperatorType{
	OP_MAIS=1, 	// +
  	OP_MENOS, 	// -
  	OP_MULT, 	// *
  	OP_DIV, 	// /
  	OP_ASSIGN, 	// =
  	OP_EQ, 		// == , [EQ]ual
  	OP_DIFF, 	// !=
  	OP_MENOR, 	// <
  	OP_MAIOR, 	// >
  	OP_LEQ, 	// <= , [L]esser or [EQ]ual
  	OP_GEQ, 	// >= , [G]reater or [EQ]ual
  	OP_MOD, 	// %
  	OP_OU, 		// ou
  	OP_E, 		// e
  	OP_NEG, 	// [NEG]ativo
  	OP_NAO, 	// !
} OperatorType;

typedef struct _Node{
	NodeType nodeType;

	struct _Node * data1;
	struct _Node * data2;
	struct _Node * data3;
	struct _Node * data4;

	char* lexema;
} Node;


#endif