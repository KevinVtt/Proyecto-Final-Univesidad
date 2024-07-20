#ifndef RESPUESTAS_H_INCLUDED
#define RESPUESTAS_H_INCLUDED

#include "lista.h"

struct Respuestas{

    int nroRespuesta;
    char respuestas[40];
    int nroPreguntaAsociada;
    int correcta;

};

typedef struct Respuestas * RespuestasPtr;

RespuestasPtr cargarRespuestaNulo();
void cargarRespuestasNulas(RespuestasPtr respuesta[],int t);
RespuestasPtr cargarRespuestas(int c,int nPreg,int nroResp,char resp[40]);

void mostrarRespuesta(RespuestasPtr respuesta);
void mostrarRespuestas(RespuestasPtr respuesta[],int t);
void mostrarRespustaLista(Lista lista);
void mostrarRes(Lista listaRes);

void liberarRespuesta(RespuestasPtr respuesta);
void liberarRespuestas(RespuestasPtr respuestas[],int t);

#endif // RESPUESTAS_H_INCLUDED
