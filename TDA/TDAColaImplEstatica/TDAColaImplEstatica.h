#ifndef TDACOLAIMPLESTATICA_H_INCLUDED
#define TDACOLAIMPLESTATICA_H_INCLUDED

#include <stddef.h>

#define TAM_COLA    1000

typedef struct
{
    char vec[TAM_COLA];
    unsigned frente;
    unsigned fondo;
    size_t tamDisp;
}
Cola;

#endif // TDACOLAIMPLESTATICA_H_INCLUDED
