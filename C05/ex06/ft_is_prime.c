/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:26:54 by portega-          #+#    #+#             */
/*   Updated: 2025/07/29 19:40:58 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	result_val;

	result_val = 1;
	if (nb < 2)
		return (0);
	while (++result_val < nb)
	{
		if (nb % result_val == 0 && (nb != result_val))
			return (0);
	}
	return (1);
}
