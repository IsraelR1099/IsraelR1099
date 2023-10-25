/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:02:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/25 10:31:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

int	Server::acceptClient(std::vector<pollfd> fds, int nfds)
{
	int	new_fd;

	new_fd = accept(fds[0].fd, NULL, NULL);
	if (new_fd < 0)
		return (-1);
	fds[nfds].fd = new_fd;
	fds[nfds].events = POLLIN;
	return (0);
}

void	Server::receiveClient(struct pollfd fd)
{
	int	rc;
	char	buffer[1024];

	memset(buffer, 0, sizeof(buffer));
	rc = recv(fd, buffer, sizeof(buffer));
	if (rc < 0)
		throw Server::ServerError("recv() failed");
	else if (rc == 0)
		throw Server::ServerError("Connection closed");
	std::cout << "Client: " << buffer << std::endl;
}
