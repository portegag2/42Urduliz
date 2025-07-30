/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:11:57 by portega-          #+#    #+#             */
/*   Updated: 2025/07/30 21:45:05 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_len_str(char *src)
{
	int	count;

	count = 0;
	while (*(src++))
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*ptr_begin;

	dest = malloc(sizeof(char) * (ft_len_str(src) + 1));
	ptr_begin = dest;
	if (dest == NULL)
		return (NULL);
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr_begin);
}
