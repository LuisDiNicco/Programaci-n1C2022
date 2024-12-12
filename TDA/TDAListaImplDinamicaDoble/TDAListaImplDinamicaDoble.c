#define TDA_LISTA_IMPL_DINAMICA_DOBLE

#include"../TDALista/TDALista.h"

void crearLista(Lista* pl)
{
    *pl = NULL;
}

/** FUNCIONES DE INSERTAR **/

int insertarEnListaOrdSinDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp) // hecha por profe
{
    NodoD* act = *pl;
    NodoD* ant = NULL;
    NodoD *sig = NULL;

    if(act != NULL) // si no esta vacia
    {
        while(act->ant && cmp(elem, act->elem) < 0)
            act = act->ant;

        while(act->sig && cmp(elem, act->elem) > 0)
            act = act->sig;

        int comp = cmp(elem, act->elem);

        if(comp == 0)
            return DUPLICADO;

        if(comp < 0) // por ej act = 10 y elem es 8. act apunta al que le seguiria al nuevo
        {
            sig = act;
            ant = act->ant;
        }
        else // por ej act = 10 y elem es 12. act apunta al que estaria antes del nuevo
        {
            ant = act;
            sig = act->sig;
        }
    }

    NodoD* nuevo = crearNodoD(elem, tamElem);

    if(!nuevo)
        return SIN_MEM;

    nuevo->ant = ant; // 1
    nuevo->sig = sig; // 2

    if(ant)
        ant->sig = nuevo; // 3

    if(sig)
        sig->ant = nuevo; // 4

    *pl = nuevo;

    return TODO_OK;
}

int insertarEnListaOrdConDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp) /***/
{
    NodoD* act = *pl;
    NodoD* sig = NULL;
    NodoD* ant = NULL;

    if(act)
    {
        while(act->ant && cmp(elem, act->elem) < 0)
            act = act->ant;

        while(act->sig && cmp(elem, act->elem) > 0)
            act = act->sig;

        int comp = cmp(elem, act->elem);

        if(comp >= 0)
        {
            ant = act;
            sig = act->sig;
        }
        else
        {
            sig = act;
            ant = act->ant;
        }
    }

    NodoD* nuevo = (NodoD*)malloc(sizeof(NodoD));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(nuevo);
        free(elemNuevo);
        return SIN_MEM;
    }

    memcpy(elemNuevo, elem, tamElem);

    nuevo->elem = elemNuevo;
    nuevo->tamElem = tamElem;

    nuevo->ant = ant;
    nuevo->sig = sig;

    if(ant)
        ant->sig = nuevo;

    if(sig)
        sig->ant = nuevo;

    *pl = nuevo;

    return TODO_OK;
}

int insertarEnListaAlPrincipio(Lista* pl, const void* elem, size_t tamElem)
{
    NodoD* act = *pl;

    if(act)
    {
        while(act->ant)
            act = act->ant;
    }

    NodoD* nuevo = (NodoD*)malloc(sizeof(NodoD));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(nuevo);
        free(elemNuevo);
        return SIN_MEM;
    }

    memcpy(elemNuevo, elem, tamElem);

    nuevo->elem = elemNuevo;
    nuevo->tamElem = tamElem;

    nuevo->ant = NULL;
    nuevo->sig = act;

    if(act)
       act->ant = nuevo;

    if(!*pl)
        *pl = nuevo; // ?? si estaba vacia hago que apunte al primero, sino que qeude en donde estaba

    return TODO_OK;
}

int insertarEnListaAlFinal(Lista* pl, const void* elem, size_t tamElem)
{
    NodoD* act = *pl;

    if(act)
    {
        while(act->sig)
            act = act->sig;
    }

    NodoD* nuevo = crearNodoD(elem, tamElem);

    if(!nuevo)
        return SIN_MEM;

    nuevo->sig = NULL;
    nuevo->ant = act;

    if(act)
        act->sig = nuevo;

    if(!*pl)
        *pl = nuevo; // si estaba vacia lo pongo en el nuevo, sino lo dejo donde estaba

    return TODO_OK;
}

int insertarEnListaEnPos(Lista* pl, const void* elem, size_t tamElem, int pos)
{
    NodoD* act = *pl;
    NodoD* sig = NULL;
    NodoD* ant = NULL;

    if(act) // si la lista no estsba vacia
    {
        while(act->ant) // lo llevo al principio
            act = act->ant;

        int i = pos - 1;
        while(act->sig && i > 0)
        {
            act = act->sig;
            i--;
        }

        if(i > 1 || i < 0)
            return NO_ENCONTRADO;

         if(i == 1) // inserto en la ultima posicion
        {
            sig = act->sig;
            ant = act;
        }
        else
        {
            sig = act;
            ant = act->ant;
        }
    }
    else if(pos != 1) // solo podria insertar en la posicion 1
        return NO_ENCONTRADO;

    NodoD* nuevo = crearNodoD(elem, tamElem);
    if(!nuevo)
        return SIN_MEM;

    nuevo->ant = ant;
    nuevo->sig = sig;

    if(ant)
        ant->sig = nuevo;

    if(sig)
        sig->ant = nuevo;

    if(!*pl)
        *pl = nuevo;

    return TODO_OK;
}

int insertarActualizarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    NodoD* act = *pl;
    NodoD* ant = NULL;
    NodoD* sig = NULL;

    if(act != NULL)
    {
        while(act->ant && cmp(elem, act->elem) < 0)
            act = act->ant;

        while(act->sig && cmp(elem, act->elem) > 0)
            act = act->sig;

        int comp = cmp(elem, act->elem);
        if(comp == 0) // duplicado
        {
            actualizar(act->elem, elem);
            return DUPLICADO;
        }

        if(comp > 0) // act apunta al que tiene que estar antes
        {
            ant = act;
            sig = act->sig;
        }
        else //act apunta al que tendria que estar despues
        {
            sig = act;
            ant = act->ant;
        }
    }

    NodoD* nuevo = (NodoD*)malloc(sizeof(NodoD));
    void* elemNuevo = malloc(tamElem);

    if(!nuevo || !elemNuevo)
    {
        free(elemNuevo);
        free(nuevo);
        return SIN_MEM;
    }

    memcpy(elemNuevo, elem, tamElem);
    nuevo->elem = elemNuevo;
    nuevo->tamElem = tamElem;

    nuevo->ant = ant;
    nuevo->sig = sig;

    if(ant)
        ant->sig = nuevo;

    if(sig)
        sig->ant = nuevo;

    *pl = nuevo;

    return TODO_OK;
}

/** FUNCIONES ELIMINAR **/

booleano eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp) // hecha por profe
{
    if(!*pl)
        return FALSO;

    NodoD* nae = *pl;

    while(nae->ant && cmp(elem, nae->elem) < 0)
        nae = nae->ant;

    while(nae->sig && cmp(elem, nae->elem) > 0)
        nae = nae->sig;

    if(cmp(elem, nae->elem) != 0)
        return FALSO;

    if(nae->ant)
        nae->ant->sig = nae->sig;

    if(nae->sig)
        nae->sig->ant = nae->ant;

    if(nae == *pl)
    {
        if(nae->sig)
            *pl = nae->sig;
        else // si estoy sacando el ultimo la lista queda en NULL
            *pl = nae->ant;
    }

    destruirNodoD(nae, elem, tamElem);

    return VERDADERO;
}

booleano eliminarDeListaDesord(Lista* pl, void* elem, size_t tamElem, Cmp cmp) /** mejorable **/
{
    if(!*pl)
        return FALSO;

    NodoD* naeI = *pl;
    NodoD* naeD = *pl;
    NodoD* nae;

    while(naeI->ant && cmp(elem, naeI->elem) != 0)
        naeI = naeI->ant;

    if(cmp(elem, naeI->elem) != 0)
    {
        while(naeD->sig && cmp(elem, naeD->elem) != 0)
            naeD = naeD->sig;

        if(cmp(elem, naeD->elem) != 0)
            return FALSO;
        else
            nae = naeD;
    }
    else
        nae = naeI;

    if(nae->ant)
        nae->ant->sig = nae->sig;
    if(nae->sig)
        nae->sig->ant = nae->ant;

    if(nae == *pl)
    {
        if(nae->sig)
            *pl = nae->sig;
        else
            *pl = nae->ant;
    }

    destruirNodoD(nae, elem, tamElem);

    return VERDADERO;
}

booleano eliminarDeListaPrimero(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    NodoD* nae = *pl;

    while(nae->ant)
        nae = nae->ant;

    if(nae->sig)
        nae->sig->ant = NULL;

    if(*pl == nae)
        *pl = nae->sig;

    destruirNodoD(nae, elem, tamElem);

    return VERDADERO;
}

booleano eliminarDeListaUltimo(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    NodoD* nae = *pl;

    while(nae->sig)
        nae = nae->sig;

    if(nae->ant)
        nae->ant->sig = NULL;

    if(nae == *pl)
        *pl = nae->ant;

    destruirNodoD(nae, elem, tamElem);

    return VERDADERO;
}

booleano eliminarDeListaEnPos(Lista* pl, void* elem, size_t tamElem, int pos)
{
    if(!*pl || pos < 1)
        return FALSO;

    NodoD* nae = *pl;
    int i = pos - 1;

    while(nae->ant) // vas al principio
        nae = nae->ant;

    while(nae->sig && i > 0)
    {
        nae = nae->sig;
        i --;
    }

    if(i != 0)
        return FALSO;

    if(nae->ant)
        nae->ant->sig = nae->sig;
    if(nae->sig)
        nae->sig->ant = nae->ant;

    if(nae == *pl)
    {
        if(nae->sig)
            *pl = nae->sig;
        else
            *pl = nae->ant;
    }

    destruirNodoD(nae, elem, tamElem);

    return VERDADERO;
}

/** FUNCIONES BUSCAR Y VER **/

booleano buscarEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    if(!*pl)
        return FALSO;

    NodoD* act = *pl;

    while(act->ant && cmp(elem, act->elem) < 0)
        act = act->ant;

    while(act->sig && cmp(elem, act->elem) > 0)
        act = act->sig;

    int comp = cmp(elem, act->elem);

    if(comp != 0)
        return FALSO;

    memcpy(elem, act->elem, min(tamElem, act->tamElem));

    return VERDADERO;
}

booleano buscarEnListaDesord(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    if(!*pl)
        return FALSO;

    NodoD* actI = *pl;
    NodoD* actD = *pl;
    NodoD* act;

    while(actI->ant && cmp(elem, actI->elem) != 0)
        actI = actI->ant;

    if(cmp(elem, actI->elem) !=0 )
    {
        while(actD->sig && cmp(elem, actI->elem) != 0)
            actD = actD->sig;

        if(cmp(elem, actD->elem) != 0)
            return FALSO;

        act = actD;
    }
    else
        act = actI;

    memcpy(elem, act->elem, min(tamElem, act->tamElem));

    return VERDADERO;
}

booleano buscarEnListaEnPos(Lista* pl, void* elem, size_t tamElem, Cmp cmp, int pos)
{
    if(!*pl || pos < 1)
        return FALSO;

    NodoD* act = *pl;
    int i = pos - 1;

    while(act->ant)
        act = act->ant;

    while(act->sig && i > 0)
    {
        act = act->sig;
        i--;
    }

    if(i != 0)
        return FALSO;

    memcpy(elem, act->elem, min(tamElem, act->tamElem));

    return VERDADERO;
}

booleano verPrimeroDeLista(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    NodoD* primero = *pl;

    while(primero->ant)
        primero = primero->ant;

    memcpy(elem, primero->elem, min(tamElem, primero->tamElem));

    return VERDADERO;
}

booleano verUltimoDeLista(Lista* pl, void* elem, size_t tamElem)
{
    if(!*pl)
        return FALSO;

    NodoD* ultimo = *pl;

    while(ultimo->sig)
        ultimo = ultimo->sig;

    memcpy(elem, ultimo->elem, min(tamElem, ultimo->tamElem));

    return VERDADERO;
}

/** ORDENAR Y ELIMINAR DUPLICADOS **/

int eliminarDuplicadosDeListaOrd(Lista* pl, Cmp cmp)
{
    if(!*pl)
        return FALSO;

    NodoD* act = *pl;
    NodoD* sig;
    NodoD* nae;

    while(act->ant)
        act = act->ant;

    while(act)
    {
        sig = act->sig;
        while(sig && cmp(act->elem, sig->elem) == 0)
        {
            nae = sig;
            sig = sig->sig;

            act->sig = nae->sig;
            nae->sig->ant = act;

            if(nae == *pl)
            {
                if(nae->ant)
                    *pl = nae->ant;
                else
                    *pl = nae->sig;
            }

            free(nae->elem);
            free(nae);
        }

        act = act->sig;
    }

    return VERDADERO;
}

int eliminarDuplicadosDeListaDesord(Lista* pl, Cmp cmp)
{
    NodoD* act = *pl;
    NodoD* nae;
    NodoD* sig;

    while(act->ant)
        act = act->ant;

    while(act)
    {
        sig = act->sig;
        while(sig)
        {
            if(cmp(act->elem, sig->elem) == 0)
            {
                nae = sig;

                if(nae->ant)
                    nae->ant->sig = nae->sig;
                if(nae->sig)
                    nae->sig->ant = nae->ant;

                if(nae == *pl)
                {
                    if(nae->ant)
                        *pl = nae->ant;
                    else
                        *pl = nae->sig;
                }

                free(nae->elem);
                free(nae);
            }

            sig = sig->sig;
        }

        act = act->sig;
    }

    return VERDADERO;
}

void ordenarLista(Lista* pl, Cmp cmp)
{
    if(!*pl)
        return;

    NodoD* act = *pl;
    NodoD* sup = NULL;
    NodoD* inf = NULL;

    int huboCambios = 1;

    while(act->ant) // te paras al principio
        act = act->ant;

    while(huboCambios == 1) // en la misma pasada ordenas 2 elementos. Los 2 extremos
    {
        huboCambios = 0;

        while(act->sig != sup) // llevo el mas grande al fondo
        {
            if(cmp(act->elem, act->sig->elem) > 0) // tengo [12] y [10]
            {
                void* elemAux = act->elem;
                size_t tamElemAux = act->tamElem;

                act->elem = act->sig->elem; // pongo el [10] atras
                act->tamElem = act->sig->tamElem;

                act->sig->elem = elemAux; // avanzo al [12]
                act->sig->tamElem = tamElemAux;

                huboCambios = 1;
            }

            act = act->sig; // avanzo act para llevar al mayor al final de todo
        }

        sup = act; // en la ultima posicion quedo el mas grande

        while(act->ant != inf) // levo al mas chico al principio
        {
            if(cmp(act->elem, act->ant->elem) < 0) // tengo [8] y [10]
            {
                void* elemAux = act->elem;
                size_t tamElemAux = act->tamElem;

                act->elem = act->ant->elem; // pongo el [10] despues
                act->tamElem = act->ant->tamElem;

                act->ant->elem = elemAux; // pongo el [8] antes
                act->ant->tamElem = tamElemAux;

                huboCambios = 1;
            }

            act = act->ant; // retrocedo act
        }

        inf = act; // en el principio quedo el mas chico
    }
}

/** FUNCIONES EXTRAS **/

booleano listaVacia(Lista* pl)
{
    return *pl == NULL;
}

booleano listaLlena(Lista* pl, size_t tamElem)
{
    NodoD* nuevo = (NodoD*)malloc(sizeof(NodoD*));
    void* elemNuevo = malloc(tamElem);

    free(nuevo);
    free(elemNuevo);

    return !nuevo || !elemNuevo;
}

void vaciarLista(Lista* pl)
{
    if(*pl)
    {
        NodoD* act = *pl;
        NodoD* nae;

        while(act->sig) // borro todo a la derecha
        {
            nae = act->sig;
            act->sig = nae->sig;

            free(nae->elem);
            free(nae);
        }

        while(act->ant) // borro todo a la izquierda
        {
            nae = act->ant;
            act->ant = nae->ant;

            free(nae->elem);
            free(nae);
        }

        free(act->elem);
        free(act);

        *pl = NULL;
    }
}

void recorrerLista(Lista* pl, Accion accion, void* datosAccion)
{
    NodoD* act = *pl;

    if(act)
    {
        while(act->ant)
            act = act->ant;
    }

    while(act)
    {
        accion(act->elem, datosAccion);
        act = act->sig;
    }
}
