#define TDA_COLA_IMPL_DINAMICA_CIRCULAR

#include "../TDACola/TDACola.h"

void crearCola(Cola* pc)
{
    *pc = NULL;
}

booleano encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nuevo = crearNodo(elem, tamElem);
    if(!nuevo)
        return FALSO;

    if(*pc) // si habia elementos en la cola
    {
        nuevo->sig = (*pc)->sig; // 1
        (*pc)->sig = nuevo; // 2
    }
    else // si estaba vacia
    {
        nuevo->sig = nuevo; // 1 bis
    }

    *pc = nuevo; // 3

    return VERDADERO;
}

booleano desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(!*pc)
        return FALSO;

    Nodo* nae = (*pc)->sig;

    if(nae == (*pc)) // estoy borrando el ultimo, va a quedar vacia.
        *pc = NULL;
    else // no estoy borrando el ultimo elemento de la cola
        (*pc)->sig = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return VERDADERO;
}

booleano verFrenteDeCola(Cola* pc, void* elem, size_t tamElem)
{
    if(!*pc)
        return FALSO;

    Nodo* primero = (*pc)->sig;

    memcpy(elem, primero->elem, min(tamElem, primero->tamElem));

    return VERDADERO;
}

booleano colaVacia(Cola* pc)
{
    return *pc == NULL;
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
    Nodo* nae;
    while(*pc)
    {
        nae = (*pc)->sig;
        if(nae != (*pc))
            (*pc)->sig = nae->sig;
        else
            *pc = NULL;

        free(nae->elem);
        free(nae);
    }
}
