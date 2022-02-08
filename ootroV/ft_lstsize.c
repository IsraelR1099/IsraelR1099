/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:52:51 by vaguilar          #+#    #+#             */
/*   Updated: 2022/01/31 01:52:59 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		x;

	x = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		x++;
	}
	return (x);
}
