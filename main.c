#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pilha.h"

//Define a partir de dois parâmetros qual operador tem maior precedência
bool mesmaOuMaiorPrecedencia(char op1, char op2) {
    if (op2 == '(' || op2 == ')') {
        return false;
    }
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) {
        return false;
    } else {
        return true;
    }
}
// função que verifica se o valor de letra é um dos caracteres presentes no vetor
bool find(char letra, char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == letra) {
            return true;
        }
    }
    return false;
}
//preenche vetor principal e limpa caracteres indesejados
void stringParaVetor(char *line, char vec[][20], int tamanho)
{
    char trab[tamanho];
    char operacoes[] = "+-*/()";
    char letra;
    bool numero = false;
    bool str = false;
    int vecI = 0;
    int aux = 0;
    strcpy(trab, "");

    for(int i = 0; i < tamanho; i++)
    {
        letra = line[i];
        if((isdigit(letra) || letra=='.')  && !str)
        {
            if(!numero)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                }
                numero = true;
                str = false;
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
        }
        else if(letra == ' ')
        {
            if(!str)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                    numero = false;
                    str = false;
                }
            }
        }
        else if(find(letra, operacoes) != 0)
        {
            if(strlen(trab)!=0)
            {
                strcpy(vec[vecI++],trab);
                strcpy(trab, "");
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
            strcpy(vec[vecI++],trab);
            strcpy(trab, "");
            numero = false;
            str = false;
        }
    }
    if(strlen(trab)!=0)
    {
        strcpy(vec[vecI++],trab);
    }
}
//Um looping para preencher as linhas do vetor com \0
void limpaVetor(char v[][20], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        strcpy(v[i], "");
    }
}

double calcular(double num1, double num2, char operacao) {
    switch(operacao) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

int main() {
    char exp[100] = "";
    char vec[100][20] = {'\0'};
    limpaVetor(vec, 100);
    strcpy(exp, "((22 + 5) * 2) / 3");
    stringParaVetor(exp, vec, 100);

    // Início do meu código
    char operador;
    double num1;
    double num2;
    double resultado;
//Separa os itens nas pilhas operadores e valores
    for (int i = 0; i < 100 && strcmp(vec[i], "") != 0; i++) {
        if (isdigit(vec[i][0]) || vec[i][0] == '.') {
            pushVal(atof(vec[i]));
        } else {
            for (int j = 0; vec[i][j] != '\0'; j++) {
                if (vec[i][j] != ')') {
                    pushOp(vec[i][j]);
                } else {
                    //Aqui ele faz os cálculos se encontrar um fecha parênteses
                    while (topoPilhaOp() != '(' && mesmaOuMaiorPrecedencia(vec[i][j], topoPilhaOp())) {
                        num1 = topoPilhaVal();
                        popVal(&num1);
                        num2 = topoPilhaVal();
                        popVal(&num2);

                        operador = topoPilhaOp();
                        popOp(&operador);

                        resultado = calcular(num2, num1, operador);
                        pushVal(resultado);
                    }
                   //Removendo o abre parenteses da pilha depois dos calculos
                    char abreParenteses = topoPilhaOp();
                    popOp(&abreParenteses);
                }
            }
        }
    }
//Garanta que o último cálculo seja feito até zerar a pilha de operador
    while (!estaVaziaOp()) {
        num1 = topoPilhaVal();
        popVal(&num1);
        num2 = topoPilhaVal();
        popVal(&num2);

        operador = topoPilhaOp();
        popOp(&operador);

        resultado = calcular(num2, num1, operador);
        pushVal(resultado);
    }

    printf("Resultado: %.2f\n", topoPilhaVal());

    return 0;
}
