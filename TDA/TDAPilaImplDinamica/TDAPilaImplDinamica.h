#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef struct SNodo
{
    void* elem;
    size_t tamElem;
    struct SNodo* sig;
}
Nodo;

typedef Nodo* Pila;

#endif // PILADINAMICA_H_INCLUDED
