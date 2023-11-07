/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:11:18 by irifarac          #+#    #+#             */
/*   Updated: 2023/11/06 17:40:49 by israel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Server.hpp"

Channel	*Server::_getChannelByName(const std::string channelName)
{
	std::map<int, Channel>::iterator	it;

	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		Channel	&channel = it->second;
		if (channel.getName() == channelName)
			return (&channel);
	}
	return (0);
}
