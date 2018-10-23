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

int main()
{
    time_t timeStart;
    float x;
    double tim = 0;
    srand (time(NULL));
    int type = 1;
    string path = "D:/Trabalhos/IC/TrabalhoIc/instancias-Grupos/TipoA/DCC136-82_01.txt";
    Input i;
    return 0;
    i.readInstance(path,type);
    timeStart = clock();
    i.construtivo();

    tim = (double)((clock() - timeStart) / CLOCKS_PER_SEC);
    while (tim <= 60)
    {
        cout << " deu " << endl;
        i.buscaLocal();
        tim = (double)((clock() - timeStart) / CLOCKS_PER_SEC);
    }
    i.s->Imprime(i.s->best);
    x = i.s->CalculoS(i.s->best);
    cout <<endl <<x <<endl;

    i.~Input();

}
