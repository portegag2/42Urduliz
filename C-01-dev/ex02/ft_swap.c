/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:10:13 by portega-          #+#    #+#             */
/*   Updated: 2025/07/15 15:16:44 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;	
}

int main (void)
{
	int	num1;
	int num2;
	int	*a;
	int *b;

	num1 = 10;
	num2 = 34;
	a = &num1;
	b = &num2;
	printf("Antes llamada a y b: %d - %d \n", *a, *b);
	ft_swap(a, b);
	printf("Despues llamada a y b: %d - %d \n", *a, *b);
}
