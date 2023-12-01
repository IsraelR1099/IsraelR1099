/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ansi.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:15:49 by israel            #+#    #+#             */
/*   Updated: 2023/11/28 11:36:28 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_HPP
# define ANSI_HPP

# include <string>

namespace ANSI
{
    std::string const reset("\033[0m");

    std::string const black("\033[30m");
    std::string const red("\033[31m");
    std::string const green("\033[32m");
    std::string const yellow("\033[33m");
    std::string const blue("\033[34m");
    std::string const magenta("\033[35m");
    std::string const cyan("\033[36m");
    std::string const white("\033[37m");

    std::string const clear("\033[1;1H\033[2J");

    std::string const bold("\033[1m");
    std::string const underline("\033[4m");

    std::string const cmd("\033[1;38;2;255;200;200m");
    std::string const arg("\033[1;38;2;120;230;180m");
}

#endif
