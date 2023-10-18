/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:15:43 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/18 12:53:42 by irifarac         ###   ########.fr       */
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

#define SERVER_PORT 6667

int	main(void)
{
	int					fd;
	int					rc;
	int					fd2;
	struct sockaddr_in	server;

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

	/* We use accept function to retrieve a connect request and convert it into
	 * a connection. The file descriptor returned by accept is a socket
	 * descriptor that is connected to the client that called connect. The new
	 * socket descriptar has the same socket type and the address family as the
	 * original.
	 * */
	fd2 = accept(fd, NULL, NULL);
	if (fd2 < 0)
		perror("accept function failed\n");
	else
		printf("Server accept the client..\n");

	char	buffer[1024];
	int		n;

	for (;;)
	{
		memset(buffer, 0, sizeof(buffer));
		read(fd2, buffer, sizeof(buffer));
		printf("From client: %s\nTo client: ", buffer);
		memset(buffer, 0, sizeof(buffer));
		n = 0;
		while ((buffer[n++] = getchar()) != '\n')
			;
		write(fd2, buffer, sizeof(buffer));
	}
	close(fd);
	close(fd2);
	return (0);
}
