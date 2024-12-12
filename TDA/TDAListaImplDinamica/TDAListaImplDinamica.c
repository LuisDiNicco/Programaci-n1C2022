#include <stdio.h>
#define TDA_LISTA_IMPL_DINAMICA

#include "../TDALista/TDALista.h"

Lista* buscarMenorDeLista(Lista* pl, Cmp cmp);

void crearLista(Lista* pl)
{
    *pl = NULL;
}

int insertarEnListaOrdSinDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0) // buscas donde iria
    {
        pl = &(*pl)->sig; // avanzas al siguiente nodo
    }

    if(*pl && cmp(elem, (*pl)->elem) == 0) // revisas si hay un duplicado
        return DUPLICADO;

    Nodo* nuevo = crearNodo(elem, tamElem); // creas el nodo

    if(!nuevo)
        return SIN_MEM;


    nuevo->sig = *pl; // 1 enganchas nuevo con lista
    *pl = nuevo; // 2 y la lista con el nodo nuevo

    return TODO_OK;
}

int insertarEnListaOrdConDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    Nodo* nuevo = crearNodo(elem, tamElem);

    if(!nuevo)
        return SIN_MEM;

    nuevo->sig = *pl;
    *pl = nuevo;

    return TODO_OK;
}

int insertarEnListaAlPrincipio(Lista* pl, const void* elem, size_t tamElem)
{
    Nodo* nuevo = crearNodo(elem, tamElem);
    if(!nuevo)
        return SIN_MEM;

    nuevo->sig = *pl;
    *pl = nuevo;

    return TODO_OK;
}

int insertarEnListaAlFinal(Lista* pl, const void* elem, size_t tamElem)
{
    while(*pl)
        pl = &(*pl)->sig;

    Nodo* nuevo = crearNodo(elem, tamElem);
    if(!nuevo)
        return SIN_MEM;

    nuevo->sig = *pl;
    *pl = nuevo;

    return TODO_OK;
}

int insertarEnListaEnPos(Lista* pl, const void* elem, size_t tamElem, int pos)
{
    int posAct = 1;

    while(*pl && posAct < pos)
    {
        posAct ++;
        pl = &(*pl)->sig;
    }

    if(posAct < pos) // si la ultima posicion posible no es la posicion pedida, no se puede insertar
        return FALSO;

    Nodo* nuevo = crearNodo(elem, tamElem);
    if(!nuevo)
        return SIN_MEM;

    nuevo->sig = *pl;
    *pl = nuevo;

    return TODO_OK;
}

booleano buscarEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp) /** duda **/
{
    while(*pl && cmp(elem, (*pl)->elem) > 0) // lo voy buscando
        pl = &(*pl)->sig;

    if(!*pl && cmp(elem, (*pl)->elem) < 0) // termino sin encontrarlo o encontre uno mas grande
        return FALSO;

    memcpy(elem, (*pl)->elem, min(tamElem, (*pl)->tamElem));

    return VERDADERO;
}

booleano buscarEnListaDesord(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) != 0)
        pl = &(*pl)->sig;

    if(!*pl)
        return FALSO;

    memcpy(elem, (*pl)->elem, min(tamElem, (*pl)->tamElem));

    return VERDADERO;
}

booleano buscarEnListaEnPos(Lista* pl, void* elem, size_t tamElem, Cmp cmp, int pos)
{
    int posAct = 1;

    while(*pl && posAct < pos)
    {
        pl = &(*pl)->sig;
        posAct ++;
    }

    if(!*pl) // si recorrio toda la lista, sumno uno de mas a posAct
        posAct --;

    if(posAct == pos) // lo encontre
    {
        memcpy(elem, (*pl)->elem, min(tamElem, (*pl)->tamElem));
        return VERDADERO;
    }

    return FALSO; // no lo encontre
}

booleano verPrimeroDeLista(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    memcpy(elem, (*pl)->elem, min(tamElem, (*pl)->tamElem));

    return VERDADERO;
}

booleano verUltimoDeLista(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    while((*pl)->sig)
        pl = &(*pl)->sig;

    memcpy(elem, (*pl)->elem, min(tamElem, (*pl)->tamElem));

    return VERDADERO;
}

booleano listaVacia(Lista* pl)
{
    if(!*pl)
        return VERDADERO;
    else
        return FALSO;
}

booleano listaLlena(Lista* pl, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNue  = malloc(tamElem);

    free(nue);
    free(elemNue);

    return !nue || !elemNue;
}

booleano eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0) // busco el elemento
        pl = &(*pl)->sig;

    if(!*pl && cmp(elem, (*pl)->elem) < 0) // si no lo encontro
        return FALSO;

    Nodo* nae = *pl; // 1 digo cual voy a borrar
    *pl= nae->sig; // 2 lo desengancho

    destruirNodo(nae, elem, tamElem);

    return VERDADERO;
}

booleano eliminarDeListaDesord(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl)
    {
        if((cmp(elem, (*pl)->elem)) == 0)
        {
            Nodo* nae = *pl;
            *pl = nae->sig;

            destruirNodo(nae, elem, tamElem);

            return VERDADERO;
        }
        pl = &(*pl)->sig;
    }

    return FALSO;
}

booleano eliminarDeListaPrimero(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    Nodo* nae = *pl;
    *pl = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return VERDADERO;
}

booleano eliminarDeListaUltimo(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    while((*pl)->sig)
        pl = &(*pl)->sig;

    Nodo* nae = *pl;
    *pl = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return VERDADERO;
}

booleano eliminarDeListaEnPos(Lista* pl, void* elem, size_t tamElem, int pos)
{
    int posAct = 1;

    while(*pl && posAct < pos)
    {
        pl = &(*pl)->sig;
        posAct ++;
    }

    if(!*pl) // si hay 10 elementos en la lista y justo quiero borrar el 11, si no hago esto explota todo
        posAct --;

    if(posAct == pos) // posicion correcta
    {
        Nodo* nae = *pl;
        *pl = nae->sig;

        destruirNodo(nae, elem, tamElem);

        return VERDADERO;
    }

    return FALSO; // posicion incorrecta
}

int eliminarDuplicadosDeListaOrd(Lista* pl, Cmp cmp) /** PROBAR !!!!! **/
{
    if(!*pl)
        return FALSO;

    Lista* nReferencia = pl;
    Lista* act;

    act = &(*nReferencia)->sig;

    while(*nReferencia)
    {
        while(*act && cmp((*nReferencia)->elem, (*act)->elem) == 0) // busco el elemento
        {
            Nodo* nae = *act;
            *act = nae->sig;

            free(nae->elem);
            free(nae);
        }

        nReferencia = act;
        act = &(*nReferencia)->sig;
    }

    return VERDADERO;
}

int eliminarDuplicadosDeListaDesord(Lista* pl, Cmp cmp) /** probar !!!!**/
{
    if(!*pl)
        return FALSO;

    Lista* nReferencia = pl;
    Lista* act;
    Lista* actAux;

    act = &(*nReferencia)->sig;

    while(*nReferencia)
    {
        actAux = act;
        while(*act) // busco el elemento
        {
            if(cmp((*nReferencia)->elem, (*act)->elem) == 0)
            {
                Nodo* nae = *act;
                *act = nae->sig;

                free(nae->elem);
                free(nae);
            }
            if(*act)
                act = &(*act)->sig;
        }

        nReferencia = actAux;
        act = &(*nReferencia)->sig;
    }

    return VERDADERO;
}

void ordenarLista(Lista* pl, Cmp cmp)
{
    Lista lOrdenada;
    Lista* plUltimo = &lOrdenada;
    Lista* plMenor;

    while(*pl)
    {
        plMenor = buscarMenorDeLista(pl, cmp); // busco el mas chico

        *plUltimo = *plMenor; // lo inserto en la lista ordenada
        *plMenor = (*plMenor)->sig; // lo desengancho de la lista original

        plUltimo = &(*plUltimo)->sig; // avanzo la posicion donde tengo que insertar en la lista ordenada
    }

    *pl = lOrdenada; // hago que la lista original apunte a la lista ordenada
}

Lista* buscarMenorDeLista(Lista* pl, Cmp cmp)
{
    Lista* plMenor = pl;
    Lista* plAct = &(*plMenor)->sig;

    while(*plAct)
    {
        if(cmp((*plAct)->elem, (*plMenor)->elem) < 0)
            plMenor = plAct;

        plAct = &(*plAct)->sig;
    }

    return plMenor;
}

void vaciarLista(Lista* pl) /** probar **/
{
    Nodo* nae;

    while(*pl)
    {
        nae = *pl;
        *pl = nae->sig;
    }
}

void recorrerLista(Lista* pl, Accion accion, void* datosAccion)
{
    while(*pl)
    {
        accion((*pl)->elem, datosAccion);
        pl = &(*pl)->sig;
    }
}


/*************************************
*************************************
            ITERADOR
**************************************
*************************************/

booleano crearIterador(Iterador* it, const Lista* pl)
{
    it->primero = *pl;
    it->actual = NULL;

    if(!*pl)
        return FALSO;

    return VERDADERO;
}

booleano primeroDeLista(Iterador* it, void* elem, size_t tamElem)
{
    if(!it->primero)
        return FALSO;

    it->actual = it->primero;

    memcpy(elem, it->actual->elem, min(tamElem, it->actual->tamElem));

    return VERDADERO;
}

booleano siguienteDeLista(Iterador* it, void* elem, size_t tamElem)
{
    if(!it->actual)
        return FALSO;

    it->actual = it->actual->sig;

    if(!it->actual)
        return FALSO;

    memcpy(elem, it->actual->elem, min(tamElem, it->actual->tamElem));

    return VERDADERO;
}

booleano haySiguienteEnLista(Iterador* it)
{
    if(!it->actual)
        return FALSO;

    return it->actual->sig != NULL;
}

booleano finLista(Iterador* it)
{
   return !it->actual; // it->actual == NULL
}
