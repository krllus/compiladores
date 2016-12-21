#ifndef _nodes_
#define _nodes_

#include <stdlib.h>
#include "tipos.h"

typedef struct _Node{
    NodeType nodeType;

	char * lexemaStr;
    int    lexemaInt;
	
    struct _Node * data1;
    struct _Node * data2;
    struct _Node * data3;
    struct _Node * data4;
} Node;

Node * createNode(NodeType nodeType){
    Node * aux = (Node*) malloc(sizeof(Node));

    if(aux){
        aux->nodeType = nodeType;

        aux->data1 = NULL;
        aux->data2 = NULL;
        aux->data3 = NULL;
        aux->data4 = NULL;

        return aux;
    }

    return NULL;
}

#endif