#include "OpenFile.h"
#include <fstream>
#include <iostream>
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;

OpenFile::OpenFile(string path)
{
    //Abre o arquivo:
    ifstream text(path);

    //Pega o tamanho do arquivo:
    text.seekg(0, text.end);
    int lenght = text.tellg();

    //Volta para o estado inicial:
    text.seekg(0, text.beg);

    //Aloca um vetor com o tamanho do texto:
    char* charText = new char[lenght];

    //Preenche o vetor com o texto:
    int position = 0;
    while(!text.eof())
    {
        text.get(charText[position++]);
    }

    //Salva o texto numa string dentro da classe:
    this->text = new string(charText);

    //Libera a memória:
    delete [] charText;

    //Inicia variável de posição:
    this->position = 0;
}

string OpenFile::getText()
{
    return *this->text;
}

bool OpenFile::next()
{
    //Alcança o primeiro número que aparecer:
    for(int i = position; i < text->length(); i++)
    {
        if(text->at(i) != ' ' && text->at(i) != '\n')
        {
            position = i;
            break;
        }
    }

    //Checa se já chegou ao final do arquivo:
    if(position+1 == text->length())
    {
        return false;
    }

    //Se achar a palavra, retorna verdadeira, senão, falso:
    string aux;
    for(int i = position; i < text->length(); i++)
    {
        if(text->at(i) != ' ' && text->at(i) != '\n')
        {
            aux = aux + text->at(i);
        }
        else
        {
            position = i+1;
            this->word = aux;
            return true;
        }
    }

    return false;
}

bool OpenFile::finished()
{
    if(position == text->length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

string OpenFile::getWord()
{
    return this->word;
}

void OpenFile::jumpToNextLine()
{
    for(int i = position; i < text->length(); i++)
    {
        if(text->at(i) == '\n')
        {
            position = i+1;
            return;
        }
    }
}
