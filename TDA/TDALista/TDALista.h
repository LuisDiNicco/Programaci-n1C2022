#ifndef TDALISTA_H_INCLUDED
#define TDALISTA_H_INCLUDED

#include <string.h>

#include "../Comun/Comun.h"
//#include "../Comun/Comun.h"

#ifdef TDA_LISTA_IMPL_ESTATICA
    #include "../TDAListaImplEstatica/TDAListaImplEstatica.h"
#endif // TDA_LISTA_IMPL_ESTATICA

#ifdef TDA_LISTA_IMPL_DINAMICA
    #include "../TDAListaImplDinamica/TDAListaImplDinamica.h"
#endif // TDA_LISTA_IMPL_DINAMICA

#ifdef TDA_LISTA_IMPL_DINAMICA_DOBLE
    #include "../TDAListaImplDinamicaDoble/TDAListaImplDinamicaDoble.h"
#endif // TDA_LISTA_IMPL_DINAMICA

void crearLista(Lista* pl);                                                             // hecho

int insertarEnListaOrdSinDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);     // hecho
int insertarEnListaOrdConDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);     /** probar **/ //
int insertarEnListaAlPrincipio(Lista* pl, const void* elem, size_t tamElem);            /** probar **/ //
int insertarEnListaAlFinal(Lista* pl, const void* elem, size_t tamElem);                /** probar **/ //
int insertarEnListaEnPos(Lista* pl, const void* elem, size_t tamElem, int pos);         /** probar **/ //

booleano buscarEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);              /** probar **/ //
booleano buscarEnListaDesord(Lista* pl, void* elem, size_t tamElem, Cmp cmp);           /** probar **/ //
booleano buscarEnListaEnPos(Lista* pl, void* elem, size_t tamElem, Cmp cmp, int pos);   /** probar **/ //

booleano verPrimeroDeLista(Lista* pl, void* elem, size_t tamElem);                      /** probar **/
booleano verUltimoDeLista(Lista* pl, void* elem, size_t tamElem);                      /** probar **/

booleano listaVacia(Lista* pl);                                                         // hecho
booleano listaLlena(Lista* pl, size_t tamElem);                                         // hecho

booleano eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);            // hecho
booleano eliminarDeListaDesord(Lista* pl, void* elem, size_t tamElem, Cmp cmp);         /** probar **/ //
booleano eliminarDeListaPrimero(Lista* pl, void* elem, size_t tamElem);                 /** probar **/ //
booleano eliminarDeListaUltimo(Lista* pl, void* elem, size_t tamElem);                  /** probar **/ //
booleano eliminarDeListaEnPos(Lista* pl, void* elem, size_t tamElem, int pos);          /** probar **/ //

int eliminarDuplicadosDeListaOrd(Lista* pl, Cmp cmp);                                   /** probar **/ //
int eliminarDuplicadosDeListaDesord(Lista* pl, Cmp cmp);                                /** probar **/ //

void ordenarLista(Lista* pl, Cmp cmp);                                                  // hecho
void vaciarLista(Lista* pl);                                                            /** probar **/ //
void recorrerLista(Lista* pl, Accion accion, void* datosAccion);                        /** probar **/

/** iteradorLista **/

booleano crearIterador(Iterador* it, const Lista* pl);                                  // hecho
booleano primeroDeLista(Iterador* it, void* elem, size_t tamElem);                      // hecho
booleano siguienteDeLista(Iterador* it, void* elem, size_t tamElem);                    // hecho
booleano haySiguienteEnLista(Iterador* it);                                             // hecho
booleano finLista(Iterador* it);                                                        // hecho

#endif // TDALISTA_H_INCLUDED
