/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:47:55 by portega-          #+#    #+#             */
/*   Updated: 2025/07/29 17:48:08 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	return_val;

	return_val = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 1)
		return_val = return_val * nb;
	return (return_val);
}
