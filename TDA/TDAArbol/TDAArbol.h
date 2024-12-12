#ifndef TDAARBOL_H_INCLUDED
#define TDAARBOL_H_INCLUDED

#ifdef TDA_ARBOL_IMPL_DINAMICA
    #include "../TDAArbolImplDinamica/TDAArbolImplDinamica.h"
#endif // TDA_ARBOL_IMPL_DINAMICA

typedef enum
{
    COMPLETO, BALANCEADO, AVL, DESBALANCEADO
}
TipoArbol;

typedef void(*ImprimirElemArbol)(void* elem, void* datosImprimir, int nivel);

void crearArbol(Arbol* pa);

int insertarEnArbolIterativa(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
int insertarEnArbolRecursiva(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
booleano buscarEnArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
booleano eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);

booleano arbolVacio(Arbol* pa);

void recorrerArbolPreOrden(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEnOrden(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPostOrden(Arbol* pa, Accion accion, void* datosAccion);


void vaciarArbol(Arbol* pa);
void imprimirArbol(const Arbol* pa, ImprimirElemArbol imprimir, void* datosImprimir);

booleano esArbolBalanceado(const Arbol* pa);
booleano esArbolCompleto(const Arbol* pa);
booleano esArbolAVL(const Arbol* pa);
TipoArbol tipoArbol(const Arbol* pa);

#endif // TDAARBOL_H_INCLUDED
