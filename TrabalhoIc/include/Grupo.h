#ifndef GRUPO_H
#define GRUPO_H
#include <vector>
using namespace std;

class Grupo
{
    public:
        Grupo();
        virtual ~Grupo();
        void insereN(int i) {grupo.push_back(i);}
        void removeN(int i);
        int retornaV(int i) {return grupo[i];}
        int retornaS() {return grupo.size();}

    private:
        vector<int> grupo;
};

#endif // GRUPO_H
