/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:10:13 by portega-          #+#    #+#             */
/*   Updated: 2025/07/15 16:20:22 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_div_mod(int a, int b, int *div1, int *mod)
{
	div_t	temp = div(a, b);
	printf("temp.quot: %d temp.rem: %d \n", temp.quot, temp.rem);	
	*div1 = temp.quot;
	*mod = temp.rem;

	*div1 = a / b;
	*mod = a % b;	
	printf("temp.quot: %d temp.rem: %d \n", *div1, *mod);	
}

int main (void)
{
	int	num1;
	int num2;
	int quot;
	int rem;	
	int	*ptr_quot;
	int *ptr_rem;

	num1 = 75;
	num2 = 13;
	quot = 0;
	rem = 0;
	ptr_quot = &quot;
	ptr_rem = &rem;
	printf("Antes llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
	ft_div_mod(num1, num2, ptr_quot, ptr_rem);
	printf("Despues llamada quot y rem: %d - %d \n", *ptr_quot, *ptr_rem);
}
