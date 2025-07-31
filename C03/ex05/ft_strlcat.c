/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 08:43:30 by portega-          #+#    #+#             */
/*   Updated: 2025/07/27 10:43:26 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

unsigned int	ft_local_strlen(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	int				count_added;

	count_added = 0;
	len_dest = ft_local_strlen(dest);
	len_src = ft_local_strlen(src);
	if (size <= len_dest)
		return (size + len_src);
	while (*dest)
		dest++;
	while ((size -1 > len_dest + count_added) && *src)
	{
		*dest = *src;
		dest++;
		src++;
		count_added++;
	}
	*dest = '\0';
	return (len_dest + len_src);
}
