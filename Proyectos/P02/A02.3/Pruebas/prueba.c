
#include <stdio.h>
int main(){

    // La contraseña a ser encriptada
    char a [] = "0.2"; 
    char b [] = "rec"; // Clave
    
    printf("Contraseña a encriptar : %s\n",a);

    int i;
    // Código de cifrado
    for(i=0;a[i];i++){
         a[i]=a[i]^b[i];
    }
    printf("Your Password is encrypted: %s\n",a);
   

    /* Código de descifrado */
    for(i=0;a[i];i++){
          a[i]=a[i]^b[i];
    }
   

   printf("You Password: %s\n\n",a);
return 0;
}