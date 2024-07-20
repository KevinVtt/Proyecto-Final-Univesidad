#ifndef PREGUNTAS_H_INCLUDED
#define PREGUNTAS_H_INCLUDED

#include "respuestas.h"

struct Preguntas{

    int nroPregunta;
    char pregunta[60];
    RespuestasPtr * posibles;

};

typedef struct Preguntas * PreguntasPtr;

PreguntasPtr cargarPregunta();

// Funciones para mostrar las preguntas
void mostrarPregunta(PreguntasPtr pregunta,int t);
void mostrarPreguntas(PreguntasPtr pregunta[],int t);

// Funciones con Archivos
int cantidadPreguntas(char * c);
PreguntasPtr * cargarPreguntasTxt(int t);
PreguntasPtr crearPreguntaYRespuestas(int nroP,char p[60],int cantResp);
void cargarRespuestaTxt(PreguntasPtr pregunta);

void liberarPregunta(PreguntasPtr pregunta,int t);
void liberarPreguntas(PreguntasPtr pregunta[],int t);

#endif // PREGUNTAS_H_INCLUDED
