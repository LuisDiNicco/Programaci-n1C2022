#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED

#include <stdlib.h>

#define TODO_OK          0
#define SIN_MEM          1
#define DUPLICADO        2
#define NO_ENCONTRADO   -1
#define ERR_ARCHIVO      3

typedef enum
{
    FALSO, VERDADERO // falso = 0 y Verdaero = 1
}
booleano;

#define min(x, y) ((x) < (y) ? (x) : (y)) // macro de la funcion minimo
#define abs(x) ((x) < 0 ? (x)*(-1) : (x))

typedef int(*Cmp)(const void*, const void*);
typedef int(*Accion)(void* elem, void* datosAccion);
typedef int(*Actualizar)(void*, const void*);


#endif // COMUN_H_INCLUDED
