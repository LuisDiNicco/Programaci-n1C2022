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

    nuevo->elem = elemNuevo; // 1
    nuevo->tamElem = tamElem;

    nuevo->sig = *pp; // 2
    *pp = nuevo; // 3

    memcpy(elemNuevo, elem, tamElem);

    return VERDADERO;
}

booleano desapilar (Pila* pp, void* elem, size_t tamElem)
{
    if(*pp == NULL)
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

booleano pilaLlena(const Pila* pp, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNue = malloc(tamElem);

    free(elemNue);
    free(nue);

    return !nue || !elemNue;
}

booleano pilaVacia(const Pila* pp)
{
    if(*pp != NULL)
        return FALSO;

    return VERDADERO;
}

void vaciarPila(Pila* pp)
{
    Nodo* nae = *pp;

    while(nae) // nae != NULL
    {
        *pp = nae->sig;

        free(nae->elem);
        free(nae);

        nae = *pp;
    }
}
