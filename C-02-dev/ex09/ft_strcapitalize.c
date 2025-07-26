/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: portega- <portega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:01:36 by portega-          #+#    #+#             */
/*   Updated: 2025/07/26 15:56:16 by portega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../index_components.h"

int	ft_local_str_is_alpha(char *str)
{
	if (*str)
	{
		if (!((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')))
			return (0);
	}
	return (1);
}

int	ft_local_str_is_numeric(char *str)
{
	if (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
	}
	return (1);
}

char	*ft_local_strupcase(char *str)
{
	char	*ptr_begin;

	ptr_begin = str;
	if (*str >= 'a' && *str <= 'z')
	{
		*str = *str - ' ';
	}
	return (ptr_begin);
}

char	*ft_local_strlowcase(char *str)
{
	char	*ptr_begin;

	ptr_begin = str;
	if (*str >= 'A' && *str <= 'Z')
	{
		*str = *str + ' ';
	}
	return (ptr_begin);
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr_begin;
	char	*char_temp;
	int		string_started;

	char_temp = "";
	ptr_begin = str;
	string_started = 0;
	while (*str)
	{
		if (ft_local_str_is_alpha(str) || ft_local_str_is_numeric(str))
		{
			if (string_started == 0)
			{
				char_temp = ft_local_strupcase(str);
				string_started = 1;
			}
			else
				char_temp = ft_local_strlowcase(str);
			*str = *char_temp;
		}
		else
			string_started = 0;
		str++;
	}
	return (ptr_begin);
}
