/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:24:16 by vaguilar          #+#    #+#             */
/*   Updated: 2022/01/31 11:24:19 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;
	t_list	*current;

	newlist = ft_lstnew(f(lst->content));
	if (newlist == NULL)
		return (NULL);
	current = lst->next;
	temp = newlist;
	while (current != NULL)
	{
		newlist->next = ft_lstnew(f(current->content));
		if (newlist->next == NULL)
			ft_lstdelone(newlist, del);
		current = current->next;
	}
	return (temp);
}
