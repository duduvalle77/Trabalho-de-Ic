#include "Input.h"
#include <fstream>
#include "Solucao.h"
#include "Grafo.h"
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

void Input::readInstance(string path, int type)
{
    if (type == 1 || type == 2)
    {
        if (type == 1)
            readType1(path);
        else
            readType2(path);
    }

}

void Input::readType1(string path)
{
    ifstream reader;
    string aux;
    reader.open (path.c_str());
    if (reader.is_open())
    {
        reader >> q;
        reader >> groupSize;
        reader >> aux;
        reader >> lowerB;
        reader >> upperB;
        s = new Solucao(q, groupSize, upperB, lowerB);
        //descartando os outros limites (pois sao todos iguais)
        for(int i = 0;i < groupSize-1; ++i)
            reader >> aux >> aux;
        reader >> aux; //descartando W

        //lendo pesos dos nos
        float auxi;
        for (int i = 0; i < q; ++i)
        {
            reader >> auxi;
            s->setVe(i,auxi);
        }


        int id1, id2;
        float weight;
        //lendo as arestas
        while (reader >> id1 >> id2 >> weight)
        {
            s->setMa(id1,id2,weight);
            s->setMa(id2,id1,weight);
        }
    }
    else
        cout << "Falha na leitura da instancia!" << endl;

}

void Input::readType2(string path)
{
    ifstream reader;
    reader.open(path.c_str());
    if (reader.is_open())
    {
        reader >> q;
        reader >> groupSize;
        reader >> upperB;
        lowerB = 0.0;
        s = new Solucao(q, groupSize, upperB, lowerB);
        //lendo pesos dos nos
        float auxi;
        for (int i = 0; i < q; ++i)
        {
            reader >> auxi;
            s->setVe(i,auxi);
        }
        //lendo as arestas
        for (int i = 0; i < q; ++i)
            for (int j = 0; j < q; ++j)
            {
                reader >> auxi;
                s->setMa(i,j,auxi);
            }
    }
    else
        cout << "Falha na leitura da instancia!" << endl;

}
Input::~Input()
{
    //cand.~vector();
    //s->~Solucao(); /// -----------------------------------------------
    delete s;
}

Input::Input()
{

}

void Input::construtivo()
{
    for(int i = 0; i<q; i++)
            cand.push_back(i);
    for(int k = 0; k<groupSize; k++)
    {
        int i = rand()%cand.size();
        s->InsereG(cand[i],k);
        cand.erase(cand.begin()+i);
        while (s->verificaGG(k)<lowerB)
        {
            s->BestVG(cand,k);
        }
    }
    for(unsigned int c = 0; c<cand.size(); c++)
    {
        s->BestGV(cand[c]);
    }
    s->best = s->grupos;
}

void Input::buscaLocal()
{
    s->Swap();
    if(s->verificaGrupos())
    {
        s->Best();
    }
    //cout << " deu (Busca Local) " << endl;
}

void Input::Clear()
{
    for(unsigned int i=0; i < s->grupos.size();i++)
    {
        s->grupos[i].clear();
        s->best[i].clear();
    }
    cand.clear();

}
