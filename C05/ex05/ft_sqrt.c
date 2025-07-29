/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:17:14 by portega-          #+#    #+#             */
/*   Updated: 2025/07/29 19:25:53 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result_val;

	result_val = 1;
	if (nb < 1)
		return (0);
	else if (nb == 1)
		return (1);
	while (result_val++ < nb)
	{
		if ((result_val * result_val) == nb)
			return (result_val);
	}
	return (0);
}
