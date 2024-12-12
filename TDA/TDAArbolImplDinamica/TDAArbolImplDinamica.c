#include <math.h>

#define TDA_ARBOL_IMPL_DINAMICA

#include "../TDAArbol/TDAArbol.h"

/** IMPRIMIR **/
void imprimirArbolRecursivo(const Arbol* pa, ImprimirElemArbol imprimir, void* datosImprimir, int nivel);

/** BUSCAR **/
const Arbol* buscarNodorbol(const Arbol* pa, const void* elem, Cmp cmp);

/** ELIMINAR **/
const Arbol* buscarRaizArbol(const Arbol* pa, const void* elem, Cmp cmp);
const Arbol* menorDeArbol(const Arbol* pa);
const Arbol* mayorDeArbol(const Arbol* pa);
void eliminarRaizDeArbol(Arbol* pae);
int alturaArbol(const Arbol* pa);

/** TIPO ARBOL **/
int contarNodos(const Arbol* pa);
int contarNodosHastaNivel(const Arbol* pa, int nivel);

void crearArbol(Arbol* pa)
{
    *pa = NULL;
}

int insertarEnArbolIeterativa(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    int comp;
    while(*pa)
    {
        comp = cmp(elem, (*pa)->elem);

        if(comp == 0)
        {
            if(actualizar) // si le pasas NULL en actualizar, no actualiza nada
               return actualizar((*pa)->elem, elem);

            return DUPLICADO;
        }

        if(comp < 0)
            pa = &(*pa)->hIzq;
        else
            pa = &(*pa)->hDer;
    }

    *pa = crearNodoA(elem, tamElem);

    return *pa ? TODO_OK : SIN_MEM; // si hay algo en *pa se puso la hoja. Si quedo null no se hizo nada
}

int insertarEnArbolRecursiva(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    if(!*pa)
    {
        *pa = crearNodoA(elem, tamElem);

        return *pa ? TODO_OK : SIN_MEM;
    }

    int comp = cmp(elem, (*pa)->elem);

    if(comp == 0)
    {
        if(actualizar)
            return actualizar((*pa)->elem, elem);

        return DUPLICADO;
    }

    return insertarEnArbolRecursiva(comp > 0 ? &(*pa)->hDer : &(*pa)->hIzq, elem, tamElem, cmp, actualizar);
}

booleano buscarEnArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp) /***/
{
    Arbol* paBuscado = (Arbol*)buscarNodorbol(pa, elem, cmp);

    if(!paBuscado) // no lo encontre
        return FALSO;

    memcpy(elem, (*paBuscado)->elem, min(tamElem, (*paBuscado)->tamElem));

    return VERDADERO;
}

const Arbol* buscarNodorbol(const Arbol* pa, const void* elem, Cmp cmp) /***/
{
    if(!*pa)
        return NULL;

    int comp = cmp(elem, (*pa)->elem);

    if(comp == 0)
        return pa;

    return buscarNodorbol(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, elem, cmp);
}

booleano eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    Arbol* pae = (Arbol*)buscarRaizArbol(pa, elem, cmp);

    if(!pae) // si pae tiene NULL, no encuentre el elem
        return FALSO;

    memcpy(elem, (*pae)->elem, min(tamElem, (*pae)->tamElem));
    free((*pae)->elem); // solo liberas el elemento a borrar, el nodo lo mantenes

    eliminarRaizDeArbol(pae);

    return VERDADERO;
}

const Arbol* buscarRaizArbol(const Arbol* pa, const void* elem, Cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp = cmp(elem, (*pa)->elem);

    if(comp == 0)
        return pa;

    return buscarRaizArbol(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, elem, cmp);
}

void eliminarRaizDeArbol(Arbol* pae)
{
    if(!(*pae)->hDer && !(*pae)->hIzq) // es hoja
    {
        free(*pae);
        *pae = NULL;
        return;
    }

    int hijosI = alturaArbol(&(*pae)->hIzq);
    int hijosD = alturaArbol(&(*pae)->hDer);

    Arbol* par = hijosI > hijosD ? (Arbol*)mayorDeArbol(&(*pae)->hIzq) : (Arbol*)menorDeArbol(&(*pae)->hDer);

    (*pae)->elem = (*par)->elem;
    (*pae)->tamElem = (*par)->tamElem;

    eliminarRaizDeArbol(par);
}

int alturaArbol(const Arbol* pa)
{
    if(!*pa)
        return 0;

    return max(alturaArbol(&(*pa)->hDer), alturaArbol(&(*pa)->hIzq)) + 1;
}

const Arbol* menorDeArbol(const Arbol* pa)
{
    if(!(*pa)->hIzq)
        return pa;

    return menorDeArbol(&(*pa)->hIzq);
}

const Arbol* mayorDeArbol(const Arbol* pa)
{
    if(!(*pa)->hDer)
        return pa;

    return mayorDeArbol(&(*pa)->hDer);
}

booleano arbolVacio(Arbol* pa) /***/
{
    return *pa == NULL;
}

void recorrerArbolPreOrden(Arbol* pa, Accion accion, void* datosAccion)
{
    if(!*pa)
        return;

    accion((*pa)->elem, datosAccion);
    recorrerArbolPreOrden(&(*pa)->hIzq, accion, datosAccion);
    recorrerArbolPreOrden(&(*pa)->hDer, accion, datosAccion);
}

void recorrerArbolEnOrden(Arbol* pa, Accion accion, void* datosAccion)
{
    if(!*pa)
        return;

    recorrerArbolPreOrden(&(*pa)->hIzq, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
    recorrerArbolPreOrden(&(*pa)->hDer, accion, datosAccion);
}

void recorrerArbolPostOrden(Arbol* pa, Accion accion, void* datosAccion)
{
     if(!*pa)
        return;

    recorrerArbolPreOrden(&(*pa)->hIzq, accion, datosAccion);
    recorrerArbolPreOrden(&(*pa)->hDer, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
}

void vaciarArbol(Arbol* pa) /***/
{
    while(*pa)
    {
        if(*pa && !(*pa)->hIzq && !(*pa)->hDer) // si es hoja
        {
          NodoA* nae = (*pa);

          free(nae->elem);
          free(nae);

          *pa = NULL;

          return;
        }

        vaciarArbol(&(*pa)->hDer); // si no es hoja mando a borrar a los hijos
        vaciarArbol(&(*pa)->hIzq);
    }
}

void vaciarArbol2(Arbol* pa) /***/
{
    if(!*pa) // caso base, ya no tengo nada
        return;

    vaciarArbol2(&(*pa)->hIzq);
    vaciarArbol2(&(*pa)->hDer);

    NodoA* nae  = *pa;

    free(nae->elem);
    free(nae);

    *pa = NULL;
}

void imprimirArbol(const Arbol* pa, ImprimirElemArbol imprimir, void* datosImprimir)
{
    imprimirArbolRecursivo(pa, imprimir, datosImprimir, 0);
}

void imprimirArbolRecursivo(const Arbol* pa, ImprimirElemArbol imprimir, void* datosImprimir, int nivel)
{
    if(!*pa)
        return;
    imprimirArbolRecursivo(&(*pa)->hDer, imprimir, datosImprimir, nivel + 1);
    imprimir((*pa)->elem, datosImprimir, nivel);
    imprimirArbolRecursivo(&(*pa)->hIzq, imprimir, datosImprimir, nivel + 1);

}

booleano esArbolBalanceado(const Arbol* pa) /***/
{
    int h = alturaArbol(pa);

    if(h <= 2)
        return VERDADERO;

    int cantNodosCompletosPenultimoNivelCALCULADO = pow(2, h-1) - 1;
    int cantNodosCompletosPenultimoNivelREALES = contarNodosHastaNivel(pa, h - 2);

    return cantNodosCompletosPenultimoNivelCALCULADO == cantNodosCompletosPenultimoNivelREALES;
}

int contarNodosHastaNivel(const Arbol* pa, int nivel) /****/
{
    if(!*pa)
        return 0;

    if(nivel == 0)
        return 1;

    return contarNodosHastaNivel(&(*pa)->hIzq, nivel-1) +
            contarNodosHastaNivel(&(*pa)->hDer, nivel-1) + 1;
}

booleano esArbolCompleto(const Arbol* pa) /****/
{
    int cantNodosCalculado = pow(2, alturaArbol(pa)) - 1;

    int cantNodosReales = contarNodos(pa);

    return cantNodosCalculado == cantNodosReales;
}

int contarNodos(const Arbol* pa) /****/
{
    if(!*pa)
        return 0;

    return contarNodos(&(*pa)->hIzq) + contarNodos(&(*pa)->hDer) + 1;
}

booleano esArbolAVL(const Arbol* pa) /****/
{
    if(!*pa)
        return VERDADERO;

    int hI = alturaArbol(&(*pa)->hIzq);
    int hD = alturaArbol(&(*pa)->hDer);

    if(abs(hI - hD) > 1)
        return FALSO;

    return esArbolAVL(&(*pa)->hIzq) && esArbolAVL(&(*pa)->hDer);
}

TipoArbol tipoArbol(const Arbol* pa) /***/
{
    if(esArbolCompleto(pa))
        return COMPLETO;

    if(esArbolBalanceado(pa))
        return BALANCEADO;

    if(esArbolAVL(pa))
        return AVL;

    return DESBALANCEADO;
}
