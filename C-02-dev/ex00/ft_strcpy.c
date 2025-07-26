/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:34:42 by portega-          #+#    #+#             */
/*   Updated: 2025/07/26 16:31:24 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*ptr_begin_dest;

	ptr_begin_dest = dest;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (ptr_begin_dest);
}
