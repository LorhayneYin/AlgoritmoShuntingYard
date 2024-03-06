
//
// Created by Lorhayne on 01/03/2024.
//
#include <stdbool.h>
#include <stdlib.h>
#include "pilha.h"

char pilhaOp[TAMANHO_PILHAOP];
double pilhaVal[TAMANHO_PILHAVAL];

int posicaoOp = 0;
int posicaoVal = 0;

bool pushOp(char op)
{
    if(estaCheiaOp())
    {
        return false;
    }
    pilhaOp[posicaoOp] = op;
    posicaoOp++;

    return true;
}

bool popOp(char *op)
{
    if(estaVaziaOp())
    {
        return false;
    }
    posicaoOp--;
    *op = pilhaOp[posicaoOp];
    return true;
}

bool pushVal(double val)
{
    if(estaCheiaVal())
    {
        return false;
    }
    pilhaVal[posicaoVal] = val;
    posicaoVal++;

    return true;
}


bool popVal(double *val)
{
    if(estaVaziaVal())
    {
        return false;
    }
    posicaoVal--;
    *val = pilhaVal[posicaoVal];
    return true;
}

bool estaCheiaOp()
{
    return posicaoOp == TAMANHO_PILHAOP;
}

bool estaCheiaVal()
{
    return posicaoVal == TAMANHO_PILHAVAL;
}

bool estaVaziaOp()
{
    return posicaoOp == 0;
}

bool estaVaziaVal()
{
    return posicaoVal == 0;
}

char topoPilhaOp() {
    return pilhaOp[posicaoOp-1];
}

double topoPilhaVal() {
    return pilhaVal[posicaoVal-1];
}