/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:29:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/10/23 12:09:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

# include <sys/time.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/poll.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <exception>
# include <string>
# include <iostream>
# include <stdbool.h>

class	Server
{
	public:
		Server(void);
		Server(char **argv);
		~Server(void);

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
	private:
		bool			m_g_run_server;
		unsigned short	m_port;
		std::string		m_password;
};
#endif
