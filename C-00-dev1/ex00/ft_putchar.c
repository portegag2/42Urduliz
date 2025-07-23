/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:48:49 by portega-          #+#    #+#             */
/*   Updated: 2025/07/23 16:38:55 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
int	main(void)
{
	ft_putchar('H');
	ft_putchar('o');
	ft_putchar('l');
	ft_putchar('a');
	ft_putchar('\n');
	ft_putchar('C');
	ft_putchar('u');
	ft_putchar('r');
	ft_putchar('s');
	ft_putchar('o');
	ft_putchar('\n');
}
*/
