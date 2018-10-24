#include <iostream>
#include "Solucao.h"
#include "Grafo.h"
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <string.h>
#include "Input.h"

using namespace std;

void Iimprime(vector<vector<int> >gr)
{
    cout << endl << "{";
    for(unsigned int i = 0; i<gr.size(); i++)
    {
        cout << "{";
        for (unsigned int j = 0; j<gr[i].size(); j++)
        {
                if(j == gr[i].size()-1)
                    cout << gr[i][j];
                else
                    cout << gr[i][j] << ", ";

        }
        if(i == gr.size()-1)
            cout << "}";
        else
            cout <<"}, ";

    }
    cout << "}" << endl;
}

int main()
{
    vector<vector<int> >bestOfbest;
    time_t timeStart;
    float x, maior = 0, media=0;
    double tim = 0;
    srand (time(NULL));
    int type = 1;
    string path = "instancias-Grupos/TipoA/DCC136-82_02.txt";
    Input i;

    i.readInstance(path,type);
    for(int z = 0; z<10;z++)
    {
        timeStart = clock();
        i.construtivo();
        tim = 0;
        tim = (double)((clock() - timeStart) / CLOCKS_PER_SEC);
        while (tim <= 60)
        {
            i.buscaLocal();
            tim = (double)((clock() - timeStart) / CLOCKS_PER_SEC);
        }
        i.s->Imprime(i.s->best);
        x = i.s->CalculoS(i.s->best);
        media += x/10;
        cout <<endl <<x <<endl;
        if(x> maior)
        {
            maior=x;
            bestOfbest= i.s->best;
        }
        i.Clear();
    }
    i.s->Imprime(bestOfbest);
    Iimprime(bestOfbest);
    cout <<maior <<" " << media;
    return 0;

}
