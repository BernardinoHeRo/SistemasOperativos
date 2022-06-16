// ctee.c
// Similar a tee (1). Version con funciones de biblioteca C
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    //Establecemos los vectores 
    //Uno almacena los datos extraidos de encriptación
    //Otro almacena la clave de decifrado
    char cadena_entrada[4];
    char clave[4]="UNSI";
    //Apuntador al fichero de salída 
    FILE* fdEncription;
    //Variable que se usará para la recolección de datos del archivo de entrada
    int c;
    if ((argc != 2)){
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        exit(1);
    }

    if ((fdEncription= fopen(argv[1], "w+")) == NULL) {
        fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);
        exit(2);
    }
    
    int i=0;
    //Mientras no sea final de archivo repetir
    while ((c=getc(stdin)) != EOF) {
        if(c=='\n'){
            i=0;
            /*Codigo de desencriptacion*/
            for (int i = 0; cadena_entrada[i]; ++i){
                cadena_entrada[i]=cadena_entrada[i]^clave[i];
                //Vaciado de datos desencriptados a el archivo de salida
                putc(cadena_entrada[i],fdEncription);
            }
                //Escribimos un salto de linea en el archivo de salida
                putc('\n',fdEncription);

            i=0;
        }else{
            //Llenado de vector con los datos de cada una de las filas
            cadena_entrada[i]=c;
            i++;
        }
    }
    //Cerramos el archivo de salida
    fclose(fdEncription);
}