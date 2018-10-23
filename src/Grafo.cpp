#include "Grafo.h"

Grafo::Grafo(int val)
{
    SetnumeroV(val);
    vet = new float[val];
    mat = new float*[val];
    for(int i = 0; i < val; i++)
        mat[i] = new float[val];
}


Grafo::~Grafo()
{
    for(int i = 0; i < numeroV; i++)
        delete [] mat[i];
    delete [] mat;
    delete [] vet;
}
