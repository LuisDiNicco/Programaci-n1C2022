#define TDA_PILA_IMPL_DINAMICA_CIRCULAR

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

    nuevo->elem = elemNuevo;
    nuevo->tamElem = tamElem;

    if(*pp == NULL) // estaba vacia
    {
        *pp = nuevo;
        (*pp)->sig = nuevo; // nuevo->sig = nuevo
    }
    else // habia elementos en la pila
    {
        nuevo->sig = (*pp)->sig; // el nuevo se pone arriba del ultimo
        (*pp)->sig = nuevo; // el primero apunta al de arriba del todo (el nuevo)
    }

    return VERDADERO;
}

booleano desapilar(Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return FALSO;

    Nodo* nae = (*pp)->sig;

    if(nae == (*pp))
        *pp = NULL;
    else
        (*pp)->sig = nae->sig;

    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));

    free(nae->elem);
    free(nae);

    return VERDADERO;
}

booleano verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return FALSO;

    Nodo* tope = (*pp)->sig;

    memcpy(elem, tope->elem, min(tamElem, tope->tamElem));

    return VERDADERO;
}

booleano pilaVacia(const Pila* pp)
{
    return *pp == NULL;
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
    Nodo* nae;

    while(*pp)
    {
        nae = (*pp)->sig;

        if(nae == *pp)
            *pp = NULL;
        else
            (*pp)->sig = nae->sig;

        free(nae->elem);
        free(nae);
    }
}
