/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:03:25 by cteixido          #+#    #+#             */
/*   Updated: 2022/02/07 18:03:07 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	length;

	length = 0;
	while (lst)
	{
		length++;
		lst = lst -> next;
	}
	return (length);
}
