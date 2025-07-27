/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 07:51:20 by portega-          #+#    #+#             */
/*   Updated: 2025/07/27 07:57:20 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr_dest;

	ptr_dest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src && nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (ptr_dest);
}
