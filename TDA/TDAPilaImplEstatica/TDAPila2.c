#include <string.h>

#define TDA_PILA_IMPL_ESTATICA

#include "../TDAPila/TDAPila.h"

void crearPila(Pila* pp)
{
    pp->tope = 0;
}

booleano apilar(Pila* pp, const void* elem, size_t tamElem)
{
    if((sizeof(size_t) + tamElem) > TAM_PILA - pp->tope)
        return FALSO;

    memcpy(pp->vec + pp->tope, elem, tamElem);
    pp->tope += tamElem;

    *(size_t*)(pp->vec + pp->tope) = tamElem;

    pp->tope += sizeof(size_t);

    return VERDADERO;
}

booleano desapilar(Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope == 0)
        return FALSO;

    pp->tope -= sizeof(size_t);

    size_t tamElemApilado = *(size_t*)(pp->vec + pp->tope);

    pp->tope -= tamElemApilado;

    memcpy(elem, pp->vec + pp->tope, min(tamElemApilado, tamElem));

    return VERDADERO;
}

booleano verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope == 0)
        return FALSO;

    int tope = pp->tope;
    tope -= sizeof(size_t);

    size_t tamElemApilado = *(size_t*)(pp->vec + tope);

    tope -= tamElemApilado;

    memcpy(elem, pp->vec + tope, min(tamElem, tamElemApilado));

    return VERDADERO;
}

booleano pilaVacia(const Pila* pp)
{
    return pp->tope == 0;
}

booleano pilaLlena(const Pila* pp, size_t tamElem)
{
    return (sizeof(size_t) + tamElem) > TAM_PILA - pp->tope;
}

void vaciarPila(Pila* pp)
{
   pp->tope = 0;
}
