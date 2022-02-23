/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:53:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/23 13:51:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
void		ft_putstr(char *str);
char		*ft_strchr(const char *str, int ch);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dest, const void *src, size_t count);
char		*ft_strjoin(char *s1, char const *s2);
#endif
