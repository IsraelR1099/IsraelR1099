/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_lstadd_frond.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:31:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/08 14:50:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

t_list *addContent(t_list *new, char *content)
{
	new->content = content;

	return (new);
}

int	main(void)
{
	t_list	*tmp;
	t_list	*new = NULL;

	addContent(new, "hola");

	ft_lstadd_front(&tmp, new);
	printf("el elemento es '%s'\n", tmp->content);

	return (0);
}
