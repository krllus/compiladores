#ifndef _tipos_
#define _tipos_

typedef enum{
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

	OP_MAIS, 	// +
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
} NodeType;
/*
typedef enum {
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
*/

#endif