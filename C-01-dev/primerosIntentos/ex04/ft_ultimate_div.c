/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:10:13 by portega-          #+#    #+#             */
/*   Updated: 2025/07/15 17:08:56 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_ultimate_div(int *a, int *b)
{
	int temp;
	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
		
	printf("div: %d mod: %d \n", *a, *b);	
}

int main (void)
{
	int	num1;
	int num2;
	int quot;
	int rem;	
	int	*ptr_quot;
	int *ptr_rem;

	num1 = 80;
	num2 = 6;
	quot = 0;
	rem = 0;
	ptr_quot = &num1;
	ptr_rem = &num2;
	printf("Antes llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
	ft_ultimate_div(ptr_quot, ptr_rem);
	printf("Despues llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
	printf("Finalmente a y b: %d - %d \n", num1, num2);
}
