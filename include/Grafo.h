#ifndef GRAFO_H
#define GRAFO_H


class Grafo
{
    public:
        Grafo(int val);
        virtual ~Grafo();

        float getM(int i, int j) { return mat[i][j]; }
        void setM(int i, int j, float val) { mat[i][j] = val; }

        float getV(int i) { return vet[i]; }
        void setV(int i, float val) { vet[i] = val; }

        int GetnumeroV() { return numeroV; }
        void SetnumeroV(int val) { numeroV = val; }

    private:
        int numeroV;
        float **mat;
        float *vet;
};

#endif // GRAFO_H
