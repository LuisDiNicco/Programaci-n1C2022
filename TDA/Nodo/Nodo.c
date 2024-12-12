#include "Nodo.h"
#include "NodoD.h"
#include "NodoA.h"

Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(nuevo);
        free(elemNuevo);
        return NULL;
    }

    memcpy(elemNuevo, elem, tamElem);

    nuevo->tamElem = tamElem;
    nuevo->elem = elemNuevo;
    nuevo->sig = NULL;

    return nuevo;
}

void destruirNodo(Nodo* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));

    free(nae->elem);
    free(nae);
}

NodoD* crearNodoD(const void* elem, size_t tamElem)
{
    NodoD* nuevo = (NodoD*)malloc(sizeof(NodoD));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(nuevo);
        free(elemNuevo);
        return NULL;
    }

    memcpy(elemNuevo, elem, tamElem);

    nuevo->tamElem = tamElem;
    nuevo->elem = elemNuevo;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    return nuevo;
}
void destruirNodoD(NodoD* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));

    free(nae->elem);
    free(nae);
}

NodoA* crearNodoA(const void* elem, size_t tamElem)
{
    NodoA* nuevo = (NodoA*)malloc(sizeof(NodoA));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(nuevo);
        free(elemNuevo);
        return NULL;
    }

    memcpy(elemNuevo, elem, tamElem);

    nuevo->tamElem = tamElem;
    nuevo->elem = elemNuevo;
    nuevo->hIzq = NULL;
    nuevo->hDer = NULL;

    return nuevo;
}
void destruirNodoA(NodoA* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));

    free(nae->elem);
    free(nae);
}
