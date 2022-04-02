/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:10:29 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/31 14:09:49 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	position;
	int	number;

	position = 0;
	number = 0;
	while (*(str + position))
	{
		number = number * 10 + *(str + position) - 48;
		position++;
	}
	return (number);
}

int	ft_check(int start)
{
	int		test;
	float	check;
	int		check2;

	test = 1;
	check = 0;
	check2 = 0;
	printf("start es %d\n", start);
	if (start == 2)
		return (1);
	while (test <= start)
	{
		check = (float)start/(float)test;
		printf("check es %f y test es %f\n", check, (float)test);
		if (check == (float)start || check == (float)1)
		{
			printf("hola\n");
			check2 += 1;
		}
		test++;
	}
	printf("check2 es %d\n", check2);
	if (check == 2)
		return (1);
	return (0);
}

int	ft_prim(int number)
{
	int	start;
	int	result;

	start = 2;
	result = 0;
	while (start <= number)
	{
		if (ft_check(start))
		{
			result += start;
		}
		start++;
	}
	return (result);
}

int	main(int counter, char **str)
{
	int	number;
	int	result;

	if (counter == 2)
	{
		number = ft_atoi(str[1]);
		result = ft_prim(number);
		printf("|%d|", result);
	}
	write(1, "\n", 1);
	return (0);
}
