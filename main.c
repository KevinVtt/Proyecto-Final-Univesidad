#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "preguntas.h"

void menuInicial();

int main()
{

    int opcion;
    int tam;

    tam = cantJugadores();
    JugadorPtr jugador[tam];
    cargarJugadoresTeclado(jugador,tam);
    mostrarJugadores(jugador,tam);
    cargarPreguntasTxt(tam);
    liberarJugadores(jugador,tam);


    /*do{
        menuInicial();
        scanf("%d",&opcion);

        switch(opcion){
        case 1:

            // Luego pedir los datos basicos || cargarJugadorPorTeclado().
            // Inicia el primer jugador -> Se le asigna un puntaje por pregunta correcta, las dificiles tienen mas puntos || Ya mostre los puntos, ahora necesito fijarme si es correcta o no.
            // Al terminar se muestra el puntaje, mostrando al ganador.
            // Las preguntas deben estar en un archivo.txt
            // Las respuestas igual.
            // El puntaje maximo de los jugadores debera estar guardado en un archivo. Se deben consultar desde el menu
            // Si hay empate se juega un desempate con una pregunta matematica el resultado debe estar tipeado.
            break;
        case 2:
            // Mostrar Puntaje maximo.
            //cargarPreguntaTxt(pregunta);
           // mostrarPreguntas(pregunta);
            break;

        case 6:
            printf("Gracias por jugar!!\n");
            break;
        }


    }while(opcion!=6);*/


    return 0;
}

void menuInicial(){

    printf("\n*******************************\n");
    printf("1) Empezar juego\n");
    printf("2) ABM\n");
    printf("6) Salir\n");
    printf("\n*******************************\n");

};
