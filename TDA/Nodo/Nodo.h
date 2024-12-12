#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#include "../Comun/Comun.h"

typedef struct Snodo
{
    void* elem;
    size_t tamElem;
    struct Snodo* sig;
}
Nodo;

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);

#endif // NODO_H_INCLUDED
