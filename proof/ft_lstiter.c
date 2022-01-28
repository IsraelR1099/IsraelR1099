/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:36:17 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/26 11:22:46 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstiteri(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	f(lst->content);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lstiter;

	lstiter = lst;
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		lstiter = lst->next;
		ft_lstiteri(lst, f);
		lst = lstiter;
	}
}
