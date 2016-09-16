#include "Matriz.h"

Matriz::Matriz(int linhas, int colunas)
{
    this->linhas = linhas;
    this->colunas = colunas;

    acentos();

    valores = new double*[linhas];
    for(int i = 0; i < linhas; i++)
    {
        valores[i] = new double[colunas];
        for(int j = 0; j < colunas; j++)
        {
            valores[i][j] = 0;
        }
    }
}

Matriz::Matriz(int tamanho, MC_VALUES mc)
{
    this->linhas = tamanho;
    this->colunas = tamanho;

    acentos();

    //Aloca espaço para armazenar os valores na matriz:

    valores = new double*[linhas];
    for(int i = 0; i < linhas; i++)
    {
        valores[i] = new double[colunas];
        for(int j = 0; j < colunas; j++)
        {
            if(mc == IDENTIDADE)
            {
                if(i == j)
                {
                    valores[i][j] = 1;
                }
                else
                {
                    valores[i][j] = 0;
                }
            }
            else
            {
                valores[i][j] = 0;
            }
        }
    }
}

Matriz::Matriz(double *entradas, int linhas, int colunas)
{
    int iterator = 0;
    acentos();
    this->linhas = linhas;
    this->colunas = colunas;

    timer.start();

    valores = new double*[linhas];
    for(int i = 0; i < linhas; i++)
    {
        valores[i] = new double[colunas];
        for(int j = 0; j < colunas; j++)
        {
            valores[i][j] = entradas[iterator++];
        }
    }

    timer.end();
}

int Matriz::getLinhas()
{
    return linhas;
}

int Matriz::getColunas()
{
    return colunas;
}

double Matriz::getValor(int linha, int coluna)
{
    if(linha >= getLinhas() || coluna >= getColunas() || linha < 0 || coluna < 0)
    {
        return 0;
    }

    return valores[linha][coluna];
}

void Matriz::imprimirMatriz()
{
    for(int i = 0; i < getLinhas(); i++)
    {
        for(int j = 0; j < getColunas(); j++)
        {
            cout << valores[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Matriz::setValor(int linha, int coluna, double valor)
{
    if(linha > this->linhas)
    {
        cout << "Erro! Insira um valor menor que " << this->linhas << " para a linha." << endl;
    }
    if(coluna > this->colunas)
    {
        cout << "Erro! Insira um valor menor que " << this->colunas << " para a coluna." << endl;
    }

    valores[linha][coluna] = valor;
}

Matriz::~Matriz()
{
    for(int i = 0; i < this->linhas; i++)
    {
        delete[] valores[i];
    }
    delete[] valores;
}

Matriz &Matriz::operator*(Matriz &A)
{
    if(this->colunas != A.linhas)
    {
        return *this;
    }

    Matriz* aux = new Matriz(this->linhas, A.colunas);

    for(int i = 0; i < aux->linhas; i++)
    {
        for(int j = 0; j < aux->colunas; j++)
        {
            for(int k = 0; k < this->colunas; k++)
            {
                aux->setValor(i, j,
                             aux->getValor(i, j) +
                             this->getValor(i, k) *
                             A.getValor(k, j));
            }
        }
    }

    return *aux;
}

Matriz &Matriz::operator+(Matriz &A)
{
    Matriz *aux = new Matriz(this->getLinhas(), this->getColunas());

    for(int i = 0; i < aux->getLinhas(); i++)
    {
        for(int j = 0; j < aux->getColunas(); j++)
        {
            aux->setValor(i, j, this->getValor(i, j) + A.getValor(i, j));
        }
    }

    return *aux;
}

double Matriz::getTempo()
{
    return timer.getElapsedTime();
}

void Matriz::operator=(Matriz &A)
{
    if(this->linhas != A.getLinhas() || this->colunas != A.getColunas())
    {
        return;
    }

    for(int i = 0; i < this->linhas; i++)
    {
        for(int j = 0; j < this->colunas; j++)
        {
            this->setValor(i, j, A.getValor(i, j));
        }
    }
}
