/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:21:18 by portega-          #+#    #+#             */
/*   Updated: 2025/07/31 09:40:31 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size_range;
	int	i;

	i = 0;
	size_range = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	size_range = max - min;
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		range[0][i] = min++;
		i++;
	}
	return (size_range);
}
