/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:46:10 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 18:43:05 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h> 
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_flag
{
	char	type;
	int		width;
	char	direction;
	int		size;
	char	zero;
	char	prec;
	int		sign;
	int		space;
	int		sharp;

}	t_flag;

int		ft_printf(const char *s, ...);
char	*my_print(char *s, va_list args, size_t *len);
size_t	printf_type(va_list args, t_flag *flgag);
//p_type1
size_t	p_c(t_flag *flag, int c);
size_t	p_s(t_flag *flag, char *str);
size_t	p_p(t_flag *flag, unsigned long long p);
size_t	p_di(t_flag *flag, int n);
//p_type2
size_t	p_u(t_flag *flag, unsigned long ul);
size_t	p_lx(t_flag *flag, unsigned int ui);
size_t	p_ux(t_flag *flag, unsigned int ui);
size_t	p_percent(t_flag *flag);
//p_type3
size_t	p_all(t_flag *flag, char *str);
size_t	p_blanks(int n);
char	*fill_zero(t_flag *flag, char *str);
//type
char	*str_upper(char *str);
char	*to_hex(unsigned long long n);
char	*u_itoa(unsigned int n);
//utils
char	*to_str(int c);
char	*join(char *s1, char *s2);
char	*sdup(char *str);
char	*sub(char *str, unsigned int start, size_t len);
//flag1
char	*get_s_flag(char *s);
t_flag	*init_flag(char	*str_flag);
char	*get_flag_nbr(char *str_flag);
char	*set_type(t_flag *flag, char *str_flag);
char	*set_width(t_flag *flag, char *str_flag);
//flag2
char	*set_dir(t_flag *flag, char	*str_flag);
char	*set_zero(t_flag *flag, char *str_flag);
char	*set_prec(t_flag *flag, char *str_flag);
char	*set_space(t_flag *flag, char *str_flag);
char	*set_sharp(t_flag *flag, char *str_flag);

#endif
