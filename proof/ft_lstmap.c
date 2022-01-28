/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:28:58 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/26 17:48:45 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*con;

	if (!lst || !f)
		return (0);
	newlst = ft_lstnew(f(lst->content));
	con = newlst;
	lst = lst->next;
	while (lst)
	{
		con->next = ft_lstnew(f(lst->content));
		if (!con)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		con = con->next;
		lst = lst->next;
	}
	return (newlst);
}
