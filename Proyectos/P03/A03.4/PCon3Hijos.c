//Padre con 3 hijos
//Papa con 3 hijos y cada hijo tiene 2
#include <stdio.h>
#include <unistd.h>
main(void)
{
 pid_t pid;
 int x,y;
 
 for(x=1;x<=3;x++)
 {
  
  pid=fork(); 
  if(pid)
  {
   printf("Soy el proceso %d : %p\n",getpid(),&pid);
   sleep(2);
  }

  else
  {
   printf("soy el hijo %d : %p, mi padre es %d : %p\n",getpid(),&pid,getppid(),&pid);
   sleep(2);
   for(y=1;y<=2;y++)
   {
    pid=fork();
     if(pid)
     {
      printf("Soy el proceso %d : %p\n",getpid(),&pid);
      sleep(2);
     }
     else
     {
      printf("soy el hijo %d : %p, mi padre es %d : p\n",getpid(),&pid,getppid(),&pid);
      sleep(2);
      exit(0);
     }
   }
   exit(0);
  }
  
 }
 return 0;
}