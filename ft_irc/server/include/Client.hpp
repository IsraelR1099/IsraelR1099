/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:35:30 by israel            #+#    #+#             */
/*   Updated: 2023/10/29 17:35:38 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

#define CLIENT_HPP

class Client {
    private:
        int _socket;
        std::string _name;
        std::string _nick;
        bool _isRegistered;
        bool _isAuthorised;

    public:
        Client();
        Client(int socket);
        Client(const Client &other);
        Client &operator=(const Client &other);
        ~Client();

        int getSocketNumber();
        void setIsRegistered(bool value);
        bool getIsRegistered();
        void setIsAuthorised(bool value);
        bool getIsAuthorised();
        void setName(std::string name);
        std::string getName();
        void setNick(std::string nick);
        std::string getNick();
};

#endif
