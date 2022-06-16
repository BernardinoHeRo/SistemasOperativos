#include <unistd.h>
#include <stdio.h>

int var = 22;

int main(void){

	pid_t pidC;
	
	printf("** proc. PID = %d comienza **\n",getpid());
	
	pidC = fork();

	printf("** proc. PID = %d , pidC = %d ejecutandose **",getpid(),pidC);

	if(pidC > 0){
		var = 44;
	}else{
		if(pidC == 0){
			var = 33;
		}else{
			printf("Error\n");
		}
	}

	printf("\n");
	while(1){
		sleep(1);
		printf("\n** proc. PID = %d , var = %d ejecutandose **",getpid(),var );
	}

	return 0;
}