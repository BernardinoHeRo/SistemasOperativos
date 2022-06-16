// procesos.c
// Prueba de procesos.
/////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, const char * argv[]) {
    int id, i;
    char dato= '0';
    char mensaje[80];

    srandom(time(NULL));  // Para mayor aleatoriedad en las ejecuciones.

    /*sprintf() --> Crea una cadena de texto a partir de varios datos, siguiendo un cierto código de formato. 
    Si no se indican suficientes argumentos para completar los códigos de formato, 
    el resultado es indeterminado. Devuelve el número de caracteres escritos.*/

    /*getpid() --> Cuando se forma algún proceso y se está ejecutando, se le asigna una identificación 
    única. Este es el ID del proceso. Esta función ayuda a devolver la identificación del 
    proceso que se llama actualmente.*/
    sprintf(mensaje, "--Punto 0 \t_ PID  >>> %d: dato= %c    %d:   \t%p\n", getpid(), dato,id,&id);
    write(1, mensaje, strlen(mensaje));
    
    /*fork() --> se utiliza para crear un nuevo proceso que represente la duplicación del 
    proceso de la persona que llama. Tenga en cuenta que el proceso de llamada se denomina 
    convencionalmente proceso padre y uno recién creado, proceso hijo.*/
    switch (id= fork()) {
      case -1:

      /*C funciones de bibliotecavacío perror (const char * str) a un mensaje de error 
      descriptivo de salida a stderr error estándar.En primer lugar, la cadenastr de salida, 
      seguido de dos puntos, seguido de un espacio.*/
        perror("fork");
        exit(1);
      case 0:
        sleep(100);
        sprintf(mensaje, "--Punto 1 \t_ PID  >>> %d: dato= %c    %d:   \t%p\n", getpid(), dato,id,&id);
        write(1, mensaje, strlen(mensaje));
        dato= 'a';
        for (i=0; i<5; i++) {
           sleep(100);
           sprintf(mensaje, "--Punto 2.%d \t_ PID  >>> %d: dato= %c    %d:   \t%p\n", i, getpid(), dato,id,&id);
           write(1, mensaje, strlen(mensaje));
           dato++;
        }
        break;
      default:
      //random()%5
        sleep(100);
        sprintf(mensaje, "--Punto 3 \t_ PID  >>> %d: dato= %c    %d:   \t%p\n", getpid(), dato,id,&id);
        write(1, mensaje, strlen(mensaje));
        dato= 'A';
        for (i=0; i<5; i++) {
           sleep(100);
           sprintf(mensaje, "--Punto 4.%d \t_ PID  >>> %d: dato= %c    %d:   \t%p\n", i, getpid(), dato,id,&id);
           write(1, mensaje, strlen(mensaje));
           dato++;
           printf("\n\n\n");
        }
    }
    sprintf(mensaje, "--Punto 5 \t_ PID  >>> %d: dato= %c    %d:   \t%p\n", getpid(), dato,id,&id);
    write(1, mensaje, strlen(mensaje));
    exit(0);
}