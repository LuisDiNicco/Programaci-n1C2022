#ifndef TDAPILA_H_INCLUDED
#define TDAPILA_H_INCLUDED

#include "../Comun/Comun.h"

#ifdef TDA_PILA_IMPL_ESTATICA
    #include "../TDAPilaImplEstatica/TDAPilaImplEstatica.h"
#endif // PILA_IMPL_ESTATICA

#ifdef TDA_PILA_IMPL_DINAMICA
        #include"../TDAPilaImplDinamica/TDAPilaImplDinamica.h"
#endif // TDA_PILA_IMPL_DINAMICA

void crearPila(Pila* pp);
booleano apilar(Pila* pp, const void* elem, size_t tamElem);
booleano desapilar(Pila* pp, void* elem, size_t tamElem);
booleano verTopeDePila(const Pila* pp, void* elem, size_t tamElem);
booleano pilaVacia(const Pila* pp);
booleano pilaLlena(const Pila* pp, size_t tamElem);
void vaciarPila(Pila* pp);

#endif // TDAPILA_H_INCLUDED
