#include <stdlib.h>
#include <string.h>

#define TDA_PILA_IMPL_DINAMICA

#include "../TDAPila/TDAPila.h"

void crearPila(Pila* pp)
{
    *pp = NULL;
}

booleano apilar(Pila* pp, const void* elem, size_t tamElem)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(elemNuevo);
        free(nuevo);
        return FALSO;
    }

    memcpy(elemNuevo, elem, tamElem);
    nuevo->elem = elemNuevo; // 1
    nuevo->tamElem = tamElem; // 1.2

    nuevo->sig = *pp; // 2

    *pp = nuevo; // 3

    return VERDADERO;
}

booleano desapilar(Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp) // *pp == NULL
        return FALSO;

    Nodo* nae = *pp; // 1
    *pp = nae->sig; // 2

    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));

    free(nae->elem);
    free(nae);

    return VERDADERO;
}

booleano verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return FALSO;

    Nodo* tope = *pp;

    memcpy(elem, tope->elem, min(tamElem, tope->tamElem));

    return VERDADERO;
}

booleano pilaVacia(const Pila* pp)
{
    return !*pp; //*pp == NULL
}

booleano pilaLlena(const Pila* pp, size_t tamElem)
{
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    void* elemNuevo = malloc(tamElem);

    free(nuevo);
    free(elemNuevo);

    return !nuevo || !elemNuevo;
}

void vaciarPila(Pila* pp)
{
    while(*pp)
    {
        Nodo* nae = *pp;
        *pp = nae->sig;

        free(nae->elem);
        free(nae);
    }
}
