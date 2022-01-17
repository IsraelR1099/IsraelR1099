/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:43:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/17 13:16:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size);

int	main(void)
{
	int	*ptr;
	int	n;
	int	i;
	
	n = 5;
	ptr = (int *)ft_calloc(n, sizeof(int));

	if (ptr == NULL)
	{
		printf("Memorry not allocated.\n");
	}
	else
	{
		printf("Memory succesfully allocated using ft_calloc.\n");
		/*for (i = 0; i < n; ++i)
		{
			ptr[i] = i + 1;
		}*/
		
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i)
		{
			printf("%d, ", ptr[i]);
		}
	}
	free(ptr);

	return (0);
}

