/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:30:04 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/21 22:03:05 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *str, int ch, size_t count);
int		ft_memcmp(const void *str1, const void *str2, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memset(void *dest, int ch, size_t count);
char	*ft_strchr(const char *str, int ch);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t number);
char	*ft_strnstr(const char *dest, const char *src, size_t count);
char	*ft_strrchr(const char *str, int ch);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_specifier(va_list lst, int str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putunsigned(long long int n);
int		ft_puthex(unsigned int n, int str);
int		ft_putptr(unsigned long long ptr);
char	*ft_print_itoa(long long n, int base);
int		ft_len(long long n, int base);
int		ft_tolower(int c);
int		ft_printf(int fd, const char *format, ...);
char	*ft_unsigned_itoa(unsigned long long n, int base);
int		ft_unsigned_len(unsigned long long n, int base);
char	*ft_strchrnul(const char *s, int c);
void	ft_init_zero(int *i, int *j);
size_t	ft_counter(char const *s, char c);
void	ft_ssh(int signal);

#endif
