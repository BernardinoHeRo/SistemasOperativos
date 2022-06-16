#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CHILD 5

int doSomething(void){
	
	int ret;
	
	srand(getpid());	
	ret = (rand()%256);
	printf("\tHIJO: PID = %d,\tvalor aleatorio calculado %d\n",getpid(),ret);
	
	return ret;
}

int main (void){

	pid_t pidC;
	int status;

	for (int i = 0; i < NUM_CHILD; ++i){
		pidC = fork();

		if(pidC > 0){
			continue;
		}else{
			if(pidC == 0){
				exit(doSomething());
			}else{
				/*error*/
			}
		}
	}

	for (int i = 0; i < NUM_CHILD; ++i){

		pidC = wait(&status);
		printf("PADRE de PID = %d,\thijo de PID = %d terminado,\tst = %d\n",getpid(),pidC,WEXITSTATUS(status));

	}

	while(1){
		sleep(10);
	}

	return 0;
}