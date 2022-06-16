// ctee.c
// Similar a tee (1). Version con funciones de biblioteca C
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    //Apuntador al fichero de salída 
    FILE* fdEncription;

    //Variable que se usará para la recolección de datos del archivo de entrada
    int c;
    
    if ((argc != 2)) {
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        //Salida anormal del programa
        exit(1);
    }
    
    if ((fdEncription= fopen(argv[1], "w+")) == NULL) {
        fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);

        exit(2);
    }

    
    char cadena_entrada[4];
    //Inicio de contador de caracteres en el archivo por fila
    int i=0;
    //Mientras el archivo tenga datos leera cada uno de los caracteres dentro del archivo ingresado "probabilidades"
    while ((c=getc(stdin)) != EOF) {
        //Si encontramos un salto de línea 
        if(c=='\n'){
            //Reseteamos contador de caracteres
            i=0;
            //Declaramos la clave que usaremos para encriptar nuestros datos de probabilidades
            char clave[4] = "UNSI";
            //Algoritmo XOR de encriptación
            for(i=0;cadena_entrada[i];i++){
                cadena_entrada[i]=cadena_entrada[i]^clave[i];
                //Tranferencia de datos ya encriptador a los archivos de salída
                putc(cadena_entrada[i], fdEncription);
                //putc(cadena_entrada[i], stdout);
            }
                //Transferencia de salto de linea en cada uno de los archivos de salida
                //putc('\n', stdout);
                putc('\n',fdEncription);
            //Reset de i nuevamente para saltar a otra linea en iniciar a leer
            i=0;
        }else{
            //Asignación de cada uno de los caracteres encontrados durante la lectura al verctor
            //cadena_entrada lleva los valores de cada uno de los caracteres encontrados
            cadena_entrada[i]=c;
            //Aumento de contador que lleva el control de cuantos caracteres leemos
            i++;
        }
    }
    //Cerramos archivo
    fclose(fdEncription);
}