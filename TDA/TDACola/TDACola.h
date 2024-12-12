#ifndef TDACOLA_H_INCLUDED
#define TDACOLA_H_INCLUDED

#include <stddef.h>
#include "../Comun/Comun.h"

#ifdef TDA_COLA_IMPL_ESTATICA
    #include "../TDAColaImplEstatica/TDAColaImplEstatica.h"
#endif // TDA_COLA_IMPL_ESTATICA

#ifdef TDA_COLA_IMPL_DINAMICA
    #include "../TDAColaImplDinamica/TDAColaImplDinamica.h"
#endif // TDA_COLA_IMPL_DINAMICA

#ifdef TDA_COLA_IMPL_DINAMICA_CIRCULAR
    #include "../TDAColaImplDinamicaCircular/TDAColaImplDinamicaCircular.h"
#endif // TDA_COLA_IMPL_DINAMICA

void crearCola(Cola* pc);
booleano encolar(Cola* pc, const void* elem, size_t tamElem);
booleano desencolar(Cola* pc, void* elem, size_t tamElem);
booleano verFrenteDeCola(Cola* pc, void* elem, size_t tamElem);
booleano colaVacia(Cola* pc);
booleano colaLlena(Cola* pc, size_t tamElem);
void vaciarCola(Cola* pc);

#endif // TDACOLA_H_INCLUDED
