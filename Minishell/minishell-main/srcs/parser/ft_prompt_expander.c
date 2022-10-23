/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_expander.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:16:58 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 13:03:02 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_home_check(char *str, int pos)
{
	if (str[pos] == '~' && str[pos - 1] != '~' && str[pos + 1] != '~'
		&& (str[pos + 1] == '/' || str[pos + 1] == 0 || str[pos + 1] == 32)
		&& (str[pos - 1] == 32 || str[pos - 1] == 0 || str[pos - 1] == '='))
		return (1);
	return (0);
}

static int	ft_is_exit(char *str)
{
	if (!(strncmp(str, "$?", 2)))
		return (1);
	else
		return (0);
}

void	ft_quote_exit_home(char *dump, char **buf, int *i)
{
	if ((dump[i[0]] == '\"' || dump[i[0]] == '\'')
		&& (dump[i[0]] != i[2]) && !i[2])
		i[2] = dump[i[0]];
	else if (dump[i[0]] == i[2])
		i[2] = 0;
	if (ft_is_exit(dump + i[0]) && i[2] != '\'')
	{
		ft_memcpy(*(buf) + i[1], ft_itoa(g_exit), ft_strlen(ft_itoa(g_exit)));
		i[1] += ft_strlen(ft_itoa(g_exit));
	}
	else if (ft_home_check(dump, (i[0])) && !i[2])
	{
		ft_memcpy(*(buf) + i[1], getenv("HOME"),
			ft_strlen(getenv("HOME")) + 1);
		i[0] += 1;
		i[1] += ft_strlen(getenv("HOME"));
	}
}

void	ft_prompt_expander(char **buf, t_env *env)
{
	int				i[3];
	char			dump[BUFFER_SIZE];

	ft_memset(i, 0, 12);
	bzero(dump, BUFFER_SIZE);
	ft_memcpy(dump, *buf, ft_strlen(*buf));
	while (*(dump + i[0]) && i[1] < BUFFER_SIZE)
	{
		ft_quote_exit_home(dump, buf, i);
		if (dump[i[0]] == '$' && i[2] != '\'')
		{
			if (ft_expand(env, dump + i[0] + 1) != NULL)
				ft_memcpy(*(buf) + i[1],
					ft_expand(env, dump + i[0] + 1),
					ft_strlen(ft_expand(env, dump + i[0] + 1)) + 1);
			if (!ft_var_name_stop(dump + i[0] + 1) && dump[i[0]] != '~')
				ft_memcpy(*buf + (++i[1] - 1), dump + (i[0]), 1);
			i[1] += ft_strlen(ft_expand(env, dump + i[0] + 1));
			i[0] += ft_var_name_stop(dump + i[0] + 1) + 1;
			continue ;
		}
		ft_memcpy(*buf + (++i[1] - 1), dump + (++i[0] - 1), 1);
	}
	buf[0][i[1]] = 0;
}
