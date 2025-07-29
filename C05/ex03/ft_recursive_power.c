/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:48:20 by portega-          #+#    #+#             */
/*   Updated: 2025/07/29 18:15:49 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	return_val;

	return_val = nb;
	if (power < 0)
		return (0);
	if ((power == 0 && nb == 0) || (power == 0))
		return (1);
	if (power > 1)
		return_val = nb * ft_recursive_power(nb, power - 1);
	return (return_val);
}
