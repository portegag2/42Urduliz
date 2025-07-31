/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:04:24 by portega-          #+#    #+#             */
/*   Updated: 2025/07/31 09:14:25 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	*ptr_begin;

	if (min >= max)
		return (NULL);
	range = malloc(sizeof(int) * (max - min));
	ptr_begin = range;
	while (min < max)
	{
		*range = min++;
		range++;
	}
	return (ptr_begin);
}
