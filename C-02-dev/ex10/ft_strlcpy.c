/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:01:21 by portega-          #+#    #+#             */
/*   Updated: 2025/07/24 20:52:21 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	count;

	n = size;
	count = 0;
	while (*src)
	{

		if (n > 1)
		{
			*dest = *src;
			dest++;
		}
		if (n == 1)
		{
			*dest = '\0';
			dest++;
		}
		src++;
		count++;
		n--;
	}

	return (count);
}
