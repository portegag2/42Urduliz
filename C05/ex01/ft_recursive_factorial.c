/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:47:43 by portega-          #+#    #+#             */
/*   Updated: 2025/07/29 17:51:59 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	return_val;

	return_val = nb;
	if (nb < 0)
		return (0);
	if (nb < 2)
		return (1);
	else
		return_val = nb * ft_recursive_factorial(nb - 1);
	return (return_val);
}
