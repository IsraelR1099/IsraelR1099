/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:54:22 by cteixido          #+#    #+#             */
/*   Updated: 2022/02/08 15:59:42 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*newone;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		newone = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = newone;
	}
	lst = 0;
}
