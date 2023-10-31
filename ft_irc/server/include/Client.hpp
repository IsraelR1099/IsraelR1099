/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:30 by israel            #+#    #+#             */
/*   Updated: 2023/10/31 17:36:48 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

#define CLIENT_HPP

class Client {
    private:
        int         _socket;
        std::string _nick;
        std::string _user;
        bool        _isRegistered;
        bool        _isAuthorised;

    public:
        Client();
        Client(int socket);
        Client(const Client &other);
        Client &operator=(const Client &other);
        ~Client();

        int			        getSocketNumber();
        bool        		getIsRegistered();
        bool	        	getIsAuthorised();
        std::string	        getName(void);
        std::string         getUser(void);
        const std::string	&getNick(void) const;
        void		        setName(std::string name);
        void        		setIsAuthorised(bool value);
        void	        	setIsRegistered(bool value);
        void		        setNick(std::string nick);
        void                setUser(std::string user);
};

#endif
