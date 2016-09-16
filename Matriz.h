#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include "MC_VALUES.h"
#include "Output.h"
#include "TimerChrono.h"

/** \brief Classe usada para armazenar valores do tipo double em uma matriz simples, de tamanho 'linha' por 'coluna'.
 */
class Matriz
{
public:
    Matriz(int linhas, int colunas);
    Matriz(int tamanho, MC_VALUES = NULA);
    Matriz(double *entradas, int linhas, int colunas);
    ~Matriz();
    double getValor(int linha, int coluna);
    void setValor(int linha, int coluna, double valor);
    int getLinhas();
    int getColunas();
    void imprimirMatriz();
    Matriz &transposta();
    Matriz &oposta();
    bool isNula();
    bool isIdentidade();
    bool isSimetrica();
    bool isQuadrada();
    bool isMatrizLinha();
    bool isMatrizColuna();
    Matriz &inversa();
    Matriz &operator*(Matriz &A);
    Matriz &operator*(double a);
    Matriz &operator+(Matriz &A);
    void operator=(Matriz &A);
    void pivotamentoParcial();

    Matriz &resolverSistema(Matriz &B);

    double getTempo();

private:
    int linhas;
    int colunas;
    double** valores;
    TimerChrono timer;
};

#endif // MATRIZ_H_INCLUDED
