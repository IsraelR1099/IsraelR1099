/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:29:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/06 12:03:51 by irifarac         ###   ########.fr       */
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
# include "./Ansi.hpp"
# include "Channel.hpp"
# include "errno.h"
# include <stdio.h>
# include <stdlib.h>
# include <sstream>
# include <algorithm>

#define MAX_CLIENTS 5

class	Server
{
	public:
		Server(void);
		Server(char **argv);
		~Server(void);

		void	setServer(void);
        int     launchServer(void);


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
		// ********************** //
		// * Private fields. * //
		// ********************** //
		bool				    _m_g_run_server;
		unsigned int		    _m_port;
		std::string			    m_password;
		int					    _m_fd_server;
		struct sockaddr_in	    _server;
		struct pollfd	        m_fds[MAX_CLIENTS + 1];
		std::map<int, Client>	_clients;
        std::map<int, Channel>  _channels;

		// ********************** //
		// * Private methods. * //
		// ********************** //

		int		_acceptClient(int nfds);
		void	_receiveClient(int i);
		void	_parseCommand(std::string userInput, unsigned short clientIndex);
        void    _joinChannel(std::string channelName, unsigned short clientIndex);
        std::vector<std::string> _getAllClientNicknames(std::map<int, Client>&clients);
        void    _sendMessageToClient(const std::string &message, unsigned short clientIndex);
        void    _reply(unsigned short clientIndex, const std::string &message);
		Channel	&_getChannelByName(const std::string channelName);

        // ********************** //
        // * Command methods. * //
        // ********************** //
        void    _capCommand(std::string params, unsigned short clientIndex);
		void	_passCommand(std::string params, unsigned short clientIndex);
        void    _nickCommand(std::string params, unsigned short clientIndex);
        void    _privmsgCommand(std::string params, unsigned short clientIndex);
        void    _userCommand(std::string params, unsigned short clientIndex);
        void    _joinCommand(std::string params, unsigned short clientIndex);
        void    _modeCommand(std::string params, unsigned short clientIndex);
        void    _pingCommand(std::string params, unsigned short clientIndex);
};
#endif
