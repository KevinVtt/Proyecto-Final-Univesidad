#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "respuestas.h"

RespuestasPtr cargarRespuestaNulo(){

    RespuestasPtr respuestas = (RespuestasPtr)malloc(sizeof(struct Respuestas));

    respuestas->correcta = -1;

    respuestas->nroPreguntaAsociada = -1;

    respuestas->nroRespuesta = -1;

    strcpy(respuestas->respuestas,"VACIO");

    return respuestas;

};

RespuestasPtr cargarRespuestas(int cor,int nPreg,int nroResp,char resp[40]){

    RespuestasPtr respuestas = (RespuestasPtr)malloc(sizeof(struct Respuestas));

    respuestas->correcta = cor;

    respuestas->nroPreguntaAsociada = nPreg;

    respuestas->nroRespuesta = nroResp;

    strcpy(respuestas->respuestas,resp);

    return respuestas;

}

void mostrarRespuesta(RespuestasPtr respuesta) {
    printf("\n---------- RESPUESTAS ----------\n");
    printf(" Número de Pregunta Asociada: %d\n", respuesta->nroPreguntaAsociada);
    printf(" Número de Respuesta: %d\n", respuesta->nroRespuesta);
    printf(" Respuesta: %s\n", respuesta->respuestas);
    printf("--------------------------------\n");
}



void mostrarRespuestas(RespuestasPtr respuesta[], int t){

    for(int i = 0; i < t; i++){
        mostrarRespuesta(respuesta[i]);
    }

};

int cantidadDeRespuestas(int cod){

    FILE * archivo = fopen("respuestas.txt","r");

    int pos = 0;

    while(!feof(archivo)){

        int nroResp;
        char resp[40];
        int nroPreguntaAso;
        int correct;

        fscanf(archivo,"%d#%d,%d\n",&nroPreguntaAso,&nroResp,&correct);
        fgets(resp,40,archivo);

        if(nroPreguntaAso == cod){
            pos++;
        }

    }

    fclose(archivo);

    return pos;

}

void liberarRespuesta(RespuestasPtr respuesta){

    free(respuesta);

};

void liberarRespuestas(RespuestasPtr respuestas[],int t){

    for(int i = 0; i < t; i++){
        free(respuestas[i]);
    }

};
