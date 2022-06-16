// ejecuta.c
// Ejecuta el programa cuyo nombre se especifica como argumento
/////////////////////////////////////////////////////////////////

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    if (argc != 4) {
       fprintf(stderr, "Uso: %s nombre_programa\n", argv[0]);
           exit(1);
   }

    if (execlp(argv[1], argv[1], NULL) == -1)
       fprintf(stderr, "El programa %s no se ha podido ejecutar\n", argv[1]);
    else
       fprintf(stderr, "El programa %s se ha ejecutado\n", argv[1]);

    int x, idh, ret;
    if(x==0){
      execlp("ls","ls","-1",argv[1],NULL);
      perror("No encuentro");
    }else{
      idh = wait(&ret);
      printf("\n idh %d \t ret %d",idh,ret);
    }

}