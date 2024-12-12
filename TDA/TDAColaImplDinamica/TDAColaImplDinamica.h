#ifndef TDACOLAIMPLDINAMICA_H_INCLUDED
#define TDACOLAIMPLDINAMICA_H_INCLUDED

typedef struct SNodo
{
    void* elem;
    size_t tamElem;
    struct SNodo* sig;
}
Nodo;

typedef struct
{
    Nodo* frente;
    Nodo* fondo;
}
Cola;

#endif // TDACOLAIMPLDINAMICA_H_INCLUDED
