/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_process_inputs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:09:02 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/10 16:09:10 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static int	ft_loader_select(int argc, char *argv[], t_meta_data *meta)
{
	char	**list;

	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
			return (0);
		if (ft_check_input_limits(list, meta) == 0)
			return (ft_clear_split(list));
		if (ft_load_stack(list, meta) == 0)
			return (ft_clear_split(list));
		ft_clear_split(list);
		return (1);
	}
	else
	{
		meta->init = 1;
		if (ft_check_input_limits(argv, meta) == 0)
			return (0);
		if (ft_load_stack(argv, meta) == 0)
			return (0);
		return (1);
	}
}

int	ft_process_list(int argc, char *argv[], t_meta_data *meta)
{
	if (ft_loader_select(argc, argv, meta) == 0)
		meta->error = 1;
	return (1);
}

void	ft_process_commands(int argc, t_meta_data *meta)
{
	char	*line;
	int		i;

	i = 0;
	while (argc)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || ft_strlen(line) < 2)
			break ;
		i++;
		ft_get_command(meta, line);
	}
	meta->moves = i;
}
