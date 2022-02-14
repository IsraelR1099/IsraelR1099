/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:00:04 by cteixido          #+#    #+#             */
/*   Updated: 2022/02/11 13:03:40 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*tmpcnt;

	n = 0;
	while (lst)
	{
		tmpcnt = ft_lstnew(f(lst->content));
		if (!tmpcnt)
		{
			ft_lstclear(&n, del);
			return (0);
		}
		ft_lstadd_back(&n, tmpcnt);
		lst = lst->next;
	}
	return (n);
}
