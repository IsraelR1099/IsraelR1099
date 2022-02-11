/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:38:23 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/11 12:50:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (lst && f)
	{
		new_list = ft_lstnew(f(lst));
		if (new_list && lst->next)
			new_list->next = ft_lstmap(lst->next, f, del);
		return (new_list);
	}
	return (0);
}
