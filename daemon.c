#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 3334

volatile sig_atomic_t term_flag = 0;

int get_socket_fd(void)
{
    int listen_fd, con_fd;
    struct sockaddr_in addr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1)
    {
        perror("Cannot create socket\n");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(SERVER_PORT);

    if (bind(listen_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        perror("Cannot bind\n");
        return -1;
    }

    if (listen(listen_fd, 10) < 0)
    {
        perror("Cannot listen\n");
        return -1;
    }

    printf("[Server] Waiting for connections.\n");

    for (;;)
    {
        con_fd = accept(listen_fd, NULL, NULL);
        if (con_fd == -1)
            continue;
        else
        {
            close(listen_fd);
            return con_fd;
        }
    }
}

void create_daemon(void)
{
    /* INSERT CODE IN HERE */
}

int main(int argc, char *argv[])
{
    create_daemon();

    return EXIT_SUCCESS;
}
