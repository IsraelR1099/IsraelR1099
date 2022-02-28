/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:32:13 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/24 12:09:37 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int			ft_print_char(char c);
int			ft_print_string(char *str);
int			ft_hex_len(unsigned	int num);
void		ft_put_hex(unsigned int num, const char format);
int			ft_hex_len2(unsigned	long long num);
void		ft_put_ptr(unsigned long long num);
int			ft_print_hex(unsigned int num, const char format);
int			ft_print_ptr(unsigned long long ptr);
char		*ft_itoa(int n);
int			ft_print_d(int n);
int			ft_num_len(unsigned int num);
char		*ft_uitoa(unsigned int n);
int			ft_print_unsigned(unsigned int n);
int			ft_print_perc(void);
int			ft_formats(va_list args, const char *s, int i);
int			ft_printf(const char *s, ...);

#endif