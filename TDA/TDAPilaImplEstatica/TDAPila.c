#include <string.h>

#define TDA_PILA_IMPL_ESTATICA

#include "../TDAPila/TDAPila.h"

void crearPila(Pila* pp)
{
    pp->tope = 0;
}

booleano apilar(Pila* pp, const void* elem, size_t tamElem)
{
    if(tamElem + sizeof(size_t) > TAM_PILA - pp->tope)
        return FALSO;

    memcpy(pp->vec + pp->tope, elem, tamElem);
    pp->tope += tamElem;

    *(size_t*)(pp->tope + pp->vec) = tamElem; // pp->tope + pp->vec es un puntero a void. Lo tenes que castear a puntero a algo. Y a ese puntero a size_t lo desreferencias para copiar ahi adentro de la pila el tamaño del size_t

    pp->tope += sizeof(size_t);

    return VERDADERO;
}

booleano desapilar(Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope == 0)
        return FALSO;

    pp->tope -= sizeof(size_t);
    size_t tamElemApi = *(size_t*)(pp->vec + pp->tope);

    pp->tope -= tamElemApi;
    memcpy(elem, pp->tope + pp->vec, min(tamElem, tamElemApi));

    return VERDADERO;
}

booleano verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
{
    if(pp->tope == 0)
        return FALSO;

    unsigned tope = pp->tope;
    tope -= sizeof(size_t);
    size_t tamElemApi = *(size_t*)(pp->vec + tope);

    tope -= tamElemApi;
    memcpy(elem, tope + pp->vec, min(tamElem, tamElemApi));

    return VERDADERO;
}

booleano pilaVacia(const Pila* pp)
{
    return pp->tope == 0 ? VERDADERO : FALSO;
}

booleano pilaLlena(const Pila* pp, size_t tamElem)
{
    return tamElem + sizeof(size_t) > TAM_PILA - pp->tope ? VERDADERO : FALSO;
}
void vaciarPila(Pila* pp);
