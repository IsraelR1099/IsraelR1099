/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:00:37 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/08 13:31:51 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"


int	main(void)
{
	t_list	tmp;

	ft_lstnew((void *)42);

	printf("%sEl resultado es %p\n%s", TC_GRN, tmp.content, TC_NRM);

	return (0);
}


