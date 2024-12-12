#ifndef NODOD_H_INCLUDED
#define NODOD_H_INCLUDED

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "../../Comun/Comun.h"

typedef struct SnodoD
{
    void* elem;
    size_t tamElem;
    struct SnodoD* sig;
    struct SnodoD* ant;
}
NodoD;

NodoD* crearNodoD(const void* elem, size_t tamElem);
void destruirNodoD(NodoD* nae, void* elem, size_t tamElem);

#endif // NODOD_H_INCLUDED
