/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:02:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/25 12:34:05 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.hpp"

int	Server::acceptClient(int nfds)
{
	int				new_fd;
	struct pollfd	new_client;

	new_fd = accept(m_fds[0].fd, NULL, NULL);
	if (new_fd < 0)
		return (-1);
	m_fds[nfds].fd = new_fd;
	m_fds[nfds].events = POLLIN;
	return (0);
}

void	Server::receiveClient(int i)
{
	int	rc;
	char	buffer[1024];

	memset(buffer, 0, sizeof(buffer));
	rc = recv(fd.fd, buffer, sizeof(buffer), 0);
	if (rc < 0)
		throw Server::ServerError("recv() failed");
	else if (rc == 0)
		throw Server::ServerError("Connection closed");
	std::cout << "Client: " << buffer << std::endl;
}
