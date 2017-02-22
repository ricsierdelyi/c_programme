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
		printf("GoodBye world\n");
		printf("Haha im a zombiee\n");
		break;
	}
	default:{
		int status;
		pid_t mypid = getpid();
		pid_t ppid = getppid();

		printf("[Parent] PID =%d PPID = %d\n", mypid, ppid);
		printf("I wont wait for my child....\n");
		//waitpid(cpid, &status, WUNTRACED|WCONTINUED);
		//printf("Child executed with status: %d\n", status);
		sleep(20);	

	}
	}	




}
