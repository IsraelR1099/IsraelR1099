/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:03:28 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/27 15:49:09 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_elem;

	last_elem = lst;
	if (lst)
	{
		while (last_elem->next)
			last_elem = last_elem->next;
		return (last_elem);
	}
	return (NULL);
}
