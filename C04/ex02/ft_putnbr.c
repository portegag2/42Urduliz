/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:54:55 by portega-          #+#    #+#             */
/*   Updated: 2025/07/28 17:50:13 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	int	mod;

	mod = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = 147483648;
		}
		else
			nb = nb * -1;
	}
	mod = nb % 10;
	if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10);
	}
	mod = (nb % 10);
	mod = mod + '0';
	write (1, &mod, 1);
}
