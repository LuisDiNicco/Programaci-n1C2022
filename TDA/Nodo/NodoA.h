#ifndef NODOA_H_INCLUDED
#define NODOA_H_INCLUDED

#include "../../Comun/Comun.h"

typedef struct SnodoA
{
    void* elem;
    size_t tamElem;
    struct SnodoA* hIzq;
    struct SnodoA* hDer;
}
NodoA;

NodoA* crearNodoA(const void* elem, size_t tamElem);
void destruirNodoA(NodoA* nae, void* elem, size_t tamElem);

#endif // NODOA_H_INCLUDED
