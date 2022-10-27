/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:48:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/27 14:12:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

int	ft_true_quotes(char **pstr, char *estr)
{
	char	*tmp;

	tmp = *pstr;
	while (tmp < estr && !ft_strchr("\t\r\n\v ", *tmp))
	{
		if (*tmp == '"' || *tmp == '\'')
			return (1);
		tmp++;
	}
	return (0);
}

void	ft_fillspace(char **copy, int len)
{
	int	i;

	i = ft_strlen(*copy);
	while (*copy[i] < len)
	{
		*copy[i] = 32;
		i++;
	}
}

static int	ft_getcleaned(char **pstr, char *estr, char **copy, int *counter)
{
	char			*tmp;
	unsigned char	in_quote;
	int				len;
	int				i;

	ft_memset(copy, 0, sizeof(copy));
	tmp = *pstr;
	len = 0;
	i = 0;
	while (tmp < estr && !ft_strchrflag("\t\r\n\v ", *tmp, in_quote)
			&& !ft_strchrflag("<|>", *tmp, in_quote))
	{
		printf("tmp es %c\n", *tmp);
		if (ft_strchr("\"\'", *tmp) && (*tmp != in_quote)
				&& !in_quote)
		{
			in_quote = *tmp;
			*counter = *counter + 1;
		}
		else if (*tmp == in_quote)
		{
			in_quote = 0;
			*counter = *counter + 1;
		}
		else if (*tmp != in_quote)
		{
			printf("entro \n");
			*copy[i] = *tmp;
			i++;
			printf("salgo\n");
		}
		tmp++;
		len++;
	}
	printf("salgo tmp %c\n", *tmp);
	ft_fillspace(copy, len);
	return (len);
}

static int	ft_copycleaned(char **pstr, char *estr, char **copy)
{
	char	*tmp;
	int		ret;
	int		counter;
	int		len;
	int		i;

	counter = 0;
	ret = ft_getcleaned(pstr, estr, copy, &counter);
	tmp = *pstr;
	len = ret;
	i = 0;
	while (tmp < estr && len > 0)
	{
		*tmp = *copy[i];
		i++;
		len--;
		tmp++;
	}
	return (len - counter);
}

int	ft_change_token(char **pstr, char *estr)
{
//	char			*tmp;
//	int				counter;
//	int				len;
	int				ret;
//	unsigned char	in_quote;
	char			*copy;
//	int				i;

//	tmp = *pstr;
//	counter = 0;
//	len = 0;
//	i = 0;
	copy = (char *)malloc(sizeof(char) * 256);
	if (!copy)
		ft_error("malloc error\n", 1);
	ret = ft_copycleaned(pstr, estr, &copy);
/*	ft_memset(copy, 0, sizeof(copy));
	while (tmp < estr && !ft_strchrflag("\t\r\n\v ", *tmp, in_quote)
		&& !ft_strchrflag("<|>", *tmp, in_quote))
	{
		if (ft_strchr("\"\'", *tmp) && (*tmp != in_quote) && !in_quote)
		{
			in_quote = *tmp;
			counter++;
		}
		else if (*tmp == in_quote)
		{
			in_quote = 0;
			counter++;
		}
		else if (*tmp != in_quote)
		{
			copy[i] = *tmp;
			i++;
		}
		tmp++;
		len++;
	}
	if (counter == 2 && len == 2)
		return (0);
	i = ft_strlen(copy);
	while (ft_strlen(copy) < (size_t)len)
	{
		copy[i] = 32;
		i++;
	}
	i = 0;
	tmp = *pstr;
	ret = len;
	while (tmp < estr && len > 0)
	{
		*tmp = copy[i];
		i++;
		len--;
		tmp++;
	}*/
	return (ret);

}
