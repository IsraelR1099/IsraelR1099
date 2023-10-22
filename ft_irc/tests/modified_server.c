/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modified_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:15:43 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/20 21:53:19 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define SERVER_PORT 6667
#define MAX_CLIENTS 5

int	main(void)
{
	int					fd;
    int                 client_fds[MAX_CLIENTS];
    int                 new_sd = 0;
	int					rc;
    int                 val = 1;
	//int					fd2;
	struct sockaddr_in	server;
    struct pollfd       fds[MAX_CLIENTS + 1];
    nfds_t              nfds = 1;
    char                buffer[1024];

    for (int i = 0; i < MAX_CLIENTS; i++)
        client_fds[i] = -1;
    /*We use socket function to access to a socket descriptor,
     This function will return a socket descriptor if OK or -1 on error.
     AF_INET is the nature of the communication, IPv4 Internet domain.
     The SOCK_STREAM is the type argument and defines the characteristics of the
     communication, in this case TCP. The last argument is the protocol
     argument and it is a 0 because we want the default protocol.*/
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0)
        perror("Socket() failed\n");
    else
        printf("Socket succesfully created...\n");

    /*We control the behavior of the socket by using the setsockopt function.
     * The first argument is the socket descriptor that we want to manipulate,
     * the second argument is the level of the option, and the third argument
     * is the name of the option, in this case SO_REUSEADDR (Reuses addresses
     * in bind function). The fourth argument is a pointer to the value of the
     * option, and the last argument is the size of this value.
     * */
    rc = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    if (rc < 0)
        perror("setsockopt() failed\n");
    else
        printf("setsockopt() succesfully set...\n");
    /*The functions htonl (host to network long) and htons (host to network
     * short) are used to ensure that values are correctly represented in
     * network byte order (big-endian).
     * */
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    /*After using socket function we use the bind function to associate our
     * sockaddr_in structure with this socket descriptor, so after the
     * succesful call to bind our socket descriptor will be associated to the
     * port 6667 and the address INADDR_ANY
     * */
    rc = bind(fd, (struct sockaddr *)&server, sizeof(server));
    if (rc < 0)
        perror("Bind() failed\n");
    else
        printf("Socket succesfully binded\n");
    /*We announce that our server is willing to accept connect requests by
     * calling the listen function. The last argument is the backlog which
     * provides a hint to the system regarding the number of connect requests
     * that it should be enqueue.
     * */
    rc = listen(fd, 5);
    if (rc < 0)
        perror("Listen function failed\n");
    else
        printf("Server listening...\n");

    /*Set up the initial listening socket. The first pollfd in the array is
     * usually reserved for the server socket.*/

    memset(fds, 0, sizeof(fds));
    fds[0].fd = fd;
    fds[0].events = POLLIN;

    while (1)
    {
        rc = poll(fds, nfds, 10000);
        if (rc < 0)
            perror("poll() failed\n");
        else if (rc == 0)
            printf("poll() timed out...\n");
        else
            printf("poll() succesfully set...\n");
        for (int i = 0; i < (int)nfds; i++)
        {
            if (fds[i].revents == 0)
                continue ;
            if (fds[i].revents != POLLIN)
            {
                printf("Error! revents = %d\n", fds[i].revents);
                break;
            }
            if (fds[i].fd == fd)
            {
                printf("Listening socket is readable\n");
                new_sd = accept(fd, NULL, NULL);
                if (new_sd < 0)
                {
                    if (errno != EWOULDBLOCK)
                    {
                        perror("accept() failed\n");
                        new_sd = -1;
                    }
                    break ;
                }
                else
                    printf("Accept succesful...\n");
                printf("New incoming connection - %d\n", new_sd);
                fds[nfds].fd = new_sd;
                fds[nfds].events = POLLIN;
                nfds++;
            }
            else
            {
                printf("Descriptor %d is readable\n", fds[i].fd);
                rc = recv(fds[i].fd, buffer, sizeof(buffer), 0);
                if (rc < 0)
                    perror("recv() failed\n");
                else if (rc == 0)
                {
                   printf("Connection closed\n");
                   break ;
                }
                printf("Client: %s\n", buffer);
                rc = send(fds[i].fd, "Hello World!\n", 13, 0);
                if (rc < 0)
                {
                    perror("send() failed\n");
                    break ;
                }
            }
        }
    }
/* We use accept function to retrieve a connect request and convert it into
     * a connection. The file descriptor returned by accept is a socket
     * descriptor that is connected to the client that called connect. The new
     * socket descriptar has the same socket type and the address family as the
     * original.
     * */
/*    fd2 = accept(fd, NULL, NULL);
    if (fd2 < 0)
        perror("accept function failed\n");
    else
        printf("Server accept the client..\n");

    memset(&fds, 0, sizeof(fds));
    fds[0].fd = fd2;
    fds[0].events = POLLIN | POLLOUT;
    fds[0].revents = 0;

    rc = poll(fds, nfds, 10000);
    if (rc < 0)
        perror("poll() failed\n");
    else if (rc == 0)
        printf("poll() timed out...\n");
    else
        printf("poll() succesfully set...\n");

    memset(&buffer, 0, sizeof(buffer));
    rc = recv(fd2, buffer, sizeof(buffer), 0);
    if (rc < 0)
        perror("rect() failed\n");
    else if (rc == 0)
        printf("Connection closed...\n");
    else
        printf("Message received: %s\n", buffer);

    rc = send(fd2, "Message received", 16, 0);
    if (rc < 0)
        perror("send() failed\n");
    else
        printf("Message sent...\n");*/
/*for (int i = 0; i < MAX_CLIENTS; i++)
        {
            if (client_fds[i] == -1)
            {
                client_fds[i] = accept(fd, NULL, NULL);
                if (client_fds[i] < 0)
                    perror("accept function failed\n");
                else
                {
                    nfds++;
                    fds[nfds - 1].fd = client_fds[i];
                    fds[nfds - 1].events = POLLIN | POLLOUT;
                    printf("Server accept the client..\n");
                }
            }
        }
*/

	close(fd);
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        if (client_fds[i] != -1)
            close(client_fds[i]);
    }
	return (0);
}
