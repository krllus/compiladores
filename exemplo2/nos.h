/**
 * Hugo de Almeida Ribeiro
**/

#ifndef __NOS__
#define __NOS__

#include "tipos.h"
#include <iostream>

using namespace std;

class No;
class NoUnario;
class NoBinario;
class NoTerciario;
class NoQuartenario;
class NoExprUnaria;
class NoExprBinaria;
class NoFolha;
void imprime_nos(No*);
void chop(No*);

class No{
public:
	No(tipoNo tipo) : tipo(tipo){};
	tipoNo tipo;

	virtual ~No(){};
	
	tipoNo getTipo(){
		return tipo;
	}
};

class NoUnario : public No{
public:
	NoUnario(tipoNo tipo, No* f1) : No(tipo), f1(f1){};
	No* f1;

	virtual ~NoUnario(){};
};

class NoBinario : public NoUnario{
public:
	NoBinario(tipoNo tipo, No* f1, No* f2) : NoUnario(tipo,f1), f2(f2){};
	No* f2;

	virtual ~NoBinario(){};
};

class NoTernario : public NoBinario{
public:
	NoTernario(tipoNo tipo, No* f1, No* f2, No* f3) : NoBinario(tipo, f1, f2), f3(f3){};
	No* f3;

	virtual ~NoTernario(){};
};

class NoQuartenario : public NoTernario{
public:
	NoQuartenario(tipoNo tipo, No* f1, No* f2, No* f3, No* f4) : NoTernario(tipo, f1, f2, f3), f4(f4){};
	No* f4;

	virtual ~NoQuartenario(){};
};

class NoExprUnaria : public NoUnario{
public:
	NoExprUnaria(tipoOpr operador, No* f1) : NoUnario(NO_EXPR_UNARIA, f1), operador(operador){};
	int operador;

	virtual ~NoExprUnaria(){};
};

class NoExprBinaria : public NoBinario{
public:
	NoExprBinaria(tipoOpr operador, No* f1, No* f2) : NoBinario(NO_EXPR_BINARIA, f1, f2), operador(operador){};
	int operador;

	virtual ~NoExprBinaria(){};
};

class NoFolha : public No{
public:
	NoFolha(tipoNo tipo, string terminal) : No(tipo), terminal(terminal){};
	string terminal;

	virtual ~NoFolha(){};
};

#endif