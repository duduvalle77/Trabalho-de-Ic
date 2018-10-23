#ifndef SOLUCAO_H
#define SOLUCAO_H
#include "Grafo.h"
#include <vector>
using namespace std;

class Solucao
{
    public:
        Solucao(int nn, int ng, float h, float l);
        virtual ~Solucao();
        void Swap();
        void Best();
        void InsereG(int v, int gru);
        void BestVG(vector<int> &cand, int gru);
        void BestGV(int v);

        float verificaGG(int gru);
        float CalculoS(vector<vector<int> >gr);
        float CalculoGV(int j, int v);
        float verificaGS(int gru);
        bool verificaSolucao();
        bool verificaGrupos();
        void Imprime(vector<vector<int> >gr);

        float getMa(int i, int j) { return g->getM(i,j); }
        void setMa(int i, int j, float val) { g->setM(i,j,val); }

        float getVe(int i) { return g->getV(i); }
        void setVe(int i, float val) { g->setV(i,val); }

        int GetnumeroVe() { return g->GetnumeroV(); }
        void SetnumeroVe(int val) { g->SetnumeroV(val); }

        vector<vector<int> >grupos;
        vector<vector<int> >best;
    private:
        float high, lower;
        int numeroG;
        Grafo *g;

};

#endif // SOLUCAO_H
