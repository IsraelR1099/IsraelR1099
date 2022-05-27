/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:22:21 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 17:47:39 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_input_limits(char **input, int init)
{
	int	i;

	i = init;
	while (input[i])
	{
		if (ft_send_to_atoi(input[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_loader_select(int argc, char *argv[], t_meta_data *meta)
{
	char	**list;

	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		if (list == NULL)
			return (0);
		if (ft_check_input_limits(list, 0) == 0)
			return (ft_clear_split(list));
		if (ft_load_stack(list, 0, meta) == 0)
			return (ft_clear_split(list));
		ft_clear_split(list);
		return (1);
	}
	else
	{
		if (ft_check_input_limits(argv, 1) == 0)
			return (0);
		if (ft_load_stack(argv, 1, meta) == 0)
			return (0);
		return (1);
	}
}

int	ft_process_list(int argc, char *argv[], t_meta_data *meta)
{
	if (ft_loader_select(argc, argv, meta) == 0)
		return (0);
	if (meta->size == 1)
		return (1);
	if (ft_check_solve(meta) == 1)
		return (1);
	ft_find_best_pivot(meta);
	if (ft_get_sub_stack_limits(meta) == 0)
		return (0);
	if (ft_select_cases(meta) == 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_meta_data	*meta;

	if (argc < 2)
		return (0);
	meta = ft_meta_data_init();
	if (meta == NULL)
		return (0);
	if (ft_process_list(argc, argv, meta) == 0)
		ft_putendl_fd("Error", STDERR_FILENO);
	ft_clear_all(meta);
	return (0);
}
