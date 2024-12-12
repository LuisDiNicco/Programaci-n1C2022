#include <stdlib.h>
#include <string.h>

#define TDA_COLA_IMPL_DINAMICA

#include "../TDACola/TDACola.h"

void crearCola(Cola* pc)
{
    pc->fondo = pc->frente = NULL;
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

    nuevo->elem = elemNuevo;
    nuevo->tamElem = tamElem;
    nuevo->sig = NULL;

    memcpy(elemNuevo, elem, tamElem);

    if(pc->fondo == NULL)
        pc->frente = nuevo;
    else
       pc->fondo->sig = nuevo;

    pc->fondo = nuevo;

    return VERDADERO;
}

booleano desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->frente == NULL)
        return FALSO;

    Nodo* nae = pc->frente;
    pc->frente = nae->sig;

    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));

    free(nae->elem);
    free(nae);

    if(pc->frente == NULL)
        pc->fondo = NULL;

    return VERDADERO;
}

booleano verFrenteDeCola(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->frente == NULL)
        return FALSO;

    Nodo* frente = pc->frente;

    memcpy(elem, frente->elem, min(tamElem, frente->tamElem));

    return TODO_OK;
}

booleano colaVacia(Cola* pc)
{
    return !pc->frente; // pc->frente == NULL
}

booleano colaLlena(Cola* pc, size_t tamElem)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    void* elemNuevo = malloc(tamElem);

    free(nuevo);
    free(elemNuevo);

    return !nuevo || !elemNuevo;
}

void vaciarCola(Cola* pc)
{
    while(pc->frente != NULL)
    {
        Nodo* nae = pc->frente;

        pc->frente = nae->sig;

        free(nae->elem);
        free(nae);
    }

    pc->fondo = NULL;
}
