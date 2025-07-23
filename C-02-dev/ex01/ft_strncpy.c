/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:59:56 by portega-          #+#    #+#             */
/*   Updated: 2025/07/23 19:50:13 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while(i<n && src[i]!='\0')
	{
		dest[i] = src[i];
		i++;
	}
	while(i<n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
