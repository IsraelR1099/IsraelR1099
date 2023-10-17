/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:59:43 by israel            #+#    #+#             */
/*   Updated: 2023/10/17 20:14:16 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"  // Replace with your server's IP address
#define SERVER_PORT 6667
#define BUFFER_LENGTH 250

int main() {
    int sd = -1;
    int rc;
    //char buffer[BUFFER_LENGTH];

    // Create a socket
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket function failed");
        exit(1);
    }
    else
        printf("Socket successfully created..\n");

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to the server
    rc = connect(sd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (rc < 0) {
        perror("connect function failed");
        close(sd);
        exit(1);
    }
    else
        printf("Connected to the server..\n");

    // Now you are connected to the server, you can send and receive data
    // For example, sending a message to the server
 /*   const char* message = "Hello, server!";
    rc = send(sd, message, strlen(message), 0);
    if (rc < 0) {
        perror("send function failed");
        close(sd);
        exit(1);
    }

    // Receiving data from the server
    rc = recv(sd, buffer, sizeof(buffer), 0);
    if (rc < 0) {
        perror("recv function failed");
    } else {
        printf("Received data from the server: %s\n", buffer);
    }*/
    char buffer[1024];
    int n;

    for (;;)
    {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter the string to send to the server: ");
        n = 0;
        while ((buffer[n++] = getchar()) != '\n');
        write(sd, buffer, sizeof(buffer));
        memset(buffer, 0, sizeof(buffer));
        read(sd, buffer, sizeof(buffer));
        printf("From Server: %s", buffer);
        if ((strncmp(buffer, "exit", 4)) == 0)
        {
            printf("Client Exit...\n");
            break;
        }
    }

    // Close the socket
    close(sd);

    return 0;
}

