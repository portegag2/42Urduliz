/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:59:47 by portega-          #+#    #+#             */
/*   Updated: 2025/07/25 12:01:43 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

int	ft_local_str_is_printable(char *str)
{
	if (*str)
	{
		if (!(*str >= ' ' && *str <= '~'))
			return (0);
	}
	return (1);
}

void	ft_convert_to_hex(char character)
{
	char	string_hex[] = "0123456789abcdef";
	char	end_result[2];

	end_result[0] = string_hex[character / 16];
	end_result[1] = string_hex[character % 16];
	write (1, &end_result[0], 1);
	write (1, &end_result[1], 1);

}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_local_str_is_printable(str))
			write(1, str, 1);
		else
		{
			ft_convert_to_hex(*str);
			write(1, "\\", 1);
		}
		str++;
	}
}
