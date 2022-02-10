/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:23:45 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/10 13:52:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

typedef struct s_user
{
	char	*first_name;
	char	*last_name;
}	t_user;
void	ft_delete_user(void *data)
{
	t_user	*user;

	user = (t_user *)data;
	free(user->first_name);
	free(user->last_name);
	free(user);
}

int	main(void)
{
	t_list	*list;
	t_list	*node;
	t_user	*user;

	list = NULL;
	user = malloc(sizeof(t_user));
	if (!user)
		return (EXIT_FAILURE);
	user->first_name = ft_strdup("Eduardo");
	user->last_name = ft_strdup("Ramirez");
	node = ft_lstnew(user);
	printf("the address of node is %d\n", (int)node);
	if (!node)
	{
		ft_delete_user(user);
		free(user);
		return (0);
	}
	printf("the address of list is %d\n", (int)list);
	ft_lstadd_front(&list, node);
	printf("%sthe address of list after is %d\n%s", TC_GRN, (int)list, TC_NRM);
	printf("%sthe address of node after is %d\n%s", TC_BLU, (int)node, TC_NRM);
	printf("%s %s\n", ((t_user *)list->content)->first_name, ((t_user *)list->content)->last_name);
//	ft_lstclear(&list, ft_delete_user);
	printf("Segunda vez :%s %s\n", ((t_user *)list->content)->first_name, ((t_user *)list->content)->last_name);
	return (0);
}

