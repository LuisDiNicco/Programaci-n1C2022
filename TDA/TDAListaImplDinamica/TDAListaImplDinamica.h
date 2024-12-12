#ifndef TDALISTAIMPLDINAMICA_H_INCLUDED
#define TDALISTAIMPLDINAMICA_H_INCLUDED

#include "../Nodo/Nodo.h"

typedef Nodo* Lista;

typedef struct
{
    Nodo* primero;
    Nodo* actual;
}
Iterador;

#endif // TDALISTAIMPLDINAMICA_H_INCLUDED
