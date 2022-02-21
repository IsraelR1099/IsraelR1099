/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/19 14:21:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	const char	*new_src;
	char		*new_dest;

	new_src = (char *)src;
	new_dest = (char *)dest;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (count--)
	{
		*new_dest++ = *new_src++;
	}
	return (dest);
}

char	*ft_strchr(const char *str, int ch)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		if (str[position] == (char)ch)
			return ((char *)str + position);
		position++;
	}
	if (str[position] == (char)ch)
		return ((char *)str + position);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	position;
	int				len_src;

	len_src = ft_strlen(src);
	position = 0;
	if (size != 0)
	{
		while (src[position] != '\0' && position < (size - 1))
		{
			dest[position] = src[position];
			position++;
		}
		dest[position] = '\0';
	}
	return (len_src);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc (ft_strlen((char *)s1) + 1);
	if (dest == NULL)
		return (0);
	ft_strlcpy(dest, s1, ft_strlen((char *)s1) + 1);
	return (dest);
}

void	*ft_realloc(void *ptr, size_t originalLen, size_t newLen)
{
	void	*new_ptr;

	printf("line en ft realloc es ****%s***\n", ptr);
	if (!newLen)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(newLen));
	else if (newLen <= originalLen)
		return (ptr);
	else
	{
		new_ptr = malloc(sizeof(char) * newLen);
		if (!new_ptr)
			return (0);
		if (new_ptr)
		{
			printf("holaaaaaaaaaaaa reallooooc\n");
			printf("line en ft realloc es ****%s***\n", ptr);
			ft_memcpy(new_ptr, ptr, originalLen);
			free(ptr);
		}
		return (new_ptr);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*ptr1;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr1 = (char *)malloc(sizeof(char) * (lens1 + lens2 +1));
	if (ptr1 == NULL)
		return (0);
	if (ptr1)
	{
		ft_memcpy(ptr1, s1, lens1);
		ft_memcpy(ptr1 + lens1, s2, lens2 + 1);
	}
	ptr1[lens1 + lens2] = '\0';
	return (ptr1);
}

int	calls_function()
{
	static int	count;

	count ++;
	return (count);
}

char	*ft_read_file(int fd)
{
	char		whole_str[BUFFER_SIZE + 1];
	int			nbr_bytes;
	static char	*line = NULL;
	static int	loop;
	char		*result;

	//whole str para leer el archivo y line para mantener el valor de whole str
//	whole_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (0);
	//nbr bytes para contar cuantos bytes lee read
	nbr_bytes = 1;
	//loop: controla el numero de veces que se esta dentro de un while
	printf("estoy fuera de while ft read file\n");
	printf("line  fuera de while ft read file |||%s||\n", line);
	//mientras no encuentres un salto de linea en whole str y no llegues al final
	while (!ft_strchr(whole_str, '\n') && nbr_bytes != 0)
	{
		nbr_bytes = read(fd, whole_str, BUFFER_SIZE);
		printf("nbr bytes es %d\n", nbr_bytes);
		if (nbr_bytes == -1)
		{
			free(whole_str);
			return (0);
		}
		//si es la primera iteracion en while copias el contenido de whole str en line si no aumentas el tamanio de line y copias su contenido
		printf("loop es igual a %d\n", loop);
		if (loop == 0)
		{
			printf("entro en if loop\n");
			line = ft_memcpy(line, whole_str, BUFFER_SIZE);
			printf("||||| line en if primera  es !!!%s!!!!\n", line);
		}
		else
		{
			printf("holaaaaasasasas\n");
			printf("line en else antes de realloc es ###%s##\n", line);
			//ft_realloc(line, BUFFER_SIZE, (BUFFER_SIZE * loop));
			whole_str[nbr_bytes] = '\0';
			line = ft_strjoin(line, whole_str);
			printf("||||| line en else segunda  es !!!%s!!!!\n", line);
			printf("-----whole str en ft read line es ===%s------\n", whole_str);
			printf("||||| line en ft read line es !!!%s!!!!\n", line);
			//free(whole_str);
		}
		loop++;
	}
	printf("||||| line en ft read line fuera es !!!%s!!!!\n", line);
	printf("?????whole str en ft read line es %s--------\n", whole_str);
	result = ft_line(line, '\n');
	result = ft_line(line, '\n');
	return (result);
}

char	*ft_line(char const *s, char c)
{
	static char	*buffer = NULL;
	char		*token;
//	char		*dup_token;

	printf("++++line en ft line es %s\n", s);
	if (!buffer)
		buffer = (char *)s;
	printf("####buffer en ft line es ##%s#\n", buffer);
	buffer = ft_strjoin(buffer, s);
	printf("****buffer despues de stjoin en ft line es ##%s#\n", buffer);
	token = buffer;
	if (!*buffer)
	{
		buffer = 0;
		return (0);
	}
	while (*buffer == c)
		buffer += 1;
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
			*buffer = 0;
			buffer += 1;
	}
	while (*token == c)
		token += 1;
	printf("@@@@@buffer en ft line es ##%s#\n", buffer);
	printf("^^^^^^token en ft line es igual a ##%s##\n", token);
	//dup_token = ft_strdup(token);
	return (token);
}



