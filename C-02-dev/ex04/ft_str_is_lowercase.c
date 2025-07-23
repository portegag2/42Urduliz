/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:06:06 by portega-          #+#    #+#             */
/*   Updated: 2025/07/23 22:12:22 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

int	ft_str_is_lowercase(char *str)
{
	if(*str)
	{
		while(*str)
		{
			if(!(*str >= 'a' && *str <= 'z'))
			{
				return (0);
			}
			str++;
		}
	}
	return (1);
}
