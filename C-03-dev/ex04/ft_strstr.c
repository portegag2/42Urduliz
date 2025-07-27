/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 08:05:04 by portega-          #+#    #+#             */
/*   Updated: 2025/07/27 13:49:19 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

char	*ft_strstr(char *str, char *to_find)
{
	int		len_to_find;
	int		count_temp;

	len_to_find = 0;
	count_temp = 0;
	while (to_find[len_to_find] != '\0')
		len_to_find++;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		count_temp = 0;
		while (str[count_temp] == to_find[count_temp])
		{
			if (count_temp == len_to_find - 1)
				return (str);
			count_temp++;
		}
		str++;
	}
	return (0);
}
