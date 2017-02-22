#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
	int fd;
	char buf[256];

	pid_t cpid = fork();
	
	switch (cpid){
	case -1:
		perror("Cannot create Child\n");
		return 0;
	case 0:
		break;
	default:
		return 0;	
	}

	if(setsid() == -1){
		perror("Cannot create new session\n");
		return 0;
	} 

	cpid = fork();

        switch (cpid){
        case -1:
                perror("Cannot create Child\n");
                return 0;
        case 0: 
                break;
        default: 
                return 0;
        }

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	fd = get_socket_fd();
	if( fd < 0)return 0;

	memset(buf, 0, sizeof(buf));
	
	while (read(fd,buf, 256)>0){
		write(fd, buf, 256);
		memset(buf,0,sizeof(buf));
	}

	close(fd);



}
