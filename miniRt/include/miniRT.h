/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:22:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/13 13:43:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

enum	e_ident
{
	A,
	C,
	L,
	sp,
	pl,
	cy
};

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_window;

//Errors
int		ft_check_error(char **str);
int		ft_error(const char *str, int ret);
int		ft_check_grammar(int fd);
//Utils
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t number);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t count);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_next_line(int fd);

#endif
