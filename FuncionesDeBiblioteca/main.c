#include <stdio.h>
#include <stdlib.h>

void* memcpy_alu(void* dest, const void* orig, size_t cant);
char* strcat_alu(char* dest, const char* orig);
char* strchr_alu(const char* cad, int car);
char* strrchr_alu(const char* cad, int car);
int strcmp_alu(const char* cad1, const char* cad2);
char* strcpy_alu(char* dest, const char* orig);
size_t strlen_alu(const char* cad);

typedef struct
{
    int dni;
    char nombre[30];
}
Persona;

#define caracterABin(c)((c) - '0')
#define numeroACaracter(n)((n) + '0')

#define ES_MINUSC(c)((c) >= 'a' && (c) <= 'z')
#define ES_MAYUSC(c)((c) >= 'A' && (c) <= 'Z')

#define A_MAYUSC(c)(ES_MINUSC(c) ? (c) + 'A' - 'a' : (c))
#define A_MINUSC(c)(ES_MAYUSC(c) ? (c) + 'a' - 'A' : (c))

int main()
{
    Persona p1 = {11222333, "Juan Rodriguez"};
    Persona p2, p3;

    puts("Persona 1: ");
    printf("%d y %s\n\n", p1.dni, p1.nombre);

    memcpy_alu(&p2, &p1, sizeof(Persona));
    strcat_alu(p2.nombre, p1.nombre);

    puts("Persona 2: ");
    printf("%d y %s", p2.dni, p2.nombre);

    char* letras = strchr_alu(p2.nombre,'i');
    printf("\n%s\n", letras);

    int comp = strcmp_alu(p1.nombre, p2.nombre);

    if(comp > 0)
        printf("%s es mas grande\n", p1.nombre);
    else
        printf("%s es mas grande\n", p2.nombre);

    strcpy_alu(p3.nombre, p1.nombre);
    p3.dni = 2;
    puts("Persona 3: ");
    printf("%d y %s", p3.dni, p3.nombre);

    return 0;
}

void* memcpy_alu(void* dest, const void* orig, size_t cant)
{
    /*void* aux = dest;
    while(cant--)
        *((char*)dest)++ = *((char)orig)++;

    return aux;*/
    void* aux = dest;
    char* destino = (char*)dest;
    char* origen = (char*)orig;

    while(cant > 0)
    {
        *destino = *origen;
        destino ++;
        origen ++;

        cant --;
    }
    return aux;
}

char* strcat_alu(char* dest, const char* orig)
{
    char* aux = dest;

    while(*dest)
        dest ++;

    while(*orig)
    {
        *dest = *orig;
        dest ++,
        orig ++;
    }
    return aux;
}

char* strchr_alu(const char* cad, int car)
{
    while(*cad && *(char*)cad != (char)car)
        cad ++;

    if(*(char*)cad == (char)car)
        return (char*)cad;
    else
        return NULL;
}

char* strrchr_alu(const char* cad, int car)
{
    char* aux  = (char*)cad;
    while(*aux)
        aux++;
    while(aux > cad && *aux != car)
        aux --;

    return *aux == car ? aux : NULL;
}

int strcmp_alu(const char* cad1, const char* cad2)
{
    while(*cad1 && *cad1 == *cad2)
    {
        cad1 ++;
        cad2 ++;
    }

    return (int)(unsigned char)*cad1 - (int)(unsigned char)*cad2;
}

char* strcpy_alu(char* dest, const char* orig)
{
    char* aux = dest;
    while(*orig)
    {
        *dest = *orig;
        dest ++;
        orig ++;
    }

    return aux;
}

size_t strlen_alu(const char* cad)
{
    size_t cont = 0;
    while(*cad)
    {
        cont ++;
        cad ++;
    }

    return cont;
}

