/**
 * Hugo de Almeida Ribeiro
**/

#include "nos.h"
#include "tipos.h"

using namespace std;

string resolve_tipo(int);
string resolve_operador(int);

void imprime_nos(No* no){
	cout << "( ";
	if(no){
		cout << resolve_tipo(no->getTipo()) << " ";
		switch(no->getTipo()){
			/** NoUnario**/
			case NO_DECLPROGRAMA:
			case NO_VETORPARAMS:
			case NO_RETORNO:
			case NO_LEIA:
			case NO_ESCREVA:
				imprime_nos(((NoUnario*)no)->f1);
				break;

			/** NoBinario **/
			case NO_PROGRAMA:
			case NO_DECLVETOR:
			case NO_DECLVAR:
			case NO_DECLFUNC:
			case NO_BLOCO:
			case NO_LISTACOMANDOS:
			case NO_SEENTAO:
			case NO_ENQUANTO:
			case NO_VETOR:
			case NO_FUNCAO:
			case NO_LISTAEXPR:
			    imprime_nos(((NoBinario*)no)->f1);
			    imprime_nos(((NoBinario*)no)->f2);
			    break;
			
			/** NoTernario **/
			case NO_LISTAPARAMS:
			case NO_SEENTAOSENAO:
				imprime_nos(((NoTernario*)no)->f1);
				imprime_nos(((NoTernario*)no)->f2);
				imprime_nos(((NoTernario*)no)->f3);
				break;
			
			/** NoQuartenario **/
			case NO_LISTADECLVAR:
			case NO_DECLFUNCVAR:
				imprime_nos(((NoQuartenario*)no)->f1);
				imprime_nos(((NoQuartenario*)no)->f2);
				imprime_nos(((NoQuartenario*)no)->f3);
				imprime_nos(((NoQuartenario*)no)->f4);
				break;

			/** NoExprUnaria **/
			case NO_EXPR_UNARIA:
				cout << resolve_operador(((NoExprUnaria*)no)->operador);
				imprime_nos(((NoExprUnaria*)no)->f1);
				break;

			/** NoExprBinaria **/
			case NO_EXPR_BINARIA:
				cout << resolve_operador(((NoExprBinaria*)no)->operador);
				imprime_nos(((NoExprBinaria*)no)->f1);
				imprime_nos(((NoExprBinaria*)no)->f2);
				break;

			/** NoFolha**/
			case NO_DECLID:
			case NO_INTCONST:
			case NO_CADEIACAR:
			case NO_ID:
			case NO_CARCONST:
				cout << ((NoFolha*)no)->terminal;
				break;
		}
	}
	cout << ") ";
}

void chop(No* no){
	if(no){
		switch(no->getTipo()){
			/** NoUnario**/
			case NO_DECLPROGRAMA:
			case NO_VETORPARAMS:
			case NO_RETORNO:
			case NO_LEIA:
			case NO_ESCREVA:
				chop(((NoUnario*)no)->f1);
				break;

			/** NoBinario **/
			case NO_PROGRAMA:
			case NO_DECLVETOR:
			case NO_DECLVAR:
			case NO_DECLFUNC:
			case NO_BLOCO:
			case NO_LISTACOMANDOS:
			case NO_SEENTAO:
			case NO_ENQUANTO:
			case NO_VETOR:
			case NO_FUNCAO:
			case NO_LISTAEXPR:
			    chop(((NoBinario*)no)->f1);
			    chop(((NoBinario*)no)->f2);
			    break;
			
			/** NoTernario **/
			case NO_LISTAPARAMS:
			case NO_SEENTAOSENAO:
				chop(((NoTernario*)no)->f1);
				chop(((NoTernario*)no)->f2);
				chop(((NoTernario*)no)->f3);
				break;
			
			/** NoQuartenario **/
			case NO_LISTADECLVAR:
			case NO_DECLFUNCVAR:
				chop(((NoQuartenario*)no)->f1);
				chop(((NoQuartenario*)no)->f2);
				chop(((NoQuartenario*)no)->f3);
				chop(((NoQuartenario*)no)->f4);
				break;

			/** NoExprUnaria **/
			case NO_EXPR_UNARIA:
				chop(((NoExprUnaria*)no)->f1);
				break;

			/** NoExprBinaria **/
			case NO_EXPR_BINARIA:
				chop(((NoExprBinaria*)no)->f1);
				chop(((NoExprBinaria*)no)->f2);
				break;

			/** NoFolha**/
			case NO_DECLID:
			case NO_INTCONST:
			case NO_CADEIACAR:
			case NO_ID:
			case NO_CARCONST:
				/** NOTHING TO DO HERE! **/
				break;
		}
		delete(no);
	}
}

string resolve_tipo(int tipo){
	string tipoStr;
	switch(tipo){
		case NO_PROGRAMA:
			tipoStr = "NO_PROGRAMA";
			break;
		case NO_DECLPROGRAMA:
			tipoStr = "NO_DECLPROGRAMA";
			break;
		case NO_DECLFUNCVAR:
			tipoStr = "NO_DECLFUNCVAR";
			break;
		case NO_DECLFUNC:
			tipoStr = "NO_DECLFUNC";
			break;
		case NO_DECLVAR:
			tipoStr = "NO_DECLVAR";
			break;
		case NO_LISTACOMANDOS:
			tipoStr = "NO_LISTACOMANDOS";
			break;
		case NO_LISTADECLVAR:
			tipoStr = "NO_LISTADECLVAR";
			break;
		case NO_LISTAPARAMS:
			tipoStr = "NO_LISTAPARAMS";
			break;
		case NO_BLOCO:
			tipoStr = "NO_BLOCO";
			break;
		case NO_FUNCAO:
			tipoStr = "NO_FUNCAO";
			break;
		case NO_VETORPARAMS:
			tipoStr = "NO_VETORPARAMS";
			break;
		case NO_SEENTAO:
			tipoStr = "NO_SEENTAO";
			break;
		case NO_SEENTAOSENAO:
			tipoStr = "NO_SEENTAOSENAO";
			break;
		case NO_ENQUANTO:
			tipoStr = "NO_ENQUANTO";
			break;
		case NO_RETORNO:
			tipoStr = "NO_RETORNO";
			break;
		case NO_ESCREVA:
			tipoStr = "NO_ESCREVA";
			break;
		case NO_LEIA:
			tipoStr = "NO_LEIA";
			break;
		case NO_COMANDOVAZIO:
			tipoStr = "NO_COMANDOVAZIO";
			break;
		case NO_NOVALINHA:
			tipoStr = "NO_NOVALINHA";
			break;
		case NO_LISTAEXPR:
			tipoStr = "NO_LISTAEXPR";
			break;
		case NO_EXPR_UNARIA:
			tipoStr = "NO_EXPR_UNARIA : operador =";
			break;
		case NO_EXPR_BINARIA:
			tipoStr = "NO_EXPR_BINARIA : operador = ";
			break;
		case NO_TIPO_CAR:
			tipoStr = "NO_TIPO_CAR";
			break;
		case NO_TIPO_INT:
			tipoStr = "NO_TIPO_INT";
			break;
		case NO_DECLID:
			tipoStr = "NO_DECLID";
			break;
		case NO_DECLVETOR:
			tipoStr = "NO_DECLVETOR";
			break;
		case NO_ID:
			tipoStr = "NO_ID";
			break;
		case NO_VETOR:
			tipoStr = "NO_VETOR";
			break;
		case NO_INTCONST:
			tipoStr = "NO_INTCONST : valor =";
			break;
		case NO_CARCONST:
			tipoStr = "NO_CARCONST : valor =";
			break;
		case NO_CADEIACAR:
			tipoStr = "NO_CADEIACAR : valor =";
			break;
	}
	return tipoStr;
}

string resolve_operador(int tipo){
	string operador;
	switch(tipo){
		case OP_MAIS:
			operador = "+";
			break;
		case OP_MENOS:
		case OP_NEG:
			operador = "-";
			break;
  		case OP_MULT:
  			operador = "*";
  			break;
		case OP_DIV:
			operador = "/";
			break;
		case OP_ASSIGN:
			operador = "=";
			break;
		case OP_EQ:
			operador = "==";
			break;
		case OP_DIFF:
			operador = "!=";
			break;
		case OP_MENOR:
			operador = "<";
			break;
		case OP_MAIOR:
			operador = ">";
			break;
		case OP_LEQ:
			operador = "<=";
			break;
		case OP_GEQ:
			operador = ">=";
			break;
		case OP_MOD:
			operador = "%%";
			break;
		case OP_OU:
			operador = " ou ";
			break;
		case OP_E:
			operador = " e ";
			break;
		case OP_NAO:
			operador = "!";
			break;
	}
	return operador+" ";
}