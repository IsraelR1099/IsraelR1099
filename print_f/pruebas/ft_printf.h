/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:30:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/02 13:33:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_specifier(va_list lst, char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);

#endif
