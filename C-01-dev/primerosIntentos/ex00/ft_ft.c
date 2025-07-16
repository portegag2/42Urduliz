/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:55:36 by portega-          #+#    #+#             */
/*   Updated: 2025/07/15 14:41:45 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;	
}

int main (void)
{
	int	num;
	int	*nbr;

	num = 10;
	nbr = &num;
	printf("el puntero apunta: %d \n", *nbr);
	ft_ft(nbr);
	printf("Tras la llamada el puntero apunta: %d", *nbr);
}
