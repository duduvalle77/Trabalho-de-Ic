#include "Solucao.h"
#include "Grafo.h"
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

Solucao::Solucao(int nn, int ng, float h, float l)
{
    high = h;
    lower = l;
    numeroG = ng;
    g = new Grafo(nn);
    for(int i = 0; i < numeroG; i++)
    {
        vector<int> grupo;
        grupo.clear();
        grupos.push_back(grupo);
    }
}

Solucao::~Solucao()
{
    delete g;
}

void Solucao::Swap()
{
    vector<int> candNovo;
    for(unsigned int j = 0;j<grupos.size();j++)
    {
        int k;
        if(grupos[j].size() == 0)
        {
            //cout << " deu ruim " << endl;
            return;
        }
        else
            k = rand()%grupos[j].size();

        int w = grupos[j][k];
        grupos[j].erase(grupos[j].begin()+k);
        candNovo.push_back(w);
    }
    for (unsigned int j = 0;j<candNovo.size(); j++)
    {
        BestGV(candNovo[j]);
    }
    //cout << " deu (Swap) " << endl;
}

void Solucao::Imprime(vector<vector<int> >gr)
{
    cout << endl;
    for(unsigned int i = 0; i<gr.size(); i++)
    {
        for (unsigned int j = 0; j<gr[i].size(); j++)
        {
                cout << " " << gr[i][j];
        }
        cout << endl;
    }
}

float Solucao::CalculoS(vector<vector<int> >gr)
{
    float soma = 0;
    for(unsigned int i = 0; i<gr.size(); i++)
    {
        for (unsigned int j = 0; j<gr[i].size(); j++)
        {
            for (unsigned int k = j+1; k<gr[i].size();k++)
            {
                soma += getMa(gr[i][j],gr[i][k]);
            }
        }

    }
    return soma;
}

void Solucao::Best()
{
    if (CalculoS(best) <= CalculoS(grupos))
    {
        best = grupos;
    }
    else
        grupos = best;

    //cout << " deu (Best) " << endl;
}

bool Solucao::verificaGrupos()
{
    bool Esolucao = true;
    float soma = 0;
    for(unsigned int i = 0; i<grupos.size(); i++)
    {
        soma = verificaGG(i);
        if (soma<lower || soma>high)
        {
            Esolucao = false;
            break;
        }
    }
    //cout << " deu (Verifica Grupos) " << endl;

    return Esolucao;
}

bool Solucao::verificaSolucao()
{
    bool Esolucao = true;
    float soma = 0;
    for(int i = 0; i<numeroG; i++)
    {
        soma = verificaGS(i);
        if (soma<lower || soma>high)
        {
            Esolucao = false;
            break;
        }
    }

    return Esolucao;
}

float Solucao::CalculoGV(int j, int v)
{
    float soma = 0;
    for(unsigned int i = 0; i<grupos[j].size(); i++)
    {
        soma += getMa(grupos[j][i],v);
    }
    return soma;
}

void Solucao::InsereG(int v, int gru)
{
    grupos[gru].push_back(v);
}

float Solucao::verificaGG(int gru)
{
    float soma = 0;
    for (unsigned int j = 0; j<grupos[gru].size(); j++)
    {
        soma += getVe(grupos[gru][j]);
    }
    return soma;
}

float Solucao::verificaGS(int gru)
{
    float soma = 0;
    for (unsigned int j = 0; j<best[gru].size(); j++)
    {
        soma += getVe(best[gru][j]);
    }
    return soma;
}

void Solucao::BestVG(vector<int> &cand, int gru)
{
    int i = 0;
    float aux = 0;
    float maior = 0;
    for (unsigned int j = 0; j<cand.size(); j++)
    {
        aux = CalculoGV(gru,cand[j]);
        if(aux>maior && verificaGG(gru)+getVe(cand[j])<=high)
        {
            maior = aux;
            i=j;
        }
    }
    if(verificaGG(gru)+getVe(cand[i])<=high)
    {
        InsereG(cand[i],gru);
        cand.erase(cand.begin()+i);
    }
}

void Solucao::BestGV(int v)
{
    int i = 0;
    float aux = 0;
    float maior = 0;
    for (unsigned int j = 0; j<grupos.size(); j++)
    {
        aux = CalculoGV(j,v);
        if(aux>=maior && verificaGG(j)+getVe(v)<=high)
        {
            maior = aux;
            i=j;
        }
    }
    if(verificaGG(i)+getVe(v)<=high)
    {
        InsereG(v,i);
    }
}

