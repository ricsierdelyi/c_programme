#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){

	pid_t cpid = fork();
	
	switch (cpid){
	case -1:
		perror("Cannot create Child\n");
		break;
	case 0:{
		pid_t mypid = getpid();
		pid_t ppid = getppid();
		
		printf("[Child] PID = %d PPID = %d\n",mypid, ppid);
		sleep(1);
		printf("GoodBYEEEEE\n");
		break;
	}
	default:{
		int status;
		pid_t mypid = getpid();
		pid_t ppid = getppid();

		printf("[Parent] PID =%d PPID = %d\n", mypid, ppid);
		printf("Waiting for my child with PID=%d",cpid);
		waitpid(cpid, &status, WUNTRACED|WCONTINUED);
		printf("Child executed with status: %d\n", status);
	
	}
	}	




}
