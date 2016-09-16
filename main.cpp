#include "Output.h"
#include "Matriz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "OpenFile.h"
#include "stringToNumber.h"

int main()
{
    OpenFile file("A4x4.txt");
    file.jumpToNextLine();

    acentos();

    std::string entrada;
    std::string line;
    std::ostringstream os; //vou usar isso aqui pra converter int em string
    int tamanho;

    cout << "Diga o tamanho da matriz, em inteiro" << endl;

    std::cin >> tamanho;

    os << tamanho;

    entrada = "A" + os.str() + "x" + os.str() + ".txt";

    cout << entrada << endl;


    double valor[tamanho][tamanho] = {};

    for(int i = 0; i < tamanho; i++)
    {
        for(int j = 0; j < tamanho; j++)
        {
            file.next(); // Vai para a próxima palavra
            valor[i][j] = stringToNumber(file.getWord()); //Converte para String
        }
    }

    Matriz A(*valor, tamanho, tamanho);
    Matriz B(*valor, tamanho, tamanho);

    cout << A.getTempo() << endl; // Tempo da entrada.
    cout << B.getTempo() << endl; // Tempo da entrada.

    TimerChrono multiplication;
    multiplication.start();

    Matriz C(tamanho, tamanho);
    C = (B * A);

    multiplication.end();

    TimerChrono reading1;
    reading1.start();
    A.imprimirMatriz();
    reading1.end();

    TimerChrono reading2;
    reading2.start();
    B.imprimirMatriz();
    reading2.end();

    cout << "Entrada A: " << A.getTempo() << endl;
    cout << "Entrada B: " << B.getTempo() << endl;
    cout << "Multiplicação: " << multiplication.getElapsedTime() << endl;
    cout << "Leitura A: << " << reading1.getElapsedTime() << endl;
    cout << "Leitura B: << " << reading2.getElapsedTime() << endl;

    return 0;
}
