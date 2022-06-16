#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int spawn (char* program, char** arg_list){
  pid_t child_pid;
  /* Duplicar este proceso. */
  child_pid = fork ();
  if (child_pid != 0)
    /* Este es el proceso principal. */
    return child_pid;
  else {
    /* Ahora ejecuta PROGRAM, buscandolo en la ruta. */
    execvp (program, arg_list);
    /* La funcion execvp regresa solo si ocurre un error. */
    fprintf (stderr, "an error occurred in execvp\n");
    abort ();
  }
}

int main (){
  /* Lista de argumentos para pasar al comando "ls".  */
  char* arg_list[] = {
    "ls",     /* argv[0], el nombre del programa.  */
    "-l", 
    "/",
    NULL      /* La lista de argumentos debe terminal en NULL.  */
  };
  /* Genera un proceso secundario que ejecuta el comando "ls". 
  Ignora el ID del proceso secundario devuelto.  */
  spawn ("ls", arg_list); 
  printf ("Hecho con el programa principal. \n");
  exit(0);
  return 0;
}
