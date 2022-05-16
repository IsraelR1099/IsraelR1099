/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:30:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/07 10:20:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_specifier(va_list lst, int str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putunsigned(long long int n);
int		ft_puthex(unsigned int n, int str);
int		ft_putptr(unsigned long long ptr);
//Funciones de la libreria libft
size_t	ft_strlen(char *str);
char	*ft_print_itoa(long long n, int base);
int		ft_len(long long n, int base);
int		ft_tolower(int c);
char	*ft_unsigned_itoa(unsigned long long n, int base);
int		ft_unsigned_len(unsigned long long n, int base);

#endif
