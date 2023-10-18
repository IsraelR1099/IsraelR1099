/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:14:55 by israel            #+#    #+#             */
/*   Updated: 2023/10/18 13:17:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <netinet/in.h>
#include <string.h>

#define SERVER_PORT 6667
#define BUFFER_LENGTH 250
#define FALSE 1

int main(void)
{
    int sd = -1;
    int sd2 = -1;
    int rc;
    //int length;
    int on = 1;
    //char    buffer[BUFFER_LENGTH];
    //struct pollfd fds;
    //nfds_t nfds = 1;
    //int timeout;
    struct sockaddr_in server_addr;

    printf("Server is starting up...\n");
    while (1)
    {
        sd = socket(AF_INET, SOCK_STREAM, 0);
        if (sd < 0)
        {
            perror("socket function failed");
            break;
        }
        else
            printf("Socket successfully created\n");
        rc = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
        if (rc < 0)
        {
            perror("setsockopt(SO_REUSEADDR failed");
            break;
        }
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        rc = bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (rc < 0)
        {
            perror("bind function failed");
            break ;

        }
        else
            printf("Socket successfully binded\n");

        rc = listen(sd, 5);
        if (rc < 0)
        {
            perror("listen function failed");
            break ;
        }
        else
            printf("Server listening...\n");
        sd2 = accept(sd, NULL, NULL);
        if (sd2 < 0)
        {
            perror("accept function failed");
            break ;
        }
        else
            printf("Server accept the client...\n");

       /* timeout = (30 * 1000);
        memset(&fds, 0, sizeof(fds));
        fds.fd = sd2;
        fds.events = POLLIN;
        fds.revents = 0;

        rc = poll(&fds, nfds, timeout);
        if (rc < 0)
        {
            perror("poll function failed");
            break ;
        }
        if (rc == 0)
        {
            printf("poll function timeout.");
            break ;
        }

		if (fds.revents & POLLIN)
			printf("Writeable\n");

        length = BUFFER_LENGTH;
        rc = setsockopt(sd2, SOL_SOCKET, SO_RCVLOWAT, (char *)&length, sizeof(length));
        if (rc < 0)
        {
            perror("setsockopt function failed");
            break ;
        }
        rc = recv(sd2, buffer, sizeof(buffer), 0);
        if (rc < 0)
        {
            perror("recv function failed");
            break ;
        }

        printf("recv() returned: %d\n", rc);
        if (rc == 0 || rc < (int)sizeof(buffer))
        {
            printf("The client closed the connection before all of the data was sent\n");
            break;
        }

        rc = send(sd2, buffer, sizeof(buffer), 0);
        if (rc < 0)
        {
            perror("send function failed");
            break ;
        }*/
        char buffer[1024];
        int n;

        for (;;)
        {
            memset(buffer, 0, 1024);
            read(sd2, buffer, (sizeof(buffer) -1));
            printf("From client: %s\n To client : ", buffer);
            memset(buffer, 0, 1024);
            n = 0;
            while ((buffer[n++] = getchar()) != '\n')
                ;
            write(sd2, buffer, sizeof(buffer));

            if (strncmp("exit", buffer, 4) == 0)
            {
                printf("Server Exit...\n");
                break;
            }
        }
    }
    if (sd != -1)
        close(sd);
    if (sd2 != -1)
        close(sd2);
    return (0);
}
