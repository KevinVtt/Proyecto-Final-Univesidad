#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "preguntas.h"
#include "respuestas.h"

PreguntasPtr cargarPregunta(){

    PreguntasPtr preguntas = (PreguntasPtr)malloc(sizeof(struct Preguntas));

    preguntas->nroPregunta = -1;
    strcpy(preguntas->pregunta,"VACIO");

    return preguntas;

};

void mostrarPregunta(PreguntasPtr pregunta,int t){

    printf("\n-------------------------\n");
    printf("      Nro Pregunta: %d\n",pregunta->nroPregunta);
    printf("      Pregunta: %s\n",pregunta->pregunta);
    printf("-------------------------\n");
    mostrarRespuestas(pregunta->posibles,t);


};

void mostrarPreguntas(PreguntasPtr pregunta[],int t){

    for(int i = 0; i < t; i++){
        int tam = cantidadDeRespuestas(pregunta[i]->nroPregunta);
        mostrarPregunta(pregunta[i],tam);
    }


};

int cantidadPreguntas(char * c){

    FILE * archivo = fopen(c,"r");

    int pos = 0;
    char renglones[100];

    while(!feof(archivo)){

        fgets(renglones,100,archivo);
        pos++;
    }

    fclose(archivo);

    return pos;


}

PreguntasPtr * cargarPreguntasTxt(int t){

    PreguntasPtr * pregunta = malloc(t * sizeof(struct Preguntas));

    FILE * archivo = fopen("preguntas.txt","r");

    int pos = 0;

    while(!feof(archivo)){

        char preg[60];
        int nroPreg;

        fscanf(archivo,"%d",&nroPreg);
        fgets(preg,60,archivo);

        int tam = cantidadDeRespuestas(nroPreg);

        pregunta[pos] = crearPreguntaYRespuestas(nroPreg,preg,tam);

        pos++;

    }

    fclose(archivo);

    return pregunta;

};

void cargarRespuestaTxt(PreguntasPtr pregunta){

    FILE * archivo = fopen("respuestas.txt","r");

    if(archivo == NULL){
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    int pos = 0;
    int tam = cantidadDeRespuestas(pos + 1);
    pregunta->posibles = malloc(tam * sizeof(struct Respuestas));

    while(!feof(archivo)){

        pregunta->posibles[pos] = malloc(sizeof(struct Respuestas));

        fscanf(archivo,"%d#%d,%d\n",&pregunta->posibles[pos]->nroPreguntaAsociada,&pregunta->posibles[pos]->nroRespuesta,&pregunta->posibles[pos]->correcta);
        fgets(pregunta->posibles[pos]->respuestas,40,archivo);
        printf("\nLeyendo: %d,%d,%d,%s", pregunta->posibles[pos]->nroPreguntaAsociada,pregunta->posibles[pos]->nroRespuesta,pregunta->posibles[pos]->correcta,pregunta->posibles[pos]->respuestas);
        //fscanf(archivo, "%d#%d,%d\n", &pregunta->posibles[pos]->nroPreguntaAsociada, &pregunta->posibles[pos]->nroRespuesta, &pregunta->posibles[pos]->correcta);
        //fgets(pregunta->posibles[pos]->respuestas,40,archivo);

        pos++;

    }


    fclose(archivo);

}

PreguntasPtr crearPreguntaYRespuestas(int nroP,char pre[60],int cantResp){

    PreguntasPtr p = (PreguntasPtr)malloc(sizeof(struct Preguntas));

    p->nroPregunta = nroP;

    strcpy(p->pregunta,pre);

    p->posibles = malloc( (cantResp * sizeof(struct Respuestas)));

    cargarRespuestaTxt(p);

    return p;

}

void liberarPregunta(PreguntasPtr pregunta,int t){

    free(pregunta);
    liberarRespuestas(pregunta->posibles,t);

};

void liberarPreguntas(PreguntasPtr pregunta[],int t){

    for(int i = 0; i < t; i++){
        int tam = cantidadDeRespuestas(pregunta[i]->nroPregunta);
        liberarPregunta(pregunta[i],tam);
    }

};
