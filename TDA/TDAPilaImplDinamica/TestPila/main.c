#include <stdio.h>
#include <stdlib.h>

#define TDA_PILA_IMPL_DINAMICA

#include "../Pila/Pila.h"

typedef struct
{
    int dni;
    char nombre[30];
}
Persona;

int main()
{
    Pila pila1;
    Persona ptope, p3;

    Persona p1 = {11222333, "Juan Perez"};
    Persona p2 = {44555666, "Juana Perez"};
    Persona p4 = {55666777, "Miguel Perez"};
    Persona p5 = {88999111, "Rocio Perez"};

    crearPila(&pila1);

    if(verTopeDePila(&pila1, &ptope, sizeof(Persona)))
        printf("La persona que estaba en el tope es: [dni: %d y nombre: %s]\n", ptope.dni, ptope.nombre);
    else
        puts("Pila Vacia");

    apilar(&pila1, &p1, sizeof(Persona));
    apilar(&pila1, &p2, sizeof(Persona));

    verTopeDePila(&pila1, &ptope, sizeof(Persona));
    printf("La persona que estaba en el tope es: [dni: %d y nombre: %s]\n", ptope.dni, ptope.nombre);

    desapilar(&pila1, &p3, sizeof(Persona));

    verTopeDePila(&pila1, &ptope, sizeof(Persona));
    printf("La persona que esta en el tope despues de desapilar a la anterior es: [dni: %d y nombre: %s]\n", ptope.dni, ptope.nombre);

    desapilar(&pila1, &p3, sizeof(Persona));
    printf("La persona que desapile es: [dni: %d y nombre: %s]\n", p3.dni, p3.nombre);

    if(pilaVacia(&pila1))
        puts("Pila Vacia");
    else
        puts("Pila con algo");

    apilar(&pila1, &p3, sizeof(Persona));
    apilar(&pila1, &p4, sizeof(Persona));
    apilar(&pila1, &p5, sizeof(Persona));

    if(pilaVacia(&pila1))
        puts("Pila Vacia");
    else
        puts("Pila con algo");

    vaciarPila(&pila1);

    if(pilaVacia(&pila1))
        puts("Pila Vacia");
    else
        puts("Pila con algo");

    return 0;
}
