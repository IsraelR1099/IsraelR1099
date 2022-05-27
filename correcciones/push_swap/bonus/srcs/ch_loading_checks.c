/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_loading_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:13:03 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/09 23:16:27 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi_isprint(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\t');
}

static void	ft_atoi_spaces(char *str, int *i, long long int *rst)
{
	while (ft_atoi_isprint(str[*(i)]) == 1)
			*(i) = *(i) + 1;
	if (str[*(i)] == '-' || str[*(i)] == '+')
	{
		if (str[*(i)] == '-')
			rst[1] = rst[1] * -1;
		*(i) = *(i) + 1;
	}
}

static int	ft_atoi_test(long long int *rst, char c)
{
	long long int	test;

	test = rst[0] * 10 + (c - '0');
	if (rst[1] == -1)
	{
		if (test > 2147483648)
			return (0);
	}
	else
	{
		if (test > 2147483647)
			return (-1);
	}
	rst[0] = test;
	rst[2] = test * rst[1];
	return (1);
}

int	ft_send_to_atoi(char *str)
{	
	long long int	rst[3];
	int				test;
	int				i;

	rst[0] = 0;
	rst[1] = 1;
	rst[2] = 0;
	i = 0;
	ft_atoi_spaces(str, &i, &rst[0]);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		else if (str[i] >= '0' && str[i] <= '9')
		{	
			test = ft_atoi_test(&rst[0], str[i]);
			if (test != 1)
				return (test);
		}
		i++;
	}
	return (1);
}
