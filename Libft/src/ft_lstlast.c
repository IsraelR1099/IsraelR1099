/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:35:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/09 12:37:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (lst)
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		return (ptr);
	}
	return (NULL);
}
