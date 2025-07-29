/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:23:15 by portega-          #+#    #+#             */
/*   Updated: 2025/07/29 18:29:26 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	result_val;

	if (index < 0)
		return (-1);
	else
	{
		if (index == 0)
			return (0);
		if (index == 1)
			return (1);
		result_val = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (result_val);
	}
}
