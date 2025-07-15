/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:10:13 by portega-          #+#    #+#             */
/*   Updated: 2025/07/15 17:29:10 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	
	while (*str)
	{
		write(1, str, 1);
		str++;
	};
}

int main (void)
{
	char palabra[] = "Hola mundo";
	char *ptr_palabra;

	ptr_palabra = palabra;
	ft_putstr(ptr_palabra);
}
