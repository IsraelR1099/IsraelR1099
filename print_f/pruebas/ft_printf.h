/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:30:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/03 14:12:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_specifier(va_list lst, int str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned int n);
//Funciones de la libreria libft
size_t	ft_strlen(char *str);
char	*ft_itoa(size_t n, int base);
int		ft_len(size_t n, int base);

#endif
