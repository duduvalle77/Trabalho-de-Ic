#include "Grupo.h"
#include <vector>

Grupo::Grupo()
{

}

Grupo::~Grupo()
{
    grupo.~vector();
}

void Grupo::removeN(int i)
{
    for (int j = 0; j < grupo.size(); j++)
        if(grupo[j] == i)
            grupo.erase(grupo.begin()+j);
}
