/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:40:58 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/25 18:50:23 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstcpy;
	t_list	*lstdel;

	lstdel = *lst;
	if (!*lst || !del)
		return ;
	while (lstdel != NULL)
	{
		lstcpy = lstdel->next;
		ft_lstdelone(lstdel, del);
		lstdel = lstcpy;
	}
	*lst = NULL;
}
