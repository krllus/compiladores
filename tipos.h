// tipos.h
// adaptation from Thierson's code

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

#endif