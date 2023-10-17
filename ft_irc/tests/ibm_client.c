/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 20:44:12 by israel            #+#    #+#             */
/*   Updated: 2023/10/16 20:24:58 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> //inet_addr
#include <string.h>
#include <netdb.h>
#include <limits.h>

#define SERVER_PORT 3005
#define BUFFER_LENGTH 250
#define FALSE 1
#define SERVER_NAME "ServerHostName"

int main(int argc, char **argv)
{
    int sd = -1;
    int rc;
    int bytesReceived;
    char buffer[BUFFER_LENGTH];
    char server[255];
    struct sockaddr_in6 serveraddr;
    struct addrinfo hints;
    struct addrinfo *res;

    while (1)
    {
        sd = socket(AF_INET6, SOCK_STREAM, 0);
        printf("sd es %d\n", sd);
        if (sd < 0)
        {
            perror("socket function failed");
            break ;
        }

        if (argc > 1)
            strcpy(server, argv[1]);
        else
            strcpy(server, SERVER_NAME);
        printf("server es %s\n", server);
        memset(&serveraddr, 0,  sizeof(serveraddr));
        serveraddr.sin6_family = AF_INET6;
        serveraddr.sin6_port = htons(SERVER_PORT);
        rc = inet_pton(AF_INET6, server, &serveraddr.sin6_addr.s6_addr);
        if (rc != 1)
        {
           memset(&hints, 0, sizeof(hints));
          hints.ai_family = AF_INET6;
          hints.ai_flags = AI_V4MAPPED;
          rc = getaddrinfo(server, NULL, &hints, &res);
          printf("rc es %d\n", rc);
          if (rc != 0)
          {
              printf("Host not found! (%s)", server);
              printf("getaddrinfo failed: %s", gai_strerror(rc));
              break ;
          }

          memcpy(&serveraddr.sin6_addr,
                  (&((struct sockaddr_in6 *)(res->ai_addr))->sin6_addr),
                  sizeof(serveraddr.sin6_addr));
          freeaddrinfo(res);

          rc = connect(sd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
          printf("connect OK rc es %d\n", rc);
          if (rc <0)
          {
              perror("connect function failed");
              break ;
          }
          memset(buffer, 'a', sizeof(buffer));
          rc = send(sd, buffer, sizeof(buffer), 0);
          if (rc < 0)
          {
              perror("send function failed");
              break ;
          }

          bytesReceived = 0;
          while (bytesReceived < BUFFER_LENGTH)
          {
            printf("bytesreceived es %d\n", bytesReceived);
              rc = recv(sd, &buffer[bytesReceived],
                    BUFFER_LENGTH - bytesReceived, 0);
              if (rc < 0)
              {
                  perror("recv function failed");
                  break ;
              }
              else if (rc == 0)
              {
                  printf("The server closed the connection");
                  break ;
              }
              bytesReceived += rc;
          }
        }
    }
    if (sd != -1)
        close(sd);
}
