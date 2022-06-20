/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:52:46 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/20 09:52:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *x, char *y) 
{ 
    char temp; 

	temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int	*ft_conversor(char *a, int len)
{
	int	position;
	int	*nbr;

	position = 0;
	nbr = (int *)malloc(sizeof(int) * (len));
	if (!nbr)
		return (0);
	while (a[position])
	{
		if (a[position] == 'A')
			nbr[position] = 1;
		else if (a[position] == 'B')
			nbr[position] = 2;
		else if (a[position] == 'C')
			nbr[position] = 3;
		else if (a[position] == 'D')
			nbr[position] = 4;
		else if (a[position] == 'E')
			nbr[position] = 5;
		position++;
	}
	return (nbr);
}

/* Function to print permutations of string 
This function takes three parameters: 
1. String 
2. Starting index of the string 
3. Ending index of the string. */
void permute(char *a, int l, int r) 
{ 
	int i; 
	int	*nbr;	

	if (l == r)
	{	
		nbr = ft_conversor(a, r + 1);
    	printf("%d %d %d %d %d\n", nbr[0], nbr[1], nbr[2], nbr[3], nbr[4]);
	}	
	else
	{ 
    	for (i = l; i <= r; i++) 
	    { 
    	    swap((a+l), (a+i)); 
        	permute(a, l+1, r); 
	        swap((a+l), (a+i)); //backtrack 
   		 } 
	} 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    char str[] = "ABCDE"; 
    int n;
	n = strlen(str); 
    permute(str, 0, n-1); 
    return 0; 
} 
