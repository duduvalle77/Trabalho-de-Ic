#ifndef INPUT_H
#define INPUT_H
#include <fstream>
#include <string.h>
#include "Solucao.h"
#include "Grafo.h"
#include <stdlib.h>
#include <vector>
#include <time.h>


class Input {

public:
    Input();
    ~Input();
    int q;
    int groupSize;
    float lowerB;
    float upperB;
    void construtivo();
    void buscaLocal();
    void readInstance(string path, int type);
    Solucao *s;
    void Clear();
private:
    void readType1(string path);
    void readType2(string path);
    vector<int> cand;
};

#endif // INPUT_H
