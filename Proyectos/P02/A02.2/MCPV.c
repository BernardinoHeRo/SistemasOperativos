/*
// ctee.c
// Similar a tee (1). Version con funciones de biblioteca C
///////////////////////////////////////////////////////////
//stdout = 1
//stderr = 2
Ejecución desde terminal ./MCPV < ~/PCL/dev/CO2 > probabilidades 2> errores
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    //apuntador al archivo de probabilidades
    FILE* fdP;
    //apuntador al archivo de errores
    FILE* fdE;

    //Declaración de variables a usar
    int c;
    float calculoProbabilidad;
    char probaChar[4];

    if ((argc > 1)) {
        fprintf(stderr, "Error en argumentos\n");
        exit(1);
    }
    
    //Abrimos fichero de entrada en este caso es el CO2
    //Dicho documento cuenta con una cantidad X de valores entre 0 - 9
    while ((c=getc(stdin)) != EOF) {
        //Conversion de caracter a numero
        int numero = c - 48;

        //Bloque de validación de rango de números entre 0 - 5 
        if(numero >= 0 && numero <= 5){
           
            //Convertimos de entero a flotante numero para usarlo en la división
            float numeroF=numero;

            //Calculamos la probabilidad
            calculoProbabilidad = numeroF/5;

            //Convertimos la probabilidad resultante de float a cadena de caracteres
            //flotante = 0.3 -----> CadenaDeCaracteres = [0][.][3][\0]
            sprintf(probaChar, "%.1f", calculoProbabilidad);
                
            //Ciclo repetitivo para escribir en Salida lo establecido
            /*Aquí escribimos cada uno de los carácteres que tenemos en nuestra cadena     
            En nuestro archivo de salida que en este caso es el de probabilidades
            */
            fdP= fopen(" ", "w+");
            for(int i=0; i<3 ; i++){
                putc(probaChar[i], stdout);
            }
            //Insertamos un salto de línea para diferenciar cuando es una probibilidad distinta
            putc('\n',stdout);
            
       }else{
            //Validación de cuando el número sea inferior a 0
            if(numero < 0){
                //No hace nada
            }else{
                //Aquí entra cuando el numero sea superior a 5
                fdE= fopen(" ", "w+");
                //Escribios directamente al archivo de errores
                putc(c,stderr);
                //Escribimos un salto de linea para organizarlos mejor
                putc('\n',stderr);
            }
        }
    }
    //Cerramos los dos ficheros que abrimos en algún punto de nuestro código
    fclose(fdE);
    fclose(fdP);
}