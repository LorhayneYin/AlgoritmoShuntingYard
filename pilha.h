//
// Created by Lorhayne on 01/03/2024.
//

#ifndef ALGORITMOSHUNTINGYARD_PILHA_H
#define ALGORITMOSHUNTINGYARD_PILHA_H

#endif //ALGORITMOSHUNTINGYARD_PILHA_H

enum {
    TAMANHO_PILHAOP = 10,
    TAMANHO_PILHAVAL = 10
};

extern char pilhaOp[TAMANHO_PILHAOP];
extern double pilhaVal[TAMANHO_PILHAVAL];

extern int posicaoOp;
extern int posicaoVal;

bool pushOp(char op);
bool pushVal(double val);
bool popOp(char *op);
bool popVal(double *val);
bool estaCheiaOp();
bool estaCheiaVal();
bool estaVaziaOp();
bool estaVaziaVal();
char topoPilhaOp();
double topoPilhaVal();