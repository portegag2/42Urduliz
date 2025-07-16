/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jouribe- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:01:58 by jouribe-          #+#    #+#             */
/*   Updated: 2025/07/12 19:12:55 by jouribe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw_top(int x)
{
	int	i;

	ft_putchar('A');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
		ft_putchar('A');
}

void	draw_middle(int x, int y)
{
	int	i;
	int	j;

	j = 1;
	while (j < y - 1)
	{
		ft_putchar('\n');
		ft_putchar('B');
		i = 1;
		while (i < x - 1)
		{
			ft_putchar(' ');
			i++;
		}
		if (x > 1)
			ft_putchar('B');
		j++;
	}
}

void	draw_bottom(int x, int y)
{
	int	i;

	if (y > 1)
	{
		ft_putchar('\n');
		ft_putchar('C');
		i = 1;
		while (i < x - 1)
		{
			ft_putchar('B');
			i++;
		}
		if (x > 1)
			ft_putchar('C');
	}
}

int	rush(int x, int y)
{
	int	intmax;

	intmax = 2147483647;
	if (x <= 0 || y <= 0)
		return (0);
	if (x > intmax || y > intmax)
		return (0);
	draw_top(x);
	draw_middle(x, y);
	draw_bottom(x, y);
	ft_putchar('\n');
	return (1);
}
