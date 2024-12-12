#include <string.h>
#define TDA_COLA_IMPL_ESTATICA

#include "../TDACola/TDACola.h"


void encolarSegmentado (Cola* pc, const void* elem, size_t tamElem);
void desencolarSegmentado (Cola* pc, void* elem, size_t tamElem, size_t tamElemEncolado);
void verFrenteSegmentado (const Cola* pc, void* elem, size_t tamElem, size_t tamElemEncolado);

void crearCola(Cola* pc)
{
    pc->fondo = pc->frente = 0;
    pc->tamDisp = TAM_COLA;
}

booleano encolar(Cola* pc, const void* elem, size_t tamElem)
{
    if(tamElem + sizeof(size_t) > pc->tamDisp)
        return VERDADERO;

    encolarSegmentado(pc, &tamElem, sizeof(size_t));

    encolarSegmentado(pc, elem, tamElem);

    return VERDADERO;
}

void encolarSegmentado (Cola* pc, const void* elem, size_t tamElem)
{
    size_t tamEspacioContiguo;
    size_t cantACopiar1, cantACopiar2;

    if(pc->frente > pc->fondo)
        tamEspacioContiguo = pc->tamDisp;
    else
        tamEspacioContiguo = TAM_COLA - pc->fondo;

    cantACopiar1 = min(tamEspacioContiguo, tamElem);
    cantACopiar2 = tamElem - cantACopiar1;

    memcpy(pc->vec + pc->fondo, elem, cantACopiar1);
    pc->fondo = (pc->fondo + cantACopiar1) % TAM_COLA;

    if(cantACopiar2 > 0)
    {
        memcpy(pc->vec + pc->fondo, elem, cantACopiar2);
        pc->fondo += cantACopiar2;
    }

    pc->tamDisp -= tamElem;
}

booleano desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->tamDisp == TAM_COLA)
        return FALSO;

    size_t tamElemEncolado;

    desencolarSegmentado(pc, &tamElemEncolado, sizeof(size_t), sizeof(size_t));

    desencolarSegmentado(pc, elem, tamElem, tamElemEncolado);

    return VERDADERO;
}

void desencolarSegmentado (Cola* pc, void* elem, size_t tamElem, size_t tamElemEncolado)
{
    size_t tamDatoContiguo;
    size_t cantACopiar, cantACopiar1, cantACopiar2;

    cantACopiar = min(tamElem, tamElemEncolado);

    if(pc->frente > pc->fondo) // puede llegar a estar cortado
        tamDatoContiguo = min(tamElemEncolado, TAM_COLA - pc->frente);
    else // todo junto
        tamDatoContiguo = tamElemEncolado;

    cantACopiar1 = min(cantACopiar, tamDatoContiguo);
    cantACopiar2 = cantACopiar - cantACopiar1;

    memcpy(elem, pc->vec + pc->frente, cantACopiar1);
    pc->frente = (pc->frente + tamDatoContiguo) % TAM_COLA;

    if(cantACopiar2 > 0)
        memcpy(elem + cantACopiar1, pc->frente + pc->vec, cantACopiar2);

    pc->frente += tamElemEncolado - tamDatoContiguo;
    pc->tamDisp += tamElemEncolado;
}

booleano verFrenteDeCola(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->tamDisp == TAM_COLA)
        return FALSO;

    unsigned frente = pc->frente;
    size_t tamElemEncolado;

    desencolarSegmentado(pc, &tamElemEncolado, sizeof(size_t), sizeof(size_t));
    pc->tamDisp -= sizeof(size_t);
    verFrenteSegmentado(pc, elem, tamElem, tamElemEncolado);

    pc->frente = frente;

    return VERDADERO;
}

void verFrenteSegmentado (const Cola* pc, void* elem, size_t tamElem, size_t tamElemEncolado)
{
    size_t tamDatoContiguo;
    size_t cantACopiar, cantACopiar1, cantAcopiar2;
    unsigned frente = pc->frente;

    cantACopiar = min(tamElem, tamElemEncolado);

    if(frente > pc->fondo)
        tamDatoContiguo = min(tamElemEncolado, TAM_COLA - frente);
    else
        tamDatoContiguo = tamElemEncolado;

    cantACopiar1 = min(cantACopiar, tamDatoContiguo);
    cantAcopiar2 = cantACopiar - cantACopiar1;

    memcpy(elem, pc->vec + frente, cantACopiar1);
    frente = (frente + tamDatoContiguo) % TAM_COLA;

    if(cantAcopiar2 > 0)
        memcpy(elem + cantACopiar1, pc->vec + frente, cantAcopiar2);
}

booleano colaVacia(Cola* pc)
{
    return pc->tamDisp == TAM_COLA;
}

booleano colaLlena(Cola* pc, size_t tamElem)
{
    return tamElem + sizeof(size_t) > pc->tamDisp;
}

void vaciarCola(Cola* pc)
{
    pc->tamDisp = TAM_COLA;
    pc->fondo = 0;
    pc->frente = 0;
}
