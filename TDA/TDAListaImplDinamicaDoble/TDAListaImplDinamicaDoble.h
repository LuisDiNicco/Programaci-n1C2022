#ifndef TDALISTAIMPLDINAMICADOBLE_H_INCLUDED
#define TDALISTAIMPLDINAMICADOBLE_H_INCLUDED

#include "../Nodo/NodoD.h"

typedef NodoD* Lista;

typedef struct
{
    NodoD* primero;
    NodoD* actual;
}
Iterador;

#endif // TDALISTAIMPLDINAMICADOBLE_H_INCLUDED
