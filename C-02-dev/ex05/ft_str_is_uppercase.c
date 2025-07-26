/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:14:36 by portega-          #+#    #+#             */
/*   Updated: 2025/07/26 08:15:44 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

int	ft_str_is_uppercase(char *str)
{
	if (*str)
	{
		while (*str)
		{
			if (!(*str >= 'A' && *str <= 'Z'))
				return (0);
			str++;
		}
	}
	return (1);
}
