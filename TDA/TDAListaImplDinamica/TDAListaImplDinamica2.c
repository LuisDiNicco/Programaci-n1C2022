#include <stdio.h>
#define TDA_LISTA_IMPL_DINAMICA

#include "../TDALista/TDALista.h"

typedef struct
{
    Nodo* primero;
    Nodo* actual;
}
iteradorLista2;
/*
booleano crearIterador2(Lista* pl, iteradorLista2* it)
{
    it->primero = *pl;
    it->actual = NULL;

    if(*pl)
        return FALSO;

    return VERDADERO;
}

booleano obtenerPrimeroDeLista2(iteradorLista2* it, void* elem, size_t tamElem)
{
    if(!it->primero)
        return FALSO;

    it->actual = it->primero;

    memcpy(elem, it->actual->elem, min(it->actual->tamElem,tamElem));

    return VERDADERO;
}

booleano obtenerSiguienteDeLista2(iteradorLista2* it, void* elem, size_t tamElem)
{
    if(!it->actual)
        return FALSO;

    it->actual = it->actual->sig;

    if(!it->actual)
        return FALSO;

    memcpy(elem, it->actual->elem, min(tamElem, it->actual->tamElem));

    return VERDADERO;
}

booleano haySiguienteEnLista2(iteradorLista2* it, void* elem, size_t tamElem)
{
    if(!it->actual)
        return FALSO;

    return it->actual->sig != NULL;
}

booleano finDeLista(iteradorLista2* it)
{
    return !it->actual;
}
*/

booleano crearIterador3(Lista* pl, iteradorLista2* it)
{
    it->primero = *pl;
    it->actual = NULL;

    if(!it->primero)
        return FALSO;

    return VERDADERO;
}

booleano obetenerPrimero3(iteradorLista2* it, void* elem, size_t tamElem)
{
    if(!it->primero)
        return FALSO;

    it->actual = it->primero;

    memcpy(elem, it->actual->elem, min(tamElem, it->actual->tamElem));

    return VERDADERO;
}

booleano obtenerSiguiente3(iteradorLista2* it, void* elem, size_t tamElem)
{
    if(!it->actual)
        return FALSO;

    it->actual = it->actual->sig;

    if(!it->actual)
        return FALSO;

    memcpy(elem, it->actual->elem, min(tamElem, it->actual->tamElem));

    return VERDADERO;
}

booleano haySiguiente3(iteradorLista2* it)
{
    if(!it->actual)
        return FALSO;

    return it->actual->sig != NULL;
}

booleano finLista3(iteradorLista2* it)
{
    return it->actual == NULL;
}
