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
    //argc != 2
    if ((argc != 2)) {
        fprintf(stderr, "Uso: %s fichero_salida\n", argv[0]);
        exit(1);
    }
    //@argv[1] : Primer parametro de fopen, no se usa momentaneamente por fallos en el compilador de gcc de linux
    if ((fdEncription= fopen(argv[1], "w+")) == NULL) {
        fprintf(stderr, "No se puede abrir para escritura en %s\n", argv[1]);
        exit(2);
    }

    
    char cadena_entrada[4];
    int i=0;
    //printf("\n\n\n");
    while ((c=getc(stdin)) != EOF) {
        
        if(c=='\n'){
            //cadena_entrada[3]='\0';
            i=0;
            //printf("\n\t\tSalida : %s\n",cadena_entrada);
            char clave[4] = "UNSI";
            for(i=0;cadena_entrada[i];i++){
                cadena_entrada[i]=cadena_entrada[i]^clave[i];
                putc(cadena_entrada[i], fdEncription);
                putc(cadena_entrada[i], stdout);
            }
                putc('\n', stdout);
                putc('\n',fdEncription);
            //printf("\n\tLa encriptacion queda así: %s\n",cadena_entrada);    
            
            
            /*Codigo de desencriptacion*/
            /*
            for (int i = 0; cadena_entrada[i]; ++i){
                cadena_entrada[i]=cadena_entrada[i]^clave[i];
            }
            printf("\n\tLa entrada principal desencriptada es : %s",cadena_entrada);
            */

            //Conversión de cadena a flotante
            //float valor= atof(cadena_entrada);
            //printf("\n\t\tFlotante: %f \n\n\n\n",valor);
            
            //Código encriptacón

            i=0;
        }else{
            cadena_entrada[i]=c;
            i++;
        }
        
        
        //putc(c, stdout);
        //putc(c, fdEncription);
        //usleep(10000);
    }
    //printf("\n");
    fclose(fdEncription);
}