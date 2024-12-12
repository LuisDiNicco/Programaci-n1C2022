#include <stdlib.h>
#include <string.h>

#define TDA_COLA_IMPL_DINAMICA

#include "../TDACola/TDACola.h"

void crearCola(Cola* pc)
{
    pc->frente = pc->fondo = NULL;
}

booleano encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(nuevo);
        free(elemNuevo);
        return FALSO;
    }

    memcpy(elemNuevo, elem, tamElem);

    nuevo->elem = elemNuevo;
    nuevo->tamElem = tamElem;
    nuevo->sig = NULL;

    if(pc->fondo == NULL)
        pc->frente = nuevo; // 3
    else
        pc->fondo->sig = nuevo; // 1

    pc->fondo = nuevo; // 2

    return VERDADERO;
}

booleano desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->fondo == NULL)
        return FALSO;

    Nodo* nae = pc->frente; // 1
    pc->frente = nae->sig; // 2

    if(pc->frente == NULL) // si la cola quedo vacia
        pc->fondo = NULL;

    memcpy(elem, nae->elem, min(nae->tamElem, tamElem));

    free(nae->elem);
    free(nae);

    return VERDADERO;
}

booleano verFrenteDeCola(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->frente == NULL)
        return FALSO;

    Nodo* frente = pc->frente; // 1
    memcpy(elem, frente->elem, min(tamElem, frente->tamElem));

    return VERDADERO;
}

booleano colaVacia(Cola* pc)
{
    if(pc->frente == NULL) // !pc->frente
        return VERDADERO;

    return FALSO; // return !pc->frente
}

booleano colaLlena(Cola* pc, size_t tamElem)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    void* elemNuevo = malloc(tamElem);

    free(nuevo);
    free(elemNuevo);

    return !nuevo || !elemNuevo; // nuevo == NULL || elemNuevo == NULL
}

void vaciarCola(Cola* pc)
{
    Nodo* nae;
    Nodo* frente = pc->frente;

    while(frente != NULL)
    {
        nae = frente;
        frente = nae->sig;

        free(nae->elem);
        free(nae);
    }

    pc->frente = pc->fondo = NULL;
}
