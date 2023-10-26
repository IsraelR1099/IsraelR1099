/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:29:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/26 20:49:22 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

# include <sys/time.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/poll.h>
# include <poll.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <exception>
# include <string>
# include <iostream>
# include <stdbool.h>
# include <cstring>
# include <cstdlib>
# include <vector>
# include <map>
# include "./Client.hpp"

#define MAX_CLIENTS 5

class	Server
{
	public:
		Server(void);
		Server(char **argv);
		~Server(void);

		void	setServer(void);
        int     launchServer(void);
		int		acceptClient(int nfds);
		void	receiveClient(int i);

	class	BadFormat : public std::exception
	{
		public:
			BadFormat(const std::string &m_msg) : error(m_msg) {}
			virtual const char *what() const throw()
			{
				return (error.c_str());
			}
			~BadFormat() throw() {}
		private:
			std::string	error;
	};

    class   ServerError : public std::exception
    {
        public:
            ServerError(const std::string &m_msg) : error(m_msg) {}
            virtual const char *what() const throw()
            {
                return (error.c_str());
            }
            ~ServerError() throw() {}
        private:
            std::string error;
    };
	private:
		bool				m_g_run_server;
		unsigned int		m_port;
		std::string			m_password;
		int					m_fd_server;
		struct sockaddr_in	server;
		struct pollfd		m_fds[MAX_CLIENTS + 1];
        std::map<int, Client> _clients;
        void                _parseCommand(std::string userInput, Client &client);
        void                _passCommand(std::string params, Client &client);
};
#endif
