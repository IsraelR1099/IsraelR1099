/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:48:38 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/23 20:16:23 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Client.hpp"

Client::Client() {
    _socket = 0;
    _isRegistered = false;
    _isAuthorised = false;
}

Client::Client(int socket)
{
    _socket = socket;
    _isRegistered = false;
    _isAuthorised = false;
}

// copy operator
Client::Client(const Client &other)
{
    this->_socket = other._socket;
    this->_nick = other._nick;
    this->_user = other._user;
    this->_fullName = other._fullName;
    this->_host = other._host;
    this->_isRegistered = other._isRegistered;
    this->_isAuthorised = other._isAuthorised;
    this->_isOperator = other._isOperator;
    this->_buffer = other._buffer;
}

// assignment operator
Client	&Client::operator=(const Client &other)
{
     if (this != &other)
     {
        _socket = other._socket;
        this->_nick = other._nick;
        this->_user = other._user;
        this->_fullName = other._fullName;
        this->_host = other._host;
        this->_isRegistered = other._isRegistered;
        this->_isAuthorised = other._isAuthorised;
        this->_isOperator = other._isOperator;
        this->_buffer = other._buffer;
     }
    return *this;
}

Client::~Client()
{
}

int	Client::getSocketNumber() const
{
    return _socket;
}

void	Client::setIsRegistered(bool value) {
    _isRegistered = value;
}

bool	Client::getIsRegistered() {
    return _isRegistered;
}
void	Client::setIsAuthorised(bool value) {
    _isAuthorised = value;
}
bool	Client::getIsAuthorised() {
    return _isAuthorised;
}

void	Client::setIsOperator(bool value)
{
    _isOperator = value;
}

bool	Client::getIsOperator(void)
{
    return (_isOperator);
}

void	Client::setUser(std::string user) {
    _user = user;
}

std::string	Client::getUser() const
{
    return _user;
}

void	Client::setNick(std::string nick) {
    _nick = nick;
}

const std::string	&Client::getNick() const
{
    return _nick;
}

void    Client::setFullName(std::string fullName)
{
    _fullName = fullName;
}

std::string Client::getFullName(void)
{
    return (_fullName);
}

void    Client::setHost(const std::string host)
{
    this->_host = host;
}

std::string Client::getHost(void) const
{
    return (this->_host);
}

void	Client::write_buffer(Client &client, const std::string &message)
{
    std::cout << ANSI::green <<
        "Sending message to client: " << ANSI::reset << message << std::endl;
    std::cout << "client es: " << client.getNick() <<
       "y socket es: " << client.getSocketNumber() << std::endl;
	client._buffer = message + "\r\n";
    std::cout << ANSI::green <<
        "Buffer: " << ANSI::reset << client._buffer << std::endl;
}

std::string	Client::getCustomPrefix(const std::string &code, const std::string channelName) const
{
	std::string	ret;

    if (code == "471")
        ret = channelName;
    else if (code == "461")
    {
        if (this->_nick.empty())
            ret = "*";
        else
            ret = this->_nick;
        ret += " " + channelName;
    }
    else if (code == "403")
    {
        if (this->_nick.empty())
            ret = "*";
        ret += " " + channelName;
    }
	else if (code == "332")
		ret = "server 332 " + this->_nick + "#" + channelName;

    return (ret);
}

std::string Client::getCustomPrefix(const std::string &code, std::vector<std::string> &params)
{
    std::string                         ret;
    std::vector<std::string>::iterator  it;

    it = params.begin();
    while (it != params.end())
    {
        ret += *it;
        if (it + 1 != params.end())
            ret += " ";
        it++;
    }
    (void)code;
    return (ret);
}

std::string Client::getCustomPrefix(const std::string &code)
{
    std::string ret;

    if (code == "001")
        ret = this->_nick + "!" + this->_user + "@" + this->_host;
    else if (code == "451")
    {
        if (this->_nick.empty())
            ret = "*";
        else
            ret = this->_nick;
    }
    return (ret);
}

void	Client::send_message(void)
{
	int	rc;

	if (!this->_buffer.length())
		return ;
	rc = send(this->_socket, this->_buffer.c_str(), this->_buffer.length(), 0);
	if (rc < 0)
		std::cerr << ANSI::red << "send() failed" << ANSI::reset << std::endl;
    this->_buffer.clear();
}
